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
        cout << "Nombre de la función: " << vf->name << endl;
        vf->ter->print();
    }
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