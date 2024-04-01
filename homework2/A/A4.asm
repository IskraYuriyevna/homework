%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    GET_DEC 4,ebx
    GET_DEC 4,ecx
    mov edx,eax

    PRINT_DEC 4,edx
    PRINT_CHAR '+'
    PRINT_DEC 4,ebx
    PRINT_CHAR '+'
    PRINT_DEC 4,ecx
    PRINT_CHAR '='
    add eax,ebx
    add eax,ecx
    PRINT_DEC 4,eax

    NEWLINE
    PRINT_DEC 4,edx
    PRINT_CHAR '*'
    PRINT_DEC 4,ebx
    PRINT_CHAR '*'
    PRINT_DEC 4,ecx
    PRINT_CHAR '='
    imul edx,ebx
    imul edx,ecx
    mov eax,edx
    PRINT_DEC 4,eax

    xor eax,eax
    ret