#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La accion semantica de WARNING 4 se encarga de:
    Imprimir por pantalla un mensaje de que el usuario quiere realizar una comparacion, falta el caracter ! para completar la comparación.
        
*/
class W4 : public AccionSemantica {
    private:
        
    public:
        W4(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {

            cerr << "\033[33m" <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Warning: Falta de caracter '!' en el comparador '!!'"<< "\033[0m" << endl;
            
            return 19;
        } ;
        string name() override {
            return "W4";
        } ;
};