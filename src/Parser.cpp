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
   28,   28,   28,   30,   31,   22,   33,   34,   35,   29,
   29,   29,   29,   29,   29,   32,   32,   32,   36,   36,
   36,   36,   36,   36,   36,   36,   36,   36,   26,   26,
   26,   26,   26,   37,   37,   38,   38,   38,   38,   38,
   23,   23,   23,   23,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    2,    2,    1,    1,
    2,    2,    1,    1,    1,    7,    7,    6,    2,    5,
    2,    4,    4,    3,    3,    2,    7,    6,    2,    2,
    3,    1,    1,    1,    1,    3,    1,    2,    0,    1,
    1,    3,    2,    3,    3,    2,    1,    1,    1,    1,
    2,    1,    1,    1,    3,    4,    3,    3,    3,    4,
    4,    4,    4,    1,    3,    3,    1,    3,    4,    3,
    4,    3,    2,    1,    1,    4,    1,    3,    1,    3,
    3,    3,    3,    3,    3,    3,    2,    2,    3,    2,
    2,    1,    3,    2,    2,    1,    1,    2,    1,    2,
    1,    1,    4,    1,    1,    1,    2,    1,    2,    1,
    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   77,   33,   34,
   35,    0,    0,    0,    6,    0,    0,    0,   13,   14,
   15,    0,   48,   49,   50,   52,   53,    0,   11,   32,
    0,    0,    0,    0,   19,    0,    0,    0,   51,    0,
    4,    0,    5,    7,    8,   37,    0,    0,    0,    0,
    0,  104,  106,  108,  105,    0,   57,    0,    0,    0,
   67,  101,  102,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   68,    0,   74,    0,    3,    0,
    0,    0,    0,  100,    0,  107,  109,   56,    0,    0,
    0,    0,    0,    0,   31,   38,    0,   69,    0,    0,
    0,    0,    0,    0,   70,    0,   97,    0,    0,    0,
   88,   87,    0,   73,    0,   75,    0,   22,    0,    0,
    0,    0,   36,    0,   78,   79,   76,    0,    0,    0,
    0,    0,    0,    0,   65,   66,  114,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   98,   95,   91,
   86,    0,    0,    0,   72,   29,    0,   20,    0,    0,
   26,    0,    0,  103,    0,    0,    0,    0,  113,    0,
    0,   47,    0,    0,   41,   93,   89,   71,   25,    0,
   24,    0,   18,    0,  112,    0,   17,    0,   46,   23,
    0,   16,    0,   45,   42,    0,   28,    0,   27,
};
short yydgoto[] = {                                       2,
   14,  172,   16,   17,   18,   47,   19,   20,   21,   22,
   68,  173,  120,  121,  122,   34,  174,  175,   23,   24,
   25,   26,   27,   70,   60,   61,   38,   75,   71,   76,
  115,   77,   28,   50,  127,  110,   62,   63,
};
short yysindex[] = {                                   -111,
  521,    0,  -21,  -32,   -8,    4, -203,    0,    0,    0,
    0, -192, -183,  535,    0,   35,   41, -171,    0,    0,
    0,   48,    0,    0,    0,    0,    0,   52,    0,    0,
  192,  228, -163,   38,    0, -166,  216,  443,    0,  -19,
    0, -154,    0,    0,    0,    0,   47, -166,  228, -167,
 -153,    0,    0,    0,    0,   72,    0, -205,   18,  -11,
    0,    0,    0,   25,  -22, -143, -141,   77,  443,  519,
   78,  419,   81,   84,    0,  432,    0,  -92,    0, -136,
   89,   93,  443,    0,  228,    0,    0,    0,  317,  412,
  228,  228,  240,  280,    0,    0,   12,    0,  228,  228,
  228,  228,  228,  228,    0,   92,    0,   94,  100,  189,
    0,    0,  443,    0, -134,    0, -107,    0, -171,   62,
  102,  111,    0,   29,    0,    0,    0,   21,  228,  228,
  -11,  228,  228,  -11,    0,    0,    0,   60,  -36,   25,
  627,   25,   25,   25,   25,   25,   25,    0,    0,    0,
    0,  113,  116,  -97,    0,    0,  -24,    0, -171,  124,
    0, -166, -114,    0,  -11,  -11,  -11,  -11,    0,  -81,
  133,    0,   53,  641,    0,    0,    0,    0,    0,   -2,
    0,  138,    0,   56,    0,  627,    0,  142,    0,    0,
   66,    0,  641,    0,    0,  457,    0,   67,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,  253,    0,    0,    0,
    0,    0,  191,    0,    0,  471,  485,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  277,    0,  153,    0,    0,    0,  330,
    0,  198,    0,    0,    0,    0,  344,  153,    0,    0,
  -41,    0,    0,    0,    0,    0,    0,  -17,    0,    7,
    0,    0,    0,  368,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  549,  560,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   31,    0,    0,   55,    0,    0,    0,    0,  166,  382,
    0,  158,  159,  161,  162,  164,  165,    0,    0,    0,
    0,  581,  592,    0,    0,    0,    0,    0,    0,    0,
    0,  153,    0,    0,   79,  104,  128,  152,    0,    0,
    0,    0,    0,   82,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   95,    0,    0,    0,    0,
    0,    0,  117,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
    0,    8,  -23,   57,  -31, -103,    0,    0,    0,    0,
  -35, -156,    0,   97,    0,    0,   32,   33,    0,    0,
    0,    0,    0,  788,  -52,   -9,    0,  172,  194,    0,
  131,  -42,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 920
short yytable[] = {                                      99,
   99,   99,   99,   99,   67,   99,  184,   31,   15,  170,
  183,    1,   81,   33,   73,  157,   67,   93,   99,  179,
   99,   43,   29,  110,  110,  110,  110,  110,   32,  110,
   91,   36,  118,  116,   80,   92,  131,  134,   94,  198,
  126,  190,  110,   37,  110,   73,  119,   64,  108,   64,
   64,   64,   73,   86,   87,  180,   80,   39,   88,   73,
   89,  164,   90,   89,   40,   90,   64,   89,   64,   90,
  116,   58,   41,   58,   58,   58,  165,  166,   44,  167,
  168,  135,  136,   99,   45,   46,  152,   48,  159,   73,
   58,   49,   58,   65,   74,   59,   66,   59,   59,   59,
  169,   79,   89,   78,   90,   80,   83,  110,    9,   10,
   11,   85,   84,   95,   59,   96,   59,   97,  105,   61,
  123,   61,   61,   61,  111,   74,  182,  112,  109,  124,
   67,   64,   74,  125,  141,  148,  155,  149,   61,   74,
   61,    3,    4,  150,   63,  161,   63,   63,   63,  156,
  162,  163,    5,  171,    6,   58,  176,    7,    8,  177,
    9,   10,   11,   63,   12,   63,  153,  181,   60,   74,
   60,   60,   60,  178,  117,  185,  186,  187,  191,   59,
  192,  189,    9,   10,   11,  195,  158,   60,  196,   60,
    2,  199,   62,   39,   62,   62,   62,    1,   82,   83,
  189,   85,   84,   61,   80,   81,   40,   99,   99,   99,
   99,   62,   99,   62,   99,   99,  160,  193,  194,   43,
   99,   99,   99,   99,   30,   99,   99,   99,   63,   84,
   99,   99,   57,   99,   99,   99,   58,   99,  110,  110,
   98,   44,   82,  154,  110,  110,  110,  110,   35,  110,
  110,  110,   60,    0,  110,  110,   69,  110,  110,  110,
   58,  110,   64,   64,    0,    0,    0,    0,   64,   64,
   64,   64,   58,   64,   64,   64,   62,    0,   64,   64,
  137,   64,   64,   64,   58,   64,   58,   58,    0,    0,
   99,    0,   58,   58,   58,   58,   54,   58,   58,   58,
    0,    0,   58,   58,    0,   58,   58,   58,    0,   58,
   59,   59,    0,  151,    0,    0,   59,   59,   59,   59,
   30,   59,   59,   59,   58,    0,   59,   59,  117,   59,
   59,   59,    0,   59,   61,   61,    9,   10,   11,    0,
   61,   61,   61,   61,    0,   61,   61,   61,    0,    0,
   61,   61,    0,   61,   61,   61,    0,   61,  129,   63,
   63,   58,    0,  130,    0,   63,   63,   63,   63,    0,
   63,   63,   63,   21,    0,   63,   63,   54,   63,   63,
   63,    0,   63,   60,   60,    0,    0,   12,    0,   60,
   60,   60,   60,    0,   60,   60,   60,    0,    0,   60,
   60,   30,   60,   60,   60,    0,   60,   62,   62,    0,
    0,   55,    0,   62,   62,   62,   62,    0,   62,   62,
   62,   99,   99,   62,   62,  111,   62,   62,   62,    0,
   62,    0,   99,   99,   99,    0,    0,   99,   99,    0,
   99,   99,   99,    0,   99,    4,    0,    0,   51,   52,
   53,   54,   55,  132,   21,    5,   58,    6,  133,    0,
    7,    8,  107,    9,   10,   11,    0,   12,   12,   56,
    0,    0,   51,   52,   53,   54,   55,    0,    0,    0,
    0,    0,    0,    0,   51,   52,   53,   54,   55,    0,
    0,    0,   55,   56,    0,    0,   51,   52,   53,   54,
   55,    0,    0,    0,    0,   56,  111,    0,   54,   54,
    0,    0,    0,    0,    0,    0,    0,   56,    0,   54,
   54,   54,    0,    0,   54,   54,    0,   54,   54,   54,
    0,   54,   30,   30,    0,    0,  139,   52,   53,   54,
   55,    0,    0,   30,   30,   30,    0,    0,   30,   30,
    0,   30,   30,   30,   72,   30,    0,   56,    0,    0,
    0,   89,    0,   90,    0,   72,    0,    0,    0,    0,
    0,    0,    0,   51,   52,   53,   54,   55,  104,    0,
  103,  197,    0,    0,    0,   21,   21,    0,    0,    0,
    0,    0,    0,    0,   56,    9,   21,   21,   21,   12,
   12,   21,   21,    0,   21,   21,   21,    0,   21,   10,
   12,   12,   12,    0,    0,   12,   12,    0,   12,   12,
   12,    0,   12,   55,   55,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   55,   55,   55,  111,  111,   55,
   55,    0,   55,   55,   55,   13,   55,    0,  111,  111,
  111,    0,    0,  111,  111,    0,  111,  111,  111,   42,
  111,    0,    0,    0,    0,    0,    0,    0,   51,   52,
   53,   54,   55,   96,  106,    4,    0,    0,    0,    0,
    0,    0,    0,    0,   92,    5,    0,    6,    4,   56,
    7,    8,    0,    9,   10,   11,    0,   12,    5,    4,
    6,  113,  114,    7,    8,   94,    9,   10,   11,    5,
   12,    6,    3,    4,    7,    8,   90,    9,   10,   11,
    0,   12,    0,    5,  171,    6,    9,    9,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    9,    9,    9,
   10,   10,    9,    9,    0,    9,    9,    9,    0,    9,
    0,   10,   10,   10,    0,    0,   10,   10,    0,   10,
   10,   10,    0,   10,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    3,    4,    0,    0,
   99,  100,  101,  102,    0,    0,    0,    5,    0,    6,
    3,    4,    7,    8,    0,    9,   10,   11,    0,   12,
    0,    5,    0,    6,    0,   96,    7,    8,    0,    9,
   10,   11,    0,   12,    0,   96,   92,   96,   59,   64,
   96,   96,    0,   96,   96,   96,   92,   96,   92,    0,
    0,   92,   92,    0,   92,   92,   92,   94,   92,    0,
    0,    0,    0,    0,    0,    0,    0,   94,   90,   94,
    0,    0,   94,   94,    0,   94,   94,   94,   90,   94,
   90,    0,    0,   90,   90,    0,   90,   90,   90,    0,
   90,    0,  128,    0,    0,    0,    0,    0,    0,    0,
  138,  140,    3,    4,    0,    0,  142,  143,  144,  145,
  146,  147,    0,    5,  171,    6,    3,    4,    7,    8,
    0,    9,   10,   11,    0,   12,    0,    5,  188,    6,
    0,    0,    7,    8,    0,    9,   10,   11,    0,   12,
};
short yycheck[] = {                                      41,
   42,   43,   44,   45,   36,   47,  163,   40,    1,   46,
  125,  123,   48,   46,   38,  119,   48,   40,   60,   44,
   62,   14,   44,   41,   42,   43,   44,   45,   61,   47,
   42,   40,  125,   76,   59,   47,   89,   90,   61,  196,
   83,   44,   60,   40,   62,   69,   78,   41,   72,   43,
   44,   45,   76,  259,  260,  159,   59,  261,   41,   83,
   43,   41,   45,   43,  257,   45,   60,   43,   62,   45,
  113,   41,  256,   43,   44,   45,  129,  130,   44,  132,
  133,   91,   92,  125,   44,  257,  110,   40,  120,  113,
   60,   40,   62,  257,   38,   41,   59,   43,   44,   45,
   41,  256,   43,  123,   45,   59,  274,  125,  275,  276,
  277,   40,  266,  257,   60,  257,   62,   41,   41,   41,
  257,   43,   44,   45,   44,   69,  162,   44,   72,   41,
  162,  125,   76,   41,  123,   44,  271,   44,   60,   83,
   62,  256,  257,   44,   41,   44,   43,   44,   45,  257,
   40,  123,  267,  268,  269,  125,   44,  272,  273,   44,
  275,  276,  277,   60,  279,   62,  110,   44,   41,  113,
   43,   44,   45,  271,  267,  257,   44,  125,   41,  125,
  125,  174,  275,  276,  277,   44,  125,   60,  123,   62,
    0,  125,   41,   41,   43,   44,   45,    0,   41,   41,
  193,   41,   41,  125,   41,   41,  125,   42,   43,   44,
   45,   60,   47,   62,  256,  257,  120,  186,  186,  125,
  262,  263,  264,  265,  257,  267,  268,  269,  125,  266,
  272,  273,   41,  275,  276,  277,   45,  279,  256,  257,
   69,  125,   49,  113,  262,  263,  264,  265,  257,  267,
  268,  269,  125,   -1,  272,  273,   41,  275,  276,  277,
   45,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   45,  267,  268,  269,  125,   -1,  272,  273,
   41,  275,  276,  277,   45,  279,  256,  257,   -1,   -1,
  125,   -1,  262,  263,  264,  265,   44,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  125,   -1,   -1,  262,  263,  264,  265,
   44,  267,  268,  269,   45,   -1,  272,  273,  267,  275,
  276,  277,   -1,  279,  256,  257,  275,  276,  277,   -1,
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
   -1,   43,   -1,   45,   -1,  123,   -1,   -1,   -1,   -1,
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
  262,  263,  264,  265,   -1,   -1,   -1,  267,   -1,  269,
  256,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,   -1,  269,   -1,  257,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,  267,  257,  269,   31,   32,
  272,  273,   -1,  275,  276,  277,  267,  279,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,  257,  279,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  257,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,  267,  279,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,   -1,   85,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   93,   94,  256,  257,   -1,   -1,   99,  100,  101,  102,
  103,  104,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
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
#line 252 "./gramaticaComCHZGenerativa.y"
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
        
        symbol* identificador = tableSymbol->getSymbol(key);// obtenemos el símbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el símbolo
        tableSymbol->deleteSymbol(key);       // eliminamos el simbolo (usa el contador)
        
        if(type != ""){
                newIdentificador->type = type;                          // actualizamos el tipo
        }
        if(scope != ""){
                newIdentificador->lexema += scope;                      // actualizamos el scope
        }
        if(uso != ""){
                newIdentificador->uso = uso;                            // actualizamos el uso
        }

        tableSymbol->insert(newIdentificador);                  // insertamos el nuevo símbolo
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
#line 623 "y.tab.c"
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
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion"); tableSymbol->addScope(yyvsp[0]->ptr); }
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
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),""); }
break;
case 37:
#line 124 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),""); }
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
{ checkTypesAsignation(tableSymbol->getSymbol(yyvsp[-2]->ptr)->type, yyvsp[0]->type); Tercet *t = new Tercet("=", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
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
case 74:
#line 185 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 76:
#line 190 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = popTercet(); int number = addTercet("BI", t2->getArg1(), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 77:
#line 193 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 78:
#line 196 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 80:
#line 202 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 81:
#line 203 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 82:
#line 204 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 205 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 84:
#line 206 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 85:
#line 207 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 88:
#line 212 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 90:
#line 216 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 92:
#line 218 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 93:
#line 219 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 94:
#line 220 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 95:
#line 221 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 96:
#line 222 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 97:
#line 223 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 98:
#line 224 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 99:
#line 227 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 100:
#line 228 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 101:
#line 229 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 102:
#line 230 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 103:
#line 231 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 104:
#line 234 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 105:
#line 235 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 106:
#line 238 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 107:
#line 239 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 108:
#line 240 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 109:
#line 241 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 110:
#line 242 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 111:
#line 245 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
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
#line 1095 "y.tab.c"
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
