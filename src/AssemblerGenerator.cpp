#include "include/AssemblerGenerator.hpp"
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

AssemblerGenerator::AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol, Tercets * tercets, VectorOfFunction * vectorOfFunction){
    //Definimos el modelo de memoria, el tamaño de la pila y las librerias a utilizar.
    this->libraries = ".386 \n"
                      ".model flat, stdcall \n" 
                      ".stack 200h \n"
                      "option casemap:none \n"
                      "include C:\\masm32\\include\\masm32rt.inc \n"
                      "include C:\\masm32\\include\\windows.inc \n"
                      "include C:\\masm32\\include\\kernel32.inc \n"
                      "include C:\\masm32\\include\\user32.inc \n"
                      "include C:\\masm32\\include\\masm32.inc \n"
                      "includelib C:\\masm32\\lib\\kernel32.lib \n"
                      "includelib C:\\masm32\\lib\\user32.lib \n"
                      "includelib C:\\masm32\\lib\\masm32.lib \n"
                      "dll_dllcrt0 PROTO C\n"
                      "printf PROTO C : VARARG\n";
    
    //Definimos los errores que pueden ocurrir en el programa.
    this->data = "\n.data\n"
                 "newline db 10, 0 ; Definición de un carácter de nueva línea \n"
                 "@varForPrintShort dw ?; variable auxiliarpara imprimir short al requerir de una promoción \n"
                 "errorSumaEnteros db \"Se produjo un overflow en la suma de enteros.\", 0 \n"
                 "errorProductoFlotantes db \"Se produjo un overflow en el producto de flotantes.\", 0 \n"
                 "errorRecursion db \"Se produjo un llamado recursivo de una funcion a si misma.\", 0 \n"
                 "@cero dd 0.0 \n"
                 "@maximoPositivo dd 3.40282347E+38 \n"
                 "@minimoPositivo dd 1.17549435E-38 \n"
                 "@maximoNegativo dd -3.40282347E+38 \n"
                 "@minimoNegativo dd -1.17549435E-38 \n";

    
    this->code = "";
    this->tableSymbol = tableSymbol;
    this->tercets = tercets;
    this->functionTercets = vectorOfFunction;
    this->pathFinal = pathFinal;
}

//Agrega una variable al string que representa la seccion .data del codigo assembler.
void AssemblerGenerator::addVariable(symbol * s){
    string prefix = "_";    //Prefijo para las variables por defecto. Las variables auxiliares tienen prefijo "@", por eso si son variables auxiliares, no se agrega prefijo.
    if (s->uso == "auxVariable")
        prefix = "";

    string value = (s->value == "" || s->value == "-") ? "?" : s->value;

    //Si es una variable de tipo short, unsigned int o float, se agrega el prefijo y se reemplazan los ":" por "_". DB (8 bits) es para short, DW (16 bits) para unsigned int y DD (32 bits) para float.
    if (s->type == "short"){
        this->data += prefix + reemplazarCaracter(s->lexema,':','_') + " db " + value + "\n";
    }
    else if (s->type == "unsigned int"){
        this->data += prefix + reemplazarCaracter(s->lexema,':','_') + " dw " + value + "\n";
    }
    else if (s->type == "float"){
        this->data += prefix + formatearFloat(reemplazarCaracter(s->lexema,':','_')) + " dq " + value + "\n";
    }
    else if (s->type == "string"){
        this->data += prefix + reemplazarCaracter(reemplazarCaracter(value, ' ', '_'),'.','_') + " db " + '"' + value + '"' + ", 0 \n";  //Aca se reemplazan los espacios por guiones bajos para que no haya problemas.
    }
}

//Genera el bloque de sentencias declarativas del código assembler.
void AssemblerGenerator::generateData(){
    unordered_map<string, symbol*> symbols = this->tableSymbol->getSymbolTable();
    unordered_map<string, symbol*>::iterator it = symbols.begin();
    while (it != symbols.end()){
        symbol * s = it->second;
        if (s){
            if (s->uso != "clase"){
                addVariable(s);
            } 
            else { 
                //Si es una clase, se agregan las variables de la tabla de simbolos de la clase.
                unordered_map<string, symbol*> functionSymbols = s->attributesAndMethodsVector->getSymbolTable();
                unordered_map<string, symbol*>::iterator it2 = functionSymbols.begin();
                while (it2 != functionSymbols.end()){
                    symbol * s = it2->second;
                    if (s){
                       addVariable(s);
                    }
                it2++;
                }
            }  
        }
    it++;    
    }
}

//Remplaza el caracter "caracter" por el caracter "reemplazo" en la cadena "s", devolviendo una copia.
string AssemblerGenerator::reemplazarCaracter(string s, char caracter, char reemplazo){
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == caracter)
            s[i] = reemplazo;
    }
    return s;
}

//Genera el código assembler de las funciones.
void AssemblerGenerator::generateFunctionsAssembler(){
    vector<functionStack*> * functions = this->functionTercets->getFunctions();
    
    //Iteramos sobre cada funcion
    for (auto f: *functions){
        if (f){
            Tercets * functionTercets = f->ter;
            this->code += reemplazarCaracter(f->name,':','_') + ":\n";
            //Chequeo de recursividad 
            this->code += "CMP _flagRecursividad" + reemplazarCaracter(f->name,':','_') + ", 1\n";
            this->code += "JE labelErrorRecursion\n";
            this->code += "MOV _flagRecursividad" + reemplazarCaracter(f->name,':','_') + ", 1\n";

            //Insertamos en la tabla de simbolos el flag de recursividad  asociado a la funcion.
            this->tableSymbol->insert(new symbol("flagRecursividad" + reemplazarCaracter(f->name,':','_'), "0", "short", "var"));
            
            int n = functionTercets->getTercets().size();
            int i = 0;

            //Iteramos sobre la lista de tercetos de la funcion actual.
            for (auto t : functionTercets->getTercets()){
                if (t){
                    if (i == n-1){
                        //En la anteultima linea, seteamos el flag de recursividad en 0.
                        this->code += "MOV " "_flagRecursividad" + reemplazarCaracter(f->name,':','_') + ", 0\n";
                    }
                    this->code += getTercetAssembler(t, functionTercets);
                }
                i++;
            }
        }
        
    }
}

//Genera el assembler de los tercetos del main.
void AssemblerGenerator::generateMainAssembler(){
    this->code += "start:\n";
    for (auto t : tercets->getTercets()){
        this->code += getTercetAssembler(t, this->tercets);
    }
    this->code += "INVOKE ExitProcess, 0\n\n";
}

//Ensambla el string final que contiene el código assembler.
void AssemblerGenerator::generateCode(){
    this->code = "\n.code\n"
                 + this->code +
                 + "\n"
                 + "end start";
}

//Genera el assembler de los labels de los errores en tiempo de ejecucion.
void AssemblerGenerator::generateErrorAssembler(){
    if (this->overflowEnteros){
        this->code += "labelErrorSumaEnteros:\n"
                      "INVOKE StdOut, addr errorSumaEnteros\n"
                      "INVOKE StdOut, addr newline ; Imprimir una nueva línea \n"
                      "INVOKE ExitProcess, 0\n";
    }
    if (this->overflowProductos){
        this->code += "labelErrorProductoFlotantes:\n"
                      "INVOKE StdOut, addr errorProductoFlotantes \n"
                      "INVOKE StdOut, addr newline ; Imprimir una nueva línea \n"
                      "INVOKE ExitProcess, 0\n";
    }
    this->code += "labelErrorRecursion:\n"
                    "INVOKE StdOut, addr errorRecursion \n"
                    "INVOKE StdOut, addr newline ; Imprimir una nueva línea \n"
                    "INVOKE ExitProcess, 0\n";


}

//Genera el código assembler de todo el programa y lo vuelca en un archivo.
void AssemblerGenerator::generateAssembler(){
    this->generateFunctionsAssembler();
    this->generateMainAssembler();
    this->generateErrorAssembler();

    this->generateData();
    this->generateCode();
    
    ofstream file(this->pathFinal, ios::out);
    if (file.is_open()) {
        // Escribir el string en el archivo
        file << this->libraries + this->data + this->code;

        // Cerrar el archivo
        file.close();

        // std::cout << "String escrito en el archivo correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo crear el archivo en la ruta especificada." << std::endl;
    }
    

}

//Obtiene una variable auxiliar y actualiza el contador de variables auxiliares.
string AssemblerGenerator::getAuxVariable(){
    this->auxVariable++;
    return "@aux" + to_string(this->auxVariable);
}

//Obtiene el label para la asignacion del float y actualiza el contador de labels.
string AssemblerGenerator::getFloatLabel(){
    this->floatLabel++;
    return "@labelAsignacionFlotante" + to_string(this->floatLabel);
}

//Formatea un float reemplazando los '+' por 'MAS', los '-' por 'MENOS' y los '.' por '_', para que no haya problemas de sintaxis en el assembler.
string AssemblerGenerator::formatearFloat(string s){
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == '+')
            s.replace(i, 1, "MAS");
        else if (s[i] == '-')
            s.replace(i, 1, "MENOS");
        else if (s[i] == '.')
            s.replace(i, 1, "_");
    }
    return s;
}

//Genera el código assembler de un terceto.
string AssemblerGenerator::getTercetAssembler(Tercet * tercet, Tercets * tercets){
    string out = "";
    string op1 = "";
    string op2 = "";
    string typeOfFirstArg = "";

    //Primero verificamos que los operandos sean referencias a tercetos.
    if (tercet->opIsTercet(1)){

        //El operando 1 es un terceto, por lo tanto buscamos en la lista de tercetos, el terceto al que hace referencia y obtenemos su variable auxiliar.
        op1 = tercets->get(stoi(tercet->getArg1().substr(1)))->getAuxVariable();

        //Buscamos en la tabla de simbolos la variable auxiliar, para obtener su tipo de dato.
        symbol * firstArg = this->tableSymbol->getSymbol(op1);
        if (firstArg)
            typeOfFirstArg = firstArg->type;
    }
    else if (tercet->getArg1() != ""){
        if (tercet->getOp() == "print"){ //Si se trata de un print, se reemplazan todos los espacios por guiones bajos.
            op1 = "_" + reemplazarCaracter(reemplazarCaracter(tercet->getArg1(), ' ', '_'), '.', '_');
        } else {

            //El operando 1 no es un terceto, por lo tanto se trata de una variable. Se agrega el prefijo "_" y se reemplazan los ":" por "" por convencion.
            op1 = "_" + reemplazarCaracter(tercet->getArg1(), ':','_');

            //Mismo razonamiento que antes, buscamos en la tabla de simbolos la variable para obtener su tipo de dato.
            symbol * firstArg = tableSymbol->getSymbol(tercet->getArg1());
            if (firstArg){
                typeOfFirstArg = firstArg->type;
                if (typeOfFirstArg == "float")
                    op1 = formatearFloat(op1);
            }         
        }
    }

    if (tercet->opIsTercet(2)){
        op2 = tercets->get(stoi(tercet->getArg2().substr(1)))->getAuxVariable();
    }
    else if (tercet->getArg2() != ""){
        op2 = "_" + reemplazarCaracter(tercet->getArg2(), ':','_');
        if (typeOfFirstArg == "float")
            op2 = formatearFloat(op2);
    }

    //Suma, chequeando overflow en suma de enteros
    if (tercet->getOp() == "+"){
        tercet->setAuxVariable(getAuxVariable());   //Seteamos la variable auxiliar del terceto.
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable"); //Creamos el simbolo de la variable auxiliar y lo insertamos en la tabla de simbolos.
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "ADD AH, " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AH\n";
            out += "JO labelErrorSumaEnteros\n";           //Esta instruccion salta si se produce un overflow en la suma de enteros con signo.
            this->overflowEnteros = true;
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "ADD AX, " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
            out += "JC labelErrorSumaEnteros\n";            //Esta instruccion salta si se produce un overflow en la suma de enteros sin signo.
            this->overflowEnteros = true;
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FADD " + op2 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
    }
    //Resta
    else if (tercet->getOp() == "-"){
        tercet->setAuxVariable(getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "SUB AH, " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AH\n";
        }
        else if (typeOfFirstArg == "unsigned int") {
            out += "MOV AX, " + op1 + "\n";
            out += "SUB AX, " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FSUB " + op2 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
    }
    //Multiplicacion
    else if (tercet->getOp() == "*"){
        tercet->setAuxVariable(getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op1 + "\n";
            out += "IMUL " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AL\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "MUL " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            string label = this->getFloatLabel();
            
            out += "FLD " + op1 + "\n";
            out += "FMUL " + op2 + "\n";

            //Chequeo de overflow. La idea es chequear que no se pase de los rangos maximos ni minimos, positivos ni negativos. 
            //En los casos validos, se salta a un label donde se realiza la asignacion.
            //IMPORTANTE: Si no se entiende la logica, recuerden: JE (Jump if Equal), JA (Jump if Above), JB (Jump if Below). Todo para aritmetica SIN SIGNO.
            
            //Chequeamos si el resultado de la multiplicacion es 0. Si es 0, no hay overflow, y se salta al label de asignacion.
            out += "FCOM @cero\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JE " + label + "\n";

            //Chequeamos si el resultado de la multiplicacion es mayor al maximo positivo. Si es mayor, hay overflow, y se salta al label de error.
            out += "FCOM @maximoPositivo\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JA labelErrorProductoFlotantes\n";

            //Chequeamos si el resultado de la multiplicacion es menor al minimo negativo. Si es menor, hay overflow, y se salta al label de error.
            out += "FCOM @minimoNegativo\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JB labelErrorProductoFlotantes\n";

            //Chequeamos si el resultado de la multiplicacion es mayor al minimo positivo. Si es mayor, no hay overflow y se salta al label de asignacion.
            out += "FCOM @minimoPositivo\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JA " + label + "\n";

            //Chequeamos si el resultado de la multiplicacion es menor al maximo negativo. Si es mayor, hay overflow, y se salta al label de error.
            out += "FCOM @maximoNegativo\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JA labelErrorProductoFlotantes\n";

            //Agregamos el label de asignacion.
            out += label + ":\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
            this->overflowProductos = true;
        }
    }
    //Division
    else if (tercet->getOp() == "/"){
        tercet->setAuxVariable(getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op1 + "\n";
            out += "IDIV " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AL\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "DIV " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FDIV " + op2 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
    }

    //Asignacion
    else if (tercet->getOp() == "="){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op2 + "\n";
            out += "MOV " + op1 + ", AH\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op2 + "\n";
            out += "MOV " + op1 + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op2 + "\n";
            out += "FSTP " + op1 + "\n";
        }
    }
    //Comparacion igual
    else if (tercet->getOp() == "=="){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JNE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JNE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JNE ";
        }
    }
    //Comparacion menor o igual
    else if (tercet->getOp() == "<="){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JG ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JA ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JG ";
        }
    }
    //Comparacion menor
    else if (tercet->getOp() == "<"){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JGE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JAE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JGE ";
        }
    }
    //Comparacion mayor o igual
    else if (tercet->getOp() == ">="){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JL ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JB ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JL ";
        }
    }
    //Comparacion mayor
    else if (tercet->getOp() == ">"){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JLE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JBE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JLE ";
        }
    }
    //Comparacion distinto
    else if (tercet->getOp() == "!!"){
        if (typeOfFirstArg == "short"){
            out += "MOV AH, " + op1 + "\n";
            out += "CMP AH," + op2 + "\n";
            out += "JE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "CMP AX," + op2 + "\n";
            out += "JE ";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FCOM " + op2 + "\n";
            out += "FSTSW AX\n";
            out += "SAHF\n";
            out += "JE ";
        }
    }
    //Branch por falso
    else if (tercet->getOp() == "BF"){
        string label = tercets->get(stoi(tercet->getArg2().substr(1)))->getArg1();
        out+= label + "\n";
    }
    //Branch incondicional
    else if (tercet->getOp() == "BI"){
        if (tercet->getArg1() != ""){
            //Busco el label al que hace referencia el operando 1.
            string label = tercets->get(stoi(tercet->getArg1().substr(1)))->getArg1();
            out+= "JMP " + label + "\n";
        } else if (tercet->getArg2() != ""){
            //Busco el label al que hace referencia el operando 2.
            string label = tercets->get(stoi(tercet->getArg2().substr(1)))->getArg1();
            out+= "JMP " + label + "\n";
        }
    }
    //Label
    else if (tercet->getOp() == "label"){
        out+= tercet->getArg1() + ":";
    }
    //Llamado a subrutina
    else if (tercet->getOp() == "call"){
        this->recursion = true; //Hay un llamado a funcion, puede haber recursion.
        out += "CALL " + op1.substr(1) + "\n";
    }
    //Return
    else if (tercet->getOp() == "return"){
        out += "RET" "\n";
    }
    //Print
    else if (tercet->getOp() == "print"){
        // out += "INVOKE MessageBox, NULL, addr " + op1 + ", addr " + op1 + ", MB_OK" + "\n";
        out += "INVOKE StdOut, addr " + op1 + "\n";
        out += "INVOKE StdOut, addr newline \n";
    }
    else if (tercet->getOp() == "printIdentificador"){
        if (typeOfFirstArg == "unsigned int"){
            out += "INVOKE printf, cfm$(\"%hu\\n\"), " + op1 + "\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "INVOKE printf, cfm$(\"%.20Lf\\n\"), " + op1 + "\n";
        }
        else if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op1 + "\n";
            out += "MOVSX AX, AL \n";
            out += "MOV @varForPrintShort, AX \n";
            out += "INVOKE printf, cfm$(\"%hd\\n\"), @varForPrintShort \n";
        }
    }
    //Parametro real
    else if (tercet->getOp() == "paramReal"){
        if (tercet->getArg2() == "short"){
            out += "MOV AH, " + op1 + "\n";
        }
        else if (tercet->getArg2() == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
        }
        else if (tercet->getArg2() == "float"){
            out += "FLD " + op1 + "\n";
        }
    }
    //Parametro formal
    else if (tercet->getOp() == "paramFormal"){
        if (tercet->getArg2() == "short"){
            out += "MOV " + op1 + ", AH\n";
        }
        else if (tercet->getArg2() == "unsigned int"){
            out += "MOV " + op1 + ", AX\n";
        }
        else if (tercet->getArg2() == "float"){
            out += "FSTP " + op1 + "\n";
        }
    }
    //Conversion explicita a float
    else if (tercet->getOp() == "tof"){
        tercet->setAuxVariable(getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", "float", "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op2 + "\n";
            out += "CBW \n";
            out += "CWDE \n";
            out += "MOV " + tercet->getAuxVariable() + ", EAX \n";
            out += "FILD " + tercet->getAuxVariable()+ "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "FILD " + op1 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
    }

    //Si se trataba de una comparacion, no se devuelve el assembler + \n ya que lo siguiente que viene es el label.
    if (tercet->getOp() == "==" || tercet->getOp() == "<=" || tercet->getOp() == "<" || tercet->getOp() == ">=" || tercet->getOp() == ">" || tercet->getOp() == "!!")
        return out;
    else
        return out + "\n";
}