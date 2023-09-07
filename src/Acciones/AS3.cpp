#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 3 (Enteros cortos -128 a 127) se encarga de:
        concantenar un caracter al lexema. 
        checkear que el lexema no se pase de rango 
        verifcar si está en la tabla de símbolos
*/
class AS3 : public AccionSemantica {
    private:
        
    public:
        AS3(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            automaton->getToken()->lexeme += characterReaded; // concatenas el caracter leído al lexema
            
            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;
            
            /*
                Definir los límites del rango
                    usamos de 0 a 128
                    realmente es de -128 a 127 pero no podemos saber si es negativo o positivo
            */ 

            short int value;

            try {
                value = std::stoi(lexeme); // Convierte el string a short int
                
                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(value >= 0 && value <= 128){
                    //Cargar en la tabla de símbolos el short int (id: 49)
                    tableSymbol->insert(lexeme, lexeme, 49);

                    // encontramos un short int y definimos el token como short int
                    automaton->getToken()->token = 49;
                }else{
                    throw std::out_of_range("El número está fuera del rango permitido");
                }
            } catch (const std::out_of_range& e) {
                
                std::cerr << "Error por entero corto fuera de rango { -128 - 127 } - Linea " << *(automaton->getPtrLineNumber()) << endl;

            }
            

        } ;

        string name() override {
            return "AS3";
        } ;
};
