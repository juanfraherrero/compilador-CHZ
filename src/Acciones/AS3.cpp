#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 3 se encarga de:
        concantenar un caracter al lexema. 
        checkear que el lexema no se pase de rango 
        verifcar si está en la tabla de símbolos
*/
class AS3 : public AccionSemantica {
    private:
        
    public:
        AS3(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cout << "AS3" << endl;
            automaton->getToken()->lexeme += characterReaded; // concatenas el caracter leído al lexema
            
            //checkear que el lexema no se pase de rango 
            
            //verifcar si está enla tabla de símbolos

        } ;
        string name() override {
            return "AS3";
        } ;
};
