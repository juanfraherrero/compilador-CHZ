#ifndef _TYPES_H_
#define _TYPES_H_

#include "AccionSemantica.hpp"

#include <iostream>

using namespace std;

// struct para el tipo del token que devuelve el léxico
struct tokenWithLexeme {
    int token;
    string lexeme;
};

// struct para los valores que contiene la matriz del autómata
struct valueOfMatrix
{
    int next_state;
    AccionSemantica * accionp;
};

// Definición de la estructura que contiene un string y un entero
struct symbol {
    string lexema;          // lexema
    string value;           // valor del token
    string type;            // define un tipo

    symbol(const string& _lexema) : lexema(_lexema) {}
    symbol(const string& _lexema, string _value) : lexema(_lexema), value(_value) {}
};


#endif