#ifndef _FUNCTIONSTACK_HPP_
#define __FUNCTIONSTACK_HPP_

#include "types.hpp"
#include "Tercets.hpp"
#include "TableSymbol.hpp"

#include <string>
#include <vector>
#include <stack>

using namespace std;

class VectorOfFunction {
private:
   vector<functionStack*> * functions = new vector<functionStack*>();     // tercetos del cuerpo de una función
public:

    VectorOfFunction();

    void add(functionStack* vf); //Añade una lista de tercetos
    void imprimir(); //Imprime todos los tercetos de la estructura.
    functionStack* getCopyOfFunction(string name); //Devuelve una copia de la lista de la función de tercetos
    vector<functionStack*> * getFunctions();    //devuelve el puntero a l vector de funciones
    ~VectorOfFunction();

};

#endif // _TERCETS_HPP_
