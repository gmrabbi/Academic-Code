ORG 100h

.DATA
NEWLINE DB 0Ah, 0Dh, '$' ; Newline string for formatting output
MESSAGE DB 'AL = ', '$'  ; Message to display before bits
N DB 55H

.CODE
MAIN PROC
    ; Load data segment
    MOV AX, @DATA
    MOV DS, AX

    MOV AL, N          

    ; Display the message "AL = "
    MOV AH, 09h          ; INT 21H function to display a string
    LEA DX, MESSAGE
    INT 21h

    ; Set up loop to display 8 bits
    MOV CL, 8            ; Loop counter for 8 bits

DISPLAY_LOOP:
    MOV AL, N
    SHL AL, 1
    MOV N, AL            ; Logical shift right, move the LSB into CF
    JC BIT_ONE           ; If CF = 1, output '1'
    MOV DL, '0'          ; If CF = 0, output '0'
    JMP DISPLAY_CHAR

BIT_ONE:
    MOV DL, '1'          ; If CF = 1, output '1'

DISPLAY_CHAR:
    MOV AH, 02h          ; INT 21H function to display a character
    INT 21h

    DEC CL               ; Decrement loop counter
    JNZ DISPLAY_LOOP     ; Repeat for all 8 bits

    ; Terminate the program
    MOV AH, 4Ch
    INT 21h

ENDP MAIN
END MAIN
