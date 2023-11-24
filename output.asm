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
_Bien_la_conversion db "Bien la conversion", 0 
@aux1 dd ?
_10_0 dd 10.0
_10_s db 10
_y_main db ?
_x_main dd ?

.code
start:
MOV AH, _10_s
MOV _y_main, AH


FLD @aux1
FSTP _x_main

FLD _x_main
FCOM _10_0
FSTSW AX
SAHF
JNE label0

INVOKE MessageBox, NULL, addr _Bien_la_conversion, addr _Bien_la_conversion, MB_OK

label0:

INVOKE ExitProcess, 0


end start