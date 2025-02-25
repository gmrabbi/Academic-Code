ORG 100H

.DATA
N DB ? ; 0-9 and A TO F 
INP_MSG DB "ENTER A HEX DIGIT:$"
INV_MSG DB "ILLEGAL CHARACTER - ENTER 0..9 OR A..F:$" 
CH_MSG DB 0AH, 0DH, "DO YOU WANT TO DO IT AGAIN? $" 
OUT_MSG DB 0AH, 0DH, "IN DECIMAL IS IT $"


A_V DB 65
F_V DB 70
Z_V DB 48
N_V DB 57


.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX  
    
 START:
    ;NEW LINE
    MOV AH, 02
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H
    ; INPUT MESSAGE HERE
    MOV AH, 09
    LEA DX, INP_MSG
    INT 21H
        
    ; USER INPUT 
    MOV AH, 01
    INT 21H 
    
    SUB AL, 48
    MOV N, AL
    
    ;NEW LINE
    MOV AH, 02
    MOV DL, 0AH
    INT 21H
    MOV DL, 0DH
    INT 21H  
    
    ; CHECK CONDITION
    MOV DL, N
    ADD DL, 48
    CMP DL, "0"
    JGE CHK_FOR_9
    ;CMP DL, "0"
    JL INVALID
            
        CHK_FOR_9:
            
            CMP DL, "9"
            JLE PRINT_0_TO_9
            JMP CHK_A_TO_F
            
       SET_9_TO_A:
            MOV DL, A_V
            DEC DL
            JMP   PRINT_0_TO_9
       
       MOV DL, N
       ADD DL, 48
       
       PRINT_0_TO_9:     
            
            
            CMP DL, N_V
            JE SET_9_TO_A
            
            INC DL
            
            MOV AH, 02
            INT 21H
            
            JMP CHOICE
            
      CHK_A_TO_F:     
        MOV DL, N
        ADD DL, 48
        CMP DL, "A"
        JGE CHK_FOR_F
        JMP INVALID
        
            CHK_FOR_F:
                CMP DL, "F"
                JLE PRINT_A_TO_F
                JMP INVALID
    
    SET_F_TO_A:
        MOV DL, Z_V
        DEC DL
        JMP PRINT_A_TO_F
                  
    MOV DL, N
    ADD DL, 48
    
    PRINT_A_TO_F: 
        CMP DL, F_V
        JE SET_F_TO_A 
        
        INC DL
        
        MOV AH, 02
        INT 21H        
        
        JMP CHOICE
        
    INVALID:
        MOV AH, 9
        LEA DX, INV_MSG
        INT 21H
        
   CHOICE:
        MOV AH, 09
        LEA DX, CH_MSG
        INT 21H  
        
        MOV AH, 01
        INT 21H
        
        CMP AL, "Y"
        JE START
        CMP AL, "y"
        JE START
        JMP EXIT
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
ENDP MAIN
END MAIN