ORG 100H

.DATA
 N DB 11001111B
RESULT DB ?
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV BX, 0
    MOV AL, N
    MOV CX, 8
    CAL:
        SHL AL, 1
        RCR BH, 1
        LOOP CAL
   MOV RESULT, BH
   
   MOV CX, 8
   MOV AL, RESULT
   CALpp: 
    MOV AL, RESULT
    SHL AL, 1
    MOV RESULT, AL
    JC SET_ONE
    MOV DL, 0
    JMP PRINT
    
  SET_ONE:
    MOV DL, 1 
    
  PRINT:
    ADD DL, "0"
    MOV AH, 2
    INT 21H
    LOOP CALpp
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET