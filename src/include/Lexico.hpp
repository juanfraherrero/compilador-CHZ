#ifndef _LEXICO_H_
#define _LEXICO_H_

#include "TableSymbol.hpp"
#include "TableReservedWord.hpp"
#include "Automaton.hpp"

#include <iostream>
#include <fstream>
using namespace std;


class Lexico {
    private:
        string content;        // es el contenido del programa para mantenerlo en RAM
        int* lineNumber;           // indica el nro de línea a leer
        bool eof;           // indica si se llegó al final del archivo
        bool fileOff;       // indica el archivo esta vacio

        Automaton *automaton; // es el autómata que se encarga de procesar los tokens
        
    public:
        Lexico(TableSymbol* tableSymbol, TableReservedWord* tableRWords, string * line, int* lineNumber);
        int yylex();
        tokenWithLexeme * getToken();
        bool endOfFile();
        string getLastLine();
        void getNextLine();
        void incrementLineNumber();
        bool isFileOff();
        bool isCommentActive;
};

#endif