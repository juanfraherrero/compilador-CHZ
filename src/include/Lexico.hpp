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
        ifstream fileAux;  // es un archivo en modo lectura input file stream
        ifstream file;      // es un archivo en modo lectura input file stream
        string file_name;   // es el nombre del archivo a compilar
        string line;        // es la línea del programa para mantenerla en RAM
        int lineNumber;           // indica el nro de línea a leer
        int character;      // es la posicion de último caracter leído
        bool eof;           // indica si se llegó al final del archivo
        bool fileOff;       // indica el archivo esta vacio

        Automaton *automaton; // es el autómata que se encarga de procesar los tokens
        
    public:
        Lexico(string file_name, TableSymbol* tableSymbol, TableReservedWord* tableRWords);
        tokenWithLexeme * getToken();
        bool endOfFile();
        string getLastLine();
        void getNextLine();
        void incrementLineNumber();
        bool isFileOff();
};

#endif