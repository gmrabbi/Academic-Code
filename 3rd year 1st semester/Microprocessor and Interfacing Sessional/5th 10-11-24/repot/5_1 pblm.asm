ORG 100H

.DATA 
A DW ?
B DW ?
C DW ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV A, 34
    MOV B, 23
    MOV C, 12
    
    MOV AX, A
    MOV BX, 5
    IMUL BX
    SUB AX, 7
    MOV A, AX   
    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
RET