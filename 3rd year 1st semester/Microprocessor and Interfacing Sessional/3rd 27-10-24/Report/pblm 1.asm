; 1+2+3+4+5+6+...+N
ORG 100H
.DATA

N DB ?
SUM DB ? 
INPUT_MSG DB 0AH, 0DH, "INPUT A NUMBER: $"
OUTPUT_MSG DB 0AH, 0DH, "SUMMATION OF SERIES: $"


.CODE
MAIN PROC 
    
    MOV AX, @DATA
    MOV DS, AX
    
    MOV AH, 9
    LEA DX, OUTPUT_MSG
    INT 21H
    
    ; INPUT
    MOV AH, 01H         
    INT 21H
    MOV N, AL
    SUB N, 48
    
    ;NEW LINE 
    ;MOV AH, 2      
    ;MOV DL, 0DH;
    ;INT 21H
    ;MOV DL, 0AH
    ;INT 21H
    
    MOV CL, N  
    MOV SUM, 0
    SERIES:  
        ADD SUM, CL
    LOOP SERIES
             
    MOV AH, 9
    LEA DX, OUTPUT_MSG
    INT 21H
      
    MOV DL, SUM
    ADD DL, 48
    MOV AH, 2
    INT 21H
    
    MAIN ENDP
END MAIN
RET