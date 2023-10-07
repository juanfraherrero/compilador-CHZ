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
bool isErrorInParsing = false;

void yyerror(string s){
    isErrorInParsing = true;    
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
   19,   24,   24,   24,   24,   24,   24,   25,   25,   25,
   26,   26,   26,   26,   23,   23,   23,   23,   23,   27,
   27,   28,   28,   28,   28,   28,   20,   20,   20,   20,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    1,    1,    1,    2,
    3,    9,    2,    2,    2,    8,    8,    5,    2,    4,
    4,    2,    3,    1,    9,    8,    2,    3,    1,    2,
    1,    1,    1,    3,    1,    2,    0,    1,    1,    3,
    2,    3,    3,    2,    1,    1,    1,    1,    3,    1,
    1,    2,    4,    3,    5,    4,    3,    3,    4,    4,
    4,    4,    1,    3,    3,    1,    9,    7,    6,    6,
    7,    3,    3,    3,    3,    3,    3,    3,    1,    1,
    2,    1,    2,    1,    1,    2,    1,    1,    4,    1,
    1,    1,    2,    1,    2,    1,    6,    8,    7,    6,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   31,   32,
   33,    0,    0,    9,    0,    0,    7,    8,    0,    0,
    0,    0,   46,   47,   48,   50,   51,   10,    0,    0,
    0,    0,   27,    0,    0,    0,    0,   52,    0,    0,
    4,    0,    5,   35,    0,   15,    0,   13,   14,    0,
    0,   90,   92,   94,   91,    0,    0,    0,    0,    0,
   66,   87,   88,   54,    0,    0,    0,    0,    0,    0,
    0,    0,   49,    0,    0,    3,   11,   34,   28,   86,
    0,   56,   93,   95,    0,    0,    0,    0,    0,   53,
    0,    0,    0,   36,    0,    0,   80,   79,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,   20,    0,
    0,   24,    0,   55,    0,    0,    0,    0,    0,    0,
   64,   65,    0,    0,    0,    0,    0,    0,   84,   82,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   18,    0,   22,   89,    0,    0,    0,    0,
  100,    0,    0,   97,    0,    0,    0,    0,    0,   39,
   78,   83,   81,   70,    0,    0,   69,    0,    0,   23,
    0,   99,    0,    0,    0,    0,   44,    0,    0,    0,
   68,   71,    0,   21,   98,   17,    0,    0,   43,   16,
   40,    0,    0,   12,   67,    0,    0,    0,   26,    0,
   25,
};
short yydgoto[] = {                                       2,
   15,  157,   17,   18,   19,   20,   69,  158,   21,   22,
  111,  112,   33,  159,  160,   23,   24,   25,   26,   27,
   71,   60,   61,   72,   99,  131,   62,   63,
};
short yysindex[] = {                                   -108,
   30,    0,  -18,  -16,  -13,   -6,  -15,    6,    0,    0,
    0, -204, -197,    0,  -56,   58,    0,    0, -182,   -9,
   38,   54,    0,    0,    0,    0,    0,    0,   20,  -41,
   18, -156,    0,   68, -211,  -36,   60,    0,   81,   -7,
    0, -133,    0,    0,   -5,    0, -132,    0,    0, -129,
 -142,    0,    0,    0,    0,   89,   93, -141,   35,  -25,
    0,    0,    0,    0,   67,  -33, -211, -127,   98,  157,
  147,   99,    0,  102, -105,    0,    0,    0,    0,    0,
   81,    0,    0,    0,  108,  -26,   -4,   81,   81,    0,
  -31,   86,  118,    0,   37,  170,    0,    0, -110,   81,
   81,   81,   81,   81,   81,  157,  -95,  -77,    0, -182,
  -76,    0,   42,    0,   81,   81,  -25,   81,   81,  -25,
    0,    0,  125,   64,  -23,   70,   59,   44,    0,    0,
  183,  137,  -12,  -12,  -12,  -12,  -12,  -12,  -32,  157,
  149,   -2,    0, -182,    0,    0,  -25,  -25,  -25,  -25,
    0,  158,  -53,    0,   -8,  162,   58,   83,  -58,    0,
    0,    0,    0,    0,  157,  167,    0,  168, -211,    0,
   11,    0,  192,  196,  120,   44,    0,  206,  207,  -57,
    0,    0,  217,    0,    0,    0,  218,  -58,    0,    0,
    0,  219,  159,    0,    0,   16,  222,  145,    0,  237,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   12,    0,    0,    0,    0,    0,    0,
    0,    0,  290,    0,    0,  169,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  254,    0,
    0,    0,    0,    0,  263,    0,    0,    0,    0,  266,
    0,  318,    0,    0,    0,    0,    0,    0,    0,  278,
   91,    0,    0,    0,    0,    0,    0,  103,    0,  113,
    0,    0,    0,    0,    0,    0,  263,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  123,    0,    0,  133,
    0,    0,    0,    0,   47,    0,    0,    0,    0,    0,
    0,    0,  283,  285,  287,  288,  291,  295,    0,    0,
    0,    0,    0,    0,    0,    0,  143,  153,  329,  339,
    0,    0,    0,    0,    0,    0, -119,    0,  223,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  263,    0,
    0,    0,    0,    0,    0,  224,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  -56,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  334,   57,  -59,  -45,  -27,  -17,  -66, -152,    0,    0,
    0,  240,  302, -144,  181,    0,    0,    0,    0,    0,
  372,  -19,   33,  319,  -88,    0,    0,    0,
};
#define YYTABLESIZE 604
short yytable[] = {                                      57,
   93,   45,  175,   58,   70,   45,   91,   68,   58,  123,
   97,  167,  177,   58,    1,  115,   88,  139,   58,  109,
  116,   89,  153,   30,   98,   28,   35,   92,   38,   32,
   86,  188,   87,   36,   46,   14,  129,  118,   77,   68,
   58,  170,  119,  198,   31,   39,   97,  110,  143,   47,
  130,  168,   40,   47,  184,   35,   47,   16,   41,   14,
   98,   64,   58,    9,   10,   11,  117,  120,   42,   47,
   35,  162,   16,   14,   44,   85,  180,   86,   50,   87,
   97,   48,  146,  144,   86,  163,   87,   14,   85,   85,
   85,   85,  142,   85,   98,  147,  148,   49,  149,  150,
   66,   14,  183,   73,  152,   97,   86,   67,   87,   86,
   90,   87,   86,  154,   87,   75,  174,   83,   84,   98,
  121,  122,   76,   80,   78,   58,  171,   29,   81,   94,
   58,   85,   85,   85,   85,   85,   82,   85,   95,  106,
  197,   68,  107,   96,   96,   96,   96,   96,   45,   96,
   85,  114,   85,   63,   13,   63,   63,   63,  127,  128,
  132,  108,   96,   57,   96,   57,   57,   57,  151,    9,
   10,   11,   63,   58,   63,   58,   58,   58,  140,  141,
  164,  155,   57,   60,   57,   60,   60,   60,  169,   86,
  108,   87,   58,   62,   58,   62,   62,   62,    9,   10,
   11,  172,   60,  173,   60,  176,  105,  178,  104,  179,
  181,  182,   62,  192,   62,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,  185,   56,  165,  166,  186,
   29,   56,   80,   34,  187,   37,   56,    3,    4,  190,
  191,   56,   51,   52,   53,   54,   55,  193,    5,  156,
    6,  194,  195,    7,    8,  199,    9,   10,   11,  200,
   12,    3,    4,   56,   51,   52,   53,   54,   55,   96,
  201,  196,    5,  156,    6,    3,    4,    7,    8,    2,
    9,   10,   11,    6,   12,   56,    5,   29,    6,    3,
    4,    7,    8,   37,    9,   10,   11,  161,   12,   19,
    5,  156,    6,    3,    4,    7,    8,    1,    9,   10,
   11,   30,   12,   74,    5,   75,    6,   77,   76,    7,
    8,   72,    9,   10,   11,   73,   12,   51,   52,   53,
   54,   55,  125,   52,   53,   54,   55,   38,   41,   43,
  145,   79,   85,   85,   85,   85,  189,   74,   56,    0,
    0,    0,    0,   56,   96,   96,   96,   96,    0,   59,
    0,   59,   59,   59,   63,   63,   63,   63,    0,   61,
    0,   61,   61,   61,   57,   57,   57,   57,   59,    0,
   59,    0,    0,    0,   58,   58,   58,   58,   61,    0,
   61,   59,   65,    0,   60,   60,   60,   60,  100,  101,
  102,  103,    0,    4,   62,   62,   62,   62,    0,    0,
    0,    0,    0,    5,    0,    6,    4,    0,    7,    8,
    0,    9,   10,   11,    0,   12,    5,    0,    6,    4,
    0,    7,    8,    0,    9,   10,   11,    0,   12,    5,
    0,    6,  113,    0,    7,    8,    0,    9,   10,   11,
    0,   12,  124,  126,    0,    0,    0,    0,    0,    0,
    0,  133,  134,  135,  136,  137,  138,    0,    0,    0,
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
   59,   59,   59,   59,    0,    0,    0,    0,    0,    0,
   61,   61,   61,   61,
};
short yycheck[] = {                                      41,
   67,   19,  155,   45,   41,  125,   40,   35,   45,   41,
   70,   44,  157,   45,  123,   42,   42,  106,   45,  125,
   47,   47,   46,   40,   70,   44,   40,   61,   44,   46,
   43,  176,   45,   40,   44,   44,   96,   42,   44,   67,
   45,   44,   47,  196,   61,   40,  106,   75,  125,   59,
   96,  140,  257,   59,   44,   44,   59,    1,  256,   44,
  106,   44,   45,  275,  276,  277,   86,   87,  125,   59,
   59,  131,   16,   44,  257,   41,  165,   43,   59,   45,
  140,   44,   41,  111,   43,  131,   45,   44,   42,   43,
   44,   45,  110,   47,  140,  115,  116,   44,  118,  119,
  257,   44,  169,   44,   41,  165,   43,   40,   45,   43,
   44,   45,   43,   44,   45,  123,  125,  259,  260,  165,
   88,   89,  256,  266,  257,   45,  144,  257,   40,  257,
   45,   41,   42,   43,   44,   45,   44,   47,   41,   41,
  125,  169,   41,   41,   42,   43,   44,   45,  268,   47,
   60,   44,   62,   41,  125,   43,   44,   45,   41,  123,
  271,  267,   60,   41,   62,   43,   44,   45,   44,  275,
  276,  277,   60,   41,   62,   43,   44,   45,  274,  257,
   44,  123,   60,   41,   62,   43,   44,   45,   40,   43,
  267,   45,   60,   41,   62,   43,   44,   45,  275,  276,
  277,   44,   60,  257,   62,   44,   60,  125,   62,  268,
   44,   44,   60,  271,   62,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   44,  278,  270,  271,   44,
  257,  278,  266,  257,  125,  261,  278,  256,  257,   44,
   44,  278,  257,  258,  259,  260,  261,   41,  267,  268,
  269,   44,   44,  272,  273,   44,  275,  276,  277,  125,
  279,  256,  257,  278,  257,  258,  259,  260,  261,  123,
   44,  123,  267,  268,  269,  256,  257,  272,  273,    0,
  275,  276,  277,  125,  279,  278,  267,   44,  269,  256,
  257,  272,  273,   41,  275,  276,  277,  125,  279,   44,
  267,  268,  269,  256,  257,  272,  273,    0,  275,  276,
  277,   44,  279,   41,  267,   41,  269,   41,   41,  272,
  273,   41,  275,  276,  277,   41,  279,  257,  258,  259,
  260,  261,  257,  258,  259,  260,  261,  125,  125,   16,
  111,   50,  262,  263,  264,  265,  176,   39,  278,   -1,
   -1,   -1,   -1,  278,  262,  263,  264,  265,   -1,   41,
   -1,   43,   44,   45,  262,  263,  264,  265,   -1,   41,
   -1,   43,   44,   45,  262,  263,  264,  265,   60,   -1,
   62,   -1,   -1,   -1,  262,  263,  264,  265,   60,   -1,
   62,   30,   31,   -1,  262,  263,  264,  265,  262,  263,
  264,  265,   -1,  257,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,  267,   -1,  269,  257,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  267,   -1,  269,  257,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  267,
   -1,  269,   81,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,   91,   92,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  100,  101,  102,  103,  104,  105,   -1,   -1,   -1,
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
  262,  263,  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,
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
#line 212 "./gramaticaComCHZExtendida.y"
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
#line 467 "y.tab.c"
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
case 13:
#line 75 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase");}
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
{ yyPrintInLine("Se detectó un bloque de control IF");}
break;
case 69:
#line 162 "./gramaticaComCHZExtendida.y"
{yyerror("Falta de END_IF en el bloque de control IF");}
break;
case 70:
#line 163 "./gramaticaComCHZExtendida.y"
{yyerror("Falta de condición en el bloque de control IF");}
break;
case 71:
#line 166 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un WHILE-DO");}
break;
case 80:
#line 179 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 83:
#line 184 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 84:
#line 185 "./gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 92:
#line 198 "./gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 93:
#line 199 "./gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 96:
#line 202 "./gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 97:
#line 205 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 98:
#line 206 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 99:
#line 207 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 100:
#line 208 "./gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 787 "y.tab.c"
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
