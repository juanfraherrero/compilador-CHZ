#include "include/AssemblerGenerator.hpp"
#include <iostream> 

using namespace std;

AssemblerGenerator::AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol){
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
    this->pathFinal = pathFinal;
}

//Genera el código assembler dado una lista de tercetos.
void AssemblerGenerator::generateAssembler(Tercets * tercets){
    this->code = tercets->getAssembler(this->tableSymbol);
    this->generateData();
    this->code = "\n.code\n"
                 "start:\n"
                 + this->code +
                 "invoke ExitProcess, 0\n"
                 "end start";
    cout << this->libraries + this->data + this->code << endl;
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
