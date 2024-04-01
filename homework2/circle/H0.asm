%include "io.inc"

section .text
global CMAIN
CMAIN:
    mov ebp,esp
    GET_UDEC 4,eax
    xor ebx,ebx
    mov ecx,ebx

.start_loop:
    GET_UDEC 4,eax
    cmp eax,0
    je .finish
    cmp ecx,eax
    jge .next
    mov ecx,eax

.next
    cmp ebx,eax
    jle .start_loop
    mov ebx,eax
    jmp .start_loop

.finish
    sub ecx,ebx
    PRINT_UDEC 4,ecx

    xor eax,eax
    ret