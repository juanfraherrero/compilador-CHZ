#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;

/*
    La acción semántica 6 ('.'. palabras reservadas) se encarga de:
        guarda el caracter en el buffer del automaton
        setea el id de la palabra reservada en el token
*/
class AS6 : public AccionSemantica {
    private:
        
    public:
        AS6(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            string lexeme = automaton->getToken()->lexeme;

            int id = tableRWords->getId(lexeme);
            if(id != -1){
                //seteamos el id de la palabra reservada de palabras reservadas
                automaton->getToken()->token = id;
            }else{
                // la palabra reservada no existe
                std::cerr << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error por palabra reservada mal formada"  << endl;

                // al ser un error forzamos volver al estado 0 y vaciamos el lexema
                automaton->getToken()->lexeme = "";
                return 0;
            }
            
            // desde la acción no modificamos el siguiente estado
            return -1;
        };

        string name() override {
            return "AS6";
        };
};