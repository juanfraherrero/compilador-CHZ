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
void TableSymbol::insert(const string& key, const string& lexema, const string& value, const string& type) {
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        // encontró un símbolo con esa clave
        // incrementamos el contador de ese símbolo
        it->second->count++;
    }else{
        //no encontró un símbolo con esa clave
        // Crear un nuevo simbolo y almacenarlo en la tabla
        symbol* newSymbol = new symbol(lexema, value, type);
        symbolTable[key] = newSymbol;
    }
    

}

// Función para imprimir la tabla completa
void TableSymbol::imprimirTabla() {
    cout << "\n\nTabla de símbolos:\n\n" << endl;
    for (const auto& pair : symbolTable) {
        const symbol* symbol = pair.second;
        cout << "Clave: " << pair.first << "\t Lexema: " << symbol->lexema << "\t Valor: " << symbol->value << "\t Tipo: " << symbol->type << endl;
    }
}

void TableSymbol::deleteSymbol(const string& key){
    // buscamos si ya existe ese símbolo en la tabla
    auto it = symbolTable.find(key);
    if (it != symbolTable.end()) {
        //no encontró un símbolo con esa clave
        // decrementamos el contador de ese símbolo   
        it->second->count--;
        if(it->second->count <= 0){
            // si el contador es 0 o menor, eliminamos el símbolo de la tabla
            delete it->second;
            symbolTable.erase(it);
        }
    }
}

// Destructor para liberar la memoria de los símbolos
TableSymbol::~TableSymbol() {
    for (auto& pair : symbolTable) {
        delete pair.second;
    }
}
