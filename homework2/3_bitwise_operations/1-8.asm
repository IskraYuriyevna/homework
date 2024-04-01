%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_UDEC 4,esi
    xor ecx,ecx
    xor eax,eax
    jmp .loop
    
.loop:
    GET_UDEC 4,ebx
    xor eax,ebx
    inc ecx
    cmp ecx,esi
    je .end
    jmp .loop
    
.end:    
    PRINT_UDEC 4,eax
    xor eax,eax
    ret