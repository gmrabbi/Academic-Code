ORG 100H

.DATA
RESULT DW 0

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AX, 7
    MOV BX, AX
    
    SHL AX, 4
    ADD RESULT, AX
    
    MOV AX, BX
    SHL AX, 3
    ADD RESULT, AX
    
    MOV AX, BX
    SHL AX, 1
    ADD RESULT, AX
    
    MOV AX, BX
    SHL AX, 0
    ADD RESULT, AX
    
    
    
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET