ORG 100H

.DATA 
F DW 1000
C DW 0

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    XOR AX, AX
    MOV AX, F
    SUB AX, 32
    MOV BX, 5
    MUL BX
    MOV BX, 9
    DIV BX
    ADD AX, 1 
    MOV C, AX
    
    
    
    MOV AX, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET