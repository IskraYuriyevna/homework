%include 'io.inc'

section .bss
N equ 10
a resd N

section .text
global CMAIN

CMAIN:
    mov ebp, esp; for correct debugging
    xor ebx,ebx
    mov ecx,N
    jmp .input

.input:
    GET_DEC 4,[a+4*ebx];a[i]
    inc ebx
    loop .input
    mov ecx,N; gap
    shr ecx,1; gap= len>>1
    jmp .sort
    
.sort:  ;loop 1
    cmp ecx,0
    jle .end; gap>0
    mov ebx,ecx;i=gap
    jmp .temp
    
.temp:  ;loop 2
    cmp ebx,N
    jge .endtemp;i < len
    mov esi,[a+4*ebx];temp = arr[i]
    mov edx,ebx
    sub edx,ecx;j = i-gap
    jmp .swp

.endtemp:      ; end loop 2
    shr ecx,1;gap >>=1
    jmp .sort
    
.swp:   ;loop 3
    cmp edx,0
    jge .cparr ;j>=0
    jl .endswp
    
.cparr: ;loop 3
    cmp [a+4*edx],esi
    jle .endswp; arr[j]>temp
    mov edi,ecx;
    add edi,edx;j+gap
    mov eax,dword[a+4*edx]
    mov dword[a+4*edi],eax;a[j+gap]=a[j]
    sub edx,ecx; j-=gap
    jmp .swp
    
.endswp: ;end loop 3
    mov edi,ecx;
    add edi,edx;j+gap
    mov dword[a+4*edi],esi;
    inc ebx;i++
    jmp .temp
    
.end:
    mov eax,dword[a+32]; a[8]
    add eax,dword[a+36];a[8]+a[9]
    PRINT_DEC 4,eax
    xor eax,eax
    ret
    
    