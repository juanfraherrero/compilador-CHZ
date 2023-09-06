
#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"


#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 1 se encarga de inicializar el string y concatenar el caracter leído.
*/
class AS1 : public AccionSemantica {
    private:
        
    public:
        AS1(){};

        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cout << "AS1" << endl;
            automaton->getToken()->lexeme = characterReaded; // seteas el lexema con el caracter leído
        } ;
        string name() override {
            return "AS1";
        } ;
};
