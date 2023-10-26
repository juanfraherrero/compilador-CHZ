#ifndef _AUTOMATON_H_
#define _AUTOMATON_H_

#include "types.hpp"
#include "TableSymbol.hpp"
#include "TableReservedWord.hpp"
#include "AccionSemantica.hpp"

#include <iostream>
#include <fstream>

using namespace std;

class Automaton {
    private:
        //Esto hay que setearlo
        valueOfMatrix matrix[21][28];           // matriz de estados y acciones
        char bufferForCharacter = '\0';         // buffer para guardar el caracter leído 
        TableSymbol* tableSymbol;                                       
        TableReservedWord* tableRWords;
        int* ptrLineNumber;                     // ptr a número de línea actual
        bool* isCommentActive;                  // booleano para identificar si un comentario está activo o no
        tokenWithLexeme * tokenToreturn = new tokenWithLexeme{0, " ", " "};      // token a devolver
        valueOfMatrix * getValueOfMatrix (char character, int actual_state);// devuelve dado el caracter y el estado actual
                                                                            // cual es el siguiente estado y acción a ejecutar
        int getSubconjunto(char character);                                 // retorna el subconjunto al que pertenece el caracter
        AccionSemantica* getAccionSemantica(string accionStr);              // retorna la acción semántica a ejecutar
    public:
        Automaton(TableSymbol* tableSymbol, TableReservedWord* tableRWords, int* ptrLineNumber, bool * isCommentActive);
        int processCharacter(char character, int actual_satate);    // Usa el léxico para procesar un caracter
        tokenWithLexeme* getToken();                                // Devuelve el token
        tokenWithLexeme* getCopyOfToken();                          // Devuelve una copia del token
        tokenWithLexeme* getCopyOfTokenAndResetToken();             // Devuelve una copia del token y resetea el token
        void printMatrix();                                         // imprime la matriz de estados y acciones
        void loadStateTable(string pathFile);                       // carga la tabla de estados
        void loadActionsTable(string pathFile);                     // carga la tabla de acciones
        bool isBufferEmpty();                                       // checkea si el buffer está vacío
        void setBuffer(char character);                             // guarda el caracter en el buffer
        char getAndClearBuffer();                                   // devuelve el caracter del buffer y vacía el buffer
        int * getPtrLineNumber();                                   // devuelve el puntero al número de línea
        void setCommentIsActive(bool value);                        // setea si el comentario está activo o no
};

#endif