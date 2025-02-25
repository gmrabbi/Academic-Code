ORG 100H

.DATA
fstt DB 0
snd DB 0 

input_string DB 'WE aRE DUET STuDeNTs', 0Dh, 0Ah, '$'

.CODE  
PROC MAIN
    MOV AX, @DATA
    MOV DS, AX      
        
    lea dx, input_string 
    mov ah, 09h ;display string function 
    int 21h ;display message 
    
    ;newline
    mov ah, 02h 
    mov dl, 0Dh 
    int 21h 
    mov dl, 0Ah 
    int 21h 
    
    mov cx, 20
    xor si, si
    
    mov si, offset input_string
      
    TOP: 
        cmp [si], 97
        jge snd_test
        and [si], 0dfh 
    next: 
        inc si 
        loop top  
        
    snd_test: 
        cmp [si], 122
        jle check_set
        jmp next
        
   check_set:
            cmp fstt, 0
            jne set_snd
            mov fstt, [si]
            jmp next
            
   set_snd:
        mov snd, [si]
        jmp next
        
        
    lea dx, [si] 
    mov ah, 09h ;display string function 
    int 21h ;display message 
 
    
    
    MOV AH, 4CH
    INT 21H
ENDP MAIN
END MAIN
RET
    
    


