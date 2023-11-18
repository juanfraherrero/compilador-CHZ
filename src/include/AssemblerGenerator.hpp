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
    AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol);
    void generateAssembler(Tercets * tercets); //genera el código assembler dado unalista de tercetos
};

#endif
