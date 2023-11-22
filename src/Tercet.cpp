#include "include/Tercet.hpp"

#include <iostream>
#include <string>

using namespace std;

Tercet::Tercet(string op, string arg1, string arg2){
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
}
Tercet::Tercet(string op, string arg1, string arg2, bool arg1Pospone, bool arg2Pospone, string type1, string type2, string typeTercet){
    this->op = op;
    this->arg1 = arg1;
    this->arg2 = arg2;
    this->arg1Pospone = arg1Pospone;
    this->arg2Pospone = arg2Pospone;
    this->type1 = type1;
    this->type2 = type2;
    this->typeTercet = typeTercet;
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

void Tercet::setArg1(string arg1){
    this->arg1 = arg1;
}   

void Tercet::setArg2(string arg2){
    this->arg2 = arg2;
}

void Tercet::print(){
    cout << "(" + this->op + "," + this->arg1 + "," + this->arg2  + ") " << this->arg1Pospone << " - " <<this->arg2Pospone << " | " << this->type1 << " - " <<this->type2 << " | " << this->typeTercet << endl;
}

Tercet::~Tercet(){
    
}