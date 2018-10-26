bits 32

global start        

import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll
extern exit, scanf, printf    

segment data use32 class=data
    format db '%d',0
    array times 1000 db 0
    n dd 0
    
segment code use32 class=code
    start:
        mov edi,0
        bucla:
        pushad
        push dword n
        push dword format
        call [scanf]
        add esp,4*2
        popad
        mov eax, [n]
        mov [array+edi], eax
        inc edi
        cmp dword[n],0
        je final
        jmp bucla
        
        final:
        push    dword 0      
        call    [exit]
