%include 'io.inc'

section .bss
    N equ 8
    a resd N
    
section .text
global CMAIN
CMAIN:
    mov ebx,0
    mov ecx,N
    jmp .input
    
.input:
    GET_DEC 4,[a+4*ebx]
    inc ebx
    loop .input
    push N
    push a
    call sum
    add esp,2*4
    PRINT_DEC 4,eax
    xor eax,eax
    ret
    
sum:
    push ebp
    mov ebp,esp
    push esi
    push edi
    push ebx
    mov esi,0
    mov edi,dword[ebp+12]
    sub esi,1
    sub dword[ebp+12],4
    mov eax,0
    
.loop:
    mov ecx,dword[ebp+8]
    mov edx,dword[ecx+4*esi]
    mov ebx,dword[ecx+4*edi]
    imul edx,ebx
    add eax,edx
    inc esi
    dec edi
    cmp esi,dword[ebp+12]
    jne .loop
    add eax,eax
    
    pop ebx
    pop edi
    pop esi
    pop ebp
    ret