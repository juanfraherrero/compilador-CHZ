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

// generamos la tabla de simbolos
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

programa    :   '{' sentencias '}'              {  yyPrintInLine("Se detecto un programa");}
            |   '{' '}'                         { yywarning("Se esta compilando un programa sin contenido"); }
            |   '{'                             { yywarning("Se esta compilando un programa sin contenido y falta la ultima llave"); }
            |   '}'                             { yywarning("Se esta compilando un programa sin contenido y falta la primer llave"); }
            |   '{' sentencias '}' error        { yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   '{' '}' error                   { yywarning("Se esta compilando un programa sin contenido"); yyerror("Se detecto contenido luego de finalizado el programa");}             
            |   sentencias                      { yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' sentencias                  { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   sentencias '}'                  { yywarning("Se detecto la falta de la primera llave del programa"); }
            |   '{' comas sentencias '}'        {  yyPrintInLine("Se detecto un programa"); }
            |   '{' comas '}'                   {  yyPrintInLine("Se detecto un programa"); }
            |   comas                           { yywarning("Se detecto la falta de llaves en el programa"); }
            |   '{' comas                       { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |   comas '}'                       { yywarning("Se detecto la falta de la primera llave del programa"); }
            |   '{' comas sentencias            { yywarning("Se detecto la falta de la ultima llave del programa"); }
            |    comas sentencias '}'           { yywarning("Se detecto la falta de la primera llave del programa"); }
            |    comas sentencias               { yywarning("Se detecto la falta de llaves en el programa"); }
            |                                   { yyerror("No hay programa"); }
            ;
            
sentencias  :   sentencias sentencia
            |   sentencia 
            ;

sentencia   :   declarativa comas                                    
            |   ejecutable comas    
            |   declarativa                                      { yywarning("Se detecto una falta de coma"); }                                 
            |   ejecutable                                       { yywarning("Se detecto una falta de coma"); }
            |   error ','                                        { yyerror("Se detecto una sentencia invalida");}
            ;

comas : ',' comas
      | ',' 
      ;

declarativa :   tipo lista_de_variables                                             { yyPrintInLine("Se detecto declaracion de variable");}
            |   declaracion_clase                                                    
            |   declaracion_objeto                                                  { yyPrintInLine("Se detecto declaracion de objeto");}
            |   declaracion_funcion                                                 { yyPrintInLine("Se detecto declaracion de funcion");}
            ;

declaracion_funcion     :       funcion_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'             { yyPrintInLine("Se detecto declaracion de funcion");}
                        |       VOID '(' parametro ')' '{' cuerpo_de_la_funcion '}'                     { yyerror("Se detecto la falta de un nombre en la funcion"); }
                        |       funcion_name '(' parametro ')' '{' '}'                                  { yywarning("Se detecto la falta de RETURN en el cuerpo de la funcion");}
                        ;

funcion_name    :       VOID IDENTIFICADOR              {  }
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


metodo  :   metodo_name '(' parametro ')' '{' cuerpo_de_la_funcion '}'                 {  yyPrintInLine("Se detecto declaracion de metodo en clase");} 
        |   metodo_name '(' parametro ')' '{' '}'                                      {  yyerror("Se detecto la falta de RETURN en el cuerpo de la funcion");}
        ;

metodo_name     :       VOID IDENTIFICADOR              { }
                |       VOID                            { yyerror("Falta de nombre de metodo"); }
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

lista_de_variables  :   lista_de_variables ';' IDENTIFICADOR    {  }
                    |   IDENTIFICADOR                           {  }
                    ;

parametro   :   tipo IDENTIFICADOR              { }
            |   tipo                            { yyerror("Falta de nombre de parametro"); }            
            |   IDENTIFICADOR                   { yyerror("Falta de tipo de parametro"); } 
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
ejecutable  :    asignacion                             { yyPrintInLine("Se detecto asignacion"); }
            |    invocacion                             { yyPrintInLine("Se detecto invocacion"); }
            |    seleccion                              { yyPrintInLine("Se detecto un if-else"); }
            |    PRINT CADENA_CARACTERES                { yyPrintInLine("Se detecto una impresion de una cadena"); }
            |    PRINT IDENTIFICADOR                    { yyPrintInLine("Se detecto una impresion de identificador"); }
            |    PRINT constanteConSigno                { yyPrintInLine("Se detecto una impresion de constante"); }
            |    PRINT constanteSinSigno                { yyPrintInLine("Se detecto una impresion de constante"); }
            |    ciclo_while                            { yyPrintInLine("Se detecto un while"); }
            ;

asignacion : IDENTIFICADOR '=' expresion_aritmetica                     { }
           | IDENTIFICADOR '.' IDENTIFICADOR '=' expresion_aritmetica
           ;

invocacion : IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '(' ')' 
           | IDENTIFICADOR '.' IDENTIFICADOR '(' expresion_aritmetica ')'      
           | IDENTIFICADOR '.' IDENTIFICADOR '(' ')'                           
           ;


expresion_aritmetica : expresion_aritmetica '+' termino         
                    | expresion_aritmetica '-' termino          
                    | expresion_aritmetica '-' '*' termino      { yywarning("Se detectaron multiples operadores '-' '*', quedara '-'");}
                    | expresion_aritmetica '+' '*' termino      { yywarning("Se detectaron multiples operadores '+' '*', quedara '+'");}
                    | expresion_aritmetica '-' '/' termino      { yywarning("Se detectaron multiples operadores '-' '/', quedara '-'");}
                    | expresion_aritmetica '+' '/' termino      { yywarning("Se detectaron multiples operadores '+' '/', quedara '+'");}   
                    | expresion_aritmetica termino      { yywarning("Se detectaron multiples operadores '+' '/', quedara '+'");}
                    | termino                                   
                    ;

termino : termino '*' factor                                    
        | termino '/' factor                                    
        | factor                                                
        ;

seleccion : IF bloque_condicion cuerpo_if                       { }                    
          ;

bloque_condicion : '(' condicion ')'                            {  }
                 | '(' condicion                                { yywarning("Falta de ultimo parentesis en condicion"); }
                 |  condicion ')'                               { yywarning("Falta de primer parentesis en condicion"); }
                 |  condicion                                   { yywarning("Falta de parantesis en condicion"); }
                 |  '(' ')'                                     { yyerror("Falta de condicion en el bloque de control IF");}
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
else_if :       ELSE                                            { }
        ;
ciclo_while : inicio_while bloque_condicion DO cuerpo_while               { }                     
            | inicio_while bloque_condicion cuerpo_while                  { yywarning("Falta de DO en WHILE-DO"); }                     
            ;

inicio_while    : WHILE                                                         {  }
                ;

/* bloque_condicion_while: '(' condicion ')'                                       { int number = addTercetAndStack("BF", charTercetoId + to_string(tableTercets->numberOfLastTercet()), ""); $$->ptr = charTercetoId + to_string(number); }
                | '(' condicion                                { }
                |  condicion ')'                               { }
                |  condicion                                   { }
                |  '(' ')'                                     { }
                ; */

cuerpo_while : bloque_ejecutables                                       
            ;   

condicion : expresion_aritmetica '>' expresion_aritmetica                       
          | expresion_aritmetica '<' expresion_aritmetica                       
          | expresion_aritmetica COMPARADOR_IGUAL_IGUAL expresion_aritmetica    
          | expresion_aritmetica COMPARADOR_DISTINTO expresion_aritmetica       
          | expresion_aritmetica COMPARADOR_MAYOR_IGUAL expresion_aritmetica    
          | expresion_aritmetica COMPARADOR_MENOR_IGUAL expresion_aritmetica    
          ;

bloque_ejecutables  :   '{' sentencias_ejecutables '}'
                    |   '{' sentencias_ejecutables RETURN ',' '}'              
                    |   ejecutable ',' 
                    |   declarativa  ','                  { yyerror("Se detecto una sentencia declarativa en bloque de control"); }
                    |   '{' RETURN ',' '}'
                    |    RETURN ','
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
       | TOF '(' expresion_aritmetica ')'                               
       | IDENTIFICADOR '.' IDENTIFICADOR 
       | CADENA_CARACTERES                      { yyerror("No se puede operar con cadena de caracteres"); }
       ;

constanteSinSigno       :       ENTERO_SIN_SIGNO                                              
                        ;

constanteConSigno       :       ENTERO_CORTO                            
                        |       '-' ENTERO_CORTO                        
                        |       PUNTO_FLOTANTE                          
                        |       '-' PUNTO_FLOTANTE                      
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
        int number = tableTercets->add(t);
        return number;
}
// Crea un terceto y lo agrega a la tabla de tercetos y lo apila.
// Los paramtros son argumento, operador1, y operador2
int addTercetAndStack(string argumento, string operando1, string operando2){
        Tercet *t = new Tercet(argumento, operando1, operando2); 
        int number = tableTercets->add(t);
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