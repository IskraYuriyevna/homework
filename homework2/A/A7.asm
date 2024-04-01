%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    mov ebx,10
    cdq
    idiv ebx

    PRINT_DEC 4,edx
    xor eax,eax
    ret