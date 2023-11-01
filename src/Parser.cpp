#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "./gramaticaComCHZGenerativa.y"

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"
#include "include/Tercets.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* generamos la tabla de símbolos*/
TableSymbol* tableSymbol = new TableSymbol();

/* generamos la tabla de palabras reservadas*/
TableReservedWord* tableRWords = new TableReservedWord();

int lineNumber = 1;
bool isErrorInCode = false;
Tercets *tableTercets = new Tercets();
char charTercetoId = '%';

string typeAux = "";

void yyerror(string s){
    isErrorInCode = true;    
    cerr << "\033[31m" << "Linea: " << lineNumber << "-> Error: " << s <<"\033[0m"<< endl;
};
void yywarning(string s){
    cerr << "\033[33m" << "Linea: " << lineNumber << "-> Warning: " << s <<"\033[0m"<< endl;
};
void yyPrintInLine(string s){
    cout << "Linea: " << lineNumber << "-> " << s << endl;
};
#line 43 "y.tab.c"
#define IDENTIFICADOR 257
#define ENTERO_SIN_SIGNO 258
#define ENTERO_CORTO 259
#define PUNTO_FLOTANTE 260
#define CADENA_CARACTERES 261
#define COMPARADOR_IGUAL_IGUAL 262
#define COMPARADOR_DISTINTO 263
#define COMPARADOR_MENOR_IGUAL 264
#define COMPARADOR_MAYOR_IGUAL 265
#define OPERADOR_SUMA_SUMA 266
#define VOID 267
#define RETURN 268
#define IF 269
#define ELSE 270
#define END_IF 271
#define PRINT 272
#define WHILE 273
#define DO 274
#define SHORT 275
#define UINT 276
#define FLOAT 277
#define TOF 278
#define CLASS 279
#define YYERRCODE 256
short yylhs[] = {                                        -1,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    1,    1,    3,    3,    3,
    3,    3,    2,    2,    4,    4,    4,    4,   10,   10,
   10,   11,    8,    8,    8,   14,   14,   14,   14,   15,
   15,   16,   16,    9,   17,   17,    6,    6,    6,    7,
    7,   12,   12,   12,   12,   13,   13,   19,   19,   19,
   19,   18,   18,    5,    5,    5,    5,    5,    5,   20,
   20,   21,   21,   21,   21,   24,   24,   24,   24,   24,
   24,   24,   25,   25,   25,   22,   27,   27,   27,   27,
   27,   28,   28,   28,   30,   32,   31,   23,   23,   34,
   35,   29,   29,   29,   29,   29,   29,   33,   33,   33,
   33,   33,   33,   36,   36,   36,   36,   36,   36,   36,
   36,   36,   36,   26,   26,   26,   26,   26,   26,   37,
   37,   38,   38,   38,   38,   38,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    1,    2,    2,    4,    3,    1,
    2,    2,    3,    3,    2,    2,    1,    2,    2,    1,
    1,    2,    2,    1,    2,    1,    1,    1,    7,    7,
    6,    2,    5,    2,    4,    4,    3,    3,    2,    7,
    6,    2,    1,    2,    3,    1,    1,    1,    1,    3,
    1,    2,    1,    1,    0,    1,    1,    3,    2,    3,
    3,    2,    1,    1,    1,    1,    2,    1,    1,    3,
    5,    4,    3,    6,    5,    3,    3,    4,    4,    4,
    4,    1,    3,    3,    1,    3,    3,    2,    2,    1,
    2,    4,    3,    2,    1,    1,    1,    4,    3,    1,
    1,    3,    3,    3,    3,    3,    3,    3,    5,    2,
    2,    4,    2,    3,    2,    2,    1,    3,    2,    2,
    1,    1,    2,    1,    2,    1,    1,    4,    3,    1,
    1,    1,    2,    1,    2,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,  100,   47,   48,   49,    0,
    0,    0,    0,    0,    0,   17,    0,    0,    0,   26,
   27,   28,    0,   64,   65,   66,   68,    0,   22,   46,
    0,    0,    0,    0,   32,    0,    0,  130,  132,  134,
  131,    0,    0,    0,    0,    0,   85,    0,    0,  126,
  127,   67,    0,    0,    0,    0,   23,    7,   16,   12,
    0,   18,   19,   51,    0,    0,    0,   73,    0,    0,
    0,    0,   54,    0,    0,  125,    0,    0,   91,    0,
  133,  135,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   86,    0,   95,   89,
    0,    4,    0,    9,    0,   14,    0,    0,    0,  101,
   99,   72,    0,    0,   45,   52,    0,  129,    0,   87,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   83,   84,  113,    0,    0,  122,    0,    0,
    0,  111,  110,   97,   94,    0,    0,   96,    0,   35,
    0,    0,    0,    0,    3,    8,   50,    0,   98,   75,
    0,    0,    0,  128,    0,    0,    0,    0,  123,    0,
  120,  116,    0,  108,    0,    0,    0,   93,   42,    0,
   33,    0,    0,   39,    0,    0,   74,    0,   63,    0,
    0,   57,  112,    0,  118,  114,   92,   38,    0,   37,
    0,   31,    0,    0,   30,    0,   62,  109,   36,    0,
   29,    0,   61,   58,    0,   41,    0,   40,
};
short yydgoto[] = {                                      13,
   14,   15,   16,   17,   18,   19,   65,   20,   21,   22,
   23,   75,  190,  152,  153,  154,   34,  191,  192,   24,
   25,   26,   27,   45,   46,   47,   48,   97,   49,   98,
  146,  147,  110,   28,  111,  141,   50,   51,
};
short yysindex[] = {                                    629,
  -15,  -38,  -40,  -24, -244,    0,    0,    0,    0, -237,
  684,   -6,    0,  865,  889,    0,   -6,   -6, -210,    0,
    0,    0,   11,    0,    0,    0,    0,  -24,    0,    0,
  -19,  264, -203,   -1,    0, -245,  -42,    0,    0,    0,
    0,   22,  451, -183,  139,  -23,    0,  790,   24,    0,
    0,    0,  -52, -173,  914,  928,    0,    0,    0,    0,
  952,    0,    0,    0,   27, -245,  732,    0,   65,   14,
  -25, -166,    0, -161,   59,    0, -156,  264,    0,   61,
    0,    0,  264,  264,  264,  264,  496,  604,  264,  264,
  264,  264,   69,  660,   71,   75,    0,  708,    0,    0,
 -122,    0, -136,    0,  966,    0, -135,   82,  790,    0,
    0,    0,  473,  264,    0,    0,    5,    0,  106,    0,
   14,   14,   14,   14,  264,  264,  -23,  264,  264,  -23,
   14,   14,    0,    0,    0,   86,   90,    0,   92,   93,
  979,    0,    0,    0,    0,  790, -140,    0, -118,    0,
 -210, -107,   99,  104,    0,    0,    0,   23,    0,    0,
  130,   14, 1058,    0,  -23,  -23,  -23,  -23,    0,   31,
    0,    0,  108,    0,  119,  123,  -95,    0,    0,  -31,
    0, -210,  133,    0, -245,  817,    0,  134,    0,   54,
 1090,    0,    0,   55,    0,    0,    0,    0,   -9,    0,
  145,    0,   62, 1058,    0,  144,    0,    0,    0,   66,
    0, 1090,    0,    0,  841,    0,   67,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
    0,  232,    0,  190,  191,    0,  446,  470,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  283,    0,  152,    1,    0,    0,    0,
    0,    0,    0,   25,    0,   49,    0,    0,  756,    0,
    0,    0,  307,  194,  195,  197,    0,    0,    0,    0,
  200,    0,    0,    0,  331,  152,    0,    0,    0,  355,
    0,    0,    0,  162,    0,    0,    0,    0,    0,  769,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  207,    0,  208,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  491,  512,  525,  548,    0,    0,   73,    0,    0,   97,
  577,  601,    0,    0,    0,    0,    0,    0, 1000, 1014,
    0,    0,    0,    0,    0,    0,    0,    0,  169,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  387,    0,    0,  121,  161,  185,  422,    0,    0,
    0,    0,    0,    0, 1027, 1044,    0,    0,    0,    0,
    0,    0,    0,    0,  152,    0,    0,    0,    0,    0,
   85,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   88,    0,    0,    0,    0,    0,    0,
    0,   89,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   -4,   87,  782,  -34,  -14,  -27, -145,    0,    0,    0,
    0,  -56, -159,    0,   60,    0,    0,    7,   12,    0,
    0,    0,    0, 1266,  -47,   -3,  187,    0,  182,    0,
    0,   81,  -43,    0,  122,    0,    0,    0,
};
#define YYTABLESIZE 1380
short yytable[] = {                                      36,
  124,   31,  150,   77,   99,  180,   55,   33,   74,  108,
   61,   73,  198,   95,  113,   43,   52,  181,   91,   53,
   44,   68,   32,   92,  136,   44,  203,  107,   29,    7,
    8,    9,   95,   96,  209,  114,  199,   12,   74,  127,
  130,  124,  124,  124,  124,  124,   64,  124,   82,  107,
   66,  105,   96,   71,  148,  217,   87,   72,   88,  139,
  124,   78,  124,   95,  100,  136,  136,  136,  136,  136,
  101,  136,   76,  151,   95,   81,   82,  165,  166,  140,
  167,  168,  102,   96,  136,  107,  136,  133,  134,   82,
  115,   82,   82,   82,   96,  116,   77,   56,   57,  117,
  118,  120,  148,   62,   63,  112,  175,   87,   82,   88,
   82,   95,  135,   76,  142,   76,   76,   76,  143,  155,
   79,  157,  158,  124,  182,  124,  176,  163,  201,  169,
  178,   96,   76,  170,   76,  171,  172,   77,  179,   77,
   77,   77,  184,  185,  149,  186,  164,  136,   87,  136,
   88,  194,    7,    8,    9,  193,   77,   74,   77,  149,
   81,   79,  195,   79,   79,   79,  196,    7,    8,    9,
  187,   82,   87,   82,   88,  197,  200,  204,  205,  208,
   79,   87,   79,   88,   78,  210,  211,  214,  215,    5,
   10,  218,   55,    2,    6,   76,   11,   76,   90,   15,
   89,   81,   53,   81,   81,   81,    1,   13,   43,   56,
  212,  183,   59,   60,   67,  213,   35,   69,   30,   77,
   81,   77,   81,   76,   80,   78,  177,   78,   78,   78,
  159,   24,   37,   38,   39,   40,   41,   37,   38,   39,
   40,   41,    0,   79,   78,   79,   78,    0,    0,    0,
    0,    0,    0,   42,    0,    0,  124,  124,   42,    0,
    0,   69,  124,  124,  124,  124,    0,  124,  124,  124,
    0,    0,  124,  124,  124,  124,  124,  124,    0,  124,
  136,  136,   44,   81,    0,   81,  136,  136,  136,  136,
    0,  136,  136,  136,    0,    0,  136,  136,  136,  136,
  136,  136,    0,  136,   82,   82,   34,   78,   44,   78,
   82,   82,   82,   82,    0,   82,   82,   82,    0,    0,
   82,   82,   82,   82,   82,   82,   44,   82,   76,   76,
   25,    0,    0,    0,   76,   76,   76,   76,    0,   76,
   76,   76,   69,    0,   76,   76,   76,   76,   76,   76,
   34,   76,   77,   77,   70,    0,   24,    0,   77,   77,
   77,   77,    0,   77,   77,   77,    0,    0,   77,   77,
   77,   77,   77,   77,   25,   77,   79,   79,    0,    0,
    0,    0,   79,   79,   79,   79,   71,   79,   79,   79,
    0,    0,   79,   79,   79,   79,   79,   79,   70,   79,
   83,   84,   85,   86,    0,    0,    0,   44,    0,    0,
    0,    0,    0,    0,    0,    0,   81,   81,    0,    0,
    0,   80,   81,   81,   81,   81,    0,   81,   81,   81,
   71,   34,   81,   81,   81,   81,   81,   81,    0,   81,
   78,   78,    0,    0,    0,   20,   78,   78,   78,   78,
    0,   78,   78,   78,    0,   25,   78,   78,   78,   78,
   78,   78,   80,   78,   80,   80,   80,    0,    0,   21,
    0,    0,    0,   69,   69,    0,    0,    0,    0,   70,
    0,   80,    0,   80,   69,   69,   69,   24,   24,   69,
   69,   79,   69,   69,   69,   44,   69,    0,   24,   24,
   24,    0,    0,   24,   24,    0,   24,   24,   24,    0,
   24,   71,    0,  160,    0,    0,    0,   44,    0,    0,
   37,   38,   39,   40,   41,    0,    0,    0,    0,    0,
    0,  104,    0,    0,    0,    0,    0,  125,   44,   44,
   44,   42,  126,    0,   80,    0,   80,    0,    0,   44,
   44,   44,  105,    0,   44,   44,    0,   44,   44,   44,
    0,   44,   34,   34,    0,  107,    0,    0,    0,    0,
   20,    0,    0,   34,   34,   34,    0,    0,   34,   34,
    0,   34,   34,   34,    0,   34,   25,   25,  106,    0,
    0,    0,    0,    0,   21,    0,    0,   25,   25,   25,
    0,    0,   25,   25,    0,   25,   25,   25,    0,   25,
   70,   70,    0,  104,    0,    0,    0,  102,    0,    0,
    0,   70,   70,   70,    0,    0,   70,   70,    0,   70,
   70,   70,    0,   70,  105,    0,    0,    0,    0,    0,
    0,  103,   71,   71,    0,  128,    0,  107,   44,    0,
  129,    0,    0,   71,   71,   71,    0,    0,   71,   71,
    0,   71,   71,   71,    0,   71,    0,    0,    0,    0,
  106,    0,   12,    0,    0,    0,    0,   80,   80,    0,
    0,    0,    0,   80,   80,   80,   80,    0,   80,   80,
   80,    0,    0,   80,   80,   80,   80,   80,   80,  102,
   80,   20,   20,  138,    0,    0,    0,   37,   38,   39,
   40,   41,   20,   20,   20,    0,    0,   20,   20,    0,
   20,   20,   20,  103,   20,   21,   21,   12,   42,   37,
   38,   39,   40,   41,    0,    0,   21,   21,   21,    0,
    0,   21,   21,    0,   21,   21,   21,  104,   21,    0,
   42,   11,   37,   38,   39,   40,   41,  104,  104,  104,
    0,    0,  104,  104,  104,  104,  104,  104,  105,  104,
    0,    0,    0,   42,    0,    0,    0,    0,  105,  105,
  105,  107,    0,  105,  105,  105,  105,  105,  105,    0,
  105,  107,  107,  107,    0,   59,  107,  107,  107,  107,
  107,  107,    0,  107,  106,    0,    0,    0,   54,    0,
    0,    0,    0,    0,  106,  106,  106,    0,    0,  106,
  106,  106,  106,  106,  106,    0,  106,    0,    0,    0,
   94,    0,    0,  102,    0,    0,   59,    0,    0,    0,
    0,    0,   59,  102,  102,  102,    0,    0,  102,  102,
  102,  102,  102,  102,   94,  102,    0,  103,    0,    0,
   37,   38,   39,   40,   41,    0,    0,  103,  103,  103,
    0,    0,  103,  103,  103,  103,  103,  103,   90,  103,
    0,   42,    0,    0,    1,    2,   59,    0,    0,    0,
    0,   88,    0,    0,    0,    3,    0,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,    0,    0,
    0,    0,   94,    0,    0,  136,    2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,  137,    4,    0,
    0,    5,    6,    0,    7,    8,    9,    0,   10,    1,
    2,  202,    0,    0,  189,    0,    0,    0,    0,    0,
    3,    0,    4,    0,    0,    5,    6,    0,    7,    8,
    9,    0,   10,    0,    2,  216,    0,  189,    0,    0,
    0,    0,  207,    0,    3,   93,    4,  144,  145,    5,
    6,    0,    7,    8,    9,  189,   10,    0,    2,   58,
    0,    0,    0,  207,    0,    0,  189,    0,    3,   93,
    4,    0,    0,    5,    6,  109,    7,    8,    9,    0,
   10,    0,   90,   60,    0,    0,    0,    0,    0,    0,
    0,    0,   90,   90,   90,   88,    0,   90,   90,   90,
   90,   90,   90,    0,   90,   88,   88,   88,  103,    0,
   88,   88,   88,   88,   88,   88,    2,   88,    0,    0,
    0,    0,  104,    0,    0,    0,    3,   93,    4,    0,
    0,    5,    6,    0,    7,    8,    9,    0,   10,    0,
    0,    0,    1,    2,    0,    0,  106,    0,    0,    0,
    0,    0,    0,    3,  188,    4,    0,    0,    5,    6,
  156,    7,    8,    9,    0,   10,    1,    2,    0,    0,
    0,    0,    0,  174,    0,    0,    0,    3,  188,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
    1,    2,    0,    0,  121,    0,    0,    0,    0,    0,
    0,    3,    0,    4,    0,    0,    5,    6,  117,    7,
    8,    9,    0,   10,    1,    2,    0,    0,    0,    0,
    0,  119,    0,    0,    0,    3,    0,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,  115,    1,
    2,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    3,    0,    4,    1,    2,    5,    6,    0,    7,    8,
    9,    0,   10,    0,    3,    0,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,    1,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,    0,
    4,    1,    2,    5,    6,    0,    7,    8,    9,    0,
   10,    0,    3,    0,    4,    2,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    3,  173,    4,    0,    0,
    5,    6,    0,    7,    8,    9,  121,   10,    0,    0,
    0,    0,    0,    0,    0,    0,  121,  121,  121,    0,
  117,  121,  121,    0,  121,  121,  121,    0,  121,    0,
  117,  117,  117,  119,    0,  117,  117,    0,  117,  117,
  117,    0,  117,  119,  119,  119,   69,   70,  119,  119,
  115,  119,  119,  119,    0,  119,    0,    0,    0,    0,
  115,  115,  115,    1,    2,  115,  115,    0,  115,  115,
  115,    0,  115,    0,    3,  188,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,    0,    0,    0,
    0,    0,    0,  119,    0,    1,    2,    0,  121,  122,
  123,  124,    0,    0,  131,  132,    3,  206,    4,    0,
    0,    5,    6,    0,    7,    8,    9,    0,   10,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  161,  162,
};
short yycheck[] = {                                      40,
    0,   40,  125,   46,   48,  151,   11,   46,   36,   66,
   15,  257,   44,   48,   40,   40,  261,  125,   42,  257,
   45,   41,   61,   47,    0,   45,  186,   59,   44,  275,
  276,  277,   67,   48,   44,   61,  182,   44,   66,   87,
   88,   41,   42,   43,   44,   45,  257,   47,    0,   59,
   40,   56,   67,  257,   98,  215,   43,   59,   45,   94,
   60,   40,   62,   98,   41,   41,   42,   43,   44,   45,
  123,   47,    0,  101,  109,  259,  260,  125,  126,   94,
  128,  129,  256,   98,   60,   59,   62,   91,   92,   41,
  257,   43,   44,   45,  109,  257,    0,   11,   12,   41,
  257,   41,  146,   17,   18,   41,  141,   43,   60,   45,
   62,  146,   44,   41,   44,   43,   44,   45,   44,  256,
    0,  257,   41,  123,  152,  125,  141,  123,  185,   44,
  271,  146,   60,   44,   62,   44,   44,   41,  257,   43,
   44,   45,   44,   40,  267,  123,   41,  123,   43,  125,
   45,   44,  275,  276,  277,  125,   60,  185,   62,  267,
    0,   41,   44,   43,   44,   45,   44,  275,  276,  277,
   41,  123,   43,  125,   45,  271,   44,   44,  125,  125,
   60,   43,   62,   45,    0,   41,  125,   44,  123,    0,
    0,  125,   41,    0,    0,  123,    0,  125,   60,    0,
   62,   41,   41,   43,   44,   45,    0,    0,   40,  125,
  204,  152,  125,  125,   28,  204,  257,    0,  257,  123,
   60,  125,   62,  266,   43,   41,  146,   43,   44,   45,
  109,    0,  257,  258,  259,  260,  261,  257,  258,  259,
  260,  261,   -1,  123,   60,  125,   62,   -1,   -1,   -1,
   -1,   -1,   -1,  278,   -1,   -1,  256,  257,  278,   -1,
   -1,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,    0,  123,   -1,  125,  262,  263,  264,  265,
   -1,  267,  268,  269,   -1,   -1,  272,  273,  274,  275,
  276,  277,   -1,  279,  256,  257,    0,  123,   45,  125,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  276,  277,   44,  279,  256,  257,
    0,   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,
  268,  269,  125,   -1,  272,  273,  274,  275,  276,  277,
   44,  279,  256,  257,    0,   -1,  125,   -1,  262,  263,
  264,  265,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   44,  279,  256,  257,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,    0,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   44,  279,
  262,  263,  264,  265,   -1,   -1,   -1,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
   -1,    0,  262,  263,  264,  265,   -1,  267,  268,  269,
   44,  125,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,    0,  262,  263,  264,  265,
   -1,  267,  268,  269,   -1,  125,  272,  273,  274,  275,
  276,  277,   41,  279,   43,   44,   45,   -1,   -1,    0,
   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,  125,
   -1,   60,   -1,   62,  267,  268,  269,  256,  257,  272,
  273,   41,  275,  276,  277,   45,  279,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,  125,   -1,   41,   -1,   -1,   -1,   45,   -1,   -1,
  257,  258,  259,  260,  261,   -1,   -1,   -1,   -1,   -1,
   -1,   41,   -1,   -1,   -1,   -1,   -1,   42,  256,  257,
   45,  278,   47,   -1,  123,   -1,  125,   -1,   -1,  267,
  268,  269,   41,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   41,   -1,   -1,   -1,   -1,
  125,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  256,  257,   41,   -1,
   -1,   -1,   -1,   -1,  125,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  123,   -1,   -1,   -1,   41,   -1,   -1,
   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  123,   -1,   -1,   -1,   -1,   -1,
   -1,   41,  256,  257,   -1,   42,   -1,  123,   45,   -1,
   47,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
  123,   -1,   44,   -1,   -1,   -1,   -1,  256,  257,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,  123,
  279,  256,  257,   44,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  123,  279,  256,  257,   44,  278,  257,
  258,  259,  260,  261,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
  278,  123,  257,  258,  259,  260,  261,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,  257,  279,
   -1,   -1,   -1,  278,   -1,   -1,   -1,   -1,  267,  268,
  269,  257,   -1,  272,  273,  274,  275,  276,  277,   -1,
  279,  267,  268,  269,   -1,   14,  272,  273,  274,  275,
  276,  277,   -1,  279,  257,   -1,   -1,   -1,  125,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,  276,  277,   -1,  279,   -1,   -1,   -1,
  123,   -1,   -1,  257,   -1,   -1,   55,   -1,   -1,   -1,
   -1,   -1,   61,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,  123,  279,   -1,  257,   -1,   -1,
  257,  258,  259,  260,  261,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,  123,  279,
   -1,  278,   -1,   -1,  256,  257,  105,   -1,   -1,   -1,
   -1,  123,   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,
   -1,   -1,  123,   -1,   -1,  256,  257,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  256,
  257,  125,   -1,   -1,  163,   -1,   -1,   -1,   -1,   -1,
  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,  257,  125,   -1,  186,   -1,   -1,
   -1,   -1,  191,   -1,  267,  268,  269,  270,  271,  272,
  273,   -1,  275,  276,  277,  204,  279,   -1,  257,  125,
   -1,   -1,   -1,  212,   -1,   -1,  215,   -1,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,
  279,   -1,  257,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,  257,   -1,  272,  273,  274,
  275,  276,  277,   -1,  279,  267,  268,  269,  125,   -1,
  272,  273,  274,  275,  276,  277,  257,  279,   -1,   -1,
   -1,   -1,  125,   -1,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
   -1,   -1,  256,  257,   -1,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  125,  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,
   -1,   -1,   -1,  125,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,  267,   -1,  269,   -1,   -1,  272,  273,  125,  275,
  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,
   -1,  125,   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  125,  256,
  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,   -1,  269,  256,  257,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,  267,   -1,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,  256,  257,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,
  269,  256,  257,  272,  273,   -1,  275,  276,  277,   -1,
  279,   -1,  267,   -1,  269,  257,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,  257,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
  257,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
  267,  268,  269,  257,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,  267,  268,  269,   31,   32,  272,  273,
  257,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
  267,  268,  269,  256,  257,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   78,   -1,  256,  257,   -1,   83,   84,
   85,   86,   -1,   -1,   89,   90,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  113,  114,
};
#define YYFINAL 13
#ifndef YYDEBUG
#define YYDEBUG 0
#endif
#define YYMAXTOKEN 279
#if YYDEBUG
char *yyname[] = {
"end-of-file",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,"'('","')'","'*'","'+'","','","'-'","'.'","'/'",0,0,0,0,0,0,0,0,0,0,
0,"';'","'<'","'='","'>'",0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,"'{'",0,"'}'",
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,
0,0,0,0,0,0,0,0,0,0,0,"IDENTIFICADOR","ENTERO_SIN_SIGNO","ENTERO_CORTO",
"PUNTO_FLOTANTE","CADENA_CARACTERES","COMPARADOR_IGUAL_IGUAL",
"COMPARADOR_DISTINTO","COMPARADOR_MENOR_IGUAL","COMPARADOR_MAYOR_IGUAL",
"OPERADOR_SUMA_SUMA","VOID","RETURN","IF","ELSE","END_IF","PRINT","WHILE","DO",
"SHORT","UINT","FLOAT","TOF","CLASS",
};
char *yyrule[] = {
"$accept : programa",
"programa : '{' sentencias '}'",
"programa : '{' '}'",
"programa : '{' sentencias '}' error",
"programa : '{' '}' error",
"programa : sentencias",
"programa : '{' sentencias",
"programa : sentencias '}'",
"programa : '{' comas sentencias '}'",
"programa : '{' comas '}'",
"programa : comas",
"programa : '{' comas",
"programa : comas '}'",
"programa : '{' comas sentencias",
"programa : comas sentencias '}'",
"programa : comas sentencias",
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : declarativa comas",
"sentencia : ejecutable comas",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : error ','",
"comas : ',' comas",
"comas : ','",
"declarativa : tipo lista_de_variables",
"declarativa : declaracion_clase",
"declarativa : declaracion_objeto",
"declarativa : declaracion_funcion",
"declaracion_funcion : funcion_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : funcion_name '(' parametro ')' '{' '}'",
"funcion_name : VOID IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'",
"declaracion_clase : CLASS IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' '}'",
"lista_atributos_y_metodos : lista_atributos_y_metodos tipo lista_de_variables ','",
"lista_atributos_y_metodos : lista_atributos_y_metodos metodo ','",
"lista_atributos_y_metodos : tipo lista_de_variables ','",
"lista_atributos_y_metodos : metodo ','",
"metodo : metodo_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"metodo : metodo_name '(' parametro ')' '{' '}'",
"metodo_name : VOID IDENTIFICADOR",
"metodo_name : VOID",
"declaracion_objeto : IDENTIFICADOR lista_de_objetos",
"lista_de_objetos : lista_de_objetos ';' IDENTIFICADOR",
"lista_de_objetos : IDENTIFICADOR",
"tipo : SHORT",
"tipo : UINT",
"tipo : FLOAT",
"lista_de_variables : lista_de_variables ';' IDENTIFICADOR",
"lista_de_variables : IDENTIFICADOR",
"parametro : tipo IDENTIFICADOR",
"parametro : tipo",
"parametro : IDENTIFICADOR",
"parametro :",
"cuerpo_de_la_funcion : cuerpo_de_la_funcion_sin_return",
"cuerpo_de_la_funcion : cuerpo_de_la_funcion_con_return",
"cuerpo_de_la_funcion_con_return : cuerpo_de_la_funcion_sin_return RETURN ','",
"cuerpo_de_la_funcion_con_return : RETURN ','",
"cuerpo_de_la_funcion_con_return : RETURN ',' cuerpo_de_la_funcion_sin_return",
"cuerpo_de_la_funcion_con_return : RETURN ',' cuerpo_de_la_funcion_con_return",
"cuerpo_de_la_funcion_sin_return : cuerpo_de_la_funcion_sin_return sentencia",
"cuerpo_de_la_funcion_sin_return : sentencia",
"ejecutable : asignacion",
"ejecutable : invocacion",
"ejecutable : seleccion",
"ejecutable : PRINT CADENA_CARACTERES",
"ejecutable : ciclo_while",
"ejecutable : PRINT",
"asignacion : IDENTIFICADOR '=' expresion_aritmetica",
"asignacion : IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica",
"invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'",
"invocacion : IDENTIFICADOR '(' ')'",
"invocacion : IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'",
"invocacion : IDENTIFICADOR '.' IDENTIFICADOR '(' ')'",
"expresion_aritmetica : expresion_aritmetica '+' termino",
"expresion_aritmetica : expresion_aritmetica '-' termino",
"expresion_aritmetica : expresion_aritmetica '-' '*' termino",
"expresion_aritmetica : expresion_aritmetica '+' '*' termino",
"expresion_aritmetica : expresion_aritmetica '-' '/' termino",
"expresion_aritmetica : expresion_aritmetica '+' '/' termino",
"expresion_aritmetica : termino",
"termino : termino '*' factor",
"termino : termino '/' factor",
"termino : factor",
"seleccion : IF bloque_condicion cuerpo_if",
"bloque_condicion : '(' condicion ')'",
"bloque_condicion : '(' condicion",
"bloque_condicion : condicion ')'",
"bloque_condicion : condicion",
"bloque_condicion : '(' ')'",
"cuerpo_if : cuerpo_then else_if cuerpo_else END_IF",
"cuerpo_if : cuerpo_then cuerpo_else END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_then : bloque_ejecutables",
"cuerpo_else : bloque_ejecutables",
"else_if : ELSE",
"ciclo_while : inicio_while bloque_condicion DO cuerpo_while",
"ciclo_while : inicio_while bloque_condicion cuerpo_while",
"inicio_while : WHILE",
"cuerpo_while : bloque_ejecutables",
"condicion : expresion_aritmetica '>' expresion_aritmetica",
"condicion : expresion_aritmetica '<' expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica",
"bloque_ejecutables : '{' sentencias_ejecutables '}'",
"bloque_ejecutables : '{' sentencias_ejecutables RETURN ',' '}'",
"bloque_ejecutables : ejecutable ','",
"bloque_ejecutables : declarativa ','",
"bloque_ejecutables : '{' RETURN ',' '}'",
"bloque_ejecutables : RETURN ','",
"sentencias_ejecutables : sentencias_ejecutables ejecutable ','",
"sentencias_ejecutables : sentencias_ejecutables ejecutable",
"sentencias_ejecutables : ejecutable ','",
"sentencias_ejecutables : ejecutable",
"sentencias_ejecutables : sentencias_ejecutables declarativa ','",
"sentencias_ejecutables : sentencias_ejecutables declarativa",
"sentencias_ejecutables : declarativa ','",
"sentencias_ejecutables : declarativa",
"sentencias_ejecutables : ','",
"sentencias_ejecutables : error ','",
"factor : IDENTIFICADOR",
"factor : IDENTIFICADOR OPERADOR_SUMA_SUMA",
"factor : constanteSinSigno",
"factor : constanteConSigno",
"factor : TOF '(' expresion_aritmetica ')'",
"factor : IDENTIFICADOR '.' IDENTIFICADOR",
"constanteSinSigno : ENTERO_SIN_SIGNO",
"constanteSinSigno : CADENA_CARACTERES",
"constanteConSigno : ENTERO_CORTO",
"constanteConSigno : '-' ENTERO_CORTO",
"constanteConSigno : PUNTO_FLOTANTE",
"constanteConSigno : '-' PUNTO_FLOTANTE",
"constanteConSigno : '-'",
};
#endif
#ifndef YYSTYPE
typedef myTypeYYLVAL* YYSTYPE;
#endif
#define yyclearin (yychar=(-1))
#define yyerrok (yyerrflag=0)
#ifdef YYSTACKSIZE
#ifndef YYMAXDEPTH
#define YYMAXDEPTH YYSTACKSIZE
#endif
#else
#ifdef YYMAXDEPTH
#define YYSTACKSIZE YYMAXDEPTH
#else
#define YYSTACKSIZE 500
#define YYMAXDEPTH 500
#endif
#endif
int yydebug;
int yynerrs;
int yyerrflag;
int yychar;
short *yyssp;
YYSTYPE *yyvsp;
YYSTYPE yyval;
YYSTYPE yylval;
short yyss[YYSTACKSIZE];
YYSTYPE yyvs[YYSTACKSIZE];
#define yystacksize YYSTACKSIZE
#line 282 "./gramaticaComCHZGenerativa.y"
void checkIntegerShort(string lexeme){
        symbol* sm = tableSymbol->getSymbol(lexeme);
        if(sm != nullptr ){
            if(atoi(sm->value.c_str()) >= 128){
                    yyerror("Entero corto fuera de rango { -128 - 127 }");
            }
        }
        else{
                yyerror("No se encuentra el token en la tabla de símbolo");
        }
}
string checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value, "short");
        return lexeme;
}
string setFloatNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;
        
        tableSymbol->insert(lexeme, lexeme, lexeme, "float");
        return lexeme;
}
void checkTypesCompare(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al comparar entre "+ type1 + " y " + type2);
        }
}
bool checkTypesOperation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al operar entre "+ type1 + " y " + type2);
                return false;
        }
        return true;
}
void checkTypesAsignation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al asignar "+ type2 + " a " + type1);
        }
}
// Esta función dado el acceso a un elemento de la tabla de símbolos elimina el simbolo y lo actualiza con el scope y el tipo de esa variable.
symbol* setNewScope(string key, string type, string scope, string uso){
        
        symbol* identificador = tableSymbol->getSymbol(key);    // obtenemos el símbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el símbolo
        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        if(type != ""){
                newIdentificador->type = type;                          // actualizamos el tipo
        }
        if(scope != ""){
                newIdentificador->lexema += scope;                      // actualizamos el scope
        }
        if(uso != ""){
                newIdentificador->uso = uso;                            // actualizamos el uso
        }

        tableSymbol->insert(newIdentificador);                          // insertamos el nuevo símbolo
        return newIdentificador;
}
// Crea un terceto y lo agrega a la tabla de tercetos.
// Los parámtros son argumento, operador1, y operador2
int addTercet(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        int number = tableTercets->add(t);
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos y lo apila.
// Los parámtros son argumento, operador1, y operador2
int addTercetAndStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        int number = tableTercets->add(t);
        tableTercets->push(t);
        return number;
}
// Crea un terceto y lo apila.
// Los parámtros son argumento, operador1, y operador2
void addTercetOnlyStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        tableTercets->push(t);
        return ;
}

// desapila un terceto de la stack de tercetos y la retorna
Tercet* popTercet(){
        return tableTercets->pop();
}
#line 748 "y.tab.c"
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(Lexico* lexico)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;
    extern char *getenv();

    if (yys = getenv("YYDEBUG"))
    {
        yyn = *yys;
        if (yyn >= '0' && yyn <= '9')
            yydebug = yyn - '0';
    }
#endif

    yynerrs = 0;
    yyerrflag = 0;
    yychar = (-1);

    yyssp = yyss;
    yyvsp = yyvs;
    *yyssp = yystate = 0;

yyloop:
    if (yyn = yydefred[yystate]) goto yyreduce;
    if (yychar < 0)
    {
        if ((yychar = lexico->yylex()) < 0) yychar = 0;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, reading %d (%s)\n", yystate,
                    yychar, yys);
        }
#endif
    }
    if ((yyn = yysindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: state %d, shifting to state %d (%s)\n",
                    yystate, yytable[yyn],yyrule[yyn]);
#endif
        if (yyssp >= yyss + yystacksize - 1)
        {
            goto yyoverflow;
        }
        *++yyssp = yystate = yytable[yyn];
        *++yyvsp = yylval;
        yychar = (-1);
        if (yyerrflag > 0)  --yyerrflag;
        goto yyloop;
    }
    if ((yyn = yyrindex[yystate]) && (yyn += yychar) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yychar)
    {
        yyn = yytable[yyn];
        goto yyreduce;
    }
    if (yyerrflag) goto yyinrecovery;
#ifdef lint
    goto yynewerror;
#endif
yynewerror:
    
#ifdef lint
    goto yyerrlab;
#endif
yyerrlab:
    ++yynerrs;
yyinrecovery:
    if (yyerrflag < 3)
    {
        yyerrflag = 3;
        for (;;)
        {
            if ((yyn = yysindex[*yyssp]) && (yyn += YYERRCODE) >= 0 &&
                    yyn <= YYTABLESIZE && yycheck[yyn] == YYERRCODE)
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: state %d, error recovery shifting\
 to state %d\n", *yyssp, yytable[yyn]);
#endif
                if (yyssp >= yyss + yystacksize - 1)
                {
                    goto yyoverflow;
                }
                *++yyssp = yystate = yytable[yyn];
                *++yyvsp = yylval;
                goto yyloop;
            }
            else
            {
#if YYDEBUG
                if (yydebug)
                    printf("yydebug: error recovery discarding state %d\n",
                            *yyssp);
#endif
                if (yyssp <= yyss) goto yyabort;
                --yyssp;
                --yyvsp;
            }
        }
    }
    else
    {
        if (yychar == 0) goto yyabort;
#if YYDEBUG
        if (yydebug)
        {
            yys = 0;
            if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
            if (!yys) yys = "illegal-symbol";
            printf("yydebug: state %d, error recovery discards token %d (%s)\n",
                    yystate, yychar, yys);
        }
#endif
        yychar = (-1);
        goto yyloop;
    }
yyreduce:
#if YYDEBUG
    if (yydebug)
        printf("yydebug: state %d, reducing by rule %d (%s)\n",
                yystate, yyn, yyrule[yyn]);
#endif
    yym = yylen[yyn];
    yyval = yyvsp[1-yym];
    switch (yyn)
    {
case 1:
#line 64 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("FIN", "-", "-");}
break;
case 2:
#line 65 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); Tercet *t = new Tercet("FIN", "-", "-"); int number = tableTercets->add(t); }
break;
case 3:
#line 66 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 4:
#line 67 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 5:
#line 68 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 6:
#line 69 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 7:
#line 70 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 10:
#line 73 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 11:
#line 74 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 12:
#line 75 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 13:
#line 76 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 14:
#line 77 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 15:
#line 78 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 20:
#line 87 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 21:
#line 88 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 22:
#line 89 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 25:
#line 96 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 27:
#line 98 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 28:
#line 99 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 29:
#line 102 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope();}
break;
case 30:
#line 103 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 31:
#line 104 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 32:
#line 107 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "funcion"); if(diff == 0){yyerror("Redeclaración de función en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion");} tableSymbol->addScope(yyvsp[0]->ptr); }
break;
case 33:
#line 110 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 34:
#line 111 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 35:
#line 112 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 36:
#line 114 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 38:
#line 116 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 40:
#line 121 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); }
break;
case 41:
#line 122 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 42:
#line 125 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope(yyvsp[0]->ptr);}
break;
case 43:
#line 126 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de método"); }
break;
case 47:
#line 136 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 48:
#line 137 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 49:
#line 138 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 50:
#line 141 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 51:
#line 143 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 52:
#line 146 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, yyvsp[-1]->type, tableSymbol->getScope(), "parametro"); yyval->ptr = newIdentificador->lexema; yyval->type = yyvsp[-1]->type;}
break;
case 53:
#line 147 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de parámetro"); }
break;
case 54:
#line 148 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de tipo de parámetro"); }
break;
case 56:
#line 152 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 60:
#line 157 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 61:
#line 158 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 67:
#line 166 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 69:
#line 168 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 70:
#line 171 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 76:
#line 182 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 77:
#line 183 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 78:
#line 184 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 79:
#line 185 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 80:
#line 186 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 81:
#line 187 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 82:
#line 188 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 83:
#line 191 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 84:
#line 192 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 85:
#line 193 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 86:
#line 196 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}}
break;
case 87:
#line 199 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 88:
#line 200 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de ultimo paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 89:
#line 201 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de primer paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 90:
#line 202 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de parantesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 91:
#line 203 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 93:
#line 207 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 97:
#line 215 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2));} int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 98:
#line 217 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet(); int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 99:
#line 218 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de DO en WHILE-DO"); Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet();int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 100:
#line 221 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 102:
#line 234 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 103:
#line 235 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 104:
#line 236 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 105:
#line 237 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 106:
#line 238 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 107:
#line 239 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 111:
#line 245 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 115:
#line 251 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 117:
#line 253 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 118:
#line 254 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 119:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 120:
#line 256 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 121:
#line 257 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 122:
#line 258 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 123:
#line 259 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 124:
#line 262 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 125:
#line 263 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 126:
#line 264 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 127:
#line 265 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 128:
#line 266 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 130:
#line 270 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 131:
#line 271 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 132:
#line 274 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 133:
#line 275 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 134:
#line 276 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 135:
#line 277 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 136:
#line 278 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 1264 "y.tab.c"
    }
    yyssp -= yym;
    yystate = *yyssp;
    yyvsp -= yym;
    yym = yylhs[yyn];
    if (yystate == 0 && yym == 0)
    {
#if YYDEBUG
        if (yydebug)
            printf("yydebug: after reduction, shifting from state 0 to\
 state %d\n", YYFINAL);
#endif
        yystate = YYFINAL;
        *++yyssp = YYFINAL;
        *++yyvsp = yyval;
        if (yychar < 0)
        {
            if ((yychar = lexico->yylex()) < 0) yychar = 0;
#if YYDEBUG
            if (yydebug)
            {
                yys = 0;
                if (yychar <= YYMAXTOKEN) yys = yyname[yychar];
                if (!yys) yys = "illegal-symbol";
                printf("yydebug: state %d, reading %d (%s)\n",
                        YYFINAL, yychar, yys);
            }
#endif
        }
        if (yychar == 0) goto yyaccept;
        goto yyloop;
    }
    if ((yyn = yygindex[yym]) && (yyn += yystate) >= 0 &&
            yyn <= YYTABLESIZE && yycheck[yyn] == yystate)
        yystate = yytable[yyn];
    else
        yystate = yydgoto[yym];
#if YYDEBUG
    if (yydebug)
        printf("yydebug: after reduction, shifting from state %d \
to state %d\n", *yyssp, yystate);
#endif
    if (yyssp >= yyss + yystacksize - 1)
    {
        goto yyoverflow;
    }
    *++yyssp = yystate;
    *++yyvsp = yyval;
    goto yyloop;
yyoverflow:
    yyerror("yacc stack overflow");
yyabort:
    return (1);
yyaccept:
    return (0);
}
