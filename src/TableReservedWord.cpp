#include "include/TableReservedWord.hpp"

#include <iostream>
#include <string>
#include <map>

using namespace std;

TableReservedWord::TableReservedWord(){    
    // insertar las palabras reservadas
    insert("VOID",267);
    insert("RETURN",268);
    insert("IF",269);
    insert("ELSE",270);
    insert("END_IF",271);
    insert("PRINT",272);
    insert("WHILE",273);
    insert("DO",274);
    insert("SHORT",275);
    insert("UINT",276);
    insert("FLOAT",277);
    insert("TOF",278);
    insert("CLASS",279);
};

// devuelve el nro de token asociado al lexema
int TableReservedWord::getId(const string& lexema) {

    auto it = wordMap.find(lexema);
    if (it != wordMap.end()) {
        return it->second;
    }
    return -1;
}

// insertar una oalabra reservada
void TableReservedWord::insert(const string& word, int value) {
    wordMap.insert(pair<string, int>(word,value));
}

// Función para imprimir la tabla completa
void TableReservedWord::imprimirTabla() {
    cout << "\n\nTabla de palabras reservadas:\n\n" << endl;
    for (const auto& pair : wordMap) {
        cout << "Clave: " << pair.first << ", id: " << pair.second << endl;
    }
}
