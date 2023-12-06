#ifndef _TERCETS_HPP_
#define _TERCETS_HPP_

#include "Tercet.hpp"

#include <string>
#include <vector>
#include <stack>

using namespace std;

class Tercets {
public:
    string objectName; // cuando los rtercetos son de un método o función de un objeto instanciado se marca su nombre
    Tercets();

    int add(Tercet* tercet); //Añade un terceto y devuelve la posicion en la que se añadio.
    void erase(int index); //Elimina un terceto en cierta posicion de la estructura
    Tercet* get(int index); //devuelve el terceto en la posición index
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
