%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp,esp
    GET_DEC 4,ecx
    push ecx
    call check
    PRINT_DEC 4,eax
    add esp,4
    xor eax,eax
    ret
    
check:
    push ebp
    mov ebp,esp
    mov ecx,dword[ebp+8]
    push edi
    mov edi,0
    cmp ecx,0
    je .endc
    
.loop:
    inc edi
    mov eax,edi
    imul eax
    cmp eax,ecx
    je .endl 
    jl .loop

.endc:
    mov eax,0
    jmp .end
    
.endl:
    mov eax,1
    
.end:
    pop edi
    pop ebp
    ret