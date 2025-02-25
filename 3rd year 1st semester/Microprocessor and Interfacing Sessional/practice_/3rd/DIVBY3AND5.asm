ORG 100H

.DATA
NUM DB 15
MSG_BOTH DB 0AH, 0DH, "DIVIDE BY BOTH 3 AND 5.$"
MSG_3 DB 0AH, 0DH, "DIVIDE BY 3.$"
MSG_5 DB 0AH, 0DH, "DIVIDE BY 5.$"
MSG_NOR DB 0AH, 0DH, "NETHER DIVIDE BY 3 AND 5$"

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    ;MOV AH, 1
    ;INT 21H
    ;SUB AL, "0"
    ;MOV NUM, AL 
    
    MOV AX, 0
    MOV AL, NUM
    MOV BL, 3
    DIV BL
    CMP AH, 0
    JE CHKFOR5
    
    MOV AX, 0   
    MOV AL, NUM
    MOV BL, 5
    DIV BL
    CMP AH, 0
    JNE NETHER_DIV 
    
    LEA DX, MSG_5
    MOV AH, 09H
    INT 21H 
    JMP EXIT
    
    
    
    
    CHKFOR5:
        MOV AL, NUM
        MOV BL, 5
        DIV BL
        CMP AH, 0
        JNE ONLY_3
        
        MOV AH, 09H
        LEA DX, MSG_BOTH
        INT 21H 
        JMP EXIT 
    ONLY_3:
        MOV AH, 09H
        LEA DX, MSG_3
        INT 21H 
        JMP EXIT 
        
   NETHER_DIV:
        MOV AH, 09H
        LEA DX, MSG_NOR
        INT 21H 
    
    
    
    
    
    EXIT:
        MOV AH, 4CH
        INT 21H
    
    MAIN ENDP
END MAIN
RET