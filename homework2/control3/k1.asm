%include "io.inc"

section .text
global CMAIN
CMAIN:
    xor ecx,ecx
    mov ebx,5
    jmp .loop
    
.loop:
    GET_DEC 4,eax
    cmp eax,0
    je .end
    cdq
    div ebx
    cmp edx,0
    je .inc
    jmp .loop
    
.inc:
    inc ecx
    jmp .loop
    
.end:
    PRINT_DEC 4,ecx
    ret
    
    
    