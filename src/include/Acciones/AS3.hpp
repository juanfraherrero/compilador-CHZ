#ifndef _AS3_H_
#define _AS3_H_

#include <iostream>
#include <string>

#include "AccionSemantica.hpp"

using namespace std;
class AS3 : public AccionSemantica {
    private:
        
    public:
        AS3();
        void execute() override ;
        string name() override ;
};

#endif