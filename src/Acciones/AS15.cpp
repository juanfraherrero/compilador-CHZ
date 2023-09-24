#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./E7.cpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 15 ('!!') se encarga de:
        Verificar si es un '!'
            Si es un '!' se devuelve el identificador de token asociado a id_COMPARADOR_DISTINTO
            sI NO es '!' se guarda el caracter leído y se retorna un error de caracter no reconocido
*/
class AS15 : public AccionSemantica {
    private:
        E7 error;
    public:
        AS15(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
           
            if(characterReaded == '!'){
                automaton->getToken()->token = id_COMPARADOR_DISTINTO;
            }
            else{
                //Simbolo distinto de "!" luego de un "!".
                return this->error.execute(automaton, characterReaded, tableSymbol, tableRWords);
            }

            // desde la acción no modificamos el siguiente estado
            return -1;
            
        };

        string name() override {
            return "AS15";
        };
};