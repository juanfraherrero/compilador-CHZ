#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./W1.cpp"
#include "./E8.cpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 4 (Enteros sin signo 0 a 65535) se encarga de:
        Verificar si el caracter leído es 'i'
            Si es Concatenarmos el caracter al string
            Si no es al strig le agregamos la i, y guardamos el caracter en el buffer, luego informamos un warning de que se agregó una 'i'
        checkear que el lexema no se pase de rango, si se pasa de rango se informa un error y se le devuelve al sintático un 0_ui para que no falle
        verifcar si está en la tabla de símbolos sino agregarlo
*/

class AS4 : public AccionSemantica {
    private:
        W1 warning;
        E8 error;
    public:
        AS4(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            
            if (characterReaded == 'i'){
                // concatenas el caracter leído al lexema
                automaton->getToken()->lexeme += characterReaded; 
            }else{
                //Emitimos el warning y ejecutamos la modificacion
                this->warning.execute(automaton, characterReaded, tableSymbol, tableRWords);
            }
            
            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;
            
            int value;

            try {
                value = std::stoi(lexeme); // Convierte el string a int
                
                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(value >= 0 && value <= 65535){
                    
                    // obtenemos el valor del entero sin signo
                    size_t pos = lexeme.find("_ui");
                    string value = lexeme.substr(0, pos);

                    //insertamos en la tabla de símbolos el short int 
                        // con el lexema como key, el lexema, el valor
                        // el insert checkea la existencia de otro lexema igual 
                    tableSymbol->insert(lexeme, lexeme, value, "unsigned int");

                    //definimos el token como short int
                    automaton->getToken()->token = id_CONSTANTE_ENTERO_SIN_SIGNO;
                    automaton->getToken()->type = "unsigned int";

                }else{
                    throw std::out_of_range("El numero esta fuera del rango permitido");
                }
            } catch (const std::out_of_range& e) {
                //Fuera de rango
                return this->error.execute(automaton, characterReaded, tableSymbol, tableRWords);
            }

            // desde la acción no modificamos el siguiente estado
            return -1;

        } ;
        string name() override {
            return "AS4";
        } ;
};