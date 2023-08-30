#ifndef _AS4_H_
#define _AS4_H_

#include <iostream>
#include <string>

#include "AccionSemantica.hpp"

using namespace std;
class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4();
        void execute() override ;
        string name() override ;
};

#endif