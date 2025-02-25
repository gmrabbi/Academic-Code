ORG 100H

.DATA 
C DW 260
F DW 0

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    XOR AX, AX
    MOV AX, C
    MOV BX, 9
    MUL BX 
    MOV BX, 5 
    DIV BX
    ADD AX, 32
    DEC AX
    MOV F, AX
    
    
    
    MOV AX, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET