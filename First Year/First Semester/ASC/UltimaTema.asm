bits 32

global bucla      
import exit msvcrt.dll
import scanf msvcrt.dll
extern scanf    

;segment data use32 class=data
 ;   format db '%X',0
  ;  array times 1000 dd 0
   ; n dd 0
    
;segment code use32 class=code
    ;start:
        ;esp = format
        ;esp + 4 =  n
        ;esp + 8 = array
       ; mov edi,0
        bucla:
        push dword [esp+8];push dword n
        push dword [esp+4];push dword format
        call [scanf]
        add esp,4*2
        mov ebx, [esp+12]
        mov eax, [esp + 8]
        mov [ebx + edi], eax; saving the number 
        inc edi
        inc edi
        inc edi
        inc edi
        cmp dword[esp+8],0
        jne bucla
        ret 12