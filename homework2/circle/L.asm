%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    xor ecx,ecx
    cmp eax,1
    je .r
    jmp .loop
    
    
.loop:
    cmp ecx,eax
    je .b
    mov ebx,ecx
    imul ebx,ebx
    cmp ebx,eax
    je .r
    inc ecx
    jmp .loop 
    
.r:
    PRINT_DEC 4,1
    jmp .end
    
.b:
    PRINT_DEC 4,0
    jmp .end
    

.end:    
    xor eax,eax
    ret