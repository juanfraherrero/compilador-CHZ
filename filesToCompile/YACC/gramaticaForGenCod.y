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
symbol* lastMethod;
stack<symbol*>*  stackClasses = new stack<symbol*>();

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
                    |   nombre_clase '{' lista_atributos_y_metodos clase_heredada'}'   { finishClass(); }
                    |   nombre_clase '{' clase_heredada '}'                     { finishClass(); }
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { forwardClass($2->ptr, tableSymbol->getScope());}
                    |   CLASS '{' lista_atributos_y_metodos '}'                 { yyerror("Falta nombre de la clase"); }
                    |   CLASS  '{' '}'                                          { yyerror("Falta nombre de la clase"); }
                    ;
clase_heredada  :       IDENTIFICADOR ','                                       { detectInheritance($1->ptr, tableSymbol->getScope(), actualClass); }
                |       IDENTIFICADOR                                           { detectInheritance($1->ptr, tableSymbol->getScope(), actualClass); yywarning("Se detecto una falta de coma"); }                    
                ;
nombre_clase    :       CLASS IDENTIFICADOR                     { initClass($2->ptr, tableSymbol->getScope(), $$->ptr); }
                ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_atributos ','           { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       lista_atributos_y_metodos metodo ','                                 
                                |       tipo lista_de_atributos ','                                    { yyPrintInLine("Se detecto declaracion de variable en clase");}
                                |       metodo ','
                                ;
lista_de_atributos  :   lista_de_atributos ';' IDENTIFICADOR    { addAtribute($3->ptr, tableSymbol->getScope(), typeAux, actualClass); }
                    |   IDENTIFICADOR                           { addAtribute($1->ptr, tableSymbol->getScope(), typeAux, actualClass); }
                    ;
metodo  :   metodo_name '(' parametro_metodo ')' '{' cuerpo_de_la_funcion '}'                 { finishMethod(); }
        |   metodo_name '(' parametro_metodo ')' '{' '}'                                      { finishMethod(); yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
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
parametro_metodo   :   tipo IDENTIFICADOR               { addParamMetodo($2->ptr, tableSymbol->getScope(), $1->type); $$->type = $1->type;}
            |   tipo                                    { yyerror("Falta de nombre de parametro"); }            
            |   IDENTIFICADOR                           { yyerror("Falta de tipo de parametro"); } 
            |   /* vacio */
            |   parametro_metodo ';' tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
            ;

parametro_funcion   :   tipo IDENTIFICADOR              { addParamFunction ($2->ptr, tableSymbol->getScope(), $1->type, $$->ptr, $$->type); }
                |   tipo                            { yyerror("Falta de nombre de parametro"); }            
                |   IDENTIFICADOR                   { yyerror("Falta de tipo de parametro"); } 
                |   /* vacio */
                |   parametro_funcion ';' tipo IDENTIFICADOR  { yyerror("Exceso de parametros"); }
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

factor : IDENTIFICADOR                                                  { checkVarInScope($1->ptr, tableSymbol->getScope(), $$->ptr, $$->type); }
       | IDENTIFICADOR OPERADOR_SUMA_SUMA                               { newFactorMasMas($1->ptr, tableSymbol->getScope(), $$->ptr, $$->type); }
       | constanteSinSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | constanteConSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | TOF '(' expresion_aritmetica ')'                               { newTof($3->ptr,$$->ptr,$$->type); } 
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
// Carga el símbolo en la tabla
// Dado el acceso a un elemento de la tabla de simbolos lo elimina
// Actualiza el símbolocon los datos pasados, 
// si no se quiere modificar los datos dejar ""
// key, type, scope, uso, Tabla a la que agregarle
symbol* setNewScope(string key, string type, string scope, string uso, string object, string scopeInsideClass, string classOfSymbol, TableSymbol* ts){
        
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
        if(object != ""){
                newIdentificador->object = object;                            // actualizamos el objeto al que pertenece
        }
        if(scopeInsideClass != ""){
                newIdentificador->scopeInsideClass = scopeInsideClass;                            // actualizamos el scope dentro de la clase
        }
        if(classOfSymbol != ""){
                newIdentificador->classOfSymbol = classOfSymbol;                            // actualizamos la clase a la que pertenece
        }

        // insrtamos en la nueva tabla de símbolos
        ts->insert(newIdentificador);                          // insertamos el nuevo simbolo en la tabla
        
        // retornamos el puntero al simbolo
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

void initClass(string key, string scope, string & reglaptr){
        // verificamos a que distancia se encuentra la primer aparición de la variable en un ámbito alcanzable
        int diff = tableSymbol->getDiffOffScope(key+scope, "clase", scope); 
        
        // si está en el mismo ámbito
        if(diff == 0){
                // en el mismo ámbito existe una clase, verificar si es forward declaration
                symbol* symbolFinded = tableSymbol->getSymbol(key+scope); // obtenemos el símbolo con mismo scope
                if(symbolFinded->forwarded == false){
                        yyerror("Redeclaracion de clase " + key + " en el mismo ambito");
                }else{
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
void finishClass(){
        tableSymbol->deleteScope();
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
// cuando detectamos un atributo de clase
// la función obtiene el símbolo viejo lo elimina y lo carga a la tabla de la clase
void addAtribute(string key, string scope, string type, string classOfAttribute){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        // buscamos a cuanta distancia se encuuentra la primera aparición de un atributo con el mismo nombre y de la misma clase
        int diff = tableSymbol->getDiffOffScopeForClass(key, "atributo", scope, classOfAttribute); 
        if(diff == 0){
                yyerror("Redeclaracion de atributio en la misma clase");
        }else{
                // creamos el nuevo símbolo para el atributo
                symbol* newAttribute = new symbol(key, "", type, "atributo");
                newAttribute->classOfSymbol = classOfAttribute;

                // obtenemos el scope posterior a la aparción del nombre de la clase
                //  scope = "x:main:func3:cs:metod1"; y la clase es cs
                // buscamos :metod1
                string scopeInsideClass = scope.substr(scope.find(classOfAttribute) + cs.length());
                newAttribute->scopeInsideClass = scopeInsideClass; // scope inside class puede ser un acadena vacía
                
                newAttribute->object = "";

                // agregamos el nuevo símbolo al vector de simbolos de la clase        
                stackClasses->top()->attributesAndMethodsVector->insert(newAttribute);

                /* // seteamos que si se debe agregar un parametro se le haga a este método
                lastMethod = newAtribute; */
        }        
};

/**
 * cuando detectamos un método de clase
 * se elimina el símbolo viejo de la tabla
 * se carga el nuevo símbolo a la tabla de la clase
 * 
 * @param key nombre del acceso
 * @param scope scope actual
 * @param classOfAttribute nombre de la clase a la que pertenece
 */
void initMethod(string key, string scope, string classOfAttribute ){

        // obtener el símbolo viejo y eliminarlo
        // cargarlo al arreglo de la clase

        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        // buscamos a cuanta distancia se encuentra la primera aparición de un metodo con el mismo nombre y de la misma clase
        int diff = tableSymbol->getDiffOffScopeForClass(key, "metodo", scope, classOfAttribute); 
        if(diff == 0){
                yyerror("Redeclaracion de metodo en la misma clase");
        }else{
                // creamos el nuevo símbolo
                symbol* newMetodo = new symbol(key, "", "void", "metodo");

                newMetodo->classOfSymbol = classOfAttribute;
                newMetodo->object = "";
                // obtenemos el scopeInsideClass
                string scopeInsideClass = scope.substr(scope.find(classOfAttribute) + classOfAttribute.length());
                newMetodo->scopeInsideClass = scopeInsideClass; // scope inside class puede ser un acadena vacía
                

                // agregamos el nuevo símbolo al vector de simbolos de la clase        
                stackClasses->top()->attributesAndMethodsVector->insert(newMetodo);
                
                // seteamos que si se debe agregar un parametro se le haga a este método
                lastMethod = newMetodo;

                // agregamos un scope
                tableSymbol->addScope(key);

                // creamos una stack para la función y la agregamos al stack con el nombre
                functionStack* fs = new functionStack(key+scope);
                fs->ter = new Tercets();
                stackFunction->push(fs);
                
                cantOfRecursions++;
        }
};
/**
 * cuando detectamos un parámtro de un método de clase
 * se elimina el símbolo viejo de la tabla
 * se carga el nuevo símbolo a la tabla de la clase, es una variable y se le agrega a su scope el nombre del método
 * 
 * @param key nombre del acceso
 * @param scope scope actual
 * @param classOfAttribute nombre de la clase a la que pertenece
*/
void addParamMetodo(string key, string scope, string type, string classOfAttribute){

        // obtener el símbolo viejo y eliminarlo
        // verificar que no esté previamente en ese scope en esa tabla de símobolo
        // lo agregamos y setear el tipo del parametro


        tableSymbol->deleteSymbol(key);                         // eliminamos el simbolo (usa el contador)
        
        // verificamos a que distancia se encuentra la primer aparición de la variable en un ámbito alcanzable
        int diff = stackClasses->top()->attributesAndMethodsVector->getDiffOffScopeForClass(key, "var", scope, classOfAttribute); 
        if(diff == 0){
                yyerror("Redeclaracion de variable en el misma ambito");
        }else{
                // creamos el nuevo símbolo para el parámtero,
                // La key es su nombre, y, como es un atributo de un metodo, le agregamos el nombre del método como scope
                symbol* newparam = new symbol(key+":"+lastMethod->key, "", type, "var");
                newparam->classOfSymbol = classOfAttribute;
                newparam->object = "";

                // obtenemos el scopeInsideClass, que al ser un parámetro de un método siempre es el mismo método
                newparam->scopeInsideClass = ":"+lastMethod->key; 
                

                // agregamos el nuevo símbolo al vector de simbolos de la clase        
                stackClasses->top()->attributesAndMethodsVector->insert(newparam);

                lastMethod->cantParam++;
                lastMethod->typeParam = type;
                lastMethod->nameParam = key;
        }
};
/**
 * cuando detectamos un parámtro de una declaración de función
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
        // verificamos si está dentro de la declaración de una clase o no

        // obtener el símbolo viejo y eliminarlo
        // setear el tipo del parametro

        TableSymbol* ts;
        symbol* newIdentificador = nullptr;
        // determinas que tabla de símbolo usas
        if(stackClasses->size() <= 0){
                ts = tableSymbol;
                newIdentificador = setNewScope(key, type, scope, "var", ts); 
                newIdentificador->object = "main";
        }else{
                ts = stackClasses->top()->attributesAndMethodsVector;
                // como la función está dentro de una clase debemos de definir el scope como el inside scope
                // y los atributos
                string classOfAttribute = stackClasses->top()->classOfSymbol;
                scope = scope.substr(scope.find(classOfAttribute) + classOfAttribute.length());
                newIdentificador = setNewScope(key, type, scope, "var", ts); 
                newIdentificador->classOfSymbol = classOfAttribute;
                newIdentificador->object = "";
                newIdentificador->scopeInsideClass = scope;
        }

        reglaptr = newIdentificador->lexema; 
        reglatype = type; 
};
void addObject(string key, string scope, string classType){
        
        // Verificamos que no exista otro objeto con el mismo nombre en el mismo ámbito
        // buscamos la clase más cercana de classType
        // si la encontramos por cada atributo y método creamos un nuevo símbolo con el scope del objeto
        if (classType == "_error"){
                return;
        }
        int diff = tableSymbol->getDiffOffScope2(key, "objeto", scope); 
        // si está en el mismo ámbito
        if(diff == 0){
                // en el mismo ámbito existe un objeto
                yyerror("Redeclaracion del objeto " + key + " en el mismo ambito");
        }else{
                // eliminamos el símbolo viejo y lo agregamos
                symbol* newObject = setNewScope(key, "", scope, "objeto", tableSymbol);
                symbol* matchingClass = tableSymbol->getFirstSymbolMatching2(classType, "clase", scope); // buscamos la primera clase que matchee 

                for (const auto& par : matchingClass->attributesAndMethodsVector->getSymbolTable()){
                        symbol* sm = par.second;
                        // creamos el nuevo símbolo
                        symbol* newSm = new symbol(*sm);                
                        size_t firstColonPos = sm->lexema.find(':');
                        string name = sm->lexema.substr(0, firstColonPos);
                        firstColonPos = sm->lexema.find(classType);
                        string scopeInsideClass = sm->lexema.substr(firstColonPos, sm->lexema.size());
                        cout<< "\nname: " << name << " scope: " << scope << " scopeInside " << scopeInsideClass  <<  " calssType " << classType << " sm->lexema " << sm->lexema  << endl;
                        newSm->lexema = name+scope+":"+scopeInsideClass+":"+key;

                        // agregamos el nuevo símbolo a la tabla de simbolos        
                        tableSymbol->insert(newSm);
                }
        } 
};
/**
 * cuando detectamos una declaracion de función
 * eliminamos el símbolo viejo de la tabla
 * verificamos si es dentro de una clase o fuera
 * si está afuera de una clase lo agregamos a la tabla general
 * si está dentro de una clase lo agregamos a la tabla de la clase con el scope inside class
 * 
 * @param key nombre del acceso
 * @param scope scope actual
*/
void initFunction(string key, string scope){
        TableSymbol* ts;
        string scopeOriginal = scope
        string clase = "";
        // determinas que tabla de símbolo usas
        if(stackClasses->size() <= 0){
                ts = tableSymbol;
        }else{
                ts = stackClasses->top()->attributesAndMethodsVector;
                clase = stackClasses->top()->classOfSymbol;
                scope = scope.substr(scope.find(clase) + clase.length()); // obtenemos el scope inside class
        }

        int diff = tableSymbol->getDiffOffScope2(key, "funcion", scope, clase); 
        if(diff == 0){
                yyerror("Redeclaracion de funcion en el mismo ambito");
        }else{
                symbol* newIdentificador = setNewScope(key, "void", scope, "funcion", ts); 
                lastMethod = newIdentificador;
                if(class!=""){
                        newIdentificador->classOfSymbol = clase;
                        newIdentificador->scopeInsideClass = scope;
                        newIdentificador->object = "";
                }
        } 
        
        tableSymbol->addScope(key);

        // creamos un vector de función y lo agregamos al stack con el nombre
        functionStack* fs = new functionStack(key+scopeOriginal); 
        fs->ter = new Tercets();
        stackFunction->push(fs);
        cantOfRecursions++;
}
/**
 * cuando detectamos el fin de una declaracion de función
 * guardamos el bloque de tercetos de la función
 * sacamos el scope de la función
*/
void finishFunction(){
        // obtenemos el stack con los tercetos de la función
        functionStack* fs = stackFunction->top();
        stackFunction->pop();
        vectorOfFunction->add(fs);
        tableSymbol->deleteScope(); // sacamos el scope de la función
        cantOfRecursions--;     // sacamos una recursión
}
/**
 * cuando detectamos el fin de una declaracion de método
 * guardamos el bloque de tercetos de la función
 * sacamos el scope de la función
*/
void finishMethod(){
        // obtenemos el stack con los tercetos de la función
        functionStack* fs = stackFunction->top();
        stackFunction->pop();
        vectorOfFunction->add(fs);
        tableSymbol->deleteScope(); // sacamos el scope de la función
        cantOfRecursions--;     // sacamos una recursión
};

/**
 * verifica si existe una variable alcanzable y seteea el $$->ptr con el lexema
 *
 * @param key el acceso.
 * @param scope el scope actual
 * @param reglaptr puntero al lexema de la regla
 * @param reglatype puntero al tipo de la regla
 * @throws yyerror si no hay variable enalcanzable
 */
void checkVarInScope(string key, string scope, string& reglaptr, string& reglatype){
        tableSymbol->deleteSymbol(key); 
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching2(key, "var", scope, ""); 
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la variable "+ key);
        }else{
                reglaptr = symbolFinded->lexema;
                reglatype = symbolFinded->type;
        }
};
// función cuando se deteta un idnetificador con ++
void newFactorMasMas (string key, string scope, string& reglaptr, string& reglatype){
        // borra el símbolo viejo
        tableSymbol->deleteSymbol(key);

        // busca variable en scope que coincide con el uso
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatchingObject(key, "var", scope, "main"); 
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la variable "+ key);
        }else{
                int number = addTercet("+", symbolFinded->lexema, symbolFinded->lexema);          
                
                reglaptr = charTercetoId + to_string(number);
                reglatype = symbolFinded->type;
        }
}
void newAsignacion(string key, string scope, string op2Lexeme, string op2Type){
        tableSymbol->deleteSymbol(key); 
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching(key+scope, "var", scope); 
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
void newTof(string key, string& reglaptr, string& reglatype){
        int number = addTercet("tof", " ", key); 
        reglaptr = charTercetoId + to_string(number); 
        reglatype = "float";
}
void condition(string& reglaptr){
        int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); 
        reglaptr = charTercetoId + to_string(number); 
}

void addElse(string& reglaptr){
        Tercet * t = popTercet();  
        if (t!=nullptr){
                t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2));
        } 
        int number =  addTercetAndStack("BI", "", ""); 
        reglaptr = charTercetoId + to_string(number); 
}

void finIf(){
        Tercet *t = popTercet(); 
        if (t!=nullptr){
                t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );
        }
}

void initWhile(){
        addTercetOnlyStack("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), "");
}

void finWhile(string & reglaptr) {
        Tercet *t = popTercet(); 
        if (t!=nullptr){
                t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) );
        } 
        Tercet *t2 = popTercet(); 
        int number; 
        if(t2!=nullptr){
                int number = addTercet("BI", t2->getArg1(), "");
        } 
        reglaptr = charTercetoId + to_string(number);
}

void newCondicion(string operador, string op1ptr, string op2ptr, string op1type, string op2type, string& reglaptr){
        checkTypesCompare(op1type, op2type); 
        int number = addTercet(operador, op1ptr, op2ptr); 
        reglaptr = charTercetoId + to_string(number);
}

void newVariable(string key, string scope, string type){
        TableSymbol* ts;
        
        // determinas que tabla de símbolo usas
        if(stackClasses->size() <= 0){
                ts = tableSymbol;
        }else{
                ts = stackClasses->top()->attributesAndMethodsVector;
        }

        int diff = ts->getDiffOffScope(key+scope, "var", scope); 
        if(diff == 0){
                yyerror("Redeclaracion de variable en el mismo ambito");
        }else{
                symbol* newIdentificador = setNewScope(key, type, scope,"var", ts);
        } 
};

void initObjectDeclaration(string key, string scope, string& reglaptr){
        // verificar que la clase haya sido declarada y exista
        // borramos el símbolo de la tabla de símbolos general
        tableSymbol->deleteSymbol(key);
        symbol* symbolFinded = tableSymbol->getFirstSymbolMatching2(key, "clase", scope);
        if(symbolFinded == nullptr){
                yyerror("No se encontro declaracion previa de la clase "+ key);
                actualClass = "_error"; 
        }else{
                reglaptr = key; 
                actualClass = key; 
        }
}       
void  detectInheritance(string classToInherit , string scope, string classWhoInherit){
        
        // checkear que exista la clase
        // pasa los atributos de la clase padre a la clase hija

        tableSymbol->deleteSymbol(classToInherit);

        symbol* classFinded = tableSymbol->getFirstSymbolMatching(classToInherit+":main", "clase", scope);
        if(classFinded == nullptr){
                yyerror("No se encontro declaracion previa de la clase a heredar"+ classToInherit);
        }else{
                
                // recorrer cada uno de los atributos y metodos de la clase a hererdar
                for (const auto& par : classFinded->attributesAndMethodsVector->getSymbolTable()){
                        
                        symbol* sm = par.second;
                        
                        // creamos el nuevo símbolo
                        symbol* newClass = new symbol(*sm);   

                        size_t firstColonPos = sm->lexema.find(':');
                        string name = sm->lexema.substr(0, firstColonPos);
                        
                        firstColonPos = scope.rfind(':');
                        string scopeaux = scope.substr(0, firstColonPos);
                        
                        firstColonPos = sm->lexema.find(classToInherit);
                        string scopeInsideClass = sm->lexema.substr(firstColonPos, sm->lexema.size());
                        newClass->lexema = name+scopeaux+":"+scopeInsideClass+":"+classWhoInherit;
                        // try{
                        //     newClass->addHeredar(classToInherit);
                        // }catch(const std::exception& e){
                        //     yyerror("La clase tiene una cadena de más de 3 herencias");
                        // }
                        // if (firstColonPos >= sm->lexema.size()) {
                        //         newSm->lexema = name+scopeaux+":"+classWhoInherit;

                        // }else{          //
                        //         newSm->lexema = name+scopeaux+":"+scopeInsideClass+":"+classWhoInherit;
                        // }
                        // agregamos el nuevo símbolo a la tabla de simbolos   
                        stackClasses->top()->attributesAndMethodsVector->insert(newClass);
                }
        }
}