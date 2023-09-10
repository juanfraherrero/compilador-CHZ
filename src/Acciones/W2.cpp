#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La accion semantica de WARNING 2 se encarga de:
        Truncar el lexema a una longitud de 20 caracteres.
        Indicar un Warning de que se trunco el identificador.
*/
class W2 : public AccionSemantica {
    private:
        
    public:
        W2(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            automaton->getToken()->lexeme = automaton->getToken()->lexeme.substr(0, 20);
                
            // avisamos que truncamos el lexema
            cerr << "\033[33m" <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Warning: Identificador '" << automaton->getToken()->lexeme <<"' excedia los 20 caracteres y fue truncado"<< "\033[0m" << endl;
            return 0;
        } ;
        string name() override {
            return "W2";
        } ;
};