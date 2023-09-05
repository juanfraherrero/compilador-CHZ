#include <iostream>
#include <string>

using namespace std;
#include "../include/Acciones/AccionSemantica.hpp"

class ASE : public AccionSemantica {
    private:
        
    public:
        ASE(){};
        void execute() override {
            cout << "EJECUTANDO - ASE - ERROR" << endl;
        } ;
        string name() override {
            return "ASE - ERROR";
        } ;
};