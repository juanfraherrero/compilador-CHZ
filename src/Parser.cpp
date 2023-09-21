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

// generamos la tabla de símbolos
TableSymbol* tableSymbol = new TableSymbol();

// generamos la tabla de palabras reservadas
TableReservedWord* tableRWords = new TableReservedWord();

int lineNumber = 1;


void yyerror(string s){
    cerr << "\033[31m" << "Linea: " << lineNumber << "-> Error: parsing failed " << s <<"\033[0m"<< endl;
};

#line 23 "y.tab.c"
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
    0,    0,    1,    1,    2,    2,    3,    3,    3,    3,
    9,    9,   11,   11,   12,   12,   13,   10,   14,   14,
    5,    5,    5,    6,    6,    7,    7,    8,    8,    4,
    4,    4,    4,    4,    4,   15,   16,   16,   20,   20,
   20,   20,   20,   20,   20,   21,   21,   21,   22,   22,
   22,   22,   17,   17,   18,   24,   24,   24,   24,   24,
   24,   25,   25,   26,   26,   23,   23,   23,   23,   23,
   23,   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    2,    1,    1,    1,    3,    9,    2,    2,
    6,    2,    4,    0,    2,    0,    9,    3,    3,    1,
    1,    1,    1,    3,    1,    2,    0,    2,    2,    1,
    1,    1,    3,    1,    1,    4,    5,    4,    3,    3,
    4,    4,    4,    4,    1,    3,    3,    1,    1,    2,
    1,    4,    9,    7,    7,    3,    3,    3,    3,    3,
    3,    3,    1,    2,    1,    1,    1,    2,    1,    2,
    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   21,   22,   23,
    0,    2,    0,    0,    5,    6,    0,    0,    0,   30,
   31,   32,   34,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    3,   25,    0,    9,   10,
    0,    0,   66,   67,   69,   71,    0,    0,    0,    0,
    0,   48,   51,    0,    0,   18,    0,    0,    0,   33,
    0,    0,    7,    0,   19,   50,    0,   38,   68,   70,
    0,    0,    0,    0,    0,   36,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   24,    0,   37,    0,    0,    0,    0,    0,    0,   46,
   47,    0,    0,    0,   26,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   63,    0,    0,    0,    0,    0,
    0,   52,    0,    0,    0,    0,    0,    0,   72,    0,
    0,    0,    0,    0,    0,    0,    0,   11,   15,   74,
    0,    0,    0,    0,   64,   62,    0,   54,   55,   13,
    0,   73,   29,   28,    0,    0,    0,    8,   53,    0,
    0,    0,    0,   17,
};
short yydgoto[] = {                                       2,
   13,  143,   15,   16,   17,   38,   80,  144,   18,   19,
   90,  120,  121,   29,   20,   21,   22,   23,   24,   58,
   51,   52,   53,   59,  116,  132,
};
short yysindex[] = {                                   -116,
 -124,    0,  -18, -238,  -11, -229,   10,    0,    0,    0,
 -201,    0,  -27,  -78,    0,    0, -162,   56,   63,    0,
    0,    0,    0,    0,   50,  -41,  -25, -137,   85,  101,
  -25,   88,  -25,   24,    0,    0,    0,   52,    0,    0,
 -111, -101,    0,    0,    0,    0,  110,  124, -147,  118,
  -26,    0,    0,   31,  -37,    0,  -73,   41,  128,    0,
  139,  -73,    0,  -74,    0,    0,  -25,    0,    0,    0,
  143,  -36,  -30,  -25,  -25,    0,  -73,  -14,  -67,  151,
  -25,  -25,  -25,  -25,  -25,  -25, -115,  -81,  -61,  -59,
    0,  119,    0,  -25,  -25,  -26,  -25,  -25,  -26,    0,
    0,  159,  -28,  162,    0,   86,    8,    8,    8,    8,
    8,    8,    9, -155,    0, -148, -115,  166,  -46,   87,
  -59,    0,  -26,  -26,  -26,  -26,  169,  -43,    0,  -91,
 -155,   90, -115,  182,  196,  -73,  201,    0,    0,    0,
  205,  206,  -91,  126,    0,    0,  -19,    0,    0,    0,
  -73,    0,    0,    0,  214,  219,  228,    0,    0,  147,
  -91,  146,  229,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  149,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  231,    0,    0,    0,    0,    0,
    0,    0,    0,  232,    0,    0,    0,    0,    0,    0,
    0,   -8,    0,    0,    0,    0,    0,    0,    0,    0,
   -3,    0,    0,    0,    0,    0,  236,    0,    0,    0,
    0, -123,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  236,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  153,
    0,    0,    0,    0,    0,    3,    0,    0,   17,    0,
    0,    0,   92,    0,    0,    0,  242,  243,  248,  253,
  254,  255,    0,    0,    0,    0,    0,    0,    0,    0,
  153,    0,   23,   28,   37,   48,    0,    0,    0,    0,
  172,    0,    0,    0,    0, -123,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  236,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  258,   13,    0,    7,  -32,    0,  -64, -138,    0,    0,
  171,  177,    0,  267,    0,    0,    0,    0,    0,   89,
   33,   51,    0,  276, -107,  183,
};
#define YYTABLESIZE 314
short yytable[] = {                                      48,
   12,   14,   77,   49,  154,   94,    1,  114,   49,  135,
   95,   97,  102,   14,   49,   74,   98,  128,   30,   49,
   75,   26,  162,   78,   79,  147,   14,   28,   31,   89,
   49,   32,   49,   49,   49,   49,   49,   45,   49,   45,
   45,   45,   27,   39,   79,   39,   39,   39,   26,   33,
   72,   49,   73,   49,   28,   34,   45,   40,   45,   40,
   40,   40,   39,   42,   39,   42,   42,   42,   44,   27,
   44,   44,   44,   72,   76,   73,   40,   41,   40,   41,
   41,   41,   42,   72,   42,   73,  157,   44,   43,   44,
   43,   43,   43,  115,   37,   63,   41,   35,   41,   39,
   86,  113,   85,   89,   96,   99,   40,   43,   41,   43,
   64,   69,   70,    5,   50,   54,    6,    7,   79,   55,
  131,  133,  134,  115,  100,  101,  123,  124,   56,  125,
  126,   60,    3,   49,   49,   49,   49,  131,   49,  115,
   57,  113,    4,   14,    5,   25,   62,    6,    7,   67,
    8,    9,   10,    5,   11,   92,    6,    7,   71,  122,
   72,   72,   73,   73,   66,    3,  104,   68,   87,  107,
  108,  109,  110,  111,  112,    4,  142,    5,    3,   88,
    6,    7,   91,    8,    9,   10,   93,   11,    4,  105,
    5,  106,  117,    6,    7,  118,    8,    9,   10,  127,
   11,    8,    9,   10,   72,  129,   73,  119,  130,  136,
  137,  138,  140,  141,  146,   42,   43,   44,   45,   46,
   42,   43,   44,   45,   46,  148,   42,   43,   44,   45,
   46,   42,   43,   44,   45,   46,   47,   66,   25,  149,
  151,   47,  103,   43,   44,   45,   46,   47,  152,  153,
  155,  156,   47,   49,   49,   49,   49,  158,   45,   45,
   45,   45,  159,   47,   39,   39,   39,   39,  160,  161,
  163,   36,  164,    4,   20,   12,   27,   16,   40,   40,
   40,   40,   58,   59,   42,   42,   42,   42,   61,   44,
   44,   44,   44,   60,   56,   57,   65,  139,   41,   41,
   41,   41,   81,   82,   83,   84,  150,   65,   61,   43,
   43,   43,   43,  145,
};
short yycheck[] = {                                      41,
  125,  125,   40,   45,  143,   42,  123,  123,   45,  117,
   47,   42,   77,    1,   45,   42,   47,   46,  257,   45,
   47,   40,  161,   61,   57,  133,   14,   46,   40,   62,
   45,  261,   41,   42,   43,   44,   45,   41,   47,   43,
   44,   45,   61,   41,   77,   43,   44,   45,   40,   40,
   43,   60,   45,   62,   46,  257,   60,   41,   62,   43,
   44,   45,   60,   41,   62,   43,   44,   45,   41,   61,
   43,   44,   45,   43,   44,   45,   60,   41,   62,   43,
   44,   45,   60,   43,   62,   45,  151,   60,   41,   62,
   43,   44,   45,   87,  257,   44,   60,  125,   62,   44,
   60,  257,   62,  136,   72,   73,   44,   60,   59,   62,
   59,  259,  260,  269,   26,   27,  272,  273,  151,  257,
  114,  270,  271,  117,   74,   75,   94,   95,   44,   97,
   98,   44,  257,   42,   43,   44,   45,  131,   47,  133,
   40,  257,  267,  267,  269,  257,  123,  272,  273,   40,
  275,  276,  277,  269,  279,   67,  272,  273,   41,   41,
   43,   43,   45,   45,  266,  257,   78,   44,   41,   81,
   82,   83,   84,   85,   86,  267,  268,  269,  257,   41,
  272,  273,  257,  275,  276,  277,   44,  279,  267,  257,
  269,   41,  274,  272,  273,  257,  275,  276,  277,   41,
  279,  275,  276,  277,   43,   44,   45,  267,  123,   44,
  257,  125,   44,  257,  125,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,   44,  257,  258,  259,  260,
  261,  257,  258,  259,  260,  261,  278,  266,  257,   44,
   40,  278,  257,  258,  259,  260,  261,  278,   44,   44,
  125,  271,  278,  262,  263,  264,  265,   44,  262,  263,
  264,  265,   44,  278,  262,  263,  264,  265,   41,  123,
  125,   14,   44,  125,   44,   44,   41,  125,  262,  263,
  264,  265,   41,   41,  262,  263,  264,  265,   41,  262,
  263,  264,  265,   41,   41,   41,  125,  121,  262,  263,
  264,  265,  262,  263,  264,  265,  136,   41,   33,  262,
  263,  264,  265,  131,
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
"declaracion_objeto : IDENTIFICADOR lista_de_objetos ','",
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
"asignacion : IDENTIFICADOR '=' expresion_aritmetica ','",
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
"factor : IDENTIFICADOR",
"factor : IDENTIFICADOR OPERADOR_SUMA_SUMA",
"factor : constante",
"factor : TOF '(' expresion_aritmetica ')'",
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
"constante : ENTERO_SIN_SIGNO",
"constante : ENTERO_CORTO",
"constante : '-' ENTERO_CORTO",
"constante : PUNTO_FLOTANTE",
"constante : '-' PUNTO_FLOTANTE",
"constante : CADENA_CARACTERES",
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
#line 174 "gramaticaComCHZExtendida.y"
void checkIntegerShort(string lexeme){
        symbol* sm = tableSymbol->getSymbol(lexeme);
        if(sm != nullptr ){
            if(atoi(sm->value.c_str()) >= 128){
                    std::cerr << "\033[31m" << "Linea: " << lineNumber << "-> Error por entero corto fuera de rango { -128 - 127 }"  << "\033[0m"<< endl;
            }
        }
}
void checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value);
}
#line 347 "y.tab.c"
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
#line 45 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << lineNumber << "-> Warning: Se está compilando un programa sin contenido" << "\033[0m" << endl;}
break;
case 5:
#line 51 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia declarativa " << endl;}
break;
case 6:
#line 52 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia ejecutable " << endl;}
break;
case 41:
#line 117 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << lineNumber << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
break;
case 42:
#line 118 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << lineNumber << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
break;
case 43:
#line 119 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << lineNumber << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
break;
case 44:
#line 120 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << lineNumber << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
break;
case 66:
#line 160 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 67:
#line 161 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 68:
#line 162 "gramaticaComCHZExtendida.y"
{ cout << "es un entero corto negtivo" << endl; checkIntegerShortNegative(yyvsp[0]);}
break;
case 69:
#line 163 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante: " << yyvsp[0] << endl;}
break;
case 70:
#line 164 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante: " << yyvsp[-1] << endl;}
break;
case 71:
#line 165 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
#line 539 "y.tab.c"
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
