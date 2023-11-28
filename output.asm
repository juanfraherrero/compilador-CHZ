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
@aux2 dq ?
_flagRecursividadmethod1_main_clase1_ob1_main db 0
_1_0 dq 1.0
_1_ui dw 1
_1_s db 1
_x_main_clase1_ob1_main db ?
@aux1 db ?
_21_s db 21
_minus31_s db -31
_x_main db ?
_k_main_clase1_method1 db ?
_JORGE db "JORGE", 0 
_y_main_clase1_method1 db ?
_2_s db 2
_PEDRO db "PEDRO", 0 
_z_main dq ?
_3_s db 3
_LEVANA db "LEVANA", 0 

.code
method1_main_clase1_ob1_main:
; Subroutine Prologue 
push ebp     ; Save the old base pointer value.
mov ebp, esp ; Set the new base pointer value. 
sub esp, 4   ; Make room for one 4-byte local variable. 
push edi     ; Save the values of registers that the function 
push esi     ; will modify. This function uses EDI and ESI. 

CMP _flagRecursividadmethod1_main_clase1_ob1_main, 1
JE labelErrorRecursion
MOV _flagRecursividadmethod1_main_clase1_ob1_main, 1
MOV AH, _2_s
MOV _y_main_clase1_method1, AH

INVOKE StdOut, addr _PEDRO
INVOKE StdOut, addr newline 

MOV AL, _x_main
MOVSX AX, AL 
MOV @varForPrintShort, AX 
INVOKE printf, cfm$("%hd\n"), @varForPrintShort 

MOV AH, _3_s
MOV _k_main_clase1_method1, AH

MOV AL, _k_main_clase1_method1
MOVSX AX, AL 
MOV @varForPrintShort, AX 
INVOKE printf, cfm$("%hd\n"), @varForPrintShort 

INVOKE StdOut, addr _LEVANA
INVOKE StdOut, addr newline 

MOV _flagRecursividadmethod1_main_clase1_ob1_main, 0
; Subroutine Epilogue 
pop esi      ; Recover register values 
pop  edi 
mov esp, ebp ; Deallocate local variables 
pop ebp ; Restore the caller's base pointer value 

RET

start:
MOV AH, _minus31_s
MOV _x_main_clase1_ob1_main, AH

MOV AH, _x_main_clase1_ob1_main
MOV _x_main, AH

MOV AL, _x_main
MOVSX AX, AL 
MOV @varForPrintShort, AX 
INVOKE printf, cfm$("%hd\n"), @varForPrintShort 

MOV AH, _x_main

MOV _k_main_clase1_method1, AH

CALL method1_main_clase1_ob1_main

INVOKE StdOut, addr _JORGE
INVOKE StdOut, addr newline 

MOV AH, _x_main
ADD AH, _21_s
MOV @aux1, AH
JO labelErrorSumaEnteros

MOV AH, @aux1
MOV _x_main, AH

MOV AL, _x_main
MOVSX AX, AL 
MOV @varForPrintShort, AX 
INVOKE printf, cfm$("%hd\n"), @varForPrintShort 

MOV AL, _x_main
CBW 
CWDE 
CDQ 
MOV  DWORD PTR @aux2, EAX
MOV  DWORD PTR @aux2 + 4, EDX
FILD @aux2
FSTP @aux2

FLD @aux2
FSTP _z_main

INVOKE printf, cfm$("%.20Lf\n"), _z_main


INVOKE ExitProcess, 0

labelErrorSumaEnteros:
INVOKE StdOut, addr errorSumaEnteros
INVOKE StdOut, addr newline ; Imprimir una nueva línea 
INVOKE ExitProcess, 0
labelErrorRecursion:
INVOKE StdOut, addr errorRecursion 
INVOKE StdOut, addr newline ; Imprimir una nueva línea 
INVOKE ExitProcess, 0

end start