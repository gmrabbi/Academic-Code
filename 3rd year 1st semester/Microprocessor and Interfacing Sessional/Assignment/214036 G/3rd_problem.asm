ORG 100H

.DATA
GRADE_F      DB 0AH, 0DH, 'Grade: F$'      
GRADE_D      DB 0AH, 0DH, 'Grade: D$'      
GRADE_C      DB 0AH, 0DH, 'Grade: C$'      
GRADE_B      DB 0AH, 0DH, 'Grade: B$'      
GRADE_A      DB 0AH, 0DH, 'Grade: A$'      
GRADE_A_PLUS DB 0AH, 0DH, 'Grade: A+$'     
N DB 0             
TEMP DB 0  

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

INPUT_LOOP:
    MOV AH, 01H
    INT 21H

    CMP AL, 0DH
    JE END_INPUT_LOOP
    CMP AL, 0AH
    JE END_INPUT_LOOP

    SUB AL, 48
    MOV TEMP, AL
    
    MOV BL, N
    MOV AL, 10
    MUL BL
    ADD AL, TEMP
    MOV N, AL

    JMP INPUT_LOOP

END_INPUT_LOOP:
    MOV AL, N           

    CMP AL, 50          
    JL PRINT_GRADE_F    

    CMP AL, 60          
    JL PRINT_GRADE_D    

    CMP AL, 70          
    JL PRINT_GRADE_C    

    CMP AL, 80          
    JL PRINT_GRADE_B    

    CMP AL, 90          
    JL PRINT_GRADE_A    

    JMP PRINT_GRADE_A_PLUS 
    
PRINT_GRADE_F:
    LEA DX, GRADE_F
    JMP DISPLAY_GRADE

PRINT_GRADE_D:
    LEA DX, GRADE_D
    JMP DISPLAY_GRADE

PRINT_GRADE_C:
    LEA DX, GRADE_C
    JMP DISPLAY_GRADE

PRINT_GRADE_B:
    LEA DX, GRADE_B
    JMP DISPLAY_GRADE

PRINT_GRADE_A:
    LEA DX, GRADE_A
    JMP DISPLAY_GRADE

PRINT_GRADE_A_PLUS:
    LEA DX, GRADE_A_PLUS

DISPLAY_GRADE:
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H   
    
    ENDP MAIN
END MAIN
RET