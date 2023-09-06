#ifndef _TABLESTRESERVEDWORD_H_
#define _TABLESTRESERVEDWORD_H_

#include <iostream>
#include <string>
#include <map>

using namespace std;

class TableReservedWord {

private:
    // map con clave de string y valor de puntero a symbol (estrcutura definida en types.hpp)
    // Es un map, porque un unorder map al usar un hashing si te colisionan las palabras perdes alguna y es un problema. podría usarse un unorder multimap.
    map<string, int> wordMap;

public:
    
    TableReservedWord();

    int getId(const string& lexema);
    void insert(const string& word, int value);
    void imprimirTabla();
};

#endif