#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "./E5.cpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 6 (palabras reservadas) se encarga de:
        guarda el caracter en el buffer del automaton
        setea el id de la palabra reservada en el token
*/
class AS6 : public AccionSemantica {
    private:
        E5 error;
    public:
        AS6(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;

            int id = tableRWords->getId(lexeme);
            if(id != -1){
                //seteamos el id de la palabra reservada de palabras reservadas
                automaton->getToken()->token = id;
            }else{
                // la palabra reservada no existe
                return this->error.execute(automaton, characterReaded, tableSymbol,tableRWords);
            }
            
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS6";
        };
};