#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 6 (deteccion constante de punto flotante fuera de rango) se encarga de:
        Indicar un error por pantalla de constante de punto flotante fuera de rango
        Vaciar el string del buffer 
        Volver al estado 0
*/
class E6 : public AccionSemantica {
    private:
        
    public:
        E6(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {

            std::cerr << "\033[31m" <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Error: Error en constante de punto flotante fuera de rango " << "\033[0m" << endl;
            
            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;
        } ;
        string name() override {
            return "E6";
        } ;
};