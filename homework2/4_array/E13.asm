%include 'io.inc'

section .bss
N equ 10
a resd N
b resd N

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ecx,N
    xor ebx,ebx
    jmp .input
    
.input:
    GET_DEC 4,[a+4*ebx]
    inc ebx
    loop .input
    xor ebx,ebx
    mov ecx,10
    jmp .outloop
    
.outloop:
    cmp ebx,N
    je .endoutloop
    mov eax,dword[a+4*ebx]
    jmp .inloop
    
.inloop:
    cdq
    div ecx
    cdq
    div ecx
    cmp edx,0
    je .rt
    jne .endinloop
    
.rt:
    mov eax,dword[a+4*ebx]
    mov dword[b+4*ebx],eax
    jmp .endinloop

.endinloop:
    inc ebx
    jmp .outloop
    
.endoutloop:
    xor ebx,ebx
    jmp .out
    
.out:
    cmp ebx,N
    je .end
    cmp dword[b+4*ebx],0
    je .skip
    PRINT_DEC 4,[b+4*ebx]
    PRINT_STRING " "
    
.skip:
    inc ebx
    jmp .out
    
.end:
    xor eax,eax
    ret