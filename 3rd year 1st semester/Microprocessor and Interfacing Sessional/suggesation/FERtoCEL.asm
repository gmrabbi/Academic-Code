ORG 100H

.DATA
C DB ?
F DB 212

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AX, 0
    MOV AL, F
    SUB AL, 32
    MOV BL, 5
    MUL BL
    MOV BL, 9
    DIV BL
    
    MOV C, AL
    
    MOV DL, C
    MOV AH, 2
    INT 21H 
        
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET