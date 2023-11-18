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

void AssemblerGenerator::generateAssembler(Tercets * tercets){
    this->code = tercets->getAssembler(this->tableSymbol);
    this->code = "\n.code\n"
                 "start:\n"
                 + this->code +
                 "invoke ExitProcess, 0\n"
                 "end start";
    cout << this->libraries + this->data + this->code << endl;
}
