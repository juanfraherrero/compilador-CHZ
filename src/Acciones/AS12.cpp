#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 12 ('+' o '++') se encarga de:
        Verificar si se leyó un '+'
            si es un '+' se devuelve el identificador de token asociado a OPERADOR_SUMA_SUMA y se concatena al lexema el '+'
            Si no es un '+' se guarda el caracter leído y se devuelve el código ASCII del '+'
*/
class AS12 : public AccionSemantica {
    private:
        
    public:
        AS12(){};

        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            
            if(characterReaded == '+'){
                // concatena el caracter al lexema
                automaton->getToken()->lexeme += characterReaded;

                automaton->getToken()->token = id_OPERADOR_SUMA_SUMA;
                
            }
            else{
                // guarda el caracter en el buffer del automaton
                automaton->setBuffer(characterReaded);

                // convertimos el caracter '+' a su valor ASCII
                int valorAscii = static_cast<int>('+');

                // encontramos un '+' y definimos el identificador en token
                automaton->getToken()->token = valorAscii;    
            }

            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS12";
        };
};