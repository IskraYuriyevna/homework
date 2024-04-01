%include "io.inc"

section .text
global CMAIN
CMAIN:
    jmp .Loop
    
.Loop:
    GET_DEC 4,eax
    cmp eax,0
    je .end
    jl .pr
    jmp .Loop

.pr:
    PRINT_DEC 4,eax
    PRINT_CHAR " "
    jmp .Loop

.end:
    xor eax,eax
    ret