#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

/*
    La acción semántica 15 ('!!') se encarga de:
        Verificar si es un '!'
            Si es un '!' se devuelve el identificador de token asociado a id_COMPARADOR_DISTINTO
            sI NO es '!' se guarda el caracter leído y se devuelve el código ASCII del '!'
*/
class AS15 : public AccionSemantica {
    public:
        AS15(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {            
           
            if(characterReaded == '!'){
                automaton->getToken()->token = id_COMPARADOR_DISTINTO;
            }
            else{
                // guarda el caracter en el buffer del automaton
                automaton->setBuffer(characterReaded);

                std::cerr <<"Linea: " << *(automaton->getPtrLineNumber()) << " -> Error encontrado en '!'. No es parte del lenguaje" << endl;
                
                // al ser un error forzamos volver al estado 0 y vaciamos el lexema
                automaton->getToken()->lexeme = "";
                return 0;    
            }

            // desde la acción no modificamos el siguiente estado
            return -1;
            
        };

        string name() override {
            return "AS15";
        };
};