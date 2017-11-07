; Basic Array Search
; Author:  Addie Morrison
; Date:    6 Nov 2017

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
arr     DWORD   10 DUP (?)
str1    BYTE    "Enter the length of the array", 0
str2    BYTE    "Enter number for index"
str3    BYTE    10 DUP (?)
strx    BYTE    ".", 0
str4    BYTE    "Would you like to search for a value? (Y or N)", 0
str5    BYTE    "Please enter your number to search for", 0
str6    BYTE    "Your number is in index: ", 0
str7    BYTE    "Your number was not found", 0
str8    BYTE    " ", 0
inpstr  BYTE    10 DUP (?)
outstr  BYTE    10 DUP (?), 0

.CODE
_MainProc PROC
getLen: input   str1, inpstr, 10
        atod    inpstr
        cmp     eax, 0
        jle     getLen
        cmp     eax, 10
        jg      getLen
        mov     edx, eax

        mov     ecx, 0
        lea     ebx, arr
getVal: dtoa    str3, ecx
        input   str2, inpstr, 10
        atod    inpstr
        mov     [ebx], eax
        add     ebx, 4
        inc     ecx
        cmp     ecx, edx
        jl      getVal

search: input   str4, inpstr, 10
        cmp     inpstr, "Y"
        je      exec
        cmp     inpstr, "y"
        je      exec
        jmp     fin
exec:   input   str5, inpstr, 10
        atod    inpstr
        mov     ecx, 0
        lea     ebx, arr
sLoop:  cmp     eax, [ebx]
        je      result
        inc     ecx
        add     ebx, 4
        cmp     ecx, edx
        jge     noRes
        jmp     sLoop
result: dtoa    outstr, ecx
        output  str6, outstr
        jmp     search
noRes:  output  str7, str8
        jmp     search
fin:    mov eax, 0
        ret
_MainProc ENDP
END