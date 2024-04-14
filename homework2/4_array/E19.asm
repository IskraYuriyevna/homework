%include 'io.inc'

section .bss
N equ 100
a resd N

section .text
global CMAIN

CMAIN:
    mov ebx,10
    xor ecx,ecx
    GET_DEC 4,eax
    
.div:
    cdq
    idiv ebx
    mov dword[a+ecx*4],edx
    inc ecx
    cmp eax,0
    jne .div
    dec ecx
    jmp .out
    
.out:
    PRINT_DEC 4,[a+ecx*4]
    PRINT_STRING " "
    dec ecx
    cmp ecx,-1
    jne .out
    xor eax,eax
    ret