#ifndef YYBISONPARSER
#define YYBISONPARSER
#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "gramaticaComCHZExtendida.y"

#include <iostream>
#include <fstream>
#include <string>
#include "include/Lexico.hpp"
using namespace std;

void yyerror(string s){
    cerr << "Error sintactico" << s << endl;
};

#line 15 "y.tab.c"
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
    0,    1,    1,    2,    2,    3,    3,    3,    3,    9,
    9,   11,   11,   12,   12,   13,   10,   14,   14,    5,
    5,    5,    6,    6,    7,    7,    8,    8,    4,    4,
    4,    4,    4,    4,   15,   16,   16,   20,   20,   20,
   21,   21,   21,   22,   22,   22,   22,   17,   17,   18,
   24,   24,   24,   24,   24,   24,   25,   25,   26,   26,
   23,   23,   23,   23,   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    0,    1,    1,    3,    9,    2,    2,    6,
    2,    4,    0,    2,    0,    9,    3,    3,    1,    1,
    1,    1,    3,    1,    2,    0,    2,    2,    1,    1,
    1,    3,    1,    1,    4,    5,    4,    3,    3,    1,
    3,    3,    1,    1,    2,    1,    4,    9,    7,    7,
    3,    3,    3,    3,    3,    3,    3,    1,    2,    1,
    1,    1,    1,    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   20,   21,   22,
    0,    0,    0,    4,    5,    0,    0,    0,   29,   30,
   31,   33,   34,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    1,    2,   24,    0,    8,    9,    0,
    0,   61,   62,   63,   64,    0,    0,    0,    0,   43,
   46,    0,    0,   17,    0,    0,    0,   32,    0,    0,
    6,    0,   18,   45,    0,   37,    0,    0,    0,    0,
    0,   35,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   23,    0,   36,    0,
    0,   41,   42,    0,    0,    0,   25,    0,    0,    0,
    0,    0,    0,    0,    0,    0,   58,    0,    0,    0,
    0,    0,    0,   47,    0,    0,   65,    0,    0,    0,
    0,    0,    0,    0,    0,   10,   14,   67,    0,    0,
    0,    0,   59,   57,    0,   49,   50,   12,    0,   66,
   28,   27,    0,    0,    0,    7,   48,    0,    0,    0,
    0,   16,
};
short yydgoto[] = {                                       2,
   12,  131,   14,   15,   16,   37,   76,  132,   17,   18,
   86,  112,  113,   28,   19,   20,   21,   22,   23,   56,
   49,   50,   51,   57,  108,  120,
};
short yysindex[] = {                                   -105,
 -166,    0,   -1, -231,   16, -202,   34,    0,    0,    0,
 -194,  -47, -166,    0,    0, -168,   50,   60,    0,    0,
    0,    0,    0,   67,  -41, -173, -138,  101,  109, -173,
  108, -173,   30,    0,    0,    0,   -4,    0,    0, -103,
 -110,    0,    0,    0,    0,  115,  113,   88,   23,    0,
    0,   93,   -3,    0, -136,  -24,  119,    0,  122, -136,
    0,  -93,    0,    0, -173,    0,  121, -173, -173, -173,
 -173,    0, -136, -143,  -91,  126, -173, -173, -173, -173,
 -173, -173, -111, -106,  -88,  -97,    0,   89,    0,   23,
   23,    0,    0,  130,  -23,   99,    0,   49,    3,    3,
    3,    3,    3,    3,    1, -145,    0, -190, -111,  129,
  -83,   51,  -97,    0,  131,  -80,    0, -200, -145,   53,
 -111,  135,  136, -136,  141,    0,    0,    0,  138,  139,
 -200,   59,    0,    0,  -86,    0,    0,    0, -136,    0,
    0,    0,  142,  143,  147,    0,    0,   66, -200,   65,
  148,    0,
};
short yyrindex[] = {                                      0,
   68,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   68,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  150,    0,    0,    0,    0,    0,    0,
    0,    0,  151,    0,    0,    0,    0,    0,    0,    0,
  -40,    0,    0,    0,    0,    0,    0,    0,  -35,    0,
    0,    0,    0,    0,  155,    0,    0,    0,    0, -108,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  155,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   72,    0,    0,    0,  -30,
  -10,    0,    0,    0,   78,    0,    0,    0,  157,  158,
  159,  160,  161,  162,    0,    0,    0,    0,    0,    0,
    0,    0,   72,    0,    0,    0,    0,    0,   81,    0,
    0,    0,    0, -108,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  155,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,
};
short yygindex[] = {                                      0,
  178,   48,    0,  -55,  -31,    0,  -57,  -78,    0,    0,
   83,   91,    0,  165,    0,    0,    0,    0,    0,   18,
   79,   80,    0,  176,  -19,   90,
};
#define YYTABLESIZE 256
short yytable[] = {                                      47,
   44,   44,   44,   44,   44,   40,   44,   40,   40,   40,
   38,  106,   38,   38,   38,   94,   13,    1,   68,   44,
   69,   44,  116,   75,   40,   29,   40,  107,   85,   38,
   39,   38,   39,   39,   39,   82,   73,   81,   25,   61,
   25,   75,   48,   52,   27,   68,   27,   69,   13,   39,
  119,   39,  142,  107,   62,   30,    3,   74,   31,   26,
   13,   26,   33,  119,   70,  107,    4,  130,    5,   71,
  150,    6,    7,   32,    8,    9,   10,   34,   11,  121,
  122,  145,   88,   41,   42,   43,   44,   45,   36,  123,
    3,   96,   85,   38,   99,  100,  101,  102,  103,  104,
    4,  135,    5,   39,   46,    6,    7,   75,    8,    9,
   10,  105,   11,   95,   42,   43,   44,   45,   53,   44,
   44,   44,   44,    5,   44,   40,    6,    7,   67,  114,
   68,   68,   69,   69,   46,   68,   72,   69,    8,    9,
   10,   68,  117,   69,   54,  105,   90,   91,   55,   92,
   93,   58,   60,   24,   65,   64,   66,    5,   13,   83,
    6,    7,   84,   87,   89,   97,   98,  109,  110,  111,
  115,  118,  124,  125,  128,  126,  129,  134,  136,  137,
  139,  140,  141,  143,  144,  146,  147,  148,  149,  151,
   35,  152,    3,   19,   11,   26,   15,   53,   54,   56,
   55,   51,   52,  127,   63,   60,  138,   59,  133,    0,
    0,    0,    0,    0,    0,   41,   42,   43,   44,   45,
    0,   44,   44,   44,   44,    0,   40,   40,   40,   40,
    0,   38,   38,   38,   38,    0,   46,   77,   78,   79,
   80,    0,   64,    0,    0,    0,    0,    0,    0,    0,
    0,   39,   39,   39,   39,   24,
};
short yycheck[] = {                                      41,
   41,   42,   43,   44,   45,   41,   47,   43,   44,   45,
   41,  123,   43,   44,   45,   73,  125,  123,   43,   60,
   45,   62,   46,   55,   60,  257,   62,   83,   60,   60,
   41,   62,   43,   44,   45,   60,   40,   62,   40,   44,
   40,   73,   25,   26,   46,   43,   46,   45,    1,   60,
  106,   62,  131,  109,   59,   40,  257,   61,  261,   61,
   13,   61,  257,  119,   42,  121,  267,  268,  269,   47,
  149,  272,  273,   40,  275,  276,  277,  125,  279,  270,
  271,  139,   65,  257,  258,  259,  260,  261,  257,  109,
  257,   74,  124,   44,   77,   78,   79,   80,   81,   82,
  267,  121,  269,   44,  278,  272,  273,  139,  275,  276,
  277,  257,  279,  257,  258,  259,  260,  261,  257,   42,
   43,   44,   45,  269,   47,   59,  272,  273,   41,   41,
   43,   43,   45,   45,  278,   43,   44,   45,  275,  276,
  277,   43,   44,   45,   44,  257,   68,   69,   40,   70,
   71,   44,  123,  257,   40,  266,   44,  269,  267,   41,
  272,  273,   41,  257,   44,  257,   41,  274,  257,  267,
   41,  123,   44,  257,   44,  125,  257,  125,   44,   44,
   40,   44,   44,  125,  271,   44,   44,   41,  123,  125,
   13,   44,  125,   44,   44,   41,  125,   41,   41,   41,
   41,   41,   41,  113,   40,  125,  124,   32,  119,   -1,
   -1,   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,
   -1,  262,  263,  264,  265,   -1,  262,  263,  264,  265,
   -1,  262,  263,  264,  265,   -1,  278,  262,  263,  264,
  265,   -1,  266,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  262,  263,  264,  265,  257,
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
"sentencias : sentencia sentencias",
"sentencias :",
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
typedef int YYSTYPE;
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
int yyparse(Lexico * lexico)
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
#endif