bits 32 ; assembling for the 32 bits architecture

; declare the EntryPoint (a label defining the very first instruction of the program)
global start        

; declare external functions needed by our program
extern exit, fopen, fread, fclose, scanf, printf               ; tell nasm that exit exists even if we won't be defining it
import exit msvcrt.dll    ; exit is a function that ends the calling process. It is defined in msvcrt.dll
import fopen msvcrt.dll                          ; msvcrt.dll contains exit, printf and all the other important C-runtime specific functions
import fclose msvcrt.dll
import fread msvcrt.dll
import scanf msvcrt.dll
import printf msvcrt.dll
; our data is declared here (the variables needed by our program)
segment data use32 class=data
    nume db "ana.txt", 0
    text times 100 db 0
    handle dd 0
    n dd 0
    car db 0
    modR db "r", 0
    format db "%c", 0
    len equ 100
    read db "%d", 0
; our code starts here
segment code use32 class=code
    bucla1:
        mov esi, text
        mov ecx, [n]
        mov ebx, text ; cond de iesire
        add ebx, eax ;comparam adresele
        add esi, ecx ; umrmatorul din sir
        
        do:
            mov edx, 0
            dec esi
            mov dl, [esi]
            inc esi
            pushad
            push edx
            push format
            call [printf]
            add esp, 4 * 2 ; afisam
            popad
            
            mov edx, esi
            cmp edx, ebx
            jge et ; daca am sarit de ultima adresa iesim
            add esi, ecx ;urmatorul din sir
            jmp do
        
    start:
        push n
        push read
        call [scanf]
        add esp, 4 * 2 ;read n
        
        push modR
        push nume
        call [fopen]
        add esp, 4 * 2 ; open file
        
        mov [handle], eax
        
        et:
            
            push dword [handle]
            push len
            push 1
            push text
            call [fread] ;read the text
            add esp, 4 * 4
            cmp eax, 0;if no text fin
            je fin
            jmp bucla1
 
        fin:
        push dword [handle];close
        call [fclose]
        add esp, 4
        ; exit(0)
        push    dword 0      ; push the parameter for exit onto the stack
        call    [exit]       ; call exit to terminate the program
