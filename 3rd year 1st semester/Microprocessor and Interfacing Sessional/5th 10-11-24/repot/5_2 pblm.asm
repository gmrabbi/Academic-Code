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
    MOV BX, B
    SUB AX, BX  ; AX = AX - BX
    ;; MOV BX, AX
    
    SUB BX, 10
    
    IMUL BX
    
    MOV B, AX   
    
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
RET