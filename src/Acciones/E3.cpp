#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 3 (detección de un salto de línea en cadena de texto) se encarga de:
        Indicar un error por pantalla de salto de línea inválido 
        Guardar el caracter en el buffer 
        Vaciar el string del buffer 
        volver al estado 0
*/
class E3 : public AccionSemantica {
    private:
        
    public:
        E3(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: salto de línea en cadena de texo " << "\033[0m"<< endl;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;    
        } ;
        string name() override {
            return "E3";
        } ;
};