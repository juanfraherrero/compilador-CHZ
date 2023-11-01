#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"
#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 8 se encarga de:
        Indicar un error por pantalla de un entero sin signo fuera de rango.
        Vaciar el string del lexema.
        devolvemos al sintáctico un 0 para que no falle el parsing y vamos al estado final
*/
class E8 : public AccionSemantica {
    private:
        
    public:
        E8(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por entero sin signo fuera de rango { 0 - 65535 }." << "\033[0m" << endl;
            
            //define that code have an error
            isErrorInCode = true;
            
            // al ser un error deberíamos forzamos volver al estado 0 
            // pero como se fue de rango mejor devolver 0 dando un aviso de que se cambió y así el parsing no falle

            // insertamos en la tabla de símbolos el unsigned int con valor 0
                // con el lexema como key, el lexema, el valor
                // el insert checkea la existencia de otro lexema igual 
            tableSymbol->insert("0_ui", "0_ui", "0", "unsigned int");

            //definimos el token como unsigned int y además le modificamos el lexema a 0_ui
            automaton->getToken()->lexeme = "0_s";
            automaton->getToken()->token = id_CONSTANTE_ENTERO_SIN_SIGNO;
            automaton->getToken()->type = "unsigned int";
            return 19;
        } ;
        string name() override {
            return "E8";
        } ;
};