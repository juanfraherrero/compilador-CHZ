#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include <iostream>
#include <fstream>
#include "types.hpp"
using namespace std;

class Automaton {
    private:
        //Esto hay que setearlo
        valueOfMatrix matrix[2][2] = {
            {{0, NULL}, {30, NULL}},
            {{0, NULL}, {0, NULL}}
        };

        tokenWithLexeme * tokenToreturn = new tokenWithLexeme{0, " "};
        valueOfMatrix * getValueOfMatrix (char character, int actual_state);
        int getSubconjunto(char character);
    public:
        Automaton();
        int processCharacter(char character, int actual_satate);
        tokenWithLexeme* getLastToken();
        
};

#endif