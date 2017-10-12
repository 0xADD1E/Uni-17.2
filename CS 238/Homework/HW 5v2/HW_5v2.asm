; Homework 5, Version 2 -- Do division
; Author:  Addie Morrison
; Date:    10 Oct 2017

.586
.MODEL FLAT

INCLUDE io.h            				; header file for input/output

.STACK 4096

.DATA
prompt1 BYTE    "Enter value for A", 0
prompt2 BYTE    "Enter value for B", 0
prompt3 BYTE    "Enter value for C", 0
string  BYTE    40 DUP (?)
result1 BYTE    "The quotient is", 0
result2 BYTE    "The remainder is", 0
num     BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
        input   prompt1, string, 40      ; Var A
        atod    string
        mov     edx, eax                 ; Push over to edx for other inputs

        input   prompt2, string, 40      ; Var B
        atod    string
        mov     ebx, eax

        input   prompt3, string, 40      ; Var C
        atod    string
        mov     ecx, eax
        
        mov     eax, edx                ; And get A back

        imul    ebx                     ; a*b
        mov     ebx, eax

        mov     eax, 5                  ; 5*c
        imul    ecx

        add     eax, ebx                ; (a*b) + (5*c)

        mov     ebx, 13                 ; () / 13
        cdq
        idiv    ebx

        dtoa    num, eax                ; Output quotient
        output  result1, num

        dtoa    num, edx                ; Output remainder
        output  result2, num

        mov eax, 0
        ret
_MainProc ENDP
END
