%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    GET_DEC 4,ecx
    GET_DEC 4,edx
    add eax,ecx
    add eax,edx
    
    mov ebx,3
    cdq
    idiv ebx

    PRINT_DEC 4,eax
    xor eax,eax
    ret
