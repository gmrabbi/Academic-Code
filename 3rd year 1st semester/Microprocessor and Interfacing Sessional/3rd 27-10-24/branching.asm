ORG 100H
.DATA

A DB ?
B DB ?
C DB ?

.CODE
MAIN PROC 
    
    MOV AX, @DATA
    MOV DS, AX
    
    ; INPUT
    MOV AH, 01H
    INT 21H
    MOV A, AL
    
    MOV AH, 01H
    INT 21H
    MOV B, AL
    
    MOV AH, 01H
    INT 21H
    MOV C, AL 
    
    ;NEW LINE 
    MOV AH, 2      
    MOV DL, 0DH;
    INT 21H
    MOV DL, 0AH
    INT 21H
    
    MOV BL, A
    CMP BL, B
    JLE GRATTER
    JMP SMALLER 
    
    
    GRATTER:
        MOV BL, A
        CMP BL, C
        JLE RESULTA
        JGE RESULTC
        JMP EXIT
        
    SMALLER:            
    
        MOV BL, B
        CMP BL, C
        JLE RESULTB
        
        JMP RESULTC 
        
        
    RESULTA:
       MOV DL, A
        ;OUTPUT
        MOV AH, 02H
        INT 21H
        JMP EXIT
        
   RESULTB:
        MOV DL, B
        ;OUTPUT
        MOV AH, 02H
        INT 21H
        JMP EXIT
        
   RESULTC:
        MOV DL, C
        ;OUTPUT
        MOV AH, 02H
        INT 21H
   
    
           
     EXIT:
     
    
    
    
    MAIN ENDP
END MAIN
RET