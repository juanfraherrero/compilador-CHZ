#include <iostream>
#include <string>

using namespace std;
#include "../include/Acciones/AccionSemantica.hpp"

class AS1 : public AccionSemantica {
    private:
        
    public:
        AS1(){};
        void execute() override {
            cout << "AS1" << endl;
        } ;
        string name() override {
            return "AS1";
        } ;
};
