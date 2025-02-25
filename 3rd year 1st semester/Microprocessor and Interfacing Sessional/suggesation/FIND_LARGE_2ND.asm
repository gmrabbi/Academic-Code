ORG 100H

.DATA
A DB ?
B DB ?
C DB ?
FST DB ?
SND DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV A, AL 
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV B, AL
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV C, AL
    
    ;MOV AL, A
    MOV FST, 0;AL
    MOV SND, 0;AL
    
    MOV AX, 0
    MOV AL, B
    CMP AL, FST
    JGE B_FST
    JMP C_CHK
    
    
    B_FST:
        MOV AL, FST
        MOV SND, AL
        MOV AL, B
        MOV FST, AL
        
    C_CHK:
        MOV AX, 0
        MOV AL, C
        CMP AL, FST
        JGE C_FST
        JMP DOUBLE_B: 
        
   C_FST:
        MOV AL, FST
        MOV SND, AL
        MOV AL, C
        MOV FST, AL
   DOUBLE_B:     
    MOV BL, FST
    CMP B, BL
    JL CHK_B_SND
    JMP DOUBLE_C
 
    CHK_B_SND:
        MOV AL, B
        CMP AL, SND
        JG SET_SND_B
        
    SET_SND_B:   
        MOV AL, B
        MOV SND, AL
   
   DOUBLE_C:     
   MOV BL, FST
    CMP C, BL
    JL CHK_C_SND
    JMP DOUBLE_A
 
    CHK_C_SND:
        MOV AL, C
        CMP AL, SND
        JG SET_SND_C
        
    SET_SND_C:   
        MOV AL, C
        MOV SND, AL
        
    ; //////
    DOUBLE_A:
    MOV BL, FST
    CMP A, BL
    JL CHK_A_SND
    JMP PRINT
 
    CHK_A_SND:
        MOV AL, A
        CMP AL, SND
        JG SET_SND_A
        
    SET_SND_A:   
        MOV AL, A
        MOV SND, AL
   
   PRINT: 
   MOV DL, FST 
   ADD DL, "0"      
   MOV AH, 2
   INT 21H
   
   MOV DL, SND
   ADD DL, "0"
   MOV AH, 2
   INT 21H     
    
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
        
    MAIN ENDP
END MAIN
RET
    