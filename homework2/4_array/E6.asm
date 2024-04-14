%include 'io.inc'

section .bss
N equ 12
a resd N

section .text
global CMAIN

CMAIN:
    mov ebp, esp; for correct debugging
    xor ebx,ebx
    xor eax,eax
    mov ecx,N
    jmp .input

.input:
    GET_DEC 4,[a+4*ebx]
    add eax,dword[a+4*ebx]
    inc ebx
    loop .input
    xor edx,edx
    mov ecx,N
    div ecx
    PRINT_DEC 4,eax
    xor eax,eax
    ret