#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 1 (detección de un caracter no válido en estado 0) se encarga de:
        Indicar un error por pantalla de caracter no válido detectado
*/
class E1 : public AccionSemantica {
    private:
        
    public:
        E1(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Caracter no válido detectado: " << characterReaded<< "\033[0m" << endl;

            // desde la acción no modificamos el siguiente estado
            return -1;     
        } ;
        string name() override {
            return "E1";
        } ;
};