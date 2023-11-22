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

    bool arg1Pospone = false;       // determina si el terceto fue pospuesto o no
    bool arg2Pospone = false;       // determina si el terceto fue pospuesto o no
    string type1;                   // tipo del primer argumento
    string type2;                   // tipo del segundo argumento
    string typeTercet = "";              // tipo del terceto

private:
    string op;
    string arg1;
    string arg2;
};

#endif // _TERCET_HPP_
