#ifndef _TERCET_HPP_
#define _TERCET_HPP_

#include <string>

using namespace std;

class Tercet {
public:
    Tercet(string op, string arg1, string arg2);
    Tercet(string op, string arg1, string arg2, bool arg1Pospone, bool arg2Pospone, string type1, string type2, string typeTercet);
    
    string getOp() const; //Operador, tipo de terceto
    string getArg1() const; //Operando 1
    string getArg2() const; //Operando 2
    string getAuxVariable() const; //Variable auxiliar que almacena al terceto.
    void setArg1(string arg1); //Seteo de operando 1
    void setArg2(string arg2); //Seteo de operando 2
    void setAuxVariable(string auxVariable); //Seteo de variable auxiliar
    void print(); //Imprime el terceto.
    bool opIsTercet(int op); //Devuelve true si el operando es una referencia a un terceto o no.

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
    string auxVariable; //Representa la variable auxiliar que almacena al terceto.
};

#endif // _TERCET_HPP_
