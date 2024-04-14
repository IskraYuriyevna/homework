%include 'io.inc'

section .bss
N equ 10
a resd N
b resd N
c resd N

section .text
global CMAIN
CMAIN:
    mov ecx,N
    mov ebx,0
    mov esi,0
    mov edi,0
    jmp .input

.input:
    GET_DEC 4,[a+4*ebx]
    inc ebx
    loop .input
    xor ebx,ebx
    jmp .loop
    
.loop:
    cmp ebx,N
    je .endloop
    mov eax,dword[a+4*ebx]
    inc ebx
    cmp eax,0
    je .loop
    jg .grt
    jl .sml
    
.grt:
    mov dword[b+4*esi],eax
    inc esi
    jmp .loop
    
.sml:
    mov dword[c+4*edi],eax
    inc edi
    jmp .loop
    
.endloop:
    xor ebx,ebx
    xor ecx,ecx
    jmp .grtout

.grtout:
    cmp esi,0
    je .smlout
    PRINT_DEC 4,[b+4*ebx]
    inc ebx
    PRINT_STRING " "
    dec esi
    cmp esi,0
    jne .grtout
    
.smlout:
    cmp edi,0
    je .end
    PRINT_DEC 4,[c+4*ecx]
    inc ecx
    PRINT_STRING " "
    dec edi
    cmp edi,0
    jne .smlout
    
.end:
    xor eax,eax
    ret