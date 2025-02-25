ORG 100h

.DATA

.CODE
MAIN PROC
    MOV AX, @DATA      ; Load data 
    MOV DS, AX

    MOV AL, 11011011B    ; Example num(binary: 11011011B)
    MOV BL, AL           ; BL = AL

    XOR BH, BH           ; Clear BH
    MOV CL, 8            ; Set loop counter to 8 bits

REVERSE_LOOP:
    SHR AL, 1            ; Shift AL right, LSB into CF
    RCL BH, 1            ; Rotate CF into the MSB of BH
    LOOP REVERSE_LOOP
    ;DEC CL               ; Decrement loop counter
    ;JNZ REVERSE_LOOP     ; Repeat until all 8 bits are processed

    ; Compare the original and reversed numbers
    CMP BL, BH           ; Compare the original (BL) with the reversed (BH)
    JE PRINT_PALINDROM   ; If equal, print "PALINDROM"
    JMP PRINT_NOT_PALINDROM ; Otherwise, print "NOT PALINDROM"

PRINT_PALINDROM:
    MOV BL, 0AH
    JMP EXIT
    
PRINT_NOT_PALINDROM:
    MOV BL, 00H

    EXIT:
    MOV AH, 4Ch
    INT 21h

ENDP MAIN
END MAIN
