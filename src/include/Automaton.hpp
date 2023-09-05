#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include <iostream>
#include <fstream>
#include "types.hpp"
using namespace std;

class Automaton {
    private:
        //Esto hay que setearlo
        valueOfMatrix matrix[21][28];

        tokenWithLexeme * tokenToreturn = new tokenWithLexeme{0, " "};
        valueOfMatrix * getValueOfMatrix (char character, int actual_state);
        int getSubconjunto(char character);
        AccionSemantica* getAccionSemantica(string accionStr);
    public:
        Automaton();
        int processCharacter(char character, int actual_satate);
        tokenWithLexeme* getLastToken();
        void printMatrix();
        void loadStateTable(string pathFile);
        void loadActionsTable(string pathFile);
};

#endif