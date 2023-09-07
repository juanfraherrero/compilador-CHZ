#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 14 (Punto Flotante) se encarga de:
        guarda el caracter en el buffer del automaton
        checkea el rango de la constante de Punto Flotante
        guardar en la tabla de símbolos la constante de Punto Flotante

*/
class AS14 : public AccionSemantica {
    private:
        bool isInRange(const string& _str) {

            // Definir los límites del rango ENUNCIADO
            const double limitPositiveInf = 1.17549435E-38;
            const double limitPositiveSup = 3.40282347E+38;
            const double limitNegativeInf = -3.40282347E+38;
            const double limitNegativeSup = -1.17549435E-38;

            double value;

            try {
                value = std::stod(_str); //convertimos el string a double

                // si se puede convertir checkeamos que esté en los límtes que nos indicaron
                if(
                    (value > limitPositiveInf && value < limitPositiveSup)
                    ||
                    (value > limitNegativeInf && value < limitNegativeSup)
                    ){
                    
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
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            //checkear que el lexema no se pase de rango
            string lexeme = automaton->getToken()->lexeme;

            // checkea el rango de la constante de Punto Flotante
            if(isInRange(lexeme)){
                // guardar en la tabla de símbolos la constante de Punto Flotante (id: 50)
                tableSymbol->insert(lexeme, lexeme, 50);

                // encontramos una constante de punto flotante y definimos el token como constante
                automaton->getToken()->token = 50;
            }
            else{
                std::cerr << "Error por punto flotante fuera de rango - Linea " << *(automaton->getPtrLineNumber()) << endl;
            };
            
        };

        string name() override {
            return "AS14";
        };
};