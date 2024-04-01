%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    mov ebx,10
    cdq
    idiv ebx
    mov ecx,edx
    cdq
    idiv ebx
    add ecx,edx
    add eax,ecx
    PRINT_DEC 4,eax
    xor eax,eax
    ret