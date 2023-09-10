#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica se encarga de concatenar un caracter al lexema.
*/
class AS2 : public AccionSemantica {
    private:
        
    public:
        AS2(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            automaton->getToken()->lexeme += characterReaded; // concatenas el caracter leído al lexema

            // desde la acción no modificamos el siguiente estado
            return -1;
        } ;
        string name() override {
            return "AS2";
        } ;
};
