#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 4 (Enteros sin signo 0 a 65535) se encarga de:
        Verificar si el caracter leído es 'i'
            Si es Concatenarmos el caracter al string
            Si no es al strig le agregamos la i, y guardamos el caracter en el buffer, luego informamosun warning de que se agregó una 'i'
        checkear que el lexema no se pase de rango
        verifcar si está en la tabla de símbolos sino agregarlo
*/

class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            
            if (characterReaded == 'i'){
                // concatenas el caracter leído al lexema
                automaton->getToken()->lexeme += characterReaded; 
            }else{
                // guardamos el caracter en el buffer
                automaton->setBuffer(characterReaded);

                // concatenas el caracter leído al lexema
                automaton->getToken()->lexeme += 'i'; 

                // informamos que se agregó una 'i'
                cerr << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Warning: Se agregó una 'i' al final del entero sin signo" << endl;
            }
            
            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;
            
            int value;

            try {
                value = std::stoi(lexeme); // Convierte el string a int
                
                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(value >= 0 && value <= 65535){
                    // verificamos si ya existe la constante entera corta en la tabla de símbolos
                    if(tableSymbol->getSymbol(lexeme)== nullptr){
                        // obtenemos el valor del entero sin signo
                        size_t pos = lexeme.find("_ui");
                        string value = lexeme.substr(0, pos);

                        //insertamos en la tabla de símbolos el short int 
                            // con el lexema como key, el lexema, el valor
                        tableSymbol->insert(lexeme, lexeme, value);
                    }

                    //definimos el token como short int
                    automaton->getToken()->token = id_CONSTANTE_ENTERO_SIN_SIGNO;

                }else{
                    throw std::out_of_range("El número está fuera del rango permitido");
                }
            } catch (const std::out_of_range& e) {
                
                cerr << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por entero sin signo fuera de rango { 0 - 65535 }" << endl;

                // al ser un error forzamos volver al estado 0 y vaciamos el lexema
                automaton->getToken()->lexeme = "";
                return 0;
            }

            // desde la acción no modificamos el siguiente estado
            return -1;

        } ;
        string name() override {
            return "AS4";
        } ;
};