#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 7 (cuando encontras un '/n') se encarga de:
        sumar uno al numero de linea
*/
class AS7 : public AccionSemantica {
    private:
        
    public:
        AS7(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // sumar uno al numero de linea
            (*(automaton->getPtrLineNumber()))++;
            
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS7";
        };
};