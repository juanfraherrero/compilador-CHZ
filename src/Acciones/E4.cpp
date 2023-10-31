#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
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

            std::cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por entero corto fuera de rango { -128, 127 }"  << "\033[0m"<< endl;
            
            //define that code have an error
            isErrorInCode = true;

            

            // al ser un error deberíamos forzamos volver al estado 0 
            // pero como se gfue de rango mejor devolver 0 dando un aviso de que se cambió y que el parsing no falle

            //insertamos en la tabla de símbolos el short int con valor 0
                // con el lexema como key, el lexema, el valor
                // el insert checkea la existencia de otro lexema igual 
            tableSymbol->insert("0_s", "0_s", "0", "short");

            //definimos el token como short int y además le modificamos el lexema a 0_s
            automaton->getToken()->lexeme = "0_s";
            automaton->getToken()->token = id_CONSTANTE_ENTERO_CORTO;
            automaton->getToken()->type = "short";
            return 19;    
        } ;
        string name() override {
            return "E4";
        } ;
};