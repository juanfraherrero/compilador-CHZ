#ifndef _TYPES_H_
#define _TYPES_H_

#include "AccionSemantica.hpp"

#include <iostream>

using namespace std;

// struct para el tipo del token que devuelve el léxico
struct tokenWithLexeme {
    int token;
    string lexeme;
    string type;
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
    string uso;             // define el uso de cada variable.
    string cantParam;        // define si la funcion tiene o no parametro, 0 si no tiene, 1 si tiene
    string typeParam;       //define si es que existe el tipo de parametro
    int count;

    symbol(const string& _lexema) : lexema(_lexema), count(1) {};
    symbol(const string& _lexema, string _value) : lexema(_lexema), value(_value), count(1) {};
    symbol(const string& _lexema, string _value, string _type) : lexema(_lexema), value(_value), type(_type), count(1) {};
    symbol(const string& _lexema, string _value, string _type, string _uso) : lexema(_lexema), value(_value), type(_type), uso(_uso), count(1) {};
    
    // Función para obtener una representación en forma de cadena
    string ToString() const {
        return "Lexema: " + lexema + "\t Valor:| " + value + "\t Tipo: " + type + "\t Uso: " + uso;
    }
};

struct myTypeYYLVAL {
    string ptr;
    string type;

    myTypeYYLVAL(string _ptr, string _type) : ptr(_ptr), type(_type) {};
};

#endif