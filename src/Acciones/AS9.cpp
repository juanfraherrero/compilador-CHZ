#include "../include/Acciones/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción emántica 9 se encarga de:
        guarda el caracter en el buffer del automaton
        trunca el lexema a una logitud de 20 caracteres
        guardar en la tabla de símbolos el identificador
*/
class AS9 : public AccionSemantica {
    private:
        
    public:
        AS9(){};
        void execute(Automaton* automaton, char characterReaded) override {
            cout << "AS9" << endl;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // trunca el lexema a una logitud de 20 caracteres
            automaton->getToken()->lexeme = automaton->getToken()->lexeme.substr(0, 20);

            //guardar en la tabla de símbolos el identificador
            ////symbolTable.insert(automaton->getToken()->lexeme);
        };
        string name() override {
            return "AS9";
        };
};