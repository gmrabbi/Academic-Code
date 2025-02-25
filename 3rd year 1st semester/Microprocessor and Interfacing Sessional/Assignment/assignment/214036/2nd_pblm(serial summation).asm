ORG 100H

.DATA 
NEWLINE DB 0AH, 0DH, "$" ; Newline string
RESULT DB 0              
SIGN DB -1               ; Alternating sign (-1, +1)
N DB ?                   ; Input number
CUNT DB 1                ; Counter for 1 TO N NUBMERS

.CODE
MAIN PROC
    ; Load data 
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 01H          ; Input N value
    INT 21H
    SUB AL, 48           ; Convert ASCII to integer
    MOV N, AL            ; Store in N

    ; new line
    MOV AH, 09H
    LEA DX, NEWLINE     
    INT 21H 

    XOR CX, CX           ; Clear CX
    MOV CL, N            ; Loop counter = N

CALCULATION:
    MOV BL, CUNT         ; BL = current counter
    INC CUNT             ; Increment counter

    MOV AL, SIGN         ; AL = (+/-) 1
    IMUL BL              ; Signed multiplication AL = AL * BL
    
    ADD RESULT, AL       ; RESULT += AL
 
    NEG SIGN             ; SIGN = -(SIGN)   Toggle sign

    LOOP CALCULATION     ; Decrement CX and loop if CX != 0
    
    ; NO NEED TO PRINT THE RESULT IN CONSOLE
    
    MOV AH, 4CH          ; DOS interrupt to terminate
    INT 21H
ENDP MAIN
END MAIN
