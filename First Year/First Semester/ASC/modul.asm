bits 32                         
segment code use32 public code
global function


function:
    push dword n
    push formatR
        call [scanf]
        add esp, 4 * 2
        bucla:
        mov eax, [n]
            push dword [n]
            push format
            call [printf]
            add esp, 4 * 2
            push dword n
            push formatR
            call [scanf]
            add esp, 4 * 2
            cmp [n], dword 0
        jne bucla
    ret