%{
    #include <iostream>
    using namespace std;
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

%start programa

%%

programa    :   '{' sentencias '}' /* es el programa que debe arrancar y terminar con '{' '}' */

sentencias  :   sentencia sentencias 
            |   /* podría ser un programa sin nada, hay que preguntar! */
            ;

sentencia   :   declarativa
            |   ejecutable
            ;

declarativa :   tipo lista_de_variables ','
            |   VOID IDENTIFICADOR '(' parametro ')' '{' cuerpo_de_la_funcion '}' ','
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

ejecutable : asignacion
           | invocacion
           | seleccion
           | PRINT CADENA_CARACTERES ','
           | ciclo_while
           ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica ','
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')' ','
           | IDENTIFICADOR '(' ')' ','
           ;

expresion_aritmetica : expresion_aritmetica '+' termino
                    | expresion_aritmetica '-' termino
                    | termino
                    ;

termino : termino '*' factor
        | termino '/' factor
        | factor
        ;

factor : IDENTIFICADOR
       | IDENTIFICADOR OPERADOR_SUMA_SUMA
       | constante
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

constante   :   ENTERO_SIN_SIGNO
            |   ENTERO_CORTO
            |   PUNTO_FLOTANTE
            |   CADENA_CARACTERES
            ;

%%

int main() {
    yyparse();
    return 0;
}

int yyerror(const char* s) {
    cout << "Error sintáctico: " << s << endl;
    return 0;
}