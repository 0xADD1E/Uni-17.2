; Convert temperatures from C to F
; Author:  Addie Morrison
; Date:    4 Oct 2017

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt          BYTE    "Enter a temperature in degrees C", 0
string          BYTE    40 DUP (?)
resultLbl       BYTE    "That temperature in degrees F is", 0
degreesOut      BYTE    11 DUP (?), 0

.CODE
_MainProc PROC
    input       prompt, string, 40      ; Input temperature in C
    atod        string
    mov         ebx, eax                ; Multiply by 9
    mov         eax, 9
    imul        ebx
    mov         ebx, 5                  ; Divide by 5
    idiv        ebx
    add         eax, 32                 ; Add 32
    dtoa        degreesOut, eax         ; Convert and Output
    output      resultLbl, degreesOut
    mov eax, 0
    ret
_MainProc ENDP
END
