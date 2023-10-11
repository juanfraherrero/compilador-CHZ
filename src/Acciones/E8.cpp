#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 8 se encarga de:
        Indicar un error por pantalla de un entero sin signo fuera de rango.
        Vaciar el string del lexema.
        Volver al estado 0.
*/
class E8 : public AccionSemantica {
    private:
        
    public:
        E8(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por entero sin signo fuera de rango { 0 - 65535 }" << "\033[0m" << endl;
            
            //define that code have an error
            isErrorInCode = true;
            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;
        } ;
        string name() override {
            return "E8";
        } ;
};