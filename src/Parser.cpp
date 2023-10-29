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
    2,    3,    3,    3,    3,    9,    9,    9,   10,    7,
    7,    7,   13,   13,   13,   13,   14,   14,   15,    8,
   16,   16,    5,    5,    5,    6,    6,   11,   11,   12,
   12,   18,   18,   18,   18,   17,   17,    4,    4,    4,
    4,    4,    4,    4,   19,   20,   20,   24,   24,   24,
   24,   24,   24,   24,   25,   25,   25,   21,   21,   27,
   28,   28,   28,   30,   32,   31,   22,   34,   35,   36,
   29,   29,   29,   29,   29,   29,   33,   33,   33,   37,
   37,   37,   37,   37,   37,   37,   37,   37,   37,   26,
   26,   26,   26,   26,   38,   38,   39,   39,   39,   39,
   39,   23,   23,   23,   23,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    2,    2,    1,    1,
    2,    2,    1,    1,    1,    7,    7,    6,    2,    5,
    2,    4,    4,    3,    3,    2,    7,    6,    2,    2,
    3,    1,    1,    1,    1,    3,    1,    2,    0,    1,
    1,    3,    2,    3,    3,    2,    1,    1,    1,    1,
    2,    1,    1,    1,    3,    4,    3,    3,    3,    4,
    4,    4,    4,    1,    3,    3,    1,    3,    4,    3,
    4,    3,    2,    1,    1,    1,    4,    1,    3,    1,
    3,    3,    3,    3,    3,    3,    3,    2,    2,    3,
    2,    2,    1,    3,    2,    2,    1,    1,    2,    1,
    2,    1,    1,    4,    1,    1,    1,    2,    1,    2,
    1,    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   78,   33,   34,
   35,    0,    0,    0,    6,    0,    0,    0,   13,   14,
   15,    0,   48,   49,   50,   52,   53,    0,   11,   32,
    0,    0,    0,    0,   19,    0,    0,    0,   51,    0,
    4,    0,    5,    7,    8,   37,    0,    0,    0,    0,
    0,  105,  107,  109,  106,    0,   57,    0,    0,    0,
   67,  102,  103,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   68,    0,   74,    0,    3,    0,
    0,    0,    0,  101,    0,  108,  110,   56,    0,    0,
    0,    0,    0,    0,   31,   38,    0,   69,    0,    0,
    0,    0,    0,    0,   70,    0,   98,    0,    0,    0,
   89,   88,   76,   73,    0,    0,   75,    0,   22,    0,
    0,    0,    0,   36,    0,   79,   80,   77,    0,    0,
    0,    0,    0,    0,    0,   65,   66,  115,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   99,   96,
   92,   87,    0,    0,    0,   72,   29,    0,   20,    0,
    0,   26,    0,    0,  104,    0,    0,    0,    0,  114,
    0,    0,   47,    0,    0,   41,   94,   90,   71,   25,
    0,   24,    0,   18,    0,  113,    0,   17,    0,   46,
   23,    0,   16,    0,   45,   42,    0,   28,    0,   27,
};
short yydgoto[] = {                                       2,
   14,  173,   16,   17,   18,   47,   19,   20,   21,   22,
   68,  174,  121,  122,  123,   34,  175,  176,   23,   24,
   25,   26,   27,   70,   60,   61,   38,   75,   71,   76,
  115,  116,   77,   28,   50,  128,  110,   62,   63,
};
short yysindex[] = {                                   -100,
  535,    0,   -5,  -32,   -8,   -4, -215,    0,    0,    0,
    0, -203, -198,  549,    0,   24,   27, -184,    0,    0,
    0,   38,    0,    0,    0,    0,    0,   50,    0,    0,
  192,  228, -175,   33,    0, -190,  216, -114,    0,  -26,
    0, -155,    0,    0,    0,    0,   43, -190,  228, -170,
 -163,    0,    0,    0,    0,   65,    0, -171,   20,  -30,
    0,    0,    0,   -3,   -6, -151, -150,   68, -114,  519,
   69,  419,   72,   75,    0,  432,    0,  -92,    0, -145,
   80,   86, -114,    0,  228,    0,    0,    0,  317,  412,
  228,  228,  240,  280,    0,    0,  -10,    0,  228,  228,
  228,  228,  228,  228,    0,   85,    0,   87,   89,  189,
    0,    0,    0,    0, -114, -141,    0, -123,    0, -184,
  -76,   91,   96,    0,   14,    0,    0,    0,   21,  228,
  228,  -30,  228,  228,  -30,    0,    0,    0,   36,  -36,
   -3,  627,   -3,   -3,   -3,   -3,   -3,   -3,    0,    0,
    0,    0,   94,   98, -131,    0,    0,  -24,    0, -184,
  100,    0, -190,  457,    0,  -30,  -30,  -30,  -30,    0,
 -111,  106,    0,   26,  652,    0,    0,    0,    0,    0,
  -22,    0,  113,    0,   35,    0,  627,    0,  123,    0,
    0,   47,    0,  652,    0,    0,  471,    0,   49,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,  253,    0,    0,    0,
    0,    0,  176,    0,    0,  485,  521,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  277,    0,  136,    0,    0,    0,  330,
    0,  178,    0,    0,    0,    0,  344,  136,    0,    0,
  -41,    0,    0,    0,    0,    0,    0,  -17,    0,    7,
    0,    0,    0,  368,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  443,  560,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   31,    0,    0,   55,    0,    0,    0,    0,  166,
  382,    0,  140,  141,  145,  146,  148,  151,    0,    0,
    0,    0,  581,  592,    0,    0,    0,    0,    0,    0,
    0,    0,  136,    0,    0,   79,  104,  128,  152,    0,
    0,    0,    0,    0,   77,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   78,    0,    0,    0,
    0,    0,    0,   81,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    4,   42,  803,    5, -113,    0,    0,    0,    0,
  -35, -153,    0,   73,    0,    0,   18,   30,    0,    0,
    0,    0,    0,  788,  -74,    3,    0,  138,  169,    0,
    0,  105,  -45,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 931
short yytable[] = {                                     100,
  100,  100,  100,  100,   15,  100,  158,   31,   72,  171,
  185,   91,   81,   33,  132,  135,   92,   43,  100,  180,
  100,  191,    1,  111,  111,  111,  111,  111,   32,  111,
  117,   36,  119,   93,   80,   37,   80,  127,   29,   89,
   67,   90,  111,  199,  111,   39,  181,   64,  159,   64,
   64,   64,   67,   40,   94,  166,  167,   41,  168,  169,
   88,  165,   89,   89,   90,   90,   64,   44,   64,  117,
   45,   58,   46,   58,   58,   58,  170,   48,   89,   73,
   90,   65,  120,  100,    9,   10,   11,   86,   87,   49,
   58,   66,   58,  136,  137,   59,   78,   59,   59,   59,
   79,   80,   84,   83,   85,   95,   96,  111,   97,  105,
   73,  124,  142,  108,   59,  111,   59,   73,  112,   61,
  125,   61,   61,   61,   73,  160,  126,  183,  149,  156,
  150,   64,  151,  157,  162,  163,  164,  177,   61,  179,
   61,  178,    4,  182,   63,  186,   63,   63,   63,  187,
  188,  153,    5,  192,    6,   58,   73,    7,    8,  193,
    9,   10,   11,   63,   12,   63,  196,   67,   60,  197,
   60,   60,   60,  200,  118,    2,   39,    1,  190,   59,
   83,   84,    9,   10,   11,   86,   85,   60,   81,   60,
  118,   82,   62,  161,   62,   62,   62,  190,    9,   10,
   11,   40,   43,   61,  194,   44,   98,  100,  100,  100,
  100,   62,  100,   62,  100,  100,  195,   82,    0,  155,
  100,  100,  100,  100,   30,  100,  100,  100,   63,   84,
  100,  100,   57,  100,  100,  100,   58,  100,  111,  111,
    0,    0,    0,    0,  111,  111,  111,  111,   35,  111,
  111,  111,   60,    0,  111,  111,   69,  111,  111,  111,
   58,  111,   64,   64,    0,    0,    0,    0,   64,   64,
   64,   64,   58,   64,   64,   64,   62,    0,   64,   64,
  138,   64,   64,   64,   58,   64,   58,   58,    0,    0,
  100,    0,   58,   58,   58,   58,   54,   58,   58,   58,
    0,    0,   58,   58,    0,   58,   58,   58,    0,   58,
   59,   59,    0,  152,    0,    0,   59,   59,   59,   59,
   30,   59,   59,   59,   58,    0,   59,   59,    0,   59,
   59,   59,    0,   59,   61,   61,    0,    0,    0,    0,
   61,   61,   61,   61,    0,   61,   61,   61,    0,    0,
   61,   61,    0,   61,   61,   61,    0,   61,  130,   63,
   63,   58,    0,  131,    0,   63,   63,   63,   63,    0,
   63,   63,   63,   21,    0,   63,   63,   54,   63,   63,
   63,    0,   63,   60,   60,    0,    0,   12,    0,   60,
   60,   60,   60,    0,   60,   60,   60,    0,    0,   60,
   60,   30,   60,   60,   60,    0,   60,   62,   62,    0,
    0,   55,    0,   62,   62,   62,   62,    0,   62,   62,
   62,  100,  100,   62,   62,  112,   62,   62,   62,    0,
   62,    0,  100,  100,  100,    0,    0,  100,  100,    0,
  100,  100,  100,    0,  100,    4,    0,    0,   51,   52,
   53,   54,   55,  133,   21,    5,   58,    6,  134,    0,
    7,    8,  107,    9,   10,   11,    0,   12,   12,   56,
    0,    0,   51,   52,   53,   54,   55,    0,    0,    0,
    0,    0,    0,    0,   51,   52,   53,   54,   55,    0,
    0,    0,   55,   56,    0,    0,   51,   52,   53,   54,
   55,    0,    0,    0,    0,   56,  112,    0,   54,   54,
    0,    0,    0,    0,    0,    0,    0,   56,    0,   54,
   54,   54,    0,    0,   54,   54,    0,   54,   54,   54,
    0,   54,   30,   30,    0,    0,  140,   52,   53,   54,
   55,    0,    0,   30,   30,   30,    0,    0,   30,   30,
    0,   30,   30,   30,   72,   30,    0,   56,    0,    0,
    0,   89,    0,   90,    0,    0,    0,   97,    0,    0,
    0,    0,    0,   51,   52,   53,   54,   55,  104,    0,
  103,  184,    0,    0,    0,   21,   21,    0,    0,    0,
    0,    0,    0,    0,   56,  198,   21,   21,   21,   12,
   12,   21,   21,    0,   21,   21,   21,    0,   21,    9,
   12,   12,   12,    0,    0,   12,   12,    0,   12,   12,
   12,    0,   12,   55,   55,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   55,   55,   55,  112,  112,   55,
   55,    0,   55,   55,   55,   10,   55,    0,  112,  112,
  112,    0,    0,  112,  112,    0,  112,  112,  112,   13,
  112,    0,    0,    0,    0,    0,    0,    0,   51,   52,
   53,   54,   55,   42,  106,    4,    0,    0,    0,    0,
    0,    0,    0,    0,   93,    5,    0,    6,    4,   56,
    7,    8,    0,    9,   10,   11,    0,   12,    5,   97,
    6,  113,  114,    7,    8,   95,    9,   10,   11,   97,
   12,   97,    3,    4,   97,   97,   91,   97,   97,   97,
    0,   97,    0,    5,  172,    6,    3,    4,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    5,  172,    6,
    9,    9,    7,    8,    0,    9,   10,   11,    0,   12,
    0,    9,    9,    9,    0,    0,    9,    9,    0,    9,
    9,    9,    0,    9,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   10,   10,    0,    0,
   99,  100,  101,  102,    0,    0,    0,   10,   10,   10,
    3,    4,   10,   10,    0,   10,   10,   10,    0,   10,
    0,    5,    0,    6,    3,    4,    7,    8,    0,    9,
   10,   11,    0,   12,    0,    5,   93,    6,   59,   64,
    7,    8,    0,    9,   10,   11,   93,   12,   93,    0,
    0,   93,   93,    0,   93,   93,   93,   95,   93,    0,
   74,    0,    0,    0,    0,    0,    0,   95,   91,   95,
    0,    0,   95,   95,    0,   95,   95,   95,   91,   95,
   91,    0,    0,   91,   91,    0,   91,   91,   91,    0,
   91,   74,  129,    0,  109,    0,    0,    0,   74,    0,
  139,  141,    3,    4,    0,   74,  143,  144,  145,  146,
  147,  148,    0,    5,  172,    6,    0,    0,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    3,    4,    0,
    0,    0,  154,    0,    0,    0,    0,   74,    5,  189,
    6,    0,    0,    7,    8,    0,    9,   10,   11,    0,
   12,
};
short yycheck[] = {                                      41,
   42,   43,   44,   45,    1,   47,  120,   40,  123,   46,
  164,   42,   48,   46,   89,   90,   47,   14,   60,   44,
   62,   44,  123,   41,   42,   43,   44,   45,   61,   47,
   76,   40,  125,   40,   59,   40,   59,   83,   44,   43,
   36,   45,   60,  197,   62,  261,  160,   41,  125,   43,
   44,   45,   48,  257,   61,  130,  131,  256,  133,  134,
   41,   41,   43,   43,   45,   45,   60,   44,   62,  115,
   44,   41,  257,   43,   44,   45,   41,   40,   43,   38,
   45,  257,   78,  125,  275,  276,  277,  259,  260,   40,
   60,   59,   62,   91,   92,   41,  123,   43,   44,   45,
  256,   59,  266,  274,   40,  257,  257,  125,   41,   41,
   69,  257,  123,   72,   60,   44,   62,   76,   44,   41,
   41,   43,   44,   45,   83,  121,   41,  163,   44,  271,
   44,  125,   44,  257,   44,   40,  123,   44,   60,  271,
   62,   44,  257,   44,   41,  257,   43,   44,   45,   44,
  125,  110,  267,   41,  269,  125,  115,  272,  273,  125,
  275,  276,  277,   60,  279,   62,   44,  163,   41,  123,
   43,   44,   45,  125,  267,    0,   41,    0,  175,  125,
   41,   41,  275,  276,  277,   41,   41,   60,   41,   62,
  267,   41,   41,  121,   43,   44,   45,  194,  275,  276,
  277,  125,  125,  125,  187,  125,   69,   42,   43,   44,
   45,   60,   47,   62,  256,  257,  187,   49,   -1,  115,
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
  276,  277,   -1,  279,   -1,  267,  257,  269,   31,   32,
  272,  273,   -1,  275,  276,  277,  267,  279,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
   38,   -1,   -1,   -1,   -1,   -1,   -1,  267,  257,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  267,  279,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,   69,   85,   -1,   72,   -1,   -1,   -1,   76,   -1,
   93,   94,  256,  257,   -1,   83,   99,  100,  101,  102,
  103,  104,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  256,  257,   -1,
   -1,   -1,  110,   -1,   -1,   -1,   -1,  115,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,
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
#line 253 "./gramaticaComCHZGenerativa.y"
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
#line 629 "y.tab.c"
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
case 16:
#line 85 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope();}
break;
case 17:
#line 86 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 18:
#line 87 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "funcion"); if(diff == 0){yyerror("Redeclaración de función en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion");} tableSymbol->addScope(yyvsp[0]->ptr); }
break;
case 20:
#line 93 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 21:
#line 94 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 22:
#line 95 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 23:
#line 97 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 25:
#line 99 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 27:
#line 104 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); }
break;
case 28:
#line 105 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 29:
#line 108 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope(yyvsp[0]->ptr);}
break;
case 33:
#line 118 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 34:
#line 119 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 35:
#line 120 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 36:
#line 123 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 37:
#line 124 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 38:
#line 127 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, yyvsp[-1]->type, tableSymbol->getScope(), "parametro"); yyval->ptr = newIdentificador->lexema; yyval->type = yyvsp[-1]->type;}
break;
case 40:
#line 131 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 44:
#line 136 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 45:
#line 137 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 51:
#line 145 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 54:
#line 148 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 55:
#line 151 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 58:
#line 159 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 59:
#line 160 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 60:
#line 161 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 61:
#line 162 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 62:
#line 163 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 63:
#line 164 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 64:
#line 165 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 65:
#line 168 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 66:
#line 169 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 67:
#line 170 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 68:
#line 173 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}
break;
case 69:
#line 174 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 70:
#line 177 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 72:
#line 181 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 76:
#line 189 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 77:
#line 191 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = popTercet(); int number = addTercet("BI", t2->getArg1(), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 78:
#line 194 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 79:
#line 197 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 81:
#line 203 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 82:
#line 204 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 205 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 84:
#line 206 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 85:
#line 207 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 86:
#line 208 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 89:
#line 213 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 91:
#line 217 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 93:
#line 219 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 94:
#line 220 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 95:
#line 221 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 96:
#line 222 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 97:
#line 223 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 98:
#line 224 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 99:
#line 225 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 100:
#line 228 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 101:
#line 229 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 102:
#line 230 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 103:
#line 231 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 104:
#line 232 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 105:
#line 235 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 106:
#line 236 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 107:
#line 239 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 108:
#line 240 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 109:
#line 241 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 110:
#line 242 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 111:
#line 243 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 112:
#line 246 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 113:
#line 247 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 114:
#line 248 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 115:
#line 249 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1101 "y.tab.c"
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
