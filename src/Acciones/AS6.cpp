#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 6 ('.'. palabras reservadas) se encarga de:
        guarda el caracter en el buffer del automaton
        setea el id de la palabra reservada en el token
*/
class AS6 : public AccionSemantica {
    private:
        
    public:
        AS6(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;

            //obtener id de la tabla de palabras reservadas
            automaton->getToken()->token = tableRWords->getId(lexeme);
            
        };

        string name() override {
            return "AS6";
        };
};