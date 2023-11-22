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
                copy->ter->add(new Tercet(tercet->getOp(), tercet->getArg1(), tercet->getArg2(), tercet->arg1Pospone, tercet->arg2Pospone, tercet->type1, tercet->type2, tercet->typeTercet));
            }
            return copy;
        }
    }
    return nullptr;
} 

//Devuelve una copia de la lista de la función de tercetos
vector<functionStack*> * VectorOfFunction::getFunctions(){
    return this->functions;
}; 

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