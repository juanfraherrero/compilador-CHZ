#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include "types.hpp"
#include "TableSymbol.hpp"
#include "TableReservedWord.hpp"
#include "AccionSemantica.hpp"

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
        TableSymbol* tableSymbol;
        TableReservedWord* tableRWords;
        int* ptrLineNumber;

    public:
        Automaton(TableSymbol* tableSymbol, TableReservedWord* tableRWords, int* ptrLineNumber);
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
        int * getPtrLineNumber();
};

#endif