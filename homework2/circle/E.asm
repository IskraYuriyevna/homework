%include "io.inc"
section .text
global main
main:
    ;write your code here
    mov ebx,0
    GET_UDEC 4,eax
    cmp eax,ebx
    ja .loop

.loop:
    mov ebx,eax
    GET_UDEC 4,eax
    cmp eax,0
    je .ed
    cmp eax,ebx
    jae .loop
    jb .na  
    
.na:
    PRINT_UDEC 4,0
    jmp .end
    
.ed:
    PRINT_UDEC 4,1
    jmp .end
    
.end:  
    xor eax, eax
    ret