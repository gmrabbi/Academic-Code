ORG 100H

.DATA
C DB 100
F DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AX, 0
    MOV AL, C
    MOV BL, 9
    MUL BL
    MOV BL, 5
    DIV BL
    ADD AL, 32
    
    MOV F, AL
    
    MOV DL, F
    MOV AH, 2
    INT 21H 
        
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET