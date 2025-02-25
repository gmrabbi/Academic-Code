ORG 100H

.DATA
N DB 65H
MES DB "AL= $"

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AH, 09H
    LEA DX, MES
    INT 21H
    
    MOV CX, 0 
    MOV CX, 8
    MOV AX, 0
    MOV AL, N
    
    DISPLAY:
        MOV AL, N
        SHL AL, 1 
        MOV N, AL
        JC SET_ONE
        JMP SET_ZERO
        
   SET_ONE:
    MOV DL, "1"
    JMP PRINT
    
  SET_ZERO:
    MOV DL, "0"
   
  PRINT:
    MOV AH, 2
    INT 21H
    LOOP DISPLAY
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
   MAIN ENDP
END MAIN
RET