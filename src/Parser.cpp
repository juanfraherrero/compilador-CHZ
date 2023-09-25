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
    0,    0,    1,    1,    2,    2,    2,    2,    3,    3,
    3,    3,    9,    9,   11,   11,   12,   12,   13,   10,
   14,   14,   14,    5,    5,    5,    6,    6,    7,    7,
    8,    8,    4,    4,    4,    4,    4,    4,    4,   15,
   15,   16,   16,   20,   20,   20,   20,   20,   20,   20,
   21,   21,   21,   17,   17,   18,   23,   23,   23,   23,
   23,   23,   24,   24,   25,   25,   22,   22,   22,   22,
   22,   26,   26,   27,   27,   27,   27,   27,   19,   19,
   19,
};
short yylen[] = {                                         2,
    3,    2,    2,    1,    1,    1,    1,    2,    3,    9,
    2,    2,    6,    2,    4,    0,    2,    0,    9,    2,
    3,    1,    2,    1,    1,    1,    3,    1,    2,    0,
    2,    2,    1,    1,    1,    3,    1,    1,    2,    4,
    3,    5,    4,    3,    3,    4,    4,    4,    4,    1,
    3,    3,    1,    9,    7,    7,    3,    3,    3,    3,
    3,    3,    3,    1,    2,    1,    1,    2,    1,    1,
    4,    1,    1,    1,    2,    1,    2,    1,    6,    8,
    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,   24,   25,
   26,    0,    2,    7,    0,    0,    5,    6,    0,    0,
    0,   33,   34,   35,   37,   38,    8,    0,    0,    0,
    0,   20,    0,    0,    0,   39,    0,    0,    1,    3,
   28,    0,   11,   12,    0,    0,   72,   74,   76,   73,
    0,    0,    0,    0,    0,   53,   69,   70,   41,    0,
    0,    0,    0,    0,   36,    0,    0,    9,    0,   21,
   68,    0,   43,   75,   77,    0,    0,    0,    0,    0,
   40,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   27,    0,   42,    0,    0,
    0,    0,    0,    0,   51,   52,    0,    0,    0,   29,
    0,    0,    0,    0,    0,    0,    0,    0,    0,   64,
    0,    0,    0,    0,    0,    0,   71,    0,    0,    0,
    0,    0,    0,   79,    0,    0,    0,    0,    0,    0,
    0,    0,   13,   17,   81,    0,    0,    0,    0,   65,
   63,    0,   55,   56,   15,    0,   80,   32,   31,    0,
    0,    0,   10,   54,    0,    0,    0,    0,   19,
};
short yydgoto[] = {                                       2,
   15,  148,   17,   18,   19,   42,   85,  149,   20,   21,
   95,  125,  126,   32,   22,   23,   24,   25,   26,   63,
   55,   56,   64,  121,  137,   57,   58,
};
short yysindex[] = {                                   -113,
  -23,    0,  -14,  -21, -241,   -7,  -22,   18,    0,    0,
    0, -233,    0,    0,  -73,   15,    0,    0, -170,   50,
   57,    0,    0,    0,    0,    0,    0,   70,  -41,    3,
 -143,    0,   81,   38,   97,    0,   38,   31,    0,    0,
    0,  -15,    0,    0, -104, -105,    0,    0,    0,    0,
  123,  121, -191,   12,   -5,    0,    0,    0,    0,   41,
  -33, -164,  119,  125,    0,  137, -164,    0,  -75,    0,
    0,   38,    0,    0,    0,  126,  -36,  -30,   38,   38,
    0, -164,   43,  -69,  148,   38,   38,   38,   38,   38,
   38,  -89,  -84,  -66,  -74,    0,   36,    0,   38,   38,
   -5,   38,   38,   -5,    0,    0,  151,  -28,  142,    0,
   71,   35,   35,   35,   35,   35,   35,  -20, -207,    0,
 -137,  -89,  152,  -62,   72,  -74,    0,   -5,   -5,   -5,
   -5,  154,  -58,    0,    1, -207,   76,  -89,  156,  158,
 -164,  163,    0,    0,    0,  160,  161,    1,   83,    0,
    0,  -65,    0,    0,    0, -164,    0,    0,    0,  165,
  166,  170,    0,    0,   84,    1,   88,  168,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   89,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  171,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  182,    0,    0,
    0,    0,    0,    0,  188,   48,    0,    0,    0,    0,
    0,    0,   62,    0,   55,    0,    0,    0,    0,    0,
    0,  194,    0,    0,    0,    0, -124,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,  194,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  116,    0,    0,    0,    0,    0,
   75,    0,    0,   82,    0,    0,    0,  129,    0,    0,
    0,  199,  202,  204,  206,  210,  214,    0,    0,    0,
    0,    0,    0,    0,    0,  116,    0,   87,   95,  107,
  115,    0,    0,    0,    0,  134,    0,    0,    0,    0,
 -124,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  194,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  249,   30,    0,  -87,  -59,    0,  -80, -112,    0,    0,
  138,  140,    0,  222,    0,    0,    0,    0,    0,  -16,
  -39,   66,  238,  -95,  147,    0,    0,
};
#define YYTABLESIZE 384
short yytable[] = {                                      52,
   16,  107,   84,   53,  120,   99,   82,   94,   53,    1,
  100,  102,   54,   60,   53,   33,  103,  133,   29,   29,
   14,   36,   84,   38,   31,   31,  140,   83,   68,   27,
   16,  136,   34,  119,  120,  159,   79,  101,  104,   30,
   30,   80,  152,   69,   14,   16,   59,   53,  136,  118,
  120,   39,   76,  167,   77,   97,   78,   37,   14,  128,
  129,    6,  130,  131,    7,    8,  109,   74,   75,  112,
  113,  114,  115,  116,  117,  162,  127,   77,   77,   78,
   78,   94,   53,   77,   81,   78,   41,   53,   67,   67,
   67,   67,   67,   43,   67,   50,   84,   50,   50,   50,
   44,   13,   78,   78,   78,   78,   78,   67,   78,   67,
    9,   10,   11,   61,   50,   44,   50,   44,   44,   44,
   62,   78,   45,   78,   45,   45,   45,   47,   45,   47,
   47,   47,  138,  139,   44,   49,   44,   49,   49,   49,
   65,   45,   16,   45,  105,  106,   47,   46,   47,   46,
   46,   46,   28,   67,   49,   48,   49,   48,   48,   48,
   71,   77,   72,   78,   73,   92,   46,  118,   46,   98,
   67,   67,   67,   67,   48,   67,   48,   93,   91,    6,
   90,   96,    7,    8,   77,  134,   78,  110,  111,  122,
  123,  132,  124,  135,  142,  141,  143,  145,  146,  153,
  151,  154,  156,  157,  158,  161,  166,  160,  163,  164,
  165,  169,  168,    4,   22,   46,   47,   48,   49,   50,
   46,   47,   48,   49,   50,   14,   46,   47,   48,   49,
   50,   23,    3,    4,   30,   28,   51,   71,   35,   59,
   18,   51,   60,    5,   62,    6,   61,   51,    7,    8,
   57,    9,   10,   11,   58,   12,    3,    4,   66,   46,
   47,   48,   49,   50,   40,  144,   70,    5,  147,    6,
    3,    4,    7,    8,   66,    9,   10,   11,  155,   12,
   51,    5,  150,    6,    0,    0,    7,    8,    0,    9,
   10,   11,    0,   12,   46,   47,   48,   49,   50,  108,
   47,   48,   49,   50,    0,    0,    0,    0,    0,   67,
   67,   67,   67,    0,    0,   51,   50,   50,   50,   50,
   51,    0,    0,   78,   78,   78,   78,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   44,   44,   44,   44,
    0,    0,    0,   45,   45,   45,   45,    0,   47,   47,
   47,   47,    0,    0,    0,    0,   49,   49,   49,   49,
    0,    0,    0,    0,    0,    0,    0,    0,   46,   46,
   46,   46,    0,    0,    0,    0,   48,   48,   48,   48,
   86,   87,   88,   89,
};
short yycheck[] = {                                      41,
  125,   82,   62,   45,   92,   42,   40,   67,   45,  123,
   47,   42,   29,   30,   45,  257,   47,   46,   40,   40,
   44,   44,   82,  257,   46,   46,  122,   61,   44,   44,
    1,  119,   40,  123,  122,  148,   42,   77,   78,   61,
   61,   47,  138,   59,   44,   16,   44,   45,  136,  257,
  138,  125,   41,  166,   43,   72,   45,   40,   44,   99,
  100,  269,  102,  103,  272,  273,   83,  259,  260,   86,
   87,   88,   89,   90,   91,  156,   41,   43,   43,   45,
   45,  141,   45,   43,   44,   45,  257,   45,   41,   42,
   43,   44,   45,   44,   47,   41,  156,   43,   44,   45,
   44,  125,   41,   42,   43,   44,   45,   60,   47,   62,
  275,  276,  277,  257,   60,   41,   62,   43,   44,   45,
   40,   60,   41,   62,   43,   44,   45,   41,   59,   43,
   44,   45,  270,  271,   60,   41,   62,   43,   44,   45,
   44,   60,  267,   62,   79,   80,   60,   41,   62,   43,
   44,   45,  257,  123,   60,   41,   62,   43,   44,   45,
  266,   43,   40,   45,   44,   41,   60,  257,   62,   44,
   42,   43,   44,   45,   60,   47,   62,   41,   60,  269,
   62,  257,  272,  273,   43,   44,   45,  257,   41,  274,
  257,   41,  267,  123,  257,   44,  125,   44,  257,   44,
  125,   44,   40,   44,   44,  271,  123,  125,   44,   44,
   41,   44,  125,  125,   44,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   44,  257,  258,  259,  260,
  261,   44,  256,  257,   41,  257,  278,  266,  261,   41,
  125,  278,   41,  267,   41,  269,   41,  278,  272,  273,
   41,  275,  276,  277,   41,  279,  256,  257,  125,  257,
  258,  259,  260,  261,   16,  126,   45,  267,  268,  269,
  256,  257,  272,  273,   37,  275,  276,  277,  141,  279,
  278,  267,  136,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  257,  258,  259,  260,  261,  257,
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
#line 195 "gramaticaComCHZExtendida.y"
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
#line 387 "y.tab.c"
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
case 5:
#line 63 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia declarativa " << endl;}
break;
case 6:
#line 64 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia ejecutable " << endl;}
break;
case 7:
#line 65 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia vacía"); }
break;
case 8:
#line 66 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó una sentencia inválida"); }
break;
case 23:
#line 96 "gramaticaComCHZExtendida.y"
{ yyerror("Falta identificador en la declaración de un objeto"); }
break;
case 39:
#line 120 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 41:
#line 124 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 46:
#line 134 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 47:
#line 135 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 48:
#line 136 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 49:
#line 137 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 72:
#line 178 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 73:
#line 179 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 74:
#line 182 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 75:
#line 183 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 76:
#line 184 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 77:
#line 185 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 78:
#line 186 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 603 "y.tab.c"
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
