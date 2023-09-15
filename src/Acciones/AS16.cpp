#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 16 ('*{') se encarga de:
        setear al automaton de que se abrió un comentario y el comentario está activo
*/
class AS16 : public AccionSemantica {
    public:
        AS16(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
           
            //seteamos que se abrió un comentario y el comentario está activo
            automaton->setCommentIsActive(true);

            // desde la acción no modificamos el siguiente estado
            return -1;
            
        };

        string name() override {
            return "AS16";
        };
};