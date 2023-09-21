#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "gramaticaComCHZExtendida.y"

#include "include/types.hpp"
#include "include/Lexico.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>

using namespace std;

void yyerror(string s, int* lineNumber){
    cerr << "Error sintactico" << s << endl;
    cerr << "\033[31m" << "Linea: " << *lineNumber << "-> Error: parsing failed " << "\033[0m"<< endl;
};

#line 22 "y.tab.c"
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
   24,   25,   25,   26,   26,   23,   23,   23,   23,   19,
   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    2,    1,    1,    1,    3,    9,    2,    2,
    6,    2,    4,    0,    2,    0,    9,    3,    3,    1,
    1,    1,    1,    3,    1,    2,    0,    2,    2,    1,
    1,    1,    3,    1,    1,    4,    5,    4,    3,    3,
    4,    4,    4,    4,    1,    3,    3,    1,    1,    2,
    1,    4,    9,    7,    7,    3,    3,    3,    3,    3,
    3,    3,    1,    2,    1,    1,    1,    1,    1,    6,
    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   21,   22,   23,
    0,    2,    0,    0,    5,    6,    0,    0,    0,   30,
   31,   32,   34,   35,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    1,    3,   25,    0,    9,   10,
    0,    0,   66,   67,   68,   69,    0,    0,    0,    0,
   48,   51,    0,    0,   18,    0,    0,    0,   33,    0,
    0,    7,    0,   19,   50,    0,   38,    0,    0,    0,
    0,    0,   36,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   24,    0,   37,
    0,    0,    0,    0,    0,    0,   46,   47,    0,    0,
    0,   26,    0,    0,    0,    0,    0,    0,    0,    0,
    0,   63,    0,    0,    0,    0,    0,    0,   52,    0,
    0,    0,    0,    0,    0,   70,    0,    0,    0,    0,
    0,    0,    0,    0,   11,   15,   72,    0,    0,    0,
    0,   64,   62,    0,   54,   55,   13,    0,   71,   29,
   28,    0,    0,    0,    8,   53,    0,    0,    0,    0,
   17,
};
short yydgoto[] = {                                       2,
   13,  140,   15,   16,   17,   38,   77,  141,   18,   19,
   87,  117,  118,   29,   20,   21,   22,   23,   24,   57,
   50,   51,   52,   58,  113,  129,
};
short yysindex[] = {                                   -116,
 -124,    0,  -31, -247,  -24, -234,   20,    0,    0,    0,
 -217,    0,  -57, -148,    0,    0, -163,   52,   74,    0,
    0,    0,    0,    0,   63,  -41,  -95, -134,   82,   90,
  -95,   88,  -95,   12,    0,    0,    0,  -40,    0,    0,
 -118, -120,    0,    0,    0,    0,  107,  106,  152,   45,
    0,    0,  158,  -22,    0,  -68,   37,  115,    0,  119,
  -68,    0,  -85,    0,    0,  -95,    0,  129,  -36,  -30,
  -95,  -95,    0,  -68,  -73,  -77,  141,  -95,  -95,  -95,
  -95,  -95,  -95, -115,  -75,  -53,  -61,    0,  155,    0,
  -95,  -95,   45,  -95,  -95,   45,    0,    0,  172,  -33,
  167,    0,   91,    4,    4,    4,    4,    4,    4,  -26,
 -159,    0, -103, -115,  171,  -25,  109,  -61,    0,   45,
   45,   45,   45,  191,  -21,    0,  -98, -159,  113, -115,
  195,  196,  -68,  201,    0,    0,    0,  203,  205,  -98,
  134,    0,    0,  -17,    0,    0,    0,  -68,    0,    0,
    0,  216,  217,  221,    0,    0,  144,  -98,  143,  225,
    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  145,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  227,    0,    0,    0,    0,    0,
    0,    0,    0,  228,    0,    0,    0,    0,    0,    0,
    0,  -19,    0,    0,    0,    0,    0,    0,    0,  -12,
    0,    0,    0,    0,    0,  232,    0,    0,    0,    0,
 -123,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  232,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  149,    0,    0,    0,
    0,    0,   -7,    0,    0,    1,    0,    0,    0,  147,
    0,    0,    0,  238,  239,  240,  241,  246,  251,    0,
    0,    0,    0,    0,    0,    0,    0,  149,    0,   13,
   21,   26,   33,    0,    0,    0,    0,  168,    0,    0,
    0,    0, -123,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,  232,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,
};
short yygindex[] = {                                      0,
  280,   58,    0,    6,   28,    0,  -69, -137,    0,    0,
  170,  186,    0,  264,    0,    0,    0,    0,    0,   25,
   46,   40,    0,  273,  -29,  179,
};
#define YYTABLESIZE 307
short yytable[] = {                                      48,
   12,   14,  151,   62,   99,   91,    1,  111,   26,   30,
   92,   94,  125,   26,   28,   31,   95,   74,   63,   28,
  159,   49,   49,   49,   49,   49,   32,   49,   45,   27,
   45,   45,   45,   39,   27,   39,   39,   39,   75,   34,
   49,   40,   49,   40,   40,   40,   69,   45,   70,   45,
   49,   53,   39,   42,   39,   42,   42,   42,   14,   33,
   40,   44,   40,   44,   44,   44,   41,   35,   41,   41,
   41,   14,   42,   43,   42,   43,   43,   43,  154,   69,
   44,   70,   44,   76,  132,   41,   71,   41,   86,  112,
   89,   72,   43,   37,   43,   39,   83,  110,   82,  101,
  144,   76,  104,  105,  106,  107,  108,  109,    3,    5,
   97,   98,    6,    7,   93,   96,  128,   40,    4,  112,
    5,   41,   54,    6,    7,   55,    8,    9,   10,   56,
   11,   59,    3,  128,   61,  112,  120,  121,   25,  122,
  123,  110,    4,   14,    5,   65,   66,    6,    7,   67,
    8,    9,   10,    5,   11,   84,    6,    7,    3,   85,
   86,   42,   43,   44,   45,   46,  130,  131,    4,  139,
    5,   88,   90,    6,    7,   76,    8,    9,   10,  102,
   11,  103,   47,  100,   43,   44,   45,   46,   49,   49,
   49,   49,   68,   49,   69,  119,   70,   69,  114,   70,
   69,   73,   70,  115,   47,  116,    8,    9,   10,   69,
  126,   70,  124,  127,  133,   42,   43,   44,   45,   46,
   42,   43,   44,   45,   46,   25,   42,   43,   44,   45,
   46,  134,   65,  135,  137,  138,   47,  143,  145,  146,
  148,   47,   49,   49,   49,   49,  149,   47,  150,   45,
   45,   45,   45,  153,   39,   39,   39,   39,  152,  155,
  156,  157,   40,   40,   40,   40,  158,  160,  161,    4,
   20,   12,   27,   16,   42,   42,   42,   42,   58,   59,
   61,   60,   44,   44,   44,   44,   56,   41,   41,   41,
   41,   57,   65,   36,   43,   43,   43,   43,   78,   79,
   80,   81,  147,  136,   64,   60,  142,
};
short yycheck[] = {                                      41,
  125,  125,  140,   44,   74,   42,  123,  123,   40,  257,
   47,   42,   46,   40,   46,   40,   47,   40,   59,   46,
  158,   41,   42,   43,   44,   45,  261,   47,   41,   61,
   43,   44,   45,   41,   61,   43,   44,   45,   61,  257,
   60,   41,   62,   43,   44,   45,   43,   60,   45,   62,
   26,   27,   60,   41,   62,   43,   44,   45,    1,   40,
   60,   41,   62,   43,   44,   45,   41,  125,   43,   44,
   45,   14,   60,   41,   62,   43,   44,   45,  148,   43,
   60,   45,   62,   56,  114,   60,   42,   62,   61,   84,
   66,   47,   60,  257,   62,   44,   60,  257,   62,   75,
  130,   74,   78,   79,   80,   81,   82,   83,  257,  269,
   71,   72,  272,  273,   69,   70,  111,   44,  267,  114,
  269,   59,  257,  272,  273,   44,  275,  276,  277,   40,
  279,   44,  257,  128,  123,  130,   91,   92,  257,   94,
   95,  257,  267,  267,  269,  266,   40,  272,  273,   44,
  275,  276,  277,  269,  279,   41,  272,  273,  257,   41,
  133,  257,  258,  259,  260,  261,  270,  271,  267,  268,
  269,  257,   44,  272,  273,  148,  275,  276,  277,  257,
  279,   41,  278,  257,  258,  259,  260,  261,   42,   43,
   44,   45,   41,   47,   43,   41,   45,   43,  274,   45,
   43,   44,   45,  257,  278,  267,  275,  276,  277,   43,
   44,   45,   41,  123,   44,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  257,  257,  258,  259,  260,
  261,  257,  266,  125,   44,  257,  278,  125,   44,   44,
   40,  278,  262,  263,  264,  265,   44,  278,   44,  262,
  263,  264,  265,  271,  262,  263,  264,  265,  125,   44,
   44,   41,  262,  263,  264,  265,  123,  125,   44,  125,
   44,   44,   41,  125,  262,  263,  264,  265,   41,   41,
   41,   41,  262,  263,  264,  265,   41,  262,  263,  264,
  265,   41,  125,   14,  262,  263,  264,  265,  262,  263,
  264,  265,  133,  118,   41,   33,  128,
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
"constante : PUNTO_FLOTANTE",
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
#define YYABORT goto yyabort
#define YYACCEPT goto yyaccept
#define YYERROR goto yyerrlab
int
yyparse(Lexico* lexico, int* lineNumber)
{
    register int yym, yyn, yystate;
#if YYDEBUG
    register char *yys;

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
        // printf("yydebug: state %d, char: %d shifting to state %d \n", yystate, yychar, yytable[yyn]);
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
    yyerror("syntax error", lineNumber);
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
#line 44 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se está compilando un programa sin contenido" << "\033[0m" << endl;}
break;
case 5:
#line 50 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia declarativa " << endl;}
break;
case 6:
#line 51 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una sentencia ejecutable " << endl;}
break;
case 41:
#line 116 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
break;
case 42:
#line 117 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
break;
case 43:
#line 118 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
break;
case 44:
#line 119 "gramaticaComCHZExtendida.y"
{ cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
break;
case 66:
#line 159 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 67:
#line 160 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero corto: " << yyvsp[0] << endl;}
break;
case 68:
#line 161 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante: " << yyvsp[0] << endl;}
break;
case 69:
#line 162 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
#line 508 "y.tab.c"
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
    yyerror("yacc stack overflow", lineNumber);
yyabort:
    return (1);
yyaccept:
    return (0);
}
