ORG 100H

.DATA
MSG DB "this is a message:$"

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV SI, 0 
    MOV CX, 17
    CAL:
        CMP MSG[SI], ' '
        JE EMP_STR
        JMP STR
        
   EMP_STR:
        INC SI
        LOOP CAL
  STR:
    SUB MSG[SI], 32
    INC SI
    LOOP CAL
    
    
  MOV AH, 09H
  LEA DX, MSG
  INT 21H
     
    
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET
    
    