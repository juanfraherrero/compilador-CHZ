%{

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

programa    :   '{' sentencias '}'              /* es el programa que debe arrancar y terminar con '{' '}' */ { yyPrintInLine("Se detectó un programa");}
            |   '{' '}'                         /* podría ser un programa sin nada*/               { yywarning("Se está compilando un programa sin contenido");}
            |   '{' sentencias '}' error                                                           { yyerror("Se detectó contenido luego de finalizado el programa");}             
            |   '{' '}' error                       { yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}             
sentencias  :   sentencia sentencias
            |   sentencia
            ;

sentencia   :   declarativa                                     
            |   ejecutable                                      
            |   ','                                              { yyerror("Se detectó una sentencia vacía"); }
            |   error ','                                       { yyerror("Se detectó una sentencia inválida"); }
            ;

declarativa :   tipo lista_de_variables ','                                             { yyPrintInLine("Se detectó declaración de variable");}
            |   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','   { yyPrintInLine("Se detectó declaración de función");}
            |   declaracion_clase ','                                                   
            |   declaracion_objeto ','                                                  { yyPrintInLine("Se detectó declaración de objeto");}
            |   lista_de_variables ','                                          { yyerror("Se detectó la falta de un tipo en la declaración de variables"); }
            |   VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','         {yyerror("Se detectó la falta de un nombre en la función"); }
            |   VOID IDENTIFICADOR '(' parametro ')' '{' '}' ','                {yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
            ;


declaracion_clase   :   CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'         /* Los atributos y métodos van en desorden */ { yyPrintInLine("Se detectó declaración de clase");}
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { yyPrintInLine("Se detectó declaración de clase adelantada");}
                    |   CLASS IDENTIFICADOR '{' '}'                             {yywarning("Se detectó una declaración de clases vacía");}
                    ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_variables ','            { yyPrintInLine("Se detectó declaración de variable en clase");}
                                |       lista_atributos_y_metodos metodo                                 
                                |       tipo lista_de_variables ','                                     { yyPrintInLine("Se detectó declaración de variable en clase");}
                                |       metodo
                                ;


metodo  :   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','       { yyPrintInLine("Se detectó declaración de método de clase");}
        |   VOID IDENTIFICADOR '(' parametro ')' '{' '}' ','                            {yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
        ;

declaracion_objeto  :   IDENTIFICADOR lista_de_objetos
                    ;

lista_de_objetos    :   IDENTIFICADOR ';' lista_de_objetos 
                    |   IDENTIFICADOR
                    |   IDENTIFICADOR ';'                                     { yyerror("Falta identificador en la declaración de un objeto"); }
                    ;

tipo    :   SHORT | UINT | FLOAT
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR
                    |   IDENTIFICADOR
                    ;

parametro   :   tipo IDENTIFICADOR
            |   /* vacío */
            ;

cuerpo_de_la_funcion    :   cuerpo_de_la_funcion_sin_return                             {yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
                        |   cuerpo_de_la_funcion_con_return
                        ;
cuerpo_de_la_funcion_con_return    :   cuerpo_de_la_funcion_sin_return RETURN ','
                                   |   RETURN ','
                                   |   RETURN ',' cuerpo_de_la_funcion_sin_return       {yywarning("Se detectó código posterior a un return"); }
                                   |   RETURN ',' cuerpo_de_la_funcion_con_return       {yywarning("Se detectó código posterior a un return"); }
                                   ;
cuerpo_de_la_funcion_sin_return    :   sentencia cuerpo_de_la_funcion_sin_return
                                   |   sentencia
                                   ;
ejecutable  :    asignacion
            |    invocacion                                     { yyPrintInLine("Se detectó invación a función");}
            |    seleccion
            |    PRINT CADENA_CARACTERES ','                    { yyPrintInLine("Se detectó una impresión");}
            |    ciclo_while
            |    acceso_objeto
            |    PRINT ','                                      { yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica ','         { yyPrintInLine("Se detectó asignación");}
           | IDENTIFICADOR '=' ','                              { yyerror("Se detectó la falta de una expresión arimética en la sentencia ejecutable");}
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')' ','     
           | IDENTIFICADOR '(' ')' ','                          
           ;


expresion_aritmetica : expresion_aritmetica '+' termino
                    | expresion_aritmetica '-' termino
                    | expresion_aritmetica '-' '*' termino      { yywarning("Se detectó un error en operador, quedará '-'");}
                    | expresion_aritmetica '+' '*' termino      { yywarning("Se detectó un error en operador, quedará '+'");}
                    | expresion_aritmetica '-' '/' termino      { yywarning("Se detectó un error en operador, quedará '-'");}
                    | expresion_aritmetica '+' '/' termino      { yywarning("Se detectó un error en operador, quedará '+'");}
                    | termino
                    ;

termino : termino '*' factor
        | termino '/' factor
        | factor
        ;

seleccion : IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables END_IF ','  { yyPrintInLine("Se detectó un bloque de control IF-ELSE");}
          | IF '(' condicion ')' bloque_ejecutables bloque_ejecutables END_IF ','  { yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
          | IF '(' condicion ')' bloque_ejecutables ELSE bloque_ejecutables ','  { yyerror("Falta de END_IF en el bloque de control IF-ELSE");}
          | IF '(' condicion ')' bloque_ejecutables END_IF ','                          { yyPrintInLine("Se detectó un bloque de control IF");}
          | IF '(' condicion ')' bloque_ejecutables ','                 {yyerror("Falta de END_IF en el bloque de control IF");}
          | IF '(' ')' bloque_ejecutables END_IF ','                    {yyerror("Falta de condición en el bloque de control IF");}
          ;

ciclo_while : WHILE '(' condicion ')' DO bloque_ejecutables ','         { yyPrintInLine("Se detectó un WHILE-DO");}
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
                    |   declarativa                     { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                    ;

sentencias_ejecutables  :   sentencias_ejecutables ejecutable 
                        |   ejecutable
                        |   sentencias_ejecutables declarativa          { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                        |   declarativa                                 { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                        ;
factor : IDENTIFICADOR
       | IDENTIFICADOR OPERADOR_SUMA_SUMA
       | constanteSinSigno
       | constanteConSigno
       | TOF '(' expresion_aritmetica ')'       /* conversión de tipo */
       ;

constanteSinSigno       :       ENTERO_SIN_SIGNO                        
                        |       CADENA_CARACTERES                       
                        ;

constanteConSigno       :       ENTERO_CORTO                            { checkIntegerShort($1);}
                        |       '-' ENTERO_CORTO                        { checkIntegerShortNegative($2);}
                        |       PUNTO_FLOTANTE                          
                        |       '-' PUNTO_FLOTANTE                      
                        |       '-'                                     { yyerror("Falta constante numérica en la expresión"); }
                        ;

acceso_objeto   :   IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica ','                { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR ','     { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')' ','            { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' ')' ','                                 { yyPrintInLine("Se detectó un acceso a un objeto");}
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