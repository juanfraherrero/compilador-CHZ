#ifndef _TYPES_H_
#define _TYPES_H_

#include "AccionSemantica.hpp"

#include <iostream>

using namespace std;

struct tokenWithLexeme {
    int token;
    string lexeme;
};

struct valueOfMatrix
{
    int next_state;
    AccionSemantica * accionp;
};

// Definición de la estructura que contiene un string y un entero
struct symbol {
    std::string name;   //lexema
    int value;          //id del token

    symbol(const string& n, int v) : name(n), value(v) {}
};


#endif