ORG 100H

.DATA

ANSWER DW ? 

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AX, 4
    MOV BX, AX
    
      
    SHL AX, 4 
    ADD ANSWER, AX
    
    MOV AX, BX
    SHL AX, 3
    ADD ANSWER, AX
    
    MOV AX, BX
    SHL AX, 1
    ADD ANSWER, AX
    
    MOV AX, BX
    SHL AX, 0
    ADD ANSWER, AX  
    
    ; TERMINAL COMMAND
    MOV AH, 4CH
    INT 21H
    
ENDP MAIN
END MAIN
RET