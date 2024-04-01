%include "io.inc"

section .text
global CMAIN
CMAIN:
    ;set ecx and ebx to zero
    xor ecx,ecx
    jmp .loop
    
.loop:
    ;outside loop,repeat 7 times
    inc ecx
    cmp ecx,8
    je .end
    GET_UDEC 4,eax
    xor edx,edx
    mov edi,eax
    jmp .jg
    
.jg:
    mov ebx,edi
    and ebx,63
    cmp ebx,31
    je .pr
    jne .loop2
    
.loop2:
    ;inside loop,repeat 5 times
    cmp edi,0
    je .loop
    mov ebx,edi 
    shr edi,1
    and ebx,127
    cmp ebx,62
    je .pr
    jne .loop2

.pr:
    ;print if have 5 continuous 1
    PRINT_UDEC 4,eax
    PRINT_CHAR " "
    jmp .loop

.end:
    xor eax,eax
    ret