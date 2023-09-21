Para convertir el .y en un código usar el siguiente comando

''' {Path del ejecutable de YACC}  -v --output=Parser.cpp gramaticaComCHZExtendida.y '''

Esto te genera un "y.tab.c" que hay que renombrarlo a "Parser.cpp" y hay que moverlo a la carpeta "" Compilador-CHZ/src ""


dentro del Parser.cpp, hay que ir a la función yyparse() y cambiar la declaración a  yyparse(Lexico* lexico, int* lineNumber)

Luego en los dos lugares donde se llama " yylex() " dentro de yyparse se debe reemplazar por " lexico->yylex() "

y cuando se llame a yyerror(string) cambiarlo por yyerror(string, lineNumber)

Además se debe cambiar el typedef de TYPEDEF por string

Con estos pasos ya se puede usar, los warnings que te tira son porque no se usan algunas variables

make cleanw

make all

Y probar

Línea para debugging Parser
printf("yydebug: state %d, char: %d shifting to state %d \n", yystate, yychar, yytable[yyn]);