bits 32

global start        
global  n
global rez

import printf msvcrt.dll
import scanf msvcrt.dll
import exit msvcrt.dll
extern exit, scanf, printf    

segment data use32
    format db '%X',0
    format2 db '%X',0
    array times 1000 db 0
    rez dd 0
    n dd 0
    
segment code use32 public code
    start:
        mov edi,0
        bucla:
        pushad
        push dword n
        push dword format
        call [scanf]
        add esp,4*2
        popad
        cmp dword[n],0
        je afis
        
        afis:
        sub edi,4
        mov ecx,edi
        mov edi,0
        bucla2:
        pushad
        mov eax,[array+edi]
        push eax
        push dword format2
        call [printf]
        add esp,4*2
        popad
        cmp ecx,edi
        je final2
        add edi,4
        jmp bucla2
        
        final2:
        push    dword 0      
        call    [exit]
