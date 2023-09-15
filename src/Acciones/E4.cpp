#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 4 (deteccion de entero corto fuera de rango) se encarga de:
        Indicar un error por pantalla de entero fuera de rango
        Vaciar el string del buffer 
        Volver al estado 0
*/
class E4 : public AccionSemantica {
    private:
        
    public:
        E4(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {

            std::cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por entero corto fuera de rango { -128 - 127 }"  << "\033[0m"<< endl;

            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;    
        } ;
        string name() override {
            return "E4";
        } ;
};