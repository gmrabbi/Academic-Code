ORG 100H

.DATA
N DB ?
RESULT DB ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV N, AL 
    
    MOV CX, 0 
    MOV CL, N
    CAL:
       MOV AL, CL
       MOV BL, CL
       MUL BL
       MUL BL
       ADD RESULT, AL
       LOOP CAL

    
    MOV AH, 4CH
    INT 21H
    
    
    MAIN ENDP
END MAIN
RET