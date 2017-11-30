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
        mov     ebp, esp	; Set the base pointer to track the stack frame for this function
        push    esi		; Backup ESI and EDI
        push    edi		; (since we're using them here)
        mov     edi, [ebp + 8]	; Skip over the push ebp and implicit push esi from the call (param 2)
        mov     esi, [ebp + 12]	; param 1

        cmp     esi, edi	; Comparison thing
        ja      more		; A > B
        jb      less		; A < B
        mov     eax, esi	; A = B
        jmp     done		; if A=B, we're done and can ret
more:   sub     esi, edi	; A-=B
	jmp     recurse		; and then call gcd again with the new value of a
less:   sub     edi, esi	; B-=A
recurse:push    esi		; Push A and B
        push    edi		; onto the stack as params for the new call
        call    gcd		; (do the call thing)
done:   pop     edi             ; Restore ESI and EDI
        pop     esi		; (from any changes we made to them
        mov     esp, ebp	; Restore the stack frame to where it was
        pop     ebp		; Enter the old stack frame
	ret     8		; And ret, removing the two params from the stack (esp+=8 after the ret)
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
