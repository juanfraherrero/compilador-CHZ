#include "include/Tercet.hpp"

#include <iostream>
#include <string>

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

void Tercet::print(){
    cout << "(" + this->op + ", " + this->arg1 + ", " + this->arg2  + ")" << endl;
}

Tercet::~Tercet(){
    
}