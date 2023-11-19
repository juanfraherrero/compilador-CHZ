#ifndef _TERCETS_HPP_
#define _TERCETS_HPP_

#include "Tercet.hpp"
#include "TableSymbol.hpp"
#include <string>
#include <vector>
#include <stack>

using namespace std;

class Tercets {
public:

    Tercets();

    int add(Tercet* tercet); //Añade un terceto y devuelve la posicion en la que se añadio.
    Tercet* get(int index); //Devuelve un terceto en cierta posicion de la estructura
    void erase(int index); //Elimina un terceto en cierta posicion de la estructura
    void replace(int index, Tercet* tercet); //Reemplaza un terceto en cierta posicion de la estructura por otro Terceto.
    int numberOfLastTercet(); //Devuelve el numero del ultimo terceto añadido.
    void print(); //Imprime todos los tercetos de la estructura.
    void push(Tercet* tercet); //Añade un terceto a la pila de tercetos.
    Tercet* pop(); //Devuelve el ultimo terceto de la pila de tercetos.
    void printStack(); //Imprime todos los tercetos de la estructura.
    vector<Tercet*> getTercets();   //Devuelve el vector de tercetos
    ~Tercets();

private:
   vector<Tercet*> tercets;
   stack<Tercet*> tercetsStack;
};

#endif // _TERCETS_HPP_
