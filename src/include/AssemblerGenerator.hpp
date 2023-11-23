#ifndef _AssemblerGenerator_HPP_
#define _AssemblerGenerator_HPP_

#include "Tercets.hpp"
#include "TableSymbol.hpp"
#include <string>
#include "VectorOfFunction.hpp"

using namespace std;

class AssemblerGenerator {
private:
    string pathFinal; //Path al archivo de salida.
    string code;    //String que contiene la seccion .code del código assembler.
    string data;    //String que contiene la seccion .data del código assembler.
    string libraries; //String que contiene las librerias del código assembler asi como los parametros iniciales.
    int auxVariable = 0;    //Contador para las variables auxiliares
    TableSymbol * tableSymbol;
    Tercets * tercets;
    VectorOfFunction * functionTercets;     //Tercetos del cuerpo de cada función
    bool overflowEnteros = false;       //Flag para saber si se debe chequear overflow en suma de enteros
    bool overflowProductos = false;     //Flag para saber si se debe chequear overflow en multiplicacion de enteros
    bool recursionMutua = false;    //Flag para saber si hay recursion mutua
public:
    AssemblerGenerator(string pathFinal, TableSymbol * tableSymbol, Tercets* tercets, VectorOfFunction * vectorOfFunction);
    void generateAssembler(); //Genera el código assembler

    void generateData(); //Genera las instrucciones declarativas.
    void generateCode(); //Genera las instrucciones del codigo.
    void generateFunctionsAssembler(); //Genera el código assembler de las funciones.
    void generateMainAssembler(); //Genera el código assembler del main.
    void generateErrorAssembler(); //Genera los labels y el assembler de los errores.

    void addVariable(symbol * s); //Agrega una variable al código assembler.
    string getTercetAssembler(Tercet * tercet, Tercets * tercets); //genera el código assembler dado un terceto
    string reemplazarCaracter(string s, char caracter, char reemplazo); //Reemplaza un caracter por otro en una cadena.
    string getAuxVariable(); //Obtiene una variable auxiliar.
};

#endif
