bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fread, fprintf, fopen, fclose, scanf              
import exit msvcrt.dll    
import fread msvcrt.dll    
import fclose msvcrt.dll    
import fopen msvcrt.dll    
import fprintf msvcrt.dll    
import scanf msvcrt.dll    
                          

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    numeFisier times 31 db 0
    output db "output.txt", 0
    access_mode1 db "w", 0
    access_mode2 db "r", 0
    descriptor1 dd 0
    descriptor2 dd 0
    charSpecial db 0
    text times 100 db 0
    n db 0
    format1 db "%s", 0
    format2 db "%c", 0
    format3 db "%i", 0
    cuv times 31 db 0
    spatiu db ' ', 0
; our code starts here
segment code use32 class=code
    et3:
        mov al, [spatiu]
        mov [edi], al
        inc edi
        jmp et4
    et4:
        mov al, [esi]
        inc esi
        dec ecx
        cmp al, [spatiu]
        jne et5
        jmp bucla2
    et5:
        mov al, [esi]
        inc esi
        dec ecx
        cmp al, [spatiu]
        je bucla2
        jmp et5
    print:
        mov bl, [n]
        mov edi, cuv
    loop2:
        mov al, [esi]
        cmp al, [spatiu]
        je addCharSpecial
        mov [edi], al
        inc edi
        dec bl
        inc esi
        cmp bl, 0
        je et3
        jmp bucla2
        
    addCharSpecial:
        inc esi
    et2:
        mov al, [charSpecial]
        mov [edi], al
        inc edi
        dec bl
        cmp bl, 0
        jg et2
        mov al, [spatiu]
        mov [edi], al
        inc edi
        jmp bucla2
    start:
        ; scanf(%s, &numeFisier)
        push dword numeFisier
        push dword format1
        call [scanf]
        add esp, 4*2
        
        ; scanf(%c, &charSpecial)
        push dword charSpecial
        push dword format1
        call [scanf]
        add esp, 4*2
        
        ; scanf(%d, &n)
        push dword n
        push dword format3
        call [scanf]
        add esp, 4*2
        
        ;fopen(numeFisier, access_mode1)
        push dword access_mode2
        push dword numeFisier
        call [fopen]
        cmp eax, 0
        je final
        mov [descriptor1], eax
        
        ;fopen(output, access_mode2)
        push dword access_mode1
        push dword output
        call [fopen]
        cmp eax, 0
        je final
        mov [descriptor2], eax
        
    bucla1:    
        ;fread(text, 1, 200, descriptor1)
        push dword [descriptor1]
        push dword 200
        push dword 1
        push dword text
        call [fread]
        add esp, 4*4
        
        mov ecx, eax
        jecxz close 
        
        mov esi, text
        mov ebx, 0
        dec ecx
        jmp et1
        
    bucla2:
        
        dec ecx
        cmp bl, 0
        jg loop2
        
        pushad
        ;fprintf(descriptor2, cuv)
        push dword cuv
        push dword [descriptor2]
        call [fprintf]
        add esp, 4*2
        popad
    et1:
        cmp ecx, 0
        jge print
        jmp bucla1
        
    
    close:
        ;fclose(descriptor1)
        push dword [descriptor1]
        call [fclose]
        add esp, 4*1
        
        ;fclose(descriptor2)
        push dword [descriptor2]
        call [fclose]
        add esp, 4*1
        
    final:
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
