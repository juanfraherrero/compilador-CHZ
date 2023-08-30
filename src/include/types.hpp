#ifndef _TYPES_H_
#define _TYPES_H_

#include <iostream>
#include "Acciones/AccionSemantica.hpp"
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