ORG 100H
.DATA
    s DB "wE aR17E DUET ST1uDeNTs$", 0  
    fst DB ' '                       
    snd DB ' '                       
    len DW 23                               
    MSG_F DB "First= $"
    MSG_SND DB " Second= $"                       
.CODE
MAIN PROC
    MOV AX, @DATA    
    MOV DS, AX

    MOV SI, OFFSET s 
    MOV AL, ' '      
    MOV fst, AL
    MOV snd, AL
    MOV CX, len      

FIND_LOWERCASE:
    LODSB            ; Load next character into AL from string
    CMP AL, 'a'      ; if AL >= 'a'
    JL NOT_LOWER     ; If less, not a lowercase letter
    CMP AL, 'z'      ; if AL <= 'z'
    JG NOT_LOWER     ; If greater, not a lowercase letter

    MOV DL, fst      ; Check if fst is still ' '
    CMP DL, ' '
    JNE CHECK_SECOND ; If fst is not ' ', check snd
    MOV fst, AL      ; Store the first lowercase letter
    JMP NEXT_CHAR

CHECK_SECOND:
    MOV snd, AL      ; Store the second lowercase letter

NOT_LOWER:
NEXT_CHAR:
    LOOP FIND_LOWERCASE 

    MOV AH, 09H       
    LEA DX, MSG_F
    INT 21H
        
    MOV DL, fst
    MOV AH, 02H
    INT 21H

    MOV AH, 09H       
    LEA DX, MSG_SND
    INT 21H
    
    MOV DL, snd
    MOV AH, 02H
    INT 21H

    MOV AH, 4CH       
    INT 21H

MAIN ENDP
END MAIN
