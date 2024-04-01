%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    mov ebx,1
    xor ecx,ecx
    jmp .loop
    
.loop:
    cmp eax,0
    je .end
    mov edx,eax
    and edx,ebx
    cmp edx,0
    jne .inc
    shr eax,1
    jmp .loop

.inc:
    inc ecx
    shr eax,1
    jmp .loop
    
.end:
    PRINT_UDEC 4,ecx
    xor eax,eax
    ret