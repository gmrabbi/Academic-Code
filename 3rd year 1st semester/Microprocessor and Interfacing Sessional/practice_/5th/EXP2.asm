; B = (A-B)x(B-10)

ORG 100H
.DATA
A DB 34
B DB 23
C DB 12

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, 0
    MOV AL, A   
    MOV AH, B
    SUB AL, AH
    
    MOV BL, B
    SUB BL, 10
    
    MUL BL
    MOV B, AL
    
    
    
    