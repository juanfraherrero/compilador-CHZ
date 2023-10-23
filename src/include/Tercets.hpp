#ifndef _TERCETS_HPP_
#define _TERCETS_HPP_

#include <string>
#include <vector>
#include "Tercet.hpp"

using namespace std;

class Tercets {
public:

    Tercets();
    void add(Tercet tercet); //Añade un terceto
    void erase(int index); //Elimina un terceto en cierta posicion de la estructura
    void replace(int index, Tercet tercet); //Reemplaza un terceto en cierta posicion de la estructura por otro Terceto.
    void print(); //Imprime todos los tercetos de la estructura.

    ~Tercets();

private:
   vector<Tercet> tercets;
};

#endif // _TERCETS_HPP_
