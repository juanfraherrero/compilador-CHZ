#include <iostream>
#include <fstream>
#include "include/Automaton.hpp"

Automaton::Automaton() {

}

int Automaton::processCharacter(char character) {
    if (character == ' ')
        return 30;
    return 0;
}

tokenWithLexeme* Automaton::getLastToken(){
    tokenWithLexeme *token = new tokenWithLexeme();
    token->token = 0;
    token->lexeme = "lexema";
    return token;
}
