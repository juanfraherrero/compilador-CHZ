#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 5 (deteccion de palabra reservada desconocida) se encarga de:
        Indicar un error por pantalla de Palabra reservada desconocida por el lenguaje
        Vaciar el string del buffer 
        Volver al estado 0
*/
class E5 : public AccionSemantica {
    private:
        
    public:
        E5(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {

            std::cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Palabra reservada desconocida por el lenguaje"  << "\033[0m" << endl;
            
            //define that code have an error
            isErrorInCode = true;

            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;    
        } ;
        string name() override {
            return "E5";
        } ;
};