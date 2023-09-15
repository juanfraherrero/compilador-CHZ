#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 8 (para el fin de un comentario) se encarga de:
        vaciar el lexema
*/
class AS8 : public AccionSemantica {
    private:
        
    public:
        AS8(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // vaciar el lexema
            automaton->getToken()->lexeme = "";
            automaton->setCommentIsActive(false);
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS8";
        };
};