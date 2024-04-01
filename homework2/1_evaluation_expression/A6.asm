%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_UDEC 4,eax
    GET_UDEC 1,cl
    mov ebx,-1
    shl ebx,cl
    xor ebx,-1
    xor eax,ebx
    PRINT_UDEC 4,eax
    xor eax,eax
    ret