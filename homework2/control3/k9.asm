%include "io.inc"

section .data
    s1 db '%d',0
    s2 db '%d @ %p\n',0

section .text
global CMAIN
CMAIN:
    push ebp
    mov ebp,esp
    and esp,~15
    
    call f
    
    mov esp,ebp
    pop ebp
    xor eax,eax
    ret
    
f:
    push ebp
    mov ebp,esp
    sub esp,24
    
    lea eax,[ebp-4]
    mov dword[esp+4],eax
    mov dword[esp],s1
    call scanf
    
    lea eax,[ebp-4]
    mov dword[esp+8],eax
    
    mov eax,dword[ebp-4]
    mov dword[esp+4],eax
    
    mov dword[esp],s2
    call printf
    
    add esp,24
    pop ebp
    ret