#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 13 (para la cadena de caracteres cuando recibe el final '#') se encarga de:
        Concatenar al lexema el caracter leído
        verifcar si está en la tabla de símbolos sino agregarlo
        setear el id del token id_CONSTANTE_CADENA_CARACTERES
*/
class AS13 : public AccionSemantica {
    private:
        
    public:
        AS13(){};

        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            
            // concatenamos el caracter leído al lexema
            automaton->getToken()->lexeme += characterReaded;

            string lexeme = automaton->getToken()->lexeme;

            // verificamos si el lexema está en la tabla de símbolos
            if(tableSymbol->getSymbol(lexeme) == nullptr){

                // obtenemos el valor del entero sin los dos #
                string value = lexeme.substr(1, lexeme.length() - 2);

                //insertamos en la tabla de símbolos la cadena de caracteres 
                    // con el lexema como key, el lexema, el valor es el lexema sin los #
                tableSymbol->insert(lexeme, lexeme, value);
            }

            //definimos el token como cadena de caracteres
            automaton->getToken()->token = id_CONSTANTE_CADENA_CARACTERES;

            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS13";
        };
};