#ifndef _AssemblerGenerator_HPP_
#define _AssemblerGenerator_HPP_

#include "Tercets.hpp"
#include "TableSymbol.hpp"
#include <string>
#include "VectorOfFunction.hpp"

using namespace std;

class AssemblerGenerator {
private:
    string pathFinal;
    string code;
    string data;
    string libraries;
    int auxVariable = 0;
    TableSymbol * tableSymbol;
    Tercets * tercets;
    VectorOfFunction * functionTercets;
    VectorOfFunction * functionTercetsDeclaredInClasses;
    bool overflowEnteros = false;
    bool overflowProductos = false;
public:
    AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol, Tercets* tercets, VectorOfFunction * vectorOfFunction, VectorOfFunction * vectorOfFunctionDeclaredInClasses);
    void generateAssembler(); //Genera el código assembler

    void generateData(); //Genera las instrucciones declarativas.
    void generateCode(); //Genera las instrucciones del codigo.
    void generateFunctionsAssembler(); //Genera el código assembler de las funciones.
    void generateMainAssembler(); //Genera el código assembler del main.
    void generateErrorAssembler(); //Genera los labels y el assembler de los errores.

    string getTercetAssembler(Tercet * tercet); //genera el código assembler dado un terceto
    string reemplazarEspacios(string s); //Reemplaza los espacios por guiones bajos.
    string getAuxVariable(); //Obtiene una variable auxiliar.
};

#endif
