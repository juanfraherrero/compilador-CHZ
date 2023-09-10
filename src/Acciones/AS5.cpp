#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 5 ('-','/','.') se encarga de:
        guarda el caracter en el buffer del automaton
        devolver el identificador de esos caracteres
*/
class AS5 : public AccionSemantica {
    private:
        
    public:
        AS5(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;
            
            // convertimos el caracter a su valor ASCII
            int valorAscii = static_cast<int>(lexeme[0]);

            // encontramos un '-', '/', '.' y definimos el identificador en token
            automaton->getToken()->token = valorAscii;

            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS5";
        };
};