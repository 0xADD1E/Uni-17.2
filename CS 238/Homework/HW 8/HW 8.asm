; Function Call Stuff - Addie Morrison
; Date:    24 Nov 2017

.586
.MODEL FLAT

INCLUDE io.h

.STACK 4096

.DATA
prompt1 BYTE    "Enter A", 0
prompt2 BYTE    "Enter B", 0
string  BYTE    11 DUP (?)
resLbl  BYTE    "GCD(A,B) is", 0
result  BYTE    11 DUP (?), 0

.CODE
gcd PROC
        push    ebp             ; Stack Frame Things
        mov     ebp, esp
        push    esi
        push    edi
        mov     edi, [ebp + 8]
        mov     esi, [ebp + 12]

        cmp     esi, edi
        ja      more
        jb      less
        mov     eax, esi
        jmp     done
more:   sub     esi, edi
	jmp     recurse
less:   sub     edi, esi
recurse:push    esi
        push    edi
        call    gcd
done:   pop     edi             ; Stack Frame Cleanup
        pop     esi
        mov     esp, ebp
        pop     ebp
	ret     8
gcd ENDP
_MainProc PROC
        input   prompt1, string, 40
        atod    string
        mov     ebx, eax

        input   prompt2, string, 40
        atod    string

        push    ebx
        push    eax
        call    gcd

        dtoa    result, eax
        output  resLbl, result

        mov     eax, 0
        ret
_MainProc ENDP
END