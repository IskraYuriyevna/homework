%include "io.inc"
section .bss
    a resd 1
section .text
global CMAIN
CMAIN:
    mov ebp,esp
    mov ebx,2
    mov ecx,0
    GET_UDEC 4,eax
    mov dword[a],eax
.start_loop:
    mov eax,dword[a]
    cmp ebx,eax
    je .finish
    xor edx,edx
    div ebx
    cmp edx,0
    jz .bad
    inc ebx
    jmp .start_loop
.bad:
    inc ecx
    inc ebx
    jmp .start_loop
.finish:
    PRINT_DEC 4,ecx
    
    xor eax,eax
    ret
    