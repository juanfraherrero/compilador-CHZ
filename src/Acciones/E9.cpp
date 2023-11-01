#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 9 (detección de un caracter no válido en una constante numérica de tipo float) se encarga de:
        Indicar un error en la constante numérica
        Guardar el caracter en el buffer 
        devolvemos al sintáctico un 0 para que no falle el parsing 
*/
class E9 : public AccionSemantica {
    private:
        
    public:
        E9(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Error en constante numérica flotante por caracter: " << characterReaded << " debe coincidir con el formato 1.40327E+38 " << "\033[0m"<< endl;
            
            //define that code have an error
            isErrorInCode = true;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // al ser un error deberíamos forzar volver al estado 0 pero directamente vamos al estado final
            // retornamos un valor por defecto al sitáctico para evitar fallas
            tableSymbol->insert("0.0", "0.0", "0.0", "float");
            
            automaton->getToken()->lexeme = "0.0";
            automaton->getToken()->token = id_CONSTANTE_PUNTO_FLOTANTE;
            automaton->getToken()->type = "float";
            return 19;    
        } ;
        string name() override {
            return "E9";
        } ;
};