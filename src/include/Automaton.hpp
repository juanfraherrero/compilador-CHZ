#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include <iostream>
#include <fstream>
#include "types.hpp"
using namespace std;

class Automaton {
    private:
        
        
    public:
        Automaton();
        int processCharacter(char character);
        tokenWithLexeme* getLastToken();
};

#endif