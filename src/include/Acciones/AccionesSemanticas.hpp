#ifndef _ACCIONESSEMANTICAS_H_
#define _ACCIONESSEMANTICAS_H_

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

class AS3 : public AccionSemantica {
    private:
        
    public:
        AS3();
        void execute() override ;
        string name() override ;
};

class AS4 : public AccionSemantica {
    private:
        
    public:
        AS4();
        void execute() override ;
        string name() override ;
};

class AS5 : public AccionSemantica {
    private:
        
    public:
        AS5();
        void execute() override ;
        string name() override ;
};

class AS6 : public AccionSemantica {
    private:
        
    public:
        AS6();
        void execute() override ;
        string name() override ;
};

class AS7 : public AccionSemantica {
    private:
        
    public:
        AS7();
        void execute() override ;
        string name() override ;
};

#endif