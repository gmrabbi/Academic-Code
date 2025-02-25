ORG 100H

.DATA
CHR DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    MOV CHR, AL
    
    MOV AH, 2
    MOV DL, 0DH
    INT 21H
    MOV DL, 0AH
    INT 21H
    
    CMP CHR, 97
    JGE CHKz
    CMP CHR, 65
    JGE CHKZ2
    JMP EXIT
    
    CHKz:
        CMP CHR, 122
        JLE LOTOUP
        JMP EXIT
    CHKZ2:
        CMP CHR, 90
        JLE UPTOLO
        JMP EXIT
    UPTOLO:
        ADD CHR, 32
        JMP PRINT
        
    LOTOUP:
        SUB CHR, 32
        JMP PRINT
    
    PRINT:            
        MOV DL, CHR
        MOV AH, 2
        INT 21H   
    
    EXIT:
        MOV AX, 4CH
        INT 21H
    
    MAIN ENDP
END MAIN
RET