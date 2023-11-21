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
@aux3 dd ? 
_falso  db " falso ", 0 
_verdadero  db " verdadero ", 0 
_6_s db ? 
_4_s db ? 
_10_s db ? 
_8_s db ? 
@aux1 dd ? 
_7_s db ? 
@aux2 dd ? 
_z:main dd ? 
_x:main db ? 

.code
start:
MOV AX, _7_s
MOV _x:main, AX

MOV AX, _x:main
ADD AX, _8_s
MOV @aux1, AX
JO errorSumaEnteros

MOV AX, @aux1
MOV _x:main, AX

FILD _10_s
FSTP @aux2

FLD @aux2
FSTP _z:main

CMP _4_s, _6_s
JGE label0

INVOKE MessageBox, NULL, addr _verdadero , addr _verdadero , MB_OK

JMP label2

label0:
INVOKE MessageBox, NULL, addr _falso , addr _falso , MB_OK

label2:
MOV AX, _x:main
ADD AX, _10_s
MOV @aux3, AX
JO errorSumaEnteros

MOV AX, @aux3
MOV _x:main, AX


invoke ExitProcess, 0
end start