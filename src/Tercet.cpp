#include "include/Tercet.hpp"

#include <iostream>
#include <string>
#include "include/types.hpp"
using namespace std;

Tercet::Tercet(string op, string arg1, string arg2){
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
}

string Tercet::getOp() const{
    return this->op;
}

string Tercet::getArg1() const{
    return this->arg1;
}

string Tercet::getArg2() const{
    return this->arg2;
}  

string Tercet::getAuxVariable() const{
    return this->auxVariable;
}

void Tercet::setArg1(string arg1){
    this->arg1 = arg1;
}   

void Tercet::setArg2(string arg2){
    this->arg2 = arg2;
}

void Tercet::setAuxVariable(string auxVariable){
    this->auxVariable = auxVariable;
}

void Tercet::print(){
    cout << "(" + this->op + "," + this->arg1 + "," + this->arg2  + ")" << endl;
}

bool Tercet::opIsTercet(int op){
    if (op == 1)
        return this->arg1[0] == '%';
    else if (op == 2)
        return this->arg2[0] == '%';
}

Tercet::~Tercet(){
    
}