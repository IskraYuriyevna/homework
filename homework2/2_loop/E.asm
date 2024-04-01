%include "io.inc"
section .text
global main
main:
    ;write your code here
    GET_DEC 4,eax
    mov ebx,eax
    ja .loop

.loop:
    mov ebx,eax
    GET_DEC 4,eax
    cmp eax,0
    je .ed
    cmp eax,ebx
    jg .loop
    jle .na  
    
.na:
    PRINT_UDEC 4,0
    jmp .end
    
.ed:
    PRINT_UDEC 4,1
    jmp .end
    
.end:  
    xor eax, eax
    ret