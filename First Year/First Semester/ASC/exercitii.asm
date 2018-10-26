bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
extern printf, scanf, fopen, fclose, fprintf, fread, WinExec, remove, Sleep
import printf msvcrt.dll
import scanf msvcrt.dll
import fopen msvcrt.dll
import fclose msvcrt.dll
import fprintf msvcrt.dll
import fread msvcrt.dll
import WinExec kernel32.dll
import remove msvcrt.dll
import Sleep kernel32.dll

; our data is declared here (the variables needed by our program)
segment data use32 class=data
    ; ...
    nume_input times 100 db 0
    nume_output db "script.cmd",0
    script db "start chrome.exe https://www.facebook.com/",0
    cmd db "",0
    pointer_input dd 0
    pointer_output dd 0
    read db "r",0
    write db "w",0
    format db "%d",0
    formats db "%s",0
    file_equ db "file name:",0
    buffer times 8192 db 0

; our code starts here
segment code use32 class=code
    start:
        ; ...
        ;call citeste
        
        push write
        push nume_output
        call [fopen]
        add esp,8
        cmp eax, 0
        jz final
        mov [pointer_output], eax
        
        push script
        push dword[pointer_output]
        call [fprintf]
        add esp, 8
        
        push dword[pointer_output]
        call [fclose]
        
        push dword 2
        push nume_output
        call [WinExec]
        add esp,8
        
        push dword 100
        call [Sleep]
        
        push nume_output
        call [remove]
        
        final:
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program

    
    citeste:
        push dword file_equ
        call [printf]
        add esp, 4
        
        push dword script
        push dword formats
        call [scanf]
        add esp, 4*2
    ret
    
    
