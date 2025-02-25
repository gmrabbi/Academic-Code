ORG 100H

.DATA
N DB ?
MSG_INP DB 0AH, 0DH, "ENTER A HEX DIGIT:$"
MSG_OUT DB 0AH, 0DH, "IN DECIMAL IS IT $"
MSG_CHO DB 0AH, 0DH, "DO YOU WANT TO DO IT AGAIN?$"
MSG_ILI DB 0AH, 0DH, "ILLIGAL CHARACTER - ENTER 0..9 OR A..F:$" 
NEW_LINE DB 0AH, 0DH, "$"

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
BACK:    
    MOV AH, 09H
    LEA DX, MSG_INP
    INT 21H
INPUT_ONLY:   
    MOV AH, 1
    INT 21H
    ;SUB AL, "0"
    MOV N, AL
    
    MOV AH, 09H
    LEA DX, NEW_LINE
    INT 21H
    
    MOV AL, N
    CMP AL, "0"
    JGE CHK9
    JMP INVALID_INPUT
    
    CHK9:
        MOV AL, N
        CMP AL, "9"
        JLE IN09
        
        CMP AL, "A"
        JGE CHKF
        JMP INVALID_INPUT
        
    CHKF:
        CMP AL, "F"
        JLE INAF
        JMP INVALID_INPUT
    INAF:
        MOV AH, 09H
        LEA DX, MSG_OUT
        INT 21H
        
        MOV DL, N
        SUB DL, 55
        MOV AH, 2
        INT 21H
        JMP CHOICE
        
        
    IN09:
        MOV AH, 09H
        LEA DX, MSG_OUT
        INT 21H
        
        MOV DL, N
        ;ADD DL, "0"
        MOV AH, 2
        INT 21H
        JMP CHOICE
    
   INVALID_INPUT:
        MOV AH, 09H
        LEA DX, MSG_ILI
        INT 21H 
        JMP INPUT_ONLY
        
   CHOICE:
        MOV AH, 09H
        LEA DX, MSG_CHO
        INT 21H
        
        MOV AH, 1
        INT 21H
        
        CMP AL, "y"
        JE BACK
        CMP AL, "Y"
        JE BACK   

    EXIT: 
        MOV AH, 4CH
        INT 21H
        MAIN ENDP
END MAIN
RET