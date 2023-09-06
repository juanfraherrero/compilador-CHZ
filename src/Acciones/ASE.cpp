#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;


class ASE : public AccionSemantica {
    private:
        
    public:
        ASE(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cout << "EJECUTANDO - ASE - ERROR" << endl;
        } ;
        string name() override {
            return "ASE - ERROR";
        } ;
};