#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción emántica 9 (Identificadores) se encarga de:
        guarda el caracter en el buffer del automaton
        trunca el lexema a una logitud de 20 caracteres
        guardar en la tabla de símbolos el identificador
*/
class AS9 : public AccionSemantica {
    private:
        
    public:
        AS9(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // trunca el lexema a una logitud de 20 caracteres
            automaton->getToken()->lexeme = automaton->getToken()->lexeme.substr(0, 20);

            string lexeme = automaton->getToken()->lexeme;

            //guardar en la tabla de símbolos el identificador (id:48)
            tableSymbol->insert(lexeme, lexeme, "48");

            // encontramos un identificador y definimos el token como identificador
            automaton->getToken()->token = 48;
        };

        string name() override {
            return "AS9";
        };
};