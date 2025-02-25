ORG 100H

.DATA
N DB 5 
RESULT DB 0

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV CX, 0
    MOV CL, N
    CALCULATION:
        MOV AL, N
        MOV BL, AL
        MUL BL
        ADD RESULT, AL
        DEC N
        LOOP CALCULATION
      
    
    
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET