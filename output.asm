.386 
.model flat, stdcall 
.stack 200h 
option casemap:none 
include C:\masm32\include\windows.inc 
include C:\masm32\include\kernel32.inc 
include C:\masm32\include\user32.inc 
include C:\masm32\include\masm32.inc 
includelib C:\masm32\lib\kernel32.lib 
includelib C:\masm32\lib\user32.lib 
includelib C:\masm32\lib\masm32.lib 

.data
errorSumaEnteros db "Se produjo un overflow en la suma de enteros.", 0 
errorProductoFlotantes db "Se produjo un overflow en el producto de flotantes.", 0 
errorRecursion db "Se produjo un llamado recursivo de una funcion a si misma.", 0 
@cero dd 0.0 
@maximoPositivo dd 3.40282347E+38 
@minimoPositivo dd 1.17549435E-38 
@maximoNegativo dd -3.40282347E+38 
@minimoNegativo dd -1.17549435E-38 
_No_son_iguales_asi_que_aca_no_se_va_a_entrar db "No son iguales asi que aca no se va a entrar", 0 
_Claramente_x_es_igual_a_100_35 db "Claramente x es igual a 100.35", 0 
_200_45_es_mayor_que_100_35 db "200.45 es mayor que 100.35", 0 
_200_45 dd 200.45
_Claramente_100_35_es_menor_o_igual_a_100_35 db "Claramente 100.35 es menor o igual a 100.35", 0 
_100_35 dd 100.35
_Claramente_100_35_no_es_igual_a_200_45 db "Claramente 100.35 no es igual a 200.45", 0 
_y_main dd ?
_x_main dd ?

.code
start:
FLD _100_35
FSTP _x_main

FLD _200_45
FSTP _y_main

FLD _y_main
FCOM _x_main
FSTSW AX
SAHF
JLE label0

INVOKE MessageBox, NULL, addr _200_45_es_mayor_que_100_35, addr _200_45_es_mayor_que_100_35, MB_OK

label0:
FLD _x_main
FCOM _y_main
FSTSW AX
SAHF
JE label1

INVOKE MessageBox, NULL, addr _Claramente_100_35_no_es_igual_a_200_45, addr _Claramente_100_35_no_es_igual_a_200_45, MB_OK

label1:
FLD _x_main
FCOM _y_main
FSTSW AX
SAHF
JNE label2

INVOKE MessageBox, NULL, addr _No_son_iguales_asi_que_aca_no_se_va_a_entrar, addr _No_son_iguales_asi_que_aca_no_se_va_a_entrar, MB_OK

label2:
FLD _x_main
FCOM _100_35
FSTSW AX
SAHF
JG label3

INVOKE MessageBox, NULL, addr _Claramente_100_35_es_menor_o_igual_a_100_35, addr _Claramente_100_35_es_menor_o_igual_a_100_35, MB_OK

label3:
FLD _x_main
FCOM _100_35
FSTSW AX
SAHF
JNE label4

INVOKE MessageBox, NULL, addr _Claramente_x_es_igual_a_100_35, addr _Claramente_x_es_igual_a_100_35, MB_OK

label4:

INVOKE ExitProcess, 0


end start