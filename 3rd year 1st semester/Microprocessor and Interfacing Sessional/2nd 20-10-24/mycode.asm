ORG 0100h
.DATA
X DW ?
Y DW ?
Z DW ? 
MSG_1 DW 'ENTER VALUE OF X $'
MSG_2 DW 'ENTER VALUE OF Y $'
MSG_3 DW 'OUTPUT= $'
.CODE
MAIN PROC
    MOV AX,@DATA
    MOV DS,AX
          
    ;INPUT X
    MOV AH,9
    LEA DX,MSG_1
    INT 21H
    MOV AH,1
    INT 21H
    MOV X,AX
    
    ;NEW LINE
    MOV AH,2
    MOV DX,0DH
    INT 21H
    MOV DX,0AH
    INT 21H
    
    ;INPUT Y 
    MOV AH,9
    LEA DX,MSG_2
    INT 21H
    MOV AH,1
    INT 21H
    MOV Y,AX
    
    ;NEW LINE
    MOV AH,2
    MOV DX,0DH
    INT 21H
    MOV DX,0AH
    INT 21H
    
    ;SUM Z=X+Y
    ADD BX,X
    ADD BX,Y
    SUB BX,48d
    MOV Z,BX
    
    ;SUM Z=X-Y+1
    ;ADD BX,X
    ;SUB BX,Y
    ;INC BX
    ;ADD BX,48d
    ;MOV Z,BX
    
    ;TO UPPER CASE
    ;SUB X,32d
    
    ;TO LOWER CASE
    ;ADD X,32d
    
    ;OUTPUT Z
    MOV AH,9
    LEA DX,MSG_3
    INT 21H
    MOV AH,2
    MOV DX,Z
    INT 21H
    
    MOV AH,4CH
    INT 21H
    
    MAIN ENDP
END MAIN
RET