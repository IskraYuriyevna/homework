%include 'io.inc'
section .rodata
    s1 db '%d',0
section .bss
section .text
global main
main:
    push ebp
    mov ebp,esp
    and esp,~15
    sub esp,16
    
    mov dword[esp],s1
    lea eax,[ebp-4]
    mov dword[esp+4],eax
    call scanf
 
    lea eax,[ebp-8]
    mov dword[esp+4],eax
    call scanf
    
    mov eax,dword[ebp-4]
    add eax,dword[ebp-8]
    sar eax,1
    mov dword[esp+4],eax
    call printf
    
    mov esp,ebp
    pop ebp
    xor eax, eax
    ret