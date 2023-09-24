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
        string content;             // es el contenido del programa para mantenerlo en RAM
        int* lineNumber;            // indica el nro de línea actual
        bool eof;                   // indica si se llegó al final del archivo

        Automaton *automaton;       // es el autómata que se encarga de procesar los tokens
        
    public:
        Lexico(TableSymbol* tableSymbol, TableReservedWord* tableRWords, string * line, int* lineNumber);
        int yylex();                    // función a usar en el parser
        tokenWithLexeme * getToken();   // devuelve el token
        bool endOfFile();               // indica si se llegó al final del archivo
        void incrementLineNumber();     // incrementa el número de línea
        bool isCommentActive;
        void printMatrix();             // imprime la matriz de estados y acciones
};

#endif