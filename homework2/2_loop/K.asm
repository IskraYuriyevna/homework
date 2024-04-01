%include "io.inc"

section .text
global CMAIN
countbinx:    
    push ebp
    mov ebp,esp        
    push ecx
    push ebx
    mov eax,dword[ebp+8]    
    xor ecx,ecx
    jmp .loop
    
.loop:    
    mov ebx,eax
    sub ebx,1
    cmp eax,0
    je .ed
    and eax,ebx
    inc ecx
    jmp .loop
    
.ed:
    mov eax,ecx
    pop ebx
    pop ecx
    pop ebp
    ret

CMAIN:
    GET_UDEC 4,eax
    push eax
    call countbinx
    add esp,4
    PRINT_UDEC 4,eax
    xor eax,eax
    ret
