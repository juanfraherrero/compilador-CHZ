#include "include/Tercets.hpp"
#include <iostream> 

Tercets::Tercets(){

}

int Tercets::add(Tercet* t){
    this->tercets.push_back(t);
    return this->tercets.size() - 1;
}

Tercet* Tercets::get(int index){
    return this->tercets[index];
}
void Tercets::erase(int index){
    this->tercets.erase(this->tercets.begin() + index);
}

void Tercets::replace(int index, Tercet* t){
    this->tercets[index] = t;
}

void Tercets::print(){
    cout << "\nLista de Tercetos:\n" << endl;
    for (int i = 0; i < this->tercets.size(); i++){
        cout << i << " - ";
        this->tercets[i]->print();
    }
}

void Tercets::printStack(){
    // Crear una copia temporal del stack original
    stack<Tercet*> tempStack = this->tercetsStack;

    // Desapilar y mostrar los elementos de la copia temporal
    while (!tempStack.empty()) {
        tempStack.top()->print();
        tempStack.pop();
    }
}

//Devuelve el vector de tercetos
vector<Tercet*> Tercets::getTercets(){
    return this->tercets;
};  

void Tercets::push(Tercet* t){
    this->tercetsStack.push(t);
}

Tercet* Tercets::pop(){
    Tercet* t = nullptr; // Inicializa con nullptr para evitar problemas
    if (!this->tercetsStack.empty()) {
        t = this->tercetsStack.top();
        this->tercetsStack.pop();
    }
    return t;
}

int Tercets::numberOfLastTercet(){
    return this->tercets.size() - 1;
}

Tercets::~Tercets() {
    // Eliminar objetos apuntados en el vector 'tercets'
    for (Tercet* tercet : tercets) {
        delete tercet;
    }
    tercets.clear();

    // Eliminar objetos apuntados en la stack 'tercetsStack'
    while (!tercetsStack.empty()) {
        delete tercetsStack.top();
        tercetsStack.pop();
    }
}