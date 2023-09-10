#ifndef _ACCIONSEMANTICA_H_
#define _ACCIONSEMANTICA_H_


#include <iostream>
using namespace std;

/*
    Esto es por las dependencias circulares
        De no saber que es BUSCALO EN INTERNET
*/
class Automaton;
class TableSymbol;
class TableReservedWord;

class AccionSemantica {
    private:
        
    public:
        virtual int execute(Automaton * automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWord) = 0;
        virtual string name() = 0;
};


#endif