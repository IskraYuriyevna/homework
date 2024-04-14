%include 'io.inc'

section .bss
N equ 10
a resd N

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx,N
    xor ebx,ebx
    xor esi,esi
    xor edi,edi
    jmp .input
    
.input:
    GET_DEC 4,[a+ebx*4]
    inc ebx
    loop .input
    xor ebx,ebx
    jmp .outloop

.outloop:
    cmp ebx,N-1
    je .end
    mov eax,dword[a+4*ebx]
    mov edx,ebx
    inc ebx
    xor ecx,ecx
    jmp .inloop

.inloop:
    cmp edx,N
    je .endinloop
    inc edx
    cmp eax,dword[a+4*edx]
    jne .inloop
    inc ecx
    cmp edx,N
    jne .inloop

.endinloop:
    cmp esi,ecx
    jge .returnout
    mov esi,ecx
    mov edi,eax
    jmp .returnout

.returnout:
    cmp ebx,N
    jl .outloop

.end:
    PRINT_DEC 4,edi
    xor eax,eax
    ret