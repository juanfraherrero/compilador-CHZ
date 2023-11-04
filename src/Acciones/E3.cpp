#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 3 (detección de un salto de línea en cadena de texto) se encarga de:
        Indicar un error por pantalla de salto de línea inválido 
        Guardar el caracter en el buffer  
        Volver al estado 19 devolviendo la cadena detectada previa al salto de línea
*/
class E3 : public AccionSemantica {
    private:
        
    public:
        E3(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: salto de linea en cadena de texto " << "\033[0m"<< endl;
            
            //define that code have an error
            isErrorInCode = true;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // obtenemos el lexema hasta el salto de línea
            string lexeme = automaton->getToken()->lexeme;

            // obtenemos el valor del entero sin el primer #
            string value = lexeme.substr(1, lexeme.length() - 1);

            //insertamos en la tabla de símbolos la cadena de caracteres 
                // con el lexema como key, el lexema, el valor es el lexema sin el primer #
                // el insert checkea la existencia de otro lexema igual 
            tableSymbol->insert(lexeme, lexeme, value, "string");

            //definimos el token como cadena de caracteres
            automaton->getToken()->token = id_CONSTANTE_CADENA_CARACTERES;
            automaton->getToken()->type = "string";
            
            // al ser un error deberíamos forzar volver al estado 0
            // pero como devolvemos igualmente una cadena forzamos a ir al estado 19 o final para obtener esa cadena.

            return 19;    
        } ;
        string name() override {
            return "E3";
        } ;
};