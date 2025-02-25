ORG 100H

.DATA
N DB ?
RESULT DB ?
CNT DB 1
SIGN DB -1

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
    MOV RESULT, 0
    CAL:
       NEG SIGN
       MOV AL, CNT
       MOV DL, CNT
       MUL DL
       MOV BL, SIGN
       MUL BL
       ADD RESULT, AL
       INC CNT
       LOOP CAL

    
    MOV AH, 4CH
    INT 21H
    
    
    MAIN ENDP
END MAIN
RET