%include "io.inc"

section .text
global CMAIN
countbinx:    
    push ebx
    xor ecx,ecx
    jmp .loop
    
.loop:    
    mov ebx,edi
    sub ebx,1
    cmp edi,0
    je .ed
    and edi,ebx
    inc ecx
    jmp .loop
    
.ed:
    mov eax,ecx
    pop ebx
    ret

CMAIN:
    mov ebp, esp; for correct debugging
    GET_UDEC 4,edi
    push ecx
    call countbinx
    pop ecx
    PRINT_UDEC 4,eax
    xor eax,eax
    ret
