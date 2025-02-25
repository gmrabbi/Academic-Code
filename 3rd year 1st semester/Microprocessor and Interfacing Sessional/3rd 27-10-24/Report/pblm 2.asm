; 1^2+3^2+5^2+..+N^2
ORG 100H  
.DATA

N DB ?
CNT DB 1
SUM DB ? 
INPUT_MSG DB 0AH, 0DH, "INPUT A NUMBER: $"
OUTPUT_MSG DB 0AH, 0DH, "SQUARE SUMMATION OF SERIES: $"


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
    
    XOR CX, CX 
    XOR AX, AX
    MOV AL, N
    MOV BL, 2
    DIV BL
    XOR CX, CX
    MOV CL, AL
    CMP AH, 01
    JE ADD_1
    JMP CALCULATION
    ADD_1:
        ADD CX, 1
    ;MOV CL, N 
    CALCULATION: 
    MOV SUM, 0 
    XOR AX, AX
    SERIES:  
        MOV AL, CNT
        MOV BL, CNT
        MUL BL
        ADD SUM, AL
        ADD CNT, 2
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