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
        string scope; 
        unsigned short int cantVartruncated = 0;
        int auxVariable = 0;
    public:
        // Constructor
        TableSymbol();
        TableSymbol(string _scope);
        // devuelve un puntero al simbolo buscado
        symbol* getSymbol(const string& key);

        // insertar un elemento en la tabla
        void insert(const string& key, const string& lexema, const string& value,const string& type); 

        // inserta un simbolo en la tabla
        void insert(symbol * symbol);

        // inserta un identificardor a la tabla checkeando el fullIdentifier
        string insertIdentifierTruncated(const string& key, const string& lexema, const string& value, const string& type, string fullIdentifier);

        // eliminar un elemento de la tabla decrementando su contador
        void deleteSymbol(const string& key);
        
        //Funcion que busca añadir el nuevo scope a la variable 
        void addScope(const string& ambito);
        
        //Funcion que busca eliminar el ultimo scope a la variable
        void deleteScope();
        
        //Funcion que devuelve el valor del la variable scope actual
        string getScope();

        //funcion para setear un valor a la variable cantParam
        void setCantParam(const string& key, const string& cant);
        //funcion para devolver el valor de la variable cantParam, 
        // si te devuelve false es por que no tiene parametros
        // si te devuelve 1 tiene parametros
        int getCantParam(const string& key);
        //funcion para devolver el valor de la variable cantParam
        void setTypeParam(const string& key, const string& type);
        //funcion para devolver el valor de la variable cantParam
        string returnTypeParam(const string& key);
        // Función para imprimir la tabla completa
        void imprimirTabla();
        // Función para imprimir atributos y métodos de las clases
        void imprimirAtributosMetodos();
        //funcion para setear un valor a la variable uso
        void setUso(const string& uso, const string& key);
        //funcion para devolver el valor de la variable uso
        string getUso(const string& key);

        symbol* getFirstSymbolMatching(const string& ambito,const string& uso, const string& scope);
        int getDiffOffScope(const string ambito, const string& uso, const string& scope);

        symbol* getFirstSymbolMatching2(const string var,const string uso, string scope);
        int getDiffOffScope2(const string var, const string uso, string scope);

        bool existMethodInTable(string key,string uso);
        bool isTheSpecificLexemaInTable(string lexema);    //verifica si existe un elemento con el mismo lexema
        symbol* getElementInTableByFisrtPartAndUse(const string key, const string uso);  // devuelva la primera apariciónde un simbolo con el mismo nombre de simbolo y mismo uso    
        vector<symbol*> getSymbolsByUseAndNameClassAndForwarded(string use, string className); // devuelve un vector de los símbolos que coincida con uso y clase y tengan forwarded en true forwarded
        
        // Destructor para liberar la memoria de los símbolos
        ~TableSymbol();

        unordered_map<string, symbol*> getSymbolTable();
        //funciones auxiliares

        bool CompareUse(const string ambito, const string uso);
};

#endif