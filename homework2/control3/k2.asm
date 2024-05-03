%include 'io.inc'
section .bss
N equ 10
a resq N

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx,N
    xor ebx,ebx
    jmp .input
    
.input:
    GET_DEC 4,eax
    mov dword[a+4*ebx],eax
    inc ebx
    loop .input
    xor ebx,ebx
    xor ecx,ecx
    mov eax,dword[a]
    jmp .fmin
    
.fmin:
    cmp ebx,10
    je .endloop
    cmp eax,dword[a+4*ebx]
    jg .swp
    inc ebx
    jmp .fmin

.swp:
    mov eax,dword[a+4*ebx]
    mov ecx,ebx
    inc ebx
    jmp .fmin

.endloop:
    mov edx,dword[a+36]
    mov dword[a+36],eax
    mov dword[a+4*ecx],edx
    mov ecx,N
    xor ebx,ebx
    jmp .out
    
.out:
    cmp ebx,10
    je .end
    mov eax,dword[a+4*ebx]
    PRINT_DEC 4,eax
    PRINT_STRING " "
    inc ebx
    jmp .out
    
.end:
    xor eax, eax
    ret