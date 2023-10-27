%{

#include "include/types.hpp"
#include "include/TableSymbol.hpp"
#include "include/TableReservedWord.hpp"
#include "include/Lexico.hpp"
#include "include/Tercets.hpp"

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

programa    :   '{' sentencias '}'              { Tercet *t = new Tercet("FIN", "-", "-"); int number = tableTercets->add(t);}
            |   '{' '}'                         { yywarning("Se está compilando un programa sin contenido"); Tercet *t = new Tercet("FIN", "-", "-"); int number = tableTercets->add(t); }
            |   '{' sentencias '}' error        { yyerror("Se detectó contenido luego de finalizado el programa");}             
            |   '{' '}' error                   { yywarning("Se está compilando un programa sin contenido"); yyerror("Se detectó contenido luego de finalizado el programa");}             
sentencias  :   sentencias sentencia
            |   sentencia
            ;

sentencia   :   declarativa ','                                    
            |   ejecutable ','    
            |   declarativa                                      { yyerror("Se detectó una falta de coma"); }                                 
            |   ejecutable                                       { yyerror("Se detectó una falta de coma"); }
            |   error ','                                        { yyerror("Se detectó una sentencia inválida"); }
            ;

declarativa :   tipo lista_de_variables                                             { yyPrintInLine("Se detectó declaración de variable");}
            |   declaracion_clase                                                    
            |   declaracion_objeto                                                  { yyPrintInLine("Se detectó declaración de objeto");}
            |   declaracion_funcion                                                 { yyPrintInLine("Se detectó declaración de función");}
            ;

declaracion_funcion     :       funcion_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'             { tableSymbol->deleteScope();}
                        |       VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'                     { yyerror("Se detectó la falta de un nombre en la función"); }
                        |       funcion_name '(' parametro ')' '{' '}'                                  { tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
                        ;

funcion_name    :       VOID IDENTIFICADOR              { symbol* newIdentificador = setNewScope($2->ptr, "void", tableSymbol->getScope(), "funcion"); tableSymbol->addScope($2->ptr); }
                ;

declaracion_clase   :   CLASS IDENTIFICADOR '{' lista_atributos_y_metodos '}'         /* Los atributos y métodos van en desorden */ { yyPrintInLine("Se detectó declaración de clase");}
                    |   CLASS IDENTIFICADOR /* fordward declaration*/           { yyPrintInLine("Se detectó declaración de clase adelantada");}
                    |   CLASS IDENTIFICADOR '{' '}'                             {yywarning("Se detectó una declaración de clases vacía");}
                    ;
lista_atributos_y_metodos       :       lista_atributos_y_metodos tipo lista_de_variables ','           { yyPrintInLine("Se detectó declaración de variable en clase");}
                                |       lista_atributos_y_metodos metodo ','                                 
                                |       tipo lista_de_variables ','                                    { yyPrintInLine("Se detectó declaración de variable en clase");}
                                |       metodo ','
                                ;


metodo  :   metodo_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'                 { tableSymbol->deleteScope(); }
        |   metodo_name '(' parametro ')' '{' '}'                                      { tableSymbol->deleteScope(); yyerror("Se detectó la falta de RETURN en el cuerpo de la función");}
        ;

metodo_name     :       VOID IDENTIFICADOR              { symbol* newIdentificador = setNewScope($2->ptr, "void", tableSymbol->getScope(), "metodo"); tableSymbol->addScope($2->ptr);}
                ;

declaracion_objeto  :   IDENTIFICADOR lista_de_objetos
                    ;

lista_de_objetos    :   lista_de_objetos ';' IDENTIFICADOR  
                    |   IDENTIFICADOR
                    ;

tipo    :       SHORT   { typeAux = "short"; $$->type ="short";}
        |       UINT    { typeAux = "unsigned int"; $$->type = "unsigned int";}
        |       FLOAT   { typeAux = "float"; $$->type = "float";}
        ;

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR    { symbol* newIdentificador = setNewScope($3->ptr, typeAux, tableSymbol->getScope(),""); }
                    |   IDENTIFICADOR                           { symbol* newIdentificador = setNewScope($1->ptr, typeAux, tableSymbol->getScope(),""); }
                    ;

parametro   :   tipo IDENTIFICADOR              { symbol* newIdentificador = setNewScope($2->ptr, $1->type, tableSymbol->getScope(), "parametro"); $$->ptr = newIdentificador->lexema; $$->type = $1->type;}
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
cuerpo_de_la_funcion_sin_return    :   cuerpo_de_la_funcion_sin_return sentencia 
                                   |   sentencia
                                   ;
ejecutable  :    asignacion
            |    invocacion                                 
            |    seleccion
            |    PRINT CADENA_CARACTERES                    { Tercet *t = new Tercet("print", tableSymbol->getSymbol($2->ptr)->value, ""); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
            |    ciclo_while
            |    acceso_objeto
            |    PRINT                                      { yyerror("Se detectó la falta de una cadena de caracteres al querer imprimir");}
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica          { checkTypesAsignation(tableSymbol->getSymbol($1->ptr)->type, $3->type); Tercet *t = new Tercet("=", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '(' ')'                           
           ;


expresion_aritmetica : expresion_aritmetica '+' termino         { if(checkTypesOperation($1->type, $3->type)){$$->type=$1->type;}else{$$->type="error";}; Tercet *t = new Tercet("+", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | expresion_aritmetica '-' termino          { if(checkTypesOperation($1->type, $3->type)){$$->type=$1->type;}else{$$->type="error";}; Tercet *t = new Tercet("-", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | expresion_aritmetica '-' '*' termino      { if(checkTypesOperation($1->type, $4->type)){$$->type=$1->type;}else{$$->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | expresion_aritmetica '+' '*' termino      { if(checkTypesOperation($1->type, $4->type)){$$->type=$1->type;}else{$$->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | expresion_aritmetica '-' '/' termino      { if(checkTypesOperation($1->type, $4->type)){$$->type=$1->type;}else{$$->type="error";}; yywarning("Se detectó un error en operador, quedará '-'"); Tercet *t = new Tercet("-", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | expresion_aritmetica '+' '/' termino      { if(checkTypesOperation($1->type, $4->type)){$$->type=$1->type;}else{$$->type="error";}; yywarning("Se detectó un error en operador, quedará '+'"); Tercet *t = new Tercet("+", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
                    | termino                                   { $$->type = $1->type; $$->ptr = $1->ptr; }
                    ;

termino : termino '*' factor                                    { if(checkTypesOperation($1->type, $3->type)){$$->type=$1->type;}else{$$->type="error";}; Tercet *t = new Tercet("*", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
        | termino '/' factor                                    { if(checkTypesOperation($1->type, $3->type)){$$->type=$1->type;}else{$$->type="error";}; Tercet *t = new Tercet("/", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
        | factor                                                { $$->ptr = $1->ptr; $$->type = $1->type;}
        ;

seleccion : IF bloque_condicion cuerpo_if                       { Tercet *t = tableTercets->pop(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1) );}                     
          | IF '(' ')' cuerpo_if                                { yyerror("Falta de condición en el bloque de control IF");}
          ;

bloque_condicion : '(' condicion ')'                            { Tercet * t = new Tercet("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); int number = tableTercets->add(t); tableTercets->push(t); $$->ptr = charTercetoId + to_string(number); }
                 ;

cuerpo_if : cuerpo_then ELSE cuerpo_else END_IF
          | cuerpo_then cuerpo_else END_IF                      { yyerror(" Falta de ELSE en bloque de control IF-ELSE");}
          | cuerpo_then END_IF                                  
          ; 

cuerpo_then : bloque_ejecutables                                { Tercet * t = tableTercets->pop();  t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2)); Tercet * t2 = new Tercet("BI", "", ""); int number = tableTercets->add(t2); tableTercets->push(t2); $$->ptr = charTercetoId + to_string(number);}
            ;
cuerpo_else : bloque_ejecutables
            ;

ciclo_while : inicio_while bloque_condicion_while DO cuerpo_while               { Tercet *t = tableTercets->pop(); t->setArg2( charTercetoId + to_string(tableTercets->numberOfLastTercet() + 2) ); Tercet *t2 = tableTercets->pop(); Tercet * t3 = new Tercet("BI", t2->getArg1(), ""); int number = tableTercets->add(t3); $$->ptr = charTercetoId + to_string(number);}                     
            ;

inicio_while    : WHILE                                                         { Tercet * t = new Tercet("incioCondicionWhile", charTercetoId + to_string(tableTercets->numberOfLastTercet() + 1), ""); tableTercets->push(t); }
                ;

bloque_condicion_while: '(' condicion ')'                                       { Tercet * t = new Tercet("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); int number = tableTercets->add(t); tableTercets->push(t); $$->ptr = charTercetoId + to_string(number); }
                ;

cuerpo_while : bloque_ejecutables                                       
            ;   

condicion : expresion_aritmetica '>' expresion_aritmetica                       { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet(">", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica '<' expresion_aritmetica                       { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet("<", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet("==", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica       { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet("!!", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet(">=", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica    { checkTypesCompare($1->type, $3->type); Tercet *t = new Tercet("<=", $1->ptr, $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); }
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   ejecutable ','
                    |   declarativa  ','                  { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                    ;

sentencias_ejecutables  :   sentencias_ejecutables ejecutable ','
                        |   sentencias_ejecutables ejecutable                   { yyerror("Se detectó una falta de coma"); }
                        |   ejecutable ','
                        |   ejecutable                                          { yyerror("Se detectó una falta de coma"); }
                        |   sentencias_ejecutables declarativa ','              { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                        |   sentencias_ejecutables declarativa                  { yyerror("Se detectó una sentencia declarativa en bloque de control y la falta de coma"); }
                        |   declarativa ','                                     { yyerror("Se detectó una sentencia declarativa en bloque de control"); }
                        |   declarativa                                         { yyerror("Se detectó una falta de coma"); }
                        |   ','                                                 { yywarning("Se detectó una sentencia vacía dentro del bloque de sentencias ejecutables"); }
                        |   error ','                                           { yyerror("Se detectó una sentencia inválida dentro del bloque de sentencias ejecutables"); }
                        ;

factor : IDENTIFICADOR                                                  { $$->ptr = $1->ptr; $$->type = tableSymbol->getSymbol($1->ptr)->type;}
       | IDENTIFICADOR OPERADOR_SUMA_SUMA                               { Tercet * t = new Tercet("+", $1->ptr, $1->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number);$$->type = tableSymbol->getSymbol($1->ptr)->type;}
       | constanteSinSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | constanteConSigno                                              { $$->ptr = $1->ptr; $$->type = $1->type;}
       | TOF '(' expresion_aritmetica ')'                               { Tercet *t = new Tercet("tof", " ", $3->ptr); int number = tableTercets->add(t); $$->ptr = charTercetoId + to_string(number); $$->type = "float"; } 
       ;

constanteSinSigno       :       ENTERO_SIN_SIGNO                        { $$->ptr = $1->ptr; $$->type = $1->type;}               
                        |       CADENA_CARACTERES                       { $$->ptr = $1->ptr; $$->type = $1->type;}
                        ;

constanteConSigno       :       ENTERO_CORTO                            { checkIntegerShort($1->ptr); $$->ptr = $1->ptr; $$->type = $1->type;}
                        |       '-' ENTERO_CORTO                        { string newLexema = checkIntegerShortNegative($2->ptr); $$->ptr = newLexema; $$->type = $2->type;}
                        |       PUNTO_FLOTANTE                          { $$->ptr = $1->ptr; $$->type = $1->type;}
                        |       '-' PUNTO_FLOTANTE                      { string newLexema = setFloatNegative($2->ptr); $$->ptr = newLexema; $$->type = $2->type;}
                        |       '-'                                     { yyerror("Falta constante numérica en la expresión"); }
                        ;

acceso_objeto   :   IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica                 { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '=' IDENTIFICADOR '.' IDENTIFICADOR      { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'             { yyPrintInLine("Se detectó un acceso a un objeto");}
                |   IDENTIFICADOR '.' IDENTIFICADOR '(' ')'                                  { yyPrintInLine("Se detectó un acceso a un objeto");}
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
        
        symbol* identificador = tableSymbol->getSymbol(key);// obtenemos el símbolo
        symbol* newIdentificador = new symbol(*identificador);  // copiamos el símbolo
        tableSymbol->deleteSymbol(identificador->lexema);       // eliminamos el simbolo (usa el contador)
        
        if(type != ""){
                newIdentificador->type = type;                          // actualizamos el tipo
        }
        if(scope != ""){
                newIdentificador->lexema += scope;                      // actualizamos el scope
        }
        if(uso != ""){
                newIdentificador->uso = uso;                            // actualizamos el uso
        }

        tableSymbol->insert(newIdentificador);                  // insertamos el nuevo símbolo
}