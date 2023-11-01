#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./W4.cpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 15 ('!!') se encarga de:
        Verificar si es un '!'
            Si es un '!' se devuelve el identificador de token asociado a id_COMPARADOR_DISTINTO
            sI NO es '!' se guarda el caracter leído y se devuelve el identificador de token asociado a id_COMPARADOR_DISTINTO informando un warning
*/
class AS15 : public AccionSemantica {
    private:
        W4 warning;
    public:
        AS15(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
           

            //definimos el token como un comparador distinto
            automaton->getToken()->token = id_COMPARADOR_DISTINTO;

            //Si el caracter leido es distinto de "!" informamos un warning
            if(characterReaded != '!'){
                //guardamos el caracter leido
                automaton->setBuffer(characterReaded);
                
                //Simbolo distinto de "!" luego de un "!".
                return this->warning.execute(automaton, characterReaded, tableSymbol, tableRWords);
            }

            // desde la acción no modificamos el siguiente estado
            return -1;
            
        };

        string name() override {
            return "AS15";
        };
};