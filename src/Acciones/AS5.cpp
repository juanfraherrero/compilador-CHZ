#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 5 ('-','/') se encarga de:
        guarda el caracter en el buffer del automaton
        guardar en la tabla de símbolos el token operador
*/
class AS5 : public AccionSemantica {
    private:
        
    public:
        AS5(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;

            //guardar en la tabla de símbolos el operador (id:52)
            tableSymbol->insert(lexeme, lexeme, 52);

            // encontramos un identificador y definimos el token como identificador
            automaton->getToken()->token = 52;
        };

        string name() override {
            return "AS5";
        };
};