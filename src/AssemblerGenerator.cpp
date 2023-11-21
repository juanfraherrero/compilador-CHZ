#include "include/AssemblerGenerator.hpp"
#include <iostream>
#include <fstream>

using namespace std;

AssemblerGenerator::AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol, Tercets * tercets){
    //Definimos el modelo de memoria, el tamaño de la pila y las librerias a utilizar.
    this->libraries = ".386 \n"
                      ".model flat, stdcall \n" 
                      ".stack 200h \n"
                      "option casemap:none \n"
                      "include C:\\masm32\\include\\windows.inc \n"
                      "include C:\\masm32\\include\\kernel32.inc \n"
                      "include C:\\masm32\\include\\user32.inc \n"
                      "include C:\\masm32\\include\\masm32.inc \n"
                      "includelib C:\\masm32\\lib\\kernel32.lib \n"
                      "includelib C:\\masm32\\lib\\user32.lib \n"
                      "includelib C:\\masm32\\lib\\masm32.lib \n";
    
    //Definimos los errores que pueden ocurrir en el programa.
    this->data = "\n.data\n"
                 "errorSumaEnteros db \"Se produjo un overflow en la suma de enteros.\", 0 \n"
                 "errorProductoFlotantes db \"Se produjo un overflow en el producto de flotantes.\", 0 \n"
                 "errorRecursion db \"Se produjo un llamado recursivo de una funcion a si misma.\", 0 \n"
                 "error db \"Error de ejecucion.\", 0 \n";
    
    //Definimos el inicio del codigo.
    this->code = "";
    this->tableSymbol = tableSymbol;
    this->tercets = tercets;
    this->pathFinal = pathFinal;
}

//Genera el bloque de sentencias declarativas del código assembler.
void AssemblerGenerator::generateData(){
    unordered_map<string, symbol*> symbols = this->tableSymbol->getSymbolTable();
    unordered_map<string, symbol*>::iterator it = symbols.begin();
    while (it != symbols.end()){
        symbol * s = it->second;
        if (s){
            if (s->type == "identifier" || s->uso == "auxVariable"){
                string prefix = "";
                if (s->type == "identifier")
                    prefix = "_";
                this->data += prefix + s->lexema + " dd ? \n";
            }
            else if (s->type == "short"){
                this->data += "_" + s->lexema + " db ? \n";
            }
            else if (s->type == "unsigned int"){
                this->data += "_" + s->lexema + " dw ? \n";
            }
            else if (s->type == "float"){
                this->data += "_" + s->lexema + " dd ? \n";
            }
            else if (s->type == "string"){
                this->data += reemplazarEspacios(s->value) + " db " + '"' + s->value + '"' + ", 0 \n";  //Aca se reemplazan los espacios por guiones bajos para que no haya problemas.
            }
        }
    it++;    
    }
}

string AssemblerGenerator::reemplazarEspacios(string s){
    for (int i = 0; i < s.length() - 1; i++){
        if (s[i] == ' ')
            s[i] = '_';
    }
    return s;
}


//Genera el código assembler dado una lista de tercetos.
void AssemblerGenerator::generateAssembler(){
    for (auto t : tercets->getTercets()){
        this->code += getTercetAssembler(t);
    }
    this->generateData();
    this->code = "\n.code\n"
                 "start:\n"
                 + this->code +
                 "invoke ExitProcess, 0\n"
                 "end start";
    //cout << this->libraries + this->data + this->code << endl;
    ofstream file(this->pathFinal, ios::out);
    if (file.is_open()) {
        // Escribir el string en el archivo
        file << this->libraries + this->data + this->code;

        // Cerrar el archivo
        file.close();

        std::cout << "String escrito en el archivo correctamente." << std::endl;
    } else {
        std::cerr << "No se pudo crear el archivo en la ruta especificada." << std::endl;
    }
    

}

string AssemblerGenerator::getTercetAssembler(Tercet * tercet){
    string out = "";
    string op1 = "";
    string op2 = "";
    string typeOfFirstArg;
    
    //Primero verificamos que los operandos sean referencias a tercetos. En caso de serlo, los reemplazamos por la variable auxiliar que guarda el resultado del terceto.
    if (tercet->opIsTercet(1)){
        op1 = this->tercets->get(stoi(tercet->getArg1().substr(1)))->getAuxVariable();
        symbol * firstArg = this->tableSymbol->getSymbol(op1);
        if (firstArg)
            typeOfFirstArg = firstArg->type;
    }
    else{
        if (tercet->getOp() == "print"){ //Si se trata de un print, se reemplazan todos los espacios por guiones bajos.
            op1 = reemplazarEspacios(tercet->getArg1());
        } else {
            op1 = "_" + tercet->getArg1();
            symbol * firstArg = tableSymbol->getSymbol(tercet->getArg1());
            if (firstArg)
                typeOfFirstArg = firstArg->type;          
        }
    }

    if (tercet->opIsTercet(2)){
        op2 = this->tercets->get(stoi(tercet->getArg2().substr(1)))->getAuxVariable();
    }
    else{
        op2 = "_" + tercet->getArg2();
    }

    //Suma, chequeando overflow en suma de enteros
    if (tercet->getOp() == "+"){
        tercet->setAuxVariable(tableSymbol->getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "ADD AX, " + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
            out += "JO errorSumaEnteros\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FADD " + op2 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
        }
        
    }
    //Resta
    else if (tercet->getOp() == "-"){
        tercet->setAuxVariable(tableSymbol->getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
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
        tercet->setAuxVariable(tableSymbol->getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AL, " + op1 + "\n";
            out += "IMUL AL" + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AL\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AX, " + op1 + "\n";
            out += "MUL AX" + op2 + "\n";
            out += "MOV " + tercet->getAuxVariable() + ", AX\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op1 + "\n";
            out += "FMUL " + op2 + "\n";
            out += "FSTP " + tercet->getAuxVariable() + "\n";
            out += "JO errorProductoFlotantes\n";
        }
    }
    //Division
    else if (tercet->getOp() == "/"){
        tercet->setAuxVariable(tableSymbol->getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", typeOfFirstArg, "auxVariable");
        tableSymbol->insert(auxSymbol);

        if (typeOfFirstArg == "short"){
            out += "MOV AX, " + op1 + "\n";
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
            out += "MOV AX, " + op2 + "\n";
            out += "MOV " + op1 + ", AX\n";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "MOV AL, " + op2 + "\n";
            out += "MOV " + op1 + ", AL\n";
        }
        else if (typeOfFirstArg == "float"){
            out += "FLD " + op2 + "\n";
            out += "FSTP " + op1 + "\n";
        }
    }
    //Comparacion igual
    else if (tercet->getOp() == "=="){
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JG ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JGE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JL";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
            out += "CMP " + op1 + ", " + op2 + "\n";
            out += "JLE ";
        }
        else if (typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
        if (typeOfFirstArg == "short" || typeOfFirstArg == "unsigned int"){
            out += "CMP " + op1 + ", " + op2 + "\n";
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
        out+= "Label" + tercet->getArg2().substr(1) + "\n";
    }
    //Branch incondicional
    else if (tercet->getOp() == "BI"){
        out+= "JMP Label" + tercet->getArg2().substr(1) + "\n";
    }
    //Label
    else if (tercet->getOp().substr(0,5) == "Label"){
        out+= tercet->getOp() + ":";
    }
    //Llamado a subrutina
    else if (tercet->getOp() == "call"){
        out += "CALL " + op1 + "\n";
    }
    //Return
    else if (tercet->getOp() == "return"){
        out += "RET" "\n";
    }
    //Print
    else if (tercet->getOp() == "print"){
        out += "INVOKE MessageBox, NULL, addr " + op1 + ", addr " + op1 + ", MB_OK" + "\n";
    }
    //Parametro real
    else if (tercet->getOp() == "paramReal"){
        if (tercet->getArg2() == "short"){
            out += "MOV AX, " + op1 + "\n";
        }
        else if (tercet->getArg2() == "unsigned int"){
            out += "MOV AL, " + op1 + "\n";
        }
        else if (tercet->getArg2() == "float"){
            out += "FLD " + op1 + "\n";
        }
    }
    //Parametro formal
    else if (tercet->getOp() == "paramFormal"){
        if (tercet->getArg2() == "short"){
            out += "MOV " + op1 + ", AX\n";
        }
        else if (tercet->getArg2() == "unsigned int"){
            out += "MOV " + op1 + ", AL\n";
        }
        else if (tercet->getArg2() == "float"){
            out += "FSTP " + op1 + "\n";
        }
    }
    //Conversion explicita a float
    else if (tercet->getOp() == "tof"){
        tercet->setAuxVariable(tableSymbol->getAuxVariable());
        string auxVariable = tercet->getAuxVariable();

        symbol * auxSymbol = new symbol(tercet->getAuxVariable(), "", "float", "auxVariable");
        tableSymbol->insert(auxSymbol);

        out += "FILD " + op2 + "\n";
        out += "FSTP " + tercet->getAuxVariable() + "\n";
    }

    //Si se trataba de una comparacion, no se devuelve el assembler + \n ya que lo siguiente que viene es el label.
    if (tercet->getOp() == "==" || tercet->getOp() == "<=" || tercet->getOp() == "<" || tercet->getOp() == ">=" || tercet->getOp() == ">" || tercet->getOp() == "!!")
        return out;
    else
        return out + "\n";
}