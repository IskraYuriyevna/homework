%include 'io.inc'
section .text
global main
main:
    ;write your code here
    GET_DEC 4,eax
    GET_DEC 4,ebx
    GET_DEC 4,ecx
    cmp eax,ebx
    jg .a
    jng .b
    
.a:
    cmp eax,ecx
    jg .end
    jng .c
    
.b:
    mov eax,ebx
    jmp .a
    
.c:
    mov eax,ecx
    jmp .end
    
.end:    
    PRINT_DEC 4,eax
    xor eax, eax
    ret