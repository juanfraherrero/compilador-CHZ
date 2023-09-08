#ifndef _TABLESTSYMBOL_H_
#define _TABLESTSYMBOL_H_

#include "types.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

class TableSymbol{

    private:
        // Unordered map con clave de string y valor de puntero a symbol (estrcutura definida en types.hpp)
        unordered_map<string, symbol*> symbolTable;

    public:

        // devuelve un puntero al simbolo buscado
        symbol* getSymbol(const string& key);

        // insertar un elemento en la tabla
        void insert(const string& key, const string& lexema, const string& value);

        // Función para imprimir la tabla completa
        void imprimirTabla();

        // Destructor para liberar la memoria de los símbolos
        ~TableSymbol();
};

#endif