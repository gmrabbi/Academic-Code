ORG 100H

.DATA
X DB ?
Y DB ?
Z DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV X, AL
    
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
    
    MOV AH, 1
    INT 21H
    SUB AL, 48
    MOV Y, AL
    
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
    
    MOV AL, X
    ADD Z, AL
    MOV AL, Y
    SUB Z, AL
    ADD Z, 1
    
    MOV DL, Z 
    ADD DL, 48
    MOV AH, 2
    INT 21H
    
    MOV AX, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET