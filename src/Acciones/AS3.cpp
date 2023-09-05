#include <iostream>
#include <string>

#include "../include/Acciones/AccionSemantica.hpp"
using namespace std;

class AS3 : public AccionSemantica {
    private:
        
    public:
        AS3(){};
        void execute() override {
            cout << "AS3" << endl;
        } ;
        string name() override {
            return "AS3";
        } ;
};
