#include "include/VectorOfFunction.hpp"
#include "include/Tercet.hpp"

#include <iostream> 

VectorOfFunction::VectorOfFunction(){
}

void VectorOfFunction::add(functionStack * vf){
    (*(this->functions)).push_back(vf);
}

void VectorOfFunction::imprimir(){
    for (functionStack * vf : *(this->functions)) {
        cout << "\nbloque de codigo: " << vf->name <<"\n" << endl;
        vf->ter->print();
    }
}

//Devuelve una copia de la lista de la función de tercetos
functionStack* VectorOfFunction::getCopyOfFunction(string _name){
    for (functionStack * vf : *(this->functions)) {
        if(vf->name == _name){
            functionStack* copy = new functionStack(_name);
            copy->ter = new Tercets();
            for (Tercet* tercet : vf->ter->getTercets()) {
                copy->ter->add(new Tercet(tercet->getOp(), tercet->getArg1(), tercet->getArg2()));
            }
            return copy;
        }
    }
    return nullptr;
} 

VectorOfFunction::~VectorOfFunction() {
    // // Eliminar objetos apuntados en el vector 'tercets'
    // for (Tercet* tercet : tercets) {
    //     delete tercet;
    // }
    // tercets.clear();

    // // // Eliminar objetos apuntados en la stack 'tercetsStack'
    // // while (!tercetsStack.empty()) {
    // //     delete tercetsStack.top();
    // //     tercetsStack.pop();
    // // }
}