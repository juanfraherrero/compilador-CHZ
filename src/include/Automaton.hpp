#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include <iostream>
#include <fstream>
#include "types.hpp"
using namespace std;

class Automaton {
    private:
        //Esto hay que setearlo
        valueOfMatrix matrix[22][28];

        tokenWithLexeme * tokenToreturn = new tokenWithLexeme{0, " "};
        valueOfMatrix * getValueOfMatrix (char character, int actual_state);
        int getSubconjunto(char character);
    public:
        Automaton();
        int processCharacter(char character, int actual_satate);
        tokenWithLexeme* getLastToken();
        void printMatrix();
        
};

#endif