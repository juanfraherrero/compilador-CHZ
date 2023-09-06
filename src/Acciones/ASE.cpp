#include "../include/Acciones/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;


class ASE : public AccionSemantica {
    private:
        
    public:
        ASE(){};
        void execute(Automaton* automaton, char characterReaded) override {
            cout << "EJECUTANDO - ASE - ERROR" << endl;
        } ;
        string name() override {
            return "ASE - ERROR";
        } ;
};