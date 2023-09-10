#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La accion semantica de WARNING 1 se encarga de:
        Guardar el caracter en el buffer del automaton.
        Concatenar el caracter agregado al lexema.
        Indicar un warning por pantalla de que se agrego una "i" al final del entero sin signo.
*/
class W1 : public AccionSemantica {
    private:
        
    public:
        W1(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guardamos el caracter en el buffer
            automaton->setBuffer(characterReaded);

            // concatenas el caracter leído al lexema
            automaton->getToken()->lexeme += 'i'; 

            // informamos que se agregó una 'i'
            cerr << "\033[33m" <<"Linea: " << *(automaton->getPtrLineNumber()) << "-> Warning: Se agrego una 'i' al final del entero sin signo" << "\033[0m" << endl;
            return 0;
        } ;
        string name() override {
            return "W1";
        } ;
};