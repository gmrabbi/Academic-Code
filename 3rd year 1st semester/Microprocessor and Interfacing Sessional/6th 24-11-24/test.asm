org 100h 

.DATA ; Data segment starts 
message db 'this is a9 message:$' ;1-D array for  string 

.CODE ; Code segment starts 
MAIN PROC 
    mov ax, @DATA 
    mov ds, ax 
 
    lea dx, message 
    mov ah, 09h ;display string function 
    int 21h ;display message 
    
    mov ah, 02h 
    mov dl, 0Dh 
    int 21h 
    mov dl, 0Ah 
    int 21h 
    
    mov cx, 17 
    xor si, si
     
    TOP: 
        cmp message[si],' ' 
        je next  
        
        cmp message[si],0
        jge lower1
        ;jmp next
        ; cond:
        ;and message[si], 0dfh 
        sub message[si], 32
    next: 
        inc si 
        loop top
        jmp print
        
    lower1:
        cmp message[si], 9
        jle next
 
    print:
    lea dx, message 
    mov ah, 09h ;display string function 
    int 21h ;display message   
    
    mov ah, 4ch 
    int 21h 

MAIN ENDP 
END MAIN 
RET 