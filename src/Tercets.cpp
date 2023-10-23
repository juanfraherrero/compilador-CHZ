#include "include/Tercets.hpp"

Tercets::Tercets(){
    
}

void Tercets::add(Tercet t){
    this->tercets.push_back(t);
}

void Tercets::erase(int index){
    this->tercets.erase(this->tercets.begin() + index);
}

void Tercets::replace(int index, Tercet t){
    this->tercets[index] = t;
}

void Tercets::print(){
    for (int i = 0; i < this->tercets.size(); i++){
        this->tercets[i].print();
    }
}

Tercets::~Tercets(){

}