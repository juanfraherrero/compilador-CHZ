%{

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"
#include "include/Tercets.hpp"
#include "include/VectorOfFunction.hpp"

#include <iostream>
#include <fstream>
#include <string>
#include <stack>

using namespace std;

// generamos la tabla de simbolos
TableSymbol* tableSymbol = new TableSymbol();

// generamos la tabla de palabras reservadas
TableReservedWord* tableRWords = new TableReservedWord();

VectorOfFunction * vectorOfFunction = new VectorOfFunction(); // este vector se guarda las listas de tercetos instanciadas y a usar, como funciones en main o métodos de un objeto instanciado
VectorOfFunction * vectorOfFunctionDeclaredInClasses = new VectorOfFunction(); // este vector se usa para cuando declaramos un método o una función dentro de una clase (esto es una declaración y se debe instanciar por cada objeto)
stack<functionStack*>* stackFunction = new stack<functionStack*>();
int cantOfRecursions = 0;
int cantOfRecursionsInMethod = 0;

int cantLabels = 0;
int lineNumber = 1;
bool isErrorInCode = false;
Tercets *tableTercets = new Tercets();
char charTercetoId = '%';
bool isVariableToCheck = false;      // booleano que sirve para indicar si se esta declarando una variable con check
string accesosEfectuados;             // string que sirve para guardar los accesos efectuados en una invocacion múltiple

string typeAux = "";
string actualClass = "";
symbol* lastMethod;
stack<symbol*>*  stackClasses = new stack<symbol*>();
void yyerrorFin(string s){
    isErrorInCode = true;    
    cerr << "\033[31m" << "Error: " << s <<"\033[0m"<< endl;
};
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
%token CHECK

%start programa

%%

programa    :   '{' sentencias '}'              { finPrograma();  }
            |   '{' comas sentencias '}'        { finPrograma(); }     
            |   '{' comas '}'                   { finPrograma(); }      
            |   '{' '}'                         { finPrograma(); yywarning("Se esta compilando un programa sin contenido"); }
            |   '{'                             { finPrograma(); yywarning("Se esta compilando un programa sin contenido y falta la ultima llave"); }
            |   '}'                             { finPrograma(); yywarning("Se esta compilando un programa sin contenido y falta la primer llave"); }
            |   '{' sentencias '}' error        { yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   '{' '}' error                   { yywarning("Se esta compilando un programa sin contenido"); yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   sentencias                      { finPrograma(); yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' sentencias                  { finPrograma(); yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   sentencias '}'                  { finPrograma(); yywarning("Se detecto la falta de la primera llave del programa"); }
            |   comas                           { finPrograma(); yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' comas                       { finPrograma(); yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   comas '}'                       { finPrograma(); yywarning("Se detecto la falta de la primera llave del programa"); }
            |   '{' comas sentencias            { finPrograma(); yywarning("Se detecto la falta de la ultima llave del programa"); }
            |    comas sentencias '}'           { finPrograma(); yywarning("Se detecto la falta de la primera llave del programa"); }
            |    comas sentencias               { finPrograma(); yywarning("Se detecto la falta de llaves en el programa"); }
            ;
            
sentencias  :   sentencias sentencia
            |   sentencia 
            ;

sentencia   :   declarativa comas                                    
            |   ejecutable comas    
            |   declarativa                                      { yywarning("Se detecto una falta de coma"); }                                 
            |   ejecutable                                       { yywarning("Se detecto una falta de coma"); }
            |   error ','                                        { yyerror("Se detecto una sentencia invalida"); }
            ;

comas : ',' comas
      | ',' 
      ;

declarativa :   tipo lista_de_variables                                             { finishVariableDeclaration(); }
            |   check tipo lista_de_variables                                       { finishVariableDeclaration(); }
            |   declaracion_clase                                                    
            |   declaracion_objeto                                                  { }
            |   declaracion_funcion                                                 { }
            ;
check   :   CHECK                                                                   { setVariableToCheck(); }
        ;
declaracion_funcion     :       funcion_name '(' parametro_funcion ')' '{' cuerpo_de_la_funcion '}'             { finishFunction();  }
                        |       VOID '(' parametro_funcion ')' '{' cuerpo_de_la_funcion '}'                     { yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       funcion_name '(' parametro_funcion ')' '{' '}'                                  { finishFunction(); yywarning("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        
                        |       funcion_name '(' parametro_funcion ')' '{' comas cuerpo_de_la_funcion '}'             { finishFunction();}
                        |       VOID '(' parametro_funcion ')' '{' comas cuerpo_de_la_funcion '}'                     { yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       funcion_name '(' parametro_funcion ')' '{' comas '}'                                  { finishFunction(); yywarning("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        ;

funcion_name    :       VOID IDENTIFICADOR              { initFunction($2->ptr, tableSymbol->getScope()); }
                ;

declaracion_clase   :   nombre_clase '{' lista_atributos_y_metodos '}'   { finishClass(); }
                    |   nombre_clase '{' '}'                             { finishClass(); yywarning("Se detecto una declaracion de clases vacia");}
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { forwardClass($2->ptr, tableSymbol->getScope());}
                    |   CLASS '{' lista_atributos_y_metodos '}'                 { yyerror("Falta nombre de la clase"); }
                    |   CLASS  '{' '}'                                          { yyerror("Falta nombre de la clase"); }
                    ;
clase_heredada  :       IDENTIFICADOR                                       { detectInheritance($1->ptr, tableSymbol->getScope(), actualClass); }
                ;
nombre_clase    :       CLASS IDENTIFICADOR                     { initClass($2->ptr, tableSymbol->getScope(), $$->ptr); }
                ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_atributos ','           { }
                                |       lista_atributos_y_metodos metodo ','                                 
                                |       lista_atributos_y_metodos clase_heredada ','                                 
                                |       lista_atributos_y_metodos IDENTIFICADOR IDENTIFICADOR ','       { addObjectToClass($3->ptr, tableSymbol->getScope(), $2->ptr, actualClass); }
                                |       tipo lista_de_atributos ','                                     { }
                                |       metodo ','
                                |       clase_heredada ','
                                |       IDENTIFICADOR IDENTIFICADOR ','                                 { addObjectToClass($2->ptr, tableSymbol->getScope(), $1->ptr, actualClass);}
                                ;
lista_de_atributos  :   lista_de_atributos ';' IDENTIFICADOR    { addAtribute($3->ptr, tableSymbol->getScope(), typeAux, actualClass); }
                    |   IDENTIFICADOR                           { addAtribute($1->ptr, tableSymbol->getScope(), typeAux, actualClass); }
                    ;
metodo  :   metodo_name '(' parametro_metodo ')' '{' cuerpo_de_la_funcion '}'                 { finishMethod(); }
        |   metodo_name '(' parametro_metodo ')' '{' '}'                                      { finishMethod(); yyerror("Se detecto la falta de RETURN en el cuerpo del metodo");}
        |   metodo_name '(' parametro_metodo ')' '{' comas cuerpo_de_la_funcion '}'           { finishMethod(); }
        ;

metodo_name     :       VOID IDENTIFICADOR              { initMethod($2->ptr, tableSymbol->getScope(), actualClass); }
                |       VOID                            { yyerror("Falta de nombre de metodo"); }
                ;

declaracion_objeto  :   typeClass lista_de_objetos   {} 
                    ;
typeClass : IDENTIFICADOR                       {initObjectDeclaration($1->ptr, tableSymbol->getScope(), $$->ptr); }
          ;

lista_de_objetos    :   lista_de_objetos ';' IDENTIFICADOR      { addObject($3->ptr, tableSymbol->getScope(), actualClass); }
                    |   IDENTIFICADOR                           { addObject($1->ptr, tableSymbol->getScope(), actualClass); }
                    ;

tipo    :       SHORT   { typeAux = "short"; $$->type ="short";}
        |       UINT    { typeAux = "unsigned int"; $$->type = "unsigned int";}
        |       FLOAT   { typeAux = "float"; $$->type = "float";}
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR    { newVariable($3->ptr,tableSymbol->getScope(),typeAux); }
                    |   IDENTIFICADOR                           { newVariable($1->ptr,tableSymbol->getScope(),typeAux); }
                    ;
parametro_metodo   :   tipo IDENTIFICADOR               { addParamMetodo($2->ptr, tableSymbol->getScope(), $1->type, actualClass); $$->type = $1->type;}
            |   tipo                                    { yyerror("Falta de nombre de parametro"); }            
            |   IDENTIFICADOR                           { yyerror("Falta de tipo de parametro"); } 
            |   /* vacio */
            |   parametro_metodo ';' tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
            |   parametro_metodo comas tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
            ;

parametro_funcion   :   tipo IDENTIFICADOR              { addParamFunction ($2->ptr, tableSymbol->getScope(), $1->type, $$->ptr, $$->type); }
                |   tipo                            { yyerror("Falta de nombre de parametro"); }            
                |   IDENTIFICADOR                   { yyerror("Falta de tipo de parametro"); } 
                |   /* vacio */
                |   parametro_funcion ';' tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
                |   parametro_funcion comas tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
                ;

cuerpo_de_la_funcion    :   cuerpo_de_la_funcion_sin_return                             {yyerror("Se detecto la falta de RETURN en el cuerpo de sentencias");}
                        |   cuerpo_de_la_funcion_con_return
                        ;
cuerpo_de_la_funcion_con_return    :   cuerpo_de_la_funcion_sin_return return ','
                                   |   cuerpo_de_la_funcion_sin_return return                                           { yywarning("Se detecto una falta de coma"); }
                                   |   cuerpo_de_la_funcion_sin_return return ',' cuerpo_de_la_funcion_sin_return       { yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return return cuerpo_de_la_funcion_sin_return           { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return return ',' cuerpo_de_la_funcion_con_return       { yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return return cuerpo_de_la_funcion_con_return           { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   return ','
                                   |   return                                           {yywarning("Se detecto una falta de coma"); }        
                                   |   return ',' cuerpo_de_la_funcion_sin_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   |   return cuerpo_de_la_funcion_sin_return       { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   return ',' cuerpo_de_la_funcion_con_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   |   return cuerpo_de_la_funcion_con_return       { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   ;
cuerpo_de_la_funcion_sin_return    :   cuerpo_de_la_funcion_sin_return sentencia 
                                   |   sentencia
                                   ;
ejecutable  :    asignacion
            |    invocacion                                 
            |    seleccion
            |    PRINT CADENA_CARACTERES                    { int number = addTercet("print", tableSymbol->getSymbol($2->ptr)->value, ""); $$->ptr = charTercetoId + to_string(number); }
            |    PRINT IDENTIFICADOR                        { printIdentificador($2->ptr, tableSymbol->getScope()); }
            |    PRINT constanteConSigno                    { int number = addTercet("print", tableSymbol->getSymbol($2->ptr)->value, ""); $$->ptr = charTercetoId + to_string(number); }
            |    PRINT constanteSinSigno                    { int number = addTercet("print", tableSymbol->getSymbol($2->ptr)->value, ""); $$->ptr = charTercetoId + to_string(number); }
            |    ciclo_while
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica                     { newAsignacion($1->ptr, tableSymbol->getScope(), $3->ptr,$3->type);}
           | accesoObjetos '.' IDENTIFICADOR '=' expresion_aritmetica   { newAsignacionObjectAttribute($1->ptr, $3->ptr, tableSymbol->getScope(), $5->ptr, $5->type, $5->ptr,$5->type); }
           | IDENTIFICADOR OPERADOR_SUMA_SUMA                           { newFactorMasMas($1->ptr, tableSymbol->getScope(), $$->ptr, $$->type); }
           | accesoObjetos '.' IDENTIFICADOR OPERADOR_SUMA_SUMA         { newUseObjectAttributeFactorMasMas($1->ptr, $3->ptr,  tableSymbol->getScope(), $$->ptr, $$->type); } 
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'                     { newInvocacionWithParam($1->ptr, tableSymbol->getScope(), $3->ptr, $3->type, $$->ptr); }
           | IDENTIFICADOR '(' ')'                                          { newInvocacion($1->ptr, tableSymbol->getScope(), $$->ptr); }
           | accesoObjetos '.' IDENTIFICADOR '(' expresion_aritmetica ')'   { newInvocacionMethodWithParam($1->ptr, $3->ptr, tableSymbol->getScope(), $5->ptr, $5->type, $$->ptr); }   
           | accesoObjetos '.' IDENTIFICADOR '(' ')'                        { newInvocacionMethod($1->ptr, $3->ptr, tableSymbol->getScope(), $$->ptr); }   
           ;

accesoObjetos : accesoObjetos '.' IDENTIFICADOR                             { accessObjects($1->ptr, $3->ptr, $$->ptr); }
              | IDENTIFICADOR                                               { accessObject($1->ptr, $$->ptr); }
              ;
expresion_aritmetica : expresion_aritmetica '+' termino         { newOperacionAritmetica("+", $1->ptr, $3->ptr, $1->type, $3->type, $$->ptr, $$->type); }
                    | expresion_aritmetica '-' termino          { newOperacionAritmetica("-", $1->ptr, $3->ptr, $1->type, $3->type, $$->ptr, $$->type); }
                    | expresion_aritmetica '-' '*' termino      { newOperacionAritmetica("-", $1->ptr, $4->ptr, $1->type, $4->type, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '-'"); }
                    | expresion_aritmetica '+' '*' termino      { newOperacionAritmetica("+", $1->ptr, $4->ptr, $1->type, $4->type, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '+'"); }
                    | expresion_aritmetica '-' '/' termino      { newOperacionAritmetica("-", $1->ptr, $4->ptr, $1->type, $4->type, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '-'"); }
                    | expresion_aritmetica '+' '/' termino      { newOperacionAritmetica("+", $1->ptr, $4->ptr, $1->type, $4->type, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '+'"); }
                    | termino                                   { $$->type = $1->type; $$->ptr = $1->ptr; }
                    ;

termino : termino '*' factor                                    { newOperacionAritmetica("*", $1->ptr, $3->ptr, $1->type, $3->type, $$->ptr, $$->type); }
        | termino '/' factor                                    { newOperacionAritmetica("/", $1->ptr, $3->ptr, $1->type, $3->type, $$->ptr, $$->type); }
        | factor                                                { $$->ptr = $1->ptr; $$->type = $1->type;}
        ;

seleccion : IF bloque_condicion cuerpo_if                       { finIf(); }                     
          ;

bloque_condicion : '(' condicion ')'                            { condition($$->ptr); }
                 | '(' condicion                                { condition($$->ptr); yywarning("Falta de ultimo parentesis en condicion"); }
                 |  condicion ')'                               { condition($$->ptr); yywarning("Falta de primer parentesis en condicion"); }
                 |  condicion                                   { condition($$->ptr); yywarning("Falta de parantesis en condicion"); }
                 |  '(' ')'                                     { condition($$->ptr); yyerror("Falta de condicion en el bloque de control IF"); }
                 ;

cuerpo_if : cuerpo_then else_if cuerpo_else END_IF
          | cuerpo_then else_if cuerpo_else                     { yyerror(" Falta de END_IF en bloque de control IF-ELSE"); }
          | cuerpo_then cuerpo_else END_IF                      { yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
          | cuerpo_then END_IF    
          | cuerpo_then else_if END_IF                         { yyerror(" Falta contenido dentro del ELSE en bloque de control IF-ELSE");}                                        
          ; 

cuerpo_then : bloque_ejecutables                                
            ;
cuerpo_else : bloque_ejecutables
            ;
else_if :       ELSE                                            { addElse($$->ptr); }
        ;
ciclo_while : inicio_while bloque_condicion DO cuerpo_while               { finWhile($$->ptr); }                     
            | inicio_while bloque_condicion cuerpo_while                  { finWhile($$->ptr); yywarning("Falta de DO en WHILE-DO"); }                     
            ;

inicio_while    : WHILE                                                         { initWhile(); }
                ;

cuerpo_while : bloque_ejecutables                                       
            ;   

condicion : expresion_aritmetica '>' expresion_aritmetica                       { newCondicion(">",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr); }
          | expresion_aritmetica '<' expresion_aritmetica                       { newCondicion("<",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr); }
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica    { newCondicion("==",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr);}
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica       { newCondicion("!!",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr);}
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica    { newCondicion(">=",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr);}
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica    { newCondicion("<=",$1->ptr, $3->ptr,$1->type, $3->type,$$->ptr);}
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   '{' sentencias_ejecutables return ',' '}'        
                    |   '{' sentencias_ejecutables return ',' sentencias_ejecutables '}'        { yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' sentencias_ejecutables return sentencias_ejecutables '}'            { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' sentencias_ejecutables return '}'                                   { yywarning("Se detecto una falta de coma"); }
                    |   ejecutable ',' 
                    |   declarativa  ','                                                        { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   '{' return ',' '}'
                    |   '{' return '}'                                                          { yywarning("Se detecto una falta de coma"); }
                    |    return ','
                    
                    |   '{' sentencias_ejecutables return ',' comas '}'        
                    |   '{' sentencias_ejecutables return ',' comas sentencias_ejecutables '}'        { yywarning("Se detecto codigo posterior a un return"); }


                    |   '{' comas sentencias_ejecutables '}'      
                    |   '{' comas sentencias_ejecutables return ',' '}'              
                    |   '{' comas sentencias_ejecutables return ',' sentencias_ejecutables '}'  { yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' comas sentencias_ejecutables return sentencias_ejecutables '}'      { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' comas sentencias_ejecutables return '}'                             { yywarning("Se detecto una falta de coma"); }
                    |   comas ejecutable ',' 
                    |   comas declarativa  ','                                                  { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   '{' comas return ',' '}'
                    |   '{' comas return '}'                                                    { yywarning("Se detecto una falta de coma"); }
                    |    comas return ','                                               
                    |   error ','                                                               { yyerror("Se detecto un bloque invalido"); }
                    ;

return  : RETURN                        { addTercetReturn($$->ptr); }
        ;

sentencias_ejecutables  :   sentencias_ejecutables ejecutable comas
                        |   sentencias_ejecutables ejecutable                   { yywarning("Se detecto una falta de coma"); }
                        |   ejecutable comas
                        |   ejecutable                                          { yywarning("Se detecto una falta de coma"); }
                        |   sentencias_ejecutables declarativa comas              { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                        |   sentencias_ejecutables declarativa                  { yyerror("Se detecto una sentencia declarativa en bloque de control y la falta de coma"); }
                        |   declarativa ','                                     { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                        |   declarativa                                         { yywarning("Se detecto una falta de coma"); }
                        |   sentencias_ejecutables error ','                    { yyerror("Se detecto una sentencia invalida dentro del bloque de sentencias ejecutables"); }
                        |   error ','                                           { yyerror("Se detecto una sentencia invalida en el bloque de sentencias ejecutables"); }
                        ;

factor : IDENTIFICADOR                                                  { checkVarInScope($1->ptr, tableSymbol->getScope(), "var", $$->ptr, $$->type); }
       | IDENTIFICADOR OPERADOR_SUMA_SUMA                               { newFactorMasMas($1->ptr, tableSymbol->getScope(), $$->ptr, $$->type); }
       | constanteSinSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | constanteConSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | TOF '(' expresion_aritmetica ')'                               { newTof($3->ptr, $3->type,$$->ptr,$$->type);} 
       | accesoObjetos '.' IDENTIFICADOR                                { newUseObjectAttribute($1->ptr, $3->ptr,  tableSymbol->getScope(), $$->ptr, $$->type); } 
       | accesoObjetos '.' IDENTIFICADOR OPERADOR_SUMA_SUMA             { newUseObjectAttributeFactorMasMas($1->ptr, $3->ptr,  tableSymbol->getScope(), $$->ptr, $$->type); } 
       | CADENA_CARACTERES                                              { yyerror("No se puede operar con cadena de caracteres");{ $$->ptr = $1->ptr; $$->type = $1->type;} }          
       ;

constanteSinSigno       :       ENTERO_SIN_SIGNO                        { $$->ptr = $1->ptr; $$->type = $1->type;}               
                        ;

constanteConSigno       :       ENTERO_CORTO                            { checkIntegerShort($1->ptr); $$->ptr = $1->ptr; $$->type = $1->type;}
                        |       '-' ENTERO_CORTO                        { string newLexema = checkIntegerShortNegative($2->ptr); $$->ptr = newLexema; $$->type = $2->type;}
                        |       PUNTO_FLOTANTE                          { $$->ptr = $1->ptr; $$->type = $1->type;}
                        |       '-' PUNTO_FLOTANTE                      { string newLexema = setFloatNegative($2->ptr); $$->ptr = newLexema; $$->type = $2->type;}
                        |       '-'                                     { yyerror("Falta constante numerica en la expresion"); }
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
string checkIntegerShortNegative(string lexeme){
        tableSymbol->deleteSymbol(lexeme); // reduce el contador, si llega a 0 lo elimina
        
        size_t pos = lexeme.find("_s");
        string value = "-"+lexeme.substr(0, pos);
        lexeme = "minus"+lexeme;
        
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
        if(type1 != type2 && type1 != "error" && type2 != "error" && type1 != "pospone" && type2 != "pospone"){
                yyerror("Incompatibilidad de tipos al comparar entre "+ type1 + " y " + type2);
        }
}
bool checkTypesOperation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error" && type1 != "pospone" && type2 != "pospone"){
                yyerror("Incompatibilidad de tipos al operar entre "+ type1 + " y " + type2);
                return false;
        }
        return true;
}
void checkTypesAsignation(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error" && type1 != "pospone" && type2 != "pospone"){
                yyerror("Incompatibilidad de tipos al asignar "+ type2 + " a " + type1);
        }
}
void checkTypesAsignationFin(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerrorFin("Incompatibilidad de tipos al asignar "+ type2 + " a " + type1);
        }
}
void checkTypesParams(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerror("Incompatibilidad de tipos "+ type2 + " y " + type1 + " entre los parametros");
        }
}
void checkTypesParamsFin(string type1, string type2){
        if(type1 != type2 && type1 != "error" && type2 != "error"){
                yyerrorFin("Incompatibilidad de tipos "+ type2 + " y " + type1 + " entre los parametros");
        }
}
/**
 * Carga el símbolo en la tabla
 * Dado el acceso a un elemento de la tabla de simbolos lo elimina
 * Actualiza el símbolocon los datos pasados, 
 * si no se quiere modificar los datos dejar ""
 * 
 * @param key nombre del acceso
 * @param type tipo del acceso
 * @param scope scope actual
 * @param uso uso del acceso
 * @param ts tabla de símbolo a la que agregarle el acceso
 */
symbol* setNewScope(string key, string type, string scope, string uso, TableSymbol* ts){
        
        // borramos el símbolo de la tabla de símbolos general
        symbol* identificador = tableSymbol->getSymbol(key);    // obtenemos el simbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el simbolo
        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        // seteas los nuevos valores
        if(type != ""){
                newIdentificador->type = type;                          // actualizamos el tipo
        }
        if(scope != ""){
                newIdentificador->lexema += scope;                      // actualizamos el scope
        }
        if(uso != ""){
                newIdentificador->uso = uso;                            // actualizamos el uso
        }

        // insrtamos en la nueva tabla de símbolos
        ts->insert(newIdentificador);                          // insertamos el nuevo simbolo en la tabla
        
        // retornamos el puntero al simbolo
        return newIdentificador;
}
vector<string> getAccesoFromString(string _accesos){
    vector<string> elementos;

    size_t posInicio = 0;
    size_t posDelimitador = _accesos.find(':');

    while (posDelimitador != string::npos) {
        string elemento = _accesos.substr(posInicio, posDelimitador - posInicio);
        elementos.push_back(elemento);

        posInicio = posDelimitador + 1;
        posDelimitador = _accesos.find(':', posInicio);
    }

    // El último elemento después del último delimitador
    string ultimoElemento = _accesos.substr(posInicio);
    elementos.push_back(ultimoElemento);

    return elementos;
};
// Crea un terceto y lo agrega a la tabla de tercetos.
// Los paramtros son argumento, operador1, y operador2
int addTercet(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        
        // le marcamos al terceto si tiene un elemento pospuesto
        symbol* smArg1 = tableSymbol->getSymbol(operando1);
        symbol* smArg2 = tableSymbol->getSymbol(operando2);
        if(smArg1!= nullptr && smArg1->posponeForForwarding == true){
                t->arg1Pospone = true;
                t->type1 = smArg1->type;
        }
        if(smArg2!= nullptr && smArg2->posponeForForwarding == true){
                t->arg2Pospone = true;
                t->type2 = smArg2->type;
        }

        int number;
        if(cantOfRecursions <= 0){
                number = tableTercets->add(t);
        }else{
                number = stackFunction->top()->ter->add(t);
        }
                
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos.
// Los paramtros son argumento, operador1, y operador2
int addTercetWithType(string argumento, string operando1, string operando2, string _type1, string _type2, string _type){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        t->typeTercet = _type;
        t->type1 = _type1;
        t->type2 = _type2;
        // le marcamos al terceto si tiene un elemento pospuesto
        symbol* smArg1 = tableSymbol->getSymbol(operando1);
        symbol* smArg2 = tableSymbol->getSymbol(operando2);
        if(smArg1!= nullptr && smArg1->posponeForForwarding == true){
                t->arg1Pospone = true;
                t->type1 = smArg1->type;
        }
        if(smArg2!= nullptr && smArg2->posponeForForwarding == true){
                t->arg2Pospone = true;
                t->type2 = smArg2->type;
        }

        int number;
        if(cantOfRecursions <= 0){
                number = tableTercets->add(t);
        }else{
                number = stackFunction->top()->ter->add(t);
        }
                
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos. pero setea si algun parametro esta pospuesto
// Los paramtros son argumento, operador1, y operador2
int addTercetPospone(string argumento, string operando1, string operando2, bool _arg1pospone, bool _arg2pospone, string _op1Type, string _op2Type){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        
        t->arg1Pospone = _arg1pospone;
        t->type1 = _op1Type;
        t->arg2Pospone = _arg2pospone;
        t->type2 = _op2Type;
        int number;
        if(cantOfRecursions <= 0){
                number = tableTercets->add(t);
        }else{
                number = stackFunction->top()->ter->add(t);
        }
                
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos. pero setea si algun parametro esta pospuesto
// Los paramtros son argumento, operador1, y operador2
int addTercetPospone(string argumento, string operando1, string operando2, bool _arg1pospone, bool _arg2pospone, string _op1Type, string _op2Type, string _typeTercet){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        
        t->arg1Pospone = _arg1pospone;
        t->type1 = _op1Type;
        t->arg2Pospone = _arg2pospone;
        t->type2 = _op2Type;
        t->typeTercet = _typeTercet;
        int number;
        if(cantOfRecursions <= 0){
                number = tableTercets->add(t);
        }else{
                number = stackFunction->top()->ter->add(t);
        }
                
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos y lo apila.
// Los paramtros son argumento, operador1, y operador2
int addTercetAndStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 

        // le marcamos al terceto si tiene un elemento pospuesto
        if(operando1[0] == charTercetoId){
            string type;
            if(cantOfRecursions <= 0){
                type = tableTercets->get(stoi(operando1.substr(1, operando1.size())))->typeTercet;
            }else{
                type = stackFunction->top()->ter->get(stoi(operando1.substr(1, operando1.size())))->typeTercet;
            }
            if(type == "pospone"){
                t->arg1Pospone = true;
                t->type1 = "pospone";
            }
        }

        int number;
        if(cantOfRecursions <= 0){
                number = tableTercets->add(t);
        }else{
                number = stackFunction->top()->ter->add(t);
        }
        tableTercets->push(t);
        return number;
}
// Crea un terceto y lo apila.
// Los paramtros son argumento, operador1, y operador2
void addTercetOnlyStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        tableTercets->push(t);
        return ;
}

// desapila un terceto de la stack de tercetos y la retorna
Tercet* popTercet(){
        return tableTercets->pop();
}

void initClass(string key, string scope, string & reglaptr){
        // verificamos a que distancia se encuentra la primer aparición de la variable en un ámbito alcanzable
        int diff = tableSymbol->getDiffOffScope2(key, "clase", scope); 
        
        // si está en el mismo ámbito
        if(diff == 0){
                // en el mismo ámbito existe una clase, verificar si es forward declaration
                symbol* symbolFinded = tableSymbol->getSymbol(key+scope); // obtenemos el símbolo con mismo scope
                if(symbolFinded->forwarded == false){
                        yyerror("Redeclaracion de clase " + key + " en el mismo ambito");
                        
                        //aca borramos el simbolo de la tabla de simbolos general
                        tableSymbol->deleteSymbol(key); 
                        
                        // agregamos la clase al stack de clases para que aunque este redeclarada no tire un error si intentamos acceder a una clase del stack que no existe
                        stackClasses->push(symbolFinded);
                }else{
                        //aca borramos el simbolo de la tabla de simbolos general
                        tableSymbol->deleteSymbol(key); 
                        // la marcamos como que ya se declaró
                        symbolFinded->forwarded = false;
                        symbolFinded->attributesAndMethodsVector = new TableSymbol(scope+":"+key); // inicializamos el vector de simbolos
                        symbolFinded->classOfSymbol = key;
                        // agregamos la clase al stack de clases
                        stackClasses->push(symbolFinded);

                }
        }else{
                symbol* newIdentificador = setNewScope(key, "", scope, "clase", tableSymbol); 
                newIdentificador->attributesAndMethodsVector = new TableSymbol(scope+":"+key); // inicializamos el vector de simbolos
                newIdentificador->classOfSymbol = key;
                stackClasses->push(newIdentificador);
        } 
        actualClass = key; 
        reglaptr = key; 
        tableSymbol->addScope(key);
};
/**
 * Esta función se llama cuando se quiere crear un método o función de un objeto a instanciar
 * Para esto se require de buscar el bloque de tercetos en el vecto de bloques de tercetos de declaración
 * copiarlo y agregarle a cada argumento que sea propio del objeto ":"+objeto+scope 
 * al nuevo bloque también le agregamos eso al nombre e insertamos la copia en el vecotr de bloques de tercetos de ejecución
 * 
 * 
 * @param objectName El nombre del objeto.
 * @param scope El scope actual.
 * @param simboloDeFuncion El símbolo de la función o método.
 * @param tableSymbolOfTheClass La tabla de símbolos de la clase.
 */
void createFunctionTerecets(string objectName, string scope, symbol* simboloDeFuncion, TableSymbol* tableSymbolOfTheClass){
     /*
        la función debe buscar en el vector de declaración de bloques de tercetos de funciones la declaraciónde este método o función, 
            copiarlo al vector de ejecución
            recorrer cada terceto y por cada operador de este terceto verificar si alguno es igual a algún atributo o método de la clase ode sus herencias, 
            en ese caso se le agrega el objeto y el scope actual
    */
    functionStack* copyOfTheStack = vectorOfFunctionDeclaredInClasses->getCopyOfFunction(simboloDeFuncion->lexema);

    // recorremos el stack de tercetos de la función o método
    for (const auto& tercet : copyOfTheStack->ter->getTercets()){
        // si la tabla contiene exactamente ese elemento del terceto entonces le agregamos el objeto y el scope actual
        if(tableSymbolOfTheClass->isTheSpecificLexemaInTable(tercet->getArg1())){
            tercet->setArg1(tercet->getArg1()+":"+objectName+scope);
        }
        // si la tabla contiene exactamente ese elemento del terceto entonces le agregamos el objeto y el scope actual
        if(tableSymbolOfTheClass->isTheSpecificLexemaInTable(tercet->getArg2())){
            tercet->setArg2(tercet->getArg1()+":"+objectName+scope);
        }
    }

    copyOfTheStack->name += ":"+objectName+scope; // le agregamos el nombre del objeto + el scope actual
    // agregamos el nuevo stack de funciones a la tabla de funciones en ejecución
    vectorOfFunction->add(copyOfTheStack);

};
// ob1 ob2:main:clase1 :main clase1
bool instanciateObject(string objectName, string objectWithScopeStatic, string scopeDynamic, string classNameOfNewObject){

    // obtenemos el símbolo de la clase del objeto
    symbol* classOfNewObject = tableSymbol->getFirstSymbolMatching2(classNameOfNewObject, "clase", ":main"); // obtenemos el símbolo de la clase del nuevo objeto
    
    // verificamos si la clase es una forward declaration 
    // de ser forward el objeto también se convierte en forwarded para luego isntanciarlo cuando la clase se declare
    // ya que si es asi no podemos agregar sus atributos y métodos
    if(classOfNewObject->forwarded){
        return true;
    }
    
    // recorremos la tabla de símbolos de la clase del objeto y agregamos cada uno de los elementos
    for (const auto& par : classOfNewObject->attributesAndMethodsVector->getSymbolTable()){
        symbol* simbolo = par.second;
        // creamos el nuevo símbolo
        symbol* newSm = new symbol(*simbolo);                
        
        // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
        //      la tabla de tercetos principal o de ejecución
        if(newSm->uso=="metodo" || newSm->uso=="funcion"){
            createFunctionTerecets(objectName, scopeDynamic, newSm, classOfNewObject->attributesAndMethodsVector);
        }
                
        if(newSm->uso=="objeto"){
            // como el elemento de la clase es un objeto, debemos copiar cada atributo de la clase del objeto e intanciarlo
            // string objectName = newSm->lexema.substr(0, newSm->lexema.find(":"));
            // ob1 ob2:main:clase1 :main clase1
            newSm->posponeForForwarding = instanciateObject(objectName, newSm->lexema, scopeDynamic, newSm->classOfSymbol);
        }

        newSm->lexema = newSm->lexema+":"+objectName+scopeDynamic; // le agregamos el nombre del objeto + el scope actual
        
        // agregamos el nuevo símbolo a la tabla de simbolos        
        tableSymbol->insert(newSm);
    }

    // recorremos las herencias de derecha a izquierda y agregamos cada uno de los elementos a la tabla general

    // recorres el arreglo de herencia de esta clase verificando que exista alguna posicion con nullptr, si es asi verificas si esa clase tiene unmetodo con el mismo nombre y si es asi devuelves 1
    for (int i=1; i >= 0; i--){
        TableSymbol* tableSymbolMatchingClass = classOfNewObject->inheritance[i];
        // si hereda de alguna clase recorremos sus simbolos y los agregamos
        if(tableSymbolMatchingClass != nullptr){
            
            // recorremos la tabla de símbolos de la clase que hereda y agregamos cada uno de los elementos
            for (const auto& par : tableSymbolMatchingClass->getSymbolTable()){
                symbol* simbolo = par.second;
                // creamos el nuevo símbolo
                symbol* newSm = new symbol(*simbolo);                
                
                // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
                //      la tabla de tercetos principal o de ejecución
                if(newSm->uso=="metodo" || newSm->uso=="funcion"){
                    createFunctionTerecets(objectName, scopeDynamic, newSm, tableSymbolMatchingClass);
                }

                if(newSm->uso=="objeto"){
                    // como el elemento de la clase es un objeto, debemos copiar cada atributo de la clase del objeto e intanciarlo
                    // string objectName = newSm->lexema.substr(0, newSm->lexema.find(":"));
                    // ob1 ob2:main:clase1 :main clase1
                    newSm->posponeForForwarding = instanciateObject(objectName, newSm->lexema, scopeDynamic, newSm->classOfSymbol);
                }

                newSm->lexema = newSm->lexema+":"+objectName+scopeDynamic; // le agregamos el nombre del objeto + el scope actual
                
                // agregamos el nuevo símbolo a la tabla de simbolos        
                tableSymbol->insert(newSm);
            }
        }
    }
    
};
/**
 * Cuando se detecta una clase que fue forwardeada y un objeto fue declarado de esa clase se llma a esta función
 * instranciamos el obejo cargando los elementos de la tabla de simbolos de la clase y de sus herencias a la tabla general
 * 
 * @param symbolObject Puntero al símbolo del objeto.
 * @param classSymbol Puntero al símbolo de la clase del objeto.
 */
void addObjectForwarded(symbol* symbolObject, symbol* classSymbol){
        // Encontrar la posición del segundo "main"
        size_t lastPosMain = symbolObject->lexema.rfind("main");
        
        // Encontrar la posición del último ":" antes del segundo "main"
        size_t posUltimo = symbolObject->lexema.rfind(":", lastPosMain - 2);
        
        string correctLexeme;
        if (posUltimo != string::npos){
            correctLexeme = symbolObject->lexema.substr(posUltimo + 1);
        }else{
            correctLexeme = symbolObject->lexema;
        };
        // Extraer la subcadena deseada
        
        string key = correctLexeme.substr(0, correctLexeme.find(":"));
        string scope = correctLexeme.substr( correctLexeme.find(":"), correctLexeme.size());
        string classType = symbolObject->classOfSymbol;
              
        // recorremos la tabla de símbolos de la clase del objeto y agregamos cada uno de los elementos
        for (const auto& par : classSymbol->attributesAndMethodsVector->getSymbolTable()){
                symbol* simbolo = par.second;
                // creamos el nuevo símbolo
                symbol* newSm = new symbol(*simbolo);                
                
                // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
                //      la tabla de tercetos principal o de ejecución
                if(newSm->uso=="metodo" || newSm->uso=="funcion"){
                    createFunctionTerecets(key, scope, newSm, classSymbol->attributesAndMethodsVector);
                }

                if(newSm->uso=="objeto"){
                    // como el elemento de la clase es un objeto, debemos copiar cada atributo de la clase del objeto e intanciarlo
                    // string objectName = newSm->lexema.substr(0, newSm->lexema.find(":"));
                    // ob1 ob2:main:clase1 :main clase1

                    newSm->posponeForForwarding = instanciateObject(key, newSm->lexema, scope, newSm->classOfSymbol);
                }

                newSm->lexema = newSm->lexema+":"+key+scope; // le agregamos el nombre del objeto + el scope actual
                
                // agregamos el nuevo símbolo a la tabla de simbolos        
                tableSymbol->insert(newSm);
        }

        // recorres el arreglo de herencia de esta clase verificando que exista alguna posicion con nullptr, si es asi verificas si esa clase tiene unmetodo con el mismo nombre y si es asi devuelves 1
        for (int i=1; i >= 0; i--){
            TableSymbol* tableSymbolMatchingClass = classSymbol->inheritance[i];
            // si hereda de alguna clase recorremos sus simbolos y los agregamos
            if(tableSymbolMatchingClass != nullptr){
                
                // recorremos la tabla de símbolos de la clase que hereda y agregamos cada uno de los elementos
                for (const auto& par : tableSymbolMatchingClass->getSymbolTable()){
                        symbol* simbolo = par.second;
                        // creamos el nuevo símbolo
                        symbol* newSm = new symbol(*simbolo);                
                        
                        // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
                        //      la tabla de tercetos principal o de ejecución
                        if(newSm->uso=="metodo" || newSm->uso=="funcion"){
                            createFunctionTerecets(key, scope, newSm, tableSymbolMatchingClass);
                        }

                        newSm->lexema = newSm->lexema+":"+key+scope; // le agregamos el nombre del objeto + el scope actual
                        
                        // agregamos el nuevo símbolo a la tabla de simbolos        
                        tableSymbol->insert(newSm);
                }
            }
        }
};
/**
 * Cuando se detecta una finalización de declaración de clase se llama a esta función
 * Recorre la tabla de símbolos en busca de símbolos de uso objeto y de la clase actual y que hayan sido declarados luego del forwarded y previo a la declaración de la clase. 
 * Por cada uno de esos objetos, los instancia y les agrega los atributos y métodos de la clase y de sus herencias.
 * 
 * @return void
 */
void finishClass(){
        tableSymbol->deleteScope();
        
        symbol* symbolClass = stackClasses->top();

        vector<symbol*> symbolsMatched = tableSymbol->getSymbolsByUseAndNameClassAndForwarded("objeto", symbolClass->classOfSymbol);

        for (symbol* sm : symbolsMatched){
                // recorremos los simbolos de los objetos e instanciamos
                sm->forwarded = false;
                sm->posponeForForwarding = false;

                addObjectForwarded(sm, symbolClass);
        }
        stackClasses->pop();
};
void forwardClass(string key, string scope){
        // las clases van en la tabla general 
        int diff = tableSymbol->getDiffOffScope(key+scope, "clase", scope); 
        if(diff == 0){
                yyerror("Redeclaracion de clase en el mismo ambito");
        }else{
                symbol* newIdentificador = setNewScope(key, "", scope, "clase", tableSymbol); 
        } 
        tableSymbol->getSymbol(key+scope)->forwarded = true; 
}
/**
 * Cuando detectamos un atributo de clase se ejecuta esta función
 * Obtiene el símbolo viejo lo elimina 
 * y lo carga a la tabla de la clase
 *
 * @param key nombre del acceso
 * @param scope scope actual
 * @param type tipo del acceso
 * @param classOfAttribute nombre de la clase a la que pertenece
*/
void addAtribute(string key, string scope, string type, string classOfAttribute){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        tableSymbol->deleteSymbol(key);         // eliminamos el simbolo dela tabla general

        // operamos sobre la tabla de símbolos de la clase
        TableSymbol * tsClass = stackClasses->top()->attributesAndMethodsVector;

        // verificamos a que distancia se encuentra la primer aparición del atributo en un ámbito alcanzable
        int diff = tsClass->getDiffOffScope2(key, "atributo", scope); 
                
        if(diff == 0){
                yyerror("Redeclaracion de atributo en la misma clase");
        }else{
                // creamos el nuevo símbolo para el atributo
                symbol* newAttribute = new symbol(key+scope, "", type, "atributo");
                /*
                        ACA SE PUEDEN AGREGAR COSAS A LOS SIMBOLOS DE ATRIBUTOS CARGADOS
                */

                // Marcamos a la clase que pertenece el atributo
                newAttribute->classOfSymbol = classOfAttribute;

                // agregamos el nuevo símbolo al vector de simbolos de la clase        
                tsClass->insert(newAttribute);
        }        
};
/**
 * Esta función verifica si un método con la clave, alcance y uso dados existe en la tabla de símbolos de la clase actual o en cualquiera de sus clases heredadas.
 * Si el método se encuentra en la tabla de símbolos de la clase actual, devuelve 0.
 * Si el método se encuentra en una tabla de símbolos de clase heredada, devuelve 1.
 * Si el método no se encuentra en ninguna de las tablas de símbolos, devuelve -1.
 *
 * @param key La clave del método a buscar.
 * @param scope El alcance del método a buscar.
 * @param uso El uso del método a buscar.
 * @param classSymbol La tabla de símbolos de la clase actual en la que buscar.
 * @return Un entero que indica si el método se encontró en la tabla de símbolos de la clase actual (0), en una tabla de símbolos de clase heredada (1), o no se encontró (-1).
 */
int existMethodInInheritance(string key, string scope, string uso, symbol* classSymbol){
    // verificamos si el método está en la tabla de símbolos de la clase actual, si es asi devolvemos 0
    // si no es asi verificamos si está en alguna de las que hereda (de derecha a izquierda), si es asi devolvemos 1 y si no esta devolvemos 2
    // revisar cuantas herencias hay, en base a esto hacer un for que se encargue de reccorer cada una de las tablas de las clases y en cada llamado usar la funcion getdiffscope y si lo que devuelve es 0 significa que esta
    
    // verificamos a que distancia se encuentra la primer aparición del atributo en un ámbito alcanzable
    int diff = classSymbol->attributesAndMethodsVector->getDiffOffScope2(key, "metodo", scope);        
    if(diff == 0){
        //si el método está en la propia tabla de símbolos de la clase se devuelve 0
        return 0;
    }else{
        // recorres el arreglo de herencia de esta clase verificando que exista alguna posicion con nullptr, si es asi verificas si esa clase tiene unmetodo con el mismo nombre y si es asi devuelves 1
        for (int i=1; i >= 0; i--){
            if(classSymbol->inheritance[i]!=nullptr){
                
                // verificar que en esa tabla no exista el simbolo
                bool existMethodInTable = classSymbol->inheritance[i]->existMethodInTable(key,uso);

                if(existMethodInTable){
                    return 1;
                }
            }
        }
        return -1;
   }           
}
/**
 * Cuando detectamos un método de clase
 * se elimina el símbolo viejo de la tabla
 * se carga el nuevo símbolo a la tabla de la clase
 * 
 * @param key nombre del acceso
 * @param scope scope actual
 * @param classOfAttribute nombre de la clase a la que pertenece
 */
void initMethod(string key, string scope, string classOfAttribute){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        tableSymbol->deleteSymbol(key);   // eliminamos el simbolo (usa el contador) de la tabla general
        symbol * classSymbol = stackClasses->top();
        TableSymbol* tsClass = classSymbol->attributesAndMethodsVector; // obtenemos la tabla de simbolos de la clase a la que le agramos el metodo
        cantOfRecursionsInMethod = 0;

        int methodAlredyExist = existMethodInInheritance(key, scope, "metodo", classSymbol);    // verificamos si el método ya existe en la clase o en alguna de sus clases heredadas

        if(methodAlredyExist == 0){
                yyerror("Redeclaracion de metodo en la misma clase");
        }
        if(methodAlredyExist == 1){
                yyerror("Sobreescritura de metodos prohibida");
        }      
        // aunque tire error igual lo agregamos para que no falle la genreacion de codigo   
                
        // creamos el nuevo símbolo
        symbol* newMetodo = new symbol(key+scope, "", "void", "metodo");
        /*
                ACA SE PUEDEN AGREGAR COSAS A LOS SIMBOLOS DE METODOS CARGADOS
        */

        newMetodo->classOfSymbol = classOfAttribute;

        // agregamos el nuevo símbolo al vector de simbolos de la clase        
        tsClass->insert(newMetodo);
        
        // seteamos que si se debe agregar un parametro se le haga a este método
        lastMethod = newMetodo;

        // agregamos un scope
        tableSymbol->addScope(key);

        // creamos una stack para la función y la agregamos al stack con el nombre
        functionStack* fs = new functionStack(key+scope);
        fs->ter = new Tercets();
        stackFunction->push(fs);
        
        cantOfRecursions++;        
};                        
/**
 * Cuando detectamos un parámtro en un método de clase
 * se elimina el símbolo viejo de la tabla
 * se carga el nuevo símbolo a la tabla de la clase
 * Se carga como una variable y se le agrega a su scope el nombre del método
 * 
 * @param key nombre del acceso
 * @param scope scope actual
 * @param type tipo del acceso
 * @param classOfAttribute nombre de la clase a la que pertenece
*/
void addParamMetodo(string key, string scope, string type, string classOfAttribute){

    // obtener el símbolo viejo y eliminarlo
    // verificar que no esté previamente en ese scope en esa tabla de símobolo
    // lo agregamos y setear el tipo del parametro


    tableSymbol->deleteSymbol(key);    // eliminamos el simbolo (usa el contador) de la tabla general
    

    /* SE SUPONE QUE ESTO NUNCA DEBERÍA SUCEDER PORQUE ES UN SOLO PARÁEMETRO Y LA PRIMER VARIABLE DEL ÁMBITO */
    // verificamos a que distancia se encuentra la primer aparición de la variable en un ámbito alcanzable dentro de la tala de símbolos de la clase
    int diff = tableSymbol->getDiffOffScope2(key, "var", scope); 
    if(diff == 0){
        yyerror("Redeclaracion de variable en el mismo ambito del metodo");
    }else{
        // creamos el nuevo símbolo
        symbol* newparam = new symbol(key+scope, "", type, "var");

        // agregamos el nuevo símbolo al vector de simbolos de la clase        
        tableSymbol->insert(newparam);

        lastMethod->cantParam++;
        lastMethod->typeParam = type;
        lastMethod->nameParam = key+scope;
    }
};
/**
 * Cuando detectamos un parámtro en una declaración de función
 * eliminamos el símbolo viejo de la tabla
 * verificamos si es dentro de una clase o fuera
 * si está afuera de una clase terminamos
 * 
 * @param key nombre del acceso
 * @param scope scope actual
 * @param type tipo del parámetro
 * @param reglaptr puntero al lexema de la regla
 * @param reglatype puntero al tipo de la regla
*/
void addParamFunction(string key, string scope, string type, string & reglaptr, string& reglatype){
    //  verificamos si está dentro de la declaración de una clase o no

    // obtener el símbolo viejo y eliminarlo
    // setear el tipo del parametro

    // obtenemos la tabla general y le cargamos el parametro como variable
    symbol* newIdentificador = setNewScope(key, type, scope, "var", tableSymbol); 

    // seteamos el parámetro al símbolo de la función
    lastMethod->cantParam++;
    lastMethod->typeParam = type;
    lastMethod->nameParam = key+scope;
    
    reglaptr = newIdentificador->lexema; 
    reglatype = type;
};

string checkNewNameBeforeInsert(symbol* newSm){
    // funcion que se encarga de borrar las apariciones de nombres de clases dentro un lexema 
    // y de verificar que no exista un nombre igual en el mismo ámbito
    // la logica funciona en iterar sobre la tabla de symbolor preguntando por cada uno de los lexemas si es que son de tipo clase
    // si es asi se crea una variable auxiliar donde se concatena de forma correcta el nuevo lexema para buscar si este se encuentra como substring dentro de 
    // de nuevo lexema a insertar dentro de la tabla de simbolos 
    
    for (const auto& par : tableSymbol->getSymbolTable()){
        symbol* sm = par.second;
        if(sm->uso == "clase"){
            // creo una variable aux para guardar el lexema                 ejemplo= b:main:func3
            string lexemaAux = sm->lexema;
            //busco la primera aparicion de :                               ejemplo= 2
            size_t firstColonPos = lexemaAux.find(':');
            //obtengo el nombre de la clase para su uso a posteriori        ejemplo= b
            string nameOfClass = lexemaAux.substr(0, firstColonPos); 
            //busco el tamaño de la palabra                                 ejemplo= 12
            size_t secondColonPos = lexemaAux.size();
            //creo el nuevo lexema                                         ejemplo= primer substr = main:func3 segundo substr = b, lo concateno y queda main:func3:b
            lexemaAux =  lexemaAux.substr(firstColonPos + 1, secondColonPos)+":"+lexemaAux.substr(0,firstColonPos);
            //busco si el nuevo lexema se encuentra dentro del lexema a insertar
            size_t pos = newSm->lexema.find(lexemaAux);
            // si encuentra una posicion con el find significa que esta
            if(pos != string::npos){
                    //si se encuentra dentro del lexema a insertar, se borra la aparicion de el nombre de la clase unicamente 
                    size_t pos = newSm->lexema.find(nameOfClass);
                    newSm->lexema.erase(pos-1, pos);      //siguiendo con el ejemplo y suponiendo que tenemos x:main:func3:b, se borra la aparicion de b y queda x:main:func3
                    newSm->lexema =  newSm->lexema +":"+nameOfClass; //se concatena el nombre de la clase al final del lexema
            }
        }
    }
    return newSm->lexema;
}
/**
 * Cuando se detecta una declaración de objeto se llama esta función
 * Verificamos que no exista un objeto en el mismo ámbito con el mismo nombre   
 * agregamos el objeto a la tabla general, obtenemos la clase del objeto
 * agregamos cada atributo y método de la clase y de sus herencias. 
 * 
 * @param key El nombre del objeto a agregar.
 * @param scope El scope del objeto a agregar.
 * @param classType La clase del objeto a agregar.
 */
void addObject(string key, string scope, string classType){
    // si la clase no existe no hacemos nada ya que en la función initObjectDeclaration() se levanta el error de clase no declarada
    if (classType == "_error"){
        return;
    }
        
    // verificamos que no existea un objeto con el mismo nombre en el mismo ámbito
    int diff = tableSymbol->getDiffOffScope2(key, "objeto", scope); 
    if(diff == 0){
        // existe un objeto ocn el mismo nombre en el mismo ámbito
        yyerror("Redeclaracion del objeto " + key + " en el mismo ambito");
    }else{
        // eliminamos el símbolo viejo y lo agregamos en la tabla de simbolo general
        symbol* newObject = setNewScope(key, "", scope, "objeto", tableSymbol);
        /*
            ACA SE AGREGAN LOS ATRIBUTOS AL OBJETO INSTANCIADO
        */
        newObject->classOfSymbol = classType; // seteamos el tipo de clase del objeto

        // obtenemos el símbolo de la clase del objeto
        symbol* matchingClass = tableSymbol->getFirstSymbolMatching2(classType, "clase", ":main"); // obtenemos el símbolo de la clase del objeto
        
        // verificamos si la clase es una forward declaration 
        // de ser forward el objeto también se convierte en forwarded para luego isntanciarlo cuando la clase se declare
        // ya que si es asi no podemos agregar sus atributos y métodos
        if(matchingClass->forwarded){
            newObject->posponeForForwarding = true;    
            return;
        }
        
        // recorremos la tabla de símbolos de la clase del objeto y agregamos cada uno de los elementos
        for (const auto& par : matchingClass->attributesAndMethodsVector->getSymbolTable()){
            symbol* simbolo = par.second;
            // creamos el nuevo símbolo
            symbol* newSm = new symbol(*simbolo);                
            
            // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
            //      la tabla de tercetos principal o de ejecución
            if(newSm->uso=="metodo" || newSm->uso=="funcion"){
                createFunctionTerecets(key, scope, newSm, matchingClass->attributesAndMethodsVector);
            }
                    
            if(newSm->uso=="objeto"){
                // como el elemento de la clase es un objeto, debemos copiar cada atributo de la clase del objeto e intanciarlo
                // string objectName = newSm->lexema.substr(0, newSm->lexema.find(":"));
                // ob1 ob2:main:clase1 :main clase1
                newSm->posponeForForwarding = instanciateObject(key, newSm->lexema, scope, newSm->classOfSymbol);
            }

            newSm->lexema = newSm->lexema+":"+key+scope; // le agregamos el nombre del objeto + el scope actual
            
            // agregamos el nuevo símbolo a la tabla de simbolos        
            tableSymbol->insert(newSm);
        }

        // recorremos las herencias de derecha a izquierda y agregamos cada uno de los elementos a la tabla general

        // recorres el arreglo de herencia de esta clase verificando que exista alguna posicion con nullptr, si es asi verificas si esa clase tiene unmetodo con el mismo nombre y si es asi devuelves 1
        for (int i=1; i >= 0; i--){
            TableSymbol* tableSymbolMatchingClass = matchingClass->inheritance[i];
            // si hereda de alguna clase recorremos sus simbolos y los agregamos
            if(tableSymbolMatchingClass != nullptr){
                
                // recorremos la tabla de símbolos de la clase que hereda y agregamos cada uno de los elementos
                for (const auto& par : tableSymbolMatchingClass->getSymbolTable()){
                        symbol* simbolo = par.second;
                        // creamos el nuevo símbolo
                        symbol* newSm = new symbol(*simbolo);                
                        
                        // verificamos si el simbolo es una función o método y cargamos su bloque de tercetos en 
                        //      la tabla de tercetos principal o de ejecución
                        if(newSm->uso=="metodo" || newSm->uso=="funcion"){
                            createFunctionTerecets(key, scope, newSm, tableSymbolMatchingClass);
                        }

                        if(newSm->uso=="objeto"){
                            // como el elemento de la clase es un objeto, debemos copiar cada atributo de la clase del objeto e intanciarlo
                            // string objectName = newSm->lexema.substr(0, newSm->lexema.find(":"));
                            // ob1 ob2:main:clase1 :main clase1
                            newSm->posponeForForwarding = instanciateObject(key, newSm->lexema, scope, newSm->classOfSymbol);
                        }

                        newSm->lexema = newSm->lexema+":"+key+scope; // le agregamos el nombre del objeto + el scope actual
                        
                        // agregamos el nuevo símbolo a la tabla de simbolos        
                        tableSymbol->insert(newSm);
                }
            }
        }
    } 
};
/**
 * cuando detectamos una declaracion de función
 * eliminamos el símbolo viejo de la tabla
 * verificamos si es dentro de una clase o fuera
 * si está afuera de una clase lo agregamos a la tabla general
 * si está dentro de una clase lo agregamos a la tabla de la clase y le seteamos la clase a la que pertenece y el scope inside class
 * 
 * @param key nombre del acceso
 * @param scope scope actual
*/
void initFunction(string key, string scope){        
        string scopeOriginal = scope;

        // verificamos si es dentro de una clase 
        if(stackClasses->size() > 0){
            // si estamos dentro de una clase sumamos 1 a la recursión interna de metodo
            cantOfRecursionsInMethod++;
            if(cantOfRecursionsInMethod > 1){
                    yyerror("No se permite anidamiento de funciones locales dentro de metodos");
            }
        }

        // buscamos si existe una función con el mismo nombre en el mismo ámbito
        int diff = tableSymbol->getDiffOffScope2(key, "funcion", scope); 
        if( diff == 0){
                yyerror("Redeclaracion de funcion en el mismo ambito");
        }else{
                symbol* newFunction = setNewScope(key, "void", scope, "funcion", tableSymbol); 
                
                // cargamos cual fue el último método o función por si tiene un parámetro
                lastMethod = newFunction;
                // si esta dentro de una clase le seteamos los atributos de clase y scopeInsideClass
                if(stackClasses->size() > 0){
                        string classOfAttribute = stackClasses->top()->classOfSymbol;
                        newFunction->classOfSymbol = classOfAttribute;
                        newFunction->scopeInsideClass = scope.substr(scope.find(classOfAttribute) + classOfAttribute.length());
                }
        } 
        // agregamos al scope el nombre de la función
        tableSymbol->addScope(key);
        // creamos un vector de función y lo agregamos al stack con el nombre
        functionStack* fs = new functionStack(key+scope);
        fs->ter = new Tercets();
        stackFunction->push(fs);
        //verificamos las recursiones y le sumamos uno
        cantOfRecursions++;
};
/**
 * Cuando detectamos el fin de una declaracion de función
 * guardamos el bloque de tercetos de la función
 * sacamos el scope de la función
*/
void finishFunction(){
    // obtenemos el stack con los tercetos de la función
    functionStack* fs = stackFunction->top();
    stackFunction->pop();
    tableSymbol->deleteScope(); // sacamos el scope de la función
    cantOfRecursions--;     // sacamos una recursión

    vectorOfFunction->add(fs);
    if(stackClasses->size() > 0){
        // si no está dentro de una clase lo agregamos a la tabla general
        cantOfRecursionsInMethod--;
    }
            
}
/**
 * cuando detectamos el fin de una declaracion de metodo
 * guardamos el bloque de tercetos de la función
 * sacamos el scope de la función
*/
void finishMethod(){
        // obtenemos el stack con los tercetos de la función
        functionStack* fs = stackFunction->top();
        stackFunction->pop();
        // los vectores siempre se guardan en el vector de funciones declaradas en clases
        vectorOfFunctionDeclaredInClasses->add(fs);
        tableSymbol->deleteScope(); // sacamos el scope de la función
        cantOfRecursions--;     // sacamos una recursión
};
/**
 * Cuando detectas una variable
 * Borras el símbolo de la tabla general
 * verifica si existe una variable alcanzable y si existe seteea el $$->ptr con el lexema
 *
 * @param key el acceso.
 * @param scope el scope actual
 * @param reglaptr puntero al lexema de la regla
 * @param reglatype puntero al tipo de la regla
 * @throws yyerror si no hay variable enalcanzable
 */
void checkVarInScope(string key, string scope, string uso, string& reglaptr, string& reglatype){
        // borramos el simbolo de la tabla general
        tableSymbol->deleteSymbol(key); 

        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching2(key, uso, scope); 
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la variable "+ key);
        }else{
                reglaptr = symbolFinded->lexema;
                reglatype = symbolFinded->type;

                /* en este punto sabes que es una variable declarada, 
                    pero ahora quiero saber si es de este ámbito o de otro, 
                    si es de otro y esa variable tiene el check debo informar que se está usando a la izquierda de una asignación
                */
                
                // si el símbolo tiene que checkearse y si los lexemas no coincidencia entonces es una variable de otro ámbito
                if(symbolFinded->isVariableToCheck && key+scope != symbolFinded->lexema){
                    yywarning("Se esta usando la variable "+ key +" como una expresion en un ambito diferente al de su declaracion");
                }
        }
};

/**
 * función cuando se detecta una variable++ 
 *
 * @param key el acceso.
 * @param scope el scope actual
 * @param reglaptr puntero al lexema de la regla
 * @param reglatype puntero al tipo de la regla
 * @throws yyerror si no hay variable enalcanzable
 */
void newFactorMasMas (string key, string scope, string& reglaptr, string& reglatype){
    tableSymbol->deleteSymbol(key);
    
    symbol* symbolFinded = tableSymbol->getFirstSymbolMatching2(key, "var", scope); 
    if(symbolFinded == nullptr){
        yyerror("No se encontro declaracion previa de la variable "+ key);
    }else{
        string value = "";
        if(symbolFinded->type == "unsigned int"){
            value = "1_ui";
        }else if(symbolFinded->type == "short"){
            value = "1_s";
        }else if(symbolFinded->type == "float"){
            value = "1.0";
        }
        int number = addTercet("+", symbolFinded->lexema, value);   
        number = addTercet("=", symbolFinded->lexema, charTercetoId + to_string(number));       
        
        reglaptr = symbolFinded->lexema;
        reglatype = symbolFinded->type;

        /* en este punto sabes que es una variable declarada, 
            pero ahora quiero saber si es de este ámbito o de otro, 
            si es de otro y esa variable tiene el check debo informar que se está usando a la izquierda de una asignación
            ESTO LO DEJO PARA ZUCCHI, DESPUES BORRAR ESTE COMENTARIO
        */
        
        // si el símbolo tiene que checkearse y si los lexemas no coincidencia entonces es una variable de otro ámbito
        if(symbolFinded->isVariableToCheck && key+scope != symbolFinded->lexema){
            yywarning("Se esta modificando la variable "+ key +" en un ambito diferente al de su declaracion");
        }
    }
}
/**
 * función cuando se detecta una asginación sobre una variable
 * Borras el símbolo de la tabla general
 * verifica si existe una variable alcanzable
 * verifica que los tipos sean iguales
 * verifica que si se usa una variable de otro ámbito que tiene el checkeo activo se informa 
 *
 * @param key el acceso al identificador al que se le asigna.
 * @param scope el scope actual
 * @param op2Lexeme el acceso de lo que se asigna
 * @param op2Type el tipo de lo que se asigna
 * @throws yyerror si no hay variable alcanzable
 */
void newAsignacion(string key, string scope, string op2Lexeme, string op2Type){
        // borramos el simbolo de la tabla general
        tableSymbol->deleteSymbol(key); 
        
        //buscamos si existe una variable con el mismo nombre al alcance de la tabla de simbolos
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching2(key, "var", scope); 
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la variable "+ key);
        }else{
                // checkeamos que los tipos sean iguales 
                checkTypesAsignation(symbolFinded->type, op2Type); 
                bool isOp1Posponed = symbolFinded->type == "pospone";
                bool isOp2Posponed = op2Type == "pospone";
                // agregamos el terceto de asignación en la respectiva tabla de tercetos
                int number = addTercetPospone("=", symbolFinded->lexema, op2Lexeme, isOp1Posponed, isOp2Posponed, symbolFinded->type, op2Type, symbolFinded->type);
                
                /* en este punto sabes que es una variable declarada, 
                    pero ahora quiero saber si es de este ámbito o de otro, 
                    si es de otro y esa variable tiene el check debo informar que se está usando a la izquierda de una asignación
                
                */

                // si al variable tiene asignado que se checke y si los lexemas no coincidencia entonces es una variable de otro ámbito
                if(symbolFinded->isVariableToCheck && key+scope != symbolFinded->lexema){
                    yywarning("Se esta usando la variable "+ key +" a la izquierda de una asignacion en un ambito diferente al de su declaracion");
                }
        } 
};

void newOperacionAritmetica(string operador, string op1ptr, string op2ptr, string op1type, string op2type, string& reglaptr, string& reglatype){
        if(op1type != "pospone" && op2type != "pospone"){
            if(checkTypesOperation(op1type, op2type)){
                    reglatype = op1type;
            }else{
                    reglatype = "error";
            } 

            int number = addTercetWithType(operador, op1ptr, op2ptr, op1type, op2type, reglatype); 
            reglaptr = charTercetoId + to_string(number); 

        }else{
            reglatype = "pospone";
            bool isOp1Posponed = op1type == "pospone";
            bool isOp2Posponed = op2type == "pospone";
            int number = addTercetPospone(operador, op1ptr, op2ptr, isOp1Posponed, isOp2Posponed, op1type, op2type, reglatype); 
            reglaptr = charTercetoId + to_string(number); 
        }
        
}
void newTof(string key, string opType, string& reglaptr, string& reglatype){
        /* int number = addTercet("tof", " ", key); 
        reglaptr = charTercetoId + to_string(number); 
        */
        if(opType != "pospone" ){
            int number = addTercetWithType("tof", "", key, "float", opType, "float"); 
            reglaptr = charTercetoId + to_string(number); 
        }else{
            reglatype = "pospone";
            int number = addTercetPospone("tof", "", key, false, true, "float", opType, reglatype); 
            reglaptr = charTercetoId + to_string(number); 
        }
        reglatype = "float"; 
}
void condition(string& reglaptr){
        string lastTercet;
        if(cantOfRecursions <= 0){
            lastTercet = to_string(tableTercets->numberOfLastTercet());
        }else{
            lastTercet = to_string(stackFunction->top()->ter->numberOfLastTercet());
        }
        int number = addTercetAndStack("BF", charTercetoId + lastTercet, ""); 
        reglaptr = charTercetoId + to_string(number); 
}

void addElse(string& reglaptr){
        string lastTercet;
        if(cantOfRecursions <= 0){
            lastTercet = to_string(tableTercets->numberOfLastTercet()+ 2);
        }else{
            lastTercet = to_string(stackFunction->top()->ter->numberOfLastTercet() + 2);
        }
        Tercet * t = popTercet();  
        if (t!=nullptr){
                t->setArg2( charTercetoId + lastTercet);
        } 
        int number =  addTercetAndStack("BI", "", ""); 
        number = addTercet("label","label"+to_string(cantLabels),"");
        cantLabels++;
        reglaptr = charTercetoId + to_string(number); 
}

void finIf(){
        string lastTercet;
        if(cantOfRecursions <= 0){
            lastTercet = to_string(tableTercets->numberOfLastTercet() + 1);
        }else{
            lastTercet = to_string(stackFunction->top()->ter->numberOfLastTercet() + 1);
        }
        Tercet *t = popTercet(); 
        if (t!=nullptr){
                t->setArg2( charTercetoId + lastTercet);
        }
        int number = addTercet("label","label"+to_string(cantLabels),"");
        cantLabels++;
}

void initWhile(){
    string lastTercet;
    if(cantOfRecursions <= 0){
        lastTercet = to_string(tableTercets->numberOfLastTercet() + 1);
    }else{
        lastTercet = to_string(stackFunction->top()->ter->numberOfLastTercet() + 1);
    }
    addTercetOnlyStack("incioCondicionWhile", charTercetoId + lastTercet, "");
    int number = addTercet("label","label"+to_string(cantLabels),"");
    cantLabels++;
}

void finWhile(string & reglaptr) {
    string lastTercet;
    if(cantOfRecursions <= 0){
        lastTercet = to_string(tableTercets->numberOfLastTercet() + 2);
    }else{
        lastTercet = to_string(stackFunction->top()->ter->numberOfLastTercet() + 2);
    }
    Tercet *t = popTercet(); 
    if (t!=nullptr){
            t->setArg2( charTercetoId + lastTercet );
    } 
    Tercet *t2 = popTercet(); 
    int number; 
    if(t2!=nullptr){
            number = addTercet("BI", t2->getArg1(), "");
    } 
    number = addTercet("label","label"+to_string(cantLabels),"");
    cantLabels++;
    reglaptr = charTercetoId + to_string(number);
}

void newCondicion(string operador, string op1ptr, string op2ptr, string op1type, string op2type, string& reglaptr){
    checkTypesCompare(op1type, op2type); 
    int number = addTercet(operador, op1ptr, op2ptr); 
    reglaptr = charTercetoId + to_string(number);
}

/**
 * Cuando se detecta una sentencia que declara una variable se llama esta función.
 * Agrega una nueva variable a la tabla de símbolos específica de clase o la general.
 * Agrega los atributos correspondientes al símbolo
 * Verifica que si se usa una variable de otro ámbito que tiene el checkeo activo se informa 
 *
 * @param key La clave de la variable.
 * @param scope El ámbito de la variable.
 * @param type El tipo de la variable.
 */
void newVariable(string key, string scope, string type){
    symbol* newIdentificador = nullptr;
    
    //buscamos si esta definida ya una variable con ese mismo nombre dentro de la tabla de simbolos que corresponda
    int diff = tableSymbol->getDiffOffScope2(key, "var", scope); 
    if(diff == 0){
        // existe una variable previa en el mismo ambito con el mismo nombre
        yyerror("Redeclaracion de variable en el mismo ambito");
    }else{
        
        newIdentificador = setNewScope(key, type, scope, "var", tableSymbol); 
        /*
            ACA SE PUEDEN AGREGAR COSAS A LOS SIMBOLOS DE VARIABLES CARGADOS
        */
        if (isVariableToCheck){
            // si es una variable a chequear le seteamos que se debe checkear en el simbolo
            newIdentificador->isVariableToCheck = true;
        }
    }
};
/**
 * Cuando se detecta la clase de un objeto a instanciar se llama esta función.
 * Borra el símbolo de la tabla de símbolos general.
 * Verifica que la clase haya sido declarada y exista.
 * 
 * @param key nombre de la clase
 * @param scope El alcance del objeto.
 * @param reglaptr El puntero a la regla.
 */
void initObjectDeclaration(string key, string scope, string& reglaptr){
    // verificar que la clase haya sido declarada y exista
    // borramos el símbolo de la tabla de símbolos general
    tableSymbol->deleteSymbol(key);
    // usamos ":main" porque todas las clases se usan en el ámbito ":main"
    symbol* classFinded = tableSymbol->getFirstSymbolMatching2(key, "clase", ":main");
    //debo revisar si es estoy dentro de una clase o no, ya que pudiera pasar que uno quiera declarar un objeto de una dentro de la misma clase
    if(classFinded == nullptr){
        yyerror("No se encontro declaracion previa de la clase "+ key);
        actualClass = "_error"; 
    }else{ 
        if(stackClasses->size() > 0){
            //si estoy dentro de una clase, debo verificar que la clase que quiero instanciar no sea la misma clase en la que estoy
            if(stackClasses->top()->classOfSymbol == key){
                yyerror("No se puede instanciar un objeto de la misma clase en la que se encuentra");
                actualClass = "_error"; 
            }
        }
        reglaptr = key; 
        actualClass = key; 
    }
}
/**
 * Borra el simbolo de la tabla general
 * verifica si existe la clase a heredar, sino existe lanza un error de que no existe la clase
 * si encontras la clase copias su arreglo de herencia a esta clase que hereda y le agregas en el primer nullptr la clase a heredar (si te pasas de 3 elemetos throw error de que no se puede heredar más de 3 veces))
 *
 *
 * @param classToInherit The name of the class to inherit from.
 * @param scope The scope of the inheriting class.
 * @param classWhoInherit The name of the class that inherits.
 * @return void
 */
void  detectInheritance(string classToInherit , string scope, string classWhoInherit){
        
        // borrar el simbolo de la tabla general
        // buscar si existe la clase a heredar, sino existe lanzar un error de que no existe la clase
        // si encontras la clase copias su arrehlo de herencia a el arreglo de este símbolo y luego le agregas la clase a 
        // heredar en el primer nullptr de ese arreglo (si te pasas de 3 elemetos throw error de que no se puede heredar más de 3 veces))

        tableSymbol->deleteSymbol(classToInherit); // borramos el símbolo de la tabla general

        symbol* symbolofClassWhoInherit = stackClasses->top();  //guardas el simbolo de la ultima clase creada y agregada al stack de clases

        // verificamos que no herede esta clase de otro,solo puede heredar de una
        if (symbolofClassWhoInherit->isAlreadyInhenriting){
                        yyerror("La clase " + symbolofClassWhoInherit->classOfSymbol +" ya hereda de otra clase");
        }else{
                // buscamos la clase a heredar, la buscamos con scope ":main" porque es en el único lugar donde se pueden declarar clases
                symbol* classFinded = tableSymbol->getFirstSymbolMatching2(classToInherit, "clase", ":main");
                if(classFinded == nullptr){
                        yyerror("No se encontro declaracion previa de la clase a heredar "+ classToInherit);
                }else if (symbolofClassWhoInherit->classOfSymbol == classToInherit)
                        {
                                yyerror("La clase " + symbolofClassWhoInherit->classOfSymbol +" intenta heredar de si misma");
                        }else{
                            // copiamos el arreglo de herencia de la clase a heredar a la clase que hereda
                            // intentamos agregar la clase a heredar en el primer nullptr del arreglo de herencia, si tiene más de 3 elementos lanzamos un error

                            // copiamos el arreglo de herencia de la clase a heredar a la clase que hereda
                            for(int i = 0; i < 2; i++) {
                                    symbolofClassWhoInherit->inheritance[i] = classFinded->inheritance[i];
                            }
                            bool isNullptr = false;
                            int posOfNullInInheritance = -1;
                            // recorres el arreglo verificando que exista alguna posicion con nullptr, si es asi seteas el booleano con true y guardas la posicion del nullptr.
                            for (int i=0; i < 2; i++){
                                    if(symbolofClassWhoInherit->inheritance[i]==nullptr){
                                            isNullptr = true;
                                            posOfNullInInheritance = i;
                                            break;
                                    }
                            }
                            // si el boleano es true, agregas la clase a heredar en el lugar que se encuentra nullptr del arreglo de herencia, si no es true lanzas un error diciendo que ya existe una herencia de 3 clases
                            if(isNullptr){
                                    symbolofClassWhoInherit->inheritance[posOfNullInInheritance] = classFinded->attributesAndMethodsVector; 
                                    symbolofClassWhoInherit->isAlreadyInhenriting = true; 
                                    //se debe realizar un chequeo de metodos para evitar la sobreescritura de metodos
                                    //si se encuentra un metodo con el mismo nombre en la clase que hereda y en la clase que es heredada se lanza un error
                                    for (const auto& par : symbolofClassWhoInherit->attributesAndMethodsVector->getSymbolTable()){
                                        symbol* sm = par.second;
                                        if(sm->uso == "metodo"){
                                            string lexemaAux = sm->lexema.substr(0, sm->lexema.find(":"));
                                            symbol* sm2 = classFinded->attributesAndMethodsVector->getElementInTableByFisrtPartAndUse(lexemaAux, "metodo");
                                            //accedo si es que classfinded hereda de otra clase para verificar si esta tambien hereda un metodo con el mismo nombre
                                            symbol* sm3;
                                            if(classFinded->inheritance[0] != nullptr){
                                                symbol* sm3 = classFinded->inheritance[0]->getElementInTableByFisrtPartAndUse(lexemaAux, "metodo");
                                            }
                                            if(sm2 != nullptr || sm3 != nullptr){
                                                yyerror("La clase " + symbolofClassWhoInherit->classOfSymbol +" intenta heredar de " + classToInherit + " pero ya hereda un metodo con el mismo nombre");
                                                }
                                        }
                                    }
                                    
                            }else{
                                    yyerror("La clase " + symbolofClassWhoInherit->classOfSymbol +" intenta heredar de " + classToInherit + " pero ya hereda de 2 clases");
                            }
                        
                        }
        }
}
/**
 * Cuando finaliza la declaración de variables se llama esta función.
 * Establece la variable para checkeo de variables en falso.
 */
void finishVariableDeclaration(){
    isVariableToCheck = false;
}
/**
 * Cuando se detecta la palabra reservada CHECK se llama esta función.
 * Establece la variable para checkeo de variables en true.
 */
void setVariableToCheck(){
    isVariableToCheck = true;
}
/**
 * Esta función busca el símbolo de un atributo que tenga el mismo nombre que el parámetro en el símbolo del a clase, si no está busca en sus herencias.
 * si encuentra elsímbololo devuelve y sino devuelve nullptr
 *
 * @param key La clave del método a buscar.
 * @param classSymbol La tabla de símbolos de la clase actual en la que buscar.
 * @return puntero al simbolo del atributo encontrado o nullptr sino lo encuentra
 */
symbol* getFirstSymbolMatchingOfAttribute(string attributeName, symbol* classSymbol){
    
    // verificamos si el elemento está en la tabla de símbolos de la clase actual, si está devolvemos el símbolo
    // si no es asi verificamos si está en alguna de las que hereda (de derecha a izquierda), si está devilvemos el símbolo
    // sino lo encontramos devolvemos nullptr
    
    // obtenemos el simbolo que tenga el mismo nombre (solo mira la primer parte del nombre) y el mismo uso
    symbol* symbolAttribute = classSymbol->attributesAndMethodsVector->getElementInTableByFisrtPartAndUse(attributeName, "atributo");
    if(symbolAttribute != nullptr){
        // si encontramos el atributo en la tabla de símbolos de la clase actual devolvemos el símbolo
        return symbolAttribute;
    }else{
        // si no encontramos símbolo en la tabla principal dela clase buscamos en sus herencias de derecha a izquierda ya que si hay sobre escritura buscamos la más reciente
        for (int i=1; i >= 0; i--){
            if(classSymbol->inheritance[i]!=nullptr){
                
                // obtener el símbolo de la clase que hereda
                symbolAttribute = classSymbol->inheritance[i]->getElementInTableByFisrtPartAndUse(attributeName, "atributo");
                if(symbolAttribute != nullptr){
                    return symbolAttribute;
                }
            }
        }
        return nullptr;
    }           
}
/**
 * Esta función busca el símbolo de un objeto que tenga el mismo nombre que el parámetro en el símbolo del a clase, si no está busca en sus herencias.
 * si encuentra el símbolo lo devuelve y sino devuelve nullptr
 *
 * @param key La clave del método a buscar.
 * @param classSymbol La tabla de símbolos de la clase actual en la que buscar.
 * @return puntero al simbolo del atributo encontrado o nullptr sino lo encuentra
 */
symbol* getFirstSymbolMatchingOfObject(string objectName, symbol* classSymbol){
    
    // verificamos si el elemento está en la tabla de símbolos de la clase actual, si está devolvemos el símbolo
    // si no es asi verificamos si está en alguna de las que hereda (de derecha a izquierda), si está devilvemos el símbolo
    // sino lo encontramos devolvemos nullptr
    
    // obtenemos el simbolo que tenga el mismo nombre (solo mira la primer parte del nombre) y el mismo uso
    symbol* symbolAttribute = classSymbol->attributesAndMethodsVector->getElementInTableByFisrtPartAndUse(objectName, "objeto");
    if(symbolAttribute != nullptr){
        // si encontramos el atributo en la tabla de símbolos de la clase actual devolvemos el símbolo
        return symbolAttribute;
    }else{
        // si no encontramos símbolo en la tabla principal dela clase buscamos en sus herencias de derecha a izquierda ya que si hay sobre escritura buscamos la más reciente
        for (int i=1; i >= 0; i--){
            if(classSymbol->inheritance[i]!=nullptr){
                
                // obtener el símbolo de la clase que hereda
                symbolAttribute = classSymbol->inheritance[i]->getElementInTableByFisrtPartAndUse(objectName, "objeto");
                if(symbolAttribute != nullptr){
                    return symbolAttribute;
                }
            }
        }
        return nullptr;
    }           
}
/**
 * Esta función se llama cuando se detecta el uso de un atributo en una expresión aritmética (a la derecha de una asignación).
 * Verifica que el objeto esté declarado y obtiene su clase.
 * Verifica que la clase exista.
 * Verifica que la clase contenga el atributo.
 * Obtiene sumando el scope estático del atributo + nombre objeto + scope actual el lexema del símbolo propio del objeto.
 * asigna a reglaptr el lexema del símbolo y a reglatype el tipo del símbolo.
 *
 * @param objectName Nombre del objeto.
 * @param attributeName Nombre del atributo.
 * @param scope Alcance.
 * @param reglaptr Puntero a la regla.
 * @param reglatype Tipo de la regla.
 */
void newUseObjectAttribute(string objectName, string attributeName, string scope, string& reglaptr, string& reglatype){

    vector<string> accesos = getAccesoFromString(objectName);
    
    tableSymbol->deleteSymbol(accesos[0]);
    tableSymbol->deleteSymbol(attributeName);

    // Verifica que el objeto este declarado y obtiene su clase
    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
    symbol* classSymbol = nullptr;
    string classOfObject;
    if(objectSymbol == nullptr){
            yyerror("No se encontro declaracion previa del objeto"+ objectName);
    }else{
        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
        classOfObject = objectSymbol->classOfSymbol;
        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
        if(classSymbol == nullptr){
            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
        }else{
            // si el objeto fue pospuesto por forwarding entonces el checkeo del uso se pospone también
            if(objectSymbol->posponeForForwarding){
                reglaptr =  attributeName+":"+classOfObject+":"+objectName+"|"+scope;
                reglatype = "pospone";
                return;
            }
            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
            for(int i = 1; i < accesos.size(); i++){
                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                if(objectSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                    return;
                }else{
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                        return;
                    }else{
                        tableSymbol->deleteSymbol(accesos[i]);
                        if(objectSymbol->posponeForForwarding){
                            reglaptr =  attributeName+":"+classOfObject+":"+objectName+"|"+scope;
                            reglatype = "pospone";
                            return;
                        }
                    }
                }
            }

            // si encontramos la clase verificamos que contenga el atributo     
            symbol* attributeSymbol = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

            if(attributeSymbol == nullptr){
                yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
            }else{
                // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                
                attributeSymbol = tableSymbol->getFirstSymbolMatching2(attributeSymbol->lexema + ":" + accesos[0], "atributo", scope);
                if (attributeSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                }else{
                    reglaptr =  attributeSymbol->lexema;
                    reglatype = attributeSymbol->type;
                }
            }
        }
    }
};
/**
 * Esta función se llama cuando se detecta la asignación de una expresión a un atributo de un objeto.
 * Verifica que el objeto esté declarado y obtiene su clase.
 * Verifica que la clase exista.
 * Verifica que la clase contenga el atributo.
 * Obtiene sumando el scope estático del atributo + nombre objeto + scope actual el lexema del símbolo propio del objeto.
 * Verifica que los tipos sean iguales.
 * Genera la asignación de la expresión al atributo del objeto.
 * 
 * @param objectName Nombre del objeto.
 * @param attributeName Nombre del atributo.
 * @param scope Alcance.
 * @param op2Lexeme Lexema de la expresión a asignar.
 * @param op2Type Tipo de la expresión a asignar.
 * @param reglaptr Puntero al terceto generado.
 * @param reglatype Tipo del atributo.
 */
void newAsignacionObjectAttribute(string objectName, string attributeName, string scope, string op2Lexeme, string op2Type, string& reglaptr, string& reglatype){
    // la idea es que sabemos los accesos que hay que usar, entonces es buscar el primer símbolo del objeto, tomar suclase yverificar que tenga el segundo objeto y así
    // luego debemos quedarnos con el último símbolo de objeto y guardarlo en objectSymbol
    // si alguno de los objetos está pospuesto debemos crear el terceto correspondiente marcando los pospuestos y marcando todos los accesos para en el forwarding poder acceder
    
    vector<string> accesos = getAccesoFromString(objectName);
    
    tableSymbol->deleteSymbol(accesos[0]);
    tableSymbol->deleteSymbol(attributeName);

    // Verifica que el objeto este declarado y obtiene su clase
    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
    symbol* classSymbol = nullptr;
    string classOfObject;
    if(objectSymbol == nullptr){
            yyerror("No se encontro declaracion previa del objeto"+ objectName);
    }else{
        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
        classOfObject = objectSymbol->classOfSymbol;
        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
        if(classSymbol == nullptr){
            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
        }else{
            // si el objeto fue pospuesto por forwarding entonces el checkeo del uso se pospone también
            if(objectSymbol->posponeForForwarding){
                bool isOp2Posponed = op2Type == "pospone";
                // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                int number = addTercetPospone("=", attributeName+":"+classOfObject+":"+objectName+"|"+scope, op2Lexeme, true, isOp2Posponed, "pospone", op2Type);

                reglaptr = charTercetoId + to_string(number);
                return;
            }
            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
            for(int i = 1; i < accesos.size(); i++){
                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                if(objectSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                    return;
                }else{
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                        return;
                    }else{
                        tableSymbol->deleteSymbol(accesos[i]);
                        if(objectSymbol->posponeForForwarding){
                        // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                        int number = addTercetPospone("=", attributeName+":"+classOfObject+":"+objectName+"|"+scope, op2Lexeme, true, false, "pospone", op2Type);

                        reglaptr = charTercetoId + to_string(number);
                        return;
                        }
                    }
                }
            }

            // si encontramos la clase verificamos que contenga el atributo     
            symbol* attributeSymbol = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

            if(attributeSymbol == nullptr){
                yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
            }else{
                // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                
                attributeSymbol = tableSymbol->getFirstSymbolMatching2(attributeSymbol->lexema + ":" + accesos[0], "atributo", scope);
                if (attributeSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                }else{
                    // checkeamos que los tipos sean iguales 
                    checkTypesAsignation(attributeSymbol->type, op2Type); 

                    // agregamos el terceto de asignación en la respectiva tabla de tercetos
                    int number = addTercet("=", attributeSymbol->lexema, op2Lexeme);
                    
                    reglaptr = charTercetoId + to_string(number);
                    reglatype = attributeSymbol->type;
                }
            }
        }
    }
};

void newUseObjectAttributeFactorMasMas(string objectName, string attributeName, string scope, string& reglaptr, string& reglatype){

    vector<string> accesos = getAccesoFromString(objectName);
    
    tableSymbol->deleteSymbol(accesos[0]);
    tableSymbol->deleteSymbol(attributeName);

    // Verifica que el objeto este declarado y obtiene su clase
    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
    symbol* classSymbol = nullptr;
    string classOfObject;
    if(objectSymbol == nullptr){
            yyerror("No se encontro declaracion previa del objeto"+ objectName);
    }else{
        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
        classOfObject = objectSymbol->classOfSymbol;
        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
        if(classSymbol == nullptr){
            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
        }else{
            // si el objeto fue pospuesto por forwarding entonces el checkeo del uso se pospone también
            if(objectSymbol->posponeForForwarding){
                int number = addTercetPospone("++", attributeName+":"+classOfObject+":"+objectName+"|"+scope, "", true, false, "pospone", ""); 
                number = addTercetPospone("=", attributeName+":"+classOfObject+":"+objectName+"|"+scope, charTercetoId + to_string(number), true, false,"pospone",""); 
                reglaptr = attributeName+":"+classOfObject+":"+objectName+"|"+scope;
                reglatype = "pospone";
                return;
            }
            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
            for(int i = 1; i < accesos.size(); i++){
                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                if(objectSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                    return;
                }else{
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                        return;
                    }else{
                        tableSymbol->deleteSymbol(accesos[i]);
                        if(objectSymbol->posponeForForwarding){
                            int number = addTercetPospone("++", attributeName+":"+classOfObject+":"+objectName+"|"+scope, "", true, false, "pospone", ""); 
                            number = addTercetPospone("=", attributeName+":"+classOfObject+":"+objectName+"|"+scope, charTercetoId + to_string(number), true, false,"pospone",""); 
                            reglaptr = attributeName+":"+classOfObject+":"+objectName+"|"+scope;
                            reglatype = "pospone";
                            return;
                        }
                    }
                }
            }

            // si encontramos la clase verificamos que contenga el atributo     
            symbol* attributeSymbol = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

            if(attributeSymbol == nullptr){
                yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
            }else{
                // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                
                attributeSymbol = tableSymbol->getFirstSymbolMatching2(attributeSymbol->lexema + ":" + accesos[0], "atributo", scope);
                if (attributeSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                }else{
                    string value = "";
                    if(attributeSymbol->type == "unsigned int"){
                        value = "1_ui";
                    }else if(attributeSymbol->type == "short"){
                        value = "1_s";
                    }else if(attributeSymbol->type == "float"){
                        value = "1.0";
                    }
                    int number = addTercet("+", attributeSymbol->lexema, value);   
                    number = addTercet("=", attributeSymbol->lexema, charTercetoId + to_string(number));           
                
                    reglaptr = attributeSymbol->lexema;
                    reglatype = attributeSymbol->type;
                }
            }
        }
    }
};
/**
 * Esta función se llama cuando se detecta una invocación a función sin parámetro.
 * Borramos el símbolo de la tabla general, verificamos si estamos dentro de una declaración de clase o en el main.
 * En base a eso usamos la respectiva tabla de símbolos para buscar el primer símbolo de función.
 * Verificamos que esa función no tenga parámetros, sino tiramos un error de que falta pasar un parámetro.
 * Generamos el terceto de call a esa función.
 * 
 * @param nombreFuncion El nombre de la función a invocar.
 * @param scope El alcance de la función.
 * @param reglaptr Puntero a la regla generada.
 */
void newInvocacion(string nombreFuncion, string scope, string& reglaptr){
    // borramos el simbolo de la tabla general
    tableSymbol->deleteSymbol(nombreFuncion); 
        
    //buscamos si existe una variable con el mismo nombre al alcance de la tabla de simbolos
    symbol* functionFinded = tableSymbol->getFirstSymbolMatching2(nombreFuncion, "funcion", scope); 
    if(functionFinded == nullptr){
        yyerror("No se encontro declaracion previa de la funcion "+ nombreFuncion);
    }else{
        // verificamos que la función no tenga parametros
        if(functionFinded->cantParam != 0){
            yyerror(" Se esta llamando a la funcion "+ nombreFuncion + " sin pasarle un parametro, el parametro debe ser de tipo " + functionFinded->typeParam);
        }

        // agregamos el terceto de asignación en la respectiva tabla de tercetos
        int number = addTercet("call", functionFinded->lexema, "");

        reglaptr = charTercetoId + to_string(number);
        } 
};
/**
 * Esta función se llama cuando se detecta una invocación a función con parámetro.
 * Borramos el símbolo de la tabla general, verificamos si estamos dentro de una declaración de clase o en el main.
 * En base a eso usamos la respectiva tabla de símbolos para buscar el primer símbolo de función.
 * Verificamos que esa función tenga parámetros, sino tiramos un error de que estamos llamando a una función que no requiere de parametros.
 * verificamos que los tipos de los parametros coincidan
 * generamos el terceto de pasaje de parameros
 * Generamos el terceto de call a esa función.
 * 
 * @param nombreFuncion El nombre de la función a invocar.
 * @param scope El alcance de la función.
 * @param reglaptr Puntero a la regla generada.
 */
void newInvocacionWithParam(string nombreFuncion, string scope, string ptrParam, string typeParam, string& reglaptr){

    // borramos el simbolo de la tabla general
    tableSymbol->deleteSymbol(nombreFuncion); 
        
    //buscamos si existe una variable con el mismo nombre al alcance de la tabla de simbolos
    symbol* functionFinded = tableSymbol->getFirstSymbolMatching2(nombreFuncion, "funcion", scope); 
    if(functionFinded == nullptr){
        yyerror("No se encontro declaracion previa de la funcion "+ nombreFuncion);
    }else{
        // verificamos que la función no tenga parametros
        if(functionFinded->cantParam == 0){
            yyerror(" Se esta llamando a la funcion "+ nombreFuncion + " con parametro y la funcion no recibe parametro");
        }else{
            // esto va acá dentro para que no tire dos errores si no recibe paramatro la función
            // verificamos que los tipos de los parametros sean ifuales
            checkTypesParams(functionFinded->typeParam, typeParam); 
        }
            
        /*
            NO SE PORQUE PERO PRESIENTO QUE VA A SERVIR
        */

        // creamos un terceto de pasaje de parametro con su ptr y su tipo
        int number = addTercet("paramReal", ptrParam, typeParam);
        number = addTercet("paramFormal", functionFinded->nameParam, functionFinded->typeParam);

        // agregamos el terceto de asignación en la respectiva tabla de tercetos
        number = addTercet("call", functionFinded->lexema, "");

        reglaptr = charTercetoId + to_string(number);
        } 
};
/**
 * Esta función busca el símbolo de un metoddo que tenga el mismo nombre que el parámetro en el símbolo del a clase, si no está busca en sus herencias.
 * si encuentra el símbololo lo devuelve y sino devuelve nullptr
 *
 * @param key La clave del método a buscar.
 * @param classSymbol La tabla de símbolos de la clase actual en la que buscar.
 * @return puntero al simbolo del atributo encontrado o nullptr sino lo encuentra
 */
symbol* getFirstSymbolMatchingOfMethod(string attributeName, symbol* classSymbol){
    
    // obtenemos el simbolo que tenga el mismo nombre (solo mira la primer parte del nombre) y el mismo uso
    symbol* symbolAttribute = classSymbol->attributesAndMethodsVector->getElementInTableByFisrtPartAndUse(attributeName, "metodo");
    if(symbolAttribute != nullptr){
        // si encontramos el atributo en la tabla de símbolos de la clase actual devolvemos el símbolo
        return symbolAttribute;
    }else{
        // si no encontramos símbolo en la tabla principal dela clase buscamos en sus herencias de derecha a izquierda ya que si hay sobre escritura buscamos la más reciente
        for (int i=1; i >= 0; i--){
            if(classSymbol->inheritance[i]!=nullptr){
                
                // obtener el símbolo de la clase que hereda
                symbolAttribute = classSymbol->inheritance[i]->getElementInTableByFisrtPartAndUse(attributeName, "metodo");
                if(symbolAttribute != nullptr){
                    return symbolAttribute;
                }
            }
        }
        return nullptr;
    }           
}
void newInvocacionMethod(string objectName, string methodName, string scope, string& reglaptr){
    /*
        Esta funciónse llama cuando se detecta quese quiere invocar un método sin parametro de un objeto
        Verifica que el objeto esté declarado y obtiene su clase.
        Verificar que la clase exista
        Verificar que la clase contenga el método
        Obtener sumando el scope estático del método + nombre objeto + scope actual el lexema del símbolo propio del objeto.
        verificar que el metodo no reciba atributos, sino informarlo
        generar el terceto de call a ese método

    */

    vector<string> accesos = getAccesoFromString(objectName);
    
    tableSymbol->deleteSymbol(accesos[0]);
    tableSymbol->deleteSymbol(methodName);
    
    // Verifica que el objeto este declarado y obtiene su clase
    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
    symbol* classSymbol = nullptr;
    string classOfObject;
    if(objectSymbol == nullptr){
            yyerror("No se encontro declaracion previa del objeto"+ objectName);
    }else{
        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
        classOfObject = objectSymbol->classOfSymbol;
        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
        if(classSymbol == nullptr){
            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
        }else{
            // si el objeto fue pospuesto por forwarding entonces el checkeo del uso se pospone también
            if(objectSymbol->posponeForForwarding){
                /// agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                int number = addTercetPospone("call", methodName+":"+classOfObject+":"+objectName+"|"+scope, "", true, false,"pospone","");

                reglaptr = charTercetoId + to_string(number);
                return;
            }
            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
            for(int i = 1; i < accesos.size(); i++){
                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                if(objectSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                    return;
                }else{
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                        return;
                    }else{
                        tableSymbol->deleteSymbol(accesos[i]);
                        if(objectSymbol->posponeForForwarding){
                            // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                            int number = addTercetPospone("call", methodName+":"+classOfObject+":"+objectName+"|"+scope, "", true, false,"pospone","");

                            reglaptr = charTercetoId + to_string(number);
                            return;
                        }
                    }
                }
            }


            // si encontramos la clase verificamos que contenga el metodo    
            symbol* methodSymbol = getFirstSymbolMatchingOfMethod(methodName, classSymbol);

            if(methodSymbol == nullptr){
                yyerror("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
            }else{
                // encontramos el metodo en la clase y obtenemos el scope estático del metodo, 
                // buscamos en la tabla general el scope estático + el nombre del objeto + el scope actual y obtenemos el simbolo del primer metodo que coincida
                
                methodSymbol = tableSymbol->getFirstSymbolMatching2(methodSymbol->lexema + ":" + accesos[0], "metodo", scope);
                if (methodSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                }else{
                    // verificamos que el metodo no tenga parametros
                    if(methodSymbol->cantParam != 0){
                        yyerror("Se esta llamando al metodo "+ methodName + " del objeto " + accesos[0] + " sin pasarle un parametro, el parametro debe ser de tipo " + methodSymbol->typeParam);
                    }
                    // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos
                    int number = addTercet("call", methodSymbol->lexema, "");

                    reglaptr = charTercetoId + to_string(number);
                }
            }
        }
    }

};

void newInvocacionMethodWithParam(string objectName, string methodName, string scope, string ptrParam, string typeParam, string& reglaptr){
    /*
        Esta funciónse llama cuando se detecta quese quiere invocar un método con parametro de un objeto 
        Verifica que el objeto esté declarado y obtiene su clase.
        Verificar que la clase exista
        Verificar que la clase contenga el método
        Obtener sumando el scope estático del método + nombre objeto + scope actual el lexema del símbolo propio del objeto.
        verificar que el metodo no reciba atributos, sino informarlo
        generar el terceto de call a ese método

    */

    vector<string> accesos = getAccesoFromString(objectName);
    
    tableSymbol->deleteSymbol(accesos[0]);
    tableSymbol->deleteSymbol(methodName);
   
    // Verifica que el objeto este declarado y obtiene su clase
    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
    symbol* classSymbol = nullptr;
    string classOfObject;
    if(objectSymbol == nullptr){
            yyerror("No se encontro declaracion previa del objeto"+ objectName);
    }else{
        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
        classOfObject = objectSymbol->classOfSymbol;
        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
        if(classSymbol == nullptr){
            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
        }else{
            // si el objeto fue pospuesto por forwarding entonces el checkeo del uso se pospone también
            if(objectSymbol->posponeForForwarding){
                // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                // como tiene un parametro se lo ponemoscomo segundo argumetno para suposterior uso
                // creamos un terceto de pasaje de parametro con su ptr y su tipo
                int number = addTercet("paramReal", ptrParam, typeParam);
                number = addTercet("paramFormal", "", "");
                number = addTercetPospone("call", methodName+":"+classOfObject+":"+objectName+"|"+scope, typeParam+":"+ptrParam, true, false,"pospone","");

                reglaptr = charTercetoId + to_string(number);
                return;
            }
            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
            for(int i = 1; i < accesos.size(); i++){
                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                if(objectSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                    return;
                }else{
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                        return;
                    }else{
                        tableSymbol->deleteSymbol(accesos[i]);
                        if(objectSymbol->posponeForForwarding){
                        // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos pero indicando que el símbolo está pospuesto
                        // como tiene un parametro se lo ponemoscomo segundo argumetno para suposterior uso
                        // creamos un terceto de pasaje de parametro con su ptr y su tipo
                        int number = addTercet("paramReal", ptrParam, typeParam);
                        number = addTercet("paramFormal", "", "");
                        number = addTercetPospone("call", methodName+":"+classOfObject+":"+objectName+"|"+scope, typeParam+":"+ptrParam, true, false,"pospone","");

                        reglaptr = charTercetoId + to_string(number);
                        return;
                        }
                    }
                }
            }
            

            // si encontramos la clase verificamos que contenga el metodo    
            symbol* methodSymbol = getFirstSymbolMatchingOfMethod(methodName, classSymbol);
            /*
                Esta función debe buscar en la tabla de la clase si existe elmétodo y sino buscarlo en las clases heredadas
                devuelve el puntero a ese metodo
            */

            if(methodSymbol == nullptr){
                yyerror("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
            }else{
                // encontramos el metodo en la clase y obtenemos el scope estático del metodo, 
                // buscamos en la tabla general el scope estático + el nombre del objeto + el scope actual y obtenemos el simbolo del primer metodo que coincida
                
                methodSymbol = tableSymbol->getFirstSymbolMatching2(methodSymbol->lexema + ":" + accesos[0], "metodo", scope);
                if (methodSymbol == nullptr){
                    yyerror("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                }else{
                    // verificamos que el metodo tenga parametros
                    if(methodSymbol->cantParam == 0){
                        yyerror("Se esta llamando al metodo "+ methodName + " con parametro y la funcion no recibe parametro");
                    }else{
                        // esto va acá dentro para que no tire dos errores si no recibe paramatro la función
                        // verificamos que los tipos de los parametros sean iguales
                        checkTypesParams(methodSymbol->typeParam, typeParam); 
                    }
                        
                    /*
                        NO SE PORQUE PERO PRESIENTO QUE VA A SERVIR
                    */

                    // creamos un terceto de pasaje de parametro con su ptr y su tipo
                    int number = addTercet("paramReal", ptrParam, typeParam);
                    number = addTercet("paramFormal", methodSymbol->nameParam, methodSymbol->typeParam);

                    // agregamos el terceto la llamada al metodo en la respectiva tabla de tercetos
                    number = addTercet("call", methodSymbol->lexema, "");

                    reglaptr = charTercetoId + to_string(number);
                }
            }
        }
    }
};
void printIdentificador(string _lexema, string _scope){
    // queres imprimir una variable, 
    // la borramos de la tabla general
    // la buscamos en la tabla de símbolos de la clase actual

    tableSymbol->deleteSymbol(_lexema);         // eliminamos el simbolo de la tabla general

    // obtenemos el símbolo de la clase del objeto
    symbol* identificador = tableSymbol->getFirstSymbolMatching2(_lexema, "var", _scope); 

    if (identificador == nullptr){
        yyerror("No se encontro declaracion previa de la variable "+ _lexema);
    }else{
        // agregamos el terceto de asignación en la respectiva tabla de tercetos
        int number = addTercet("printIdentificador", identificador->lexema, "");
    }
}; 
void addTercetReturn(string& reglaptr){
        int number = addTercet("return","","");        

        reglaptr = charTercetoId + to_string(number);
};
void addObjectToClass(string objectName, string scope, string className, string classActual){
    // Obtememos el simbolo viejo de la clase y el objeto y los borramos
    // buscamos si existe la clase de este objeto, sino lanzamos ese error
    // buscamos si existe la clase en donde queremos poner el objeto sino no hacemos nada
    // agregamos el objeto a la clase

    tableSymbol->deleteSymbol(objectName);         // eliminamos el simbolo de la tabla general
    tableSymbol->deleteSymbol(className);

    // operamos sobre la tabla de símbolos de la clase
    TableSymbol * tsClass = stackClasses->top()->attributesAndMethodsVector;

    // verificamos a que distancia se encuentra la primer aparición del atributo en un ámbito alcanzable
    int diff = tsClass->getDiffOffScope2(objectName, "objeto", scope); 
            
    if(diff == 0){
            yyerror("Redeclaracion de objeto en la misma clase");
    }else{
            // creamos el nuevo símbolo para el atributo
            symbol* newAttribute = new symbol(objectName+scope, "", "", "objeto");
            /*
                    ACA SE PUEDEN AGREGAR COSAS A LOS SIMBOLOS DE ATRIBUTOS CARGADOS
            */

            // Marcamos a la clase que pertenece el atributo
            newAttribute->classOfSymbol = className;

            // agregamos el nuevo símbolo al vector de simbolos de la clase        
            tsClass->insert(newAttribute);
    }        
}
void accessObjects(string _accesosEfectuados, string _nuevoAcceso, string& _reglaptr){
    _reglaptr = _accesosEfectuados + ":" + _nuevoAcceso;
    accesosEfectuados = _accesosEfectuados + ":" + _nuevoAcceso;
};
void accessObject(string _nuevoAcceso, string& _reglaptr){
    _reglaptr = _nuevoAcceso;
    accesosEfectuados = _nuevoAcceso;
};
void verifyAllClassForwardedAreDeclared(){
        // esta función se encarga de recorrer la tabla de símbolo y por cada clase verifica que no este forwardeada

        // recorremos la tabla de símbolos
        for(const auto& pair : tableSymbol->getSymbolTable()){
                symbol* sm = pair.second;
                // verificamos que sea una clase
                if(sm->uso == "clase"){
                        // verificamos que no este forwardeada
                        if(sm->forwarded){
                                yyerror("La clase " + sm->lexema + " esta forwardeada y no se completó su declaración");
                        }
                }
        }
};
void instanciatePosponeObjectForForwarding(){
        // esta función se encarga de recorrer la tabla de símbolo y por cada objeto que tenga posponeForForwarding en true, 
        // agrega sus atributos y métodos a la tabla de símbolos general y setea posponeForForwarding en false

        // recorremos la tabla de símbolos
        for(const auto& pair : tableSymbol->getSymbolTable()){
                symbol* sm = pair.second;
                // verificamos que sea una clase
                if(sm->uso == "objeto"){
                        // verificamos que no este forwardeada
                        if(sm->posponeForForwarding){
                                // agregamos los atributos y métodos a la tabla de símbolos general
                                symbol* symbolClass = tableSymbol->getFirstSymbolMatching2(sm->classOfSymbol, "clase", ":main");
                                addObjectForwarded(sm, symbolClass);
                        }
                }
        } 
};
void checkTercetsPosponeAreCorrect(Tercets* ts){
    // recorrer los tercetos del main y buscamos que terceto tiene algún pospone activado
    // sabemos que si es un call es a un étodo del primer argumento y debemos verificar que exista y setear correctamente el argumento (por el scope)
    // si es una operación aritmétca es una tributo de clase y debemos ver cual de los argumetnos está pospuesto, buscar ese atributo y checkear tipos
    int numberTercet = -1;
    for (Tercet* tercet : ts->getTercets()){
        numberTercet++;
        // tercet->print();

        if(tercet->getOp() == "call"){
            if(tercet->arg1Pospone ){
                // es un llamado a método
                
                // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                size_t posSeparador = tercet->getArg1().find("|");
                string primeraParte = tercet->getArg1().substr(0, posSeparador);
                string scope = tercet->getArg1().substr(posSeparador + 1);

                size_t firstPos = primeraParte.find(":");
                size_t secondPos = primeraParte.find(":", firstPos + 1);

                string methodName = primeraParte.substr(0, firstPos);
                string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                string objectName = primeraParte.substr(secondPos+1, primeraParte.size());
                
                vector<string> accesos = getAccesoFromString(objectName);
   
                // Verifica que el objeto este declarado y obtiene su clase
                symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                symbol* classSymbol = nullptr;
                if(objectSymbol == nullptr){
                        yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                }else{
                    // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                    }else{
                        
                        // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                        for(int i = 1; i < accesos.size(); i++){
                            objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                            if(objectSymbol == nullptr){
                                yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                return;
                            }else{
                                tableSymbol->deleteSymbol(accesos[i]);
                                classOfObject = objectSymbol->classOfSymbol;
                                classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                if(classSymbol == nullptr){
                                    // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                    yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                    return;
                                }
                            }
                        }



                        // si encontramos la clase verificamos que contenga el metodo    
                        symbol* methodSymbol = getFirstSymbolMatchingOfMethod(methodName, classSymbol);
                        if(methodSymbol == nullptr){
                            yyerrorFin("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
                        }else{
                            // encontramos el metodo en la clase y obtenemos el scope estático del metodo, 
                            // buscamos en la tabla general el scope estático + el nombre del objeto + el scope actual y obtenemos el simbolo del primer metodo que coincida
                
                            methodSymbol = tableSymbol->getFirstSymbolMatching2(methodSymbol->lexema + ":" + accesos[0], "metodo", scope);
                            if (methodSymbol == nullptr){
                                yyerrorFin("No se encontro declaracion previa del metodo "+ methodName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                            }else{
                            // verificamos que el metodo tenga parametros
                                if(tercet->getArg2() != ""){
                                    // el método tiene parametros
                                    string typeParam = tercet->getArg2().substr(0, tercet->getArg2().find(":"));
                                    string ptrParam = tercet->getArg2().substr(tercet->getArg2().find(":")+1, tercet->getArg2().size());
                                    if(methodSymbol->cantParam == 0){
                                        yyerrorFin("Se esta llamando al metodo "+ methodName + " con parametro y el metodo no recibe parametro");
                                    }else{
                                        // esto va acá dentro para que no tire dos errores si no recibe paramatro la función
                                        // verificamos que los tipos de los parametros sean iguales
                                        checkTypesParamsFin(methodSymbol->typeParam, typeParam); 
                                    }

                                    // reemplazamos los tercetos existentes de los parametros por los correctos
                                    Tercet *t1 = new Tercet("paramReal", ptrParam, typeParam); 
                                    Tercet *t2 = new Tercet("paramFormal", methodSymbol->nameParam, methodSymbol->typeParam); 
                                    ts->replace(numberTercet-2, t1);
                                    ts->replace(numberTercet-1, t2);

                                }else{
                                    // el método no tiene parametros
                                    if(methodSymbol->cantParam != 0){
                                        yyerrorFin("Se esta llamando al metodo "+ methodName + " sin parametro y el metodo recibe parametro");
                                    }
                                }
                                Tercet *tcall = new Tercet("call", methodSymbol->lexema, "");
                                ts->replace(numberTercet, tcall);
                            }
                        }
                    }
                }
            }
            
        }
        if(tercet->getOp() == "tof"){
            // estamos ante una operación de tof
            // verificamos que el atributo del segundo argumento exista y atualzamos el terceto
            symbol* attributeSymbol2;
            bool isErrorInAttribute = false;
            if (tercet->arg2Pospone){
                if(tercet->getArg2()[0] == charTercetoId){
                    // si e sun terceto guardamos su tipo en el terceto actual
                    tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                }else{
                    // es un llamado a método
                    // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                    size_t posSeparador = tercet->getArg2().find("|");
                    string primeraParte = tercet->getArg2().substr(0, posSeparador);
                    string scope = tercet->getArg2().substr(posSeparador + 1);

                    size_t firstPos = primeraParte.find(":");
                    size_t secondPos = primeraParte.find(":", firstPos + 1);

                    string attributeName = primeraParte.substr(0, firstPos);
                    string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                    string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                    vector<string> accesos = getAccesoFromString(objectName);
    
                    // Verifica que el objeto este declarado y obtiene su clase
                    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                    symbol* classSymbol = nullptr;
            
                    if(objectSymbol == nullptr){
                            yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                            isErrorInAttribute = true;
                    }else{
                        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                        classOfObject = objectSymbol->classOfSymbol;
                        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                        if(classSymbol == nullptr){
                            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                            isErrorInAttribute = true;
                        }else{
                            
                            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                            for(int i = 1; i < accesos.size(); i++){
                                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                                if(objectSymbol == nullptr){
                                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    tableSymbol->deleteSymbol(accesos[i]);
                                    classOfObject = objectSymbol->classOfSymbol;
                                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                    if(classSymbol == nullptr){
                                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                            if(!isErrorInAttribute){
                                // si encontramos la clase verificamos que contenga el atributo     
                                attributeSymbol2 = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                                if(attributeSymbol2 == nullptr){
                                    yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                    isErrorInAttribute = true;
                                }else{
                                    // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                                    // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                                    
                                    attributeSymbol2 = tableSymbol->getFirstSymbolMatching2(attributeSymbol2->lexema + ":" + accesos[0], "atributo", scope);
                                    if (attributeSymbol2 == nullptr){
                                        yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!isErrorInAttribute){
                if (!tercet->arg1Pospone && tercet->arg2Pospone){
                    if(tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = "float";
                    }else{
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        Tercet * tasig = ts->get(numberTercet);
                        tasig->setArg2(attributeSymbol2->lexema);
                        tasig->type2 = attributeSymbol2->type;
                        tasig->arg2Pospone = false;
                        tasig->typeTercet = "float";
                    }
                }
            }
        }
        if(tercet->getOp() == "++"){
            // estamos ante una operación de ++
            // verificamos que el atributo exista y atualzamosel terceto
            if(tercet->arg1Pospone ){
                // es un llamado a método
                
                // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                size_t posSeparador = tercet->getArg1().find("|");
                string primeraParte = tercet->getArg1().substr(0, posSeparador);
                string scope = tercet->getArg1().substr(posSeparador + 1);

                size_t firstPos = primeraParte.find(":");
                size_t secondPos = primeraParte.find(":", firstPos + 1);

                string attributeName = primeraParte.substr(0, firstPos);
                string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                
                vector<string> accesos = getAccesoFromString(objectName);
   
                // Verifica que el objeto este declarado y obtiene su clase
                symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                symbol* classSymbol = nullptr;
        
                if(objectSymbol == nullptr){
                        yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                }else{
                    // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                    classOfObject = objectSymbol->classOfSymbol;
                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                    if(classSymbol == nullptr){
                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                    }else{
                        
                        // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                        for(int i = 1; i < accesos.size(); i++){
                            objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                            if(objectSymbol == nullptr){
                                yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                return;
                            }else{
                                tableSymbol->deleteSymbol(accesos[i]);
                                classOfObject = objectSymbol->classOfSymbol;
                                classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                if(classSymbol == nullptr){
                                    // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                    yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                    return;
                                }
                            }
                        }

                        // si encontramos la clase verificamos que contenga el atributo     
                        symbol* attributeSymbol = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                        if(attributeSymbol == nullptr){
                            yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
                        }else{
                            // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                            // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                            
                            attributeSymbol = tableSymbol->getFirstSymbolMatching2(attributeSymbol->lexema + ":" + accesos[0], "atributo", scope);
                            if (attributeSymbol == nullptr){
                                yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                            }else{
                                string value = "";
                                if(attributeSymbol->type == "unsigned int"){
                                    value = "1_ui";
                                }else if(attributeSymbol->type == "short"){
                                    value = "1_s";
                                }else if(attributeSymbol->type == "float"){
                                    value = "1.0";
                                }
                                Tercet *tcall = new Tercet("+", attributeSymbol->lexema, value);
                                tcall->typeTercet = attributeSymbol->type; // le seteamos el tipo al terceto para luego poder operar con estos
                                tcall->type1 = attributeSymbol->type;
                                tcall->type2 = attributeSymbol->type;
                                ts->replace(numberTercet, tcall);

                            }
                        }
                    }
                }
            }
        }   
        if(tercet->getOp() == "="){
            // detectamos una asignación
            // verificamos que alguno de los dos argumentos sea pospone
            symbol* attributeSymbol1;
            symbol* attributeSymbol2;
            bool isErrorInAttribute = false;
            if ( tercet->arg1Pospone){
                if(tercet->getArg1()[0] == charTercetoId){
                    tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                }else{
                    // es un llamado a método
                    // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                    size_t posSeparador = tercet->getArg1().find("|");
                    string primeraParte = tercet->getArg1().substr(0, posSeparador);
                    string scope = tercet->getArg1().substr(posSeparador + 1);

                    size_t firstPos = primeraParte.find(":");
                    size_t secondPos = primeraParte.find(":", firstPos + 1);

                    string attributeName = primeraParte.substr(0, firstPos);
                    string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                    string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                    
                    vector<string> accesos = getAccesoFromString(objectName);
    
                    // Verifica que el objeto este declarado y obtiene su clase
                    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                    symbol* classSymbol = nullptr;
            
                    if(objectSymbol == nullptr){
                            yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                            isErrorInAttribute = true;
                    }else{
                        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                        classOfObject = objectSymbol->classOfSymbol;
                        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                        if(classSymbol == nullptr){
                            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                            isErrorInAttribute = true;
                        }else{
                            
                            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                            for(int i = 1; i < accesos.size(); i++){
                                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                                if(objectSymbol == nullptr){
                                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    tableSymbol->deleteSymbol(accesos[i]);
                                    classOfObject = objectSymbol->classOfSymbol;
                                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                    if(classSymbol == nullptr){
                                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                            if(!isErrorInAttribute){
                                // si encontramos la clase verificamos que contenga el atributo     
                                attributeSymbol1 = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                                if(attributeSymbol1 == nullptr){
                                    yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                                    // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                                    
                                    attributeSymbol1 = tableSymbol->getFirstSymbolMatching2(attributeSymbol1->lexema + ":" + accesos[0], "atributo", scope);
                                    if (attributeSymbol1 == nullptr){
                                        yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ( tercet->arg2Pospone){
                if(tercet->getArg2()[0] == charTercetoId){
                    tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                }else{
                    // es un llamado a método
                    // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                    size_t posSeparador = tercet->getArg2().find("|");
                    string primeraParte = tercet->getArg2().substr(0, posSeparador);
                    string scope = tercet->getArg2().substr(posSeparador + 1);

                    size_t firstPos = primeraParte.find(":");
                    size_t secondPos = primeraParte.find(":", firstPos + 1);

                    string attributeName = primeraParte.substr(0, firstPos);
                    string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                    string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                    vector<string> accesos = getAccesoFromString(objectName);
    
                    // Verifica que el objeto este declarado y obtiene su clase
                    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                    symbol* classSymbol = nullptr;
            
                    if(objectSymbol == nullptr){
                            yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                            isErrorInAttribute = true;
                    }else{
                        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                        classOfObject = objectSymbol->classOfSymbol;
                        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                        if(classSymbol == nullptr){
                            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                            isErrorInAttribute = true;
                        }else{
                            
                            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                            for(int i = 1; i < accesos.size(); i++){
                                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                                if(objectSymbol == nullptr){
                                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    tableSymbol->deleteSymbol(accesos[i]);
                                    classOfObject = objectSymbol->classOfSymbol;
                                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                    if(classSymbol == nullptr){
                                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                            if(!isErrorInAttribute){
                                // si encontramos la clase verificamos que contenga el atributo     
                                attributeSymbol2 = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                                if(attributeSymbol2 == nullptr){
                                    yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                                    // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                                    
                                    attributeSymbol2 = tableSymbol->getFirstSymbolMatching2(attributeSymbol2->lexema + ":" + accesos[0], "atributo", scope);
                                    if (attributeSymbol2 == nullptr){
                                        yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!isErrorInAttribute){
                if (tercet->arg1Pospone && !tercet->arg2Pospone){
                    // checkeamos que los tipos sean iguales 
                    if(tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                    }
                    checkTypesAsignationFin(attributeSymbol1->type, tercet->type2); 
                    // agregamos el terceto de asignación en la respectiva tabla de tercetos
                    tercet->setArg1(attributeSymbol1->lexema);
                    tercet->type1 = attributeSymbol1->type;
                    tercet->arg1Pospone = false;
                }
                if (!tercet->arg1Pospone && tercet->arg2Pospone){
                    if(tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg1()[0] == charTercetoId){
                            tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(tercet->type1, tercet->type2);
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = tercet->type2;
                    }else{
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg1()[0] == charTercetoId){
                            tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(tercet->type1, attributeSymbol2->type); 

                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        tercet->setArg2(attributeSymbol2->lexema);
                        tercet->type2 = attributeSymbol2->type;
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = attributeSymbol2->type;
                    }
                }
                if (tercet->arg1Pospone && tercet->arg2Pospone){
                    if(tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        // checkeamos que los tipos sean iguales 
                        checkTypesAsignationFin(attributeSymbol1->type, tercet->type2); 
                        
                        tercet->setArg1(attributeSymbol1->lexema);
                        tercet->type1 = attributeSymbol1->type;
                        tercet->arg1Pospone = false;
                        tercet->arg2Pospone = false;

                    }else{
                        // checkeamos que los tipos sean iguales 
                        checkTypesAsignationFin(attributeSymbol1->type, attributeSymbol2->type);
                        tercet->setArg1(attributeSymbol1->lexema);
                        tercet->setArg2(attributeSymbol2->lexema);
                        tercet->type1 = attributeSymbol1->type;
                        tercet->type2 = attributeSymbol2->type;
                        tercet->arg1Pospone = false;
                        tercet->arg2Pospone = false;
                    }
                }
            }
                
        }
        if(tercet->getOp() == "+" || tercet->getOp() == "-" || tercet->getOp() == "*" || tercet->getOp() == "/"){
            // encontramos un terceto de operación
            // verificamos que alguno de los dos argumentos sea pospone
            symbol* attributeSymbol1;
            symbol* attributeSymbol2;
            bool isErrorInAttribute = false;
            if ( tercet->arg1Pospone){
                if(tercet->getArg1()[0] == charTercetoId){
                    tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                }else{
                    // es un llamado a método
                    // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                    size_t posSeparador = tercet->getArg1().find("|");
                    string primeraParte = tercet->getArg1().substr(0, posSeparador);
                    string scope = tercet->getArg1().substr(posSeparador + 1);

                    size_t firstPos = primeraParte.find(":");
                    size_t secondPos = primeraParte.find(":", firstPos + 1);

                    string attributeName = primeraParte.substr(0, firstPos);
                    string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                    string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                    
                    vector<string> accesos = getAccesoFromString(objectName);
    
                    // Verifica que el objeto este declarado y obtiene su clase
                    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                    symbol* classSymbol = nullptr;
            
                    if(objectSymbol == nullptr){
                            yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                            isErrorInAttribute = true;
                    }else{
                        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                        classOfObject = objectSymbol->classOfSymbol;
                        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                        if(classSymbol == nullptr){
                            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                            isErrorInAttribute = true;
                        }else{
                            
                            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                            for(int i = 1; i < accesos.size(); i++){
                                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                                if(objectSymbol == nullptr){
                                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    tableSymbol->deleteSymbol(accesos[i]);
                                    classOfObject = objectSymbol->classOfSymbol;
                                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                    if(classSymbol == nullptr){
                                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                            if(!isErrorInAttribute){
                                // si encontramos la clase verificamos que contenga el atributo     
                                attributeSymbol1 = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                                if(attributeSymbol1 == nullptr){
                                    yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                                    // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                                    
                                    attributeSymbol1 = tableSymbol->getFirstSymbolMatching2(attributeSymbol1->lexema + ":" + accesos[0], "atributo", scope);
                                    if (attributeSymbol1 == nullptr){
                                        yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if ( tercet->arg2Pospone){
                if(tercet->getArg2()[0] == charTercetoId){
                    tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                }else{
                    // es un llamado a método
                    // obtenemos cada uno de los elementos del argumento para verificar si es correcto el uso del objeto
                    size_t posSeparador = tercet->getArg2().find("|");
                    string primeraParte = tercet->getArg2().substr(0, posSeparador);
                    string scope = tercet->getArg2().substr(posSeparador + 1);

                    size_t firstPos = primeraParte.find(":");
                    size_t secondPos = primeraParte.find(":", firstPos + 1);

                    string attributeName = primeraParte.substr(0, firstPos);
                    string classOfObject = primeraParte.substr(firstPos+1, secondPos - firstPos - 1);
                    string objectName = primeraParte.substr(secondPos+1, primeraParte.size());

                    vector<string> accesos = getAccesoFromString(objectName);
    
                    // Verifica que el objeto este declarado y obtiene su clase
                    symbol* objectSymbol = tableSymbol->getFirstSymbolMatching2(accesos[0], "objeto", scope);
                    symbol* classSymbol = nullptr;
            
                    if(objectSymbol == nullptr){
                            yyerror("No se encontro declaracion previa del objeto"+ accesos[0]);
                            isErrorInAttribute = true;
                    }else{
                        // si encontramos el objeto declarado obtenemos su clase y verificamos que exista la clase en el scope ":main" ya que todas las clases van ahí
                        classOfObject = objectSymbol->classOfSymbol;
                        classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                        if(classSymbol == nullptr){
                            // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                            yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                            isErrorInAttribute = true;
                        }else{
                            
                            // ya encontraste el primer objeto en u ámbito alcanzable, ahora buscamos dentro de su clase cada uno de los diferentes acccesos
                            for(int i = 1; i < accesos.size(); i++){
                                objectSymbol = getFirstSymbolMatchingOfObject(accesos[i], classSymbol);
                                if(objectSymbol == nullptr){
                                    yyerror("No se encontro declaracion previa del objeto "+ accesos[i] + " en la clase " + classSymbol->classOfSymbol + " del objeto " + accesos[i-1]); 
                                    isErrorInAttribute = true;
                                }else{
                                    tableSymbol->deleteSymbol(accesos[i]);
                                    classOfObject = objectSymbol->classOfSymbol;
                                    classSymbol = tableSymbol->getFirstSymbolMatching2(classOfObject, "clase", ":main");
                                    if(classSymbol == nullptr){
                                        // nunca debería entrar acá porque si el objeto existe es porque la clase también existe
                                        yyerror("No se encontro declaracion previa de la clase del objeto "+ classOfObject); 
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                            if(!isErrorInAttribute){
                                // si encontramos la clase verificamos que contenga el atributo     
                                attributeSymbol2 = getFirstSymbolMatchingOfAttribute(attributeName, classSymbol);

                                if(attributeSymbol2 == nullptr){
                                    yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                    isErrorInAttribute = true;
                                }else{
                                    // encontramos el atributo en la clase y obtenemos el scope estático del atributo, 
                                    // buscamos en la tabla general el scope estático + le nombre del objeto + el scope actual y obtenemos el simbolo del primer atributo que coincida
                                    
                                    attributeSymbol2 = tableSymbol->getFirstSymbolMatching2(attributeSymbol2->lexema + ":" + accesos[0], "atributo", scope);
                                    if (attributeSymbol2 == nullptr){
                                        yyerrorFin("No se encontro declaracion previa del atributo "+ attributeName + " en la clase " + classOfObject + " del objeto " + accesos[accesos.size()-1]);
                                        isErrorInAttribute = true;
                                    }
                                }
                            }
                        }
                    }
                }
            }
            if (!isErrorInAttribute){
                if (tercet->arg1Pospone && !tercet->arg2Pospone){
                    if(tercet->getArg1()[0] == charTercetoId){
                        tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg2()[0] == charTercetoId){
                            tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(tercet->type1, tercet->type2);
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        tercet->arg1Pospone = false;
                        tercet->typeTercet = tercet->type1;
                    }else{
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg2()[0] == charTercetoId){
                            tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(attributeSymbol1->type, tercet->type2); 
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        Tercet * tasig = ts->get(numberTercet);
                        tasig->setArg1(attributeSymbol1->lexema);
                        tasig->type1 = attributeSymbol1->type;
                        tasig->arg1Pospone = false;
                        tasig->typeTercet = attributeSymbol1->type;
                    }   
                }
                if (!tercet->arg1Pospone && tercet->arg2Pospone){
                    if(tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg1()[0] == charTercetoId){
                            tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(tercet->type1, tercet->type2);
                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = tercet->type2;
                    }else{
                        // checkeamos que los tipos sean iguales 
                        if(tercet->getArg1()[0] == charTercetoId){
                            tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        }
                        checkTypesAsignationFin(tercet->type1, attributeSymbol2->type); 

                        // agregamos el terceto de asignación en la respectiva tabla de tercetos
                        Tercet * tasig = ts->get(numberTercet);
                        tasig->setArg2(attributeSymbol2->lexema);
                        tasig->type2 = attributeSymbol2->type;
                        tasig->arg2Pospone = false;
                        tasig->typeTercet = attributeSymbol2->type;
                    }
                }
                if (tercet->arg1Pospone && tercet->arg2Pospone){
                    if(tercet->getArg1()[0] == charTercetoId && tercet->getArg2()[0] != charTercetoId){
                        tercet->type1 = ts->get(stoi(tercet->getArg1().substr(1, tercet->getArg1().size())))->typeTercet;
                        checkTypesAsignationFin(tercet->type1, attributeSymbol2->type); 
                        tercet->setArg2(attributeSymbol2->lexema);
                        tercet->type2 = attributeSymbol2->type;
                        tercet->arg1Pospone = false;
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = attributeSymbol2->type;
                    }
                    if(tercet->getArg1()[0] != charTercetoId && tercet->getArg2()[0] == charTercetoId){
                        tercet->type2 = ts->get(stoi(tercet->getArg2().substr(1, tercet->getArg2().size())))->typeTercet;
                        checkTypesAsignationFin(attributeSymbol1->type, tercet->type2); 
                        tercet->setArg1(attributeSymbol1->lexema);
                        tercet->type1 = attributeSymbol1->type;
                        tercet->arg1Pospone = false;
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = attributeSymbol1->type;
                    }
                    if(tercet->getArg1()[0] != charTercetoId && tercet->getArg2()[0] != charTercetoId){
                        
                        checkTypesAsignationFin(attributeSymbol1->type, attributeSymbol2->type); 
                        tercet->setArg1(attributeSymbol1->lexema);
                        tercet->setArg2(attributeSymbol2->lexema);
                        tercet->type1 = attributeSymbol1->type;
                        tercet->type2 = attributeSymbol2->type;
                        tercet->arg1Pospone = false;
                        tercet->arg2Pospone = false;
                        tercet->typeTercet = attributeSymbol1->type;
                    }
                }
            }
        }
        
    }
};
void finPrograma(){
        int number = addTercet("FIN", "-", "-");
        verifyAllClassForwardedAreDeclared();
        instanciatePosponeObjectForForwarding();
        tableSymbol->imprimirTabla();
        checkTercetsPosponeAreCorrect(tableTercets);
        tableSymbol->imprimirTabla();
        for(functionStack* fs : *(vectorOfFunction->getFunctions())){
            checkTercetsPosponeAreCorrect(fs->ter);
        }
}