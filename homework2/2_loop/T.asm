%include "io.inc"

section .text
global CMAIN
CMAIN:
    xor ecx,ecx
    mov edx,-1
    shl edx,5
    not edx
    jmp .loop  
    
.loop:
    GET_UDEC 4,eax
    cmp eax,0
    je .end
    and eax,edx
    add ecx,eax   
    jmp .loop

 .end: 
    PRINT_UDEC 4,ecx
    xor eax,eax
    ret