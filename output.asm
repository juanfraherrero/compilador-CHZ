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
@aux2 dd ? 
_clase2:main dd ? 
_metodo1 dd ? 
inside_metodo1 db "inside metodo1", 0 
_x:main:clase2:metodo1:ob2:main dw ? 
_3_s db ? 
_z:main:clase2:ob2:main db ? 
_x:main db ? 
_3_ui dw ? 
_ob2:main dd ? 
_ob2 dd ? 
_z dd ? 
@aux1 dd ? 

.code
metodo1:main:clase2:ob2:main:
MOV AL, _3_ui
MOV _x:main:clase2:metodo1:ob2:main, AL

INVOKE MessageBox, NULL, addr inside_metodo1, addr inside_metodo1, MB_OK

RET

start:
MOV AX, _z:main:clase2:ob2:main
MOV _x:main, AX

MOV AX, _3_s
MOV _z:main:clase2:ob2:main, AX

MOV AX, _z:main:clase2:ob2:main
ADD AX, _1_s
MOV @aux1, AX
JO errorSumaEnteros

MOV AX, @aux1
MOV _z:main:clase2:ob2:main, AX

MOV AX, _z:main:clase2:ob2:main
ADD AX, _1_s
MOV @aux2, AX
JO errorSumaEnteros

MOV AX, @aux2
MOV _z:main:clase2:ob2:main, AX

MOV AX, 
MOV _x:main, AX

CALL _metodo1:main:clase2:ob2:main


invoke ExitProcess, 0
end start