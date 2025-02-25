ORG 100H

.DATA
N DB ?

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 1
    INT 21H
    ;SUB AL, "0"
    MOV N, AL
   
     
    
    CMP AL, "A"
    JGE CMP_Z
    JMP EXIT
    
    CMP_Z:
        CMP AL, "Z"
        JLE UP_TO_LOW
        
        CMP AL, "a"
        JGE CMP_z2
        JMP EXIT
        
        
    CMP_z2:
        CMP AL, "z"
        JLE LOW_TO_UP
        JMP EXIT
    
    UP_TO_LOW:
        ADD N, 32
        
        MOV BL, N
        SUB BL, 1
        CMP BL, "a"
        JNL NOTHING
        MOV BL, "z"
        
        NOTHING:
        MOV DL, BL
        MOV AH, 2
        INT 21H 
        
        
        MOV BL, N
        ADD BL, 1
        CMP BL, "z"
        JNG NOTHING2
        MOV BL, "a"
        
        NOTHING2:
        MOV DL, BL
        MOV AH, 2
        INT 21H
        JMP EXIT
        
         
        
   LOW_TO_UP:
        SUB N, 32
        
        MOV BL, N
        SUB BL, 1
        CMP BL, "A"
        JNL NOTHING3
        MOV BL, "Z"
        
        NOTHING3:
        MOV DL, BL
        MOV AH, 2
        INT 21H 
        
        
        MOV BL, N
        ADD BL, 1
        CMP BL, "Z"
        JNG NOTHING4
        MOV BL, "A"
        
        NOTHING4:
        MOV DL, BL
        MOV AH, 2
        INT 21H
        JMP EXIT
        
   EXIT:
        MOV AH, 4CH
        INT 21H
        
   MAIN ENDP
END MAIN
RET
        
        