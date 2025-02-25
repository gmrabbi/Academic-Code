ORG 100H

.DATA

.CODE
MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AX, "A"
    MOV BX, 'A'
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET