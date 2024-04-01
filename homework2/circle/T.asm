%include "io.inc"

section .text
global CMAIN
CMAIN:
    xor ecx,ecx
    jmp .loop
        
.loop:
    GET_UDEC 4,eax
    cmp eax,0
    je .end
    mov ebx,eax
    shr eax,5
    shl eax,5
    sub ebx,eax
    add ecx,ebx
    jmp .loop

 .end: 
    PRINT_UDEC 4,ecx
    xor eax,eax
    ret