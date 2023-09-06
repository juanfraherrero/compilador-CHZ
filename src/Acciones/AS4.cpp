#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4(){};
        void execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            cout << "AS4" << endl;
        } ;
        string name() override {
            return "AS4";
        } ;
};