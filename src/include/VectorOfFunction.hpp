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
    vector<functionStack*> * getFunctionsStack(); //Devuelve la lista de tercetos
    functionStack* getCopyOfFunction(string name); //Devuelve una copia de la lista de la función de tercetos
    ~VectorOfFunction();

};

#endif // _TERCETS_HPP_
