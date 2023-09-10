#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 2 (detección de un caracter no válido en una constante numérica) se encarga de:
        Indicar un error por pantalla de caracter no válido detectado 
        Guardar el caracter en el buffer 
        Vaciar el string del buffer 
*/
class E2 : public AccionSemantica {
    private:
        
    public:
        E2(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: en constante numérica " << endl;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;    
        } ;
        string name() override {
            return "E2";
        } ;
};