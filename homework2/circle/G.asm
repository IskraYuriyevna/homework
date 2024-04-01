%include"io.inc"
;problem
section .text
global CMAIN
CMAIN:
    mov ecx,0
    mov ebx,10
    GET_UDEC 4,eax
.start_loop:
    cmp eax,0
    jz .finish
    xor edx,edx
    div ebx
    cmp edx,5
    jnz .start_loop
    inc ecx
    jmp .start_loop
.finish:
    PRINT_DEC 4,ecx
    xor eax,eax
    ret
