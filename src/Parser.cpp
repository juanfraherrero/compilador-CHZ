#ifndef lint
static char yysccsid[] = "@(#)yaccpar	1.8 (Berkeley) 01/20/90";
#endif
#define YYBYACC 1
#line 2 "./gramaticaComCHZGenerativa.y"

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"
#include "include/Tercets.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

/* generamos la tabla de símbolos*/
TableSymbol* tableSymbol = new TableSymbol();

/* generamos la tabla de palabras reservadas*/
TableReservedWord* tableRWords = new TableReservedWord();

int lineNumber = 1;
bool isErrorInCode = false;
Tercets *tableTercets = new Tercets();
char charTercetoId = '%';

string typeAux = "";

void yyerror(string s){
    isErrorInCode = true;    
    cerr << "\033[31m" << "Linea: " << lineNumber << "-> Error: " << s <<"\033[0m"<< endl;
};
void yywarning(string s){
    cerr << "\033[33m" << "Linea: " << lineNumber << "-> Warning: " << s <<"\033[0m"<< endl;
};
void yyPrintInLine(string s){
    cout << "Linea: " << lineNumber << "-> " << s << endl;
};
#line 43 "y.tab.c"
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
    0,    0,    0,    0,    0,    1,    1,    2,    2,    2,
    2,    2,    3,    3,    3,    3,    9,    9,    9,   10,
    7,    7,    7,   13,   13,   13,   13,   14,   14,   15,
   15,    8,   16,   16,    5,    5,    5,    6,    6,   11,
   11,   12,   12,   18,   18,   18,   18,   17,   17,    4,
    4,    4,    4,    4,    4,    4,   19,   20,   20,   24,
   24,   24,   24,   24,   24,   24,   25,   25,   25,   21,
   21,   27,   28,   28,   28,   30,   32,   31,   22,   34,
   35,   36,   29,   29,   29,   29,   29,   29,   33,   33,
   33,   33,   33,   33,   37,   37,   37,   37,   37,   37,
   37,   37,   37,   37,   26,   26,   26,   26,   26,   38,
   38,   39,   39,   39,   39,   39,   23,   23,   23,   23,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    1,    2,    1,    2,    2,    1,
    1,    2,    2,    1,    1,    1,    7,    7,    6,    2,
    5,    2,    4,    4,    3,    3,    2,    7,    6,    2,
    1,    2,    3,    1,    1,    1,    1,    3,    1,    2,
    0,    1,    1,    3,    2,    3,    3,    2,    1,    1,
    1,    1,    2,    1,    1,    1,    3,    4,    3,    3,
    3,    4,    4,    4,    4,    1,    3,    3,    1,    3,
    4,    3,    4,    3,    2,    1,    1,    1,    4,    1,
    3,    1,    3,    3,    3,    3,    3,    3,    3,    5,
    2,    2,    4,    2,    3,    2,    2,    1,    3,    2,
    2,    1,    1,    2,    1,    2,    1,    1,    4,    1,
    1,    1,    2,    1,    2,    1,    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,   80,   35,   36,   37,    0,
    0,    0,    0,    7,    0,    0,    0,   14,   15,   16,
    0,   50,   51,   52,   54,   55,    0,   12,   34,    0,
    0,    0,    0,   20,    0,    0,    0,   53,    0,    0,
    0,    6,    8,    9,   39,    0,    0,    0,    0,    0,
  110,  112,  114,  111,    0,   59,    0,    0,    0,   69,
  107,  108,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,   70,    0,   76,    0,    4,    0,
    0,    0,    0,    0,  106,    0,  113,  115,   58,    0,
    0,    0,    0,    0,    0,   33,   40,    0,   71,    0,
    0,    0,    0,    0,    0,   72,   94,    0,    0,  103,
    0,    0,    0,   92,   91,   78,   75,    0,    0,   77,
    0,   23,    0,    0,    0,    0,    3,   38,    0,   81,
   82,   79,    0,    0,    0,    0,    0,    0,    0,   67,
   68,  120,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  104,    0,  101,   97,    0,   89,    0,    0,
    0,   74,   30,    0,   21,    0,    0,   27,    0,    0,
  109,    0,    0,    0,    0,  119,    0,    0,   49,    0,
    0,   43,   93,    0,   99,   95,   73,   26,    0,   25,
    0,   19,    0,  118,    0,   18,    0,   48,   90,   24,
    0,   17,    0,   47,   44,    0,   29,    0,   28,
};
short yydgoto[] = {                                      12,
   13,  179,   15,   16,   17,   46,   18,   19,   20,   21,
   67,  180,  124,  125,  126,   33,  181,  182,   22,   23,
   24,   25,   26,   69,   59,   60,   37,   75,   70,   76,
  118,  119,   77,   27,   49,  132,  113,   61,   62,
};
short yysindex[] = {                                    -72,
  -29,  -38,  -36,  -22, -255,    0,    0,    0,    0, -219,
  576,    0,  761,    0,   18,   27, -201,    0,    0,    0,
   36,    0,    0,    0,    0,    0,   46,    0,    0,  -34,
  356, -168,   32,    0, -174,  379,  522,    0,  -28, -150,
  605,    0,    0,    0,    0,   48, -174,  356, -166, -154,
    0,    0,    0,    0,   70,    0, -195,   38,  -23,    0,
    0,    0,   14,  -27, -144, -142,   78,  522,  634,   79,
   80,  476,   81,   84,    0,  499,    0, -122,    0, -134,
 -128,   82,   89,  522,    0,  356,    0,    0,    0,  459,
  481,  356,  356,  403,  468,    0,    0,    8,    0,  356,
  356,  356,  356,  356,  356,    0,    0,   88,   90,    0,
   92,   93,  633,    0,    0,    0,    0,  522, -132,    0,
 -110,    0, -201, -104,   99,  108,    0,    0,   26,    0,
    0,    0,   39,  356,  356,  -23,  356,  356,  -23,    0,
    0,    0,   55,  -46,   14, -240,   14,   14,   14,   14,
   14,   14,    0,   31,    0,    0,  107,    0,  114,  116,
 -119,    0,    0,  -18,    0, -201,  117,    0, -174,  548,
    0,  -23,  -23,  -23,  -23,    0,  -90,  124,    0,   44,
  747,    0,    0,   50,    0,    0,    0,    0,   -4,    0,
  135,    0,   52,    0, -240,    0,  134,    0,    0,    0,
   56,    0,  747,    0,    0,  562,    0,   57,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
    0,    0,  180,    0,  375,  399,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  242,    0,  145,    0,    0,    0,  279,  188,
    0,    0,    0,    0,    0,  303,  145,    0,    0,    1,
    0,    0,    0,    0,    0,    0,   25,    0,   49,    0,
    0,    0,  327,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,  192,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  656,  677,    0,    0,    0,    0,    0,    0,    0,    0,
  153,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   73,    0,    0,   97,    0,
    0,    0,    0,  436,  351,    0,  155,  158,  161,  168,
  169,  171,    0,    0,    0,    0,    0,    0,  701,  715,
    0,    0,    0,    0,    0,    0,    0,    0,  145,    0,
    0,  121,  146,  170,  194,    0,    0,    0,    0,    0,
   91,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,  104,    0,    0,    0,    0,    0,
    0,    0,  106,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  206,   47,  774,  846,  -25, -114,    0,    0,    0,    0,
  -42, -156,    0,  109,    0,    0,   41,   45,    0,    0,
    0,    0,    0,  907,  -60,   12,    0,  166,  193,    0,
    0,  125,  -64,    0,    0,    0,    0,    0,    0,
};
#define YYTABLESIZE 1040
short yytable[] = {                                     177,
  105,   30,  122,   35,   82,   38,   56,   32,  164,   66,
   57,  120,   94,  193,   28,    1,    2,   36,   92,  131,
  165,   66,   31,   93,  116,  188,    3,  178,    4,  136,
  139,    5,    6,   95,    7,    8,    9,   39,   10,  200,
   81,  105,  105,  105,  105,  105,   14,  105,   66,  208,
   11,  189,  123,  120,   81,   45,   90,   14,   91,   42,
  105,   43,  105,   87,   88,  116,  116,  116,  116,  116,
   44,  116,   60,  172,  173,   47,  174,  175,   89,  171,
   90,   90,   91,   91,  116,   48,  116,   42,   64,   66,
   65,   66,   66,   66,   78,  176,   61,   90,  166,   91,
    7,    8,    9,  140,  141,   79,   81,   84,   66,   86,
   66,   85,   96,   60,   97,   60,   60,   60,   98,  106,
   63,  127,  129,  107,  114,  105,  191,  115,  128,  130,
  146,  153,   60,  154,   60,  155,  156,   61,  162,   61,
   61,   61,  168,   66,  121,   65,  163,  169,  170,  116,
  184,  187,    7,    8,    9,  183,   61,  185,   61,  186,
  190,   63,  121,   63,   63,   63,  194,  195,  196,   62,
    7,    8,    9,   66,  199,  201,  202,  205,  206,    5,
   63,  209,   63,    1,    2,   41,   65,    2,   65,   65,
   65,    1,   31,   64,    3,   85,    4,   60,   86,    5,
    6,   88,    7,    8,    9,   65,   10,   65,   87,   83,
   62,   84,   62,   62,   62,   42,   41,   56,   29,   85,
   34,   61,   50,   51,   52,   53,   54,  198,   45,   62,
   46,   62,  167,   99,   64,  203,   64,   64,   64,  204,
   83,   32,  161,   55,    0,   63,    0,    0,    0,  198,
    0,    0,    0,   64,    0,   64,  105,  105,    0,    0,
    0,   56,  105,  105,  105,  105,    0,  105,  105,  105,
   65,    0,  105,  105,    0,  105,  105,  105,   22,  105,
  116,  116,    0,    0,    0,   32,  116,  116,  116,  116,
    0,  116,  116,  116,   62,    0,  116,  116,    0,  116,
  116,  116,   13,  116,   66,   66,    0,    0,    0,    0,
   66,   66,   66,   66,    0,   66,   66,   66,   64,    0,
   66,   66,   22,   66,   66,   66,   57,   66,   60,   60,
    0,    0,    0,    0,   60,   60,   60,   60,    0,   60,
   60,   60,   56,    0,   60,   60,   13,   60,   60,   60,
  117,   60,   61,   61,    0,    0,    0,    0,   61,   61,
   61,   61,    0,   61,   61,   61,   32,    0,   61,   61,
   57,   61,   61,   61,   10,   61,   63,   63,    0,    0,
    0,    0,   63,   63,   63,   63,    0,   63,   63,   63,
    0,    0,   63,   63,  117,   63,   63,   63,   11,   63,
   57,   65,   65,   22,    0,    0,    0,   65,   65,   65,
   65,    0,   65,   65,   65,    0,    0,   65,   65,   68,
   65,   65,   65,   57,   65,   62,   62,   13,    0,    0,
    0,   62,   62,   62,   62,  105,   62,   62,   62,    0,
    0,   62,   62,  142,   62,   62,   62,   57,   62,   64,
   64,   57,    0,    0,    0,   64,   64,   64,   64,    0,
   64,   64,   64,    0,    0,   64,   64,    0,   64,   64,
   64,    0,   64,   56,   56,  117,    0,  105,  105,  105,
  105,    0,  105,    0,   56,   56,   56,    0,    0,   56,
   56,    0,   56,   56,   56,    0,   56,   32,   32,   10,
  134,    0,    0,   57,    0,  135,    0,    0,   32,   32,
   32,    0,   57,   32,   32,    0,   32,   32,   32,  110,
   32,    0,  137,   11,    0,   57,    0,  138,    0,    0,
    0,    0,    0,    0,   22,   22,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   22,   22,   22,    0,    0,
   22,   22,    0,   22,   22,   22,    0,   22,   13,   13,
  105,    0,    0,    0,    0,    0,    0,    0,    0,   13,
   13,   13,    0,    0,   13,   13,    0,   13,   13,   13,
    0,   13,   57,   57,    0,    0,    0,    0,    0,    0,
    0,    0,    0,   57,   57,   57,    0,    0,   57,   57,
    0,   57,   57,   57,    0,   57,  117,  117,    0,    0,
    0,    0,   50,   51,   52,   53,   54,  117,  117,  117,
    0,   72,  117,  117,    0,  117,  117,  117,    0,  117,
   10,   10,    0,   55,    0,   50,   51,   52,   53,   54,
    0,   10,   10,   10,   72,    0,   10,   10,    0,   10,
   10,   10,    0,   10,   11,   11,   55,    0,    0,   50,
   51,   52,   53,   54,    0,   11,   11,   11,    0,    0,
   11,   11,  192,   11,   11,   11,   90,   11,   91,    0,
   55,    0,    0,    0,    0,    0,  207,    0,    0,    0,
    0,  105,  105,  105,    0,  104,    0,    0,    0,    0,
   40,    0,  105,  105,  105,    0,    0,  105,  105,    0,
  105,  105,  105,    0,  105,   50,   51,   52,   53,   54,
    0,    0,    0,    0,  144,   51,   52,   53,   54,   80,
    0,  108,    2,    0,    0,    0,   55,   50,   51,   52,
   53,   54,    3,  109,    4,   55,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    2,    0,  158,   55,    0,
    0,    0,    0,    0,    0,    3,   71,    4,  116,  117,
    5,    6,    0,    7,    8,    9,    0,   10,    2,    0,
  102,    0,    0,    0,    0,    0,    0,    0,    3,   71,
    4,    0,    0,    5,    6,    0,    7,    8,    9,    0,
   10,   98,    0,    1,    2,    0,    0,    0,    0,    0,
   73,    0,    0,    0,    3,  178,    4,    1,    2,    5,
    6,    0,    7,    8,    9,  100,   10,    0,    3,  178,
    4,    1,    2,    5,    6,    0,    7,    8,    9,   96,
   10,   73,    3,    0,    4,  111,    0,    5,    6,   73,
    7,    8,    9,    0,   10,    0,    0,   73,    0,    0,
    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    4,    0,    0,    5,    6,    0,    7,
    8,    9,   74,   10,    0,    0,  159,    0,    0,    2,
    0,   73,    0,    0,    0,  100,  101,  102,  103,    3,
  157,    4,    0,    0,    5,    6,    0,    7,    8,    9,
    0,   10,  102,   74,    0,    0,    0,  112,    0,    0,
    0,   74,  102,  102,  102,    0,    0,  102,  102,   74,
  102,  102,  102,   98,  102,    0,   58,   63,    0,    0,
    0,    0,    0,   98,   98,   98,    0,    0,   98,   98,
    0,   98,   98,   98,    0,   98,    0,  100,  160,    0,
    0,    0,    0,   74,    0,    0,    0,  100,  100,  100,
    0,   96,  100,  100,    0,  100,  100,  100,    0,  100,
    0,   96,   96,   96,    0,    0,   96,   96,    0,   96,
   96,   96,  133,   96,    0,    0,    0,    0,    0,    0,
  143,  145,    1,    2,    0,    0,  147,  148,  149,  150,
  151,  152,    0,    3,  197,    4,    1,    2,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    3,    0,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
};
short yycheck[] = {                                      46,
    0,   40,  125,   40,   47,  261,   41,   46,  123,   35,
   45,   76,   40,  170,   44,  256,  257,   40,   42,   84,
  125,   47,   61,   47,    0,   44,  267,  268,  269,   90,
   91,  272,  273,   61,  275,  276,  277,  257,  279,   44,
   59,   41,   42,   43,   44,   45,    0,   47,    0,  206,
  123,  166,   78,  118,   59,  257,   43,   11,   45,   13,
   60,   44,   62,  259,  260,   41,   42,   43,   44,   45,
   44,   47,    0,  134,  135,   40,  137,  138,   41,   41,
   43,   43,   45,   45,   60,   40,   62,   41,  257,   41,
   59,   43,   44,   45,  123,   41,    0,   43,  124,   45,
  275,  276,  277,   92,   93,  256,   59,  274,   60,   40,
   62,  266,  257,   41,  257,   43,   44,   45,   41,   41,
    0,  256,   41,   44,   44,  125,  169,   44,  257,   41,
  123,   44,   60,   44,   62,   44,   44,   41,  271,   43,
   44,   45,   44,  169,  267,    0,  257,   40,  123,  125,
   44,  271,  275,  276,  277,  125,   60,   44,   62,   44,
   44,   41,  267,   43,   44,   45,  257,   44,  125,    0,
  275,  276,  277,  125,  125,   41,  125,   44,  123,    0,
   60,  125,   62,  256,  257,   41,   41,    0,   43,   44,
   45,    0,   40,    0,  267,   41,  269,  125,   41,  272,
  273,   41,  275,  276,  277,   60,  279,   62,   41,   41,
   41,   41,   43,   44,   45,  125,   11,    0,  257,  266,
  257,  125,  257,  258,  259,  260,  261,  181,  125,   60,
  125,   62,  124,   68,   41,  195,   43,   44,   45,  195,
   48,    0,  118,  278,   -1,  125,   -1,   -1,   -1,  203,
   -1,   -1,   -1,   60,   -1,   62,  256,  257,   -1,   -1,
   -1,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
  125,   -1,  272,  273,   -1,  275,  276,  277,    0,  279,
  256,  257,   -1,   -1,   -1,   44,  262,  263,  264,  265,
   -1,  267,  268,  269,  125,   -1,  272,  273,   -1,  275,
  276,  277,    0,  279,  256,  257,   -1,   -1,   -1,   -1,
  262,  263,  264,  265,   -1,  267,  268,  269,  125,   -1,
  272,  273,   44,  275,  276,  277,    0,  279,  256,  257,
   -1,   -1,   -1,   -1,  262,  263,  264,  265,   -1,  267,
  268,  269,  125,   -1,  272,  273,   44,  275,  276,  277,
    0,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,   -1,  267,  268,  269,  125,   -1,  272,  273,
   44,  275,  276,  277,    0,  279,  256,  257,   -1,   -1,
   -1,   -1,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   44,  275,  276,  277,    0,  279,
   45,  256,  257,  125,   -1,   -1,   -1,  262,  263,  264,
  265,   -1,  267,  268,  269,   -1,   -1,  272,  273,   41,
  275,  276,  277,   45,  279,  256,  257,  125,   -1,   -1,
   -1,  262,  263,  264,  265,    0,  267,  268,  269,   -1,
   -1,  272,  273,   41,  275,  276,  277,   45,  279,  256,
  257,  125,   -1,   -1,   -1,  262,  263,  264,  265,   -1,
  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,  256,  257,  125,   -1,   42,   43,   44,
   45,   -1,   47,   -1,  267,  268,  269,   -1,   -1,  272,
  273,   -1,  275,  276,  277,   -1,  279,  256,  257,  125,
   42,   -1,   -1,   45,   -1,   47,   -1,   -1,  267,  268,
  269,   -1,   45,  272,  273,   -1,  275,  276,  277,   44,
  279,   -1,   42,  125,   -1,   45,   -1,   47,   -1,   -1,
   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  256,  257,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,
   -1,   -1,  257,  258,  259,  260,  261,  267,  268,  269,
   -1,  123,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,  278,   -1,  257,  258,  259,  260,  261,
   -1,  267,  268,  269,  123,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,  278,   -1,   -1,  257,
  258,  259,  260,  261,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  125,  275,  276,  277,   43,  279,   45,   -1,
  278,   -1,   -1,   -1,   -1,   -1,  125,   -1,   -1,   -1,
   -1,  256,  257,   60,   -1,   62,   -1,   -1,   -1,   -1,
  125,   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  257,  258,  259,  260,  261,
   -1,   -1,   -1,   -1,  257,  258,  259,  260,  261,  125,
   -1,  256,  257,   -1,   -1,   -1,  278,  257,  258,  259,
  260,  261,  267,  268,  269,  278,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  257,   -1,  125,  278,   -1,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,  270,  271,
  272,  273,   -1,  275,  276,  277,   -1,  279,  257,   -1,
  125,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,  125,   -1,  256,  257,   -1,   -1,   -1,   -1,   -1,
   37,   -1,   -1,   -1,  267,  268,  269,  256,  257,  272,
  273,   -1,  275,  276,  277,  125,  279,   -1,  267,  268,
  269,  256,  257,  272,  273,   -1,  275,  276,  277,  125,
  279,   68,  267,   -1,  269,   72,   -1,  272,  273,   76,
  275,  276,  277,   -1,  279,   -1,   -1,   84,   -1,   -1,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   37,  279,   -1,   -1,  113,   -1,   -1,  257,
   -1,  118,   -1,   -1,   -1,  262,  263,  264,  265,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  257,   68,   -1,   -1,   -1,   72,   -1,   -1,
   -1,   76,  267,  268,  269,   -1,   -1,  272,  273,   84,
  275,  276,  277,  257,  279,   -1,   30,   31,   -1,   -1,
   -1,   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  257,  113,   -1,
   -1,   -1,   -1,  118,   -1,   -1,   -1,  267,  268,  269,
   -1,  257,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   86,  279,   -1,   -1,   -1,   -1,   -1,   -1,
   94,   95,  256,  257,   -1,   -1,  100,  101,  102,  103,
  104,  105,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
};
#define YYFINAL 12
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
"programa : sentencias",
"sentencias : sentencias sentencia",
"sentencias : sentencia",
"sentencia : declarativa ','",
"sentencia : ejecutable ','",
"sentencia : declarativa",
"sentencia : ejecutable",
"sentencia : error ','",
"declarativa : tipo lista_de_variables",
"declarativa : declaracion_clase",
"declarativa : declaracion_objeto",
"declarativa : declaracion_funcion",
"declaracion_funcion : funcion_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"declaracion_funcion : funcion_name '(' parametro ')' '{' '}'",
"funcion_name : VOID IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'",
"declaracion_clase : CLASS IDENTIFICADOR",
"declaracion_clase : CLASS IDENTIFICADOR '{' '}'",
"lista_atributos_y_metodos : lista_atributos_y_metodos tipo lista_de_variables ','",
"lista_atributos_y_metodos : lista_atributos_y_metodos metodo ','",
"lista_atributos_y_metodos : tipo lista_de_variables ','",
"lista_atributos_y_metodos : metodo ','",
"metodo : metodo_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'",
"metodo : metodo_name '(' parametro ')' '{' '}'",
"metodo_name : VOID IDENTIFICADOR",
"metodo_name : VOID",
"declaracion_objeto : IDENTIFICADOR lista_de_objetos",
"lista_de_objetos : lista_de_objetos ';' IDENTIFICADOR",
"lista_de_objetos : IDENTIFICADOR",
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
"cuerpo_de_la_funcion_sin_return : cuerpo_de_la_funcion_sin_return sentencia",
"cuerpo_de_la_funcion_sin_return : sentencia",
"ejecutable : asignacion",
"ejecutable : invocacion",
"ejecutable : seleccion",
"ejecutable : PRINT CADENA_CARACTERES",
"ejecutable : ciclo_while",
"ejecutable : acceso_objeto",
"ejecutable : PRINT",
"asignacion : IDENTIFICADOR '=' expresion_aritmetica",
"invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'",
"invocacion : IDENTIFICADOR '(' ')'",
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
"seleccion : IF bloque_condicion cuerpo_if",
"seleccion : IF '(' ')' cuerpo_if",
"bloque_condicion : '(' condicion ')'",
"cuerpo_if : cuerpo_then else_if cuerpo_else END_IF",
"cuerpo_if : cuerpo_then cuerpo_else END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_then : bloque_ejecutables",
"cuerpo_else : bloque_ejecutables",
"else_if : ELSE",
"ciclo_while : inicio_while bloque_condicion_while DO cuerpo_while",
"inicio_while : WHILE",
"bloque_condicion_while : '(' condicion ')'",
"cuerpo_while : bloque_ejecutables",
"condicion : expresion_aritmetica '>' expresion_aritmetica",
"condicion : expresion_aritmetica '<' expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica",
"condicion : expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica",
"bloque_ejecutables : '{' sentencias_ejecutables '}'",
"bloque_ejecutables : '{' sentencias_ejecutables RETURN ',' '}'",
"bloque_ejecutables : ejecutable ','",
"bloque_ejecutables : declarativa ','",
"bloque_ejecutables : '{' RETURN ',' '}'",
"bloque_ejecutables : RETURN ','",
"sentencias_ejecutables : sentencias_ejecutables ejecutable ','",
"sentencias_ejecutables : sentencias_ejecutables ejecutable",
"sentencias_ejecutables : ejecutable ','",
"sentencias_ejecutables : ejecutable",
"sentencias_ejecutables : sentencias_ejecutables declarativa ','",
"sentencias_ejecutables : sentencias_ejecutables declarativa",
"sentencias_ejecutables : declarativa ','",
"sentencias_ejecutables : declarativa",
"sentencias_ejecutables : ','",
"sentencias_ejecutables : error ','",
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
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'",
"acceso_objeto : IDENTIFICADOR '.' IDENTIFICADOR '(' ')'",
};
#endif
#ifndef YYSTYPE
typedef myTypeYYLVAL* YYSTYPE;
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
#line 261 "./gramaticaComCHZGenerativa.y"
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
string checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value, "short");
        return lexeme;
}
string setFloatNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;
        
        tableSymbol->insert(lexeme, lexeme, lexeme, "float");
        return lexeme;
}
void checkTypesCompare(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al comparar entre "+ type1 + " y " + type2);
        }
}
bool checkTypesOperation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al operar entre "+ type1 + " y " + type2);
                return false;
        }
        return true;
}
void checkTypesAsignation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos al asignar "+ type2 + " a " + type1);
        }
}
// Esta función dado el acceso a un elemento de la tabla de símbolos elimina el simbolo y lo actualiza con el scope y el tipo de esa variable.
symbol* setNewScope(string key, string type, string scope, string uso){
        
        symbol* identificador = tableSymbol->getSymbol(key);    // obtenemos el símbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el símbolo
        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        if(type != ""){
                newIdentificador->type = type;                          // actualizamos el tipo
        }
        if(scope != ""){
                newIdentificador->lexema += scope;                      // actualizamos el scope
        }
        if(uso != ""){
                newIdentificador->uso = uso;                            // actualizamos el uso
        }

        tableSymbol->insert(newIdentificador);                          // insertamos el nuevo símbolo
        return newIdentificador;
}
// Crea un terceto y lo agrega a la tabla de tercetos.
// Los parámtros son argumento, operador1, y operador2
int addTercet(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        int number = tableTercets->add(t);
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos y lo apila.
// Los parámtros son argumento, operador1, y operador2
int addTercetAndStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        int number = tableTercets->add(t);
        tableTercets->push(t);
        return number;
}
// Crea un terceto y lo apila.
// Los parámtros son argumento, operador1, y operador2
void addTercetOnlyStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        tableTercets->push(t);
        return ;
}

// desapila un terceto de la stack de tercetos y la retorna
Tercet* popTercet(){
        return tableTercets->pop();
}
#line 657 "y.tab.c"
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
    { yyerror("Se detectó una falta de coma"); }
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
#line 64 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("FIN", "-", "-");}
break;
case 2:
#line 65 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); Tercet *t = new Tercet("FIN", "-", "-"); int number = tableTercets->add(t); }
break;
case 3:
#line 66 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 4:
#line 67 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}
break;
case 5:
#line 68 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó falta de llaves en el programa"); }
break;
case 10:
#line 77 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 11:
#line 78 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 12:
#line 79 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 13:
#line 82 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 15:
#line 84 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 16:
#line 85 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 17:
#line 88 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope();}
break;
case 18:
#line 89 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 20:
#line 93 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "funcion"); if(diff == 0){yyerror("Redeclaración de función en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion");} tableSymbol->addScope(yyvsp[0]->ptr); }
break;
case 21:
#line 96 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 22:
#line 97 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 23:
#line 98 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 24:
#line 100 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 26:
#line 102 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 28:
#line 107 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); }
break;
case 29:
#line 108 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 30:
#line 111 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope(yyvsp[0]->ptr);}
break;
case 31:
#line 112 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de método"); }
break;
case 35:
#line 122 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 36:
#line 123 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 37:
#line 124 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 38:
#line 127 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 39:
#line 129 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 40:
#line 132 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, yyvsp[-1]->type, tableSymbol->getScope(), "parametro"); yyval->ptr = newIdentificador->lexema; yyval->type = yyvsp[-1]->type;}
break;
case 42:
#line 136 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 46:
#line 141 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 47:
#line 142 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 53:
#line 150 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 56:
#line 153 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 57:
#line 156 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 60:
#line 164 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 61:
#line 165 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 62:
#line 166 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 63:
#line 167 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 64:
#line 168 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 65:
#line 169 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 66:
#line 170 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 67:
#line 173 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 68:
#line 174 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 69:
#line 175 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 70:
#line 178 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}
break;
case 71:
#line 179 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF");}
break;
case 72:
#line 182 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 74:
#line 186 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 78:
#line 194 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 79:
#line 196 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = popTercet(); int number = addTercet("BI", t2->getArg1(), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 80:
#line 199 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 81:
#line 202 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 83:
#line 208 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 84:
#line 209 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 85:
#line 210 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 86:
#line 211 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 87:
#line 212 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 88:
#line 213 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 92:
#line 219 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 96:
#line 225 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 98:
#line 227 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 99:
#line 228 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 100:
#line 229 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 101:
#line 230 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 102:
#line 231 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 103:
#line 232 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 104:
#line 233 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 105:
#line 236 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 106:
#line 237 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 107:
#line 238 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 108:
#line 239 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 109:
#line 240 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 110:
#line 243 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 111:
#line 244 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 112:
#line 247 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 113:
#line 248 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 114:
#line 249 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 115:
#line 250 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 116:
#line 251 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 117:
#line 254 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 118:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 119:
#line 256 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 120:
#line 257 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1137 "y.tab.c"
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
