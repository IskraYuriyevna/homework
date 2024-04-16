%include 'io.inc'

section .bss
    N equ 20
    a resd N

section .text
global CMAIN
CMAIN:
    mov ebx,0
    mov ecx,N
    push N
    push a
    call read_array
    add esp,2*4
    push N
    push a
    call sort
    add esp,2*4
    push N
    push a
    call print_array
    add esp,2*4
    xor eax,eax
    ret
    
read_array:
    push ebp
    mov ebp,esp
    push edi
    push ebx
    mov edi,dword[ebp+8]
    xor ebx,ebx
    jmp .input

.input:
    GET_DEC 4,[edi+4*ebx]
    inc ebx
    cmp ebx,dword[ebp+12]
    jl .input
    pop ebx
    pop edi
    pop ebp
    ret 
    
sort:
    push ebp
    mov ebp,esp
    push edi
    push ebx
    mov edi,dword[ebp+8]
    
    
    
    
print_array:
    push ebp
    mov ebp,esp
    push edi
    push ebx
    mov edi,dword[ebp+8]
    xor ebx,ebx
    jmp .output
    
.output:
    PRINT_DEC 4,[edi+4*ebx]
    PRINT_CHAR ' '
    inc ebx
    cmp ebx,dword[ebp+12]
    jl .output
    pop ebx
    pop edi
    pop ebp
    ret
