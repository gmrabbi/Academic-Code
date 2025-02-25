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
 
    COND_CHKZ:
        MOV DL, 65
        DEC DL
        JMP PRINT_FR
   COND_CHKz2:
        MOV DL, 97
        DEC DL
        JMP PRINT_FR
             ; ////////////////////
    COND_CHKA:
        MOV DL, 90
        INC DL
        JMP PRINT_BW
   COND_CHKa2:
        MOV DL, 122
        INC DL
        JMP PRINT_BW
        
    
    PRINT:            
        MOV DL, CHR
        MOV CX, 5
        MOV AH, 2
        PRINT_FR:
            INC DL
            
            CMP DL, 90
            JG COND_CHKZ
            CMP DL, 122
            JG COND_CHKz2
            
            INT 21H
            LOOP PRINT_FR
        
        MOV AH, 2
        MOV DL, 0DH
        INT 21H
        MOV DL, 0AH
        INT 21H
            
        MOV DL, CHR
        MOV CX, 5
        MOV AH, 2
        PRINT_BW:
            DEC DL 
            
            CMP DL, 65
            JL COND_CHKA
            CMP DL, 97
            JG COND_CHKa2
            
            INT 21H
            LOOP PRINT_BW
         
    
    EXIT:
        MOV AX, 4CH
        INT 21H
    
    MAIN ENDP
END MAIN
RET