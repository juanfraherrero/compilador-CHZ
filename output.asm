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
_re_contra_mal_la_comparacion db "re contra mal la comparacion", 0 
_20_0 dd 20.0
_bien_la_comparacion db "bien la comparacion", 0 
_2_0 dd 2.0
_5_0 dd 5.0
@aux1 dd ?
_10_0 dd 10.0
_z_main dd ?
_y_main dd ?
_x_main dd ?

.code
start:
FLD _10_0
FSTP _x_main

FLD _5_0
FSTP _y_main

FLD _x_main
FDIV _y_main
FSTP @aux1

FLD @aux1
FSTP _z_main

FLD _z_main
FCOM _2_0
FSTSW AX
SAHF
JNE label0

INVOKE MessageBox, NULL, addr _bien_la_comparacion, addr _bien_la_comparacion, MB_OK

label0:
FLD _z_main
FCOM _20_0
FSTSW AX
SAHF
JNE label1

INVOKE MessageBox, NULL, addr _re_contra_mal_la_comparacion, addr _re_contra_mal_la_comparacion, MB_OK

label1:

INVOKE ExitProcess, 0


end start