#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 10 (Comparadores) se encarga de:
        Verifica si el caracter leído es un '='
            Si lo es lo concatena al lexema y devuelve el id del respectivo comparador
            Si no lo es guarda en le buffer el caracter, y devuelve el token asociado usando el código ASCII
*/
class AS10 : public AccionSemantica {
    private:
        
    public:
        AS10(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            
            if(characterReaded == '='){
                // concatena el caracter al lexema
                automaton->getToken()->lexeme += characterReaded;

                string lexeme = automaton->getToken()->lexeme;

                if (lexeme == "<=") {
                    automaton->getToken()->token = id_COMPARADOR_MENOR_IGUAL;
                } else if (lexeme == ">=") {
                    automaton->getToken()->token = id_COMPARADOR_MAYOR_IGUAL;
                } else if (lexeme == "==") {
                    automaton->getToken()->token = id_COMPARADOR_IGUAL_IGUAL;
                }
                
                
            }
            else{
                // guarda el caracter en el buffer del automaton
                automaton->setBuffer(characterReaded);

                // convertimos el caracter a su valor ASCII
                int valorAscii = static_cast<int>(automaton->getToken()->lexeme[0]);

                // encontramos un '<', '>', '=' y definimos el identificador en token
                automaton->getToken()->token = valorAscii;
            }

            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS10";
        };
};