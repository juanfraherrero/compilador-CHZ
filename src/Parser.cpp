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
    0,    0,    0,    0,    0,    0,    0,    0,    1,    1,
    3,    3,    3,    3,    3,    2,    2,    4,    4,    4,
    4,   10,   10,   10,   11,    8,    8,    8,   14,   14,
   14,   14,   15,   15,   16,   16,    9,   17,   17,    6,
    6,    6,    7,    7,   12,   12,   12,   12,   13,   13,
   19,   19,   19,   19,   18,   18,    5,    5,    5,    5,
    5,    5,    5,    5,   20,   20,   21,   21,   21,   21,
   26,   26,   26,   26,   26,   26,   26,   27,   27,   27,
   22,   29,   29,   29,   29,   29,   30,   30,   30,   32,
   34,   33,   25,   25,   36,   37,   31,   31,   31,   31,
   31,   31,   35,   35,   35,   35,   35,   35,   38,   38,
   38,   38,   38,   38,   38,   38,   38,   38,   28,   28,
   28,   28,   28,   28,   28,   24,   23,   23,   23,   23,
   23,
};
short yylen[] = {                                         2,
    3,    2,    1,    1,    4,    3,    1,    2,    2,    4,
    3,    1,    2,    2,    3,    3,    2,    0,    2,    1,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    1,
    1,    7,    7,    6,    2,    5,    2,    4,    4,    3,
    3,    2,    7,    6,    2,    1,    2,    3,    1,    1,
    1,    1,    3,    1,    2,    1,    1,    0,    1,    1,
    3,    2,    3,    3,    2,    1,    1,    1,    1,    2,
    2,    2,    2,    1,    3,    5,    4,    3,    6,    5,
    3,    3,    4,    4,    4,    4,    1,    3,    3,    1,
    3,    3,    2,    2,    1,    2,    4,    3,    2,    1,
    1,    1,    4,    3,    1,    1,    3,    3,    3,    3,
    3,    3,    3,    5,    2,    2,    4,    2,    3,    2,
    2,    1,    3,    2,    2,    1,    1,    2,    1,    2,
    1,    1,    4,    3,    1,    1,    1,    2,    1,    2,
    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,  105,   50,   51,   52,    0,
    0,    4,    0,    0,    0,    0,   20,    0,    0,    0,
   29,   30,   31,    0,   67,   68,   69,   74,    0,   25,
   49,    0,    0,    0,    0,   35,    0,    0,  136,  137,
  139,  135,    0,    0,    0,  132,  131,    0,    0,   90,
    0,    0,   71,   70,   72,   73,    0,    0,    0,    0,
   26,    9,   19,   14,    0,   21,   22,   54,    0,    0,
    0,   78,    0,    0,    0,    0,   57,    0,    0,  130,
    0,    0,   96,    0,  138,  140,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   91,    0,  100,   94,    0,    6,    0,   11,    0,   16,
    0,    0,    0,  106,  104,   77,    0,    0,   48,   55,
    0,  134,    0,   92,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   88,   89,  118,    0,
    0,  127,    0,    0,    0,  116,  115,  102,   99,    0,
    0,  101,    0,   38,    0,    0,    0,    0,    5,   10,
   53,    0,  103,   80,    0,    0,    0,  133,    0,    0,
    0,    0,  128,    0,  125,  121,    0,  113,    0,    0,
    0,   98,   45,    0,   36,    0,    0,   42,    0,    0,
   79,    0,   66,    0,    0,   60,  117,    0,  123,  119,
   97,   41,    0,   40,    0,   34,    0,    0,   33,    0,
   65,  114,   39,    0,   32,    0,   64,   61,    0,   44,
    0,   43,
};
short yydgoto[] = {                                      14,
   15,   16,   17,   18,   19,   20,   69,   21,   22,   23,
   24,   79,  194,  156,  157,  158,   35,  195,  196,   25,
   26,   27,   46,   47,   28,   48,   49,   50,   51,  101,
   52,  102,  150,  151,  114,   29,  115,  145,
};
short yysindex[] = {                                    656,
  -20,  -38,  -40,  -24,   -9,    0,    0,    0,    0, -237,
  627,    0,    7,    0,  838,  852,    0,    7,    7, -222,
    0,    0,    0,   15,    0,    0,    0,    0,  -24,    0,
    0,  -19,  447, -198,   12,    0, -245,  -42,    0,    0,
    0,    0,   42,  360, -232,    0,    0,  147,    5,    0,
  765,   24,    0,    0,    0,    0,  -37, -165,  879,  905,
    0,    0,    0,    0,  929,    0,    0,    0,   43, -245,
  726,    0,   19,  -28,  -27, -152,    0, -150,   69,    0,
 -142,  447,    0,   79,    0,    0,  447,  447,  447,  447,
  496,  595,  447,  447,  447,  447,   78,  591,   85,   86,
    0,  677,    0,    0, -122,    0, -133,    0,  953,    0,
 -126,   93,  765,    0,    0,    0,  457,  447,    0,    0,
   13,    0,   55,    0,  -28,  -28,  -28,  -28,  447,  447,
    5,  447,  447,    5,  -28,  -28,    0,    0,    0,   95,
   99,    0,  100,  102,  865,    0,    0,    0,    0,  765,
 -134,    0, -110,    0, -222, -107,  105,  112,    0,    0,
    0,   40,    0,    0,   58,  -28, 1028,    0,    5,    5,
    5,    5,    0,   46,    0,    0,  123,    0,  129,  131,
  -95,    0,    0,  -30,    0, -222,  133,    0, -245,  789,
    0,  134,    0,   54, 1059,    0,    0,   57,    0,    0,
    0,    0,   -3,    0,  139,    0,   59, 1028,    0,  142,
    0,    0,    0,   64,    0, 1059,    0,    0,  813,    0,
   63,    0,
};
short yyrindex[] = {                                    189,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  191,    0,  232,    0,  193,  194,    0,  256,  391,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  218,    0,  154,    1,    0,    0,
    0,    0,    0,    0,   25,    0,    0,    0,   49,    0,
    0,  739,    0,    0,    0,    0,  283,  197,  199,  200,
    0,    0,    0,    0,  201,    0,    0,    0,  307,  154,
    0,    0,    0,  331,    0,    0,    0,  162,    0,    0,
    0,    0,    0,  752,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  208,    0,  210,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  455,  469,  493,  516,    0,    0,
   73,    0,    0,   97,  529,  550,    0,    0,    0,    0,
    0,    0,  966,  979,    0,    0,    0,    0,    0,    0,
    0,    0,  171,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  355,    0,    0,  121,  161,
  185,  422,    0,    0,    0,    0,    0,    0,  993, 1014,
    0,    0,    0,    0,    0,    0,    0,    0,  154,    0,
    0,    0,    0,    0,   87,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   88,    0,    0,
    0,    0,    0,    0,    0,   89,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
   -6,   70,  772,  -18,    6,  -31, -136,    0,    0,    0,
    0,  -61, -179,    0,   60,    0,    0,   23,   35,    0,
    0,    0,  220,  222,    0, 1231,  -54,   17,  186,    0,
  209,    0,    0,  110,  -44,    0,  148,    0,
};
#define YYTABLESIZE 1349
short yytable[] = {                                      37,
  129,   32,  154,   81,   59,   78,  103,   34,  112,   65,
  207,   77,  117,  202,   91,   44,   92,  185,  184,   57,
   45,   72,   33,   30,  141,   45,   85,   86,  111,    7,
    8,    9,   99,  118,   68,   45,  131,  134,   78,  221,
  213,  129,  129,  129,  129,  129,   95,  129,   87,  203,
   13,   96,   99,  109,   70,  111,  100,  152,   75,  116,
  129,   91,  129,   92,  104,  141,  141,  141,  141,  141,
   76,  141,   81,  155,  169,  170,  100,  171,  172,  143,
   60,   82,   61,   99,  141,  105,  141,   66,   67,   87,
  106,   87,   87,   87,   99,  168,   82,   91,  191,   92,
   91,  111,   92,  144,  119,  152,  120,  100,   87,  121,
   87,  137,  138,   81,  122,   81,   81,   81,  100,  124,
   84,  139,  159,  129,  186,  129,  179,  205,  146,  147,
  161,   99,   81,  162,   81,  167,  182,   82,  173,   82,
   82,   82,  174,  175,  153,  176,  183,  141,  188,  141,
  180,  189,    7,    8,    9,  100,   82,   78,   82,  153,
   86,   84,  190,   84,   84,   84,  198,    7,    8,    9,
  197,   87,  199,   87,  200,  201,  204,  208,  209,  214,
   84,  212,   84,  215,   83,  218,  219,  222,   18,   91,
    3,   92,    7,   12,   58,   81,    2,   81,    8,   13,
   17,   86,   56,   86,   86,   86,   94,    1,   93,   15,
   46,   59,   62,   63,   71,  187,   36,   47,   31,   82,
   86,   82,   86,   80,   55,   83,   56,   83,   83,   83,
  216,   27,   38,   39,   40,   41,   42,   38,   39,   40,
   41,   42,  217,   84,   83,   84,   83,   53,   39,   40,
   41,   54,   84,   43,    0,   23,  129,  129,   43,  181,
  163,   47,  129,  129,  129,  129,    0,  129,  129,  129,
    0,    0,  129,  129,  129,  129,  129,  129,    0,  129,
  141,  141,   37,   86,    0,   86,  141,  141,  141,  141,
    0,  141,  141,  141,    0,    0,  141,  141,  141,  141,
  141,  141,    0,  141,   87,   87,   28,   83,    0,   83,
   87,   87,   87,   87,    0,   87,   87,   87,    0,    0,
   87,   87,   87,   87,   87,   87,   37,   87,   81,   81,
   75,    0,    0,    0,   81,   81,   81,   81,    0,   81,
   81,   81,   47,    0,   81,   81,   81,   81,   81,   81,
   28,   81,   82,   82,   76,    0,   27,    0,   82,   82,
   82,   82,    0,   82,   82,   82,    0,    0,   82,   82,
   82,   82,   82,   82,   75,   82,   84,   84,    0,    0,
   23,    0,   84,   84,   84,   84,    0,   84,   84,   84,
   24,    0,   84,   84,   84,   84,   84,   84,   76,   84,
   83,    0,    0,    0,   45,    0,    0,   37,   87,   88,
   89,   90,    0,    0,    0,    0,   86,   86,    0,    0,
    0,   85,   86,   86,   86,   86,    0,   86,   86,   86,
    0,   28,   86,   86,   86,   86,   86,   86,    0,   86,
   83,   83,    0,    0,    0,    0,   83,   83,   83,   83,
    0,   83,   83,   83,    0,   75,   83,   83,   83,   83,
   83,   83,   85,   83,   85,   85,   85,    0,    0,    0,
    0,    0,    0,   47,   47,    0,    0,    0,    0,   76,
    0,   85,    0,   85,   47,   47,   47,   27,   27,   47,
   47,   45,   47,   47,   47,  109,   47,  164,   27,   27,
   27,   45,    0,   27,   27,    0,   27,   27,   27,  110,
   27,   23,   23,    0,    0,   24,    0,    0,    0,    0,
    0,    0,   23,   23,   23,    0,    0,   23,   23,    0,
   23,   23,   23,  112,   23,    0,    0,  129,   37,   37,
   45,    0,  130,    0,   85,    0,   85,    0,    0,   37,
   37,   37,    0,    0,   37,   37,  111,   37,   37,   37,
    0,   37,   28,   28,    0,    0,    0,    0,    0,  107,
    0,    0,    0,   28,   28,   28,    0,  109,   28,   28,
    0,   28,   28,   28,    0,   28,   75,   75,    0,    0,
  108,  110,    0,    0,    0,    0,    0,   75,   75,   75,
    0,    0,   75,   75,    0,   75,   75,   75,    0,   75,
   76,   76,    0,    0,    0,  112,   38,   39,   40,   41,
   42,   76,   76,   76,    0,    0,   76,   76,    0,   76,
   76,   76,    0,   76,  142,    0,  132,   43,  111,   45,
    0,  133,    0,    0,    0,    0,   24,   24,    0,    0,
    0,  107,    0,    0,    0,    0,    0,   24,   24,   24,
    0,    0,   24,   24,    0,   24,   24,   24,    0,   24,
   13,    0,  108,    0,    0,    0,    0,   85,   85,    0,
    0,    0,    0,   85,   85,   85,   85,    0,   85,   85,
   85,    0,    0,   85,   85,   85,   85,   85,   85,   13,
   85,    0,    0,   38,   39,   40,   41,   42,    0,    0,
    0,  109,    0,   38,   39,   40,   41,   42,    0,    0,
    0,  109,  109,  109,   43,  110,  109,  109,  109,  109,
  109,  109,    0,  109,   43,  110,  110,  110,    0,    0,
  110,  110,  110,  110,  110,  110,    0,  110,    0,  112,
    0,   58,   38,   39,   40,   41,   42,    0,    0,  112,
  112,  112,    0,    0,  112,  112,  112,  112,  112,  112,
    0,  112,  111,   43,    0,    0,    0,    0,   11,    0,
   12,    0,  111,  111,  111,  107,   63,  111,  111,  111,
  111,  111,  111,    0,  111,  107,  107,  107,    0,   98,
  107,  107,  107,  107,  107,  107,  108,  107,    0,    0,
    0,    0,    0,    0,    0,    0,  108,  108,  108,    0,
    0,  108,  108,  108,  108,  108,  108,    0,  108,    0,
   63,    0,    0,    0,    0,    0,   63,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  140,    2,   98,    0,
    0,   38,   39,   40,   41,   42,    0,    3,  141,    4,
    0,   95,    5,    6,    0,    7,    8,    9,    0,   10,
    0,    0,   43,    0,   93,    0,    0,    0,    0,    0,
   63,    0,    1,    2,    0,    0,    0,   98,    0,    0,
    0,    0,    0,    3,    0,    4,    0,    0,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    0,    0,    0,
    0,    1,    2,  206,    0,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    4,    0,    0,    5,    6,    0,
    7,    8,    9,    2,   10,    0,    0,  220,  193,    0,
    0,    0,    0,    3,   97,    4,  148,  149,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    0,    0,    0,
    0,  193,   62,    0,    0,    0,  211,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   64,    0,    0,  193,
    0,    0,    2,    0,    0,    0,    0,  211,    0,  178,
  193,    0,    3,   97,    4,   95,    0,    5,    6,  113,
    7,    8,    9,  107,   10,   95,   95,   95,   93,    0,
   95,   95,   95,   95,   95,   95,    0,   95,   93,   93,
   93,    2,    0,   93,   93,   93,   93,   93,   93,  108,
   93,    3,   97,    4,    0,    0,    5,    6,    0,    7,
    8,    9,    0,   10,    1,    2,    0,    0,    0,    0,
    0,    0,    0,  110,    0,    3,  192,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,    1,    2,
    0,    0,    0,    0,    0,    0,    0,  160,    0,    3,
  192,    4,    0,    0,    5,    6,    0,    7,    8,    9,
  126,   10,    0,    1,    2,    0,    0,    0,    0,    0,
    0,    0,    0,  122,    3,    0,    4,    1,    2,    5,
    6,    0,    7,    8,    9,    0,   10,  124,    3,    0,
    4,    2,    0,    5,    6,    0,    7,    8,    9,    0,
   10,    3,  177,    4,    1,    2,    5,    6,  120,    7,
    8,    9,    0,   10,    0,    3,    0,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,    0,    0,
    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    4,    0,    0,    5,    6,    0,    7,
    8,    9,    0,   10,    1,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,    1,    2,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    4,  126,    0,    5,    6,    0,    7,    8,    9,
    0,   10,  126,  126,  126,  122,    0,  126,  126,    0,
  126,  126,  126,    0,  126,  122,  122,  122,    0,  124,
  122,  122,    0,  122,  122,  122,    0,  122,    0,  124,
  124,  124,   73,   74,  124,  124,    0,  124,  124,  124,
  120,  124,    0,    0,    0,    0,    0,    0,    0,    0,
  120,  120,  120,    1,    2,  120,  120,    0,  120,  120,
  120,    0,  120,    0,    3,  192,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,    0,    0,    0,
    0,    0,  123,    0,    1,    2,    0,  125,  126,  127,
  128,    0,    0,  135,  136,    3,  210,    4,    0,    0,
    5,    6,    0,    7,    8,    9,    0,   10,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  165,  166,
};
short yycheck[] = {                                      40,
    0,   40,  125,   46,   11,   37,   51,   46,   70,   16,
  190,  257,   40,   44,   43,   40,   45,  125,  155,  257,
   45,   41,   61,   44,    0,   45,  259,  260,   59,  275,
  276,  277,   51,   61,  257,   45,   91,   92,   70,  219,
   44,   41,   42,   43,   44,   45,   42,   47,    0,  186,
   44,   47,   71,   60,   40,   59,   51,  102,  257,   41,
   60,   43,   62,   45,   41,   41,   42,   43,   44,   45,
   59,   47,    0,  105,  129,  130,   71,  132,  133,   98,
   11,   40,   13,  102,   60,  123,   62,   18,   19,   41,
  256,   43,   44,   45,  113,   41,    0,   43,   41,   45,
   43,   59,   45,   98,  257,  150,  257,  102,   60,   41,
   62,   95,   96,   41,  257,   43,   44,   45,  113,   41,
    0,   44,  256,  123,  156,  125,  145,  189,   44,   44,
  257,  150,   60,   41,   62,  123,  271,   41,   44,   43,
   44,   45,   44,   44,  267,   44,  257,  123,   44,  125,
  145,   40,  275,  276,  277,  150,   60,  189,   62,  267,
    0,   41,  123,   43,   44,   45,   44,  275,  276,  277,
  125,  123,   44,  125,   44,  271,   44,   44,  125,   41,
   60,  125,   62,  125,    0,   44,  123,  125,    0,   43,
    0,   45,    0,    0,   41,  123,    0,  125,    0,    0,
    0,   41,   41,   43,   44,   45,   60,    0,   62,    0,
   40,  125,  125,  125,   29,  156,  257,    0,  257,  123,
   60,  125,   62,  266,    5,   41,    5,   43,   44,   45,
  208,    0,  257,  258,  259,  260,  261,  257,  258,  259,
  260,  261,  208,  123,   60,  125,   62,  257,  258,  259,
  260,  261,   44,  278,   -1,    0,  256,  257,  278,  150,
  113,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,    0,  123,   -1,  125,  262,  263,  264,  265,
   -1,  267,  268,  269,   -1,   -1,  272,  273,  274,  275,
  276,  277,   -1,  279,  256,  257,    0,  123,   -1,  125,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  276,  277,   44,  279,  256,  257,
    0,   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,
  268,  269,  125,   -1,  272,  273,  274,  275,  276,  277,
   44,  279,  256,  257,    0,   -1,  125,   -1,  262,  263,
  264,  265,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   44,  279,  256,  257,   -1,   -1,
  125,   -1,  262,  263,  264,  265,   -1,  267,  268,  269,
    0,   -1,  272,  273,  274,  275,  276,  277,   44,  279,
   41,   -1,   -1,   -1,   45,   -1,   -1,  125,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
   -1,    0,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,  125,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
   -1,  267,  268,  269,   -1,  125,  272,  273,  274,  275,
  276,  277,   41,  279,   43,   44,   45,   -1,   -1,   -1,
   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,  125,
   -1,   60,   -1,   62,  267,  268,  269,  256,  257,  272,
  273,   45,  275,  276,  277,   41,  279,   41,  267,  268,
  269,   45,   -1,  272,  273,   -1,  275,  276,  277,   41,
  279,  256,  257,   -1,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   41,  279,   -1,   -1,   42,  256,  257,
   45,   -1,   47,   -1,  123,   -1,  125,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   41,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,   41,
   -1,   -1,   -1,  267,  268,  269,   -1,  123,  272,  273,
   -1,  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,
   41,  123,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,  123,  257,  258,  259,  260,
  261,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   44,   -1,   42,  278,  123,   45,
   -1,   47,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
   -1,  123,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
   44,   -1,  123,   -1,   -1,   -1,   -1,  256,  257,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,   44,
  279,   -1,   -1,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  257,   -1,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  267,  268,  269,  278,  257,  272,  273,  274,  275,
  276,  277,   -1,  279,  278,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  276,  277,   -1,  279,   -1,  257,
   -1,  125,  257,  258,  259,  260,  261,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,  274,  275,  276,  277,
   -1,  279,  257,  278,   -1,   -1,   -1,   -1,  123,   -1,
  125,   -1,  267,  268,  269,  257,   15,  272,  273,  274,
  275,  276,  277,   -1,  279,  267,  268,  269,   -1,  123,
  272,  273,  274,  275,  276,  277,  257,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,  274,  275,  276,  277,   -1,  279,   -1,
   59,   -1,   -1,   -1,   -1,   -1,   65,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,  123,   -1,
   -1,  257,  258,  259,  260,  261,   -1,  267,  268,  269,
   -1,  123,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,   -1,  278,   -1,  123,   -1,   -1,   -1,   -1,   -1,
  109,   -1,  256,  257,   -1,   -1,   -1,  123,   -1,   -1,
   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
   -1,  256,  257,  125,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  257,  279,   -1,   -1,  125,  167,   -1,
   -1,   -1,   -1,  267,  268,  269,  270,  271,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,   -1,
   -1,  190,  125,   -1,   -1,   -1,  195,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,  208,
   -1,   -1,  257,   -1,   -1,   -1,   -1,  216,   -1,  125,
  219,   -1,  267,  268,  269,  257,   -1,  272,  273,  274,
  275,  276,  277,  125,  279,  267,  268,  269,  257,   -1,
  272,  273,  274,  275,  276,  277,   -1,  279,  267,  268,
  269,  257,   -1,  272,  273,  274,  275,  276,  277,  125,
  279,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,   -1,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  256,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  125,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  125,  279,   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  125,  267,   -1,  269,  256,  257,  272,
  273,   -1,  275,  276,  277,   -1,  279,  125,  267,   -1,
  269,  257,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,  267,  268,  269,  256,  257,  272,  273,  125,  275,
  276,  277,   -1,  279,   -1,  267,   -1,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  256,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
   -1,  269,  257,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  267,  268,  269,  257,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  267,  268,  269,   -1,  257,
  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,  267,
  268,  269,   32,   33,  272,  273,   -1,  275,  276,  277,
  257,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,  256,  257,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   82,   -1,  256,  257,   -1,   87,   88,   89,
   90,   -1,   -1,   93,   94,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  117,  118,
};
#define YYFINAL 14
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
"programa : '{'",
"programa : '}'",
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
"programa :",
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
"ejecutable : PRINT IDENTIFICADOR",
"ejecutable : PRINT constanteConSigno",
"ejecutable : PRINT constanteSinSigno",
"ejecutable : ciclo_while",
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
"factor : CADENA_CARACTERES",
"constanteSinSigno : ENTERO_SIN_SIGNO",
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
#line 286 "./gramaticaComCHZGenerativa.y"
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
#line 752 "y.tab.c"
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
{  yyPrintInLine("Se detectó un programa");}
break;
case 2:
#line 65 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); }
break;
case 3:
#line 66 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido y falta la última llave"); }
break;
case 4:
#line 67 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido y falta la primer llave"); }
break;
case 5:
#line 68 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 6:
#line 69 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 7:
#line 70 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 8:
#line 71 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 9:
#line 72 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 10:
#line 73 "./gramaticaComCHZGenerativa.y"
{  yyPrintInLine("Se detectó un programa"); }
break;
case 11:
#line 74 "./gramaticaComCHZGenerativa.y"
{  yyPrintInLine("Se detectó un programa"); }
break;
case 12:
#line 75 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
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
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 16:
#line 79 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 17:
#line 80 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 18:
#line 81 "./gramaticaComCHZGenerativa.y"
{ yyerror("No hay programa"); }
break;
case 23:
#line 90 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una falta de coma"); }
break;
case 24:
#line 91 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una falta de coma"); }
break;
case 25:
#line 92 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia invalida");}
break;
case 28:
#line 99 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 30:
#line 101 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 31:
#line 102 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 32:
#line 105 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 33:
#line 106 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 34:
#line 107 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 35:
#line 110 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 36:
#line 113 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 37:
#line 114 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 38:
#line 115 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 39:
#line 117 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 41:
#line 119 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 43:
#line 124 "./gramaticaComCHZGenerativa.y"
{  yyPrintInLine("Se detectó declaración de metodo en clase");}
break;
case 44:
#line 125 "./gramaticaComCHZGenerativa.y"
{  yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 45:
#line 128 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 46:
#line 129 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de método"); }
break;
case 50:
#line 139 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 51:
#line 140 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 52:
#line 141 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 53:
#line 144 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 54:
#line 145 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 55:
#line 148 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 56:
#line 149 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de parámetro"); }
break;
case 57:
#line 150 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de tipo de parámetro"); }
break;
case 59:
#line 154 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 63:
#line 159 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 64:
#line 160 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 67:
#line 165 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó asignación"); }
break;
case 68:
#line 166 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó invocación"); }
break;
case 69:
#line 167 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un if-else"); }
break;
case 70:
#line 168 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó una impresión de una cadena"); }
break;
case 71:
#line 169 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó una impresión de identificador"); }
break;
case 72:
#line 170 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó una impresión de constante"); }
break;
case 73:
#line 171 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó una impresión de constante"); }
break;
case 74:
#line 172 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un while"); }
break;
case 75:
#line 175 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 91:
#line 200 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 92:
#line 203 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 93:
#line 204 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de ultimo paréntesis en condición"); }
break;
case 94:
#line 205 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de primer paréntesis en condición"); }
break;
case 95:
#line 206 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de parantesis en condición"); }
break;
case 96:
#line 207 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 98:
#line 211 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 102:
#line 219 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 103:
#line 221 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 104:
#line 222 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de DO en WHILE-DO"); }
break;
case 105:
#line 225 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 116:
#line 249 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 120:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 122:
#line 257 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 123:
#line 258 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 124:
#line 259 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 125:
#line 260 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 126:
#line 261 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 127:
#line 262 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 128:
#line 263 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 135:
#line 272 "./gramaticaComCHZGenerativa.y"
{ yyerror("No se puede operar con cadena de caracteres"); }
break;
case 141:
#line 282 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 1208 "y.tab.c"
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
