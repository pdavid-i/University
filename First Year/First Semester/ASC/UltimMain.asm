bits 32
global start

import scanf msvcrt.dll
import exit msvcrt.dll
extern scanf, exit
extern function


segment data use32 class=data
    format db '%X',0
    array times 1000 dd 0
    n dd 0
    

segment code use32 public code
start:
    mov edi,0
    push dword format
    push dword n
    push dword array
	call function
    push 0
	call [exit]
