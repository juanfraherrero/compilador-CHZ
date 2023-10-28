#ifndef _AssemblerGenerator_HPP_
#define _AssemblerGenerator_HPP_

#include "Tercets.hpp"

#include <string>
using namespace std;

class AssemblerGenerator {
private:
    string pathFinal;
public:
    AssemblerGenerator(string pathFinal);
    
    void generateAssembler(Tercets * tercets); //genera el código assembler dado unalista de tercetos
    
};

#endif
