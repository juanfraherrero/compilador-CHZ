#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La accion semantica de WARNING 3 se encarga de:
    Imprimir por pantalla un mensaje de que la palabra reservada tiene minusculas y se convertira a mayusculas
        
*/
class W3 : public AccionSemantica {
    private:
        
    public:
        W3(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {

            cerr << "\033[33m" <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Warning: Palabra reservada '" << automaton->getToken()->lexeme <<"' tiene minúsculas y se convirtieron a mayúsuclas "<< "\033[0m" << endl;
            
            return 0;
        } ;
        string name() override {
            return "W3";
        } ;
};