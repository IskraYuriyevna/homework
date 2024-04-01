%include "io.inc"

section .text
global CMAIN
CMAIN:
    PRINT_STRING "Let's"
    NEWLINE
    PRINT_STRING "  go"
    NEWLINE
    PRINT_STRING "   to walk"
    xor eax,eax
    ret