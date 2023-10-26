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
    0,    0,    0,    0,    1,    1,    2,    2,    2,    2,
    2,    3,    3,    3,    3,    9,    9,    9,    7,    7,
    7,   12,   12,   12,   12,   13,   13,    8,   14,   14,
    5,    5,    5,    6,    6,   10,   10,   11,   11,   16,
   16,   16,   16,   15,   15,    4,    4,    4,    4,    4,
    4,    4,   17,   18,   18,   22,   22,   22,   22,   22,
   22,   22,   23,   23,   23,   19,   19,   25,   26,   26,
   26,   28,   29,   20,   31,   32,   33,   27,   27,   27,
   27,   27,   27,   30,   30,   30,   34,   34,   34,   34,
   34,   34,   34,   34,   34,   34,   24,   24,   24,   24,
   24,   35,   35,   36,   36,   36,   36,   36,   21,   21,
   21,   21,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    2,    2,    1,    1,
    2,    2,    1,    1,    1,    8,    7,    7,    5,    2,
    4,    4,    3,    3,    2,    8,    7,    2,    3,    1,
    1,    1,    1,    3,    1,    2,    0,    1,    1,    3,
    2,    3,    3,    2,    1,    1,    1,    1,    2,    1,
    1,    1,    3,    4,    3,    3,    3,    4,    4,    4,
    4,    1,    3,    3,    1,    3,    4,    3,    4,    3,
    2,    1,    1,    4,    1,    3,    1,    3,    3,    3,
    3,    3,    3,    3,    2,    2,    3,    2,    2,    1,
    3,    2,    2,    1,    1,    2,    1,    2,    1,    1,
    4,    1,    1,    1,    2,    1,    2,    1,    5,    7,
    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   75,   31,   32,
   33,    0,    0,    0,    6,    0,    0,    0,   13,   14,
   15,   46,   47,   48,   50,   51,    0,   11,   30,    0,
    0,    0,    0,    0,    0,    0,    0,   49,    0,    4,
    0,    5,    7,    8,   35,    0,    0,    0,    0,  102,
  104,  106,  103,    0,   55,    0,    0,    0,   65,   99,
  100,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   66,    0,   72,    0,    3,    0,    0,
    0,   98,    0,  105,  107,   54,    0,    0,    0,    0,
    0,    0,   29,    0,   36,    0,   67,    0,    0,    0,
    0,    0,    0,   68,    0,   95,    0,    0,    0,   86,
   85,    0,   71,    0,   73,    0,   21,    0,    0,    0,
   34,   76,   77,   74,    0,    0,    0,    0,    0,    0,
    0,   63,   64,  112,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   96,   93,   89,   84,    0,
    0,    0,   70,    0,    0,   19,    0,    0,   25,  101,
    0,    0,    0,    0,  111,    0,    0,    0,   45,    0,
    0,   39,   91,   87,   69,    0,   24,    0,   23,  110,
   18,    0,    0,   17,    0,   44,    0,   22,   16,    0,
   43,   40,    0,    0,   27,    0,   26,
};
short yydgoto[] = {                                       2,
   14,  169,   16,   17,   18,   46,   19,   20,   21,   67,
  170,  119,  120,   33,  171,  172,   22,   23,   24,   25,
   26,   69,   58,   59,   37,   74,   70,   75,  114,   76,
   27,   48,  124,  109,   60,   61,
};
short yysindex[] = {                                    -89,
  535,    0,   21,  -32,   -8,   -4, -195,    0,    0,    0,
    0, -186, -177,  549,    0,   42,   46, -176,    0,    0,
    0,    0,    0,    0,    0,    0,   48,    0,    0,  192,
  228, -165,   50,   70, -173,  216, -114,    0,  -11,    0,
 -143,    0,    0,    0,    0,   57,  228, -155, -145,    0,
    0,    0,    0,   85,    0, -199,    1,   17,    0,    0,
    0,  -23,  -28, -131, -173, -130,   87, -114,  519,   88,
  419,   86,   89,    0,  432,    0,  -76,    0, -126,   93,
 -114,    0,  228,    0,    0,    0,  317,  412,  228,  228,
  240,  280,    0,   95,    0,   14,    0,  228,  228,  228,
  228,  228,  228,    0,   96,    0,   98,  100,  -90,    0,
    0, -114,    0, -125,    0, -107,    0, -176,  204,  107,
    0,    0,    0,    0,   37,  228,  228,   17,  228,  228,
   17,    0,    0,    0,   44,  -36,  -23,   34,  626,  -23,
  -23,  -23,  -23,  -23,  -23,    0,    0,    0,    0,  110,
  116, -103,    0,  130,  -21,    0, -176,  132,    0,    0,
   17,   17,   17,   17,    0,  -83,  457,  134,    0,   56,
  640,    0,    0,    0,    0, -173,    0,    3,    0,    0,
    0,   59,  626,    0,  148,    0,  157,    0,    0,  640,
    0,    0,   80,  471,    0,   77,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,  253,    0,    0,    0,
    0,    0,  205,    0,    0,  485,  521,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  277,    0,  165,    0,    0,    0,  330,    0,
  207,    0,    0,    0,    0,  344,    0,    0,  -41,    0,
    0,    0,    0,    0,    0,  -17,    0,    7,    0,    0,
    0,  368,    0,    0,  165,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  189,  443,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   31,    0,    0,
   55,    0,    0,    0,    0,  166,  382,    0,    0,  176,
  177,  178,  179,  200,  201,    0,    0,    0,    0,  560,
  581,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   79,  104,  128,  152,    0,    0,    0,    0,    0,    0,
  118,    0,    0,    0,    0,  165,    0,    0,    0,    0,
    0,    0,  119,    0,    0,    0,    0,    0,    0,  129,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    4,    2,   26,  -24, -101,    0,    0,    0,  -58,
 -154,    0,  146,    0,   83,   84,    0,    0,    0,    0,
    0,  789,  -72,   16,    0,  210,  221,    0,  180,  -44,
    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 919
short yytable[] = {                                      97,
   97,   97,   97,   97,   15,   97,   94,   30,   71,  166,
   66,   91,  182,   32,  128,  131,  155,   42,   97,   87,
   97,   88,  177,  108,  108,  108,  108,  108,   31,  108,
  115,   35,   92,    1,  149,   36,  123,   79,   72,  196,
   66,   86,  108,   87,  108,   88,  188,   62,  117,   62,
   62,   62,  118,  161,  162,  178,  163,  164,   89,   84,
   85,   79,   73,   90,   28,   38,   62,  115,   62,   72,
   39,   56,  107,   56,   56,   56,   72,  160,   40,   87,
   45,   88,   72,   97,  165,   43,   87,   47,   88,   44,
   56,   63,   56,   73,  157,   57,  108,   57,   57,   57,
   73,    9,   10,   11,  132,  133,   73,  108,   64,   65,
  150,   77,   78,   72,   57,   79,   57,  187,   81,   59,
   82,   59,   59,   59,   83,   93,   95,   96,  104,  110,
  121,   62,  111,  122,  151,  138,  139,   73,   59,  146,
   59,  147,    4,  148,   61,  153,   61,   61,   61,  154,
  159,   66,    5,  173,    6,   56,  167,    7,    8,  174,
    9,   10,   11,   61,   12,   61,    4,  175,   58,  176,
   58,   58,   58,  180,  186,  179,    5,  183,    6,   57,
  184,    7,    8,  189,    9,   10,   11,   58,   12,   58,
  116,  192,   60,  186,   60,   60,   60,  193,    9,   10,
   11,  197,  194,   59,    2,   37,    1,   97,   97,   97,
   97,   60,   97,   60,   97,   97,   80,   81,   83,   82,
   97,   97,   97,   97,   29,   97,   97,   97,   61,   82,
   97,   97,   55,   97,   97,   97,   56,   97,  108,  108,
   78,   79,   38,   41,  108,  108,  108,  108,   34,  108,
  108,  108,   58,   42,  108,  108,   68,  108,  108,  108,
   56,  108,   62,   62,  158,  190,  191,   80,   62,   62,
   62,   62,   56,   62,   62,   62,   60,   97,   62,   62,
  134,   62,   62,   62,   56,   62,   56,   56,    0,    0,
   97,  152,   56,   56,   56,   56,   52,   56,   56,   56,
    0,    0,   56,   56,    0,   56,   56,   56,    0,   56,
   57,   57,    0,   94,    0,    0,   57,   57,   57,   57,
   28,   57,   57,   57,   56,    0,   57,   57,  156,   57,
   57,   57,    0,   57,   59,   59,    0,    0,    0,    0,
   59,   59,   59,   59,    0,   59,   59,   59,    0,    0,
   59,   59,    0,   59,   59,   59,    0,   59,  126,   61,
   61,   56,    0,  127,    0,   61,   61,   61,   61,    0,
   61,   61,   61,   20,    0,   61,   61,   52,   61,   61,
   61,    0,   61,   58,   58,    0,    0,   12,    0,   58,
   58,   58,   58,    0,   58,   58,   58,    0,    0,   58,
   58,   28,   58,   58,   58,    0,   58,   60,   60,    0,
    0,   53,    0,   60,   60,   60,   60,    0,   60,   60,
   60,   97,   97,   60,   60,  109,   60,   60,   60,    0,
   60,    0,   97,   97,   97,    0,    0,   97,   97,    0,
   97,   97,   97,    0,   97,   94,    0,    0,   49,   50,
   51,   52,   53,  129,   20,   94,   56,   94,  130,    0,
   94,   94,  106,   94,   94,   94,    0,   94,   12,   54,
  116,    0,   49,   50,   51,   52,   53,    0,    9,   10,
   11,    0,    0,    0,   49,   50,   51,   52,   53,    0,
    0,    0,   53,   54,    0,    0,   49,   50,   51,   52,
   53,    0,    0,    0,    0,   54,  109,    0,   52,   52,
    0,    0,    0,    0,    0,    0,    0,   54,    0,   52,
   52,   52,    0,    0,   52,   52,    0,   52,   52,   52,
    0,   52,   28,   28,    0,    0,  136,   50,   51,   52,
   53,    0,    0,   28,   28,   28,    0,    0,   28,   28,
    0,   28,   28,   28,   71,   28,    0,   54,    0,    0,
    0,   87,    0,   88,    0,    0,    0,   90,    0,    0,
    0,    0,    0,   49,   50,   51,   52,   53,  103,    0,
  102,  181,    0,    0,    0,   20,   20,    0,    0,    0,
    0,    0,    0,    0,   54,  195,   20,   20,   20,   12,
   12,   20,   20,    0,   20,   20,   20,    0,   20,    9,
   12,   12,   12,    0,    0,   12,   12,    0,   12,   12,
   12,    0,   12,   53,   53,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   53,   53,   53,  109,  109,   53,
   53,    0,   53,   53,   53,   10,   53,    0,  109,  109,
  109,    0,    0,  109,  109,    0,  109,  109,  109,   13,
  109,    0,    0,    0,    0,    0,    0,    0,   49,   50,
   51,   52,   53,   41,  105,    4,    0,    0,    0,    0,
    0,    0,    0,    0,   92,    5,    0,    6,    4,   54,
    7,    8,    0,    9,   10,   11,    0,   12,    5,   90,
    6,  112,  113,    7,    8,   88,    9,   10,   11,   90,
   12,   90,    3,    4,   90,   90,    0,   90,   90,   90,
    0,   90,    0,    5,  168,    6,    3,    4,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    5,  168,    6,
    9,    9,    7,    8,    0,    9,   10,   11,    0,   12,
    0,    9,    9,    9,    0,    0,    9,    9,    0,    9,
    9,    9,    0,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   10,    0,    0,
   98,   99,  100,  101,    0,    0,    0,   10,   10,   10,
    3,    4,   10,   10,    0,   10,   10,   10,    0,   10,
    0,    5,    0,    6,    3,    4,    7,    8,    0,    9,
   10,   11,    0,   12,    0,    5,   92,    6,   57,   62,
    7,    8,    0,    9,   10,   11,   92,   12,   92,    0,
    0,   92,   92,    0,   92,   92,   92,   88,   92,    0,
    0,    0,    0,    0,    0,    0,    0,   88,    0,   88,
    0,    0,   88,   88,    0,   88,   88,   88,    0,   88,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  125,    0,    0,    0,    0,    0,    0,    0,  135,
  137,    3,    4,    0,    0,    0,  140,  141,  142,  143,
  144,  145,    5,  168,    6,    3,    4,    7,    8,    0,
    9,   10,   11,    0,   12,    0,    5,  185,    6,    0,
    0,    7,    8,    0,    9,   10,   11,    0,   12,
};
short yycheck[] = {                                      41,
   42,   43,   44,   45,    1,   47,   65,   40,  123,   46,
   35,   40,  167,   46,   87,   88,  118,   14,   60,   43,
   62,   45,   44,   41,   42,   43,   44,   45,   61,   47,
   75,   40,   61,  123,  125,   40,   81,   59,   37,  194,
   65,   41,   60,   43,   62,   45,   44,   41,  125,   43,
   44,   45,   77,  126,  127,  157,  129,  130,   42,  259,
  260,   59,   37,   47,   44,  261,   60,  112,   62,   68,
  257,   41,   71,   43,   44,   45,   75,   41,  256,   43,
  257,   45,   81,  125,   41,   44,   43,   40,   45,   44,
   60,  257,   62,   68,  119,   41,   71,   43,   44,   45,
   75,  275,  276,  277,   89,   90,   81,  125,   59,   40,
  109,  123,  256,  112,   60,   59,   62,  176,  274,   41,
  266,   43,   44,   45,   40,  257,  257,   41,   41,   44,
  257,  125,   44,   41,  109,   41,  123,  112,   60,   44,
   62,   44,  257,   44,   41,  271,   43,   44,   45,  257,
   44,  176,  267,   44,  269,  125,  123,  272,  273,   44,
  275,  276,  277,   60,  279,   62,  257,  271,   41,   40,
   43,   44,   45,  257,  171,   44,  267,   44,  269,  125,
  125,  272,  273,  125,  275,  276,  277,   60,  279,   62,
  267,   44,   41,  190,   43,   44,   45,   41,  275,  276,
  277,  125,  123,  125,    0,   41,    0,   42,   43,   44,
   45,   60,   47,   62,  256,  257,   41,   41,   41,   41,
  262,  263,  264,  265,  257,  267,  268,  269,  125,  266,
  272,  273,   41,  275,  276,  277,   45,  279,  256,  257,
   41,   41,  125,  125,  262,  263,  264,  265,  257,  267,
  268,  269,  125,  125,  272,  273,   41,  275,  276,  277,
   45,  279,  256,  257,  119,  183,  183,   47,  262,  263,
  264,  265,   45,  267,  268,  269,  125,   68,  272,  273,
   41,  275,  276,  277,   45,  279,  256,  257,   -1,   -1,
  125,  112,  262,  263,  264,  265,   44,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  125,   -1,   -1,  262,  263,  264,  265,
   44,  267,  268,  269,   45,   -1,  272,  273,  125,  275,
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
  267,   -1,  257,  258,  259,  260,  261,   -1,  275,  276,
  277,   -1,   -1,   -1,  257,  258,  259,  260,  261,   -1,
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
  279,  269,  256,  257,  272,  273,   -1,  275,  276,  277,
   -1,  279,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,  268,  269,
  256,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
  262,  263,  264,  265,   -1,   -1,   -1,  267,  268,  269,
  256,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,   -1,  269,  256,  257,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,  267,  257,  269,   30,   31,
  272,  273,   -1,  275,  276,  277,  267,  279,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   83,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   91,
   92,  256,  257,   -1,   -1,   -1,   98,   99,  100,  101,
  102,  103,  267,  268,  269,  256,  257,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,  267,  268,  269,   -1,
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
"seleccion : IF bloque_condicion cuerpo_if",
"seleccion : IF '(' ')' cuerpo_if",
"bloque_condicion : '(' condicion ')'",
"cuerpo_if : cuerpo_then ELSE cuerpo_else END_IF",
"cuerpo_if : cuerpo_then cuerpo_else END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_then : bloque_ejecutables",
"cuerpo_else : bloque_ejecutables",
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
#line 246 "./gramaticaComCHZGenerativa.y"
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
#line 575 "y.tab.c"
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
{ Tercet *t = new Tercet("FIN", "-", "-"); int number = tableTercets->add(t);}
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
case 9:
#line 74 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 10:
#line 75 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 11:
#line 76 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 12:
#line 79 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 14:
#line 81 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 15:
#line 82 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 17:
#line 86 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 18:
#line 87 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 20:
#line 91 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 21:
#line 92 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 22:
#line 94 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 24:
#line 96 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 26:
#line 101 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de método de clase");}
break;
case 27:
#line 102 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 31:
#line 112 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short" ;}
break;
case 32:
#line 113 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 33:
#line 114 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 34:
#line 117 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->getSymbol(yyvsp[0]->ptr)->type = typeAux; }
break;
case 35:
#line 118 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->getSymbol(yyvsp[0]->ptr)->type = typeAux; }
break;
case 36:
#line 121 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->getSymbol(yyvsp[0]->ptr)->type = yyvsp[-1]->type; tableSymbol->getSymbol(yyvsp[0]->ptr)->uso = "parametro"; yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[-1]->type;}
break;
case 38:
#line 125 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 42:
#line 130 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 43:
#line 131 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 49:
#line 139 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = new Tercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 52:
#line 142 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 53:
#line 145 "./gramaticaComCHZGenerativa.y"
{ checkTypesAsignation(tableSymbol->getSymbol(yyvsp[-2]->ptr)->type, yyvsp[0]->type); Tercet *t = new Tercet("=", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 56:
#line 153 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 57:
#line 154 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 58:
#line 155 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 59:
#line 156 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 60:
#line 157 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 61:
#line 158 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 62:
#line 159 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 63:
#line 162 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 64:
#line 163 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 65:
#line 164 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 66:
#line 167 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = tableTercets->pop(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}
break;
case 67:
#line 168 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 68:
#line 171 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); int number = tableTercets->add(t); tableTercets->push(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 70:
#line 175 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 72:
#line 179 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = tableTercets->pop();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); Tercet * t2 = new Tercet("BI", "", ""); int number = tableTercets->add(t2); tableTercets->push(t2); yyval->ptr = charTercetoId + to_string(number);}
break;
case 74:
#line 184 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = tableTercets->pop(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = tableTercets->pop(); Tercet * t3 = new Tercet("BI", t2->getArg1(), ""); int number = tableTercets->add(t3); yyval->ptr = charTercetoId + to_string(number);}
break;
case 75:
#line 187 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); tableTercets->push(t); }
break;
case 76:
#line 190 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); int number = tableTercets->add(t); tableTercets->push(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 78:
#line 196 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 79:
#line 197 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 80:
#line 198 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 81:
#line 199 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 82:
#line 200 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 201 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); Tercet *t = new Tercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 86:
#line 206 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 88:
#line 210 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 90:
#line 212 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 91:
#line 213 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 92:
#line 214 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 93:
#line 215 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 94:
#line 216 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 95:
#line 217 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 96:
#line 218 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 97:
#line 221 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 98:
#line 222 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 99:
#line 223 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 100:
#line 224 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 101:
#line 225 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = new Tercet("tof", " ", yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 102:
#line 228 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 103:
#line 229 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 104:
#line 232 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 105:
#line 233 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 106:
#line 234 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 107:
#line 235 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 108:
#line 236 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 109:
#line 239 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 110:
#line 240 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 111:
#line 241 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 112:
#line 242 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1035 "y.tab.c"
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
