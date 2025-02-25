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
       ADD RESULT, CL
       LOOP CAL

    
    MOV AH, 4CH
    INT 21H
    
    
    MAIN ENDP
END MAIN
RET