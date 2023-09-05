#include <iostream>
#include <string>

using namespace std;

#include "../include/Acciones/AccionSemantica.hpp"

class AS2 : public AccionSemantica {
    private:
        
    public:
        AS2(){};
        void execute() override {
            cout << "AS2" << endl;
        } ;
        string name() override {
            return "AS2";
        } ;
};
