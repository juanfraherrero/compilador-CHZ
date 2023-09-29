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
    3,    3,    3,    3,    9,    9,   11,   11,   12,   12,
   13,   10,   14,   14,   14,    5,    5,    5,    6,    6,
    7,    7,    8,    8,    4,    4,    4,    4,    4,    4,
    4,   15,   15,   16,   16,   20,   20,   20,   20,   20,
   20,   20,   21,   21,   21,   17,   17,   18,   23,   23,
   23,   23,   23,   23,   24,   24,   24,   25,   25,   25,
   25,   22,   22,   22,   22,   22,   26,   26,   27,   27,
   27,   27,   27,   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    1,    1,    1,    2,
    3,    9,    2,    2,    6,    2,    4,    0,    2,    0,
    9,    2,    3,    1,    2,    1,    1,    1,    3,    1,
    2,    0,    2,    2,    1,    1,    1,    3,    1,    1,
    2,    4,    3,    5,    4,    3,    3,    4,    4,    4,
    4,    1,    3,    3,    1,    9,    7,    7,    3,    3,
    3,    3,    3,    3,    3,    1,    1,    2,    1,    2,
    1,    1,    2,    1,    1,    4,    1,    1,    1,    2,
    1,    2,    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,   27,
   28,    0,    0,    9,    0,    0,    7,    8,    0,    0,
    0,   35,   36,   37,   39,   40,   10,    0,    0,    0,
    0,   22,    0,    0,    0,   41,    0,    0,    4,    0,
    5,   30,    0,   13,   14,    0,    0,   77,   79,   81,
   78,    0,    0,    0,    0,    0,   55,   74,   75,   43,
    0,    0,    0,    0,    0,   38,    0,    0,    3,   11,
    0,   23,   73,    0,   45,   80,   82,    0,    0,    0,
    0,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   44,
    0,    0,    0,    0,    0,    0,   53,   54,    0,    0,
    0,   31,    0,    0,    0,    0,    0,    0,    0,    0,
   67,   66,    0,    0,    0,    0,    0,    0,   76,    0,
    0,    0,    0,    0,    0,   84,    0,   71,   69,    0,
    0,    0,    0,    0,    0,   15,   19,   86,    0,    0,
    0,    0,   65,   70,   68,    0,   57,   58,   17,    0,
   85,   34,   33,    0,    0,    0,   12,   56,    0,    0,
    0,    0,   21,
};
short yydgoto[] = {                                       2,
   15,  151,   17,   18,   19,   43,   87,  152,   20,   21,
   97,  127,  128,   32,   22,   23,   24,   25,   26,   64,
   56,   57,   65,  123,  140,   58,   59,
};
short yysindex[] = {                                    -92,
  -23,    0,    5,  -21, -213,   20,  -22,   27,    0,    0,
    0, -178, -176,    0,  -38,   15,    0,    0, -163,   53,
   57,    0,    0,    0,    0,    0,    0,   74,  -41,    3,
 -143,    0,   81,   38,   90,    0,   38,   18,    0, -111,
    0,    0,  -39,    0,    0, -104, -120,    0,    0,    0,
    0,  114,  117, -203,   -2,  -14,    0,    0,    0,    0,
   41,  -37,  -10,  119,  122,    0,  124,  -10,    0,    0,
  -91,    0,    0,   38,    0,    0,    0,  126,  -36,  -30,
   38,   38,    0,  -10,   43,  -72,  148,   38,   38,   38,
   38,   38,   38,  -89,  -83,  -62,  -71,    0,   23,    0,
   38,   38,  -14,   38,   38,  -14,    0,    0,  158,  -28,
  262,    0,   83,   -7,   -7,   -7,   -7,   -7,   -7,  -64,
    0,    0, -200,  -89,  163,  -47,   89,  -71,    0,  -14,
  -14,  -14,  -14,  182,  -25,    0,    1,    0,    0,  -75,
  -89,  191,  196,  -10,  201,    0,    0,    0,  199,  203,
    1,  120,    0,    0,    0,  -20,    0,    0,    0,  -10,
    0,    0,    0,  211,  215,  234,    0,    0,  156,    1,
  160,  239,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  286,    0,    0,  164,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  249,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  264,    0,  309,
    0,    0,    0,    0,    0,  270,   48,    0,    0,    0,
    0,    0,    0,   62,    0,   55,    0,    0,    0,    0,
    0,    0,  274,    0,    0,    0,    0, -124,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  274,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  197,    0,    0,    0,
    0,    0,   75,    0,    0,   82,    0,    0,    0,  129,
    0,    0,    0,  282,  287,  288,  289,  290,  291,    0,
    0,    0,    0,    0,    0,    0,    0,  197,    0,   87,
   95,  107,  115,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0, -124,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  274,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,
};
short yygindex[] = {                                      0,
  317,    7,  -78,  -59,  -31,    0,  -82, -144,    0,    0,
  190,  207,    0,  295,    0,    0,    0,    0,    0,  -16,
  -50,   30,  299, -114,    0,    0,    0,
};
#define YYTABLESIZE 384
short yytable[] = {                                      53,
   18,  109,   84,   54,   70,  101,  163,   16,   54,  143,
  102,  104,   55,   61,   54,  121,  105,  135,   29,   71,
   14,   36,   16,   85,   31,  171,  156,   81,  103,  106,
    1,   86,   82,  120,  122,   79,   96,   80,   78,   30,
   79,  138,   80,   33,   14,  121,   60,   54,   27,  153,
  130,  131,   86,  132,  133,   76,   77,   99,   14,   34,
  139,  154,  121,  129,  122,   79,   37,   80,  111,  141,
  142,  114,  115,  116,  117,  118,  119,  166,   38,   39,
  155,  122,   54,   79,   83,   80,   40,   54,   72,   72,
   72,   72,   72,   42,   72,   52,   44,   52,   52,   52,
   45,   13,   83,   83,   83,   83,   83,   72,   83,   72,
  107,  108,   96,   62,   52,   46,   52,   46,   46,   46,
   63,   83,   47,   83,   47,   47,   47,   49,   86,   49,
   49,   49,   46,   66,   46,   51,   46,   51,   51,   51,
   68,   47,   18,   47,   69,   73,   49,   48,   49,   48,
   48,   48,   28,   74,   51,   50,   51,   50,   50,   50,
   75,   79,   94,   80,   95,   98,   48,    4,   48,  100,
   72,   72,   72,   72,   50,   72,   50,    5,   93,    6,
   92,    4,    7,    8,  112,    9,   10,   11,  113,   12,
  124,    5,    4,    6,  125,  126,    7,    8,  134,    9,
   10,   11,    5,   12,    6,  137,  144,    7,    8,  145,
    9,   10,   11,  146,   12,   47,   48,   49,   50,   51,
   47,   48,   49,   50,   51,  148,   47,   48,   49,   50,
   51,  149,    3,    4,  157,   28,   52,   73,   35,  158,
  160,   52,  161,    5,  164,    6,  162,   52,    7,    8,
  165,    9,   10,   11,  167,   12,    3,    4,  168,   47,
   48,   49,   50,   51,    9,   10,   11,    5,  150,    6,
    3,    4,    7,    8,  169,    9,   10,   11,  170,   12,
   52,    5,  173,    6,  172,    2,    7,    8,    6,    9,
   10,   11,   24,   12,   47,   48,   49,   50,   51,  110,
   48,   49,   50,   51,   79,  136,   80,   16,    1,   72,
   72,   72,   72,   25,   32,   52,   52,   52,   52,   52,
   52,   20,   61,   83,   83,   83,   83,   62,   64,   63,
   59,   60,   41,  159,  147,   67,   46,   46,   46,   46,
   72,    0,    0,   47,   47,   47,   47,    0,   49,   49,
   49,   49,    0,    0,    0,    0,   51,   51,   51,   51,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   48,
   48,   48,    0,    0,    0,    0,   50,   50,   50,   50,
   88,   89,   90,   91,
};
short yycheck[] = {                                      41,
  125,   84,   40,   45,   44,   42,  151,    1,   45,  124,
   47,   42,   29,   30,   45,   94,   47,   46,   40,   59,
   44,   44,   16,   61,   46,  170,  141,   42,   79,   80,
  123,   63,   47,  123,   94,   43,   68,   45,   41,   61,
   43,  120,   45,  257,   44,  124,   44,   45,   44,  125,
  101,  102,   84,  104,  105,  259,  260,   74,   44,   40,
  120,  140,  141,   41,  124,   43,   40,   45,   85,  270,
  271,   88,   89,   90,   91,   92,   93,  160,  257,  256,
  140,  141,   45,   43,   44,   45,  125,   45,   41,   42,
   43,   44,   45,  257,   47,   41,   44,   43,   44,   45,
   44,  125,   41,   42,   43,   44,   45,   60,   47,   62,
   81,   82,  144,  257,   60,   41,   62,   43,   44,   45,
   40,   60,   41,   62,   43,   44,   45,   41,  160,   43,
   44,   45,   59,   44,   60,   41,   62,   43,   44,   45,
  123,   60,  267,   62,  256,  266,   60,   41,   62,   43,
   44,   45,  257,   40,   60,   41,   62,   43,   44,   45,
   44,   43,   41,   45,   41,  257,   60,  257,   62,   44,
   42,   43,   44,   45,   60,   47,   62,  267,   60,  269,
   62,  257,  272,  273,  257,  275,  276,  277,   41,  279,
  274,  267,  257,  269,  257,  267,  272,  273,   41,  275,
  276,  277,  267,  279,  269,  123,   44,  272,  273,  257,
  275,  276,  277,  125,  279,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   44,  257,  258,  259,  260,
  261,  257,  256,  257,   44,  257,  278,  266,  261,   44,
   40,  278,   44,  267,  125,  269,   44,  278,  272,  273,
  271,  275,  276,  277,   44,  279,  256,  257,   44,  257,
  258,  259,  260,  261,  275,  276,  277,  267,  268,  269,
  256,  257,  272,  273,   41,  275,  276,  277,  123,  279,
  278,  267,   44,  269,  125,    0,  272,  273,  125,  275,
  276,  277,   44,  279,  257,  258,  259,  260,  261,  257,
  258,  259,  260,  261,   43,   44,   45,   44,    0,  262,
  263,  264,  265,   44,   41,  278,  262,  263,  264,  265,
  278,  125,   41,  262,  263,  264,  265,   41,   41,   41,
   41,   41,   16,  144,  128,   37,  262,  263,  264,  265,
   46,   -1,   -1,  262,  263,  264,  265,   -1,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
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
"cuerpo_de_la_funcion : sentencia cuerpo_de_la_funcion",
"cuerpo_de_la_funcion : RETURN ','",
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
#line 199 "gramaticaComCHZExtendida.y"
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
#line 395 "y.tab.c"
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
        printf("yydebug: state %d, char: %d shifting to state %d \n", yystate, yychar, yytable[yyn]);
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
case 25:
#line 97 "gramaticaComCHZExtendida.y"
{ yyerror("Falta identificador en la declaración de un objeto"); }
break;
case 41:
#line 121 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 43:
#line 125 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 48:
#line 135 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 49:
#line 136 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 50:
#line 137 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 51:
#line 138 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 67:
#line 167 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 70:
#line 172 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 71:
#line 173 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 77:
#line 182 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 78:
#line 183 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 79:
#line 186 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 80:
#line 187 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 81:
#line 188 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 82:
#line 189 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 83:
#line 190 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 631 "y.tab.c"
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
