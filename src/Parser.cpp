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
   19,   18,   18,    5,    5,    5,    5,    5,    5,    5,
   20,   21,   21,   25,   25,   25,   25,   25,   25,   25,
   26,   26,   26,   22,   28,   28,   28,   28,   28,   29,
   29,   29,   31,   33,   32,   23,   23,   35,   36,   30,
   30,   30,   30,   30,   30,   34,   34,   34,   34,   34,
   34,   37,   37,   37,   37,   37,   37,   37,   37,   37,
   37,   27,   27,   27,   27,   27,   38,   38,   39,   39,
   39,   39,   39,   24,   24,   24,   24,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    1,    2,    2,    4,    3,    1,
    2,    2,    3,    3,    2,    2,    1,    2,    2,    1,
    1,    2,    2,    1,    2,    1,    1,    1,    7,    7,
    6,    2,    5,    2,    4,    4,    3,    3,    2,    7,
    6,    2,    1,    2,    3,    1,    1,    1,    1,    3,
    1,    2,    1,    1,    0,    1,    1,    3,    2,    3,
    3,    2,    1,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    3,    3,    3,    4,    4,    4,    4,    1,
    3,    3,    1,    3,    3,    2,    2,    1,    2,    4,
    3,    2,    1,    1,    1,    4,    3,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    5,    2,    2,    4,
    2,    3,    2,    2,    1,    3,    2,    2,    1,    1,
    2,    1,    2,    1,    1,    4,    1,    1,    1,    2,
    1,    2,    1,    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,   98,   47,   48,   49,    0,
    0,    0,    0,    0,    0,   17,    0,    0,    0,   26,
   27,   28,    0,   64,   65,   66,   68,   69,    0,   22,
   46,    0,    0,    0,    0,   32,    0,    0,  127,  129,
  131,  128,    0,    0,    0,    0,    0,   83,    0,    0,
  124,  125,   67,    0,    0,    0,    0,   23,    7,   16,
   12,    0,   18,   19,   51,    0,    0,    0,   73,    0,
    0,    0,    0,   54,    0,    0,  123,    0,   89,    0,
  130,  132,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   84,    0,   93,   87,
    0,    4,    0,    9,    0,   14,    0,    0,    0,   99,
   97,   72,    0,    0,   45,   52,    0,    0,   85,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   81,   82,  111,    0,    0,  120,    0,    0,    0,
  109,  108,   95,   92,    0,    0,   94,    0,   35,    0,
    0,    0,    0,    3,    8,   50,    0,   96,  137,    0,
    0,    0,    0,  126,    0,    0,    0,    0,  121,    0,
  118,  114,    0,  106,    0,    0,    0,   91,   42,    0,
   33,    0,    0,   39,    0,    0,  136,    0,    0,   63,
    0,    0,   57,  110,    0,  116,  112,   90,   38,    0,
   37,    0,   31,    0,  135,    0,   30,    0,   62,  107,
   36,    0,   29,    0,   61,   58,    0,   41,    0,   40,
};
short yydgoto[] = {                                      13,
   14,   15,   16,   17,   18,   19,   66,   20,   21,   22,
   23,   76,  191,  151,  152,  153,   35,  192,  193,   24,
   25,   26,   27,   28,   46,   47,   48,   49,   97,   50,
   98,  145,  146,  110,   29,  111,  140,   51,   52,
};
short yysindex[] = {                                    658,
  -27,  -40,  -38,  -26, -238,    0,    0,    0,    0, -230,
  689,  -10,    0,  873,  897,    0,  -10,  -10, -221,    0,
    0,    0,   12,    0,    0,    0,    0,    0,  -26,    0,
    0,  -19,  246, -217,   36,    0, -247, -206,    0,    0,
    0,    0,   31,  154, -205,  566,    9,    0,  788,   58,
    0,    0,    0,  -22, -153,  921,  946,    0,    0,    0,
    0,  971,    0,    0,    0,   46, -247,  675,    0,   38,
  -30,  -28, -151,    0, -150,   67,    0,  246,    0,   69,
    0,    0,  246,  246,  246,  246,  501,  580,  246,  246,
  246,  246,   68,  703,   71,   75,    0,  720,    0,    0,
 -122,    0, -143,    0,  995,    0, -137,   84,  788,    0,
    0,    0,  457,  258,    0,    0,    5,   41,    0,  -30,
  -30,  -30,  -30,  246,  246,    9,  246,  246,    9,  -30,
  -30,    0,    0,    0,   85,   86,    0,   87,   88,  859,
    0,    0,    0,    0,  788, -135,    0, -123,    0, -221,
 -107,   93,   99,    0,    0,    0,   20,    0,    0,   57,
  -42,  -30, 1070,    0,    9,    9,    9,    9,    0,   19,
    0,    0,  105,    0,  107,  112, -124,    0,    0,  -24,
    0, -221,  114,    0, -247,  813,    0,  -94,  123,    0,
   48, 1097,    0,    0,   50,    0,    0,    0,    0,  -20,
    0,  135,    0,   52,    0, 1070,    0,  134,    0,    0,
    0,   56,    0, 1097,    0,    0,  838,    0,   59,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
    0,  254,    0,  182,  186,    0,  496,  520,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  295,    0,  146,    1,    0,    0,
    0,    0,    0,    0,   25,    0,   49,    0,    0,  737,
    0,    0,    0,  331,  188,  189,  190,    0,    0,    0,
    0,  191,    0,    0,    0,  387,  146,    0,    0,    0,
  455,    0,    0,    0,  151,    0,    0,    0,    0,  761,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  193,    0,  194,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  534,
  548,  577,  606,    0,    0,   73,    0,    0,   97,  620,
  633,    0,    0,    0,    0,    0,    0, 1008, 1022,    0,
    0,    0,    0,    0,    0,    0,    0,  160,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  363,  469,    0,    0,  121,  161,  185,  422,    0,    0,
    0,    0,    0,    0, 1035, 1056,    0,    0,    0,    0,
    0,    0,    0,    0,  146,    0,    0,    0,    0,    0,
    0,   78,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   82,    0,    0,    0,    0,
    0,    0,    0,   83,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   -4,   47,  862,  -18,  103,   -5, -141,    0,    0,    0,
    0,  -62, -170,    0,   60,    0,    0,    3,    4,    0,
    0,    0,    0,    0, 1273,  -50,   -3,  184,    0,  170,
    0,    0,   70,  -41,    0,  116,    0,    0,    0,
};
#define YYTABLESIZE 1387
short yytable[] = {                                      32,
  122,   37,  149,  188,  108,   34,   56,   99,  180,   74,
   62,  113,   87,   44,   88,  204,   30,  181,   45,  199,
   33,   69,   53,  211,  133,   45,   54,    7,    8,    9,
   95,   75,  114,   12,  107,   65,  126,  129,  107,   72,
  200,  122,  122,  122,  122,  122,  219,  122,   80,   95,
   91,   67,  105,   81,   82,   92,  147,   57,   58,   77,
  122,   75,  122,   63,   64,  133,  133,  133,  133,  133,
   78,  133,   74,  165,  166,  138,  167,  168,  112,   95,
   87,  164,   88,   87,  133,   88,  133,  132,  133,   80,
   95,   80,   80,   80,   73,  150,   75,  187,  100,   87,
  101,   88,  102,  147,  107,  115,  116,  117,   80,  119,
   80,  134,  154,   74,  141,   74,   74,   74,  142,  156,
   77,  175,  202,  122,  157,  122,   95,  163,  169,  170,
  171,  172,   74,  179,   74,  178,  184,   75,  185,   75,
   75,   75,  186,  194,  148,  182,  198,  133,  195,  133,
  196,   96,    7,    8,    9,  197,   75,  201,   75,  148,
   79,   77,  205,   77,   77,   77,  206,    7,    8,    9,
   96,   80,  207,   80,  210,  212,  213,  216,  217,   75,
   77,    5,   77,  220,   76,   10,   55,    2,    6,   11,
   15,   53,    1,   13,   79,   74,  139,   74,   45,   43,
   96,   79,   56,   79,   79,   79,   59,   60,  214,  215,
  183,   96,   68,   80,  177,    0,   31,   70,   36,   75,
   79,   75,   79,   77,  158,   76,    0,   76,   76,   76,
   38,   39,   40,   41,   42,    0,    0,   38,   39,   40,
   41,   42,  176,   77,   76,   77,   76,   96,    0,    0,
    0,   43,    0,   24,    0,    0,  122,  122,   43,    0,
    0,   70,  122,  122,  122,  122,    0,  122,  122,  122,
    0,    0,  122,  122,  122,  122,  122,  122,    0,  122,
  133,  133,    0,   79,    0,   79,  133,  133,  133,  133,
   45,  133,  133,  133,   44,    0,  133,  133,  133,  133,
  133,  133,   45,  133,   80,   80,    0,   76,    0,   76,
   80,   80,   80,   80,    0,   80,   80,   80,    0,    0,
   80,   80,   80,   80,   80,   80,    0,   80,   74,   74,
   34,    0,    0,    0,   74,   74,   74,   74,   44,   74,
   74,   74,   70,    0,   74,   74,   74,   74,   74,   74,
    0,   74,   75,   75,    0,    0,    0,    0,   75,   75,
   75,   75,  122,   75,   75,   75,    0,    0,   75,   75,
   75,   75,   75,   75,   34,   75,   77,   77,   24,    0,
    0,    0,   77,   77,   77,   77,   25,   77,   77,   77,
    0,    0,   77,   77,   77,   77,   77,   77,    0,   77,
    0,    0,    0,    0,  122,  122,  122,  122,    0,  122,
   38,   39,   40,   41,   42,    0,   79,   79,    0,   44,
    0,   78,   79,   79,   79,   79,    0,   79,   79,   79,
   25,   43,   79,   79,   79,   79,   79,   79,    0,   79,
   76,   76,    0,    0,    0,    0,   76,   76,   76,   76,
    0,   76,   76,   76,   71,   34,   76,   76,   76,   76,
   76,   76,   78,   76,   78,   78,   78,    0,  134,    0,
    0,    0,    0,   70,   70,    0,    0,    0,    0,    0,
    0,   78,    0,   78,   70,   70,   70,  122,    0,   70,
   70,    0,   70,   70,   70,   20,   70,  159,   71,    0,
    0,   45,   38,   39,   40,   41,   42,    0,    0,   24,
   24,   25,  134,    0,  161,   39,   40,   41,   42,   21,
   24,   24,   24,   43,    0,   24,   24,    0,   24,   24,
   24,    0,   24,    0,    0,   43,    0,    0,    0,    0,
    0,    0,  124,    0,   78,   45,   78,  125,    0,    0,
   44,   44,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   44,   44,   44,    0,    0,   44,   44,    0,   44,
   44,   44,    0,   44,  102,    0,    0,    0,    0,   71,
    0,    0,    0,    0,    0,    0,   34,   34,  103,    0,
    0,    0,    0,  134,    0,    0,    0,   34,   34,   34,
    0,    0,   34,   34,    0,   34,   34,   34,   87,   34,
   88,    0,    0,    0,    0,    0,    0,  105,  122,  122,
   20,  127,    0,    0,   45,   90,  128,   89,    0,  122,
  122,  122,    0,    0,  122,  122,    0,  122,  122,  122,
    0,  122,   25,   25,   21,    0,  104,    0,    0,    0,
    0,    0,    0,   25,   25,   25,  102,    0,   25,   25,
  100,   25,   25,   25,    0,   25,    0,    0,    0,    0,
  103,    0,    0,  101,    0,    0,    0,   78,   78,    0,
    0,    0,    0,   78,   78,   78,   78,    0,   78,   78,
   78,    0,    0,   78,   78,   78,   78,   78,   78,  105,
   78,   12,    0,    0,    0,    0,    0,    0,    0,    0,
   71,   71,    0,   38,   39,   40,   41,   42,    0,    0,
    0,   71,   71,   71,  134,  134,   71,   71,  104,   71,
   71,   71,   12,   71,   43,  134,  134,  134,    0,    0,
  134,  134,  100,  134,  134,  134,  137,  134,    0,    0,
    0,   20,   20,    0,    0,  101,    0,   38,   39,   40,
   41,   42,   20,   20,   20,    0,    0,   20,   20,    0,
   20,   20,   20,    0,   20,   21,   21,    0,   43,    0,
   11,    0,    0,    0,    0,    0,   21,   21,   21,    0,
  102,   21,   21,    0,   21,   21,   21,   94,   21,    0,
  102,  102,  102,    0,  103,  102,  102,  102,  102,  102,
  102,    0,  102,   55,  103,  103,  103,    0,    0,  103,
  103,  103,  103,  103,  103,    0,  103,   83,   84,   85,
   86,    0,    0,  105,    0,    0,   38,   39,   40,   41,
   42,    0,   94,  105,  105,  105,    0,    0,  105,  105,
  105,  105,  105,  105,    0,  105,    0,   43,    0,   88,
    0,    0,  104,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  104,  104,  104,   60,  100,  104,  104,  104,
  104,  104,  104,   86,  104,    0,  100,  100,  100,  101,
    0,  100,  100,  100,  100,  100,  100,    0,  100,  101,
  101,  101,    0,    0,  101,  101,  101,  101,  101,  101,
   94,  101,    0,    1,    2,    0,    0,   60,    0,    0,
    0,    0,    0,   60,    3,    0,    4,    0,    0,    5,
    6,    2,    7,    8,    9,    0,   10,  203,    0,    0,
    0,    3,   93,    4,    1,    2,    5,    6,  109,    7,
    8,    9,    0,   10,    0,    3,    0,    4,  135,    2,
    5,    6,  218,    7,    8,    9,   60,   10,    0,    3,
  136,    4,    0,    0,    5,    6,    2,    7,    8,    9,
    0,   10,    0,  174,    0,    0,    3,   93,    4,  143,
  144,    5,    6,   88,    7,    8,    9,   59,   10,    0,
    0,    0,    0,   88,   88,   88,    0,    0,   88,   88,
   88,   88,   88,   88,    0,   88,    0,   86,    0,    0,
    0,   61,    0,    0,  190,    0,    0,   86,   86,   86,
    0,    0,   86,   86,   86,   86,   86,   86,    0,   86,
    0,    0,    0,    0,    2,  103,    0,  190,    0,    0,
    0,    0,    0,  209,    3,   93,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,  190,    1,    2,
  104,    0,    0,    0,    0,  209,    0,    0,  190,    3,
  189,    4,    0,    0,    5,    6,    0,    7,    8,    9,
    0,   10,    0,    1,    2,  106,    0,    0,    0,    0,
    0,    0,    0,    0,    3,  189,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    2,   10,    0,    0,  155,
    0,    0,    0,    0,    0,    3,  173,    4,    1,    2,
    5,    6,  119,    7,    8,    9,    0,   10,    0,    3,
    0,    4,    0,    0,    5,    6,  115,    7,    8,    9,
    0,   10,    1,    2,    0,    0,    0,    0,    0,  117,
    0,    0,    0,    3,    0,    4,    0,    0,    5,    6,
    0,    7,    8,    9,    0,   10,    1,    2,    0,    0,
  113,    0,    0,    0,    0,    0,    0,    3,    0,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
    0,    1,    2,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    4,    0,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    0,    1,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,    0,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    4,  119,    0,    5,    6,    0,    7,
    8,    9,    0,   10,  119,  119,  119,    0,  115,  119,
  119,    0,  119,  119,  119,    0,  119,    0,  115,  115,
  115,  117,    0,  115,  115,    0,  115,  115,  115,    0,
  115,  117,  117,  117,   70,   71,  117,  117,    0,  117,
  117,  117,  113,  117,    0,    0,    0,    0,    0,    0,
    0,    0,  113,  113,  113,    1,    2,  113,  113,    0,
  113,  113,  113,    0,  113,    0,    3,  189,    4,    0,
    0,    5,    6,    0,    7,    8,    9,    0,   10,    0,
  118,    0,    1,    2,    0,  120,  121,  122,  123,    0,
    0,  130,  131,    3,  208,    4,    0,    0,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  160,  162,
};
short yycheck[] = {                                      40,
    0,   40,  125,   46,   67,   46,   11,   49,  150,  257,
   15,   40,   43,   40,   45,  186,   44,  125,   45,   44,
   61,   41,  261,   44,    0,   45,  257,  275,  276,  277,
   49,   37,   61,   44,   59,  257,   87,   88,   59,  257,
  182,   41,   42,   43,   44,   45,  217,   47,    0,   68,
   42,   40,   57,  259,  260,   47,   98,   11,   12,  266,
   60,   67,   62,   17,   18,   41,   42,   43,   44,   45,
   40,   47,    0,  124,  125,   94,  127,  128,   41,   98,
   43,   41,   45,   43,   60,   45,   62,   91,   92,   41,
  109,   43,   44,   45,   59,  101,    0,   41,   41,   43,
  123,   45,  256,  145,   59,  257,  257,   41,   60,   41,
   62,   44,  256,   41,   44,   43,   44,   45,   44,  257,
    0,  140,  185,  123,   41,  125,  145,  123,   44,   44,
   44,   44,   60,  257,   62,  271,   44,   41,   40,   43,
   44,   45,  123,  125,  267,  151,  271,  123,   44,  125,
   44,   49,  275,  276,  277,   44,   60,   44,   62,  267,
    0,   41,  257,   43,   44,   45,   44,  275,  276,  277,
   68,  123,  125,  125,  125,   41,  125,   44,  123,  185,
   60,    0,   62,  125,    0,    0,   41,    0,    0,    0,
    0,   41,    0,    0,   41,  123,   94,  125,   45,   40,
   98,   41,  125,   43,   44,   45,  125,  125,  206,  206,
  151,  109,   29,   44,  145,   -1,  257,    0,  257,  123,
   60,  125,   62,  266,  109,   41,   -1,   43,   44,   45,
  257,  258,  259,  260,  261,   -1,   -1,  257,  258,  259,
  260,  261,  140,  123,   60,  125,   62,  145,   -1,   -1,
   -1,  278,   -1,    0,   -1,   -1,  256,  257,  278,   -1,
   -1,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   -1,  123,   -1,  125,  262,  263,  264,  265,
   45,  267,  268,  269,    0,   -1,  272,  273,  274,  275,
  276,  277,   45,  279,  256,  257,   -1,  123,   -1,  125,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  276,  277,   -1,  279,  256,  257,
    0,   -1,   -1,   -1,  262,  263,  264,  265,   44,  267,
  268,  269,  125,   -1,  272,  273,  274,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,    0,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   44,  279,  256,  257,  125,   -1,
   -1,   -1,  262,  263,  264,  265,    0,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,   -1,   42,   43,   44,   45,   -1,   47,
  257,  258,  259,  260,  261,   -1,  256,  257,   -1,  125,
   -1,    0,  262,  263,  264,  265,   -1,  267,  268,  269,
   44,  278,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
   -1,  267,  268,  269,    0,  125,  272,  273,  274,  275,
  276,  277,   41,  279,   43,   44,   45,   -1,    0,   -1,
   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   60,   -1,   62,  267,  268,  269,  125,   -1,  272,
  273,   -1,  275,  276,  277,    0,  279,   41,   44,   -1,
   -1,   45,  257,  258,  259,  260,  261,   -1,   -1,  256,
  257,  125,   44,   -1,  257,  258,  259,  260,  261,    0,
  267,  268,  269,  278,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,   -1,  278,   -1,   -1,   -1,   -1,
   -1,   -1,   42,   -1,  123,   45,  125,   47,   -1,   -1,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   41,   -1,   -1,   -1,   -1,  125,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   41,   -1,
   -1,   -1,   -1,  125,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   43,  279,
   45,   -1,   -1,   -1,   -1,   -1,   -1,   41,  256,  257,
  125,   42,   -1,   -1,   45,   60,   47,   62,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,  125,   -1,   41,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,  123,   -1,  272,  273,
   41,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
  123,   -1,   -1,   41,   -1,   -1,   -1,  256,  257,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,  123,
  279,   44,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  256,  257,   -1,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  267,  268,  269,  256,  257,  272,  273,  123,  275,
  276,  277,   44,  279,  278,  267,  268,  269,   -1,   -1,
  272,  273,  123,  275,  276,  277,   44,  279,   -1,   -1,
   -1,  256,  257,   -1,   -1,  123,   -1,  257,  258,  259,
  260,  261,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  256,  257,   -1,  278,   -1,
  123,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
  257,  272,  273,   -1,  275,  276,  277,  123,  279,   -1,
  267,  268,  269,   -1,  257,  272,  273,  274,  275,  276,
  277,   -1,  279,  125,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,  276,  277,   -1,  279,  262,  263,  264,
  265,   -1,   -1,  257,   -1,   -1,  257,  258,  259,  260,
  261,   -1,  123,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   -1,  279,   -1,  278,   -1,  123,
   -1,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,   14,  257,  272,  273,  274,
  275,  276,  277,  123,  279,   -1,  267,  268,  269,  257,
   -1,  272,  273,  274,  275,  276,  277,   -1,  279,  267,
  268,  269,   -1,   -1,  272,  273,  274,  275,  276,  277,
  123,  279,   -1,  256,  257,   -1,   -1,   56,   -1,   -1,
   -1,   -1,   -1,   62,  267,   -1,  269,   -1,   -1,  272,
  273,  257,  275,  276,  277,   -1,  279,  125,   -1,   -1,
   -1,  267,  268,  269,  256,  257,  272,  273,  274,  275,
  276,  277,   -1,  279,   -1,  267,   -1,  269,  256,  257,
  272,  273,  125,  275,  276,  277,  105,  279,   -1,  267,
  268,  269,   -1,   -1,  272,  273,  257,  275,  276,  277,
   -1,  279,   -1,  125,   -1,   -1,  267,  268,  269,  270,
  271,  272,  273,  257,  275,  276,  277,  125,  279,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   -1,  279,   -1,  257,   -1,   -1,
   -1,  125,   -1,   -1,  163,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,   -1,  257,  125,   -1,  186,   -1,   -1,
   -1,   -1,   -1,  192,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,  206,  256,  257,
  125,   -1,   -1,   -1,   -1,  214,   -1,   -1,  217,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,   -1,  256,  257,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  257,  279,   -1,   -1,  125,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  256,  257,
  272,  273,  125,  275,  276,  277,   -1,  279,   -1,  267,
   -1,  269,   -1,   -1,  272,  273,  125,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,  125,
   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,  256,  257,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,   -1,  269,  257,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  267,  268,  269,   -1,  257,  272,
  273,   -1,  275,  276,  277,   -1,  279,   -1,  267,  268,
  269,  257,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,  267,  268,  269,   32,   33,  272,  273,   -1,  275,
  276,  277,  257,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,  256,  257,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
   78,   -1,  256,  257,   -1,   83,   84,   85,   86,   -1,
   -1,   89,   90,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  113,  114,
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
"ejecutable : acceso_objeto",
"ejecutable : PRINT",
"asignacion : IDENTIFICADOR '=' expresion_aritmetica",
"invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'",
"invocacion : IDENTIFICADOR '(' ')'",
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
"constanteSinSigno : ENTERO_SIN_SIGNO",
"constanteSinSigno : CADENA_CARACTERES",
"constanteConSigno : ENTERO_CORTO",
"constanteConSigno : '-' ENTERO_CORTO",
"constanteConSigno : PUNTO_FLOTANTE",
"constanteConSigno : '-' PUNTO_FLOTANTE",
"constanteConSigno : '-'",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' ')'",
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
#line 285 "./gramaticaComCHZGenerativa.y"
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
#line 751 "y.tab.c"
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
    yyerror("se detecó una sentenica inválida");
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
case 70:
#line 169 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 71:
#line 172 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 74:
#line 180 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 75:
#line 181 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 76:
#line 182 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 77:
#line 183 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
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
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 81:
#line 189 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 82:
#line 190 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 191 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 84:
#line 194 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}}
break;
case 85:
#line 197 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 86:
#line 198 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de ultimo paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 87:
#line 199 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de primer paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 88:
#line 200 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de parantesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 89:
#line 201 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 91:
#line 205 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 95:
#line 213 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2));} int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 96:
#line 215 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet(); int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 97:
#line 216 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de DO en WHILE-DO"); Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet();int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 98:
#line 219 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 100:
#line 232 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 101:
#line 233 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 102:
#line 234 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 103:
#line 235 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 104:
#line 236 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 105:
#line 237 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 109:
#line 243 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 113:
#line 249 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 115:
#line 251 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 116:
#line 252 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 117:
#line 253 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 118:
#line 254 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 119:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 120:
#line 256 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 121:
#line 257 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 122:
#line 260 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 123:
#line 261 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 124:
#line 262 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 125:
#line 263 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 126:
#line 264 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 127:
#line 267 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 128:
#line 268 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 129:
#line 271 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 130:
#line 272 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 131:
#line 273 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 132:
#line 274 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 133:
#line 275 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 134:
#line 278 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 135:
#line 279 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 136:
#line 280 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 137:
#line 281 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1283 "y.tab.c"
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
