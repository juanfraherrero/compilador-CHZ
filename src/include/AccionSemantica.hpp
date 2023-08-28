#ifndef _ACCIONSEMANTICA_H_
#define _ACCIONSEMANTICA_H_

#include <iostream>

class AccionSemantica {
    private:
        
    public:
        AccionSemantica();
        virtual void execute() = 0;
};


#endif