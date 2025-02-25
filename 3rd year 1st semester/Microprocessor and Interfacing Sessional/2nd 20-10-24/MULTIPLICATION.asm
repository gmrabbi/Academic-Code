ORG 0100h

.DATA
X DW ?
Y DW ?
Z DW ? 

.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
          
    MOV AL, 4H
    MOV BL, 3H
    
    MUL BL   ; AX = AL * BL
    
    
    
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET