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
_flagRecursividadfuncion1_main db 0

.code
funcion1_main:
CMP _flagRecursividadfuncion1_main, 1
JE labelErrorRecursion
MOV _flagRecursividadfuncion1_main, 1
CALL funcion1_main

MOV _flagRecursividadfuncion1_main, 0
RET

start:
CALL funcion1_main


INVOKE ExitProcess, 0

labelErrorRecursion:
INVOKE MessageBox, NULL, addr errorRecursion, addr errorRecursion, MB_OK
INVOKE ExitProcess, 0

end start