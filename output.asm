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
_1_s db 1
@aux1 db ?
_20_s db 20
_12_s db 12
_x_main db ?

.code
start:
MOV AH, _12_s
MOV _x_main, AH

label0:
CMP _x_main, _20_s
JGE label1

MOV AH, _x_main
ADD AH, _1_s
MOV @aux1, AH
JO labelErrorSumaEnteros

MOV AH, @aux1
MOV _x_main, AH

JMP label0

label1:

INVOKE ExitProcess, 0
labelErrorSumaEnteros:
INVOKE MessageBox, NULL, addr errorSumaEnteros, addr errorSumaEnteros, MB_OK
INVOKE ExitProcess, 0

end start