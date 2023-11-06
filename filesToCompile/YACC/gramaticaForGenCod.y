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

VectorOfFunction * vectorOfFunction = new VectorOfFunction();
stack<functionStack*>* stackFunction = new stack<functionStack*>();
int cantOfRecursions = 0;

int lineNumber = 1;
bool isErrorInCode = false;
Tercets *tableTercets = new Tercets();
char charTercetoId = '%';

string typeAux = "";
string actualClass = "";
symbol* lastParam;
symbol* lastClass;

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

programa    :   '{' sentencias '}'              { int number = addTercet("FIN", "-", "-"); }
            |   '{' comas sentencias '}'        { int number = addTercet("FIN", "-", "-"); }     
            |   '{' comas '}'                   { int number = addTercet("FIN", "-", "-"); }      
            |   '{' '}'                         { yywarning("Se esta compilando un programa sin contenido"); }
            |   '{'                             { yywarning("Se esta compilando un programa sin contenido y falta la ultima llave"); }
            |   '}'                             { yywarning("Se esta compilando un programa sin contenido y falta la primer llave"); }
            |   '{' sentencias '}' error        { yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   '{' '}' error                   { yywarning("Se esta compilando un programa sin contenido"); yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   sentencias                      { yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' sentencias                  { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   sentencias '}'                  { yywarning("Se detecto la falta de la primera llave del programa"); }
            |   comas                           { yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' comas                       { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   comas '}'                       { yywarning("Se detecto la falta de la primera llave del programa"); }
            |   '{' comas sentencias            { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |    comas sentencias '}'           { yywarning("Se detecto la falta de la primera llave del programa"); }
            |    comas sentencias               { yywarning("Se detecto la falta de llaves en el programa"); }
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

declarativa :   tipo lista_de_variables                                             { yyPrintInLine("Se detecto declaracion de variable");}
            |   declaracion_clase                                                    
            |   declaracion_objeto                                                  { yyPrintInLine("Se detecto declaracion de objeto");}
            |   declaracion_funcion                                                 { yyPrintInLine("Se detecto declaracion de funcion");}
            ;

declaracion_funcion     :       funcion_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'             { finishFunction();  }
                        |       VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'                     { yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       funcion_name '(' parametro ')' '{' '}'                                  { finishFunction(); yywarning("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        
                        |       funcion_name '(' parametro ')' '{' comas cuerpo_de_la_funcion '}'             { finishFunction();}
                        |       VOID '(' parametro ')' '{' comas cuerpo_de_la_funcion '}'                     { yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       funcion_name '(' parametro ')' '{' comas '}'                                  { finishFunction(); yywarning("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        ;

funcion_name    :       VOID IDENTIFICADOR              { initFunction($2->ptr, tableSymbol->getScope()); }
                ;

declaracion_clase   :   nombre_clase '{' lista_atributos_y_metodos '}'   { tableSymbol->deleteScope(); }
                    |   nombre_clase '{' '}'                             { tableSymbol->deleteScope(); yywarning("Se detecto una declaracion de clases vacia");}
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { int diff = tableSymbol->getDiffOffScope($2->ptr+tableSymbol->getScope(), "clase"); if(diff == 0){yyerror("Redeclaracion de funcion en el mismo ambito");}else{symbol* newIdentificador = setNewScope($2->ptr, "", tableSymbol->getScope(), "clase"); } tableSymbol->getSymbol($2->ptr+tableSymbol->getScope())->forwarded = true; }
                    |   CLASS '{' lista_atributos_y_metodos '}'                 { yyerror("Falta nombre de la clase"); }
                    |   CLASS  '{' '}'                                          { yyerror("Falta nombre de la clase"); }
                    ;
                    
nombre_clase    :       CLASS IDENTIFICADOR                     { initClass($2->ptr, tableSymbol->getScope()); $$->ptr = $2->ptr; tableSymbol->addScope($2->ptr);}
                ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_atributos ','           { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       lista_atributos_y_metodos metodo ','                                 
                                |       tipo lista_de_atributos ','                                    { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       metodo ','
                                ;
lista_de_atributos  :   lista_de_atributos ';' IDENTIFICADOR    { addAtribute($3->ptr, tableSymbol->getScope(), typeAux); }
                    |   IDENTIFICADOR                           { addAtribute($1->ptr, tableSymbol->getScope(), typeAux); }
                    ;
metodo  :   metodo_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'                 { finishMethod(); }
        |   metodo_name '(' parametro ')' '{' '}'                                      { finishMethod(); yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
        |   metodo_name '(' parametro ')' '{' comas cuerpo_de_la_funcion '}'           { finishMethod(); }
        ;

metodo_name     :       VOID IDENTIFICADOR              { initMethod($2->ptr, tableSymbol->getScope()); }
                |       VOID                            { yyerror("Falta de nombre de metodo"); }
                ;

declaracion_objeto  :   typeClass lista_de_objetos   {} 
                    ;
typeClass : IDENTIFICADOR                       { $$->ptr = $1->ptr; actualClass = $1->ptr; tableSymbol->deleteSymbol($1->ptr);}
          ;

lista_de_objetos    :   lista_de_objetos ';' IDENTIFICADOR      { addObject($3->ptr, tableSymbol->getScope(), actualClass); }
                    |   IDENTIFICADOR                           { addObject($1->ptr, tableSymbol->getScope(), actualClass); }
                    ;

tipo    :       SHORT   { typeAux = "short"; $$->type ="short";}
        |       UINT    { typeAux = "unsigned int"; $$->type = "unsigned int";}
        |       FLOAT   { typeAux = "float"; $$->type = "float";}
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR    { int diff = tableSymbol->getDiffOffScope($3->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaracion de variable en el mismo ambito");}else{symbol* newIdentificador = setNewScope($3->ptr, typeAux, tableSymbol->getScope(),"var");} }
                    |   IDENTIFICADOR                           { int diff = tableSymbol->getDiffOffScope($1->ptr+tableSymbol->getScope(), "var"); if(diff == 0){yyerror("Redeclaracion de variable en el mismo ambito");}else{symbol* newIdentificador = setNewScope($1->ptr, typeAux, tableSymbol->getScope(),"var");} }
                    ;

parametro   :   tipo IDENTIFICADOR              { addParam($2->ptr, tableSymbol->getScope(), $1->type); $$->type = $1->type;}
            |   tipo                            { yyerror("Falta de nombre de parametro"); }            
            |   IDENTIFICADOR                   { yyerror("Falta de tipo de parametro"); } 
            |   /* vacio */
            |   parametro ';' tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
            ;

cuerpo_de_la_funcion    :   cuerpo_de_la_funcion_sin_return                             {yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        |   cuerpo_de_la_funcion_con_return
                        ;
cuerpo_de_la_funcion_con_return    :   cuerpo_de_la_funcion_sin_return RETURN ','
                                   |   cuerpo_de_la_funcion_sin_return RETURN                                           { yywarning("Se detecto una falta de coma"); }
                                   |   cuerpo_de_la_funcion_sin_return RETURN ',' cuerpo_de_la_funcion_sin_return       { yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return RETURN cuerpo_de_la_funcion_sin_return           { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return RETURN ',' cuerpo_de_la_funcion_con_return       { yywarning("Se detecto codigo posterior a un return"); }
                                   |   cuerpo_de_la_funcion_sin_return RETURN cuerpo_de_la_funcion_con_return           { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   RETURN ','
                                   |   RETURN                                           {yywarning("Se detecto una falta de coma"); }        
                                   |   RETURN ',' cuerpo_de_la_funcion_sin_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   |   RETURN cuerpo_de_la_funcion_sin_return       { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   |   RETURN ',' cuerpo_de_la_funcion_con_return       {yywarning("Se detecto codigo posterior a un return"); }
                                   |   RETURN cuerpo_de_la_funcion_con_return       { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                                   ;
cuerpo_de_la_funcion_sin_return    :   cuerpo_de_la_funcion_sin_return sentencia 
                                   |   sentencia
                                   ;
ejecutable  :    asignacion
            |    invocacion                                 
            |    seleccion
            |    PRINT CADENA_CARACTERES                    { int number = addTercet("print", tableSymbol->getSymbol($2->ptr)->value, ""); $$->ptr = charTercetoId + to_string(number); }
            |    PRINT IDENTIFICADOR                        { yyPrintInLine("Se detecto una impresion de identificador"); }
            |    PRINT constanteConSigno                    { yyPrintInLine("Se detecto una impresion de constante"); }
            |    PRINT constanteSinSigno                    { yyPrintInLine("Se detecto una impresion de constante"); }
            |    ciclo_while
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica                     { newAsignacion($1->ptr, tableSymbol->getScope(), $3->ptr,$3->type);}
           | IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '(' ')' 
           | IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '.' IDENTIFICADOR '(' ')'                           
           ;


expresion_aritmetica : expresion_aritmetica '+' termino         { newOperacionAritmetica("+", $1->ptr, $3->ptr, $1->type, $3->ptr, $$->ptr, $$->type); }
                    | expresion_aritmetica '-' termino          { newOperacionAritmetica("-", $1->ptr, $3->ptr, $1->type, $3->ptr, $$->ptr, $$->type); }
                    | expresion_aritmetica '-' '*' termino      { newOperacionAritmetica("-", $1->ptr, $4->ptr, $1->type, $4->ptr, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '-'"); }
                    | expresion_aritmetica '+' '*' termino      { newOperacionAritmetica("+", $1->ptr, $4->ptr, $1->type, $4->ptr, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '+'"); }
                    | expresion_aritmetica '-' '/' termino      { newOperacionAritmetica("-", $1->ptr, $4->ptr, $1->type, $4->ptr, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '-'"); }
                    | expresion_aritmetica '+' '/' termino      { newOperacionAritmetica("+", $1->ptr, $4->ptr, $1->type, $4->ptr, $$->ptr, $$->type); yywarning("Se detecto un error en operador, quedara '+'"); }
                    | termino                                   { $$->type = $1->type; $$->ptr = $1->ptr; }
                    ;

termino : termino '*' factor                                    { newOperacionAritmetica("*", $1->ptr, $3->ptr, $1->type, $3->ptr, $$->ptr, $$->type); }
        | termino '/' factor                                    { newOperacionAritmetica("/", $1->ptr, $3->ptr, $1->type, $3->ptr, $$->ptr, $$->type); }
        | factor                                                { $$->ptr = $1->ptr; $$->type = $1->type;}
        ;

seleccion : IF bloque_condicion cuerpo_if                       { Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}}                     
          ;

bloque_condicion : '(' condicion ')'                            { int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number); }
                 | '(' condicion                                { yywarning("Falta de ultimo parentesis en condicion"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number);}
                 |  condicion ')'                               { yywarning("Falta de primer parentesis en condicion"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number);}
                 |  condicion                                   { yywarning("Falta de parantesis en condicion"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number);}
                 |  '(' ')'                                     { yyerror("Falta de condicion en el bloque de control IF"); int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number);}
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
else_if :       ELSE                                            { Tercet * t = popTercet();  if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2));} int number =  addTercetAndStack("BI", "", ""); $$->ptr = charTercetoId + to_string(number); }
        ;
ciclo_while : inicio_while bloque_condicion DO cuerpo_while               { Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet(); int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} $$->ptr = charTercetoId + to_string(number);}                     
            | inicio_while bloque_condicion cuerpo_while                  { yywarning("Falta de DO en WHILE-DO"); Tercet *t = popTercet(); if (t!=nullptr){t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );} Tercet *t2 = popTercet();int number; if(t2!=nullptr){int number = addTercet("BI", t2->getArg1(), "");} $$->ptr = charTercetoId + to_string(number);}                     
            ;

inicio_while    : WHILE                                                         { addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); }
                ;

cuerpo_while : bloque_ejecutables                                       
            ;   

condicion : expresion_aritmetica '>' expresion_aritmetica                       { checkTypesCompare($1->type, $3->type); int number = addTercet(">", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica '<' expresion_aritmetica                       { checkTypesCompare($1->type, $3->type); int number = addTercet("<", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); int number = addTercet("==", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica       { checkTypesCompare($1->type, $3->type); int number = addTercet("!!", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); int number = addTercet(">=", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); int number = addTercet("<=", $1->ptr, $3->ptr); $$->ptr = charTercetoId + to_string(number); }
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   '{' sentencias_ejecutables RETURN ',' '}'        
                    |   '{' sentencias_ejecutables RETURN ',' sentencias_ejecutables '}'        { yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' sentencias_ejecutables RETURN sentencias_ejecutables '}'            { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' sentencias_ejecutables RETURN '}'                                   { yywarning("Se detecto una falta de coma"); }
                    |   ejecutable ',' 
                    |   declarativa  ','                                                        { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   '{' RETURN ',' '}'
                    |   '{' RETURN '}'                                                          { yywarning("Se detecto una falta de coma"); }
                    |    RETURN ','
                    
                    |   '{' sentencias_ejecutables RETURN ',' comas '}'        
                    |   '{' sentencias_ejecutables RETURN ',' comas sentencias_ejecutables '}'        { yywarning("Se detecto codigo posterior a un return"); }


                    |   '{' comas sentencias_ejecutables '}'      
                    |   '{' comas sentencias_ejecutables RETURN ',' '}'              
                    |   '{' comas sentencias_ejecutables RETURN ',' sentencias_ejecutables '}'  { yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' comas sentencias_ejecutables RETURN sentencias_ejecutables '}'      { yywarning("Se detecto una falta de coma"); yywarning("Se detecto codigo posterior a un return"); }
                    |   '{' comas sentencias_ejecutables RETURN '}'                             { yywarning("Se detecto una falta de coma"); }
                    |   comas ejecutable ',' 
                    |   comas declarativa  ','                                                  { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   '{' comas RETURN ',' '}'
                    |   '{' comas RETURN '}'                                                    { yywarning("Se detecto una falta de coma"); }
                    |    comas RETURN ','
                    |   error ','                                                               { yyerror("Se detecto un bloque invalido"); }
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

factor : IDENTIFICADOR                                                  { $$->ptr = $1->ptr; $$->type = tableSymbol->getSymbol($1->ptr)->type;}
       | IDENTIFICADOR OPERADOR_SUMA_SUMA                               { int number = addTercet("+", $1->ptr, $1->ptr); $$->ptr = charTercetoId + to_string(number); $$->type = tableSymbol->getSymbol($1->ptr)->type;}
       | constanteSinSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | constanteConSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | TOF '(' expresion_aritmetica ')'                               { int number = addTercet("tof", " ", $3->ptr); $$->ptr = charTercetoId + to_string(number); $$->type = "float"; } 
       | IDENTIFICADOR '.' IDENTIFICADOR 
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
// Esta funcion dado el acceso a un elemento de la tabla de simbolos elimina el simbolo y lo actualiza con el scope y el tipo de esa variable.
symbol* setNewScope(string key, string type, string scope, string uso){
        
        symbol* identificador = tableSymbol->getSymbol(key);    // obtenemos el simbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el simbolo
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

        tableSymbol->insert(newIdentificador);                          // insertamos el nuevo simbolo
        return newIdentificador;
}
// Crea un terceto y lo agrega a la tabla de tercetos.
// Los paramtros son argumento, operador1, y operador2
int addTercet(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
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

void initClass(string key, string scope){
        // verificamos a que distancia se encuentra la primer aparición de la variable en un ámbito alcanzable
        int diff = tableSymbol->getDiffOffScope(key+scope, "clase"); 
        
        // si está en el mismo ámbito
        if(diff == 0){
                // en el mismo ámbito existe una clase, verificar si es forward declaration
                symbol* symbolFinded = tableSymbol->getSymbol(key+scope); // obtenemos el símbolo con mismo scope
                if(symbolFinded->forwarded == false){
                        yyerror("Redeclaracion de clase " + key + " en el mismo ambito");
                }else{
                        // la marcamos como que ya se declaró
                        symbolFinded->forwarded = false;
                        symbolFinded->attributesAndMethodsVector = new vector<symbol*>; // inicializamos el vector de simbolos
                        lastClass = symbolFinded;
                }
        }else{
                symbol* newIdentificador = setNewScope(key, "", scope, "clase"); 
                newIdentificador->attributesAndMethodsVector = new vector<symbol*>; // inicializamos el vector de simbolos
                lastClass = newIdentificador;
        } 
        actualClass = key; 
};
void addAtribute(string key, string scope, string type){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        int diff = tableSymbol->getDiffOffScope(key + scope, "atributo"); 
        if(diff == 0){
                yyerror("Redeclaracion de atributio en la misma clase");
        }else{
                tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
                
                // creamos el nuevo símbolo para el atributo
                symbol* newAtribute = new symbol(key+scope, "", type, "atributo");

                // agregamos el nuevo símbolo al vector de simbolos de la clase        
                lastClass->attributesAndMethodsVector->push_back(newAtribute);

                // seteamos que si se debe agregar un parametro se le haga a este método
                lastParam = newAtribute;
        }        
};
void initMethod(string key, string scope ){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        // creamos el nuevo símbolo
        symbol* newMetodo = new symbol(key+scope, "", "void", "metodo");

        // agregamos el nuevo símbolo al vector de simbolos de la clase        
        lastClass->attributesAndMethodsVector->push_back(newMetodo);
        
        // seteamos que si se debe agregar un parametro se le haga a este método
        lastParam = newMetodo;

        // agregamos un scope
        tableSymbol->addScope(key);

        // creamos una stack para la función y la agregamos al stack con el nombre
        functionStack* fs = new functionStack(key+scope);
        fs->ter = new Tercets();
        stackFunction->push(fs);
        cantOfRecursions++;
};
void addParam(string key, string scope, string type){

        // obtener el símbolo viejo y eliminarlo
        // setear el tipo del parametro

        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        lastParam->cantParam++;
        lastParam->typeParam = type;
        lastParam->nameParam = key;
};
void addObject(string key, string scope, string classType){
        
        // Verificamos que no exista otro objeto con el mismo nombre en el mismo ámbito
        // buscamos la clase más cercana de classType
        // si la encontramos por cada atributo y método creamos un nuevo símbolo con el scope del objeto

        
        
        int diff = tableSymbol->getDiffOffScope(key+scope, "objeto"); 
        
        // si está en el mismo ámbito
        if(diff == 0){
                // en el mismo ámbito existe un objeto
                yyerror("Redeclaracion del objeto " + key + " en el mismo ambito");
        }else{
                tableSymbol->deleteSymbol(key); // borramos elobjeto de la tabla de simbolos
                
                symbol* matchingClass = tableSymbol->getFirstSymbolMatching(classType+scope, "clase"); // buscamos la primera clase que matchee
                
                for (symbol * sm : *matchingClass->attributesAndMethodsVector){
                        // creamos el nuevo símbolo
                        symbol* newSm = new symbol(*sm);
                        newSm->lexema = key+":"+sm->lexema;

                        // agregamos el nuevo símbolo a la tabla de simbolos        
                        tableSymbol->insert(newSm);
                }
        } 
};
void initFunction(string key, string scope){
        int diff = tableSymbol->getDiffOffScope(key+scope, "funcion"); 
        if(diff == 0){
                yyerror("Redeclaracion de funcion en el mismo ambito");
        }else{
                symbol* newIdentificador = setNewScope(key, "void", scope, "funcion"); 
                lastParam = newIdentificador;
        } 
        
        tableSymbol->addScope(key);

        // creamos un vector de función y lo agregamos al stack con el nombre
        functionStack* fs = new functionStack(key+scope);
        fs->ter = new Tercets();
        stackFunction->push(fs);
        cantOfRecursions++;
}
void finishFunction(){
        // obtenemos el stack con los tercetos de la función
        functionStack* fs = stackFunction->top();
        stackFunction->pop();
        vectorOfFunction->add(fs);
        tableSymbol->deleteScope(); // sacamos el scope de la función
        cantOfRecursions--;     // sacamos una recursión
}
void finishMethod(){
        // obtenemos el stack con los tercetos de la función
        functionStack* fs = stackFunction->top();
        stackFunction->pop();
        vectorOfFunction->add(fs);
        tableSymbol->deleteScope(); // sacamos el scope de la función
        cantOfRecursions--;     // sacamos una recursión
};

void newAsignacion(string key, string scope, string op2Lexeme, string op2Type){
        tableSymbol->deleteSymbol(key); 
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(key+scope, "var"); 
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la variable "+ key);
        }else{
                checkTypesAsignation(symbolFinded->type, op2Type); 
                int number = addTercet("=", symbolFinded->lexema, op2Lexeme); 
        } 
};

void newOperacionAritmetica(string operador, string op1ptr, string op2ptr, string op1type, string op2type, string& reglaptr, string& reglatype){
        if(checkTypesOperation(op1type, op2type)){
                reglatype = op1type;
        }else{
                reglatype = "error";
        } 
        
        int number = addTercet(operador, op1ptr, op2ptr); 
        reglaptr = charTercetoId + to_string(number); 
}