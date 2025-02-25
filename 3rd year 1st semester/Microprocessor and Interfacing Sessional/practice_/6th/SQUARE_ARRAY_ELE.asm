ORG 100H

.DATA
N DB ?
ARR DB 10 DUP(0)
CNT DB 1 
RESULT DW 0
.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV AX, 0   
    MOV AH, 1
    INT 21H
    SUB AL, "0"
    MOV N, AL
    
    MOV AX, 0
    MOV CX, 0
    MOV CL, N
    MOV SI, 0
    INPUT:
        MOV AL, CNT
        MOV BL, AL
        MUL BL    
        MOV ARR[SI], AL
        ADD CNT, 1
        ADD SI, 1
        LOOP INPUT    
    
    MOV CX, 0
    MOV CL, N
    MOV SI, 0       
    OUTPUT: 
        MOV DX, 0
        MOV DL, ARR[SI] 
        ADD RESULT, DX
        ADD SI, 1
        LOOP OUTPUT 
        
    
    
    
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET