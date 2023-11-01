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
    0,    0,    0,    0,    0,    0,    0,    1,    1,    2,
    2,    2,    2,    2,    3,    3,    3,    3,    9,    9,
    9,   10,    7,    7,    7,   13,   13,   13,   13,   14,
   14,   15,   15,    8,   16,   16,    5,    5,    5,    6,
    6,   11,   11,   11,   11,   12,   12,   18,   18,   18,
   18,   17,   17,    4,    4,    4,    4,    4,    4,    4,
   19,   20,   20,   24,   24,   24,   24,   24,   24,   24,
   25,   25,   25,   21,   27,   27,   27,   27,   27,   28,
   28,   28,   30,   32,   31,   22,   22,   34,   35,   29,
   29,   29,   29,   29,   29,   33,   33,   33,   33,   33,
   33,   36,   36,   36,   36,   36,   36,   36,   36,   36,
   36,   26,   26,   26,   26,   26,   37,   37,   38,   38,
   38,   38,   38,   23,   23,   23,   23,
};
short yylen[] = {                                         2,
    3,    2,    4,    3,    1,    2,    2,    2,    1,    2,
    2,    1,    1,    2,    2,    1,    1,    1,    7,    7,
    6,    2,    5,    2,    4,    4,    3,    3,    2,    7,
    6,    2,    1,    2,    3,    1,    1,    1,    1,    3,
    1,    2,    1,    1,    0,    1,    1,    3,    2,    3,
    3,    2,    1,    1,    1,    1,    2,    1,    1,    1,
    3,    4,    3,    3,    3,    4,    4,    4,    4,    1,
    3,    3,    1,    3,    3,    2,    2,    1,    2,    4,
    3,    2,    1,    1,    1,    4,    3,    1,    1,    3,
    3,    3,    3,    3,    3,    3,    5,    2,    2,    4,
    2,    3,    2,    2,    1,    3,    2,    2,    1,    1,
    2,    1,    2,    1,    1,    4,    1,    1,    1,    2,
    1,    2,    1,    5,    7,    6,    5,
};
short yydefred[] = {                                      0,
    0,    0,    0,    0,    0,   88,   37,   38,   39,    0,
    0,    0,    0,    9,    0,    0,    0,   16,   17,   18,
    0,   54,   55,   56,   58,   59,    0,   14,   36,    0,
    0,    0,    0,   22,    0,    0,  117,  119,  121,  118,
    0,    0,    0,    0,    0,   73,    0,    0,  114,  115,
   57,    0,    0,    0,    7,    8,   10,   11,   41,    0,
    0,    0,   63,    0,    0,    0,    0,   44,    0,    0,
  113,    0,   79,    0,  120,  122,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   74,    0,   83,   77,    0,    4,    0,    0,    0,    0,
   89,   87,   62,    0,    0,   35,   42,    0,    0,   75,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,   71,   72,  101,    0,    0,  110,    0,    0,
    0,   99,   98,   85,   82,    0,    0,   84,    0,   25,
    0,    0,    0,    0,    3,   40,    0,   86,  127,    0,
    0,    0,    0,  116,    0,    0,    0,    0,  111,    0,
  108,  104,    0,   96,    0,    0,    0,   81,   32,    0,
   23,    0,    0,   29,    0,    0,  126,    0,    0,   53,
    0,    0,   47,  100,    0,  106,  102,   80,   28,    0,
   27,    0,   21,    0,  125,    0,   20,    0,   52,   97,
   26,    0,   19,    0,   51,   48,    0,   31,    0,   30,
};
short yydgoto[] = {                                      12,
   13,  180,   15,   16,   17,   60,   18,   19,   20,   21,
   70,  181,  142,  143,  144,   33,  182,  183,   22,   23,
   24,   25,   26,   44,   45,   46,   47,   91,   48,   92,
  136,  137,  101,   27,  102,  131,   49,   50,
};
short yysindex[] = {                                    719,
  -24,  -40,  -38,  -26, -238,    0,    0,    0,    0, -227,
  791,    0,  815,    0,   -7,   -3, -210,    0,    0,    0,
   24,    0,    0,    0,    0,    0,  -26,    0,    0,  -19,
  246, -200,   12,    0, -242, -191,    0,    0,    0,    0,
   40,  154, -177,  607,  -30,    0,  732,   43,    0,    0,
    0,  -35, -170,  839,    0,    0,    0,    0,    0,   37,
 -242,  281,    0,   11,  -14,  -29, -159,    0, -155,   63,
    0,  246,    0,   64,    0,    0,  246,  246,  246,  246,
  499,  580,  246,  246,  246,  246,   62,  638,   66,   68,
    0,  651,    0,    0, -122,    0, -149, -142,   67,  732,
    0,    0,    0,  457,  258,    0,    0,   -4,   17,    0,
  -14,  -14,  -14,  -14,  246,  246,  -30,  246,  246,  -30,
  -14,  -14,    0,    0,    0,   79,   83,    0,   84,   85,
  749,    0,    0,    0,    0,  732, -141,    0, -126,    0,
 -210,  -98,   88,   96,    0,    0,   14,    0,    0,   33,
  -42,  -14,  936,    0,  -30,  -30,  -30,  -30,    0,   19,
    0,    0,   99,    0,  102,  103, -120,    0,    0,  -31,
    0, -210,  105,    0, -242,  763,    0, -105,  112,    0,
   38,  960,    0,    0,   42,    0,    0,    0,    0,  -20,
    0,  117,    0,   45,    0,  936,    0,  124,    0,    0,
    0,   48,    0,  960,    0,    0,  777,    0,   50,    0,
};
short yyrindex[] = {                                      0,
    0,    0,    0,    0,  218,    0,    0,    0,    0,    0,
    0,    0,  173,    0,  254,  496,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,  295,    0,  135,    1,    0,    0,    0,    0,
    0,    0,   25,    0,   49,    0,    0,  679,    0,    0,
    0,  331,  180,  182,    0,    0,    0,    0,    0,  387,
  135,    0,    0,    0,  455,    0,    0,    0,  143,    0,
    0,    0,    0,  693,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    0,  186,    0,    0,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  524,  538,  551,  577,    0,    0,   73,    0,    0,   97,
  610,  624,    0,    0,    0,    0,    0,    0,  852,  865,
    0,    0,    0,    0,    0,    0,    0,    0,  148,    0,
    0,    0,    0,    0,    0,    0,    0,    0,    0,    0,
  363,  469,    0,    0,  121,  161,  185,  422,    0,    0,
    0,    0,    0,    0,  878,  902,    0,    0,    0,    0,
    0,    0,    0,    0,  135,    0,    0,    0,    0,    0,
    0,   65,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    0,    0,    0,    0,   69,    0,    0,    0,    0,
    0,    0,    0,   72,    0,    0,    0,    0,    0,    0,
};
short yygindex[] = {                                      0,
  178,    5,  -11,    3,   18, -134,    0,    0,    0,    0,
  -53, -167,    0,   58,    0,    0,   -5,    7,    0,    0,
    0,    0,    0, 1118,  362,   15,  165,    0,  159,    0,
    0,   71,  -37,    0,  108,    0,    0,    0,
};
#define YYTABLESIZE 1239
short yytable[] = {                                      30,
  112,   35,  140,  178,   14,   32,  170,   99,  194,   93,
  104,   85,  189,   42,   68,   14,   86,   56,   43,   28,
   31,   63,   51,  201,  123,   43,  171,   98,   81,   52,
   82,  105,    7,    8,    9,   89,   57,  190,   98,  209,
   58,  112,  112,  112,  112,  112,   59,  112,   70,   90,
   89,  103,   69,   81,  138,   82,   66,  154,   56,   81,
  112,   82,  112,   61,   90,  123,  123,  123,  123,  123,
   67,  123,   64,  177,   71,   81,  129,   82,   69,   72,
   89,   75,   76,   94,  123,   96,  123,   95,   89,   70,
  130,   70,   70,   70,   90,   98,   65,  106,  138,  123,
  124,  107,   90,  108,  110,  125,  145,  147,   70,  132,
   70,  133,  141,   64,  146,   64,   64,   64,  153,  165,
   67,  192,  159,  112,   89,  112,  160,  161,  162,  168,
  169,  174,   64,  166,   64,  175,  176,   65,   90,   65,
   65,   65,  185,  184,  139,  186,  187,  123,  191,  123,
  188,  195,    7,    8,    9,  196,   65,  202,   65,  172,
   69,   67,  197,   67,   67,   67,  200,  206,  139,  203,
  207,   70,    5,   70,  210,   45,    7,    8,    9,    2,
   67,    6,   67,   43,   66,    1,  199,   33,   54,   46,
  204,   62,   69,   49,   73,   64,   50,   64,   43,  173,
   74,   69,  205,   69,   69,   69,  167,  148,  199,    0,
    0,    0,    0,    0,    0,    0,   29,   60,   34,   65,
   69,   65,   69,   71,    0,   66,    0,   66,   66,   66,
   36,   37,   38,   39,   40,    0,    0,   36,   37,   38,
   39,   40,    0,   67,   66,   67,   66,    0,    0,    0,
    0,   41,    0,   12,    0,    0,  112,  112,   41,    0,
    0,   60,  112,  112,  112,  112,    0,  112,  112,  112,
    0,    0,  112,  112,  112,  112,  112,  112,    0,  112,
  123,  123,    0,   69,    0,   69,  123,  123,  123,  123,
   43,  123,  123,  123,   34,    0,  123,  123,  123,  123,
  123,  123,   43,  123,   70,   70,    0,   66,    0,   66,
   70,   70,   70,   70,    0,   70,   70,   70,    0,    0,
   70,   70,   70,   70,   70,   70,    0,   70,   64,   64,
   24,    0,    0,    0,   64,   64,   64,   64,   34,   64,
   64,   64,   60,    0,   64,   64,   64,   64,   64,   64,
    0,   64,   65,   65,    0,    0,    0,    0,   65,   65,
   65,   65,  112,   65,   65,   65,    0,    0,   65,   65,
   65,   65,   65,   65,   24,   65,   67,   67,   12,    0,
    0,    0,   67,   67,   67,   67,   15,   67,   67,   67,
    0,    0,   67,   67,   67,   67,   67,   67,    0,   67,
    0,    0,    0,   88,  112,  112,  112,  112,    0,  112,
   36,   37,   38,   39,   40,    0,   69,   69,    0,   34,
    0,   68,   69,   69,   69,   69,    0,   69,   69,   69,
   15,   41,   69,   69,   69,   69,   69,   69,    0,   69,
   66,   66,  117,  120,    0,    0,   66,   66,   66,   66,
    0,   66,   66,   66,   61,   24,   66,   66,   66,   66,
   66,   66,   68,   66,   68,   68,   68,    0,  124,    0,
    0,    0,    0,   60,   60,    0,  155,  156,    0,  157,
  158,   68,    0,   68,   60,   60,   60,  112,    0,   60,
   60,    0,   60,   60,   60,   13,   60,  149,   61,    0,
    0,   43,   36,   37,   38,   39,   40,    0,    0,   12,
   12,   15,  124,    0,  151,   37,   38,   39,   40,    0,
   12,   12,   12,   41,    0,   12,   12,    0,   12,   12,
   12,    0,   12,    0,    0,   41,    0,    2,    0,    0,
  115,    0,    0,   43,   68,  116,   68,    3,   87,    4,
   34,   34,    5,    6,  100,    7,    8,    9,    0,   10,
    0,   34,   34,   34,   92,    0,   34,   34,    0,   34,
   34,   34,    0,   34,    0,    0,    0,    0,   93,   61,
    0,    0,    0,    0,    0,    0,   24,   24,    0,    0,
    0,   95,    0,  124,    0,    0,    0,   24,   24,   24,
    0,    0,   24,   24,    0,   24,   24,   24,    0,   24,
    0,    0,    0,    0,    0,    0,    0,   94,  112,  112,
   13,  118,    0,    0,   43,    0,  119,    0,    0,  112,
  112,  112,    0,    0,  112,  112,    0,  112,  112,  112,
    0,  112,   15,   15,    0,    0,   92,    0,    0,   81,
   90,   82,    0,   15,   15,   15,    0,    0,   15,   15,
   93,   15,   15,   15,   91,   15,   84,    0,   83,    0,
    0,    0,    0,   95,    0,    0,    0,   68,   68,    0,
    0,  128,    0,   68,   68,   68,   68,    0,   68,   68,
   68,    0,    0,   68,   68,   68,   68,   68,   68,   94,
   68,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   61,   61,    0,   36,   37,   38,   39,   40,    0,    0,
    0,   61,   61,   61,  124,  124,   61,   61,    0,   61,
   61,   61,   90,   61,   41,  124,  124,  124,    0,    0,
  124,  124,    0,  124,  124,  124,   91,  124,    0,    0,
    0,   13,   13,    0,    0,   36,   37,   38,   39,   40,
    0,    0,   13,   13,   13,    0,    0,   13,   13,    0,
   13,   13,   13,   88,   13,    0,   41,    0,    0,    0,
   92,    0,    0,    0,    0,    0,    0,    0,    0,    0,
   92,   92,   92,    0,   93,   92,   92,   92,   92,   92,
   92,   78,   92,    0,   93,   93,   93,   95,    0,   93,
   93,   93,   93,   93,   93,   76,   93,   95,   95,   95,
    0,    0,   95,   95,   95,   95,   95,   95,    0,   95,
    0,    0,    0,   94,    0,    0,   36,   37,   38,   39,
   40,   11,    0,   94,   94,   94,    0,    0,   94,   94,
   94,   94,   94,   94,   88,   94,    0,   41,    0,    0,
    0,    0,    0,    0,    0,    0,   90,    0,   77,   78,
   79,   80,    0,  164,    0,    0,   90,   90,   90,    0,
   91,   90,   90,   90,   90,   90,   90,  193,   90,    0,
   91,   91,   91,  126,    2,   91,   91,   91,   91,   91,
   91,  208,   91,    0,    3,  127,    4,    2,    0,    5,
    6,    0,    7,    8,    9,   53,   10,    3,   87,    4,
  134,  135,    5,    6,    0,    7,    8,    9,    0,   10,
    0,    0,    0,    0,    0,   78,    0,    0,    0,   55,
    0,    0,    0,    0,    0,   78,   78,   78,    0,   76,
   78,   78,   78,   78,   78,   78,    0,   78,    0,   76,
   76,   76,    0,   97,   76,   76,   76,   76,   76,   76,
    0,   76,    0,    0,    1,    2,  109,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    4,    2,  105,
    5,    6,    0,    7,    8,    9,    0,   10,    3,   87,
    4,    0,  107,    5,    6,    2,    7,    8,    9,    0,
   10,    0,    0,    0,    0,    3,  163,    4,    1,    2,
    5,    6,    0,    7,    8,    9,  103,   10,    0,    3,
  179,    4,    1,    2,    5,    6,    0,    7,    8,    9,
    0,   10,    0,    3,  179,    4,    1,    2,    5,    6,
    0,    7,    8,    9,    0,   10,    0,    3,    0,    4,
    0,    0,    5,    6,    0,    7,    8,    9,    0,   10,
    1,    2,    0,    0,    0,    0,    0,    0,    0,    0,
    0,    3,    0,    4,    0,    0,    5,    6,    0,    7,
    8,    9,    0,   10,    1,    2,    0,    0,    0,    0,
    0,    0,    0,    0,    0,    3,    0,    4,  109,    0,
    5,    6,    0,    7,    8,    9,    0,   10,  109,  109,
  109,  105,    0,  109,  109,    0,  109,  109,  109,    0,
  109,  105,  105,  105,  107,    0,  105,  105,    0,  105,
  105,  105,    0,  105,  107,  107,  107,   64,   65,  107,
  107,    0,  107,  107,  107,    0,  107,    0,  103,    0,
    0,    0,    0,    0,    0,    0,    0,    0,  103,  103,
  103,    0,    0,  103,  103,    0,  103,  103,  103,    0,
  103,    0,    0,    0,    0,    0,    0,    0,    0,  109,
    0,    1,    2,    0,  111,  112,  113,  114,    0,    0,
  121,  122,    3,  179,    4,    0,    0,    5,    6,    0,
    7,    8,    9,    0,   10,    1,    2,    0,    0,    0,
    0,  150,  152,    0,    0,    0,    3,  198,    4,    0,
    0,    5,    6,    0,    7,    8,    9,    0,   10,
};
short yycheck[] = {                                      40,
    0,   40,  125,   46,    0,   46,  141,   61,  176,   47,
   40,   42,   44,   40,  257,   11,   47,   13,   45,   44,
   61,   41,  261,   44,    0,   45,  125,   59,   43,  257,
   45,   61,  275,  276,  277,   47,   44,  172,   59,  207,
   44,   41,   42,   43,   44,   45,  257,   47,    0,   47,
   62,   41,   35,   43,   92,   45,  257,   41,   54,   43,
   60,   45,   62,   40,   62,   41,   42,   43,   44,   45,
   59,   47,    0,   41,  266,   43,   88,   45,   61,   40,
   92,  259,  260,   41,   60,  256,   62,  123,  100,   41,
   88,   43,   44,   45,   92,   59,    0,  257,  136,   85,
   86,  257,  100,   41,   41,   44,  256,   41,   60,   44,
   62,   44,   95,   41,  257,   43,   44,   45,  123,  131,
    0,  175,   44,  123,  136,  125,   44,   44,   44,  271,
  257,   44,   60,  131,   62,   40,  123,   41,  136,   43,
   44,   45,   44,  125,  267,   44,   44,  123,   44,  125,
  271,  257,  275,  276,  277,   44,   60,   41,   62,  142,
    0,   41,  125,   43,   44,   45,  125,   44,  267,  125,
  123,  123,    0,  125,  125,   41,  275,  276,  277,    0,
   60,    0,   62,   41,    0,    0,  182,   40,   11,  125,
  196,   27,  175,  125,   41,  123,  125,  125,   45,  142,
   42,   41,  196,   43,   44,   45,  136,  100,  204,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,    0,  257,  123,
   60,  125,   62,  266,   -1,   41,   -1,   43,   44,   45,
  257,  258,  259,  260,  261,   -1,   -1,  257,  258,  259,
  260,  261,   -1,  123,   60,  125,   62,   -1,   -1,   -1,
   -1,  278,   -1,    0,   -1,   -1,  256,  257,  278,   -1,
   -1,   44,  262,  263,  264,  265,   -1,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   -1,  123,   -1,  125,  262,  263,  264,  265,
   45,  267,  268,  269,    0,   -1,  272,  273,  274,  275,
  276,  277,   45,  279,  256,  257,   -1,  123,   -1,  125,
  262,  263,  264,  265,   -1,  267,  268,  269,   -1,   -1,
  272,  273,  274,  275,  276,  277,   -1,  279,  256,  257,
    0,   -1,   -1,   -1,  262,  263,  264,  265,   44,  267,
  268,  269,  125,   -1,  272,  273,  274,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,   -1,   -1,  262,  263,
  264,  265,    0,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,   44,  279,  256,  257,  125,   -1,
   -1,   -1,  262,  263,  264,  265,    0,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,  123,   42,   43,   44,   45,   -1,   47,
  257,  258,  259,  260,  261,   -1,  256,  257,   -1,  125,
   -1,    0,  262,  263,  264,  265,   -1,  267,  268,  269,
   44,  278,  272,  273,  274,  275,  276,  277,   -1,  279,
  256,  257,   81,   82,   -1,   -1,  262,  263,  264,  265,
   -1,  267,  268,  269,    0,  125,  272,  273,  274,  275,
  276,  277,   41,  279,   43,   44,   45,   -1,    0,   -1,
   -1,   -1,   -1,  256,  257,   -1,  115,  116,   -1,  118,
  119,   60,   -1,   62,  267,  268,  269,  125,   -1,  272,
  273,   -1,  275,  276,  277,    0,  279,   41,   44,   -1,
   -1,   45,  257,  258,  259,  260,  261,   -1,   -1,  256,
  257,  125,   44,   -1,  257,  258,  259,  260,  261,   -1,
  267,  268,  269,  278,   -1,  272,  273,   -1,  275,  276,
  277,   -1,  279,   -1,   -1,  278,   -1,  257,   -1,   -1,
   42,   -1,   -1,   45,  123,   47,  125,  267,  268,  269,
  256,  257,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,  267,  268,  269,   41,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,   -1,   -1,   -1,   -1,   41,  125,
   -1,   -1,   -1,   -1,   -1,   -1,  256,  257,   -1,   -1,
   -1,   41,   -1,  125,   -1,   -1,   -1,  267,  268,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   41,  256,  257,
  125,   42,   -1,   -1,   45,   -1,   47,   -1,   -1,  267,
  268,  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,
   -1,  279,  256,  257,   -1,   -1,  123,   -1,   -1,   43,
   41,   45,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  123,  275,  276,  277,   41,  279,   60,   -1,   62,   -1,
   -1,   -1,   -1,  123,   -1,   -1,   -1,  256,  257,   -1,
   -1,   44,   -1,  262,  263,  264,  265,   -1,  267,  268,
  269,   -1,   -1,  272,  273,  274,  275,  276,  277,  123,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  256,  257,   -1,  257,  258,  259,  260,  261,   -1,   -1,
   -1,  267,  268,  269,  256,  257,  272,  273,   -1,  275,
  276,  277,  123,  279,  278,  267,  268,  269,   -1,   -1,
  272,  273,   -1,  275,  276,  277,  123,  279,   -1,   -1,
   -1,  256,  257,   -1,   -1,  257,  258,  259,  260,  261,
   -1,   -1,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,  123,  279,   -1,  278,   -1,   -1,   -1,
  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
  267,  268,  269,   -1,  257,  272,  273,  274,  275,  276,
  277,  123,  279,   -1,  267,  268,  269,  257,   -1,  272,
  273,  274,  275,  276,  277,  123,  279,  267,  268,  269,
   -1,   -1,  272,  273,  274,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,  257,   -1,   -1,  257,  258,  259,  260,
  261,  123,   -1,  267,  268,  269,   -1,   -1,  272,  273,
  274,  275,  276,  277,  123,  279,   -1,  278,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,  257,   -1,  262,  263,
  264,  265,   -1,  125,   -1,   -1,  267,  268,  269,   -1,
  257,  272,  273,  274,  275,  276,  277,  125,  279,   -1,
  267,  268,  269,  256,  257,  272,  273,  274,  275,  276,
  277,  125,  279,   -1,  267,  268,  269,  257,   -1,  272,
  273,   -1,  275,  276,  277,  125,  279,  267,  268,  269,
  270,  271,  272,  273,   -1,  275,  276,  277,   -1,  279,
   -1,   -1,   -1,   -1,   -1,  257,   -1,   -1,   -1,  125,
   -1,   -1,   -1,   -1,   -1,  267,  268,  269,   -1,  257,
  272,  273,  274,  275,  276,  277,   -1,  279,   -1,  267,
  268,  269,   -1,  125,  272,  273,  274,  275,  276,  277,
   -1,  279,   -1,   -1,  256,  257,  125,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,  257,  125,
  272,  273,   -1,  275,  276,  277,   -1,  279,  267,  268,
  269,   -1,  125,  272,  273,  257,  275,  276,  277,   -1,
  279,   -1,   -1,   -1,   -1,  267,  268,  269,  256,  257,
  272,  273,   -1,  275,  276,  277,  125,  279,   -1,  267,
  268,  269,  256,  257,  272,  273,   -1,  275,  276,  277,
   -1,  279,   -1,  267,  268,  269,  256,  257,  272,  273,
   -1,  275,  276,  277,   -1,  279,   -1,  267,   -1,  269,
   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
  256,  257,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,
   -1,  267,   -1,  269,   -1,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,   -1,
   -1,   -1,   -1,   -1,   -1,  267,   -1,  269,  257,   -1,
  272,  273,   -1,  275,  276,  277,   -1,  279,  267,  268,
  269,  257,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,  267,  268,  269,  257,   -1,  272,  273,   -1,  275,
  276,  277,   -1,  279,  267,  268,  269,   30,   31,  272,
  273,   -1,  275,  276,  277,   -1,  279,   -1,  257,   -1,
   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,  267,  268,
  269,   -1,   -1,  272,  273,   -1,  275,  276,  277,   -1,
  279,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   -1,   72,
   -1,  256,  257,   -1,   77,   78,   79,   80,   -1,   -1,
   83,   84,  267,  268,  269,   -1,   -1,  272,  273,   -1,
  275,  276,  277,   -1,  279,  256,  257,   -1,   -1,   -1,
   -1,  104,  105,   -1,   -1,   -1,  267,  268,  269,   -1,
   -1,  272,  273,   -1,  275,  276,  277,   -1,  279,
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
"programa : '{' sentencias",
"programa : sentencias '}'",
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
"parametro : tipo",
"parametro : IDENTIFICADOR",
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
"bloque_condicion : '(' condicion ')'",
"bloque_condicion : '(' condicion",
"bloque_condicion : condicion ')'",
"bloque_condicion : condicion",
"bloque_condicion : '(' ')'",
"cuerpo_if : cuerpo_then else_if cuerpo_else END_IF",
"cuerpo_if : cuerpo_then cuerpo_else END_IF",
"cuerpo_if : cuerpo_then END_IF",
"cuerpo_then : bloque_ejecutables",
"cuerpo_else : bloque_ejecutables",
"else_if : ELSE",
"ciclo_while : inicio_while bloque_condicion DO cuerpo_while",
"ciclo_while : inicio_while bloque_condicion cuerpo_while",
"inicio_while : WHILE",
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
#line 273 "./gramaticaComCHZGenerativa.y"
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
#line 706 "y.tab.c"
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
{ yywarning("Se detectó la falta de llaves en el programa"); }
break;
case 6:
#line 69 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la ultima llave del programa"); }
break;
case 7:
#line 70 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó la falta de la primera llave del programa"); }
break;
case 12:
#line 79 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 13:
#line 80 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 14:
#line 81 "./gramaticaComCHZGenerativa.y"
{ }
break;
case 15:
#line 84 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable");}
break;
case 17:
#line 86 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de objeto");}
break;
case 18:
#line 87 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de función");}
break;
case 19:
#line 90 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope();}
break;
case 20:
#line 91 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de un nombre en la función"); }
break;
case 21:
#line 92 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yywarning("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 22:
#line 95 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "funcion"); if(diff == 0){yyerror("Redeclaración de función en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "funcion");} tableSymbol->addScope(yyvsp[0]->ptr); }
break;
case 23:
#line 98 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase");}
break;
case 24:
#line 99 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de clase adelantada");}
break;
case 25:
#line 100 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó una declaración de clases vacía");}
break;
case 26:
#line 102 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 28:
#line 104 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó declaración de variable en clase");}
break;
case 30:
#line 109 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); }
break;
case 31:
#line 110 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 32:
#line 113 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope(yyvsp[0]->ptr);}
break;
case 33:
#line 114 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de método"); }
break;
case 37:
#line 124 "./gramaticaComCHZGenerativa.y"
{ typeAux = "short"; yyval->type ="short";}
break;
case 38:
#line 125 "./gramaticaComCHZGenerativa.y"
{ typeAux = "unsigned int"; yyval->type = "unsigned int";}
break;
case 39:
#line 126 "./gramaticaComCHZGenerativa.y"
{ typeAux = "float"; yyval->type = "float";}
break;
case 40:
#line 129 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 41:
#line 131 "./gramaticaComCHZGenerativa.y"
{ int diff = tableSymbol->getDiffOffScope(yyvsp[0]->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaración de variable en el mismo ámbito");}else{symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, typeAux, tableSymbol->getScope(),"var");} }
break;
case 42:
#line 134 "./gramaticaComCHZGenerativa.y"
{ symbol* newIdentificador = setNewScope(yyvsp[0]->ptr, yyvsp[-1]->type, tableSymbol->getScope(), "parametro"); yyval->ptr = newIdentificador->lexema; yyval->type = yyvsp[-1]->type;}
break;
case 43:
#line 135 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de nombre de parámetro"); }
break;
case 44:
#line 136 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de tipo de parámetro"); }
break;
case 46:
#line 140 "./gramaticaComCHZGenerativa.y"
{yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
break;
case 50:
#line 145 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 51:
#line 146 "./gramaticaComCHZGenerativa.y"
{yywarning("Se detectó código posterior a un return"); }
break;
case 57:
#line 154 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("print", tableSymbol->getSymbol(yyvsp[0]->ptr)->value, ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 60:
#line 157 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
break;
case 61:
#line 160 "./gramaticaComCHZGenerativa.y"
{ tableSymbol->deleteSymbol(yyvsp[-2]->ptr); symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(yyvsp[-2]->ptr+tableSymbol->getScope(), "var"); if(symbolFinded == nullptr){yyerror("No se encontró declaración previa de la variable "+ yyvsp[-2]->ptr);}else{checkTypesAsignation(symbolFinded->type, yyvsp[0]->type); int number = addTercet("=", symbolFinded->lexema, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number);} }
break;
case 64:
#line 168 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("+", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 65:
#line 169 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("-", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 66:
#line 170 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 67:
#line 171 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 68:
#line 172 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 69:
#line 173 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-3]->type, yyvsp[0]->type)){yyval->type=yyvsp[-3]->type;}else{yyval->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", yyvsp[-3]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 70:
#line 174 "./gramaticaComCHZGenerativa.y"
{ yyval->type = yyvsp[0]->type; yyval->ptr = yyvsp[0]->ptr; }
break;
case 71:
#line 177 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("*", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 72:
#line 178 "./gramaticaComCHZGenerativa.y"
{ if(checkTypesOperation(yyvsp[-2]->type, yyvsp[0]->type)){yyval->type=yyvsp[-2]->type;}else{yyval->type="error";}; Tercet *t = new Tercet("/", yyvsp[-2]->ptr, yyvsp[0]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number); }
break;
case 73:
#line 179 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 74:
#line 182 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}}
break;
case 75:
#line 185 "./gramaticaComCHZGenerativa.y"
{ int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 76:
#line 186 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de ultimo paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 77:
#line 187 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de primer paréntesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 78:
#line 188 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de parantesis en condición"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 79:
#line 189 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta de condición en el bloque de control IF"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); yyval->ptr = charTercetoId + to_string(number);}
break;
case 81:
#line 193 "./gramaticaComCHZGenerativa.y"
{ yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
break;
case 85:
#line 201 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = popTercet();  if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2));} int number =  addTercetAndStack("BI", "", ""); yyval->ptr = charTercetoId + to_string(number); }
break;
case 86:
#line 203 "./gramaticaComCHZGenerativa.y"
{ Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet(); int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 87:
#line 204 "./gramaticaComCHZGenerativa.y"
{ yywarning("Falta de DO en WHILE-DO"); Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet();int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} yyval->ptr = charTercetoId + to_string(number);}
break;
case 88:
#line 207 "./gramaticaComCHZGenerativa.y"
{ addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
break;
case 90:
#line 220 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 91:
#line 221 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 92:
#line 222 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("==", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 93:
#line 223 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("!!", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 94:
#line 224 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet(">=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 95:
#line 225 "./gramaticaComCHZGenerativa.y"
{ checkTypesCompare(yyvsp[-2]->type, yyvsp[0]->type); int number = addTercet("<=", yyvsp[-2]->ptr, yyvsp[0]->ptr); yyval->ptr = charTercetoId + to_string(number); }
break;
case 99:
#line 231 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 103:
#line 237 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 105:
#line 239 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 106:
#line 240 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 107:
#line 241 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
break;
case 108:
#line 242 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia declarativa en bloque de control"); }
break;
case 109:
#line 243 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una falta de coma"); }
break;
case 110:
#line 244 "./gramaticaComCHZGenerativa.y"
{ yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
break;
case 111:
#line 245 "./gramaticaComCHZGenerativa.y"
{ yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
break;
case 112:
#line 248 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = tableSymbol->getSymbol(yyvsp[0]->ptr)->type;}
break;
case 113:
#line 249 "./gramaticaComCHZGenerativa.y"
{ Tercet * t = new Tercet("+", yyvsp[-1]->ptr, yyvsp[-1]->ptr); int number = tableTercets->add(t); yyval->ptr = charTercetoId + to_string(number);yyval->type = tableSymbol->getSymbol(yyvsp[-1]->ptr)->type;}
break;
case 114:
#line 250 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 115:
#line 251 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 116:
#line 252 "./gramaticaComCHZGenerativa.y"
{ int number = addTercet("tof", " ", yyvsp[-1]->ptr); yyval->ptr = charTercetoId + to_string(number); yyval->type = "float"; }
break;
case 117:
#line 255 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 118:
#line 256 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 119:
#line 259 "./gramaticaComCHZGenerativa.y"
{ checkIntegerShort(yyvsp[0]->ptr); yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 120:
#line 260 "./gramaticaComCHZGenerativa.y"
{ string newLexema = checkIntegerShortNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 121:
#line 261 "./gramaticaComCHZGenerativa.y"
{ yyval->ptr = yyvsp[0]->ptr; yyval->type = yyvsp[0]->type;}
break;
case 122:
#line 262 "./gramaticaComCHZGenerativa.y"
{ string newLexema = setFloatNegative(yyvsp[0]->ptr); yyval->ptr = newLexema; yyval->type = yyvsp[0]->type;}
break;
case 123:
#line 263 "./gramaticaComCHZGenerativa.y"
{ yyerror("Falta constante numérica en la expresión"); }
break;
case 124:
#line 266 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 125:
#line 267 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 126:
#line 268 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
case 127:
#line 269 "./gramaticaComCHZGenerativa.y"
{ yyPrintInLine("Se detectó un acceso a un objeto");}
break;
#line 1214 "y.tab.c"
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
