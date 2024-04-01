%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    GET_UDEC 1,cl
    mov esi,-1
    shl esi,cl
    not esi
    mov ecx,eax
    and ecx,esi
    jmp .loop
    
.loop:
    cmp eax,0
    je .end
    mov ebx,eax
    and ebx,esi
    cmp ebx,ecx
    ja .a
    shr eax,1
    jmp .loop
    
.a: 
    mov ecx,ebx
    shr eax,1
    jmp .loop

.end:

    PRINT_DEC 4,ecx
    xor eax,eax
    ret