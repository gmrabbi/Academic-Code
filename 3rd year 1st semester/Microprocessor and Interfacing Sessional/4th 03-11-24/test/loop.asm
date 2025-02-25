ORG 100H

.DATA

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
               
    MOV CX, 5
    MOV DL, "*"
    MOV AH, 2
    
    PRINT:
    CMP CX, 0
    JE EXIT
    
        INT 21H 
        DEC CX
    JMP PRINT       
    
    EXIT:
    MAIN ENDP 
END MAIN
RET         
