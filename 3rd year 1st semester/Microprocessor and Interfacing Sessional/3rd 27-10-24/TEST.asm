ORG 100H

.DATA
NUM DB ?
LB DB 2
UB DB ? 
INP_MSG DB 0AH, 0DH, "INPUT A NUMBER: $"
NTP_MSG DB 0AH, 0DH, "NOT PRIME NUMBER$"
P_MSG DB 0AH, 0DH, "PRIME NUMBER$"
.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 09
    LEA DX, INP_MSG 
    INT 21H   
    
    MOV AH, 1
    INT 21H
    
    SUB AL, 48
    MOV NUM, AL
    
    MOV AH, 02
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H 
    XOR AX, AX
    MOV AL, NUM
    MOV CL, LB
    DIV CL
    MOV UB, AL
    
    XOR CX, CX
    MOV CL, UB
    MOV DL, LB
    XOR AX, AX
    MOV AL, NUM
    
    PRINT:
        DIV DL
        CMP CL, 01
        JE PRIME
        CMP AH, 0
        JE NOT_PRIME
    LOOP PRINT
    
    
    PRIME:
        MOV AH, 09
        LEA DX, P_MSG
        INT 21H
        JMP EXIT
    
    NOT_PRIME: 
        MOV AH, 09
        LEA DX, NTP_MSG
        INT 21H
        
        
    
    MOV AH, 02
    INT 21H
    
    EXIT:
        MOV AH, 4CH
        INT 21H 
        
    MAIN ENDP
END MAIN
RET