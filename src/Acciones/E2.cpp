#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 2 (detección de un caracter no válido en una constante numérica) se encarga de:
        Indicar un error por pantalla de caracter no válido detectado 
        Guardar el caracter en el buffer 
        devolver un 0 de tipo short (puede suceder que al usuario le salte errores por incopatibilidad de tipos al forzar un short) 
*/
class E2 : public AccionSemantica {
    private:
        
    public:
        E2(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Error en constante numerica, no se logra identificar el tipo. Verificar documentacion. Se convierte en 0 de tipo short" << "\033[0m"<< endl;
            
            //define that code have an error
            isErrorInCode = true;

            // guarda el caracter en el buffer del automaton
            automaton->setBuffer(characterReaded);

            // al ser un error deberíamos forzar volver al estado 0 pero directamente vamos al estado final
            // retornamos un valor por defecto al sitáctico para evitar fallas 0 de tipo short
            tableSymbol->insert("0_s", "0_s", "0", "short");
            
            automaton->getToken()->lexeme = "0_s";
            automaton->getToken()->token = id_CONSTANTE_ENTERO_CORTO;
            automaton->getToken()->type = "short";
            return 19;    
        } ;
        string name() override {
            return "E2";
        } ;
};