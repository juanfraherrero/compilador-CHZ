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
    ~VectorOfFunction();

};

#endif // _TERCETS_HPP_
