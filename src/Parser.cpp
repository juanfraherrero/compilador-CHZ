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
   27,   28,   28,   28,   28,   28,   20,   20,   20,
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
    1,    1,    2,    1,    2,    1,    6,    8,    7,
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
   64,   65,    0,    0,    0,    0,    0,   84,   82,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,    0,   22,   89,    0,    0,    0,    0,    0,
    0,   97,    0,    0,    0,    0,    0,   39,   78,   83,
   81,   70,    0,    0,   69,    0,    0,   23,    0,   99,
    0,    0,    0,    0,   44,    0,    0,    0,   68,   71,
    0,   21,   98,   17,    0,    0,   43,   16,   40,    0,
    0,   12,   67,    0,    0,    0,   26,    0,   25,
};
short yydgoto[] = {                                       2,
   15,  155,   17,   18,   19,   20,   69,  156,   21,   22,
  111,  112,   33,  157,  158,   23,   24,   25,   26,   27,
   71,   60,   61,   72,   99,  130,   62,   63,
};
short yysindex[] = {                                   -111,
   20,    0,   19,  -16,  -11,  -32,  -13,    4,    0,    0,
    0, -185, -183,    0,  -49,   48,    0,    0, -177,  -12,
   49,   53,    0,    0,    0,    0,    0,    0,   40,  -41,
    8, -155,    0,   64, -106,  -36,   61,    0,   71,  -15,
    0, -136,    0,    0,   -1,    0, -130,    0,    0, -125,
 -124,    0,    0,    0,    0,  110,  107, -204,   55,   37,
    0,    0,    0,    0,  136,  -19, -106,  -98,  131,  157,
  147,  141,    0,  148, -115,    0,    0,    0,    0,    0,
   71,    0,    0,    0,  158,  -31,  -25,   71,   71,    0,
 -106,   76,  163,    0,   83,  170,    0,    0,  -63,   71,
   71,   71,   71,   71,   71,  157,  -60,  -17,    0, -177,
  -76,    0,   74,    0,   71,   71,   37,   71,   71,   37,
    0,    0,  190,  -23,  167,  129,   34,    0,    0,  183,
  212,   38,   38,   38,   38,   38,   38,  -26,  157,  220,
   15,    0, -177,    0,    0,   37,   37,   37,   37,  226,
    7,    0,  -18,  227,   48,  159,   26,    0,    0,    0,
    0,    0,  157,  228,    0,  244, -106,    0,   16,    0,
  254,  256,  187,   34,    0,  270,  272,   47,    0,    0,
  278,    0,    0,    0,  282,   26,    0,    0,    0,  294,
  199,    0,    0,    6,  295,  215,    0,  297,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   23,    0,    0,    0,    0,    0,    0,
    0,    0,  342,    0,    0,  222,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  304,    0,
    0,    0,    0,    0,  309,    0,    0,    0,    0,  307,
    0,  352,    0,    0,    0,    0,    0,    0,    0,  315,
   81,    0,    0,    0,    0,    0,    0,   93,    0,  103,
    0,    0,    0,    0,    0,    0,  309,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  309,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  113,    0,    0,  123,
    0,    0,    0,   44,    0,    0,    0,    0,    0,    0,
    0,  312,  320,  328,  329,  330,  331,    0,    0,    0,
    0,    0,    0,    0,    0,  133,  143,  153,  319,    0,
    0,    0,    0,    0, -119,    0,  248,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  309,    0,    0,    0,
    0,    0,    0,  249,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  -49,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  364,   18,  -68,  -45,  -34,   -4,  -64, -146,    0,    0,
    0,  271,  333, -120,  210,    0,    0,    0,    0,    0,
    9,  -50,   41,  350,  -93,    0,    0,    0,
};
#define YYTABLESIZE 584
short yytable[] = {                                      57,
   68,   97,   93,   58,   70,   45,  173,   36,   58,  109,
  115,    1,  138,   58,   45,  116,  118,  165,   16,   58,
   91,  119,  151,   30,   98,   14,  123,  128,   35,   32,
   38,   46,   68,   16,  175,  117,  120,   97,   59,   65,
  110,   92,   77,   39,   31,  166,   47,  196,  142,   14,
  129,   64,   58,  186,   83,   84,   68,   47,  168,  182,
   98,  160,   28,   14,  146,  147,   35,  148,  149,  178,
   97,   40,   41,   47,   47,   42,  143,   14,   88,   44,
   86,   35,   87,   89,  161,   85,   85,   85,   85,  113,
   85,   14,   48,   98,   97,   85,   49,   86,   50,   87,
  125,   66,  181,   67,   73,  141,  172,   75,  132,  133,
  134,  135,  136,  137,  145,   58,   86,   98,   87,   76,
   58,   85,   85,   85,   85,   85,   78,   85,  121,  122,
  195,   29,   68,   96,   96,   96,   96,   96,  169,   96,
   85,   80,   85,   63,   13,   63,   63,   63,   45,   81,
   82,  108,   96,   57,   96,   57,   57,   57,   94,    9,
   10,   11,   63,   58,   63,   58,   58,   58,    9,   10,
   11,   95,   57,   60,   57,   60,   60,   60,   86,   90,
   87,  106,   58,   62,   58,   62,   62,   62,  107,   86,
  108,   87,   60,   59,   60,   59,   59,   59,    9,   10,
   11,  114,   62,  126,   62,  127,  105,  131,  104,   86,
  152,   87,   59,  139,   59,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,   51,   52,   53,   54,   55,
  150,   51,   52,   53,   54,   55,   56,    3,    4,  140,
   29,   56,   80,  163,  164,   34,   56,   37,    5,  154,
    6,  153,   56,    7,    8,  162,    9,   10,   11,  167,
   12,    3,    4,  171,   51,   52,   53,   54,   55,  170,
  174,  179,    5,  154,    6,    3,    4,    7,    8,   96,
    9,   10,   11,  176,   12,   56,    5,  180,    6,    3,
    4,    7,    8,  177,    9,   10,   11,  183,   12,  184,
    5,  154,    6,    3,    4,    7,    8,  159,    9,   10,
   11,  185,   12,  188,    5,  189,    6,  190,  191,    7,
    8,  194,    9,   10,   11,  192,   12,   51,   52,   53,
   54,   55,  124,   52,   53,   54,   55,  193,  197,  198,
  199,    2,   85,   85,   85,   85,    6,   29,   56,   37,
   19,    1,   74,   56,   96,   96,   96,   96,   30,   61,
   75,   61,   61,   61,   63,   63,   63,   63,   77,   76,
   72,   73,   38,   41,   57,   57,   57,   57,   61,   43,
   61,  144,   79,  187,   58,   58,   58,   58,   74,    0,
    0,    0,    0,    0,   60,   60,   60,   60,    0,    0,
    0,    0,    0,    0,   62,   62,   62,   62,  100,  101,
  102,  103,    0,    4,   59,   59,   59,   59,    0,    0,
    0,    0,    0,    5,    0,    6,    4,    0,    7,    8,
    0,    9,   10,   11,    0,   12,    5,    0,    6,    4,
    0,    7,    8,    0,    9,   10,   11,    0,   12,    5,
    0,    6,    0,    0,    7,    8,    0,    9,   10,   11,
    0,   12,    0,    0,    0,    0,    0,    0,    0,    0,
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
   61,   61,   61,   61,
};
short yycheck[] = {                                      41,
   35,   70,   67,   45,   41,  125,  153,   40,   45,  125,
   42,  123,  106,   45,   19,   47,   42,   44,    1,   45,
   40,   47,   46,   40,   70,   44,   91,   96,   40,   46,
   44,   44,   67,   16,  155,   86,   87,  106,   30,   31,
   75,   61,   44,   40,   61,  139,   59,  194,  125,   44,
   96,   44,   45,  174,  259,  260,   91,   59,   44,   44,
  106,  130,   44,   44,  115,  116,   44,  118,  119,  163,
  139,  257,  256,   59,   59,  125,  111,   44,   42,  257,
   43,   59,   45,   47,  130,   42,   43,   44,   45,   81,
   47,   44,   44,  139,  163,   41,   44,   43,   59,   45,
   92,  257,  167,   40,   44,  110,  125,  123,  100,  101,
  102,  103,  104,  105,   41,   45,   43,  163,   45,  256,
   45,   41,   42,   43,   44,   45,  257,   47,   88,   89,
  125,  257,  167,   41,   42,   43,   44,   45,  143,   47,
   60,  266,   62,   41,  125,   43,   44,   45,  268,   40,
   44,  267,   60,   41,   62,   43,   44,   45,  257,  275,
  276,  277,   60,   41,   62,   43,   44,   45,  275,  276,
  277,   41,   60,   41,   62,   43,   44,   45,   43,   44,
   45,   41,   60,   41,   62,   43,   44,   45,   41,   43,
  267,   45,   60,   41,   62,   43,   44,   45,  275,  276,
  277,   44,   60,   41,   62,  123,   60,  271,   62,   43,
   44,   45,   60,  274,   62,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  258,  259,  260,  261,
   41,  257,  258,  259,  260,  261,  278,  256,  257,  257,
  257,  278,  266,  270,  271,  257,  278,  261,  267,  268,
  269,  123,  278,  272,  273,   44,  275,  276,  277,   40,
  279,  256,  257,  257,  257,  258,  259,  260,  261,   44,
   44,   44,  267,  268,  269,  256,  257,  272,  273,  123,
  275,  276,  277,  125,  279,  278,  267,   44,  269,  256,
  257,  272,  273,  268,  275,  276,  277,   44,  279,   44,
  267,  268,  269,  256,  257,  272,  273,  125,  275,  276,
  277,  125,  279,   44,  267,   44,  269,  271,   41,  272,
  273,  123,  275,  276,  277,   44,  279,  257,  258,  259,
  260,  261,  257,  258,  259,  260,  261,   44,   44,  125,
   44,    0,  262,  263,  264,  265,  125,   44,  278,   41,
   44,    0,   41,  278,  262,  263,  264,  265,   44,   41,
   41,   43,   44,   45,  262,  263,  264,  265,   41,   41,
   41,   41,  125,  125,  262,  263,  264,  265,   60,   16,
   62,  111,   50,  174,  262,  263,  264,  265,   39,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,  262,  263,
  264,  265,   -1,  257,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,  267,   -1,  269,  257,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  267,   -1,  269,  257,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  267,
   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
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
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' parametro ')' ','",
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
#line 211 "./gramaticaComCHZExtendida.y"
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
#line 459 "y.tab.c"
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
#line 775 "y.tab.c"
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
