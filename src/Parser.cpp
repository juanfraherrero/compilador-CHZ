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
    5,    5,   20,   20,   21,   21,   21,   21,   24,   24,
   24,   24,   24,   24,   24,   25,   25,   25,   22,   27,
   27,   27,   27,   27,   28,   28,   28,   30,   32,   31,
   23,   23,   34,   35,   29,   29,   29,   29,   29,   29,
   33,   33,   33,   33,   33,   33,   36,   36,   36,   36,
   36,   36,   36,   36,   36,   36,   26,   26,   26,   26,
   26,   26,   37,   37,   38,   38,   38,   38,   38,
};
short yylen[] = {                                         2,
    3,    2,    1,    1,    4,    3,    1,    2,    2,    4,
    3,    1,    2,    2,    3,    3,    2,    0,    2,    1,
    2,    2,    1,    1,    2,    2,    1,    2,    1,    1,
    1,    7,    7,    6,    2,    5,    2,    4,    4,    3,
    3,    2,    7,    6,    2,    1,    2,    3,    1,    1,
    1,    1,    3,    1,    2,    1,    1,    0,    1,    1,
    3,    2,    3,    3,    2,    1,    1,    1,    1,    2,
    1,    1,    3,    5,    4,    3,    6,    5,    3,    3,
    4,    4,    4,    4,    1,    3,    3,    1,    3,    3,
    2,    2,    1,    2,    4,    3,    2,    1,    1,    1,
    4,    3,    1,    1,    3,    3,    3,    3,    3,    3,
    3,    5,    2,    2,    4,    2,    3,    2,    2,    1,
    3,    2,    2,    1,    1,    2,    1,    2,    1,    1,
    4,    3,    1,    1,    1,    2,    1,    2,    1,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,  103,   50,   51,   52,    0,
    0,    4,    0,    0,    0,    0,   20,    0,    0,    0,
   29,   30,   31,    0,   67,   68,   69,   71,    0,   25,
   49,    0,    0,    0,    0,   35,    0,    0,  133,  135,
  137,  134,    0,    0,    0,    0,    0,   88,    0,    0,
  129,  130,   70,    0,    0,    0,    0,   26,    9,   19,
   14,    0,   21,   22,   54,    0,    0,    0,   76,    0,
    0,    0,    0,   57,    0,    0,  128,    0,    0,   94,
    0,  136,  138,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   89,    0,   98,
   92,    0,    6,    0,   11,    0,   16,    0,    0,    0,
  104,  102,   75,    0,    0,   48,   55,    0,  132,    0,
   90,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   86,   87,  116,    0,    0,  125,    0,
    0,    0,  114,  113,  100,   97,    0,    0,   99,    0,
   38,    0,    0,    0,    0,    5,   10,   53,    0,  101,
   78,    0,    0,    0,  131,    0,    0,    0,    0,  126,
    0,  123,  119,    0,  111,    0,    0,    0,   96,   45,
    0,   36,    0,    0,   42,    0,    0,   77,    0,   66,
    0,    0,   60,  115,    0,  121,  117,   95,   41,    0,
   40,    0,   34,    0,    0,   33,    0,   65,  112,   39,
    0,   32,    0,   64,   61,    0,   44,    0,   43,
};
short yydgoto[] = {                                      14,
   15,   16,   17,   18,   19,   20,   66,   21,   22,   23,
   24,   76,  191,  153,  154,  155,   35,  192,  193,   25,
   26,   27,   28,   46,   47,   48,   49,   98,   50,   99,
  147,  148,  111,   29,  112,  142,   51,   52,
};
short yysindex[] = {                                    648,
  -27,  -38,  -40,  -24, -241,    0,    0,    0,    0, -228,
  684,    0,   -7,    0,  863,  887,    0,   -7,   -7, -210,
    0,    0,    0,   11,    0,    0,    0,    0,  -24,    0,
    0,  -19,  264, -203,   -1,    0, -245,  -42,    0,    0,
    0,    0,   22,  451, -183,  139,  -23,    0,  788,   24,
    0,    0,    0,  -52, -173,  915,  941,    0,    0,    0,
    0,  965,    0,    0,    0,   27, -245,  749,    0,  106,
   14,  -25, -166,    0, -161,   58,    0, -156,  264,    0,
   61,    0,    0,  264,  264,  264,  264,  496,  604,  264,
  264,  264,  264,   60,  708,   64,   66,    0,  732,    0,
    0, -122,    0, -143,    0,  990,    0, -142,   78,  788,
    0,    0,    0,  473,  264,    0,    0,   -3,    0,  130,
    0,   14,   14,   14,   14,  264,  264,  -23,  264,  264,
  -23,   14,   14,    0,    0,    0,   79,   84,    0,   86,
   90, 1003,    0,    0,    0,    0,  788, -149,    0, -126,
    0, -210, -107,   92,   99,    0,    0,    0,   20,    0,
    0,  135,   14, 1070,    0,  -23,  -23,  -23,  -23,    0,
   12,    0,    0,  100,    0,  102,  108, -115,    0,    0,
  -31,    0, -210,  119,    0, -245,  812,    0,  123,    0,
   52, 1084,    0,    0,   54,    0,    0,    0,    0,   -9,
    0,  145,    0,   62, 1070,    0,  144,    0,    0,    0,
   67,    0, 1084,    0,    0,  837,    0,   68,    0,
};
short yyrindex[] = {                                    189,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
  191,    0,  232,    0,  192,  194,    0,  446,  470,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  283,    0,  154,    1,    0,    0,
    0,    0,    0,    0,   25,    0,   49,    0,    0,  762,
    0,    0,    0,  307,  197,  200,  203,    0,    0,    0,
    0,  207,    0,    0,    0,  331,  154,    0,    0,    0,
  355,    0,    0,    0,  167,    0,    0,    0,    0,    0,
  775,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  209,    0,  210,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  491,  512,  525,  548,    0,    0,   73,    0,    0,
   97,  577,  601,    0,    0,    0,    0,    0,    0, 1016,
 1030,    0,    0,    0,    0,    0,    0,    0,    0,  171,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  387,    0,    0,  121,  161,  185,  422,    0,
    0,    0,    0,    0,    0, 1043, 1056,    0,    0,    0,
    0,    0,    0,    0,    0,  154,    0,    0,    0,    0,
    0,   88,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   89,    0,    0,    0,    0,    0,
    0,    0,   91,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
   -5,   87,  781,  -35,  -15,  -28, -145,    0,    0,    0,
    0,  -57, -160,    0,   59,    0,    0,   10,   26,    0,
    0,    0,    0, 1116,  -48,   -4,  196,    0,  183,    0,
    0,   96,  -44,    0,  138,    0,    0,    0,
};
#define YYTABLESIZE 1363
short yytable[] = {                                      37,
  127,   32,  151,   78,  100,   56,  181,   34,   75,  109,
   62,   74,  199,   96,  114,   44,   30,  182,   92,   53,
   45,   69,   33,   93,  139,   45,  204,  108,   54,    7,
    8,    9,   96,   97,  210,  115,   13,  200,   75,  128,
  131,  127,  127,  127,  127,  127,   65,  127,   85,  108,
   67,  106,   97,   72,  149,  218,   88,   73,   89,  140,
  127,   79,  127,   96,  101,  139,  139,  139,  139,  139,
  102,  139,   79,  152,   96,   82,   83,  166,  167,  141,
  168,  169,  103,   97,  139,  108,  139,  134,  135,   85,
  116,   85,   85,   85,   97,  117,   80,   57,  118,   58,
  119,  121,  149,  136,   63,   64,  176,  143,   85,  144,
   85,   96,  156,   79,  158,   79,   79,   79,  159,  164,
   82,  179,  170,  127,  183,  127,  177,  171,  202,  172,
  180,   97,   79,  173,   79,  185,  194,   80,  186,   80,
   80,   80,  187,  195,  150,  196,  113,  139,   88,  139,
   89,  197,    7,    8,    9,  198,   80,   75,   80,  150,
   84,   82,  201,   82,   82,   82,  205,    7,    8,    9,
  165,   85,   88,   85,   89,  188,  206,   88,  209,   89,
   82,   88,   82,   89,   81,  211,  212,  215,   18,  216,
    3,    7,  219,   12,   58,   79,    2,   79,   91,    8,
   90,   84,   13,   84,   84,   84,   17,   56,    1,   15,
   46,  184,   59,   62,  213,   63,   36,   72,   31,   80,
   84,   80,   84,   77,   68,   81,   81,   81,   81,   81,
  214,   27,   38,   39,   40,   41,   42,   38,   39,   40,
   41,   42,  178,   82,   81,   82,   81,  160,    0,    0,
    0,    0,    0,   43,    0,    0,  127,  127,   43,    0,
    0,   72,  127,  127,  127,  127,    0,  127,  127,  127,
    0,    0,  127,  127,  127,  127,  127,  127,    0,  127,
  139,  139,   47,   84,    0,   84,  139,  139,  139,  139,
    0,  139,  139,  139,    0,    0,  139,  139,  139,  139,
  139,  139,    0,  139,   85,   85,   37,   81,   45,   81,
   85,   85,   85,   85,    0,   85,   85,   85,    0,    0,
   85,   85,   85,   85,   85,   85,   47,   85,   79,   79,
   28,    0,    0,    0,   79,   79,   79,   79,    0,   79,
   79,   79,   72,    0,   79,   79,   79,   79,   79,   79,
   37,   79,   80,   80,   73,    0,   27,    0,   80,   80,
   80,   80,    0,   80,   80,   80,    0,    0,   80,   80,
   80,   80,   80,   80,   28,   80,   82,   82,    0,    0,
    0,    0,   82,   82,   82,   82,   74,   82,   82,   82,
    0,    0,   82,   82,   82,   82,   82,   82,   73,   82,
   84,   85,   86,   87,    0,    0,    0,   47,    0,    0,
    0,    0,    0,    0,    0,    0,   84,   84,    0,    0,
    0,   83,   84,   84,   84,   84,    0,   84,   84,   84,
   74,   37,   84,   84,   84,   84,   84,   84,    0,   84,
   81,   81,    0,    0,    0,   23,   81,   81,   81,   81,
    0,   81,   81,   81,    0,   28,   81,   81,   81,   81,
   81,   81,   83,   81,   83,   83,   83,    0,    0,   24,
    0,    0,    0,   72,   72,    0,    0,    0,    0,   73,
    0,   83,    0,   83,   72,   72,   72,   27,   27,   72,
   72,   80,   72,   72,   72,   45,   72,    0,   27,   27,
   27,    0,    0,   27,   27,    0,   27,   27,   27,    0,
   27,   74,    0,  161,    0,    0,    0,   45,    0,    0,
   38,   39,   40,   41,   42,    0,    0,    0,    0,    0,
    0,  107,    0,    0,    0,    0,    0,  126,   47,   47,
   45,   43,  127,    0,   83,    0,   83,    0,    0,   47,
   47,   47,  108,    0,   47,   47,    0,   47,   47,   47,
    0,   47,   37,   37,    0,  110,    0,    0,    0,    0,
   23,    0,    0,   37,   37,   37,    0,    0,   37,   37,
    0,   37,   37,   37,    0,   37,   28,   28,  109,    0,
    0,    0,    0,    0,   24,    0,    0,   28,   28,   28,
    0,    0,   28,   28,    0,   28,   28,   28,    0,   28,
   73,   73,    0,  107,    0,    0,    0,  105,    0,    0,
    0,   73,   73,   73,    0,    0,   73,   73,    0,   73,
   73,   73,    0,   73,  108,    0,    0,    0,    0,    0,
    0,  106,   74,   74,    0,  129,    0,  110,   45,    0,
  130,    0,    0,   74,   74,   74,    0,    0,   74,   74,
    0,   74,   74,   74,    0,   74,    0,    0,    0,    0,
  109,    0,    0,    0,    0,    0,    0,   83,   83,    0,
    0,    0,    0,   83,   83,   83,   83,    0,   83,   83,
   83,   13,    0,   83,   83,   83,   83,   83,   83,  105,
   83,   23,   23,    0,    0,    0,    0,   38,   39,   40,
   41,   42,   23,   23,   23,    0,    0,   23,   23,    0,
   23,   23,   23,  106,   23,   24,   24,   13,   43,   38,
   39,   40,   41,   42,    0,    0,   24,   24,   24,    0,
    0,   24,   24,    0,   24,   24,   24,  107,   24,    0,
   43,  139,   38,   39,   40,   41,   42,  107,  107,  107,
    0,    0,  107,  107,  107,  107,  107,  107,  108,  107,
   11,    0,   12,   43,    0,    0,    0,    0,  108,  108,
  108,  110,    0,  108,  108,  108,  108,  108,  108,    0,
  108,  110,  110,  110,    0,   60,  110,  110,  110,  110,
  110,  110,    0,  110,  109,    0,    0,    0,   55,    0,
    0,    0,    0,    0,  109,  109,  109,    0,    0,  109,
  109,  109,  109,  109,  109,    0,  109,    0,    0,    0,
    0,    0,    0,  105,    0,    0,   60,    0,    0,    0,
    0,    0,   60,  105,  105,  105,    0,    0,  105,  105,
  105,  105,  105,  105,   95,  105,    0,  106,    0,    0,
   38,   39,   40,   41,   42,    0,    0,  106,  106,  106,
    0,   95,  106,  106,  106,  106,  106,  106,    0,  106,
    0,   43,    0,    0,   93,    0,   60,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   91,    0,    0,
    0,    0,    0,    1,    2,    0,    0,    0,    0,    0,
   95,    0,    0,    0,    3,    0,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  203,    0,    0,    1,
    2,    0,    0,    0,  190,    0,    0,    0,    0,    0,
    3,    0,    4,    0,    0,    5,    6,    0,    7,    8,
    9,  217,   10,  137,    2,    0,    0,  190,    0,    0,
    0,    0,  208,    0,    3,  138,    4,    0,    0,    5,
    6,    0,    7,    8,    9,  190,   10,   59,    2,    0,
    0,    0,    0,  208,    0,    0,  190,    0,    3,   94,
    4,  145,  146,    5,    6,    2,    7,    8,    9,    0,
   10,   61,    0,    0,    0,    3,   94,    4,   93,    0,
    5,    6,  110,    7,    8,    9,    0,   10,   93,   93,
   93,   91,    0,   93,   93,   93,   93,   93,   93,  104,
   93,   91,   91,   91,    2,    0,   91,   91,   91,   91,
   91,   91,    0,   91,    3,   94,    4,    0,    0,    5,
    6,    0,    7,    8,    9,  105,   10,    1,    2,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    3,  189,
    4,    0,    0,    5,    6,    0,    7,    8,    9,  107,
   10,    0,    1,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    3,  189,    4,    0,    0,    5,    6,
    0,    7,    8,    9,  157,   10,    0,    0,    1,    2,
    0,    0,    0,    0,    0,    0,    0,  175,    0,    3,
    0,    4,    0,    0,    5,    6,    0,    7,    8,    9,
  124,   10,    1,    2,    0,    0,    0,   70,   71,    0,
    0,    0,    0,    3,  120,    4,    0,    0,    5,    6,
    0,    7,    8,    9,    0,   10,    0,  122,    0,    0,
    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,
  118,    3,    0,    4,    0,    0,    5,    6,    0,    7,
    8,    9,    0,   10,  120,    0,    1,    2,    0,  122,
  123,  124,  125,    0,    0,  132,  133,    3,    0,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
    1,    2,    0,    0,    0,    0,    0,    0,    0,  162,
  163,    3,    0,    4,    0,    0,    5,    6,    0,    7,
    8,    9,    0,   10,    0,    1,    2,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    0,    4,    2,
    0,    5,    6,    0,    7,    8,    9,    0,   10,    3,
  174,    4,  124,    0,    5,    6,    0,    7,    8,    9,
    0,   10,  124,  124,  124,    0,  120,  124,  124,    0,
  124,  124,  124,    0,  124,    0,  120,  120,  120,  122,
    0,  120,  120,    0,  120,  120,  120,    0,  120,  122,
  122,  122,  118,    0,  122,  122,    0,  122,  122,  122,
    0,  122,  118,  118,  118,    1,    2,  118,  118,    0,
  118,  118,  118,    0,  118,    0,    3,  189,    4,    1,
    2,    5,    6,    0,    7,    8,    9,    0,   10,    0,
    3,  207,    4,    0,    0,    5,    6,    0,    7,    8,
    9,    0,   10,
};
short yycheck[] = {                                      40,
    0,   40,  125,   46,   49,   11,  152,   46,   37,   67,
   16,  257,   44,   49,   40,   40,   44,  125,   42,  261,
   45,   41,   61,   47,    0,   45,  187,   59,  257,  275,
  276,  277,   68,   49,   44,   61,   44,  183,   67,   88,
   89,   41,   42,   43,   44,   45,  257,   47,    0,   59,
   40,   57,   68,  257,   99,  216,   43,   59,   45,   95,
   60,   40,   62,   99,   41,   41,   42,   43,   44,   45,
  123,   47,    0,  102,  110,  259,  260,  126,  127,   95,
  129,  130,  256,   99,   60,   59,   62,   92,   93,   41,
  257,   43,   44,   45,  110,  257,    0,   11,   41,   13,
  257,   41,  147,   44,   18,   19,  142,   44,   60,   44,
   62,  147,  256,   41,  257,   43,   44,   45,   41,  123,
    0,  271,   44,  123,  153,  125,  142,   44,  186,   44,
  257,  147,   60,   44,   62,   44,  125,   41,   40,   43,
   44,   45,  123,   44,  267,   44,   41,  123,   43,  125,
   45,   44,  275,  276,  277,  271,   60,  186,   62,  267,
    0,   41,   44,   43,   44,   45,   44,  275,  276,  277,
   41,  123,   43,  125,   45,   41,  125,   43,  125,   45,
   60,   43,   62,   45,    0,   41,  125,   44,    0,  123,
    0,    0,  125,    0,   41,  123,    0,  125,   60,    0,
   62,   41,    0,   43,   44,   45,    0,   41,    0,    0,
   40,  153,  125,  125,  205,  125,  257,    0,  257,  123,
   60,  125,   62,  266,   29,   41,   44,   43,   44,   45,
  205,    0,  257,  258,  259,  260,  261,  257,  258,  259,
  260,  261,  147,  123,   60,  125,   62,  110,   -1,   -1,
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
  123,   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,   44,   -1,  272,  273,  274,  275,  276,  277,  123,
  279,  256,  257,   -1,   -1,   -1,   -1,  257,  258,  259,
  260,  261,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  123,  279,  256,  257,   44,  278,  257,
  258,  259,  260,  261,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
  278,   44,  257,  258,  259,  260,  261,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,  257,  279,
  123,   -1,  125,  278,   -1,   -1,   -1,   -1,  267,  268,
  269,  257,   -1,  272,  273,  274,  275,  276,  277,   -1,
  279,  267,  268,  269,   -1,   15,  272,  273,  274,  275,
  276,  277,   -1,  279,  257,   -1,   -1,   -1,  125,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,
  273,  274,  275,  276,  277,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   -1,  257,   -1,   -1,   56,   -1,   -1,   -1,
   -1,   -1,   62,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,  123,  279,   -1,  257,   -1,   -1,
  257,  258,  259,  260,  261,   -1,   -1,  267,  268,  269,
   -1,  123,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,  278,   -1,   -1,  123,   -1,  106,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  123,   -1,   -1,
   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,
  123,   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,  256,
  257,   -1,   -1,   -1,  164,   -1,   -1,   -1,   -1,   -1,
  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,  125,  279,  256,  257,   -1,   -1,  187,   -1,   -1,
   -1,   -1,  192,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  205,  279,  125,  257,   -1,
   -1,   -1,   -1,  213,   -1,   -1,  216,   -1,  267,  268,
  269,  270,  271,  272,  273,  257,  275,  276,  277,   -1,
  279,  125,   -1,   -1,   -1,  267,  268,  269,  257,   -1,
  272,  273,  274,  275,  276,  277,   -1,  279,  267,  268,
  269,  257,   -1,  272,  273,  274,  275,  276,  277,  125,
  279,  267,  268,  269,  257,   -1,  272,  273,  274,  275,
  276,  277,   -1,  279,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,  125,  279,  256,  257,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,  125,
  279,   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  125,  279,   -1,   -1,  256,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  125,   -1,  267,
   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
  125,  279,  256,  257,   -1,   -1,   -1,   32,   33,   -1,
   -1,   -1,   -1,  267,  125,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  125,   -1,   -1,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  125,  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   79,   -1,  256,  257,   -1,   84,
   85,   86,   87,   -1,   -1,   90,   91,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  114,
  115,  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,  256,  257,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,  257,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  267,
  268,  269,  257,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  267,  268,  269,   -1,  257,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,  267,  268,  269,  257,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  267,
  268,  269,  257,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  267,  268,  269,  256,  257,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,  267,  268,  269,  256,
  257,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,
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
#line 749 "y.tab.c"
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
    yyerror("syntax error");
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
#line 146 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 55:
#line 149 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 56:
#line 150 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de parámetro"); }
break;
case 57:
#line 151 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de tipo de parámetro"); }
break;
case 59:
#line 155 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 63:
#line 160 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 64:
#line 161 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 67:
#line 166 "./gramaticaComCHZGenerativa.y"
{yyPrintInLine("Se detectó asignación");}
break;
case 68:
#line 167 "./gramaticaComCHZGenerativa.y"
{yyPrintInLine("Se detectó invocación");}
break;
case 69:
#line 168 "./gramaticaComCHZGenerativa.y"
{yyPrintInLine("Se detectó un if-else");}
break;
case 70:
#line 169 "./gramaticaComCHZGenerativa.y"
{ {yyPrintInLine("Se detectó una impresión");} }
break;
case 71:
#line 170 "./gramaticaComCHZGenerativa.y"
{yyPrintInLine("Se detectó un while");}
break;
case 72:
#line 171 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 73:
#line 174 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 89:
#line 199 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 90:
#line 202 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 91:
#line 203 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de ultimo paréntesis en condición"); }
break;
case 92:
#line 204 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de primer paréntesis en condición"); }
break;
case 93:
#line 205 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de parantesis en condición"); }
break;
case 94:
#line 206 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 96:
#line 210 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 100:
#line 218 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 101:
#line 220 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 102:
#line 221 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de DO en WHILE-DO"); }
break;
case 103:
#line 224 "./gramaticaComCHZGenerativa.y"
{  }
break;
case 114:
#line 248 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 118:
#line 254 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 120:
#line 256 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 121:
#line 257 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 122:
#line 258 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 123:
#line 259 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 124:
#line 260 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 125:
#line 261 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 126:
#line 262 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 139:
#line 281 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 1193 "y.tab.c"
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
