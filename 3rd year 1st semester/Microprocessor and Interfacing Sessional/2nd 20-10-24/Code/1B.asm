; USER INPUT CODE AND PRINT THE USER INPUT
ORG 0100h

.DATA
X DB ?
Y DB ?
Z DB ? 

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
    
    ; USER INPUT      
    MOV AH, 1
    INT 21H      ; STORE USER INPUT INTO AL REGISTER 
    SUB AL, 48
    MOV X, AL    ; MOV AL VALUE TO BL 
    
    MOV AH, 1
    INT 21H      ; STORE USER INPUT INTO AL REGISTER 
    SUB AL, 48
    MOV Y, AL
    
    MOV BL, X
    SUB BL, Y 
    ADD BL, 1
    MOV Z, BL
    
    ; NEW LINE CODE
    MOV AH, 2
    MOV DL, 0DH
    INT 21h
    MOV DL, 0AH
    INT 21h   
            
    ;MOV FROM AL TO DL 
    
    MOV DL, Z
    ADD DL, 48

    
    ; USER OUTPUT
    MOV AH, 2
    INT 21H
    
    ; RETURN TO DOS
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET