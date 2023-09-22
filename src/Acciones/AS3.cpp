#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./E4.cpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 3 (Enteros cortos -128 a 127) se encarga de:
        concantenar un caracter al lexema. 
        checkear que el lexema no se pase de rango 
        verifcar si está en la tabla de símbolos

    Al definir los límites del rango usamos de 0 a 128
        realmente es de -128 a 127 pero no podemos saber si es negativo o positivo
*/
class AS3 : public AccionSemantica {
    private:
        E4 error;
    public:
        AS3(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            automaton->getToken()->lexeme += characterReaded; // concatenas el caracter leído al lexema
            
            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;

            short int value;

            try {
                value = std::stoi(lexeme); // Convierte el string a short int
                
                // si se puede convertir checkeamos que esté en los límites que nos indicaron
                if(value >= 0 && value <= 128){
                    // obtenemos el valor del entero sin signo
                    size_t pos = lexeme.find("_s");
                    string value = lexeme.substr(0, pos);

                    //insertamos en la tabla de símbolos el short int 
                        // con el lexema como key, el lexema, el valor
                        // el insert checkea la existencia de otro lexema igual 
                    tableSymbol->insert(lexeme, lexeme, value, "short");

                    //definimos el token como short int
                    automaton->getToken()->token = id_CONSTANTE_ENTERO_CORTO;
                }else{
                    throw std::out_of_range("El número está fuera del rango permitido");
                }
            } catch (const std::out_of_range& e) {
                //Fuera de rango
                return this->error.execute(automaton, characterReaded, tableSymbol, tableRWords);
            }
            
            // desde la acción no modificamos el siguiente estado
            return -1;
            
        } ;

        string name() override {
            return "AS3";
        } ;
};
