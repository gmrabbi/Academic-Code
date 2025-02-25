;1^2 + 2^2+ 3^2 + . . . + N^2
ORG 100H

.DATA
N DB ? ; 2 TO 9
RESULT DB ?

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX  
    
    ; USER INPUT 
    MOV AH, 01
    INT 21H 
    MOV BL, AL
    
    SUB AL, 48
    MOV N, AL
       
    
    XOR CX, CX
    MOV CL, N
    MOV RESULT, 0
    
    XOR AX, AX
    CALCULATION:
        MOV DL, CL
        MOV AL, CL
        MUL DL
        ADD RESULT, AL
        LOOP CALCULATION
        
       
    
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
ENDP MAIN
END MAIN