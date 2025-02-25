; USER INPUT CODE AND PRINT THE USER INPUT
ORG 0100h

.DATA
A_V DB 65
Z_V DB 90

aa_V DB 97
zz_V DB 122

CHAR DB ? 
COUNT DW 5 

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; USER INPUT      
    MOV AH, 1
    INT 21H      ; STORE USER INPUT INTO AL REGISTER 
    ;SUB AL, 48
    MOV CHAR, AL    ; MOV AL VALUE TO BL 
    
    ; NEW LINE CODE
    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h   
    
    ; MAIN OPERATION
    MOV BL, CHAR
    CMP BL, A_V
    JGE UPPER1
    JMP EXIT
    
    UPPER1:  
        MOV BL, CHAR
        CMP BL, Z_V
        JLE UPPER2
        
        CMP BL, aa_V
        JGE SMALLER1 
        JMP EXIT
        
    UPPER2:
        ;MOV DL, CHAR
        ADD CHAR, 32
        MOV DL, CHAR
        
         MOV CX, 0
          
        PRINT_NEXT:
            INC DL
            INC CX 
            ; USER OUTPUT
            MOV AH, 2
            INT 21H
             
            CMP CX, COUNT
            JL PRINT_NEXT 
              
            ; NEW LINE CODE
            MOV AH, 2
            MOV DL, 0DH
            INT 21h
            MOV DL, 0AH
            INT 21h 
            
            MOV DL, CHAR
            MOV CX, 0     
                    
        PRINT_PREV:
            DEC DL
            INC CX 
            ; USER OUTPUT
            MOV AH, 2
            INT 21H 
            CMP CX, COUNT
            JL PRINT_PREV
         
            JMP EXIT
     
    
    SMALLER1:
        MOV BL, CHAR
        CMP BL, zz_V
        JLE SMALLER2
        JMP EXIT 
        
    SMALLER2:
        ;MOV DL, CHAR
        SUB CHAR, 32
        MOV DL, CHAR
        
         MOV CX, 0
          
        PRINT_NEXT2:
            INC DL
            INC CX 
            ; USER OUTPUT
            MOV AH, 2
            INT 21H
             
            CMP CX, COUNT
            JL PRINT_NEXT2 
              
            ; NEW LINE CODE
            MOV AH, 2
            MOV DL, 0DH
            INT 21h
            MOV DL, 0AH
            INT 21h 
            
            MOV DL, CHAR
            MOV CX, 0     
                    
        PRINT_PREV2:
            DEC DL
            INC CX 
            ; USER OUTPUT
            MOV AH, 2
            INT 21H 
            CMP CX, COUNT
            JL PRINT_PREV2
         
            JMP EXIT
        
    EXIT:
        ; RETURN TO DOS
        MOV AH,4CH
        INT 21H
        
    MAIN ENDP
END MAIN
RET