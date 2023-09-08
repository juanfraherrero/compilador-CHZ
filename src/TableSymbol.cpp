#include "include/types.hpp"
#include "include/TableSymbol.hpp"

#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

// devuelve un puntero al simbolo buscado
symbol* TableSymbol::getSymbol(const string& key) {

    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        return it->second; // Devolver el puntero al símbolo si se encuentra
    }
    return nullptr; // Devolver nullptr si la clave no se encuentra
}

// insertar un elemento en la tabla
void TableSymbol::insert(const string& key, const string& lexema, const string& value) {
    
    // Crear un nuevo simbolo y almacenarlo en la tabla
    symbol* newSymbol = new symbol(lexema, value);
    symbolTable[key] = newSymbol;
}

// Función para imprimir la tabla completa
void TableSymbol::imprimirTabla() {
    cout << "Tabla de símbolos:" << endl;
    for (const auto& pair : symbolTable) {
        const symbol* symbol = pair.second;
        cout << "Clave: " << pair.first << ", Lexema: " << symbol->lexema << ", Valor: " << symbol->value << endl;
    }
}

// Destructor para liberar la memoria de los símbolos
TableSymbol::~TableSymbol() {
    for (auto& pair : symbolTable) {
        delete pair.second;
    }
}
