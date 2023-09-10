#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 14 (Punto Flotante) se encarga de:
        guarda el caracter en el buffer del automaton
        checkea el rango de la constante de Punto Flotante (sino está en rango avisa del error y vuelve al estado 0)
        guardar en la tabla de símbolos la constante de Punto Flotante

*/
class AS14 : public AccionSemantica {
    private:
        bool isInRange(const string& _str) {

            // Definir los límites del rango ENUNCIADO
            const double limitInf = 1.17549435E-38;
            const double limitSup = 3.40282347E+38;

            double value;

            try {
                value = std::stod(_str); //convertimos el string a double

                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(value > limitInf && value < limitSup){
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
                
                // verificamos si el lexema está en la tabla de símbolos
                if(tableSymbol->getSymbol(lexeme) == nullptr){

                    //insertamos en la tabla de símbolos la constante de punto flotante 
                        // con el lexema como key, el lexema, el valor es el mismo lexema
                    tableSymbol->insert(lexeme, lexeme, lexeme);
                }

                // encontramos una constante de punto flotante y definimos el token como constante
                automaton->getToken()->token = id_CONSTANTE_PUNTO_FLOTANTE;

                // desde la acción no modificamos el siguiente estado
                return -1;
            }
            else{
                std::cerr <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Error en constante de punto flotante fuera de rango " << endl;
                
                // al ser un error forzamos volver al estado 0 y vaciamos el lexema
                automaton->getToken()->lexeme = "";
                return 0;
            };
            
        };

        string name() override {
            return "AS14";
        };
};