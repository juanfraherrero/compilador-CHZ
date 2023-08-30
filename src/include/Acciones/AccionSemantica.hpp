#ifndef _ACCIONSEMANTICA_H_
#define _ACCIONSEMANTICA_H_

#include <iostream>

class AccionSemantica {
    private:
        
    public:
        virtual void execute() = 0;
        virtual string name() = 0;
};


#endif