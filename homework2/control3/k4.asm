%include "io.inc"

section .text
global main
main:
    mov ebp, esp; for correct debugging
    GET_UDEC 4,eax
    push eax
    call is2pow
    add esp,4
    PRINT_UDEC 4,eax
    xor eax, eax
    ret
    
is2pow:
    push ebp
    mov ebp,esp
    mov eax,dword[ebp+8]
    cmp eax,1
    je .yes
    mov ecx,2
    cdq 
    idiv ecx
    cmp edx,0
    je .yes
    mov eax,0
    pop ebp
    ret
    
.yes:
    mov eax,1
    pop ebp
    ret
    
    
    ;write your code here
    
    
    
