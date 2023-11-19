#ifndef _AssemblerGenerator_HPP_
#define _AssemblerGenerator_HPP_

#include "Tercets.hpp"
#include "TableSymbol.hpp"
#include <string>

using namespace std;

class AssemblerGenerator {
private:
    string pathFinal;
    string code;
    string data;
    string libraries;
    TableSymbol * tableSymbol;
    Tercets * tercets;
public:
    AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol, Tercets* tercets);
    void generateAssembler(); //Genera el código assembler
    string getTercetAssembler(Tercet * tercet); //genera el código assembler dado un terceto
    void generateData(); //Genera las instrucciones declarativas.
    string reemplazarEspacios(string s); //Reemplaza los espacios por guiones bajos.
};

#endif
