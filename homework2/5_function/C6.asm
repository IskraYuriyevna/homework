%include "io.inc"
section .bss
    N equ 7
    a resd N
    
section .text
global CMAIN
CMAIN:
    mov ebp, esp; for correct debugging
    mov ebx,0
    mov ecx,N

.input:
    GET_DEC 4,[a+4*ebx]
    inc ebx
    loop .input
    push N
    push a
    call count3
    add esp,2*4
    PRINT_DEC 4,eax
    xor eax,eax
    ret
    
count3:
    push ebp
    mov ebp,esp
    push edi
    push ebx
    push esi
    xor esi,esi
    mov ecx,3
    xor ebx,ebx
    mov edi,dword[ebp+8]
    
.loop:
    mov eax,dword[edi+4*ebx]
    cdq
    idiv ecx
    cmp edx,0
    jne .end
    inc esi
    
.end:
    inc ebx
    cmp ebx,dword[ebp+12]
    jl .loop
    mov eax,esi
    pop esi
    pop ebx
    pop edi
    pop ebp
    ret