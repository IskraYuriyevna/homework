%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    GET_UDEC 4,ebx
    push eax
    push ebx
    call mid
    PRINT_UDEC 4,eax
    add esp,8
    xor eax,eax
    ret
   
mid:
    push ebp
    mov ebp,esp
    mov ecx,2
    mov eax,dword[ebp+8]
    add eax,dword[ebp+12]
    cdq 
    idiv ecx
    pop ebp
    ret