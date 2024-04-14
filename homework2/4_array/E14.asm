%include 'io.inc'

section .bss
N equ 10
a resd N

section .text
global CMAIN
CMAIN:
    mov ecx,N
    xor ebx,ebx
    jmp .input
    
.input:
    GET_DEC 4,[a+4*ebx]
    inc ebx
    loop .input
    xor ebx,ebx
    jmp .loop

.loop:
    mov eax,dword[a+4*ebx]
    inc ebx
    mov edi,0
    mov ecx,ebx
    jmp .jg
    
.jg:
    cmp ebx,N
    je .end
    cmp ecx,N
    je .loop
    mov edx,dword[a+4*ecx]
    inc ecx
    cmp eax,edx
    jne .jg
    PRINT_DEC 4,eax
    PRINT_STRING " "
    cmp ecx,N
    jl .jg
    
.end:
    xor eax,eax
    ret
    
    
