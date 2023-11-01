#include "../include/AccionSemantica.hpp"
#include "../include/Automaton.hpp"
#include "../include/types.hpp"
#include "../include/ID_YACC.hpp"   

#include <iostream>
#include <string>

using namespace std;
extern bool isErrorInCode;
/*
    La acción semántica de ERROR 10 (detección de un caracter no válido en una constante numérica de tipo UI o SHORT) se encarga de:
        Indicar un error por pantalla de que la constante numérica de tipo UI o SHORT no tiene el sufijo correspondiente
        Guardar el caracter en el buffer 
        devolver un 0 de tipo short (puede suceder que al usuario le salte errores por incopatibilidad de tipos al forzar un short) 
*/
class E10 : public AccionSemantica {
    private:
        
    public:
        E10(){};
        int execute(Automaton* automaton, char characterReaded, TableSymbol* tableSymbol, TableReservedWord* tableRWords) override {
            // indicar un error por pantalla de caracter no válido detectado
            cerr << "\033[31m" << "Linea: " << *(automaton->getPtrLineNumber()) << "-> Error: Error en constante numérica, se detecó la falta de 's' o 'ui' (short y unsigned int respectivamente) se convierte en 0 de tipo short" << "\033[0m"<< endl;
            
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
            return "E10";
        } ;
};