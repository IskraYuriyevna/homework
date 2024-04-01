%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4,eax
    mov esi,eax
    mov ecx,1
    xor edi,edi
    jmp .loop
    
.loop:
    inc ecx
    mov eax,esi
    cmp ecx,eax
    je .end
    mov ebx,ecx
    xor edx,edx
    div ebx
    cmp edx,0
    je .p
    jmp .loop
    
.p:
    inc edi
    jmp .loop
    
.end:
    PRINT_DEC 4,edi
    
    xor eax,eax
    ret 