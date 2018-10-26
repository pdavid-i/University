bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit 
extern fopen
extern fclose
extern printf     
extern scanf
extern fprintf
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import printf msvcrt.dll
import scanf msvcrt.dll         ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
        nr_vocale dd 0
        mod_acces db "w",0
        nume_fisier db "output.txt",0
        format_citire db "The number is=",0
        format_int db "%d",0
        lungime_cuv dd 0
        format_string db "%s",0
        format db '%c',0
        descriptor dd -1
        array times 1000 db 0
        n dd 0
        var dd 0
        
; our code starts here
segment code use32 class=code
    start:
        call citesc_numar
        call citesc_sir
        call deschid_fisier
        call deschid_fisier
        call scriere_in_fisier
        call inchid_fisier
        call final

    citesc_numar:
        push dword format_citire
        call [printf]
        add esp, 4*1
        push dword n
        push dword format_int
        call [scanf]
        add esp, 4*2
        ret
    
    citesc_sir:
        mov edi,0
        bucla:
        push dword var
        push dword format
        call [scanf]
        add esp,4*2
        ;pushad
        ;push dword var
        ;call [printf]
        ;add esp, 4
        ;popad
        mov eax, [var]
        mov [array+edi], eax
        inc edi
        cmp dword[var],"#"
        je final
        jmp bucla
        stop:
         ret
    
    
    deschid_fisier:
        push dword mod_acces     
        push dword nume_fisier
        call [fopen]
        add esp, 4*2
        mov [descriptor], eax 
        ;cmp eax, 0
        ;je final
        ret
    
    scriere_in_fisier:
        push dword array
        push dword [descriptor]
        call [fprintf]
        add esp, 4*2
        ret
    
    inchid_fisier:
        push dword [descriptor]
        call [fclose]
        add esp, 4
        ret
    
   ; verific_vocale:
    ;    mov nr_vocale, 0
     ;   mov ecx, lungime_cuv
      ;  parcurg_cuv:
            
            
    
    increment_vocale:
        add dword [nr_vocale], 1
    
    final:
        push    dword 0      
        call    [exit]