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
    0,    0,    1,    1,    2,    2,    3,    3,    3,    3,
    9,    9,   11,   11,   12,   12,   13,   10,   14,   14,
    5,    5,    5,    6,    6,    7,    7,    8,    8,    4,
    4,    4,    4,    4,    4,    4,   15,   15,   16,   16,
   20,   20,   20,   20,   20,   20,   20,   21,   21,   21,
   17,   17,   18,   23,   23,   23,   23,   23,   23,   24,
   24,   25,   25,   22,   22,   22,   22,   22,   26,   26,
   27,   27,   27,   27,   27,   19,   19,   19,
};
short yylen[] = {                                         2,
    3,    2,    2,    1,    1,    1,    3,    9,    2,    2,
    6,    2,    4,    0,    2,    0,    9,    3,    3,    1,
    1,    1,    1,    3,    1,    2,    0,    2,    2,    1,
    1,    1,    3,    1,    1,    2,    4,    3,    5,    4,
    3,    3,    4,    4,    4,    4,    1,    3,    3,    1,
    9,    7,    7,    3,    3,    3,    3,    3,    3,    3,
    1,    2,    1,    1,    2,    1,    1,    4,    1,    1,
    1,    2,    1,    2,    1,    6,    8,    7,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,   21,   22,   23,
    0,    2,    0,    0,    5,    6,    0,    0,    0,   30,
   31,   32,   34,   35,    0,    0,    0,    0,    0,    0,
    0,    0,   36,    0,    0,    1,    3,   25,    0,    9,
   10,    0,    0,   69,   71,   73,   70,    0,    0,    0,
    0,    0,   50,   66,   67,   38,    0,    0,   18,    0,
    0,    0,   33,    0,    0,    7,    0,   19,   65,    0,
   40,   72,   74,    0,    0,    0,    0,    0,   37,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   24,    0,   39,    0,    0,    0,    0,
    0,    0,   48,   49,    0,    0,    0,   26,    0,    0,
    0,    0,    0,    0,    0,    0,    0,   61,    0,    0,
    0,    0,    0,    0,   68,    0,    0,    0,    0,    0,
    0,   76,    0,    0,    0,    0,    0,    0,    0,    0,
   11,   15,   78,    0,    0,    0,    0,   62,   60,    0,
   52,   53,   13,    0,   77,   29,   28,    0,    0,    0,
    8,   51,    0,    0,    0,    0,   17,
};
short yydgoto[] = {                                       2,
   13,  146,   15,   16,   17,   39,   83,  147,   18,   19,
   93,  123,  124,   29,   20,   21,   22,   23,   24,   61,
   52,   53,   62,  119,  135,   54,   55,
};
short yysindex[] = {                                   -118,
 -124,    0,  -18, -236,   -7,  -21,   26,    0,    0,    0,
 -152,    0,   -9,  -84,    0,    0, -128,   83,   92,    0,
    0,    0,    0,    0,   78,  -41,  -25, -117,  103,  116,
  -14,  115,    0,  -14,   51,    0,    0,    0,   87,    0,
    0,  -80,  -85,    0,    0,    0,    0,  144,  142, -230,
   19,  -15,    0,    0,    0,    0,   42,  -37,    0,  -68,
   72,  146,    0,  149,  -68,    0,  -63,    0,    0,  -14,
    0,    0,    0,  152,  -36,  -30,  -14,  -14,    0,  -68,
   -3,  -52,  169,  -14,  -14,  -14,  -14,  -14,  -14, -115,
  -48,  -46,  -26,    0,  161,    0,  -14,  -14,  -15,  -14,
  -14,  -15,    0,    0,  208,  -28,  170,    0,  127,   81,
   81,   81,   81,   81,   81,   74, -232,    0, -173, -115,
  207,   -5,  134,  -26,    0,  -15,  -15,  -15,  -15,  216,
    4,    0,  -97, -232,  137, -115,  219,  225,  -68,  234,
    0,    0,    0,  236,  237,  -97,  157,    0,    0,   12,
    0,    0,    0,  -68,    0,    0,    0,  240,  241,  245,
    0,    0,  164,  -97,  163,  250,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  175,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  251,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  261,    0,    0,    0,    0,    0,
    0,    0,    3,    0,    0,    0,    0,    0,    0,   14,
    0,    8,    0,    0,    0,    0,    0,    0,    0,  248,
    0,    0,    0,    0, -123,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  248,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  181,    0,    0,    0,    0,    0,   28,    0,
    0,   34,    0,    0,    0,  156,    0,    0,    0,  266,
  267,  268,  273,  274,  275,    0,    0,    0,    0,    0,
    0,    0,    0,  181,    0,   39,   48,   59,   68,    0,
    0,    0,    0,  192,    0,    0,    0,    0, -123,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,  248,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  304,   53,    0,    5,   58,    0,  -73, -130,    0,    0,
  180,  196,    0,  283,    0,    0,    0,    0,    0,   80,
  -62,   85,  292, -110,  193,    0,    0,
};
#define YYTABLESIZE 337
short yytable[] = {                                      49,
   12,   14,   80,   50,    1,   97,  105,  117,   50,  138,
   98,  100,   99,  102,   50,  157,  101,  131,   56,   50,
   30,   26,   33,   81,  116,  150,   77,   28,   72,   73,
   50,   78,   31,  165,  126,  127,    5,  128,  129,    6,
    7,   50,   27,   64,   64,   64,   64,   64,   47,   64,
   47,   47,   47,   14,   75,   75,   75,   75,   75,   74,
   75,   75,   64,   76,   64,   34,   14,   47,   41,   47,
   41,   41,   41,   75,   42,   75,   42,   42,   42,   44,
  160,   44,   44,   44,   75,   79,   76,   41,   46,   41,
   46,   46,   46,   42,  118,   42,  136,  137,   44,   43,
   44,   43,   43,   43,   35,   51,   57,   46,   45,   46,
   45,   45,   45,   26,   75,   36,   76,   82,   43,   28,
   43,  134,   92,   75,  118,   76,   40,   45,   38,   45,
   66,   89,    3,   88,   27,   41,   42,   82,  134,   58,
  118,  116,    4,   14,    5,   67,   59,    6,    7,   95,
    8,    9,   10,    5,   11,   60,    6,    7,   63,    3,
  107,  103,  104,  110,  111,  112,  113,  114,  115,    4,
  145,    5,    3,   65,    6,    7,   25,    8,    9,   10,
   69,   11,    4,   70,    5,   71,   90,    6,    7,   91,
    8,    9,   10,   94,   11,   96,   92,   64,   64,   64,
   64,  125,   64,   75,  108,   76,    8,    9,   10,  109,
  121,   82,   75,  132,   76,   43,   44,   45,   46,   47,
   43,   44,   45,   46,   47,  120,   43,   44,   45,   46,
   47,   43,   44,   45,   46,   47,   48,   69,   25,   32,
  122,   48,   43,   44,   45,   46,   47,   48,  130,  133,
  139,  140,   48,  106,   44,   45,   46,   47,  141,  143,
  144,  149,  151,   48,   64,   64,   64,   64,  152,   47,
   47,   47,   47,  154,   48,   75,   75,   75,   75,  155,
  156,  158,  159,  161,  162,  163,  164,  166,   27,   41,
   41,   41,   41,  167,   20,   42,   42,   42,   42,    4,
   44,   44,   44,   44,   12,   16,   56,   57,   59,   46,
   46,   46,   46,   58,   54,   55,   63,   37,  153,  142,
   43,   43,   43,   43,   68,   64,  148,    0,    0,   45,
   45,   45,   45,   84,   85,   86,   87,
};
short yycheck[] = {                                      41,
  125,  125,   40,   45,  123,   42,   80,  123,   45,  120,
   47,   42,   75,   76,   45,  146,   47,   46,   44,   45,
  257,   40,   44,   61,  257,  136,   42,   46,  259,  260,
   45,   47,   40,  164,   97,   98,  269,  100,  101,  272,
  273,   45,   61,   41,   42,   43,   44,   45,   41,   47,
   43,   44,   45,    1,   41,   42,   43,   44,   45,   41,
   47,   43,   60,   45,   62,   40,   14,   60,   41,   62,
   43,   44,   45,   60,   41,   62,   43,   44,   45,   41,
  154,   43,   44,   45,   43,   44,   45,   60,   41,   62,
   43,   44,   45,   60,   90,   62,  270,  271,   60,   41,
   62,   43,   44,   45,  257,   26,   27,   60,   41,   62,
   43,   44,   45,   40,   43,  125,   45,   60,   60,   46,
   62,  117,   65,   43,  120,   45,   44,   60,  257,   62,
   44,   60,  257,   62,   61,   44,   59,   80,  134,  257,
  136,  257,  267,  267,  269,   59,   44,  272,  273,   70,
  275,  276,  277,  269,  279,   40,  272,  273,   44,  257,
   81,   77,   78,   84,   85,   86,   87,   88,   89,  267,
  268,  269,  257,  123,  272,  273,  257,  275,  276,  277,
  266,  279,  267,   40,  269,   44,   41,  272,  273,   41,
  275,  276,  277,  257,  279,   44,  139,   42,   43,   44,
   45,   41,   47,   43,  257,   45,  275,  276,  277,   41,
  257,  154,   43,   44,   45,  257,  258,  259,  260,  261,
  257,  258,  259,  260,  261,  274,  257,  258,  259,  260,
  261,  257,  258,  259,  260,  261,  278,  266,  257,  261,
  267,  278,  257,  258,  259,  260,  261,  278,   41,  123,
   44,  257,  278,  257,  258,  259,  260,  261,  125,   44,
  257,  125,   44,  278,  262,  263,  264,  265,   44,  262,
  263,  264,  265,   40,  278,  262,  263,  264,  265,   44,
   44,  125,  271,   44,   44,   41,  123,  125,   41,  262,
  263,  264,  265,   44,   44,  262,  263,  264,  265,  125,
  262,  263,  264,  265,   44,  125,   41,   41,   41,  262,
  263,  264,  265,   41,   41,   41,  125,   14,  139,  124,
  262,  263,  264,  265,   42,   34,  134,   -1,   -1,  262,
  263,  264,  265,  262,  263,  264,  265,
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
#line 192 "gramaticaComCHZExtendida.y"
void checkIntegerShort(string lexeme){
        symbol* sm = tableSymbol->getSymbol(lexeme);
        if(sm != nullptr ){
            if(atoi(sm->value.c_str()) >= 128){
                    yyerror("Entero corto fuera de rango { -128 - 127 }");
            }
        }else{
                yyerror("No se encuentra el token en la tabla de símbolo");
        }
}
void checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value);
}
#line 371 "y.tab.c"
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
case 36:
#line 117 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 38:
#line 121 "gramaticaComCHZExtendida.y"
{ yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
break;
case 43:
#line 131 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 44:
#line 132 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 45:
#line 133 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '-'");}
break;
case 46:
#line 134 "gramaticaComCHZExtendida.y"
{ yywarning("Se detectó un error en operador, quedará '+'");}
break;
case 69:
#line 175 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un entero sin signo: " << yyvsp[0] << endl;}
break;
case 70:
#line 176 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó una cadena de caracteres: " << yyvsp[0] << endl;}
break;
case 71:
#line 179 "gramaticaComCHZExtendida.y"
{ checkIntegerShort(yyvsp[0]);}
break;
case 72:
#line 180 "gramaticaComCHZExtendida.y"
{ checkIntegerShortNegative(yyvsp[0]);}
break;
case 73:
#line 181 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante positivo: " << yyvsp[0] << endl;}
break;
case 74:
#line 182 "gramaticaComCHZExtendida.y"
{ cout << "Se detectó un punto flotante negativo: " << yyvsp[0] << endl;}
break;
case 75:
#line 183 "gramaticaComCHZExtendida.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
#line 575 "y.tab.c"
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
