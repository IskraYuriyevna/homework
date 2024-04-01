%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    jmp .loop

.loop:
    xor edx,edx
    mov ebx,10 
    idiv ebx
    cmp eax,0
    je .end
    jmp .loop
    
.end:
    PRINT_UDEC 4,edx
    xor eax,eax
    ret