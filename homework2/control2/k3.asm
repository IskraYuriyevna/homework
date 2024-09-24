%include "io.inc"
section .text
global main
main:
    mov ebp, esp; for correct debugging
    ;write your code here
    GET_UDEC 4,eax
    push eax
    call countbin    
    add esp,4
    PRINT_UDEC 4,eax    
    xor eax,eax
    ret   
    
countbin:
    push ebp
    mov ebp,esp
    mov edx,dword[ebp+8]
    push ebx
    xor ecx,ecx
    jmp .run
    
.run:
    cmp edx,0
    je .stop
    mov ebx,edx
    and ebx,1
    jz .continue
    inc ecx
    sar edx,1
    jmp .run
    
.continue:
    sar edx,1
    jmp .run
    
.stop:
    mov eax,ecx
    pop ebx
    pop ebp
    ret