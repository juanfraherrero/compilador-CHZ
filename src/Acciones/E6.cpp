#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
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

            std::cerr << "\033[31m" <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Error: Error en constante de punto flotante fuera de rango {1.17549435E-38 , 3.40282347E+38}" << "\033[0m" << endl;
            
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
            return "E6";
        } ;
};