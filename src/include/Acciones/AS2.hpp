#ifndef _AS2_H_
#define _AS2_H_

#include <iostream>
#include <string>

#include "AccionSemantica.hpp"

using namespace std;
class AS2 : public AccionSemantica {
    private:
        
    public:
        AS2();
        void execute() override ;
        string name() override ;
};

#endif