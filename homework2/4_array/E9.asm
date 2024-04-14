%include 'io.inc'

section .bss
N equ 10
a resd N

section .text
global CMAIN

CMAIN:
    mov ebp, esp; for correct debugging
    xor ebx,ebx
    mov ecx,N
    jmp .input

.input:
    GET_DEC 4,[a+4*ebx];a[i]
    inc ebx
    loop .input    
    mov eax,dword[a+4*ebx]
    jmp .ror
    
.ror:
    dec ebx
    mov ecx,dword[a+4*ebx]
    inc ebx
    mov dword[a+4*ebx],ecx
    dec ebx
    cmp ebx,0
    jne .ror
    mov dword[a],eax
    jmp .out
    
.out:
    mov eax,dword[a+4*ebx]
    PRINT_DEC 4,eax
    PRINT_CHAR ' '
    inc ebx
    cmp ebx,10
    je .end
    jmp .out

.end:
    xor eax,eax
    ret
    