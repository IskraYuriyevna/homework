%include 'io.inc'

section .bss
N equ 10; Assign the value of variable N to 10
a resd N; Create an array of size N

section .text
global CMAIN

CMAIN:
    xor ebx,ebx; "i"
    xor edx,edx
    mov ecx,N; Loop cycles
    
.input:
    GET_DEC 4,[a+4*ebx]; a[i]
    inc ebx
    loop .input
    xor ebx,ebx
    mov eax,dword[a]; a[0]
    
.Fmax:
    cmp ebx,N
    je .maxout
    mov edi,[a+4*ebx]
    cmp eax,edi
    jl .swpmax
    inc ebx
    jmp .Fmax
    
.swpmax:
    mov eax,edi
    mov edx,ebx
    jmp .Fmax
    
.maxout:
    inc edx
    PRINT_DEC 4,edx
    PRINT_STRING ' '
    PRINT_DEC 4,eax
    PRINT_STRING ' '
    xor ebx,ebx
    xor edx,edx
    mov eax,dword[a]
    
.Fmin:
    cmp ebx,N
    je .minout
    mov esi,[a+4*ebx]
    cmp esi,eax
    jl .swpmin
    inc ebx
    jmp .Fmin
    
.swpmin:
    mov eax,esi
    mov edx,ebx
    jmp .Fmin
            
.minout:
    inc edx
    PRINT_DEC 4,edx
    PRINT_STRING ' '
    PRINT_DEC 4,eax
    xor eax,eax
    ret
    