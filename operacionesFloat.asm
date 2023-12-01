.386 
.model flat, stdcall 
.stack 200h 
option casemap:none 
include C:\masm32\include\masm32rt.inc 
include C:\masm32\include\windows.inc 
include C:\masm32\include\kernel32.inc 
include C:\masm32\include\user32.inc 
include C:\masm32\include\masm32.inc 
includelib C:\masm32\lib\kernel32.lib 
includelib C:\masm32\lib\user32.lib 
includelib C:\masm32\lib\masm32.lib 
dll_dllcrt0 PROTO C
printf PROTO C : VARARG

.data
newline db 10, 0 ; Definición de un carácter de nueva línea 
@varForPrintShort dw ?; variable auxiliarpara imprimir short al requerir de una promoción 
errorSumaEnteros db "Se produjo un overflow en la suma de enteros.", 0 
errorProductoFlotantes db "Se produjo un overflow en el producto de flotantes.", 0 
errorRecursion db "Se produjo un llamado recursivo de una funcion a si misma.", 0 
@cero dd 0.0 
@maximoPositivo dd 3.40282347E+38 
@minimoPositivo dd 1.17549435E-38 
@maximoNegativo dd -3.40282347E+38 
@minimoNegativo dd -1.17549435E-38 
@aux8 dq ?
@aux7 dq ?
@aux4 dq ?
@aux3 dq ?
_a_main dq ?
@aux9 dq ?
_M1D2 dq -1.2
_1D2EP10 dq 1.2E+10
_4D dq 4.
_0D dq 0.
@aux5 dq ?
_1_s db 1
_3D dq 3.
_1_ui dw 1
_M1D2EP10 dq -1.2E+10
_2DEP34 dq 2.E+34
@aux1 dq ?
_1D0 dq 1.0
@aux6 dq ?
@aux2 dq ?

.code
start:
FLD _3D
FADD _4D
FSTP @aux1

FLD @aux1
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FSUB _4D
FSTP @aux2

FLD @aux2
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FMUL _4D
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
FSTP @aux3

FLD @aux3
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FDIV _4D
FSTP @aux4

FLD @aux4
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FADD _M1D2EP10
FSTP @aux5

FLD @aux5
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FADD _M1D2
FSTP @aux6

FLD @aux6
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FADD _2DEP34
FSTP @aux7

FLD @aux7
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FADD _1D2EP10
FSTP @aux8

FLD @aux8
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main

FLD _3D
FADD _0D
FSTP @aux9

FLD @aux9
FSTP _a_main

INVOKE printf, cfm$("%.20Lf\n"), _a_main


INVOKE ExitProcess, 0

labelErrorProductoFlotantes:
INVOKE StdOut, addr errorProductoFlotantes 
INVOKE StdOut, addr newline ; Imprimir una nueva línea 
INVOKE ExitProcess, 0
labelErrorRecursion:
INVOKE StdOut, addr errorRecursion 
INVOKE StdOut, addr newline ; Imprimir una nueva línea 
INVOKE ExitProcess, 0

end start