#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 11 ('{','}','(',')',',';') se encarga de:
        Devuelve el identificador de esos caracteres que es su código ASCII
*/
class AS11 : public AccionSemantica {
    private:
        
    public:
        AS11(){};

        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // convertimos el caracter a su valor ASCII
            int valorAscii = static_cast<int>(characterReaded);

            // encontramos un '{','}','(',')',',';' y definimos el identificador en token
            automaton->getToken()->token = valorAscii;
            
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS11";
        };
};