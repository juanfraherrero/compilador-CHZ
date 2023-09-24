#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica de ERROR 7 se encarga de:
        Indicar un error por pantalla de un simbolo cualquiera luego de un "!".
        Guardar el caracter en el buffer del automaton.
        Vaciar el string del lexema.
        Volver al estado 0.
*/
class E7 : public AccionSemantica {
    private:
        
    public:
        E7(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            std::cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << " -> Error: '!' no es parte del lenguaje" << "\033[0m" <<endl;
            
            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;   
        } ;
        string name() override {
            return "E7";
        } ;
};