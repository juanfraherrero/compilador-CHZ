#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 4 (Enteros sin signo 0 a 65535) se encarga de:
        concantenar un caracter al lexema. 
        checkear que el lexema no se pase de rango (checkear al no poder ser negativo)
        verifcar si está en la tabla de símbolos
*/

class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            automaton->getToken()->lexeme += characterReaded; // concatenas el caracter leído al lexema
            
            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;
            
            int value;

            try {
                value = std::stoi(lexeme); // Convierte el string a int
                
                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(value >= 0 && value <= 65535){

                    //Cargar en la tabla de símbolos el short int (id: 51)
                    tableSymbol->insert(lexeme, lexeme, "51");

                    // encontramos un short int y definimos el token como short int
                    automaton->getToken()->token = 51;

                }else{
                    throw std::out_of_range("El número está fuera del rango permitido");
                }
            } catch (const std::out_of_range& e) {
                
                cerr <<"Error por entero sin signo fuera de rango { 0 - 65535 } - Linea " << *(automaton->getPtrLineNumber()) << endl;

            }

        } ;
        string name() override {
            return "AS4";
        } ;
};