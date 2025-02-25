ORG 100H

.DATA
A DB 0
B DB 1
C DB ?
N DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV N, AL
    
    MOV AL, N
    ADD AL, "0"
    CMP AL, "0"
    JE EXIT
    CMP AL, "1"
    JE PRINT_A
    CMP AL, "2"
    JE PRINT_AB
    
    MOV DL, A
    ADD DL, "0"
    MOV AH, 2
    INT 21H
    
    MOV DL, B
    ADD DL, "0"
    MOV AH, 2
    INT 21H 
    
    MOV CX, 0
    MOV CL, N
    SUB CL, 2
    
    CAL:
        MOV AL, A
        MOV BL, B
        ADD AL, BL
        MOV C, AL
        
        MOV AL, B
        MOV A, AL 
        
        MOV AL, C
        MOV B, AL
        
        MOV DL, C
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        LOOP CAL
        JMP EXIT
        
    
    
    
        
    
    
    PRINT_A:
        MOV DL, A
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        JMP EXIT
    
    
    PRINT_AB:
        MOV DL, A
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        
        MOV DL, B
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        
        JMP EXIT 
    
    EXIT:
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET