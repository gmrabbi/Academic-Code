ORG 100H

.DATA
A DB ?
B DB ?
C DB ?

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
    
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H 
    
    MOV AX, 0
    MOV AL, B
    CMP A, AL
    JGE CHKAC
    JMP CHKBA
    
    
    CHKAC:
        MOV AL, C
        CMP A, AL
        JGE PRINT_A
        JMP CHKBA
    
    PRINT_A:
        MOV DL, A
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        JMP EXIT
        
    CHKBA:
        MOV AX, 0
        MOV AL, A
        CMP B, AL
        JGE CHKBC
        JMP PRINT_C
        
    CHKBC:
        MOV AL, C
        CMP B, AL
        JGE PRINT_B
        JMP PRINT_C
        
    PRINT_B:
        MOV DL, B
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        JMP EXIT
        
   PRINT_C:
        MOV DL, C 
        ADD DL, "0"
        MOV AH, 2
        INT 21H    
        
    EXIT:
        MOV AH, 4CH
        INT 21H
    MAIN ENDP
END MAIN
RET