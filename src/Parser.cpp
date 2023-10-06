#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "gramaticaComCHZExtendida.y"

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
    0,    0,    0,   55,    0,    0,    0,    0,    0,    0,
   64,   65,    0,    0,    0,    0,    0,   84,   82,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   18,   22,   89,    0,    0,    0,    0,    0,    0,
   97,    0,    0,    0,    0,    0,   39,   78,   83,   81,
   70,    0,    0,   69,    0,    0,    0,   99,    0,    0,
    0,    0,   44,    0,    0,    0,   68,   71,    0,   21,
   98,   17,    0,    0,   43,   16,   40,    0,    0,   12,
   67,    0,    0,    0,   26,    0,   25,
};
short yydgoto[] = {                                       2,
   15,  154,   17,   18,   19,   20,   69,  155,   21,   22,
  111,  112,   33,  156,  157,   23,   24,   25,   26,   27,
   71,   60,   61,   72,   99,  130,   62,   63,
};
short yysindex[] = {                                   -102,
   20,    0,   -9,  -16,  -11,    1,  -13,    4,    0,    0,
    0, -199, -191,    0,  -48,   48,    0,    0, -173,  -17,
   43,   46,    0,    0,    0,    0,    0,    0,   39,  -41,
    8, -166,    0,   65, -194,  -36,   57,    0,   71,    7,
    0, -144,    0,    0,  -12,    0, -130,    0,    0, -128,
 -134,    0,    0,    0,    0,   99,   89, -211,   52,   32,
    0,    0,    0,    0,   75,  -27, -194, -107,  101,  157,
  147,  110,    0,  118, -115,    0,    0,    0,    0,    0,
   71,    0,    0,    0,  125,  -31,  -25,   71,   71,    0,
 -194,   76,  129,    0,   59,  170,    0,    0,  -82,   71,
   71,   71,   71,   71,   71,  157,  -83,  -58,    0, -173,
   77, -207,   61,    0,   71,   71,   32,   71,   71,   32,
    0,    0,  159,  -23,  136,   78,   34,    0,    0,  183,
  160,   30,   30,   30,   30,   30,   30,  -26,  157,  166,
   -5,    0,    0,    0,   32,   32,   32,   32,  164,  -47,
    0,  -18,  167,   48,   87,  -54,    0,    0,    0,    0,
    0,  157,  187,    0,  196, -194, -207,    0,  208,  212,
  135,   34,    0,  220,  226,   13,    0,    0,  230,    0,
    0,    0,  228,  -54,    0,    0,    0,  244,  171,    0,
    0,    6,  254,  175,    0,  268,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    2,    0,    0,    0,    0,    0,    0,
    0,    0,  314,    0,    0,  191,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  274,    0,
    0,    0,    0,    0,  278,    0,    0,    0,    0,  282,
    0,  322,    0,    0,    0,    0,    0,    0,    0,  294,
   81,    0,    0,    0,    0,    0,    0,   93,    0,  103,
    0,    0,    0,    0,    0,    0,  278,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  278,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  214,    0,    0,    0,    0,  113,    0,    0,  123,
    0,    0,    0,   66,    0,    0,    0,    0,    0,    0,
    0,  299,  300,  301,  306,  307,  309,    0,    0,    0,
    0,    0,    0,    0,  133,  143,  153,  319,    0,    0,
    0,    0,    0, -119,    0,  227,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  278,  234,    0,    0,    0,
    0,  236,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  -48,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  335,   50,  -68,  -63,    5,   -7,  -66, -137,    0,    0,
 -104,    0,  303, -135,  197,    0,    0,    0,    0,    0,
  372,  -30,   26,  331, -103,    0,    0,    0,
};
#define YYTABLESIZE 584
short yytable[] = {                                      57,
   93,   97,  138,   58,   70,   45,   98,  143,   58,  109,
  115,   45,   91,   58,  171,  116,  118,  164,  173,   58,
    1,  119,  150,   30,  123,   14,   46,  128,   35,   32,
   38,   77,  129,   92,   28,  165,  184,   97,  167,   68,
   36,   47,   98,   39,   31,   35,   47,   83,   84,   14,
   16,   64,   58,   47,  194,  117,  120,   40,  176,  108,
   35,  159,  180,   14,   41,   16,  160,    9,   10,   11,
   97,   68,   86,   88,   87,   98,   42,   14,   89,  110,
    9,   10,   11,   44,  145,  146,   48,  147,  148,   49,
   66,   14,   85,   97,   86,   68,   87,   50,   98,  179,
   73,  144,  141,   86,   67,   87,  170,   85,   85,   85,
   85,   76,   85,  121,  122,   58,  110,   86,   90,   87,
   58,   85,   85,   85,   85,   85,   78,   85,   29,   75,
  193,   80,   82,   96,   96,   96,   96,   96,   81,   96,
   85,   95,   85,   63,   13,   63,   63,   63,   45,   94,
  106,  108,   96,   57,   96,   57,   57,   57,  107,    9,
   10,   11,   63,   58,   63,   58,   58,   58,  114,  126,
   68,  110,   57,   60,   57,   60,   60,   60,   86,  151,
   87,  127,   58,   62,   58,   62,   62,   62,  131,   86,
  139,   87,   60,   59,   60,   59,   59,   59,  140,  149,
  152,  142,   62,  161,   62,  166,  105,  168,  104,  169,
  172,  174,   59,  175,   59,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,   51,   52,   53,   54,   55,
  177,   51,   52,   53,   54,   55,   56,    3,    4,  178,
   29,   56,   80,  162,  163,   34,   56,   37,    5,  153,
    6,  181,   56,    7,    8,  182,    9,   10,   11,  183,
   12,    3,    4,  186,   51,   52,   53,   54,   55,  187,
  189,  190,    5,  153,    6,    3,    4,    7,    8,   96,
    9,   10,   11,  188,   12,   56,    5,  191,    6,    3,
    4,    7,    8,  192,    9,   10,   11,  195,   12,  196,
    5,  153,    6,    3,    4,    7,    8,  158,    9,   10,
   11,  197,   12,    2,    5,    6,    6,   29,   37,    7,
    8,    1,    9,   10,   11,   19,   12,   51,   52,   53,
   54,   55,  124,   52,   53,   54,   55,   30,   24,   74,
   75,   77,   85,   85,   85,   85,   76,   72,   56,   73,
   43,   38,   79,   56,   96,   96,   96,   96,   23,   61,
   41,   61,   61,   61,   63,   63,   63,   63,  185,   74,
    0,    0,    0,    0,   57,   57,   57,   57,   61,    0,
   61,    0,    0,    0,   58,   58,   58,   58,    0,    0,
    0,    0,    0,    0,   60,   60,   60,   60,    0,    0,
    0,   59,   65,    0,   62,   62,   62,   62,  100,  101,
  102,  103,    0,    4,   59,   59,   59,   59,    0,    0,
    0,    0,    0,    5,    0,    6,    4,    0,    7,    8,
    0,    9,   10,   11,    0,   12,    5,    0,    6,    4,
    0,    7,    8,    0,    9,   10,   11,    0,   12,    5,
    0,    6,  113,    0,    7,    8,    0,    9,   10,   11,
    0,   12,    0,  125,    0,    0,    0,    0,    0,    0,
    0,  132,  133,  134,  135,  136,  137,    0,    0,    0,
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
   67,   70,  106,   45,   41,  125,   70,  112,   45,  125,
   42,   19,   40,   45,  152,   47,   42,   44,  154,   45,
  123,   47,   46,   40,   91,   44,   44,   96,   40,   46,
   44,   44,   96,   61,   44,  139,  172,  106,   44,   35,
   40,   59,  106,   40,   61,   44,   59,  259,  260,   44,
    1,   44,   45,   59,  192,   86,   87,  257,  162,  267,
   59,  130,  167,   44,  256,   16,  130,  275,  276,  277,
  139,   67,   43,   42,   45,  139,  125,   44,   47,   75,
  275,  276,  277,  257,  115,  116,   44,  118,  119,   44,
  257,   44,   41,  162,   43,   91,   45,   59,  162,  166,
   44,   41,  110,   43,   40,   45,  125,   42,   43,   44,
   45,  256,   47,   88,   89,   45,  112,   43,   44,   45,
   45,   41,   42,   43,   44,   45,  257,   47,  257,  123,
  125,  266,   44,   41,   42,   43,   44,   45,   40,   47,
   60,   41,   62,   41,  125,   43,   44,   45,  268,  257,
   41,  267,   60,   41,   62,   43,   44,   45,   41,  275,
  276,  277,   60,   41,   62,   43,   44,   45,   44,   41,
  166,  167,   60,   41,   62,   43,   44,   45,   43,   44,
   45,  123,   60,   41,   62,   43,   44,   45,  271,   43,
  274,   45,   60,   41,   62,   43,   44,   45,  257,   41,
  123,  125,   60,   44,   62,   40,   60,   44,   62,  257,
   44,  125,   60,  268,   62,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  258,  259,  260,  261,
   44,  257,  258,  259,  260,  261,  278,  256,  257,   44,
  257,  278,  266,  270,  271,  257,  278,  261,  267,  268,
  269,   44,  278,  272,  273,   44,  275,  276,  277,  125,
  279,  256,  257,   44,  257,  258,  259,  260,  261,   44,
   41,   44,  267,  268,  269,  256,  257,  272,  273,  123,
  275,  276,  277,  271,  279,  278,  267,   44,  269,  256,
  257,  272,  273,  123,  275,  276,  277,   44,  279,  125,
  267,  268,  269,  256,  257,  272,  273,  125,  275,  276,
  277,   44,  279,    0,  267,  125,  269,   44,   41,  272,
  273,    0,  275,  276,  277,   44,  279,  257,  258,  259,
  260,  261,  257,  258,  259,  260,  261,   44,  125,   41,
   41,   41,  262,  263,  264,  265,   41,   41,  278,   41,
   16,  125,   50,  278,  262,  263,  264,  265,  125,   41,
  125,   43,   44,   45,  262,  263,  264,  265,  172,   39,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   60,   -1,
   62,   -1,   -1,   -1,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   -1,   -1,
   -1,   30,   31,   -1,  262,  263,  264,  265,  262,  263,
  264,  265,   -1,  257,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,  267,   -1,  269,  257,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  267,   -1,  269,  257,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,  267,
   -1,  269,   81,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,   -1,   92,   -1,   -1,   -1,   -1,   -1,   -1,
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
"lista_atributos_y_metodos : tipo lista_de_variables ',' lista_atributos_y_metodos",
"lista_atributos_y_metodos : metodo lista_atributos_y_metodos",
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
#line 211 "gramaticaComCHZExtendida.y"
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
#line 59 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un programa");}
break;
case 2:
#line 60 "gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido");}
break;
case 3:
#line 61 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 4:
#line 62 "gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 9:
#line 69 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia vacía"); }
break;
case 10:
#line 70 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 11:
#line 73 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 12:
#line 74 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 13:
#line 75 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 14:
#line 76 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 15:
#line 77 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de un tipo en la declaración de variables"); }
break;
case 16:
#line 78 "gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 17:
#line 79 "gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 20:
#line 85 "gramaticaComCHZExtendida.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 26:
#line 95 "gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 30:
#line 103 "gramaticaComCHZExtendida.y"
{ yyerror("Falta identificador en la declaración de un objeto"); }
break;
case 38:
#line 117 "gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 42:
#line 122 "gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 43:
#line 123 "gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 47:
#line 129 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó invación a función");}
break;
case 52:
#line 134 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 53:
#line 137 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó asignación");}
break;
case 54:
#line 138 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 59:
#line 148 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 60:
#line 149 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 61:
#line 150 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 62:
#line 151 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 67:
#line 160 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF-ELSE");}
break;
case 68:
#line 161 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un bloque de control IF");}
break;
case 69:
#line 162 "gramaticaComCHZExtendida.y"
{yyerror("Falta de END_IF en el bloque de control IF");}
break;
case 70:
#line 163 "gramaticaComCHZExtendida.y"
{yyerror("Falta de condición en el bloque de control IF");}
break;
case 71:
#line 166 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un WHILE-DO");}
break;
case 80:
#line 179 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 83:
#line 184 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 84:
#line 185 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 92:
#line 198 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 93:
#line 199 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 96:
#line 202 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 97:
#line 205 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 98:
#line 206 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 99:
#line 207 "gramaticaComCHZExtendida.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 763 "y.tab.c"
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
