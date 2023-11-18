#ifndef _TERCET_HPP_
#define _TERCET_HPP_

#include <string>
#include "TableSymbol.hpp"

using namespace std;

class Tercet {
public:
    Tercet(string op, string arg1, string arg2);
    
    string getOp() const; //Operador, tipo de terceto
    string getArg1() const; //Operando 1
    string getArg2() const; //Operando 2
    void setArg1(string arg1); //Seteo de operando 1
    void setArg2(string arg2); //Seteo de operando 2
    void print(); //Imprime el terceto.

    bool opIsTercet(int op); //Devuelve true si el operador es una referencia a un terceto o no.
    string typeOfArg1(); //Devuelve el tipo del operando 1
    string typeOfArg2(); //Devuelve el tipo del operando 2
    string getAssembler(TableSymbol * tableSymbols); //Devuelve el codigo assembler generado por el terceto
    ~Tercet();

private:
    string op;
    string arg1;
    string arg2;
    string auxVariable; //Representa la variable auxiliar que almacena al terceto.
};

#endif // _TERCET_HPP_
