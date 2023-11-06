#include "include/types.hpp"
#include "include/Lexico.hpp"
#include "include/Automaton.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
// #include "include/TableSymbol.hpp"
// #include "include/TableReservedWord.hpp"

#include <iostream>
#include <fstream>

// ACa DEFNIR EL TIPO QUE ESTa EN EL PARSER.CPP
extern myTypeYYLVAL* yylval;

Lexico::Lexico(TableSymbol* tableSymbol, TableReservedWord* tableRWords, string * content, int* lineNumber) {
    // definimos que archivo va a usar y las variables para hacer el conteo de lineas y caracteres leidos   
    this->content = *content;
    this->lineNumber = lineNumber;
    this->automaton = new Automaton(tableSymbol, tableRWords, this->lineNumber, &(this->isCommentActive));
    this->isCommentActive = false;
    this->eof = false;
}
int Lexico::yylex(){
    
    tokenWithLexeme * token = this->getToken(); // esto queda guardado en el heap // checkear cuando hay que eliminarlo
    
    if(token == nullptr){
        return 0; //segun documentacion el token final es un 0
    };
    
    cout <<  "El token es: " << token->token << " con lexema: " << token->lexeme << endl;

    yylval = new myTypeYYLVAL(token->lexeme, token->type);
    return token->token;

}

tokenWithLexeme *Lexico::getToken(){

    if(this->content.empty()){
        //ya no tenemos mas que caracteres que leer
        this->eof = true;
        return nullptr;
    }
    // seteamos el estado del automata en 0
    int stateAutomaton = 0;

    // obtenemos un token       
    /*
        suponemos que el 19 es el estado final (ambos terminan el token)
    */
    while (stateAutomaton != 19 ){
        if(this->eof){
            //ya no terminamos de leer el archivo
            if(this->isCommentActive)
            {
                // si hay un comentario activo lo informamos
                cerr << "\033[31m" << "Linea: " << *(this->lineNumber) << "-> Error: Comentario activo al final del archivo" << "\033[0m" << endl;
            }
                
            return nullptr;
        }
        char firstCharacter;
        // si el buffer del automata esta vacio le mandamos otro sino el mismo que tiene
        if(this->automaton->isBufferEmpty()){        
            // obtenemos el primer caracter de la linea
            if(!this->content.empty()){
                firstCharacter = this->content[0]; 
                // eliminamos ese caracter de la linea
                this->content.erase(0, 1); 
            }else{
                this->eof = true; //seteamos que termianmos de leer el archivo
                
                // si no hay mas caracteres le mandamos un espacio que no afecta en ningun caso,
                    // esto es para que termine de leer un posible token que no termino
                firstCharacter = ' ';
            }
        }
        else{
            firstCharacter = this->automaton->getAndClearBuffer(); 
        }
        
        // procesamos el caracter por el automata esperando el estado siguiente
        stateAutomaton = this->automaton->processCharacter(firstCharacter, stateAutomaton);
    }

    return this->automaton->getCopyOfTokenAndResetToken();
}

// checkea si es el final de archivo
bool Lexico::endOfFile(){
    return this->eof;
}

void Lexico::printMatrix(){
    this->automaton->printMatrix();
}

void Lexico::incrementLineNumber(){
    (*(this->lineNumber))++;
}