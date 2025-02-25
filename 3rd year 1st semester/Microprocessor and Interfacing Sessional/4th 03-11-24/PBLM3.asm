ORG 100H

.DATA
N DB ? ; 0-9 and A TO F 
INP_MSG DB 0AH, 0DH, "ENTER A HEX DIGIT:$"
INV_MSG DB 0AH, 0DH, "ILLEGAL CHARACTER - ENTER 0..9 OR A..F:$" 
CH_MSG DB 0AH, 0DH, "DO YOU WANT TO DO IT AGAIN? $" 
OUT_MSG DB 0AH, 0DH, "IN DECIMAL IS IT $"
A_MSG DB "10$"
B_MSG DB "11$"
C_MSG DB "12$"
D_MSG DB "13$"
E_MSG DB "14$"
F_MSG DB "15$"      
      
A_V DB 65
F_V DB 70
Z_V DB 48
N_V DB 57


.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX  
    
 START:
    ; INPUT MESSAGE HERE
    MOV AH, 09
    LEA DX, INP_MSG
    INT 21H
    
USER_INPUT:    
    ; USER INPUT 
    MOV AH, 01
    INT 21H 
    
    SUB AL, 48
    MOV N, AL
    
    
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
       
       PRINT_0_TO_9:     
            MOV AH, 09
            LEA DX, OUT_MSG
            INT 21H
            
            MOV DL, N
            ADD DL, 48
            
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
 
    PRINT_A:
        MOV AH, 09
        LEA DX, A_MSG
        INT 21H
        JMP CHOICE
    PRINT_B:
        MOV AH, 09
        LEA DX, B_MSG
        INT 21H
        JMP CHOICE
     PRINT_C:
        MOV AH, 09
        LEA DX, C_MSG
        INT 21H
        JMP CHOICE
     PRINT_D:
        MOV AH, 09
        LEA DX, D_MSG
        INT 21H
        JMP CHOICE
     PRINT_E:
        MOV AH, 09
        LEA DX, D_MSG
        INT 21H
        JMP CHOICE
     PRINT_F:
        MOV AH, 09
        LEA DX, F_MSG
        INT 21H
        JMP CHOICE

    PRINT_A_TO_F:
        MOV AH, 09
        LEA DX, OUT_MSG
        INT 21H
            
        MOV DL, N
        ADD DL, 48
        
        CMP DL, "A" 
        JE PRINT_A
        
        CMP DL, "B" 
        JE PRINT_B
        
        CMP DL, "C" 
        JE PRINT_C
        
        CMP DL, "D" 
        JE PRINT_D
        
        CMP DL, "E" 
        JE PRINT_E
        
        CMP DL, "F" 
        JE PRINT_F
        
    INVALID:
        MOV AH, 9
        LEA DX, INV_MSG
        INT 21H
        JMP USER_INPUT
        
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