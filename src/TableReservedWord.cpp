#include "include/TableReservedWord.hpp"

#include <iostream>
#include <string>
#include <map>

using namespace std;

TableReservedWord::TableReservedWord(){    
    // insertar las palabras reservadas
    insert("IF",1);
    insert("ELSE",2);
    insert("END_IF",3);
    insert("PRINT",4);
    insert("CLASS",5);
    insert("VOID",6);
    insert("SHORT",7);
    insert("UINT",8);
    insert("FLOAT",9);
    insert("WHILE",10);
    insert("DO",11);
    insert("RETURN",12);
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
