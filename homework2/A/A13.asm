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
    imul eax,edx
    imul eax,ecx
    PRINT_DEC 4,eax
    xor eax,eax
    ret

