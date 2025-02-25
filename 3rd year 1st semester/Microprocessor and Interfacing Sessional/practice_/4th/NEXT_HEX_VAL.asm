ORG 100H

.DATA
N DB ?
INP_MSG DB 0AH, 0DH, "ENTER HEX DIGIT:$"
ILI_MSG DB 0AH, 0DH, "ILLEGAL CHARACTER - ENTER 0 .. 9 OR A .. F:$"
CHS_MSG DB 0AH, 0DH, "DO YOU WANT TO DO IT AGAIN?$"
OUT_MSG DB 0AH, 0DH, "IN DECIMAL IS IT $"
EX DB ?

.CODE 
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

INPUT_LOOP:
    MOV AH, 09H
    LEA DX, INP_MSG
    INT 21H
    
ILI_INPUT:        
    MOV AH, 1
    INT 21H
    ;SUB AL, "0"
    MOV N, AL
    
    CMP AL, "0"
    JGE CHKFOR9
    JMP INVALID_INPUT 
    
    CHKFOR9:
        MOV AX, "0"
        MOV AL, N
        CMP AL, "9"
        JLE PRINT_NUM
        
        CMP AL, "A"
        JGE CHKFORF
        
    CHKFORF:
        MOV AX, 0
        MOV AL, N
        CMP AL, "F"
        JLE PRINT_AL_TO_NUM
        JMP INVALID_INPUT
        
    PRINT_AL_TO_NUM:
        SUB N, 55       
    
    PRINT_NUM:
        MOV AH, 09H
        LEA DX, OUT_MSG
        INT 21H
        
        MOV DL, N
        MOV AH, 2
        INT 21H
        JMP AGAIN
    
    
    
    INVALID_INPUT:
        MOV AH, 09H
        LEA DX, ILI_MSG
        INT 21H
        JMP ILI_INPUT 
    
    AGAIN:
        MOV AH, 09H
        LEA DX, CHS_MSG
        INT 21H
            
        MOV AH, 1
        INT 21H
        CMP AL, "N"
        JNE INPUT_LOOP      
    
    
    
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET


