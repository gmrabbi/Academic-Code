ORG 100H

.DATA
ARRAY DW 10, 17, 20, 21, 25, 28, 30, 38, 42, 48, 50, 55, 60, 63, 68, 70
SIZE DW 16      ; Number of elements in the array
COUNT3 DW 0     ; Count of numbers divisible by 3
COUNT5 DW 0     ; Count of numbers divisible by 5
COUNT35 DW 0    ; Count of numbers divisible by both 3 and 5

.CODE
MAIN PROC
    MOV AX, @DATA      ; Initialize data segment
    MOV DS, AX

    MOV SI, OFFSET ARRAY ; Pointer to the array
    MOV CX, SIZE          ; Load the size of the array

    XOR BX, BX           ; BX will hold the current element
    XOR DX, DX           ; Clear DX

    XOR AX, AX           ; Initialize AX to 0
    MOV DI, 0            ; DI is used as a counter for results

CHECK_LOOP:
    MOV AX, [SI]         ; Load the current array element into AX
    
    ; Check divisibility by 3
    MOV DX, 0            ; Clear DX for division
    MOV BX, 3
    DIV BX               ; AX = AX / 3, DX = remainder
    CMP DX, 0            ; Check if remainder is 0
    JNE CHECK_5          ; If not 0, skip to check for 5
    
    ; Increment COUNT3
    INC WORD PTR COUNT3

CHECK_5:
    MOV AX, [SI]         ; Reload the current element into AX
    MOV DX, 0            ; Clear DX for division
    MOV BX, 5
    DIV BX               ; AX = AX / 5, DX = remainder
    CMP DX, 0            ; Check if remainder is 0
    JNE CHECK_35         ; If not 0, skip to check for 3 and 5
    
    ; Increment COUNT5
    INC WORD PTR COUNT5

CHECK_35:
    MOV AX, [SI]         ; Reload the current element into AX
    MOV DX, 0            ; Clear DX for division
    MOV BX, 15           ; Check divisibility by 15 (3 * 5)
    DIV BX               ; AX = AX / 15, DX = remainder
    CMP DX, 0            ; Check if remainder is 0
    JNE NEXT_ELEMENT     ; If not 0, skip to the next element
    
    ; Increment COUNT35
    INC WORD PTR COUNT35

NEXT_ELEMENT:
    ADD SI, 2            ; Move to the next array element
    LOOP CHECK_LOOP      ; Decrement CX and repeat loop if CX != 0

    ; End of the program
    MOV AX, 4C00H        ; Exit to DOS
    INT 21H

MAIN ENDP
END MAIN