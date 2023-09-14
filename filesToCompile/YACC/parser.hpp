/* A Bison parser, made by GNU Bison 3.8.2.  */

/* Bison interface for Yacc-like parsers in C

   Copyright (C) 1984, 1989-1990, 2000-2015, 2018-2021 Free Software Foundation,
   Inc.

   This program is free software: you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation, either version 3 of the License, or
   (at your option) any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program.  If not, see <https://www.gnu.org/licenses/>.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* DO NOT RELY ON FEATURES THAT ARE NOT DOCUMENTED in the manual,
   especially those whose name start with YY_ or yy_.  They are
   private implementation details that can be changed or removed.  */

#ifndef YY_YY_PARSER_HPP_INCLUDED
# define YY_YY_PARSER_HPP_INCLUDED
/* Debug traces.  */
#ifndef YYDEBUG
# define YYDEBUG 0
#endif
#if YYDEBUG
extern int yydebug;
#endif

/* Token kinds.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
  enum yytokentype
  {
    YYEMPTY = -2,
    YYEOF = 0,                     /* "end of file"  */
    YYerror = 256,                 /* error  */
    YYUNDEF = 257,                 /* "invalid token"  */
    IDENTIFICADOR = 258,           /* IDENTIFICADOR  */
    ENTERO_SIN_SIGNO = 259,        /* ENTERO_SIN_SIGNO  */
    ENTERO_CORTO = 260,            /* ENTERO_CORTO  */
    PUNTO_FLOTANTE = 261,          /* PUNTO_FLOTANTE  */
    CADENA_CARACTERES = 262,       /* CADENA_CARACTERES  */
    COMPARADOR_IGUAL_IGUAL = 263,  /* COMPARADOR_IGUAL_IGUAL  */
    COMPARADOR_DISTINTO = 264,     /* COMPARADOR_DISTINTO  */
    COMPARADOR_MENOR_IGUAL = 265,  /* COMPARADOR_MENOR_IGUAL  */
    COMPARADOR_MAYOR_IGUAL = 266,  /* COMPARADOR_MAYOR_IGUAL  */
    OPERADOR_SUMA_SUMA = 267,      /* OPERADOR_SUMA_SUMA  */
    VOID = 268,                    /* VOID  */
    RETURN = 269,                  /* RETURN  */
    IF = 270,                      /* IF  */
    ELSE = 271,                    /* ELSE  */
    END_IF = 272,                  /* END_IF  */
    PRINT = 273,                   /* PRINT  */
    WHILE = 274,                   /* WHILE  */
    DO = 275,                      /* DO  */
    SHORT = 276,                   /* SHORT  */
    UINT = 277,                    /* UINT  */
    FLOAT = 278,                   /* FLOAT  */
    TOF = 279,                     /* TOF  */
    CLASS = 280                    /* CLASS  */
  };
  typedef enum yytokentype yytoken_kind_t;
#endif
/* Token kinds.  */
#define YYEMPTY -2
#define YYEOF 0
#define YYerror 256
#define YYUNDEF 257
#define IDENTIFICADOR 258
#define ENTERO_SIN_SIGNO 259
#define ENTERO_CORTO 260
#define PUNTO_FLOTANTE 261
#define CADENA_CARACTERES 262
#define COMPARADOR_IGUAL_IGUAL 263
#define COMPARADOR_DISTINTO 264
#define COMPARADOR_MENOR_IGUAL 265
#define COMPARADOR_MAYOR_IGUAL 266
#define OPERADOR_SUMA_SUMA 267
#define VOID 268
#define RETURN 269
#define IF 270
#define ELSE 271
#define END_IF 272
#define PRINT 273
#define WHILE 274
#define DO 275
#define SHORT 276
#define UINT 277
#define FLOAT 278
#define TOF 279
#define CLASS 280

/* Value type.  */
#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef int YYSTYPE;
# define YYSTYPE_IS_TRIVIAL 1
# define YYSTYPE_IS_DECLARED 1
#endif


extern YYSTYPE yylval;


int yyparse (void);


#endif /* !YY_YY_PARSER_HPP_INCLUDED  */
