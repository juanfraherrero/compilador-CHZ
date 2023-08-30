#ifndef _AS1_H_
#define _AS1_H_

#include <iostream>
#include <string>

#include "AccionSemantica.hpp"

using namespace std;
class AS1 : public AccionSemantica {
    private:
        
    public:
        AS1();
        void execute() override ;
        string name() override ;
};

#endif