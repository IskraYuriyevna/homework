%include "io.inc"

section .text
global CMAIN
CMAIN:
    ;set ecx and ebx to zero
    xor ecx,ecx
    jmp .loop
    
.loop:
    ;outside loop,repeat 7 times
    inc ecx
    cmp ecx,8
    je .end
    GET_UDEC 4,eax
    xor edx,edx
    mov edi,eax
    jmp .loop2
    
.loop2:
    ;inside loop,repeat 5 times
    cmp edi,0
    je .loop
    mov ebx,edi 
    and ebx,1
    cmp ebx,0
    je .clr
    inc edx
    cmp edx,5
    je .jg
    jne .ctn
    
.ctn:
    shr edi,1
    jmp .loop2
    
.clr:
    xor edx,edx
    shr edi,1
    jmp .loop2
    
.jg:
    shr edi,1
    and edi,1
    cmp edi,0
    je .pr
    jne .loop

.pr:
    ;print if have 5 continuous 1
    PRINT_UDEC 4,eax
    PRINT_CHAR " "
    jmp .loop

.end:
    xor eax,eax
    ret