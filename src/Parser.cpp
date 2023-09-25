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
    0,    0,    1,    1,    2,    2,    2,    3,    3,    3,
    3,    9,    9,   11,   11,   12,   12,   13,   10,   14,
   14,    5,    5,    5,    6,    6,    7,    7,    8,    8,
    4,    4,    4,    4,    4,    4,    4,   15,   15,   16,
   16,   20,   20,   20,   20,   20,   20,   20,   21,   21,
   21,   17,   17,   18,   23,   23,   23,   23,   23,   23,
   24,   24,   25,   25,   22,   22,   22,   22,   22,   26,
   26,   27,   27,   27,   27,   27,   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    2,    1,    1,    1,    1,    3,    9,    2,
    2,    6,    2,    4,    0,    2,    0,    9,    2,    3,
    1,    1,    1,    1,    3,    1,    2,    0,    2,    2,
    1,    1,    1,    3,    1,    1,    2,    4,    3,    5,
    4,    3,    3,    4,    4,    4,    4,    1,    3,    3,
    1,    9,    7,    7,    3,    3,    3,    3,    3,    3,
    3,    1,    2,    1,    1,    2,    1,    1,    4,    1,
    1,    1,    2,    1,    2,    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   22,   23,   24,
    0,    2,    7,    0,    0,    5,    6,    0,    0,    0,
   31,   32,   33,   35,   36,    0,    0,    0,    0,   19,
    0,    0,    0,   37,    0,    0,    1,    3,   26,    0,
   10,   11,    0,    0,   70,   72,   74,   71,    0,    0,
    0,    0,    0,   51,   67,   68,   39,    0,    0,    0,
    0,    0,   34,    0,    0,    8,    0,   20,   66,    0,
   41,   73,   75,    0,    0,    0,    0,    0,   38,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   25,    0,   40,    0,    0,    0,    0,
    0,    0,   49,   50,    0,    0,    0,   27,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   62,    0,    0,
    0,    0,    0,    0,   69,    0,    0,    0,    0,    0,
    0,   77,    0,    0,    0,    0,    0,    0,    0,    0,
   12,   16,   79,    0,    0,    0,    0,   63,   61,    0,
   53,   54,   14,    0,   78,   30,   29,    0,    0,    0,
    9,   52,    0,    0,    0,    0,   18,
};
short yydgoto[] = {                                       2,
   14,  146,   16,   17,   18,   40,   83,  147,   19,   20,
   93,  123,  124,   30,   21,   22,   23,   24,   25,   61,
   53,   54,   62,  119,  135,   55,   56,
};
short yysindex[] = {                                    -93,
  -23,    0,  -22, -224,   -4,  -25,    6,    0,    0,    0,
 -214,    0,    0,  -72,    3,    0,    0, -190,   25,   55,
    0,    0,    0,    0,    0,   21,  -41,   26, -156,    0,
   64,   31,   65,    0,   31,   -3,    0,    0,    0,  -28,
    0,    0, -132, -135,    0,    0,    0,    0,   92,   90,
 -177,   20,    8,    0,    0,    0,    0,   29,  -38, -198,
  117,   95,    0,   96, -198,    0, -118,    0,    0,   31,
    0,    0,    0,   97,  -36,  -30,   31,   31,    0, -198,
   36, -115,  114,   31,   31,   31,   31,   31,   31,  -91,
 -113,  -90, -108,    0,   23,    0,   31,   31,    8,   31,
   31,    8,    0,    0,  123,  -33,  149,    0,   46,  -40,
  -40,  -40,  -40,  -40,  -40,  -26, -228,    0, -164,  -91,
  127,  -83,   51, -108,    0,    8,    8,    8,    8,  136,
  -73,    0,  -10, -228,   60,  -91,  151,  152, -198,  157,
    0,    0,    0,  154,  155,  -10,   75,    0,    0,  -70,
    0,    0,    0, -198,    0,    0,    0,  158,  159,  163,
    0,    0,   82,  -10,   81,  164,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   84,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  166,    0,    0,    0,    0,
    0,    0,    0,    0,    0,  167,    0,    0,    0,    0,
    0,    0,    0,   43,    0,    0,    0,    0,    0,    0,
   53,    0,   48,    0,    0,    0,    0,    0,    0,  171,
    0,    0,    0,    0, -117,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  171,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   88,    0,    0,    0,    0,    0,   73,    0,
    0,   78,    0,    0,    0,   15,    0,    0,    0,  173,
  174,  185,  191,  197,  198,    0,    0,    0,    0,    0,
    0,    0,    0,   88,    0,   83,  103,  108,  113,    0,
    0,    0,    0,  115,    0,    0,    0,    0, -117,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  171,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  192,   27,    0,  -80,  259,    0,  -79, -139,    0,    0,
  104,  121,    0,  208,    0,    0,    0,    0,    0,  102,
  -49,   34,  206,  -98,  130,    0,    0,
};
#define YYTABLESIZE 413
short yytable[] = {                                      50,
  105,   80,   75,   51,   76,   97,  157,   15,   51,  118,
   98,  100,  131,   27,   51,   66,  101,   27,   34,   29,
   13,  138,   81,   29,  165,   99,  102,   15,  116,    1,
   67,  117,   31,   13,   28,   32,  134,  150,   28,  118,
    5,   15,   36,    6,    7,   35,   13,  126,  127,   77,
  128,  129,   37,  134,   78,  118,   65,   65,   65,   65,
   74,   65,   75,  125,   76,   75,   39,   76,   41,   57,
   51,   75,   79,   76,  160,   51,    8,    9,   10,   43,
   51,   72,   73,   65,   65,   65,   65,   65,   48,   65,
   48,   48,   48,   76,   76,   76,   76,   76,   42,   76,
   59,   12,   65,   60,   65,  136,  137,   48,   63,   48,
  103,  104,   76,   42,   76,   42,   42,   42,   43,   65,
   43,   43,   43,   45,   26,   45,   45,   45,   52,   58,
   69,   70,   42,   71,   42,   90,   91,   43,   94,   43,
   96,  108,   45,   47,   45,   47,   47,   47,   44,   15,
   44,   44,   44,   46,  109,   46,   46,   46,  122,   75,
  120,   76,   47,  130,   47,  116,  121,   44,  133,   44,
  139,   95,   46,  140,   46,  141,   89,    5,   88,  143,
    6,    7,  107,  144,  149,  110,  111,  112,  113,  114,
  115,   75,  132,   76,  151,  152,  154,  155,  156,  158,
  159,  161,  162,  163,  164,  166,   38,  167,    4,   21,
   13,   28,   17,   57,   58,   44,   45,   46,   47,   48,
   44,   45,   46,   47,   48,   60,   44,   45,   46,   47,
   48,   59,   69,    3,   26,   33,   49,   55,   56,   64,
   64,   49,  153,    4,  142,    5,    3,   49,    6,    7,
   68,    8,    9,   10,    0,   11,    4,  145,    5,    3,
    0,    6,    7,  148,    8,    9,   10,    0,   11,    4,
    0,    5,    0,    0,    6,    7,    0,    8,    9,   10,
    0,   11,   44,   45,   46,   47,   48,   44,   45,   46,
   47,   48,  106,   45,   46,   47,   48,    0,    0,    0,
    0,    0,    0,   49,   65,   65,   65,   65,   49,   48,
   48,   48,   48,   49,   76,   76,   76,   76,   82,    0,
    0,    0,    0,   92,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   42,   42,   42,   42,   82,   43,
   43,   43,   43,    0,   45,   45,   45,   45,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   47,   47,   47,   47,    0,   44,
   44,   44,   44,    0,   46,   46,   46,   46,   84,   85,
   86,   87,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   92,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   82,
};
short yycheck[] = {                                      41,
   80,   40,   43,   45,   45,   42,  146,  125,   45,   90,
   47,   42,   46,   40,   45,   44,   47,   40,   44,   46,
   44,  120,   61,   46,  164,   75,   76,    1,  257,  123,
   59,  123,  257,   44,   61,   40,  117,  136,   61,  120,
  269,   15,  257,  272,  273,   40,   44,   97,   98,   42,
  100,  101,  125,  134,   47,  136,   42,   43,   44,   45,
   41,   47,   43,   41,   45,   43,  257,   45,   44,   44,
   45,   43,   44,   45,  154,   45,  275,  276,  277,   59,
   45,  259,  260,   41,   42,   43,   44,   45,   41,   47,
   43,   44,   45,   41,   42,   43,   44,   45,   44,   47,
  257,  125,   60,   40,   62,  270,  271,   60,   44,   62,
   77,   78,   60,   41,   62,   43,   44,   45,   41,  123,
   43,   44,   45,   41,  257,   43,   44,   45,   27,   28,
  266,   40,   60,   44,   62,   41,   41,   60,  257,   62,
   44,  257,   60,   41,   62,   43,   44,   45,   41,  267,
   43,   44,   45,   41,   41,   43,   44,   45,  267,   43,
  274,   45,   60,   41,   62,  257,  257,   60,  123,   62,
   44,   70,   60,  257,   62,  125,   60,  269,   62,   44,
  272,  273,   81,  257,  125,   84,   85,   86,   87,   88,
   89,   43,   44,   45,   44,   44,   40,   44,   44,  125,
  271,   44,   44,   41,  123,  125,   15,   44,  125,   44,
   44,   41,  125,   41,   41,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   41,  257,  258,  259,  260,
  261,   41,  266,  257,  257,  261,  278,   41,   41,  125,
   35,  278,  139,  267,  124,  269,  257,  278,  272,  273,
   43,  275,  276,  277,   -1,  279,  267,  268,  269,  257,
   -1,  272,  273,  134,  275,  276,  277,   -1,  279,  267,
   -1,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  257,  258,  259,  260,  261,  257,  258,  259,
  260,  261,  257,  258,  259,  260,  261,   -1,   -1,   -1,
   -1,   -1,   -1,  278,  262,  263,  264,  265,  278,  262,
  263,  264,  265,  278,  262,  263,  264,  265,   60,   -1,
   -1,   -1,   -1,   65,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   80,  262,
  263,  264,  265,   -1,  262,  263,  264,  265,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   -1,  262,
  263,  264,  265,   -1,  262,  263,  264,  265,  262,  263,
  264,  265,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,  139,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,  154,
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
#line 193 "gramaticaComCHZExtendida.y"
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
#line 389 "y.tab.c"
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
case 37:
#line 118 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 39:
#line 122 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 44:
#line 132 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 45:
#line 133 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 46:
#line 134 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 47:
#line 135 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 70:
#line 176 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 71:
#line 177 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 72:
#line 180 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 73:
#line 181 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 74:
#line 182 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 75:
#line 183 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 76:
#line 184 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 597 "y.tab.c"
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
