%{

#include "include/types.hpp"
#include "include/Lexico.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

void yyerror(string s, int* lineNumber){
    cerr << "Error sintactico" << s << endl;
    cerr << "\033[31m" << "Linea: " << *lineNumber << "-> Error: parsing failed " << "\033[0m"<< endl;
};

%}


%token IDENTIFICADOR
%token ENTERO_SIN_SIGNO
%token ENTERO_CORTO
%token PUNTO_FLOTANTE
%token CADENA_CARACTERES
%token COMPARADOR_IGUAL_IGUAL
%token COMPARADOR_DISTINTO
%token COMPARADOR_MENOR_IGUAL
%token COMPARADOR_MAYOR_IGUAL
%token OPERADOR_SUMA_SUMA

%token VOID RETURN
%token IF ELSE END_IF
%token PRINT
%token WHILE DO
%token SHORT UINT FLOAT
%token TOF
%token CLASS

%start programa

%%

programa    :   '{' sentencias '}'      /* es el programa que debe arrancar y terminar con '{' '}' */
            |   '{' '}'                 /* podría ser un programa sin nada, hay que preguntar! */               { cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se está compilando un programa sin contenido" << "\033[0m" << endl;}

sentencias  :   sentencia sentencias
            |   sentencia
            ;

sentencia   :   declarativa                                     { cout << "Se detectó una sentencia declarativa " << endl;}
            |   ejecutable                                      { cout << "Se detectó una sentencia ejecutable " << endl;}
            ;

declarativa :   tipo lista_de_variables ','
            |   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','
            |   declaracion_clase ','
            |   declaracion_objeto ','
            ;


declaracion_clase   :   CLASS IDENTIFICADOR '{' lista_de_atributos lista_de_metodos '}' /* primero van los atributos y luego los métodos */
                    |   CLASS IDENTIFICADOR /* fordward declaration*/
                    ;

lista_de_atributos  :    tipo IDENTIFICADOR ',' lista_de_atributos
                    |    /* vacío */
                    ;

lista_de_metodos    :   metodo lista_de_metodos 
                    |   /* vacío */
                    ;

metodo  :   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','
        ;

declaracion_objeto  :   IDENTIFICADOR lista_de_objetos ','
                    ;

lista_de_objetos    :   IDENTIFICADOR ';' lista_de_objetos 
                    |   IDENTIFICADOR
                    ;

tipo    :   SHORT | UINT | FLOAT
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR
                    |   IDENTIFICADOR
                    ;

parametro   :   tipo IDENTIFICADOR
            |   /* vacío */
            ;

cuerpo_de_la_funcion    :   sentencia cuerpo_de_la_funcion
                        |   RETURN ','
                        ;

ejecutable  :    asignacion
            |    invocacion
            |    seleccion
            |    PRINT CADENA_CARACTERES ','
            |    ciclo_while
            |    acceso_objeto
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica ','
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')' ','
           | IDENTIFICADOR '(' ')' ','
           ;


expresion_aritmetica : expresion_aritmetica '+' termino
                    | expresion_aritmetica '-' termino
                    | expresion_aritmetica '-' '*' termino      { cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
                    | expresion_aritmetica '+' '*' termino      { cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
                    | expresion_aritmetica '-' '/' termino      { cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '-'" << "\033[0m" << endl;}
                    | expresion_aritmetica '+' '/' termino      { cerr << "\033[33m" <<"Linea: " << *(lineNumber) << "-> Warning: Se detectó un error en operador, quedará '+'" << "\033[0m" << endl;}
                    | termino
                    ;

termino : termino '*' factor
        | termino '/' factor
        | factor
        ;

factor : IDENTIFICADOR
       | IDENTIFICADOR OPERADOR_SUMA_SUMA
       | constante
       | TOF '(' expresion_aritmetica ')'       /* conversión de tipo */
       ;



seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables END_IF ','
          | IF '(' condicion ')' bloque_ejecutables END_IF ','
          ;

ciclo_while : WHILE '(' condicion ')' DO bloque_ejecutables ','
            ;

condicion : expresion_aritmetica '>' expresion_aritmetica
          | expresion_aritmetica '<' expresion_aritmetica
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   ejecutable
                    ;

sentencias_ejecutables  :   ejecutable sentencias_ejecutables 
                        |   ejecutable
                        ;

constante   :   ENTERO_SIN_SIGNO                        { cout << "Se detectó un entero sin signo: " << $1 << endl;}
            |   ENTERO_CORTO                            { cout << "Se detectó un entero corto: " << $1 << endl;}
            |   '-' ENTERO_CORTO                        { cout << "Se detectó un entero corto: " << $1 << endl;}
            |   PUNTO_FLOTANTE                          { cout << "Se detectó un punto flotante: " << $1 << endl;}
            |   '-' PUNTO_FLOTANTE                      { cout << "Se detectó un punto flotante: " << $1 << endl;}
            |   CADENA_CARACTERES                       { cout << "Se detectó una cadena de caracteres: " << $1 << endl;}
            ;

acceso_objeto   :   IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica ','
                |   IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR ','
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' parametro ')' ','
                ;

%%
