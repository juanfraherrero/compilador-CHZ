#include <iostream>
#include <fstream>
#include "include/Automaton.hpp"

Automaton::Automaton() {

}

int Automaton::processCharacter(char character, int actual_state) {

    valueOfMatrix* value = this->getValueOfMatrix(character, actual_state);

    // esto lo debe hacer una accion semantica
    this->tokenToreturn->lexeme+=character;
    if (value->accionp != NULL){
        value->accionp->execute();
    }   
    
    return value->next_state;
}

valueOfMatrix * Automaton::getValueOfMatrix (char character, int actual_state){
    int column = this->getSubconjunto(character);
    int row = actual_state;
    
    return &this->matrix[row][column];
}

int Automaton::getSubconjunto(char character){
    if (isalpha(character)) {
        std::cout << "Es una letra." << std::endl;
        return 0;
    } else if (isdigit(character)) {
        std::cout << "Es un número." << std::endl;
        return 0;
    } else if (isspace(character)) {
        std::cout << "Es un espacio." << std::endl;
        return 1;
    } else {
        std::cout << "No es una letra, número ni espacio." << std::endl;
        return 0;
    }

}
tokenWithLexeme* Automaton::getLastToken(){

    tokenWithLexeme *token = new tokenWithLexeme();
    // copiamos el token con su lexema
    token->token = this->tokenToreturn->token;
    token->lexeme = this->tokenToreturn->lexeme;
    
    // limpiamos la variable para guardar el token
    this->tokenToreturn->token = 0;
    this->tokenToreturn->lexeme = "";

    return token;
}
