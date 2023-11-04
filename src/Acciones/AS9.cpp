#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./W2.cpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 9 (Identificadores) se encarga de:
        guarda el caracter en el buffer del automaton
        trunca el lexema a una logitud de 20 caracteres
        guardar en la tabla de símbolos el identificador
*/
class AS9 : public AccionSemantica {
    private:
        W2 warning;
    public:
        AS9(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string fullLexeme = automaton->getToken()->lexeme;

            // si el lexema tiene más de 20 caracteres lo trunca
            if(fullLexeme.length() > 20){
                this->warning.execute(automaton, characterReaded, tableSymbol, tableRWords);
                
                string shortLexeme = automaton->getToken()->lexeme; // obtenemos el lexema truncado
                
                //insertamos en la tabla de símbolos el identificador 
                    // con el lexema como key, el lexema y el valor que es el lexema
                    // el insert checkea la existencia de otro lexema igual 
                    // la clave y el lexema seran cambiados a una variable interna
                string newLexeme = tableSymbol->insertIdentifierTruncated(shortLexeme, shortLexeme, "-", "identifier", fullLexeme);
                automaton->getToken()->lexeme = newLexeme; // seteamos el nuevo lexema para que le pase al parsing
            
            }else{
                //insertamos en la tabla de símbolos el identificador
                    // con el lexema como key, el lexema y el valor que es el lexema
                    // el insert checkea la existencia de otro lexema igual 
                    // la clave y el lexema seran cambiados a una variable interna
                tableSymbol->insert(fullLexeme, fullLexeme, "-", "identifier");
            }


            
            
            //definimos el token como un identificador
            automaton->getToken()->token = id_IDENTIFICADOR;

            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS9";
        };
};