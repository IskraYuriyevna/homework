%include 'io.inc'

section .bss
N equ 100
a resd N
b resd N
c resd 1
d resd 1

section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ebx,10
    xor ecx,ecx
    GET_DEC 4,eax
    jmp .div
    
.div:
    cdq
    idiv ebx
    mov dword[a+4*ecx],edx
    inc ecx
    cmp eax,0
    jne .div
    mov dword[c],ecx
    mov dword[d],ecx
    dec dword[d]
    xor ebx,ebx
    xor ecx,ecx
    xor edx,edx
    jmp .loop

.loop:
    cmp ecx,dword[c]
    je .end
    mov eax,dword[a+4*ecx]
    mov ebx,ecx
    inc ecx
    jmp .swp
    
.swp:
    cmp ebx,dword[d]
    je .rt
    inc ebx
    cmp eax,dword[a+4*ebx]
    jge .swp
    mov edi,eax
    mov eax,dword[a+4*ebx]
    mov dword[a+4*edx],edi
    cmp ebx,dword[d]
    jne .swp
    
.rt:
    mov dword[b+4*edx],eax
    inc edx
    jmp .loop

.end:
    mov ecx,edx
    xor ebx,ebx
    jmp .print

.print:
    PRINT_DEC 4,[b+4*ebx]
    inc ebx
    loop .print
    xor eax,eax
    ret