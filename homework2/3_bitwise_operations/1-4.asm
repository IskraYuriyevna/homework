%include "io.inc"
section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    GET_UDEC 1,cl
    mov ebx,eax
    shr ebx,cl
    shl ebx,cl
    sub eax,ebx
    PRINT_DEC 4,eax
    xor eax,eax
    ret