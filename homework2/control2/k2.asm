%include 'io.inc'

section .bss
N equ 12
a resd N

section .text
global CMAIN
CMAIN:
    mov ebx,0
    mov ecx,N
    
.input:
    GET_DEC 4,[a+ebx*4]
    inc ebx
    loop .input
    mov ecx,11
    mov eax,dword[a+4*ebx-4]
    mov edx,dword[a+4*ebx-8]
    mov esi,dword[a+4*ebx-12]
    mov edi,dword[a+4*ebx-16]
    jmp .ror
    
.ror:
    mov ebx,dword[a+4*ecx-16]
    mov dword[a+4*ecx],ebx
    sub ecx,1
    cmp ecx,3
    jne .ror
    mov [a],edi
    mov [a+4],esi
    mov [a+8],edx
    mov [a+12],eax
    xor ebx,ebx
    mov ecx,N
    jmp .out

.out:
    PRINT_DEC 4,[a+ebx*4]
    PRINT_CHAR ' '
    inc ebx
    sub ecx,1
    cmp ecx,0
    jne .out
    xor eax,eax
    ret