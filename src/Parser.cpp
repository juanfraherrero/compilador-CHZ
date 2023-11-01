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
    0,    0,    0,    0,    0,    0,    0,    1,    1,    2,
    2,    2,    2,    2,    3,    3,    3,    3,    9,    9,
    9,   10,    7,    7,    7,   13,   13,   13,   13,   14,
   14,   15,   15,    8,   16,   16,    5,    5,    5,    6,
    6,   11,   11,   11,   11,   12,   12,   18,   18,   18,
   18,   17,   17,    4,    4,    4,    4,    4,    4,    4,
   19,   20,   20,   24,   24,   24,   24,   24,   24,   24,
   25,   25,   25,   21,   21,   27,   28,   28,   28,   30,
   32,   31,   22,   34,   35,   36,   29,   29,   29,   29,
   29,   29,   33,   33,   33,   33,   33,   33,   37,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   26,   26,
   26,   26,   26,   38,   38,   39,   39,   39,   39,   39,
   23,   23,   23,   23,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    1,    2,    2,    2,    1,    2,
    2,    1,    1,    2,    2,    1,    1,    1,    7,    7,
    6,    2,    5,    2,    4,    4,    3,    3,    2,    7,
    6,    2,    1,    2,    3,    1,    1,    1,    1,    3,
    1,    2,    1,    1,    0,    1,    1,    3,    2,    3,
    3,    2,    1,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    3,    3,    3,    4,    4,    4,    4,    1,
    3,    3,    1,    3,    4,    3,    4,    3,    2,    1,
    1,    1,    4,    1,    3,    1,    3,    3,    3,    3,
    3,    3,    3,    5,    2,    2,    4,    2,    3,    2,
    2,    1,    3,    2,    2,    1,    1,    2,    1,    2,
    1,    1,    4,    1,    1,    1,    2,    1,    2,    1,
    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,   84,   37,   38,   39,    0,
    0,    0,    0,    9,    0,    0,    0,   16,   17,   18,
    0,   54,   55,   56,   58,   59,    0,   14,   36,    0,
    0,    0,    0,   22,    0,    0,    0,   57,    0,    0,
    0,    7,    8,   10,   11,   41,    0,    0,    0,    0,
    0,  114,  116,  118,  115,    0,   63,    0,    0,    0,
   73,  111,  112,    0,    0,    0,   44,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   74,    0,   80,    0,
    4,    0,    0,    0,    0,    0,  110,    0,  117,  119,
   62,    0,    0,    0,    0,    0,    0,   35,   42,    0,
   75,    0,    0,    0,    0,    0,    0,   76,   98,    0,
    0,  107,    0,    0,    0,   96,   95,   82,   79,    0,
    0,   81,    0,   25,    0,    0,    0,    0,    3,   40,
    0,   85,   86,   83,    0,    0,    0,    0,    0,    0,
    0,   71,   72,  124,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  108,    0,  105,  101,    0,   93,
    0,    0,    0,   78,   32,    0,   23,    0,    0,   29,
    0,    0,  113,    0,    0,    0,    0,  123,    0,    0,
   53,    0,    0,   47,   97,    0,  103,   99,   77,   28,
    0,   27,    0,   21,    0,  122,    0,   20,    0,   52,
   94,   26,    0,   19,    0,   51,   48,    0,   31,    0,
   30,
};
short yydgoto[] = {                                      12,
   13,  181,   15,   16,   17,   47,   18,   19,   20,   21,
   69,  182,  126,  127,  128,   33,  183,  184,   22,   23,
   24,   25,   26,   71,   60,   61,   37,   77,   72,   78,
  120,  121,   79,   27,   50,  134,  115,   62,   63,
};
short yysindex[] = {                                    523,
  -11,  -38,  -36,   -6, -255,    0,    0,    0,    0, -218,
  598,    0,  633,    0,   -3,    7, -205,    0,    0,    0,
   20,    0,    0,    0,    0,    0,   31,    0,    0,  -34,
  356, -193,   15,    0, -198,  379,  536,    0,  -48, -180,
  657,    0,    0,    0,    0,    0,   22, -198,  356, -192,
 -183,    0,    0,    0,    0,   46,    0, -241,   57,  -20,
    0,    0,    0,   -5,  -25, -168,    0, -166,   54,  536,
  634,   64,   63,  476,   68,   69,    0,  499,    0, -122,
    0, -141, -137,   81,   83,  536,    0,  356,    0,    0,
    0,  459,  481,  356,  356,  403,  468,    0,    0,    4,
    0,  356,  356,  356,  356,  356,  356,    0,    0,   79,
   85,    0,   87,   88,  681,    0,    0,    0,    0,  536,
 -135,    0, -123,    0, -205, -104,   93,   99,    0,    0,
   21,    0,    0,    0,   58,  356,  356,  -20,  356,  356,
  -20,    0,    0,    0,   65,  -46,   -5,  787,   -5,   -5,
   -5,   -5,   -5,   -5,    0,   18,    0,    0,  103,    0,
  104,  107, -110,    0,    0,  -28,    0, -205,  114,    0,
 -198,  560,    0,  -20,  -20,  -20,  -20,    0,  -90,  125,
    0,   50,  801,    0,    0,   51,    0,    0,    0,    0,
  -27,    0,  136,    0,   53,    0,  787,    0,  135,    0,
    0,    0,   59,    0,  801,    0,    0,  574,    0,   55,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
    0,    0,  184,    0,  375,  399,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  242,    0,  144,    0,    0,    0,  279,  186,
  188,    0,    0,    0,    0,    0,  303,  144,    0,    0,
    1,    0,    0,    0,    0,    0,    0,   25,    0,   49,
    0,    0,    0,  327,    0,    0,    0,  151,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  193,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  694,  715,    0,    0,    0,    0,    0,    0,
    0,    0,  155,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   73,    0,    0,
   97,    0,    0,    0,    0,  436,  351,    0,  158,  159,
  160,  162,  163,  164,    0,    0,    0,    0,    0,    0,
  732,  753,    0,    0,    0,    0,    0,    0,    0,    0,
  144,    0,    0,  121,  146,  170,  194,    0,    0,    0,
    0,    0,   71,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   84,    0,    0,    0,
    0,    0,    0,    0,   91,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  199,   24,   10,   82,  -22, -113,    0,    0,    0,    0,
  -43, -158,    0,   86,    0,    0,   34,   36,    0,    0,
    0,    0,    0,  945,  -83,  -65,    0,  147,  179,    0,
    0,  116,  -58,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1080
short yytable[] = {                                     179,
  109,   30,  124,   35,   84,   38,   57,   32,  138,  141,
   58,  166,   68,  195,   96,  190,  202,   89,   90,  122,
  167,   94,   31,   14,  120,   68,   95,  133,  142,  143,
   83,   83,   28,   36,   14,   97,   43,   92,   39,   93,
   44,  109,  109,  109,  109,  109,   75,  109,   70,  210,
   45,   46,  174,  175,  191,  176,  177,  125,   67,   48,
  109,  122,  109,   65,   43,  120,  120,  120,  120,  120,
   49,  120,   64,   66,   80,   81,    7,    8,    9,   75,
   83,   86,   87,  113,  120,   88,  120,   75,   98,   70,
   99,   70,   70,   70,  100,   75,   65,   91,  173,   92,
   92,   93,   93,  168,  108,  178,  109,   92,   70,   93,
   70,  116,  117,   64,  129,   64,   64,   64,   76,  130,
   67,  131,  155,  132,  161,  109,  148,  193,  156,   75,
  157,  158,   64,  165,   64,  164,  170,   65,  171,   65,
   65,   65,  185,  172,  123,   69,  186,  187,   68,  120,
  188,   76,    7,    8,    9,  114,   65,  192,   65,   76,
  189,   67,  123,   67,   67,   67,  196,   76,  197,   66,
    7,    8,    9,   70,  198,  201,  203,  204,  207,  211,
   67,  208,   67,    5,   45,    2,   69,    6,   69,   69,
   69,   43,    1,   68,   33,   46,  162,   64,   89,   90,
   92,   76,   91,   87,   88,   69,  200,   69,   49,   41,
   66,  169,   66,   66,   66,   50,  101,   60,   29,   87,
   34,   65,   51,   52,   53,   54,   55,   85,  200,   66,
  205,   66,  206,    0,   68,  163,   68,   68,   68,    0,
    0,   34,    0,   56,    0,   67,    0,    0,    0,    0,
    0,    0,    0,   68,    0,   68,  109,  109,    0,    0,
    0,   60,  109,  109,  109,  109,    0,  109,  109,  109,
   69,    0,  109,  109,    0,  109,  109,  109,   24,  109,
  120,  120,    0,    0,    0,   34,  120,  120,  120,  120,
    0,  120,  120,  120,   66,    0,  120,  120,    0,  120,
  120,  120,   15,  120,   70,   70,    0,    0,    0,    0,
   70,   70,   70,   70,    0,   70,   70,   70,   68,    0,
   70,   70,   24,   70,   70,   70,   61,   70,   64,   64,
    0,    0,    0,    0,   64,   64,   64,   64,    0,   64,
   64,   64,   60,    0,   64,   64,   15,   64,   64,   64,
  121,   64,   65,   65,    0,    0,    0,    0,   65,   65,
   65,   65,    0,   65,   65,   65,   34,    0,   65,   65,
   61,   65,   65,   65,   12,   65,   67,   67,    0,    0,
    0,    0,   67,   67,   67,   67,    0,   67,   67,   67,
    0,    0,   67,   67,  121,   67,   67,   67,   13,   67,
   58,   69,   69,   24,    0,    0,    0,   69,   69,   69,
   69,    0,   69,   69,   69,    0,    0,   69,   69,   70,
   69,   69,   69,   58,   69,   66,   66,   15,    0,    0,
    0,   66,   66,   66,   66,  109,   66,   66,   66,    0,
    0,   66,   66,  144,   66,   66,   66,   58,   66,   68,
   68,   61,    0,    0,    0,   68,   68,   68,   68,    0,
   68,   68,   68,    0,    0,   68,   68,    0,   68,   68,
   68,    0,   68,   60,   60,  121,    0,  109,  109,  109,
  109,    0,  109,    0,   60,   60,   60,    0,    0,   60,
   60,    0,   60,   60,   60,    0,   60,   34,   34,   12,
  136,    0,    0,   58,    0,  137,    0,    0,   34,   34,
   34,    0,   58,   34,   34,    0,   34,   34,   34,  112,
   34,    0,  139,   13,    0,   58,    0,  140,    0,    0,
    0,    0,    0,    0,   24,   24,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   24,   24,   24,    0,    0,
   24,   24,    0,   24,   24,   24,    0,   24,   15,   15,
  109,    0,    0,    0,    0,    0,    0,    0,    0,   15,
   15,   15,    0,    0,   15,   15,    0,   15,   15,   15,
    0,   15,   61,   61,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   61,   61,   61,    0,    0,   61,   61,
    0,   61,   61,   61,    0,   61,  121,  121,    0,    0,
    0,    0,   51,   52,   53,   54,   55,  121,  121,  121,
    0,   74,  121,  121,    0,  121,  121,  121,    0,  121,
   12,   12,    0,   56,    0,   51,   52,   53,   54,   55,
    0,   12,   12,   12,    0,   11,   12,   12,    0,   12,
   12,   12,    0,   12,   13,   13,   56,    0,   74,   51,
   52,   53,   54,   55,    0,   13,   13,   13,    0,    0,
   13,   13,    0,   13,   13,   13,   92,   13,   93,    0,
   56,    0,    0,    0,  194,    0,    0,    0,    0,    0,
    0,  109,  109,  107,    0,  106,    0,    0,  209,    0,
    0,    0,  109,  109,  109,    0,    0,  109,  109,    0,
  109,  109,  109,    0,  109,   51,   52,   53,   54,   55,
    0,    0,   40,    0,  146,   52,   53,   54,   55,    0,
    0,  110,    2,    0,    0,    0,   56,   51,   52,   53,
   54,   55,    3,  111,    4,   56,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    2,    0,   42,   56,    0,
    0,    0,    0,    0,    0,    3,   73,    4,  118,  119,
    5,    6,    0,    7,    8,    9,    0,   10,    1,    2,
    0,   82,    0,    0,    0,    0,    0,    0,    0,    3,
    0,    4,    2,    0,    5,    6,    0,    7,    8,    9,
    0,   10,    3,   73,    4,  160,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    1,    2,    0,  106,    0,
    0,    0,    0,    0,    0,    0,    3,  180,    4,    1,
    2,    5,    6,    0,    7,    8,    9,    0,   10,  102,
    3,  180,    4,    0,    0,    5,    6,    0,    7,    8,
    9,    0,   10,    1,    2,    0,  104,    0,    0,    0,
    0,    0,    0,    0,    3,    0,    4,    0,    0,    5,
    6,    0,    7,    8,    9,    0,   10,  100,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    1,    2,
    0,    0,    0,    0,    0,  102,  103,  104,  105,    3,
    0,    4,    0,    0,    5,    6,    0,    7,    8,    9,
    0,   10,    1,    2,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    3,    0,    4,    0,    0,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    2,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    3,  159,    4,
  106,    0,    5,    6,    0,    7,    8,    9,    0,   10,
  106,  106,  106,    0,    0,  106,  106,    0,  106,  106,
  106,  102,  106,    0,   59,   64,    0,    0,    0,    0,
    0,  102,  102,  102,    0,    0,  102,  102,  104,  102,
  102,  102,    0,  102,    0,    0,    0,    0,  104,  104,
  104,    0,    0,  104,  104,    0,  104,  104,  104,  100,
  104,    0,    0,    0,    0,    0,    0,    0,    0,  100,
  100,  100,    0,    0,  100,  100,    0,  100,  100,  100,
    0,  100,  135,    0,    0,    0,    0,    0,    0,    0,
  145,  147,    1,    2,    0,    0,  149,  150,  151,  152,
  153,  154,    0,    3,  180,    4,    1,    2,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    3,  199,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
};
short yycheck[] = {                                      46,
    0,   40,  125,   40,   48,  261,   41,   46,   92,   93,
   45,  125,   35,  172,   40,   44,   44,  259,  260,   78,
  125,   42,   61,    0,    0,   48,   47,   86,   94,   95,
   59,   59,   44,   40,   11,   61,   13,   43,  257,   45,
   44,   41,   42,   43,   44,   45,   37,   47,    0,  208,
   44,  257,  136,  137,  168,  139,  140,   80,  257,   40,
   60,  120,   62,  257,   41,   41,   42,   43,   44,   45,
   40,   47,    0,   59,  123,  256,  275,  276,  277,   70,
   59,  274,  266,   74,   60,   40,   62,   78,  257,   41,
  257,   43,   44,   45,   41,   86,    0,   41,   41,   43,
   43,   45,   45,  126,   41,   41,   44,   43,   60,   45,
   62,   44,   44,   41,  256,   43,   44,   45,   37,  257,
    0,   41,   44,   41,  115,  125,  123,  171,   44,  120,
   44,   44,   60,  257,   62,  271,   44,   41,   40,   43,
   44,   45,  125,  123,  267,    0,   44,   44,  171,  125,
   44,   70,  275,  276,  277,   74,   60,   44,   62,   78,
  271,   41,  267,   43,   44,   45,  257,   86,   44,    0,
  275,  276,  277,  125,  125,  125,   41,  125,   44,  125,
   60,  123,   62,    0,   41,    0,   41,    0,   43,   44,
   45,   41,    0,    0,   40,  125,  115,  125,   41,   41,
   41,  120,   41,   41,   41,   60,  183,   62,  125,   11,
   41,  126,   43,   44,   45,  125,   70,    0,  257,  266,
  257,  125,  257,  258,  259,  260,  261,   49,  205,   60,
  197,   62,  197,   -1,   41,  120,   43,   44,   45,   -1,
   -1,    0,   -1,  278,   -1,  125,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   60,   -1,   62,  256,  257,   -1,   -1,
   -1,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
  125,   -1,  272,  273,   -1,  275,  276,  277,    0,  279,
  256,  257,   -1,   -1,   -1,   44,  262,  263,  264,  265,
   -1,  267,  268,  269,  125,   -1,  272,  273,   -1,  275,
  276,  277,    0,  279,  256,  257,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,   -1,  267,  268,  269,  125,   -1,
  272,  273,   44,  275,  276,  277,    0,  279,  256,  257,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,
  268,  269,  125,   -1,  272,  273,   44,  275,  276,  277,
    0,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   -1,  267,  268,  269,  125,   -1,  272,  273,
   44,  275,  276,  277,    0,  279,  256,  257,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   44,  275,  276,  277,    0,  279,
   45,  256,  257,  125,   -1,   -1,   -1,  262,  263,  264,
  265,   -1,  267,  268,  269,   -1,   -1,  272,  273,   41,
  275,  276,  277,   45,  279,  256,  257,  125,   -1,   -1,
   -1,  262,  263,  264,  265,    0,  267,  268,  269,   -1,
   -1,  272,  273,   41,  275,  276,  277,   45,  279,  256,
  257,  125,   -1,   -1,   -1,  262,  263,  264,  265,   -1,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,  256,  257,  125,   -1,   42,   43,   44,
   45,   -1,   47,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,  256,  257,  125,
   42,   -1,   -1,   45,   -1,   47,   -1,   -1,  267,  268,
  269,   -1,   45,  272,  273,   -1,  275,  276,  277,   44,
  279,   -1,   42,  125,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  256,  257,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  267,  268,  269,
   -1,  123,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  278,   -1,  257,  258,  259,  260,  261,
   -1,  267,  268,  269,   -1,  123,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,  278,   -1,  123,  257,
  258,  259,  260,  261,   -1,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   43,  279,   45,   -1,
  278,   -1,   -1,   -1,  125,   -1,   -1,   -1,   -1,   -1,
   -1,  256,  257,   60,   -1,   62,   -1,   -1,  125,   -1,
   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  257,  258,  259,  260,  261,
   -1,   -1,  125,   -1,  257,  258,  259,  260,  261,   -1,
   -1,  256,  257,   -1,   -1,   -1,  278,  257,  258,  259,
  260,  261,  267,  268,  269,  278,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  257,   -1,  125,  278,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,  273,   -1,  275,  276,  277,   -1,  279,  256,  257,
   -1,  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
   -1,  269,  257,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  267,  268,  269,  125,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  256,  257,   -1,  125,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  256,
  257,  272,  273,   -1,  275,  276,  277,   -1,  279,  125,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,  256,  257,   -1,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,  125,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,
   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,  267,
   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  257,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,
  257,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,  257,  279,   -1,   30,   31,   -1,   -1,   -1,   -1,
   -1,  267,  268,  269,   -1,   -1,  272,  273,  257,  275,
  276,  277,   -1,  279,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,  257,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,   88,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   96,   97,  256,  257,   -1,   -1,  102,  103,  104,  105,
  106,  107,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
};
#define YYFINAL 12
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
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : declarativa ','",
"sentencia : ejecutable ','",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : error ','",
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
"seleccion : IF '(' ')' cuerpo_if",
"bloque_condicion : '(' condicion ')'",
"cuerpo_if : cuerpo_then else_if cuerpo_else END_IF",
"cuerpo_if : cuerpo_then cuerpo_else END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_then : bloque_ejecutables",
"cuerpo_else : bloque_ejecutables",
"else_if : ELSE",
"ciclo_while : inicio_while bloque_condicion_while DO cuerpo_while",
"inicio_while : WHILE",
"bloque_condicion_while : '(' condicion ')'",
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
#line 265 "./gramaticaComCHZGenerativa.y"
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
#line 674 "y.tab.c"
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
case 12:
#line 79 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 13:
#line 80 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 14:
#line 81 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 15:
#line 84 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 17:
#line 86 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 18:
#line 87 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope();}
break;
case 20:
#line 91 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 21:
#line 92 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 22:
#line 95 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "funcion"); if(diff == 0){yyerror("Redeclaración de función en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion");} tableSymbol->addScope(yyvsp[0]->ptr); }
break;
case 23:
#line 98 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 24:
#line 99 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 25:
#line 100 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 26:
#line 102 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 28:
#line 104 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 30:
#line 109 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); }
break;
case 31:
#line 110 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 32:
#line 113 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope(yyvsp[0]->ptr);}
break;
case 33:
#line 114 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de método"); }
break;
case 37:
#line 124 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 38:
#line 125 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 39:
#line 126 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 40:
#line 129 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 41:
#line 131 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 42:
#line 134 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, yyvsp[-1]->type, tableSymbol->getScope(), "parametro"); yyval->ptr = newIdentificador->lexema; yyval->type = yyvsp[-1]->type;}
break;
case 43:
#line 135 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de parámetro"); }
break;
case 44:
#line 136 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de tipo de parámetro"); }
break;
case 46:
#line 140 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 50:
#line 145 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 51:
#line 146 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 57:
#line 154 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 60:
#line 157 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 61:
#line 160 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 64:
#line 168 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 65:
#line 169 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 66:
#line 170 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 67:
#line 171 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 68:
#line 172 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 69:
#line 173 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 70:
#line 174 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 71:
#line 177 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 72:
#line 178 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 73:
#line 179 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 74:
#line 182 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}
break;
case 75:
#line 183 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 76:
#line 186 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 78:
#line 190 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 82:
#line 198 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 200 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = popTercet(); int number = addTercet("BI", t2->getArg1(), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 84:
#line 203 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 85:
#line 206 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 87:
#line 212 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 88:
#line 213 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 89:
#line 214 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 90:
#line 215 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 91:
#line 216 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 92:
#line 217 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 96:
#line 223 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 100:
#line 229 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 102:
#line 231 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 103:
#line 232 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 104:
#line 233 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 105:
#line 234 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 106:
#line 235 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 107:
#line 236 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 108:
#line 237 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 109:
#line 240 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 110:
#line 241 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 111:
#line 242 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 112:
#line 243 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 113:
#line 244 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 114:
#line 247 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 115:
#line 248 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 116:
#line 251 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 117:
#line 252 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 118:
#line 253 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 119:
#line 254 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 120:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 121:
#line 258 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 122:
#line 259 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 123:
#line 260 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 124:
#line 261 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1170 "y.tab.c"
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
