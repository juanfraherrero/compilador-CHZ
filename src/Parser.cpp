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


void yyerror(string s){
    cerr << "\033[31m" << "Linea: " << lineNumber << "-> Error: " << s <<"\033[0m"<< endl;
};
void yywarning(string s){
    cerr << "\033[33m" << "Linea: " << lineNumber << "-> Warning: " << s <<"\033[0m"<< endl;
};

#line 35 "y.tab.c"
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
    3,    3,    3,    3,    3,    3,    3,    9,    9,   11,
   11,   12,   12,   13,   10,   14,   14,   14,    5,    5,
    5,    6,    6,    7,    7,    8,    8,   16,   16,   16,
   16,   15,   15,    4,    4,    4,    4,    4,    4,    4,
   17,   17,   18,   18,   22,   22,   22,   22,   22,   22,
   22,   23,   23,   23,   19,   19,   20,   25,   25,   25,
   25,   25,   25,   26,   26,   26,   27,   27,   27,   27,
   24,   24,   24,   24,   24,   28,   28,   29,   29,   29,
   29,   29,   21,   21,   21,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    1,    1,    1,    2,
    3,    9,    2,    2,    2,    8,    8,    6,    2,    4,
    0,    2,    0,    9,    2,    3,    1,    2,    1,    1,
    1,    3,    1,    2,    0,    1,    1,    3,    2,    3,
    3,    2,    1,    1,    1,    1,    3,    1,    1,    2,
    4,    3,    5,    4,    3,    3,    4,    4,    4,    4,
    1,    3,    3,    1,    9,    7,    7,    3,    3,    3,
    3,    3,    3,    3,    1,    1,    2,    1,    2,    1,
    1,    2,    1,    1,    4,    1,    1,    1,    2,    1,
    2,    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   29,   30,
   31,    0,    0,    9,    0,    0,    7,    8,    0,    0,
    0,    0,   44,   45,   46,   48,   49,   10,    0,    0,
    0,    0,   25,    0,    0,    0,    0,   50,    0,    0,
    4,    0,    5,   33,    0,   15,    0,   13,   14,    0,
    0,   86,   88,   90,   87,    0,    0,    0,    0,    0,
   64,   83,   84,   52,    0,    0,    0,    0,    0,    0,
    0,   47,    0,    0,    3,   11,   32,   26,   82,    0,
   54,   89,   91,    0,    0,    0,    0,    0,   51,    0,
    0,    0,   34,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   53,    0,    0,    0,    0,
    0,    0,   62,   63,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   76,   75,    0,    0,
    0,    0,    0,    0,   85,    0,    0,    0,    0,    0,
    0,   93,    0,    0,    0,    0,    0,   37,   80,   78,
    0,    0,    0,    0,    0,    0,   18,   22,   95,    0,
    0,    0,    0,   42,    0,    0,   74,   79,   77,    0,
   66,   67,   20,    0,   94,   17,    0,    0,   41,   16,
   38,    0,    0,   12,   65,    0,    0,    0,    0,   24,
};
short yydgoto[] = {                                       2,
   15,  145,   17,   18,   19,   20,   69,  146,   21,   22,
  104,  133,  134,   33,  147,  148,   23,   24,   25,   26,
   27,   70,   60,   61,   71,  129,  151,   62,   63,
};
short yysindex[] = {                                    -97,
    1,    0,  -14,  -21,  -18,  -37,  -20,   39,    0,    0,
    0, -175, -165,    0,  -24,   29,    0,    0, -148,  -15,
   78,   80,    0,    0,    0,    0,    0,    0,   69,  -41,
    3, -115,    0,  112, -177,   52,  110,    0,   52,   33,
    0,  -98,    0,    0,  -13,    0,  -96,    0,    0,  -93,
 -107,    0,    0,    0,    0,  123,  133, -217,   42,   34,
    0,    0,    0,    0,  168,  -27, -177,  -76,  142,  139,
  145,    0,  148, -177,    0,    0,    0,    0,    0,   52,
    0,    0,    0,  147,  -36,  -30,   52,   52,    0, -177,
   58,  152,    0,   71,   52,   52,   52,   52,   52,   52,
  -69,  -78,  -55,  -62,   86,    0,   52,   52,   34,   52,
   52,   34,    0,    0,  173,  -28,  222,   92,   15,   32,
   32,   32,   32,   32,   32, -183,    0,    0, -215,  -69,
  165,  -31,  107,  -62,    0,   34,   34,   34,   34,  191,
  -17,    0,  -23,  199,   29,  122,   -9,    0,    0,    0,
  150,  -69,  207,  211, -177,  229,    0,    0,    0,  235,
  245,  170,   15,    0,  249,  253,    0,    0,    0,   28,
    0,    0,    0, -177,    0,    0,  256,   -9,    0,    0,
    0,  259,  266,    0,    0,  197,   15,  189,  277,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,   19,    0,    0,    0,    0,    0,    0,
    0,    0,  322,    0,    0,  198,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  280,    0,
    0,    0,    0,    0,  288,    0,    0,    0,    0,  287,
    0,  345,    0,    0,    0,    0,    0,    0,    0,  -14,
   63,    0,    0,    0,    0,    0,    0,   70,    0,   75,
    0,    0,    0,    0,    0,    0,  288,    0,    0,    0,
    0,    0,    0, -120,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  288,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  223,    0,    0,    0,    0,   95,    0,
    0,  100,    0,    0,    0,  299,    0,    0,    0,  306,
  308,  309,  310,  311,  312,    0,    0,    0,    0,    0,
    0,    0,    0,  223,    0,  105,  125,  130,  135,    0,
    0,    0,    0,    0, -117,    0,  230,    0,    0,    0,
    0,    0,    0,    0, -120,    0,    0,    0,    0,    0,
    0,    0,  231,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  288,    0,    0,    0,  236,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  338,   79,  -94,  -91,   -2,  347,  -53, -123,    0,    0,
  216,  238,    0,  323, -122,  212,    0,    0,    0,    0,
    0,  -29,  -58,   46,  335, -114,    0,    0,    0,
};
#define YYTABLESIZE 429
short yytable[] = {                                      57,
   59,   65,   36,   58,   21,  107,  127,   43,   58,  128,
  108,  110,   90,   92,   58,  154,  111,  141,   30,  162,
   14,   35,  164,   38,   32,    1,  109,  112,   46,   28,
   76,  149,   68,   91,  150,  127,  115,  170,  128,   31,
  178,   82,   83,   47,   14,   47,   64,   58,  136,  137,
  105,  138,  139,  126,  152,  153,  168,  127,   14,  169,
  128,  117,   33,  188,   68,  120,  121,  122,  123,  124,
  125,  103,   14,    4,   85,   87,   86,   33,   39,   16,
   88,   40,   84,    5,   85,    6,   86,   68,    7,    8,
   41,    9,   10,   11,   16,   12,   58,    9,   10,   11,
   42,  161,   58,   81,   81,   81,   81,   81,   44,   81,
   92,   92,   92,   92,   92,   61,   92,   61,   61,   61,
  183,   48,   81,   49,   81,   13,  135,   50,   85,   92,
   86,   92,  113,  114,   61,   55,   61,   55,   55,   55,
   56,   66,   56,   56,   56,   58,   21,   58,   58,   58,
   43,   67,  103,   72,   55,   74,   55,   75,   79,   56,
   77,   56,   80,   29,   58,   60,   58,   60,   60,   60,
   57,   68,   57,   57,   57,   59,   81,   59,   59,   59,
   93,   85,   94,   86,   60,  101,   60,    4,  102,   57,
  106,   57,  118,  119,   59,  130,   59,    5,  100,    6,
   99,  131,    7,    8,  132,    9,   10,   11,  155,   12,
   85,   89,   86,  140,  143,   51,   52,   53,   54,   55,
   51,   52,   53,   54,   55,  156,   51,   52,   53,   54,
   55,  157,    3,    4,  159,   29,   56,   79,   34,  160,
   37,   56,  163,    5,  144,    6,  165,   56,    7,    8,
  171,    9,   10,   11,  172,   12,    3,    4,  166,   51,
   52,   53,   54,   55,   85,  142,   86,    5,  174,    6,
    3,    4,    7,    8,  167,    9,   10,   11,  175,   12,
   56,    5,  144,    6,    3,    4,    7,    8,  176,    9,
   10,   11,  180,   12,  177,    5,  181,    6,  182,  184,
    7,    8,  185,    9,   10,   11,  186,   12,   51,   52,
   53,   54,   55,  189,  116,   52,   53,   54,   55,  187,
  190,    2,    6,   27,   81,   81,   81,   81,   35,   56,
   19,   92,   92,   92,   92,   56,   61,   61,   61,   61,
   81,   81,   81,   81,    1,   81,   70,   23,   71,   73,
   72,   68,   69,   43,   36,   39,   55,   55,   55,   55,
   40,   56,   56,   56,   56,   45,   58,   58,   58,   58,
  173,  158,   78,   73,  179,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   60,   60,   60,   60,
    0,   57,   57,   57,   57,    0,   59,   59,   59,   59,
   95,   96,   97,   98,    0,    0,    4,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    5,    0,    6,    0,
    0,    7,    8,    0,    9,   10,   11,    0,   12,
};
short yycheck[] = {                                      41,
   30,   31,   40,   45,  125,   42,  101,  125,   45,  101,
   47,   42,   40,   67,   45,  130,   47,   46,   40,  143,
   44,   40,  145,   44,   46,  123,   85,   86,   44,   44,
   44,  126,   35,   61,  126,  130,   90,  152,  130,   61,
  163,  259,  260,   59,   44,   59,   44,   45,  107,  108,
   80,  110,  111,  123,  270,  271,  151,  152,   44,  151,
  152,   91,   44,  187,   67,   95,   96,   97,   98,   99,
  100,   74,   44,  257,   43,   42,   45,   59,   40,    1,
   47,  257,   41,  267,   43,  269,   45,   90,  272,  273,
  256,  275,  276,  277,   16,  279,   45,  275,  276,  277,
  125,  125,   45,   41,   42,   43,   44,   45,  257,   47,
   41,   42,   43,   44,   45,   41,   47,   43,   44,   45,
  174,   44,   60,   44,   62,  125,   41,   59,   43,   60,
   45,   62,   87,   88,   60,   41,   62,   43,   44,   45,
   41,  257,   43,   44,   45,   41,  267,   43,   44,   45,
  268,   40,  155,   44,   60,  123,   62,  256,  266,   60,
  257,   62,   40,  257,   60,   41,   62,   43,   44,   45,
   41,  174,   43,   44,   45,   41,   44,   43,   44,   45,
  257,   43,   41,   45,   60,   41,   62,  257,   41,   60,
   44,   62,   41,  123,   60,  274,   62,  267,   60,  269,
   62,  257,  272,  273,  267,  275,  276,  277,   44,  279,
   43,   44,   45,   41,  123,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  257,  258,  259,  260,
  261,  125,  256,  257,   44,  257,  278,  266,  257,  257,
  261,  278,   44,  267,  268,  269,  125,  278,  272,  273,
   44,  275,  276,  277,   44,  279,  256,  257,  268,  257,
  258,  259,  260,  261,   43,   44,   45,  267,   40,  269,
  256,  257,  272,  273,  125,  275,  276,  277,   44,  279,
  278,  267,  268,  269,  256,  257,  272,  273,   44,  275,
  276,  277,   44,  279,  125,  267,   44,  269,  271,   44,
  272,  273,   44,  275,  276,  277,   41,  279,  257,  258,
  259,  260,  261,  125,  257,  258,  259,  260,  261,  123,
   44,    0,  125,   44,  262,  263,  264,  265,   41,  278,
   44,  262,  263,  264,  265,  278,  262,  263,  264,  265,
   42,   43,   44,   45,    0,   47,   41,  125,   41,   41,
   41,   41,   41,   16,  125,  125,  262,  263,  264,  265,
  125,  262,  263,  264,  265,   19,  262,  263,  264,  265,
  155,  134,   50,   39,  163,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
   -1,  262,  263,  264,  265,   -1,  262,  263,  264,  265,
  262,  263,  264,  265,   -1,   -1,  257,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,   -1,
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
"declaracion_clase : CLASS IDENTIFICADOR '{' lista_de_atributos lista_de_metodos '}'",
"declaracion_clase : CLASS IDENTIFICADOR",
"lista_de_atributos : tipo IDENTIFICADOR ',' lista_de_atributos",
"lista_de_atributos :",
"lista_de_metodos : metodo lista_de_metodos",
"lista_de_metodos :",
"metodo : VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','",
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
#line 209 "gramaticaComCHZExtendida.y"
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
#line 417 "y.tab.c"
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
case 2:
#line 57 "gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido");}
break;
case 3:
#line 58 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 4:
#line 59 "gramaticaComCHZExtendida.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 7:
#line 64 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia declarativa " << endl;}
break;
case 8:
#line 65 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia ejecutable " << endl;}
break;
case 9:
#line 66 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia vacía"); }
break;
case 10:
#line 67 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 12:
#line 71 "gramaticaComCHZExtendida.y"
{cout << "\033[33mSe detectó una función\033[0m" << endl;}
break;
case 15:
#line 74 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de un tipo en la declaración de variables"); }
break;
case 16:
#line 75 "gramaticaComCHZExtendida.y"
{cout << "\033[33mSe detectó una función\033[0m" << endl; yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 17:
#line 76 "gramaticaComCHZExtendida.y"
{cout << "\033[33mSe detectó una función\033[0m" << endl; yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 28:
#line 100 "gramaticaComCHZExtendida.y"
{ yyerror("Falta identificador en la declaración de un objeto"); }
break;
case 36:
#line 114 "gramaticaComCHZExtendida.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 40:
#line 119 "gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 41:
#line 120 "gramaticaComCHZExtendida.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 50:
#line 131 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 52:
#line 135 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 57:
#line 145 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 58:
#line 146 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 59:
#line 147 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 60:
#line 148 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 76:
#line 177 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 79:
#line 182 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 80:
#line 183 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 86:
#line 192 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 87:
#line 193 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 88:
#line 196 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 89:
#line 197 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 90:
#line 198 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 91:
#line 199 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 92:
#line 200 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 681 "y.tab.c"
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
