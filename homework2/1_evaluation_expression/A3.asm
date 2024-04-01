%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    GET_DEC 4,ebx
    GET_DEC 4,ecx
    PRINT_DEC 4,eax
    PRINT_CHAR "+"
    PRINT_DEC 4,ebx
    PRINT_CHAR "+"
    PRINT_DEC 4,ecx
    PRINT_CHAR "="
    add eax,ebx
    add eax,ecx
    PRINT_DEC 4,eax
    xor eax,eax
    ret