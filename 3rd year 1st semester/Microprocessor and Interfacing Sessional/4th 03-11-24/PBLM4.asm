ORG 100H

.DATA
PROMPT_MSG DB 0AH, 0DH, "ENTER A STRING OF CAPITAL LETTERS:$"
RESULT_MSG DB 0AH, 0DH, "THE LONGEST CONSECUTIVELY INCREASING STRING IS:$"
NEWLINE DB 0AH, 0DH, '$'
CURR_CHAR DB ?         ; Current character read
PREV_CHAR DB ?         ; Previous character for comparison
CURR_COUNT DB 1        ; Current count of consecutive letters
MAX_COUNT DB 1         ; Maximum count of consecutive letters found
MAX_CHAR DB ?          ; Character marking the start of the longest sequence

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX

    ; Display prompt message
    MOV AH, 09
    LEA DX, PROMPT_MSG
    INT 21H

    ; Initialize variables
    MOV CURR_COUNT, 1
    MOV MAX_COUNT, 1
    MOV PREV_CHAR, 0  ; Initialize PREV_CHAR to 0

INPUT_LOOP:
    ; Read a character
    MOV AH, 01
    INT 21H
    MOV CURR_CHAR, AL

    ; Check if it's a carriage return (end of input)
    CMP CURR_CHAR, 0DH
    JE DISPLAY_RESULT

    ; Check if character is alphabetically increasing
    MOV AL, CURR_CHAR
    MOV BL, PREV_CHAR
    CMP AL, BL
    JG IS_INCREASING

    ; Sequence broken, reset count
    MOV CURR_COUNT, 1
    MOV AH, CURR_CHAR 
    MOV PREV_CHAR, AH
    JMP INPUT_LOOP

IS_INCREASING:
    ; Increase count if sequence is increasing
    INC CURR_COUNT

    ; Update max count and store the starting character of the longest sequence
    MOV AL, CURR_COUNT
    MOV BL, MAX_COUNT
    CMP AL, BL
    JLE CONTINUE

    ; New longest sequence found, update MAX_COUNT and MAX_CHAR
    MOV AH, CURR_COUNT
    MOV MAX_COUNT, AH
    MOV AH, PREV_CHAR
    MOV MAX_CHAR, AH

CONTINUE:
    ; After checking, update PREV_CHAR to current character for next iteration
    MOV AH, CURR_CHAR
    MOV PREV_CHAR, AH

    JMP INPUT_LOOP

DISPLAY_RESULT:
    ; Display result message
    MOV AH, 09
    LEA DX, RESULT_MSG
    INT 21H

    ; Display the longest sequence based on MAX_COUNT and MAX_CHAR
    MOV AL, MAX_COUNT
    MOV BL, 1
    MOV DL, MAX_CHAR

DISPLAY_LOOP:
    MOV AH, 02
    INT 21H
    INC DL
    INC BL
    CMP BL, AL
    JLE DISPLAY_LOOP

    ; End the program
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
