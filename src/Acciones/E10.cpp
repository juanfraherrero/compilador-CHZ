#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 2 (detección de un caracter no válido en una constante numérica) se encarga de:
        Indicar un error por pantalla de caracter no válido detectado 
        Guardar el caracter en el buffer 
        Vaciar el string del buffer 
*/
class E10 : public AccionSemantica {
    private:
        
    public:
        E10(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Error en constante numérica, se detecó la falta de 's' o 'u' (short y unsigned int respectivamente) " << "\033[0m"<< endl;
            
            //define that code have an error
            isErrorInCode = true;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // al ser un error forzamos volver al estado 0 y vaciamos el lexema
            automaton->getToken()->lexeme = "";
            return 0;    
        } ;
        string name() override {
            return "E10";
        } ;
};