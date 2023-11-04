%{

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

// generamos la tabla de simbolos
TableSymbol* tableSymbol = new TableSymbol();

// generamos la tabla de palabras reservadas
TableReservedWord* tableRWords = new TableReservedWord();

int lineNumber = 1;
bool isErrorInCode = false;

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

programa    :   '{' sentencias '}'              /* es el programa que debe arrancar y terminar con '{' '}' */ { yyPrintInLine("Se detecto un programa");}
            |   '{' '}'                         /* podria ser un programa sin nada*/               { yywarning("Se esta compilando un programa sin contenido");}
            |   '{' sentencias '}' error                                                           { yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   '{' '}' error                       { yywarning("Se esta compilando un programa sin contenido"); yyerror("Se detecto contenido luego de finalizado el programa");}             
sentencias  :   sentencias sentencia
            |   sentencia
            ;

sentencia   :   declarativa ','                                    
            |   ejecutable ','    
            |   declarativa                                      { yyerror("Se detecto una falta de coma"); }                                 
            |   ejecutable                                       { yyerror("Se detecto una falta de coma"); }
            |   error ','                                        {  }
            ;

declarativa :   tipo lista_de_variables                                             { yyPrintInLine("Se detecto declaracion de variable");}
            |   declaracion_clase                                                    
            |   declaracion_objeto                                                  { yyPrintInLine("Se detecto declaracion de objeto");}
            |   declaracion_funcion                                                 { yyPrintInLine("Se detecto declaracion de funcion");}
            ;

declaracion_funcion     :       VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}'  
                        |       VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'                     {yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       VOID IDENTIFICADOR '(' parametro ')' '{' '}'                            {yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        ;

declaracion_clase   :   CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'         /* Los atributos y metodos van en desorden */ { yyPrintInLine("Se detecto declaracion de clase");}
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { yyPrintInLine("Se detecto declaracion de clase adelantada");}
                    |   CLASS IDENTIFICADOR '{' '}'                             {yywarning("Se detecto una declaracion de clases vacia");}
                    ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_variables ','           { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       lista_atributos_y_metodos metodo ','                                 
                                |       tipo lista_de_variables ','                                    { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       metodo ','
                                ;


metodo  :   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}'       { yyPrintInLine("Se detecto declaracion de metodo de clase");}
        |   VOID IDENTIFICADOR '(' parametro ')' '{' '}'                            {yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
        ;

declaracion_objeto  :   IDENTIFICADOR lista_de_objetos
                    ;

lista_de_objetos    :   lista_de_objetos ';' IDENTIFICADOR  
                    |   IDENTIFICADOR
                    ;

tipo    :   SHORT | UINT | FLOAT
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR
                    |   IDENTIFICADOR
                    ;

parametro   :   tipo IDENTIFICADOR
            |   /* vacio */
            ;

cuerpo_de_la_funcion    :   cuerpo_de_la_funcion_sin_return                             {yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        |   cuerpo_de_la_funcion_con_return
                        ;
cuerpo_de_la_funcion_con_return    :   cuerpo_de_la_funcion_sin_return RETURN ','
                                   |   RETURN ','
                                   |   RETURN ',' cuerpo_de_la_funcion_sin_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   |   RETURN ',' cuerpo_de_la_funcion_con_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   ;
cuerpo_de_la_funcion_sin_return    :   cuerpo_de_la_funcion_sin_return sentencia 
                                   |   sentencia
                                   ;
ejecutable  :    asignacion
            |    invocacion                                     { yyPrintInLine("Se detecto invacion a funcion");}
            |    seleccion
            |    PRINT CADENA_CARACTERES                    { yyPrintInLine("Se detecto una impresion");}
            |    ciclo_while
            |    acceso_objeto
            |    PRINT                                      { yyerror("Se detecto la falta de una cadena de caracteres al querer imprimir");}
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica          { yyPrintInLine("Se detecto asignacion");}
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '(' ')'                           
           ;


expresion_aritmetica : expresion_aritmetica '+' termino
                    | expresion_aritmetica '-' termino
                    | expresion_aritmetica '-' '*' termino      { yywarning("Se detecto un error en operador, quedara '-'");}
                    | expresion_aritmetica '+' '*' termino      { yywarning("Se detecto un error en operador, quedara '+'");}
                    | expresion_aritmetica '-' '/' termino      { yywarning("Se detecto un error en operador, quedara '-'");}
                    | expresion_aritmetica '+' '/' termino      { yywarning("Se detecto un error en operador, quedara '+'");}
                    | termino
                    ;

termino : termino '*' factor
        | termino '/' factor
        | factor
        ;

seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables END_IF   { yyPrintInLine("Se detecto un bloque de control IF-ELSE");}
          | IF '(' condicion ')' bloque_ejecutables bloque_ejecutables END_IF   { yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
          | IF '(' condicion ')' bloque_ejecutables END_IF                           { yyPrintInLine("Se detecto un bloque de control IF");}
          | IF '(' ')' bloque_ejecutables END_IF                     {yyerror("Falta de condicion en el bloque de control IF");}
          ;

ciclo_while : WHILE '(' condicion ')' DO bloque_ejecutables          { yyPrintInLine("Se detecto un WHILE-DO");}
            ;

condicion : expresion_aritmetica '>' expresion_aritmetica
          | expresion_aritmetica '<' expresion_aritmetica
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   ejecutable ','
                    |   declarativa  ','                  { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   RETURN ','
                    ;

sentencias_ejecutables  :   sentencias_ejecutables ejecutable ','
                        |   sentencias_ejecutables ejecutable                   { yyerror("Se detecto una falta de coma"); }
                        |   ejecutable ','
                        |   ejecutable                                          { yyerror("Se detecto una falta de coma"); }
                        |   sentencias_ejecutables declarativa ','              { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                        |   sentencias_ejecutables declarativa                  { yyerror("Se detecto una sentencia declarativa en bloque de control y la falta de coma"); }
                        |   declarativa ','                                     { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                        |   declarativa                                         { yyerror("Se detecto una falta de coma"); }
                        |   ','                                                 { yywarning("Se detecto una sentencia vacia dentro del bloque de sentencias ejecutables"); }
                        |   error ','                                           { yyerror("Se detecto una sentencia invalida dentro del bloque de sentencias ejecutables"); }
                        ;
factor : IDENTIFICADOR
       | IDENTIFICADOR OPERADOR_SUMA_SUMA
       | constanteSinSigno
       | constanteConSigno
       | TOF '(' expresion_aritmetica ')'       /* conversion de tipo */
       ;

constanteSinSigno       :       ENTERO_SIN_SIGNO                        
                        |       CADENA_CARACTERES                       
                        ;

constanteConSigno       :       ENTERO_CORTO                            { checkIntegerShort($1);}
                        |       '-' ENTERO_CORTO                        { checkIntegerShortNegative($2);}
                        |       PUNTO_FLOTANTE                          
                        |       '-' PUNTO_FLOTANTE                      
                        |       '-'                                     { yyerror("Falta constante numerica en la expresion"); }
                        ;

acceso_objeto   :   IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica                 { yyPrintInLine("Se detecto un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR      { yyPrintInLine("Se detecto un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'             { yyPrintInLine("Se detecto un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' ')'                                  { yyPrintInLine("Se detecto un acceso a un objeto");}
                ;

%%
void checkIntegerShort(string lexeme){
        symbol* sm = tableSymbol->getSymbol(lexeme);
        if(sm != nullptr ){
            if(atoi(sm->value.c_str()) >= 128){
                    yyerror("Entero corto fuera de rango { -128 - 127 }");
            }
        }
        else{
                yyerror("No se encuentra el token en la tabla de simbolo");
        }
}
void checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        lexeme = '-'+lexeme;

        size_t pos = lexeme.find("_s");
        string value = lexeme.substr(0, pos);
        
        tableSymbol->insert(lexeme, lexeme, value, "short");
}