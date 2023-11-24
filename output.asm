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
@aux1 dd ?
_1_17549435EMENOS37 dd 1.17549435E-37
_0_0001 dd 0.0001
_y_main dd ?
_x_main dd ?

.code
start:
FLD _0_0001
FSTP _x_main

FLD _1_17549435EMENOS37
FSTP _y_main

FLD _x_main
FMUL _y_main
FCOM @cero
FSTSW AX
SAHF
JE @labelAsignacionFlotante1
FCOM @maximoPositivo
FSTSW AX
SAHF
JA labelErrorProductoFlotantes
FCOM @minimoNegativo
FSTSW AX
SAHF
JB labelErrorProductoFlotantes
FCOM @minimoPositivo
FSTSW AX
SAHF
JA @labelAsignacionFlotante1
FCOM @maximoNegativo
FSTSW AX
SAHF
JA labelErrorProductoFlotantes
@labelAsignacionFlotante1:
FSTP @aux1

FLD @aux1
FSTP _x_main


INVOKE ExitProcess, 0

labelErrorProductoFlotantes:
INVOKE MessageBox, NULL, addr errorProductoFlotantes, addr errorProductoFlotantes, MB_OK
INVOKE ExitProcess, 0

end start