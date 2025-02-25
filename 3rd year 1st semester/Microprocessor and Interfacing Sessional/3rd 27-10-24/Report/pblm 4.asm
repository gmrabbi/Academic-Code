ORG 100H  

.DATA
INPUT_MSG DB 0AH, 0DH, "INPUT A NUMBER: $"
DIV3_MSG DB 0AH, 0DH, "The number is divisible by 3.$"
DIV5_MSG DB 0AH, 0DH, "The number is divisible by 5.$"
BOTH_MSG DB 0AH, 0DH, "The number is divisible by both 3 and 5.$"
NEITHER_MSG DB 0AH, 0DH, "The number is neither divisible by 3 nor 5.$"

.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX

    ; Display input message
    MOV AH, 9
    LEA DX, INPUT_MSG
    INT 21H

    ; INPUT
    MOV AH, 01H         
    INT 21H
    SUB AL, 48           ; Convert from ASCII to numeric
    MOV BL, AL           ; Store the number in BL

    ; Check divisibility by 3
    MOV AX, 0           ; Copy the number to AL for division
    MOV AL, BL
    MOV CL, 3           ; Divisor 3
    DIV CL               ; Divide AL by 3
    CMP AH, 0           ; Check remainder
    JE DIV35_CHECKED      ; Jump if divisible by 3 
    
    ; Check divisibility by 3
    MOV AX, 0
    MOV AL, BL           ; Copy the number to AL for division
    MOV CL, 5           ; Divisor 3
    ;XOR DX, DX           ; Clear DX before division
    DIV CL               ; Divide AL by 3
    CMP AH, 0           ; Check remainder
    JE DIV5_CHECKED      ; Jump if divisible by 3 
    ;JMP END_PROGRAM  
    
    MOV AH, 09H
    LEA DX, NEITHER_MSG
    INT 21H
    JMP END_PROGRAM  
    
    ; Check divisibility by 5
DIV35_CHECKED:  
    MOV AX, 0
    MOV AL, BL           ; Copy the number to AL for division
    MOV CL, 5           ; Divisor 5
    DIV CL               ; Divide AL by 5
    CMP AH, 0           ; Check remainder
    JE BOTH_CHECKED      ; Jump if divisible by 5
    
    
    ;NEITHER
    MOV AH, 09H
    LEA DX, DIV3_MSG
    INT 21H
    JMP END_PROGRAM      ; Jump to end

    ; If divisible by 5
BOTH_CHECKED:
    MOV AH, 09H
    LEA DX, BOTH_MSG
    INT 21H
    JMP END_PROGRAM      ; Jump to end

    ; If divisible by both 3 and 5
DIV3_CHECKED:
    MOV AH, 9
    LEA DX, DIV3_MSG
    INT 21H  
    JMP END_PROGRAM 
    
DIV5_CHECKED:
    MOV AH, 09H
    LEA DX, DIV5_MSG
    INT 21H  
    JMP END_PROGRAM

END_PROGRAM:
    MOV AH, 4CH       ; Terminate program
    INT 21H

    MAIN ENDP
END MAIN
