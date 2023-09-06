#ifndef _TYPES_H_
#define _TYPES_H_

#include "Acciones/AccionSemantica.hpp"

#include <iostream>

struct tokenWithLexeme {
    int token;
    std::string lexeme;
};

struct valueOfMatrix
{
    int next_state;
    AccionSemantica * accionp;
};


#endif