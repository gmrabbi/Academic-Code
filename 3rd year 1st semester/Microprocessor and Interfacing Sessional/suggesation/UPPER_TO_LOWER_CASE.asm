ORG 100H

.DATA
N DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    MOV N, AL
    
    CMP AL, "A"
    JGE CHK_Z
    JMP EXIT
    
    CHK_Z:
        CMP AL, "Z"
        JLE VALID_UP_TO_LOW
        
        CMP AL, "a"
        JGE CHK_z2
        JMP EXIT
    CHK_z2:
        CMP AL, "z"
        JLE VALID_LOW_TO_UP
        JMP EXIT   
    
    VALID_LOW_TO_UP:
        SUB N, 32
        JMP PRINT 
        
    VALID_UP_TO_LOW:
        ADD N, 32
        
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
    
    PRINT:
        MOV DL, N
        MOV AH, 2
        INT 21H
    
    EXIT:
    MOV AH, 4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET