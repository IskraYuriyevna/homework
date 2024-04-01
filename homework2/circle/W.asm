%include "io.inc"

section .text
global CMAIN
CMAIN:
    jmp .loop
    
.loop:
    GET_UDEC 4,eax
    cmp eax,0
    je .end
    mov ebx,eax
    shl ebx,28
    shr ebx,28
    mov ecx,eax
    shr ecx,28
    xor ebx,ecx
    cmp ebx,0
    je .pr
    jmp .loop

.pr:
    PRINT_UDEC 4,eax
    PRINT_CHAR " "
    jmp .loop

.end:
    xor eax,eax
    ret