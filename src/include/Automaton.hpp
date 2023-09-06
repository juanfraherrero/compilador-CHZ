#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include "types.hpp"
#include "Acciones/AccionSemantica.hpp"
#include <iostream>
#include <fstream>

using namespace std;

class Automaton {
    private:
        //Esto hay que setearlo
        valueOfMatrix matrix[21][28];

        tokenWithLexeme * tokenToreturn = new tokenWithLexeme{0, " "};
        valueOfMatrix * getValueOfMatrix (char character, int actual_state);
        int getSubconjunto(char character);
        AccionSemantica* getAccionSemantica(string accionStr);
        char bufferForCharacter = '\0';

    public:
        Automaton();
        int processCharacter(char character, int actual_satate);
        tokenWithLexeme* getToken();            
        tokenWithLexeme* getCopyOfToken();
        tokenWithLexeme* getCopyOfTokenAndResetToken();
        void printMatrix();
        void loadStateTable(string pathFile);
        void loadActionsTable(string pathFile);
        bool isBufferEmpty();
        void setBuffer(char character);
        char getAndClearBuffer();
};

#endif