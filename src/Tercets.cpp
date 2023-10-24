#include "include/Tercets.hpp"

Tercets::Tercets(){
    
}

int Tercets::add(Tercet* t){
    this->tercets.push_back(t);
    return this->tercets.size() - 1;
}

void Tercets::erase(int index){
    this->tercets.erase(this->tercets.begin() + index);
}

void Tercets::replace(int index, Tercet* t){
    this->tercets[index] = t;
}

void Tercets::print(){
    for (int i = 0; i < this->tercets.size(); i++){
        this->tercets[i]->print();
    }
}

void Tercets::push(Tercet* t){
    this->tercetsStack.push(t);
}

Tercet* Tercets::pop(){
    Tercet* t = this->tercetsStack.top();
    this->tercetsStack.pop();
    return t;
}

int Tercets::numberOfLastTercet(){
    return this->tercets.size() - 1;
}

Tercets::~Tercets(){

}