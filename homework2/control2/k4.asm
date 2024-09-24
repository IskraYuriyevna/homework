%include 'io.inc'
section .text
global main
main:
    mov ebp, esp; for correct debugging
    GET_UDEC 4,eax
    push eax
    call isSquare
    add ebp,4
    PRINT_UDEC 4,eax
    ;write your code here
    xor eax, eax
    ret
    
    
isSquare:
    push ebp
    mov ebp,esp
    mov ebx,dword[ebp+8]
    xor ecx,ecx
    xor eax,eax
    xor edx,edx
    jmp .loop
    
.loop:
    cmp edx,ebx
    jg .out
    mov edx,ecx
    imul edx,edx
    cmp edx,ebx
    je .ge
    inc ecx
    jmp .loop
    
.ge:
    mov eax,1
    jmp .out
    
.out:
    pop ebp
    ret