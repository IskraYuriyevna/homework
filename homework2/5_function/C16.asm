%include "io.inc"

section .text
global CMAIN
CMAIN:
    GET_DEC 4,eax
    push