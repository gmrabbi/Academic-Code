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
        MOV DL, CHAR
        ADD DL, 32
        
        
         MOV CX, 0 
         JMP PRINT_NEXT
         
        SET_Z_TO_a:
            MOV DL, aa_V
            DEC DL
          
        PRINT_NEXT:
            SUB DL, 32
            CMP DL, Z_V
            JE SET_Z_TO_a
            ADD DL, 32
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
              ADD DL, 32 
              MOV CX, 0
              JMP PRINT_PREV  
          
          SET_A_TO_zz_V:
            MOV DL, zz_V
            INC DL        
               
        PRINT_PREV:
            SUB DL, 32
            CMP DL, A_V
            JE SET_A_TO_zz_V 
            ADD DL, 32
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
        MOV DL, CHAR
        SUB DL, 32
        
         MOV CX, 0
         JMP PRINT_NEXT2
                      
      SET_zz_TO_A:
        MOV DL, A_V
        DEC DL
          
        PRINT_NEXT2:
            ADD DL, 32
            CMP DL, zz_V
            JE SET_zz_TO_A
            SUB DL, 32
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
            SUB DL, 32
            MOV CX, 0
            JMP PRINT_PREV2
            
          SET_a_TO_Z_V:
            MOV DL, Z_V
            INC DL           
                    
        PRINT_PREV2:
            ADD DL, 32
            CMP DL, aa_V
            JE SET_a_TO_Z_V
            SUB DL, 32
            
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