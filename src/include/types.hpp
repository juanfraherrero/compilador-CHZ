#ifndef _TYPES_H_
#define _TYPES_H_

#include "AccionSemantica.hpp"
#include "Tercets.hpp"

#include <iostream>
#include <vector>

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
    string type;            // define un tipo                       SHORT, FLOAT
    string uso;             // define el uso de cada variable.      metodo, variable, parametro, funcion
    unsigned int cantParam = 0;       // define si la funcion tiene o no parametro, 0 si no tiene, 1 si tiene si el uso es función o método
    string typeParam;       // define si es que tiene parámetro el tipo
    string nameParam;       // define el nombre del parámetro
    string fullIdentifier;  // define el identificador completo, se usa para el truncado
    int count;              // se usa para contabilizar cuantos lexemas apuntan al mismo elemento
    bool forwarded = false; // se usa para saber si el simbolo fue forwardado o no
    TableSymbol* attributesAndMethodsVector; // se usa para que tengamos los atritbutos y métodos de una clase en este vector en heap de simbolos del heap
    // string hereda[3] = {"","",""};


    symbol(const string& _lexema) : lexema(_lexema), count(1) {};
    symbol(const string& _lexema, string _value) : lexema(_lexema), value(_value), count(1) {};
    symbol(const string& _lexema, string _value, string _type) : lexema(_lexema), value(_value), type(_type), count(1) {};
    symbol(const string& _lexema, string _value, string _type, string _uso) : lexema(_lexema), value(_value), type(_type), uso(_uso), count(1) {};
    symbol(const string& _lexema, string _value, string _type, string _uso, string _fi) : lexema(_lexema), value(_value), type(_type), uso(_uso), count(1), fullIdentifier(_fi) {};
    
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

struct functionStack {
    string name;
    Tercets * ter;

    functionStack(string _name) : name(_name){};
};

#endif