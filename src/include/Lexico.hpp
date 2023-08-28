#ifndef _LEXICO_H_
#define _LEXICO_H_

#include <iostream>
#include <fstream>
using namespace std;

#include "Automaton.hpp"
#include "types.hpp"

class Lexico {
    private:
        ifstream file;      // es un archivo en modo lectura input file stream
        string file_name;   // es el nombre del archivo a compilar
        string line;        // es la línea del programa para mantenerla en RAM
        int lineNumber;           // indica el nro de línea a leer
        int character;      // es la posicion de último caracter leído
        bool eof;           // indica si se llegó al final del archivo

        Automaton *automaton; // es el autómata que se encarga de procesar los tokens
        
    public:
        Lexico(string file_name);
        tokenWithLexeme * getToken();
        bool endOfFile();
        string getLastLine();
        void getNextLine();
        void incrementLineNumber();
};

#endif