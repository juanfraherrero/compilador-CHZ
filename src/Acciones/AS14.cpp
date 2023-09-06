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
class AS9 : public AccionSemantica {
    private:
        bool isInRange(const string& _str) {

            /*
                limites de float. 
                El problema es que solo toman hasta 6 digitos decimales, y en el enunciado nos pide checkear 8 y no seríamos precisos
                terminamos usando double (64bits) pero podemos checkear el rango de forma precisa
            
            // string limiteFloat = "3.40282356E+38"; 
            // string limiteFloat2 = "1.17549432E-38"; 
            // string limiteFloat3 = "-3.40282356E+38";
            // string limiteFloat4 = "-1.17549432E-38";

            */

            // Definir los límites del rango ENUNCIADO
            double limitPositiveInf = 1.17549435E-38;
            double limitPositiveSup = 3.40282347E+38;
            double limitNegativeInf = -3.40282347E+38;
            double limitNegativeSup = -1.17549435E-38;

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

            } catch (const std::invalid_argument& e) {

                // no debería llegar nunca a este caso

                std::cerr << "Error de conversión: " << e.what() << std::endl;
                return false;
                
            } catch (const std::out_of_range& e) {
                // std::cerr << "Desbordamiento al convertir: " << e.what() << std::endl;

                // si se pasa de rango debemos lanzar un warning
                //
                //
                //
                return false;
            }
        }

    public:
        AS9(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cout << "AS9" << endl;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;

            // checkea el rango de la constante de Punto Flotante
            if(isInRange(lexeme)){
                // guardar en la tabla de símbolos la constante de Punto Flotante (id: 50)
                tableSymbol->insert(lexeme, lexeme, 50);

                // encontramos una constante de punto flotante y definimos el token como constante
                automaton->getToken()->token = 50;
            }
            else{
                // lanzar warning
                // cout << "Warning: la constante de Punto Flotante está fuera de rango" << endl;
            };
            
        };

        string name() override {
            return "AS9";
        };
};