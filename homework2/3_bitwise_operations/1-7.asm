%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    mov ebx,255
    shl ebx,24
    xor eax,ebx
    PRINT_UDEC 4,eax
    xor eax,eax
    ret
    