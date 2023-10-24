#ifndef _TERCET_HPP_
#define _TERCET_HPP_

#include <string>

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

    ~Tercet();

private:
    string op;
    string arg1;
    string arg2;
};

#endif // _TERCET_HPP_
