%include "io.inc"
section .text
global main
main:
    GET_UDEC 4,eax
    xor ecx,ecx
    mov ebx,10
    
.cnt:
    cmp eax,0
    je .end
    cdq
    idiv ebx
    cmp edx,7
    je .inc
    jmp .cnt
    
.inc:
    inc ecx
    jmp .cnt    
    
.end:
    PRINT_UDEC 4,ecx
    xor eax, eax
    ret