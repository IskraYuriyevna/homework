%include "io.inc"

section .text
global CMAIN
CMAIN:
    PRINT_STRING "Hello world!"
    xor eax,eax
    ret