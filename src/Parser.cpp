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
    3,    3,    3,    3,    3,    3,    3,    9,    9,    9,
   11,   11,   11,   11,   12,   12,   10,   13,   13,   13,
    5,    5,    5,    6,    6,    7,    7,    8,    8,   15,
   15,   15,   15,   14,   14,    4,    4,    4,    4,    4,
    4,    4,   16,   16,   17,   17,   21,   21,   21,   21,
   21,   21,   21,   22,   22,   22,   18,   18,   18,   18,
   18,   18,   19,   24,   24,   24,   24,   24,   24,   25,
   25,   25,   26,   26,   26,   26,   23,   23,   23,   23,
   23,   27,   27,   28,   28,   28,   28,   28,   20,   20,
   20,   20,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    1,    1,    1,    2,
    3,    9,    2,    2,    2,    8,    8,    5,    2,    4,
    4,    2,    3,    1,    9,    8,    2,    3,    1,    2,
    1,    1,    1,    3,    1,    2,    0,    1,    1,    3,
    2,    3,    3,    2,    1,    1,    1,    1,    3,    1,
    1,    2,    4,    3,    5,    4,    3,    3,    4,    4,
    4,    4,    1,    3,    3,    1,    9,    8,    8,    7,
    6,    6,    7,    3,    3,    3,    3,    3,    3,    3,
    1,    1,    2,    1,    2,    1,    1,    2,    1,    1,
    4,    1,    1,    1,    2,    1,    2,    1,    6,    8,
    7,    6,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   31,   32,
   33,    0,    0,    9,    0,    0,    7,    8,    0,    0,
    0,    0,   46,   47,   48,   50,   51,   10,    0,    0,
    0,    0,   27,    0,    0,    0,    0,   52,    0,    0,
    4,    0,    5,   35,    0,   15,    0,   13,   14,    0,
    0,   92,   94,   96,   93,    0,    0,    0,    0,    0,
   66,   89,   90,   54,    0,    0,    0,    0,    0,    0,
    0,    0,   49,    0,    0,    3,   11,   34,   28,   88,
    0,   56,   95,   97,    0,    0,    0,    0,    0,   53,
    0,    0,    0,   36,    0,    0,   82,   81,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
    0,   24,    0,   55,    0,    0,    0,    0,    0,    0,
   64,   65,    0,    0,    0,    0,    0,    0,   86,   84,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,    0,   22,   91,    0,    0,    0,    0,
  102,    0,    0,   99,    0,    0,    0,    0,    0,   39,
   80,   85,   83,   72,    0,    0,   71,    0,    0,    0,
   23,    0,  101,    0,    0,    0,    0,   44,    0,    0,
    0,   70,    0,   73,    0,   21,  100,   17,    0,    0,
   43,   16,   40,    0,   69,   68,    0,   12,   67,    0,
    0,    0,   26,    0,   25,
};
short yydgoto[] = {                                       2,
   15,  157,   17,   18,   19,   20,   69,  158,   21,   22,
  111,  112,   33,  159,  160,   23,   24,   25,   26,   27,
   71,   60,   61,   72,   99,  131,   62,   63,
};
short yysindex[] = {                                    -97,
   43,    0,   -8,  -16,  -18,  -12,  -17,   14,    0,    0,
    0, -217, -198,    0,  -57,   71,    0,    0, -185,  -27,
   36,   48,    0,    0,    0,    0,    0,    0,   17,  -41,
   94, -158,    0,   62, -210,  -36,   60,    0,   99,    7,
    0, -145,    0,    0,   11,    0, -116,    0,    0, -111,
 -147,    0,    0,    0,    0,  107,  106, -138,   55,   -5,
    0,    0,    0,    0,   73,  -11, -210, -109,  114,  180,
  233,  115,    0,  126, -124,    0,    0,    0,    0,    0,
   99,    0,    0,    0,  130,  -26,   -4,   99,   99,    0,
  -31,  104,  136,    0,   56,  232,    0,    0,  -84,   99,
   99,   99,   99,   99,   99,  180,  -94,  -58,    0, -185,
  120,    0,   64,    0,   99,   99,   -5,   99,   99,   -5,
    0,    0,  151,   67,  -23,   82,   77,   57,    0,    0,
  206,  158,  -25,  -25,  -25,  -25,  -25,  -25,   -9,  180,
  164,   12,    0, -185,    0,    0,   -5,   -5,   -5,   -5,
    0,  161,  -51,    0,   15,  163,   71,   84,  -56,    0,
    0,    0,    0,    0,  180,  167,    0,  -35,  170, -210,
    0,   16,    0,  196,  202,  124,   57,    0,  207,  215,
  -33,    0,  221,    0,  209,    0,    0,    0,  225,  -56,
    0,    0,    0,  229,    0,    0,  152,    0,    0,   29,
  235,  155,    0,  237,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   20,    0,    0,    0,    0,    0,    0,
    0,    0,  277,    0,    0,  182,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  245,    0,
    0,    0,    0,    0,  268,    0,    0,    0,    0,  267,
    0,  317,    0,    0,    0,    0,    0,    0,    0,  279,
  116,    0,    0,    0,    0,    0,    0,  128,    0,  121,
    0,    0,    0,    0,    0,    0,  268,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  141,    0,    0,  148,
    0,    0,    0,    0,   46,    0,    0,    0,    0,    0,
    0,    0,  280,  294,  296,  298,  300,  301,    0,    0,
    0,    0,    0,    0,    0,    0,  153,  378,  383,  388,
    0,    0,    0,    0,    0,    0, -123,    0,  220,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  268,
    0,    0,    0,    0,    0,    0,  224,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  -57,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  350,   30,  -62,  -45,  -28,  -13,  -64, -143,    0,    0,
    0,  256,  318, -144,  192,    0,    0,    0,    0,    0,
   32,  -34,   40,  331,  -91,    0,    0,    0,
};
#define YYTABLESIZE 653
short yytable[] = {                                      57,
  109,   45,   93,   58,   70,   45,   68,   97,   58,  123,
  195,  176,  178,   58,  139,  115,   46,   86,   58,   87,
  116,   35,  153,   30,   98,    1,   38,   36,   91,   32,
   16,   47,  190,  129,  167,   28,   88,  118,   68,   40,
   58,   89,  119,   97,   31,   16,  110,  168,  169,   92,
  130,  117,  120,   39,   77,  171,  202,   41,   14,  186,
   98,   59,   65,   35,    9,   10,   11,   42,  162,   47,
   47,   44,   14,  181,   47,   50,   97,   97,   35,   48,
  147,  148,  144,  149,  150,  163,   14,   87,   87,   87,
   87,   49,   87,   98,   98,   85,  142,   86,   66,   87,
   14,   67,   97,   73,  146,  185,   86,  152,   87,   86,
   76,   87,  113,   96,   14,   86,   90,   87,   80,   98,
   83,   84,  124,  126,   86,  154,   87,  121,  122,   75,
  172,  133,  134,  135,  136,  137,  138,   64,   58,  175,
   78,   68,  108,   58,   45,   29,   81,   94,   58,   82,
    9,   10,   11,  201,   95,  106,   87,   87,   87,   87,
   87,   63,   87,   63,   63,   63,  107,   13,   98,   98,
   98,   98,   98,  114,   98,   87,  127,   87,  128,  140,
   63,   57,   63,   57,   57,   57,  132,   98,   58,   98,
   58,   58,   58,   60,  151,   60,   60,   60,  141,  155,
   57,  164,   57,  170,  173,  174,  177,   58,  179,   58,
  182,  180,   60,  184,   60,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,  183,   56,  194,   34,  187,
   29,   56,   80,   37,  143,  188,   56,    4,  189,  197,
  192,   56,   51,   52,   53,   54,   55,    5,  193,    6,
  165,  166,    7,    8,  196,    9,   10,   11,  198,   12,
    3,    4,  199,   56,  200,   86,    2,   87,  203,  204,
  205,    5,  156,    6,    3,    4,    7,    8,   29,    9,
   10,   11,  105,   12,  104,    5,  156,    6,    3,    4,
    7,    8,   96,    9,   10,   11,    6,   12,   37,    5,
   19,    6,    3,    4,    7,    8,    1,    9,   10,   11,
   76,   12,   30,    5,  156,    6,    3,    4,    7,    8,
  161,    9,   10,   11,   77,   12,   79,    5,   78,    6,
   74,   75,    7,    8,   38,    9,   10,   11,   41,   12,
   51,   52,   53,   54,   55,   51,   52,   53,   54,   55,
  125,   52,   53,   54,   55,   43,  145,   79,  191,   74,
    0,   56,    0,    0,    0,    0,   56,   87,   87,   87,
   87,   56,   63,   63,   63,   63,  108,    0,    0,   98,
   98,   98,   98,    0,    9,   10,   11,    0,    0,    0,
    0,    0,   57,   57,   57,   57,    0,    0,    0,   58,
   58,   58,   58,    0,   60,   60,   60,   60,   62,    0,
   62,   62,   62,   59,    0,   59,   59,   59,   61,    0,
   61,   61,   61,    0,    0,    0,    4,   62,    0,   62,
    0,    0,   59,    0,   59,    0,    5,   61,    6,   61,
    0,    7,    8,    0,    9,   10,   11,    0,   12,    0,
    0,    0,    4,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    5,    0,    6,    0,    0,    7,    8,    0,
    9,   10,   11,    0,   12,    0,    0,    0,    4,    0,
    0,    0,    0,    0,  100,  101,  102,  103,    5,    0,
    6,    0,    0,    7,    8,    0,    9,   10,   11,    0,
   12,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   62,
   62,   62,   62,    0,   59,   59,   59,   59,    0,   61,
   61,   61,   61,
};
short yycheck[] = {                                      41,
  125,  125,   67,   45,   41,   19,   35,   70,   45,   41,
   44,  155,  157,   45,  106,   42,   44,   43,   45,   45,
   47,   40,   46,   40,   70,  123,   44,   40,   40,   46,
    1,   59,  177,   96,   44,   44,   42,   42,   67,  257,
   45,   47,   47,  106,   61,   16,   75,  139,  140,   61,
   96,   86,   87,   40,   44,   44,  200,  256,   44,   44,
  106,   30,   31,   44,  275,  276,  277,  125,  131,   59,
   59,  257,   44,  165,   59,   59,  139,  140,   59,   44,
  115,  116,  111,  118,  119,  131,   44,   42,   43,   44,
   45,   44,   47,  139,  140,   41,  110,   43,  257,   45,
   44,   40,  165,   44,   41,  170,   43,   41,   45,   43,
  256,   45,   81,  123,   44,   43,   44,   45,  266,  165,
  259,  260,   91,   92,   43,   44,   45,   88,   89,  123,
  144,  100,  101,  102,  103,  104,  105,   44,   45,  125,
  257,  170,  267,   45,  268,  257,   40,  257,   45,   44,
  275,  276,  277,  125,   41,   41,   41,   42,   43,   44,
   45,   41,   47,   43,   44,   45,   41,  125,   41,   42,
   43,   44,   45,   44,   47,   60,   41,   62,  123,  274,
   60,   41,   62,   43,   44,   45,  271,   60,   41,   62,
   43,   44,   45,   41,   44,   43,   44,   45,  257,  123,
   60,   44,   62,   40,   44,  257,   44,   60,  125,   62,
   44,  268,   60,   44,   62,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  271,  278,  271,  257,   44,
  257,  278,  266,  261,  125,   44,  278,  257,  125,   41,
   44,  278,  257,  258,  259,  260,  261,  267,   44,  269,
  270,  271,  272,  273,   44,  275,  276,  277,   44,  279,
  256,  257,   44,  278,  123,   43,    0,   45,   44,  125,
   44,  267,  268,  269,  256,  257,  272,  273,   44,  275,
  276,  277,   60,  279,   62,  267,  268,  269,  256,  257,
  272,  273,  123,  275,  276,  277,  125,  279,   41,  267,
   44,  269,  256,  257,  272,  273,    0,  275,  276,  277,
   41,  279,   44,  267,  268,  269,  256,  257,  272,  273,
  125,  275,  276,  277,   41,  279,   41,  267,   41,  269,
   41,   41,  272,  273,  125,  275,  276,  277,  125,  279,
  257,  258,  259,  260,  261,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   16,  111,   50,  177,   39,
   -1,  278,   -1,   -1,   -1,   -1,  278,  262,  263,  264,
  265,  278,  262,  263,  264,  265,  267,   -1,   -1,  262,
  263,  264,  265,   -1,  275,  276,  277,   -1,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,   -1,   -1,   -1,  262,
  263,  264,  265,   -1,  262,  263,  264,  265,   41,   -1,
   43,   44,   45,   41,   -1,   43,   44,   45,   41,   -1,
   43,   44,   45,   -1,   -1,   -1,  257,   60,   -1,   62,
   -1,   -1,   60,   -1,   62,   -1,  267,   60,  269,   62,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,   -1,
   -1,   -1,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,   -1,   -1,   -1,  257,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  267,   -1,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,   -1,  262,  263,  264,  265,   -1,  262,
  263,  264,  265,
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
"sentencias : sentencia sentencias",
"sentencias : sentencia",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : ','",
"sentencia : error ','",
"declarativa : tipo lista_de_variables ','",
"declarativa : VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','",
"declarativa : declaracion_clase ','",
"declarativa : declaracion_objeto ','",
"declarativa : lista_de_variables ','",
"declarativa : VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','",
"declarativa : VOID IDENTIFICADOR '(' parametro ')' '{' '}' ','",
"declaracion_clase : CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'",
"declaracion_clase : CLASS IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' '}'",
"lista_atributos_y_metodos : lista_atributos_y_metodos tipo lista_de_variables ','",
"lista_atributos_y_metodos : lista_atributos_y_metodos metodo",
"lista_atributos_y_metodos : tipo lista_de_variables ','",
"lista_atributos_y_metodos : metodo",
"metodo : VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','",
"metodo : VOID IDENTIFICADOR '(' parametro ')' '{' '}' ','",
"declaracion_objeto : IDENTIFICADOR lista_de_objetos",
"lista_de_objetos : IDENTIFICADOR ';' lista_de_objetos",
"lista_de_objetos : IDENTIFICADOR",
"lista_de_objetos : IDENTIFICADOR ';'",
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
"cuerpo_de_la_funcion_sin_return : sentencia cuerpo_de_la_funcion_sin_return",
"cuerpo_de_la_funcion_sin_return : sentencia",
"ejecutable : asignacion",
"ejecutable : invocacion",
"ejecutable : seleccion",
"ejecutable : PRINT CADENA_CARACTERES ','",
"ejecutable : ciclo_while",
"ejecutable : acceso_objeto",
"ejecutable : PRINT ','",
"asignacion : IDENTIFICADOR '=' expresion_aritmetica ','",
"asignacion : IDENTIFICADOR '=' ','",
"invocacion : IDENTIFICADOR '(' expresion_aritmetica ')' ','",
"invocacion : IDENTIFICADOR '(' ')' ','",
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
"seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables END_IF ','",
"seleccion : IF '(' condicion ')' bloque_ejecutables bloque_ejecutables END_IF ','",
"seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables ','",
"seleccion : IF '(' condicion ')' bloque_ejecutables END_IF ','",
"seleccion : IF '(' condicion ')' bloque_ejecutables ','",
"seleccion : IF '(' ')' bloque_ejecutables END_IF ','",
"ciclo_while : WHILE '(' condicion ')' DO bloque_ejecutables ','",
"condicion : expresion_aritmetica '>' expresion_aritmetica",
"condicion : expresion_aritmetica '<' expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica",
"bloque_ejecutables : '{' sentencias_ejecutables '}'",
"bloque_ejecutables : ejecutable",
"bloque_ejecutables : declarativa",
"sentencias_ejecutables : sentencias_ejecutables ejecutable",
"sentencias_ejecutables : ejecutable",
"sentencias_ejecutables : sentencias_ejecutables declarativa",
"sentencias_ejecutables : declarativa",
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
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica ','",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR ','",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')' ','",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' ')' ','",
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
#line 214 "./gramaticaComCHZExtendida.y"
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
#line 481 "y.tab.c"
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
{ yyerror("Se detectó una sentencia vacía"); }
break;
case 10:
#line 70 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 11:
#line 73 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 12:
#line 74 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 14:
#line 76 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 15:
#line 77 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de un tipo en la declaración de variables"); }
break;
case 16:
#line 78 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 17:
#line 79 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 18:
#line 83 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 19:
#line 84 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 20:
#line 85 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 21:
#line 87 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 23:
#line 89 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 25:
#line 94 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de método de clase");}
break;
case 26:
#line 95 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 30:
#line 103 "./gramaticaComCHZExtendida.y"
{ yyerror("Falta identificador en la declaración de un objeto"); }
break;
case 38:
#line 117 "./gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 42:
#line 122 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 43:
#line 123 "./gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 47:
#line 129 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó invación a función");}
break;
case 49:
#line 131 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó una impresión");}
break;
case 52:
#line 134 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 53:
#line 137 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó asignación");}
break;
case 54:
#line 138 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 59:
#line 148 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 60:
#line 149 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 61:
#line 150 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 62:
#line 151 "./gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 67:
#line 160 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF-ELSE");}
break;
case 68:
#line 161 "./gramaticaComCHZExtendida.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 69:
#line 162 "./gramaticaComCHZExtendida.y"
{ yyerror("Falta de END_IF en el bloque de control IF-ELSE");}
break;
case 70:
#line 163 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF");}
break;
case 71:
#line 164 "./gramaticaComCHZExtendida.y"
{yyerror("Falta de END_IF en el bloque de control IF");}
break;
case 72:
#line 165 "./gramaticaComCHZExtendida.y"
{yyerror("Falta de condición en el bloque de control IF");}
break;
case 73:
#line 168 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un WHILE-DO");}
break;
case 82:
#line 181 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 85:
#line 186 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 86:
#line 187 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 94:
#line 200 "./gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 95:
#line 201 "./gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 98:
#line 204 "./gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 99:
#line 207 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 100:
#line 208 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 101:
#line 209 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 102:
#line 210 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 817 "y.tab.c"
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
