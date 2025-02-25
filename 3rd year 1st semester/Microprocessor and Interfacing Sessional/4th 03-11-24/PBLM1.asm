; 1+2+3+4+ . . . + N
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
    
    CALCULATION:
        ADD RESULT, CL
        LOOP CALCULATION
        
       
    
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
ENDP MAIN
END MAIN