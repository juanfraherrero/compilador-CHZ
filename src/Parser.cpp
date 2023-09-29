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
   23,   23,   23,   23,   24,   24,   25,   25,   22,   22,
   22,   22,   22,   26,   26,   27,   27,   27,   27,   27,
   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    2,    1,    1,    1,    1,    2,
    3,    9,    2,    2,    6,    2,    4,    0,    2,    0,
    9,    2,    3,    1,    2,    1,    1,    1,    3,    1,
    2,    0,    2,    2,    1,    1,    1,    3,    1,    1,
    2,    4,    3,    5,    4,    3,    3,    4,    4,    4,
    4,    1,    3,    3,    1,    9,    7,    7,    3,    3,
    3,    3,    3,    3,    3,    1,    2,    1,    1,    2,
    1,    1,    4,    1,    1,    1,    2,    1,    2,    1,
    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   26,   27,
   28,    0,    0,    9,    0,    0,    7,    8,    0,    0,
    0,   35,   36,   37,   39,   40,   10,    0,    0,    0,
    0,   22,    0,    0,    0,   41,    0,    0,    4,    0,
    5,   30,    0,   13,   14,    0,    0,   74,   76,   78,
   75,    0,    0,    0,    0,    0,   55,   71,   72,   43,
    0,    0,    0,    0,    0,   38,    0,    0,    3,   11,
    0,   23,   70,    0,   45,   77,   79,    0,    0,    0,
    0,    0,   42,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   29,    0,   44,
    0,    0,    0,    0,    0,    0,   53,   54,    0,    0,
    0,   31,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   66,    0,    0,    0,    0,    0,    0,   73,    0,
    0,    0,    0,    0,    0,   81,    0,    0,    0,    0,
    0,    0,    0,    0,   15,   19,   83,    0,    0,    0,
    0,   67,   65,    0,   57,   58,   17,    0,   82,   34,
   33,    0,    0,    0,   12,   56,    0,    0,    0,    0,
   21,
};
short yydgoto[] = {                                       2,
   15,  150,   17,   18,   19,   43,   87,  151,   20,   21,
   97,  127,  128,   32,   22,   23,   24,   25,   26,   64,
   56,   57,   65,  123,  139,   58,   59,
};
short yysindex[] = {                                   -103,
  -23,    0,  -13,  -21, -224,   -3,  -22,    9,    0,    0,
    0, -201, -196,    0,  -50,   15,    0,    0, -176,   50,
   57,    0,    0,    0,    0,    0,    0,   28,  -41,    3,
 -143,    0,   81,   38,   85,    0,   38,   18,    0,  -95,
    0,    0,  -20,    0,    0,  -94, -101,    0,    0,    0,
    0,  126,  127, -216,   12,  -15,    0,    0,    0,    0,
   35,  -35, -191,  119,  129,    0,  131, -191,    0,    0,
  -84,    0,    0,   38,    0,    0,    0,  130,  -36,  -30,
   38,   38,    0, -191,   43,  -75,  135,   38,   38,   38,
   38,   38,   38,  -89,  -88,  -72,  -80,    0,   31,    0,
   38,   38,  -15,   38,   38,  -15,    0,    0,  147,  -28,
   68,    0,   67,  -29,  -29,  -29,  -29,  -29,  -29,  -10,
 -211,    0, -125,  -89,  154,  -66,   74,  -80,    0,  -15,
  -15,  -15,  -15,  156,  -56,    0,    1, -211,   77,  -89,
  159,  160, -191,  165,    0,    0,    0,  162,  163,    1,
   83,    0,    0,  -62,    0,    0,    0, -191,    0,    0,
    0,  166,  167,  171,    0,    0,   90,    1,   89,  182,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  215,    0,    0,  110,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  188,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  196,    0,  241,
    0,    0,    0,    0,    0,  199,   48,    0,    0,    0,
    0,    0,    0,   62,    0,   55,    0,    0,    0,    0,
    0,    0,  204,    0,    0,    0,    0, -124,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  204,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  122,    0,    0,    0,
    0,    0,   75,    0,    0,   82,    0,    0,    0,   26,
    0,    0,    0,  210,  214,  218,  224,  225,  226,    0,
    0,    0,    0,    0,    0,    0,    0,  122,    0,   87,
   95,  107,  115,    0,    0,    0,    0,  150,    0,    0,
    0,    0, -124,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  204,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  263,   49,    0,  -86,  -61,    0,  -81, -140,    0,    0,
  140,  157,    0,  240,    0,    0,    0,    0,    0,  104,
  -38,   72,  252, -111,  155,    0,    0,
};
#define YYTABLESIZE 384
short yytable[] = {                                      53,
   18,   86,  109,   54,   84,  101,   96,  122,   54,  161,
  102,  104,  142,   79,   54,   80,  105,  135,   29,    1,
   14,   36,   86,   70,   31,   85,   81,  169,  154,   29,
   27,   82,   33,  121,  138,   31,   34,  122,   71,   30,
  103,  106,   76,   77,   14,  120,   60,   54,   37,   16,
   30,  138,   78,  122,   79,   38,   80,    6,   14,   39,
    7,    8,  130,  131,   16,  132,  133,   69,   69,   69,
   69,  129,   69,   79,   40,   80,  164,   79,   83,   80,
   42,   96,   54,    9,   10,   11,   46,   54,   69,   69,
   69,   69,   69,   44,   69,   52,   86,   52,   52,   52,
   45,   13,   80,   80,   80,   80,   80,   69,   80,   69,
   79,  136,   80,   62,   52,   46,   52,   46,   46,   46,
   63,   80,   47,   80,   47,   47,   47,   49,   66,   49,
   49,   49,   55,   61,   46,   51,   46,   51,   51,   51,
   68,   47,   18,   47,  140,  141,   49,   48,   49,   48,
   48,   48,  107,  108,   51,   50,   51,   50,   50,   50,
   69,   79,   28,   80,   73,   74,   48,  120,   48,   94,
   75,   95,   98,  100,   50,  113,   50,   99,   93,    6,
   92,  112,    7,    8,  125,  124,  126,  134,  111,  137,
  144,  114,  115,  116,  117,  118,  119,  143,  145,  147,
  148,  153,  155,  156,  158,  159,  160,  162,  163,  165,
  166,  167,  168,  170,    2,   47,   48,   49,   50,   51,
   47,   48,   49,   50,   51,  171,   47,   48,   49,   50,
   51,   24,    3,    4,    6,   28,   52,   73,   35,   16,
    1,   52,   25,    5,   32,    6,   20,   52,    7,    8,
   61,    9,   10,   11,   62,   12,    3,    4,   64,   47,
   48,   49,   50,   51,   63,   59,   60,    5,  149,    6,
    3,    4,    7,    8,   68,    9,   10,   11,   41,   12,
   52,    5,  157,    6,  146,   72,    7,    8,   67,    9,
   10,   11,  152,   12,   47,   48,   49,   50,   51,  110,
   48,   49,   50,   51,    0,    0,    0,    0,    0,   69,
   69,   69,   69,    0,    0,   52,   52,   52,   52,   52,
   52,    0,    0,   80,   80,   80,   80,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   46,   46,   46,   46,
    0,    0,    0,   47,   47,   47,   47,    0,   49,   49,
   49,   49,    0,    0,    0,    0,   51,   51,   51,   51,
    0,    0,    0,    0,    0,    0,    0,    0,   48,   48,
   48,   48,    0,    0,    0,    0,   50,   50,   50,   50,
   88,   89,   90,   91,
};
short yycheck[] = {                                      41,
  125,   63,   84,   45,   40,   42,   68,   94,   45,  150,
   47,   42,  124,   43,   45,   45,   47,   46,   40,  123,
   44,   44,   84,   44,   46,   61,   42,  168,  140,   40,
   44,   47,  257,  123,  121,   46,   40,  124,   59,   61,
   79,   80,  259,  260,   44,  257,   44,   45,   40,    1,
   61,  138,   41,  140,   43,  257,   45,  269,   44,  256,
  272,  273,  101,  102,   16,  104,  105,   42,   43,   44,
   45,   41,   47,   43,  125,   45,  158,   43,   44,   45,
  257,  143,   45,  275,  276,  277,   59,   45,   41,   42,
   43,   44,   45,   44,   47,   41,  158,   43,   44,   45,
   44,  125,   41,   42,   43,   44,   45,   60,   47,   62,
   43,   44,   45,  257,   60,   41,   62,   43,   44,   45,
   40,   60,   41,   62,   43,   44,   45,   41,   44,   43,
   44,   45,   29,   30,   60,   41,   62,   43,   44,   45,
  123,   60,  267,   62,  270,  271,   60,   41,   62,   43,
   44,   45,   81,   82,   60,   41,   62,   43,   44,   45,
  256,   43,  257,   45,  266,   40,   60,  257,   62,   41,
   44,   41,  257,   44,   60,   41,   62,   74,   60,  269,
   62,  257,  272,  273,  257,  274,  267,   41,   85,  123,
  257,   88,   89,   90,   91,   92,   93,   44,  125,   44,
  257,  125,   44,   44,   40,   44,   44,  125,  271,   44,
   44,   41,  123,  125,    0,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   44,  257,  258,  259,  260,
  261,   44,  256,  257,  125,  257,  278,  266,  261,   44,
    0,  278,   44,  267,   41,  269,  125,  278,  272,  273,
   41,  275,  276,  277,   41,  279,  256,  257,   41,  257,
  258,  259,  260,  261,   41,   41,   41,  267,  268,  269,
  256,  257,  272,  273,  125,  275,  276,  277,   16,  279,
  278,  267,  143,  269,  128,   46,  272,  273,   37,  275,
  276,  277,  138,  279,  257,  258,  259,  260,  261,  257,
  258,  259,  260,  261,   -1,   -1,   -1,   -1,   -1,  262,
  263,  264,  265,   -1,   -1,  278,  262,  263,  264,  265,
  278,   -1,   -1,  262,  263,  264,  265,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  262,  263,  264,  265,
   -1,   -1,   -1,  262,  263,  264,  265,   -1,  262,  263,
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
"sentencias_ejecutables : ejecutable sentencias_ejecutables",
"sentencias_ejecutables : ejecutable",
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
#line 196 "gramaticaComCHZExtendida.y"
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
#line 392 "y.tab.c"
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
case 74:
#line 179 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 75:
#line 180 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 76:
#line 183 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 77:
#line 184 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 78:
#line 185 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 79:
#line 186 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 80:
#line 187 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 616 "y.tab.c"
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
