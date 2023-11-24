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
@aux1 dw ?
_100_ui dw 100
_65530_ui dw 65530
_y_main dw ?
_x_main dw ?

.code
start:
MOV AX, _65530_ui
MOV _x_main, AX

MOV AX, _100_ui
MOV _y_main, AX

MOV AX, _x_main
ADD AX, _y_main
MOV @aux1, AX
JC labelErrorSumaEnteros

MOV AX, @aux1
MOV _x_main, AX


INVOKE ExitProcess, 0

labelErrorSumaEnteros:
INVOKE MessageBox, NULL, addr errorSumaEnteros, addr errorSumaEnteros, MB_OK
INVOKE ExitProcess, 0

end start