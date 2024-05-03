%include 'io.inc'

section .text
global CMAIN
CMAIN:
    
    
.loop: 
    GET_DEC 4,eax
    mov ebx,eax
    cmp eax,0
    je .end
    push eax
    call check
    add esp,4
    cmp eax,0
    je .loop
    PRINT_DEC 4,ebx
    jmp .loop
    
check:
    push ebp
    mov ebp,esp
    mov eax,[esp+8]
    cmp eax,
    
.loop:
    
    
    
    ret
    



.end:
    xor eax, eax
    ret