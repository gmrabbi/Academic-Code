ORG 100H

.DATA
GRADE_F      DB 0AH, 0DH, 'Grade: F$'      ; Grade F
GRADE_D      DB 0AH, 0DH, 'Grade: D$'      ; Grade D
GRADE_C      DB 0AH, 0DH, 'Grade: C$'      ; Grade C
GRADE_B      DB 0AH, 0DH, 'Grade: B$'      ; Grade B
GRADE_A      DB 0AH, 0DH, 'Grade: A$'      ; Grade A
GRADE_A_PLUS DB 0AH, 0DH, 'Grade: A+$'     ; Grade A+
N DB 0             
TEMP DB 0  

.CODE
MAIN PROC
    ; Load data segment
    MOV AX, @DATA
    MOV DS, AX

INPUT_LOOP:
    ; Read a character
    MOV AH, 01H
    INT 21H

    ; Check for CR (Carriage Return) or LF (Line Feed)
    CMP AL, 0DH
    JE END_INPUT_LOOP
    CMP AL, 0AH
    JE END_INPUT_LOOP

    ; Convert character to digit and accumulate in N
    SUB AL, 48
    MOV TEMP, AL
    
    MOV BL, N
    MOV AL, 10
    MUL BL
    ADD AL, TEMP
    MOV N, AL

    ; Loop back for the next character
    JMP INPUT_LOOP

END_INPUT_LOOP:
    MOV AL, N           

    CMP AL, 50          ; If marks < 50
    JL PRINT_GRADE_F    ; Jump to print F

    CMP AL, 60          ; If marks >= 50 and marks < 60
    JL PRINT_GRADE_D    ; Jump to print D

    CMP AL, 70          ; If marks >= 60 and marks < 70
    JL PRINT_GRADE_C    ; Jump to print C

    CMP AL, 80          ; If marks >= 70 and marks < 80
    JL PRINT_GRADE_B    ; Jump to print B

    CMP AL, 90          ; If marks >= 80 and marks < 90
    JL PRINT_GRADE_A    ; Jump to print A

    JMP PRINT_GRADE_A_PLUS ; If marks >= 90, print A+

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
    ; Print grades
    MOV AH, 09H
    INT 21H

    MOV AH, 4CH
    INT 21H
ENDP MAIN
END MAIN
RET