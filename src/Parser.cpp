#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "./gramaticaComCHZExtendida.y"

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"

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
#line 38 "y.tab.c"
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
    0,    0,    0,    0,    1,    1,    2,    2,    2,    2,
    2,    3,    3,    3,    3,    9,    9,    9,    7,    7,
    7,   12,   12,   12,   12,   13,   13,    8,   14,   14,
    5,    5,    5,    6,    6,   10,   10,   11,   11,   16,
   16,   16,   16,   15,   15,    4,    4,    4,    4,    4,
    4,    4,   17,   18,   18,   22,   22,   22,   22,   22,
   22,   22,   23,   23,   23,   19,   19,   19,   19,   20,
   25,   25,   25,   25,   25,   25,   26,   26,   26,   27,
   27,   27,   27,   27,   27,   27,   27,   27,   27,   24,
   24,   24,   24,   24,   28,   28,   29,   29,   29,   29,
   29,   21,   21,   21,   21,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    2,    2,    1,    1,
    2,    2,    1,    1,    1,    8,    7,    7,    5,    2,
    4,    4,    3,    3,    2,    8,    7,    2,    3,    1,
    1,    1,    1,    3,    1,    2,    0,    1,    1,    3,
    2,    3,    3,    2,    1,    1,    1,    1,    2,    1,
    1,    1,    3,    4,    3,    3,    3,    4,    4,    4,
    4,    1,    3,    3,    1,    8,    7,    6,    5,    6,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    3,
    2,    2,    1,    3,    2,    2,    1,    1,    2,    1,
    2,    1,    1,    4,    1,    1,    1,    2,    1,    2,
    1,    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   31,   32,
   33,    0,    0,    0,    6,    0,    0,    0,   13,   14,
   15,   46,   47,   48,   50,   51,   11,   30,    0,    0,
    0,    0,    0,    0,    0,   49,    0,    0,    4,    0,
    5,    7,    8,   35,    0,    0,   95,   97,   99,   96,
    0,   55,    0,    0,    0,   65,   92,   93,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    3,
    0,   91,    0,   98,  100,   54,    0,    0,    0,    0,
    0,    0,   29,    0,   36,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   21,
    0,    0,    0,   34,    0,    0,    0,    0,    0,    0,
    0,   63,   64,  105,    0,    0,    0,    0,    0,    0,
   88,    0,    0,    0,   79,   78,   69,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   19,    0,    0,
   25,   94,    0,    0,    0,    0,  104,    0,    0,    0,
   45,    0,    0,   39,   89,   86,   82,   77,    0,    0,
    0,   68,    0,   70,    0,   24,    0,   23,  103,   18,
    0,    0,   17,    0,   44,   84,   80,    0,   67,    0,
   22,   16,    0,   43,   40,   66,    0,    0,   27,    0,
   26,
};
short yydgoto[] = {                                       2,
   14,  151,   16,   17,   18,   45,   19,   20,   21,   64,
  152,  102,  103,   32,  153,  154,   22,   23,   24,   25,
   26,   66,   55,   56,   67,   90,  124,   57,   58,
};
short yysindex[] = {                                   -111,
  535,    0,  -29,  -32,   -8,   -3, -220,   15,    0,    0,
    0, -210, -191,  549,    0,   27,   29, -172,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  192,  228,
 -169,   33,   54, -171,  216,    0,  228,  -28,    0, -159,
    0,    0,    0,    0,   42, -164,    0,    0,    0,    0,
   67,    0, -182,   -1,  -11,    0,    0,    0,   25,  -27,
 -148, -171, -146,   71, -114,  519,   73,   75,  -92,    0,
 -139,    0,  228,    0,    0,    0,  317,  412,  228,  228,
  240,  280,    0,   78,    0,   -2,  419,   81,   82, -144,
  228,  228,  228,  228,  228,  228, -114, -145, -129,    0,
 -172,  -76,   86,    0,   18,  228,  228,  -11,  228,  228,
  -11,    0,    0,    0,   21,  -36,   25,    8,  634,   89,
    0,   90,   91,  189,    0,    0,    0,   25,   25,   25,
   25,   25,   25,  432, -114,   96,  -24,    0, -172,   93,
    0,    0,  -11,  -11,  -11,  -11,    0, -119,  457,  100,
    0,   35,  660,    0,    0,    0,    0,    0,  102,  108,
 -114,    0, -117,    0, -171,    0,  -21,    0,    0,    0,
   43,  634,    0,  123,    0,    0,    0, -101,    0,  133,
    0,    0,  660,    0,    0,    0,   53,  471,    0,   56,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,  253,    0,    0,    0,
    0,    0,  178,    0,    0,  485,  521,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  277,    0,  138,    0,    0,    0,  330,    0,  182,
    0,    0,    0,    0,  344,  -41,    0,    0,    0,    0,
    0,    0,  -17,    0,    7,    0,    0,    0,  368,    0,
    0,  138,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
   55,    0,    0,    0,    0,  166,  382,    0,    0,    0,
    0,  443,  560,    0,    0,    0,    0,  145,  148,  151,
  153,  157,  161,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   79,  104,  128,  152,    0,    0,    0,    0,
    0,    0,   80,    0,    0,    0,    0,    0,  581,  592,
    0,    0,    0,    0,  138,    0,    0,    0,    0,    0,
    0,   92,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   94,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
    0,    4,   16,  754,  -23,  -79,    0,    0,    0,  -55,
 -132,    0,  101,    0,   34,   46,    0,    0,    0,    0,
    0,  801,  -20,    3,  170,  -81,    0,    0,    0,
};
#define YYTABLESIZE 939
short yytable[] = {                                      90,
   90,   90,   90,   90,   15,   90,   84,   29,   87,  148,
   63,    1,   81,   31,   27,  134,  171,   41,   90,  166,
   90,  137,  181,  101,  101,  101,  101,  101,   30,  101,
   79,   34,  100,   82,   71,   80,   35,   71,   63,   76,
   36,   77,  101,   78,  101,  101,   38,   62,  138,   62,
   62,   62,  163,  164,   37,  190,  108,  111,  142,  167,
   77,  147,   78,   77,   39,   78,   62,   77,   62,   78,
   42,   56,   43,   56,   56,   56,   74,   75,  139,  178,
   88,  112,  113,   90,   44,  143,  144,   60,  145,  146,
   56,   61,   56,   62,   69,   57,   70,   57,   57,   57,
   71,   72,  122,    9,   10,   11,   73,  101,   83,  180,
   85,   86,   88,   97,   57,   98,   57,  104,  118,   59,
  119,   59,   59,   59,  125,  126,  127,  136,  135,  141,
  149,   62,  155,  156,  157,  165,  168,  169,   59,  159,
   59,   63,    4,  172,   61,  176,   61,   61,   61,   88,
   88,  177,    5,  179,    6,   56,  175,    7,    8,  173,
    9,   10,   11,   61,   12,   61,  185,  182,   58,  186,
   58,   58,   58,  187,   99,  188,   88,    2,   37,   57,
  191,    1,    9,   10,   11,   73,  175,   58,   74,   58,
   99,   76,   60,   75,   60,   60,   60,   71,    9,   10,
   11,   72,  140,   59,   38,  183,   68,   90,   90,   90,
   90,   60,   90,   60,   90,   90,   41,  184,   42,    0,
   90,   90,   90,   90,   28,   90,   90,   90,   61,   72,
   90,   90,   52,   90,   90,   90,   53,   90,  101,  101,
    0,    0,    0,    0,  101,  101,  101,  101,   33,  101,
  101,  101,   58,    0,  101,  101,   65,  101,  101,  101,
   53,  101,   62,   62,    0,    0,    0,    0,   62,   62,
   62,   62,   53,   62,   62,   62,   60,    0,   62,   62,
  114,   62,   62,   62,   53,   62,   56,   56,    0,    0,
   90,    0,   56,   56,   56,   56,   52,   56,   56,   56,
    0,    0,   56,   56,    0,   56,   56,   56,    0,   56,
   57,   57,    0,  158,    0,    0,   57,   57,   57,   57,
   28,   57,   57,   57,   53,    0,   57,   57,    0,   57,
   57,   57,    0,   57,   59,   59,    0,    0,    0,    0,
   59,   59,   59,   59,    0,   59,   59,   59,    0,    0,
   59,   59,    0,   59,   59,   59,    0,   59,  106,   61,
   61,   53,    0,  107,    0,   61,   61,   61,   61,    0,
   61,   61,   61,   20,    0,   61,   61,   52,   61,   61,
   61,    0,   61,   58,   58,    0,    0,   12,    0,   58,
   58,   58,   58,    0,   58,   58,   58,    0,    0,   58,
   58,   28,   58,   58,   58,    0,   58,   60,   60,    0,
    0,   53,    0,   60,   60,   60,   60,    0,   60,   60,
   60,   90,   90,   60,   60,  102,   60,   60,   60,    0,
   60,    0,   90,   90,   90,    0,    0,   90,   90,    0,
   90,   90,   90,    0,   90,    4,    0,    0,   46,   47,
   48,   49,   50,  109,   20,    5,   53,    6,  110,    0,
    7,    8,  121,    9,   10,   11,    0,   12,   12,   51,
    0,    0,   46,   47,   48,   49,   50,    0,    0,    0,
    0,    0,    0,    0,   46,   47,   48,   49,   50,    0,
    0,    0,   53,   51,    0,    0,   46,   47,   48,   49,
   50,    0,    0,    0,    0,   51,  102,    0,   52,   52,
    0,    0,    0,    0,    0,    0,    0,   51,    0,   52,
   52,   52,    0,    0,   52,   52,    0,   52,   52,   52,
    0,   52,   28,   28,    0,    0,  116,   47,   48,   49,
   50,    0,    0,   28,   28,   28,    0,    0,   28,   28,
    0,   28,   28,   28,   87,   28,    0,   51,    0,    0,
    0,   77,    0,   78,    0,    0,    0,   87,    0,    0,
    0,    0,    0,   46,   47,   48,   49,   50,   96,    0,
   95,  170,    0,    0,    0,   20,   20,    0,    0,    0,
    0,    0,    0,    0,   51,  189,   20,   20,   20,   12,
   12,   20,   20,    0,   20,   20,   20,    0,   20,    9,
   12,   12,   12,    0,    0,   12,   12,    0,   12,   12,
   12,    0,   12,   53,   53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   53,   53,   53,  102,  102,   53,
   53,    0,   53,   53,   53,   10,   53,    0,  102,  102,
  102,    0,    0,  102,  102,    0,  102,  102,  102,   13,
  102,    0,    0,    0,    0,    0,    0,    0,   46,   47,
   48,   49,   50,   40,  120,    4,    0,    0,    0,    0,
    0,    0,    0,    0,   83,    5,    0,    6,    4,   51,
    7,    8,    0,    9,   10,   11,    0,   12,    5,   87,
    6,  161,  162,    7,    8,   85,    9,   10,   11,   87,
   12,   87,    3,    4,   87,   87,   81,   87,   87,   87,
    0,   87,    0,    5,  150,    6,    3,    4,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    5,  150,    6,
    9,    9,    7,    8,    0,    9,   10,   11,    0,   12,
    0,    9,    9,    9,    0,    0,    9,    9,    0,    9,
    9,    9,    0,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   10,    0,    0,
   91,   92,   93,   94,    0,    0,    0,   10,   10,   10,
    3,    4,   10,   10,    0,   10,   10,   10,    0,   10,
    0,    5,    0,    6,    3,    4,    7,    8,    0,    9,
   10,   11,    0,   12,    0,    5,   83,    6,   89,    0,
    7,    8,    0,    9,   10,   11,   83,   12,   83,   54,
   59,   83,   83,    0,   83,   83,   83,   85,   83,    0,
  123,    0,    0,    0,    0,    0,    0,   85,   81,   85,
   89,    0,   85,   85,    0,   85,   85,   85,   81,   85,
   81,    0,    0,   81,   81,    0,   81,   81,   81,    0,
   81,    0,    0,  105,    0,    0,    0,  160,    0,    0,
    0,  115,  117,    0,    0,    0,    0,   89,   89,    3,
    4,  128,  129,  130,  131,  132,  133,    0,    0,    0,
    5,  150,    6,    0,    0,    7,    8,    0,    9,   10,
   11,    0,   12,    0,   89,    3,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,  174,    6,    0,
    0,    7,    8,    0,    9,   10,   11,    0,   12,
};
short yycheck[] = {                                      41,
   42,   43,   44,   45,    1,   47,   62,   40,  123,   46,
   34,  123,   40,   46,   44,   97,  149,   14,   60,   44,
   62,  101,   44,   41,   42,   43,   44,   45,   61,   47,
   42,   40,  125,   61,   59,   47,   40,   59,   62,   41,
  261,   43,   60,   45,   62,   69,  257,   41,  125,   43,
   44,   45,  134,  135,   40,  188,   77,   78,   41,  139,
   43,   41,   45,   43,  256,   45,   60,   43,   62,   45,
   44,   41,   44,   43,   44,   45,  259,  260,  102,  161,
   65,   79,   80,  125,  257,  106,  107,  257,  109,  110,
   60,   59,   62,   40,  123,   41,  256,   43,   44,   45,
   59,  266,   87,  275,  276,  277,   40,  125,  257,  165,
  257,   41,   97,   41,   60,   41,   62,  257,   41,   41,
  123,   43,   44,   45,   44,   44,  271,  257,  274,   44,
  123,  125,   44,   44,   44,   40,   44,  257,   60,  124,
   62,  165,  257,   44,   41,   44,   43,   44,   45,  134,
  135,   44,  267,  271,  269,  125,  153,  272,  273,  125,
  275,  276,  277,   60,  279,   62,   44,  125,   41,  271,
   43,   44,   45,   41,  267,  123,  161,    0,   41,  125,
  125,    0,  275,  276,  277,   41,  183,   60,   41,   62,
  267,   41,   41,   41,   43,   44,   45,   41,  275,  276,
  277,   41,  102,  125,  125,  172,   37,   42,   43,   44,
   45,   60,   47,   62,  256,  257,  125,  172,  125,   -1,
  262,  263,  264,  265,  257,  267,  268,  269,  125,  266,
  272,  273,   41,  275,  276,  277,   45,  279,  256,  257,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  257,  267,
  268,  269,  125,   -1,  272,  273,   41,  275,  276,  277,
   45,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   45,  267,  268,  269,  125,   -1,  272,  273,
   41,  275,  276,  277,   45,  279,  256,  257,   -1,   -1,
  125,   -1,  262,  263,  264,  265,   44,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  125,   -1,   -1,  262,  263,  264,  265,
   44,  267,  268,  269,   45,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,   42,  256,
  257,   45,   -1,   47,   -1,  262,  263,  264,  265,   -1,
  267,  268,  269,   44,   -1,  272,  273,  125,  275,  276,
  277,   -1,  279,  256,  257,   -1,   -1,   44,   -1,  262,
  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,  272,
  273,  125,  275,  276,  277,   -1,  279,  256,  257,   -1,
   -1,   44,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,  256,  257,  272,  273,   44,  275,  276,  277,   -1,
  279,   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  257,   -1,   -1,  257,  258,
  259,  260,  261,   42,  125,  267,   45,  269,   47,   -1,
  272,  273,   44,  275,  276,  277,   -1,  279,  125,  278,
   -1,   -1,  257,  258,  259,  260,  261,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
   -1,   -1,  125,  278,   -1,   -1,  257,  258,  259,  260,
  261,   -1,   -1,   -1,   -1,  278,  125,   -1,  256,  257,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  278,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,  257,  258,  259,  260,
  261,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,  123,  279,   -1,  278,   -1,   -1,
   -1,   43,   -1,   45,   -1,   -1,   -1,  125,   -1,   -1,
   -1,   -1,   -1,  257,  258,  259,  260,  261,   60,   -1,
   62,  125,   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  278,  125,  267,  268,  269,  256,
  257,  272,  273,   -1,  275,  276,  277,   -1,  279,  125,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  267,  268,  269,  256,  257,  272,
  273,   -1,  275,  276,  277,  125,  279,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,  125,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  257,  258,
  259,  260,  261,  125,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  125,  267,   -1,  269,  257,  278,
  272,  273,   -1,  275,  276,  277,   -1,  279,  267,  257,
  269,  270,  271,  272,  273,  125,  275,  276,  277,  267,
  279,  269,  256,  257,  272,  273,  125,  275,  276,  277,
   -1,  279,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,  268,  269,
  256,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
  262,  263,  264,  265,   -1,   -1,   -1,  267,  268,  269,
  256,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,   -1,  269,  256,  257,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,  267,  257,  269,   65,   -1,
  272,  273,   -1,  275,  276,  277,  267,  279,  269,   29,
   30,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
   87,   -1,   -1,   -1,   -1,   -1,   -1,  267,  257,  269,
   97,   -1,  272,  273,   -1,  275,  276,  277,  267,  279,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,   -1,   -1,   73,   -1,   -1,   -1,  124,   -1,   -1,
   -1,   81,   82,   -1,   -1,   -1,   -1,  134,  135,  256,
  257,   91,   92,   93,   94,   95,   96,   -1,   -1,   -1,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,  161,  256,  257,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
};
#define YYFINAL 2
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
"declaracion_funcion : VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : VOID IDENTIFICADOR '(' parametro ')' '{' '}'",
"declaracion_clase : CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'",
"declaracion_clase : CLASS IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' '}'",
"lista_atributos_y_metodos : lista_atributos_y_metodos tipo lista_de_variables ','",
"lista_atributos_y_metodos : lista_atributos_y_metodos metodo ','",
"lista_atributos_y_metodos : tipo lista_de_variables ','",
"lista_atributos_y_metodos : metodo ','",
"metodo : VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"metodo : VOID IDENTIFICADOR '(' parametro ')' '{' '}'",
"declaracion_objeto : IDENTIFICADOR lista_de_objetos",
"lista_de_objetos : lista_de_objetos ';' IDENTIFICADOR",
"lista_de_objetos : IDENTIFICADOR",
"tipo : SHORT",
"tipo : UINT",
"tipo : FLOAT",
"lista_de_variables : lista_de_variables ';' IDENTIFICADOR",
"lista_de_variables : IDENTIFICADOR",
"parametro : tipo IDENTIFICADOR",
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
"seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables END_IF",
"seleccion : IF '(' condicion ')' bloque_ejecutables bloque_ejecutables END_IF",
"seleccion : IF '(' condicion ')' bloque_ejecutables END_IF",
"seleccion : IF '(' ')' bloque_ejecutables END_IF",
"ciclo_while : WHILE '(' condicion ')' DO bloque_ejecutables",
"condicion : expresion_aritmetica '>' expresion_aritmetica",
"condicion : expresion_aritmetica '<' expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica",
"bloque_ejecutables : '{' sentencias_ejecutables '}'",
"bloque_ejecutables : ejecutable ','",
"bloque_ejecutables : declarativa ','",
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
typedef string YYSTYPE;
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
#line 218 "./gramaticaComCHZExtendida.y"
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
void checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value, "short");
}
#line 537 "y.tab.c"
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
#line 59 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un programa");}
break;
case 2:
#line 60 "./gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido");}
break;
case 3:
#line 61 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 4:
#line 62 "./gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 9:
#line 69 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 10:
#line 70 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 11:
#line 71 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 12:
#line 74 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 14:
#line 76 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 15:
#line 77 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 17:
#line 81 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 18:
#line 82 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 19:
#line 85 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 20:
#line 86 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 21:
#line 87 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 22:
#line 89 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 24:
#line 91 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 26:
#line 96 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de método de clase");}
break;
case 27:
#line 97 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 38:
#line 118 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 42:
#line 123 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 43:
#line 124 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 47:
#line 130 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó invación a función");}
break;
case 49:
#line 132 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó una impresión");}
break;
case 52:
#line 135 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 53:
#line 138 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó asignación");}
break;
case 58:
#line 148 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 59:
#line 149 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 60:
#line 150 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 61:
#line 151 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 66:
#line 160 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF-ELSE");}
break;
case 67:
#line 161 "./gramaticaComCHZExtendida.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 68:
#line 162 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF");}
break;
case 69:
#line 163 "./gramaticaComCHZExtendida.y"
{yyerror("Falta de condición en el bloque de control IF");}
break;
case 70:
#line 166 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un WHILE-DO");}
break;
case 79:
#line 179 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 81:
#line 183 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 83:
#line 185 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 84:
#line 186 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 85:
#line 187 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 86:
#line 188 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 87:
#line 189 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 88:
#line 190 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 89:
#line 191 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 97:
#line 204 "./gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 98:
#line 205 "./gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 101:
#line 208 "./gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 102:
#line 211 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 103:
#line 212 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 104:
#line 213 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 105:
#line 214 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 881 "y.tab.c"
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
