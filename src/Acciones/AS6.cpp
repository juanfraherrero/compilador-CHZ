#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "./E5.cpp"
#include "./W3.cpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 6 (palabras reservadas) se encarga de:
        guarda el caracter en el buffer del automaton
        verifica si lapalabra tiene minúsucluas en tal caso informa un warning
        verifica si existe la palabra reservada en el lenguaje, sino informa un error
        setea el id de la palabra reservada en el token
*/
class AS6 : public AccionSemantica {
    private:
        E5 error;
        W3 warning;

        string toUppercaseString(const string& texto) {
            string resultado = texto; // Copia el texto original

            for (char& c : resultado) {
                c = toupper(c); // Convierte cada caracter a mayúsculas
            }

            return resultado;
        }

    public:
        AS6(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // obtiene el string que se fue concatenando
            string lexeme = automaton->getToken()->lexeme;
            string lexemeUpper = toUppercaseString(lexeme);
            // verificamos si la palabra reservada tiene minúsculas
            if(lexeme != lexemeUpper){
                // avisamos que truncamos el lexema
                warning.execute(automaton, characterReaded, tableSymbol,tableRWords);
                lexeme = lexemeUpper;
            }

            int id = tableRWords->getId(lexeme);
            if(id != -1){
                //seteamos el id de la palabra reservada de palabras reservadas
                automaton->getToken()->token = id;
            }else{
                // la palabra reservada no existe
                return this->error.execute(automaton, characterReaded, tableSymbol,tableRWords);
            }
            
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS6";
        };
};