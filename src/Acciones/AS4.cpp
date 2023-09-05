#include <iostream>
#include <string>

using namespace std;
#include "../include/Acciones/AccionSemantica.hpp"

class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4(){};
        void execute() override {
            cout << "AS4" << endl;
        } ;
        string name() override {
            return "AS4";
        } ;
};