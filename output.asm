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
error db "Error de ejecucion.", 0 
@aux2 db ?
@aux1 db ?
_b_main_func2 db ?
_a_main_func2 db ?
_2_s db 2
_1_s db 1
_y_main db ?
_x_main db ?

.code
func2_main:
MOV AH, _1_s
MOV _a_main_func2, AH

MOV AH, _2_s
MOV _b_main_func2, AH

MOV AH, _a_main_func2
ADD AH, _b_main_func2
MOV @aux1, AH
JO labelErrorSumaEnteros

MOV AH, @aux1
MOV _a_main_func2, AH

RET

start:
MOV AH, _1_s
MOV _x_main, AH

MOV AH, _2_s
MOV _y_main, AH

MOV AH, _x_main
ADD AH, _y_main
MOV @aux2, AH
JO labelErrorSumaEnteros

MOV AH, @aux2
MOV _x_main, AH


INVOKE ExitProcess, 0
labelErrorSumaEnteros:
INVOKE MessageBox, NULL, addr errorSumaEnteros, addr errorSumaEnteros, MB_OK
INVOKE ExitProcess, 0

end start