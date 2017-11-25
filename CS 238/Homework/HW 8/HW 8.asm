; Function Call Stuff - Addie Morrison
; Date:    24 Nov 2017

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
number1 DWORD   ?
number2 DWORD   ?
prompt1 BYTE    "Enter A", 0
prompt2 BYTE    "Enter B", 0
string  BYTE    40 DUP (?)
resLbl  BYTE    "GCD(A,B) is", 0
result  BYTE    11 DUP (?), 0

.CODE
gcd PROC
        push    ebp
        mov     ebp, esp

        mov     esi, [ebp + 8]
        mov     edi, [ebp + 12]
        cmp     esi, edi
        ja      more
        jb      less
        mov     eax, esi
	pop     ebp
        ret     8
more:   sub     esi, edi
	push    esi
	push    edi
        call    gcd
	pop     ebp
        ret     8
less:   sub     edi, esi
	push    esi
	push    edi
        call    gcd
        pop     ebp
        ret     8
gcd ENDP
gcdfast PROC
        cmp     esi, edi
        ja      more
        jb      less
        mov     eax, esi
        ret
more:   sub     esi, edi
        call    gcd
        ret
less:   sub     edi, esi
        call    gcd
        ret
gcdfast ENDP
_MainProc PROC
        input   prompt1, string, 40
        atod    string
        mov     esi, eax

        input   prompt2, string, 40
        atod    string
        mov     edi, eax

        ; Standard, boring, complicated implementation with C style calling
        push    esi
        push    edi
        call    gcd
        
        ; Alternative implementation with the fastcall convention.
        ; Uses registers instead of the stack. Faster, less risk
        ; (though only useful for things that fit into 6 registers)
        ; Which would you rather see in your code?
        call gcdfast

        dtoa    result, eax
        output  resLbl, result

        mov     eax, 0
        ret
_MainProc ENDP
END