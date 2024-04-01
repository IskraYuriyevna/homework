%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    mov ebx,eax
    mov ecx,eax
    jmp .loop

.loop:
    GET_DEC 4,eax
    cmp eax,0
    je .end
    cmp eax,ebx
    jg .b
    cmp eax,ecx
    jl .c
    jmp .loop
    
.b:
    mov ebx,eax
    jmp .loop
    
.c:
    mov ecx,eax
    jmp .loop

    
.end: 
    sub ebx,ecx
    PRINT_DEC 4,ebx
    xor eax,eax
    ret