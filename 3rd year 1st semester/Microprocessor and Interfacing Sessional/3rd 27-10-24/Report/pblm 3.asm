ORG 0100h

.DATA

.CODE
MAIN PROC

    ; Input a character
    MOV AH, 1
    INT 21h
    MOV BL, AL            ; Store input character in BL

    ; New line with carriage return
    MOV AH, 2 
    MOV DL, 0DH 
    INT 21h
    MOV DL, 0AH 
    INT 21h  

    ; Check if input is uppercase or lowercase
    CMP BL, 'A'
    JL EXIT               ; Not a valid letter (below 'A')
    CMP BL, 'Z'
    JLE IS_UPPERCASE      ; Uppercase letter range
    CMP BL, 'a'
    JL EXIT               ; Not a valid letter (between 'Z' and 'a')
    CMP BL, 'z'
    JLE IS_LOWERCASE      ; Lowercase letter range
    JMP EXIT              ; Not a valid letter (above 'z')

IS_UPPERCASE:
    ADD BL, 32            ; Convert to lowercase for forward sequence
    JMP PRINT_FORWARD

IS_LOWERCASE:
    SUB BL, 32            ; Convert to uppercase for forward sequence

PRINT_FORWARD:
    ; Print forward sequence with wrap-around
    MOV DL, BL            ; Start with converted case in DL
    MOV CX, 5             ; Set counter for 5 characters
FORWARD:
    MOV AH, 2
    INT 21H
    INC DL
    CMP BL, 'a'           ; Check if original character was lowercase
    JE LOWER_FORWARD_WRAP
    CMP DL, 'Z'           ; Wrap-around for uppercase letters
    JG RESET_UPPERCASE
    JMP FORWARD_NEXT

LOWER_FORWARD_WRAP:
    CMP DL, 'z'           ; Wrap-around for lowercase letters
    JLE FORWARD_NEXT
    MOV DL, 'a'
    JMP FORWARD_NEXT

RESET_UPPERCASE:
    MOV DL, 'A'

FORWARD_NEXT:
    LOOP FORWARD

    ; New line with carriage return
    MOV AH, 2 
    MOV DL, 0DH 
    INT 21h
    MOV DL, 0AH 
    INT 21h

    ; Print backward sequence with wrap-around
    MOV DL, BL            ; Reset DL to opposite case of input
    MOV CX, 5             ; Set counter for 5 characters

BACKWARD:
    DEC DL
    CMP BL, 'a'           ; Check if original character was lowercase
    JE LOWER_BACKWARD_WRAP
    CMP DL, 'A'           ; Wrap-around for uppercase letters
    JL RESET_TO_Z
    JMP BACKWARD_NEXT

LOWER_BACKWARD_WRAP:
    CMP DL, 'a'           ; Wrap-around for lowercase letters
    JGE BACKWARD_NEXT
    MOV DL, 'z'
    JMP BACKWARD_NEXT

RESET_TO_Z:
    MOV DL, 'Z'

BACKWARD_NEXT:
    MOV AH, 2
    INT 21H
    LOOP BACKWARD

EXIT:
    ; Return to DOS
    MOV AH, 4CH 
    INT 21H

MAIN ENDP 
END MAIN
