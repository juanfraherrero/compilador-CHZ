#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include "./E6.cpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 14 (Punto Flotante) se encarga de:
        guarda el caracter en el buffer del automaton
        checkea el rango de la constante de Punto Flotante (sino está en rango avisa del error y devuelve un 0.0 y va al estado final)
        guardar en la tabla de símbolos la constante de Punto Flotante

*/
class AS14 : public AccionSemantica {
    private:
        E6 error;
        bool isInRange(const string& _str) {

            // Definir los límites del rango ENUNCIADO
            const double limitInf = 1.17549435E-38;
            const double limitSup = 3.40282347E+38;

            double value;

            try {
                value = std::stod(_str); //convertimos el string a double

                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if((value > limitInf && value < limitSup) || value == 0.0){
                    return true;
                }
                else{
                    throw std::out_of_range("El número está fuera del rango permitido");
                }

            } catch (const std::out_of_range& e) {
                return false;
            }
        }

    public:
        AS14(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;

            // checkea el rango de la constante de Punto Flotante
            if(isInRange(lexeme)){

                //insertamos en la tabla de símbolos la constante de punto flotante 
                    // con el lexema como key, el lexema, el valor es el mismo lexema
                    // el insert checkea la existencia de otro lexema igual 
                tableSymbol->insert(lexeme, lexeme, lexeme, "float");

                // encontramos una constante de punto flotante y definimos el token como constante
                automaton->getToken()->token = id_CONSTANTE_PUNTO_FLOTANTE;
                automaton->getToken()->type = "float";
                
                // desde la acción no modificamos el siguiente estado
                return -1;
            }
            else{
                //Fuera de rango
                return this->error.execute(automaton, characterReaded, tableSymbol, tableRWords);
            };
            
        };

        string name() override {
            return "AS14";
        };
};