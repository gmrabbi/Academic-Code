ORG 100H

.DATA
N DB 5
RESULT DB 1
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV CL, N
    CAL: 
        MOV DL, N
        ADD RESULT, DL
        ADD DL, "0"
        MOV AH, 2
        INT 21H
        NEG N
        LOOP CAL
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET