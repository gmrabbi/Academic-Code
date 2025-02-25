include 'emu8086.inc'
org 0100h
.data
    max db 0
    count db ?
    hold db ?
.code       
main proc
    mov ax,@data
    mov ds,ax
    print "ENTER A STKING OF CAPITAL LETTERS: "
    mov ah,1
    int 21h
    
    Set:
        mov count,0       
        mov cl,al
        mov bl,al
    
    Repeat:
        
         
        ;carriage return
        cmp al,13
        je pre_output
        
        cmp al,bl
        jne Update
        
        inc bl
        inc count
        mov ah,1
        int 21h
        
        jmp Repeat
        
        
        
        
    Update:  
        mov bl,max
        cmp bl,count
        jl max_update
        jmp Set
        
        
    max_update:
        mov bl,count
        mov max,bl
        mov hold,cl
        jmp Set
    Pre_Output:
        mov bl,max
        cmp bl,count
        jg Output
        mov bl,count
        mov max,bl
        mov hold,cl
        
    Output:
        mov cl,max
        mov ah,2
        mov dl,10
        int 21h
        mov dl,13
        int 21h
        print "THE LONGEST CONSECUTIVELY INCREASING STRING IS: " 
        Looping:
            mov ah,2
            mov dl,hold
            int 21h
            inc hold
            loop Looping
    
    exit:
        mov ah,4ch
        int 21h
        main endp
end main
ret