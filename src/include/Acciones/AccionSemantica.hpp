#ifndef _ACCIONSEMANTICA_H_
#define _ACCIONSEMANTICA_H_

#include <iostream>
using namespace std;

class Automaton;

class AccionSemantica {
    private:
        
    public:
        virtual void execute(Automaton * automaton, char characterReaded) = 0;
        virtual string name() = 0;
};


#endif