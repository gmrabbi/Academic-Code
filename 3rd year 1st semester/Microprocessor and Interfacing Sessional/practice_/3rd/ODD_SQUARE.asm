                 ORG 100H

.DATA
N DB ?
MESG DW "ENTER A NUMBER:$"
NEW_LINE DW 0AH, 0DH, "$" 
RESULT DB ? 
NUM DB 1

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
              
    MOV AH, 09H
    LEA DX, MESG
    INT 21H
                 
    MOV AH, 01
    INT 21H
    SUB AL, "0"
    MOV N, AL 
    
    MOV AH, 09H
    LEA DX, NEW_LINE
    INT 21H
    
    MOV CX, 0
    MOV CL, N 
    MOV RESULT, 0
    CALCULATION:
        MOV BL, NUM
        MOV AL, NUM
        MUL BL 
        ADD RESULT, AL
        
        ADD NUM, 2       
        MOV BL, -1
        MOV AL, NUM
        MUL BL
        MOV NUM, AL
        
        SUB CX, 1
        JNZ CALCULATION
          
    
    MOV DL, RESULT
    ADD DL, "0"      
    MOV AH, 02
    INT 21H
    
    
    
    
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET