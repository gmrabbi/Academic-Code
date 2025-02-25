ORG 100H

.DATA
EQUAL DB "All the numbers are equal$" 
NEWLINE DB 0AH, 0DH, "$"
A DB ?
B DB ?
C DB ?   
FST DB 0
SND DB 0

.CODE

MAIN PROC
    ; DATA LOAD
    MOV AX, @DATA
    MOV DS, AX  
    
    ; THREE INPUT A, B, C VARIABLE
    MOV AH, 01H
    INT 21H 
    MOV A, AL
    
    INT 21H 
    MOV B, AL
    
    INT 21H 
    MOV C, AL
    
    ; NEW LINE
    MOV AH, 09H
    LEA DX, NEWLINE
    INT 21H 
    
    MOV BL, A
    MOV FST, BL      ; FST = A
    
    ; CHECK EQUAL OR NOT
    
    MOV BL, B   
    CMP BL, A         ; A == B ?
    JE A_B_EQUAL      ; YES, THEN JUMP TO CHECK B==C? (A_B_EQUAL) LABEL
    JMP FIND_SND      ; 3 NUMBERS ARE NOT EQUAL, FIND 2ND LARGEST AMONG THEM
    
    A_B_EQUAL:
        MOV BL, B
        CMP BL, C
        JE ABC_EQUAL  ; A == B && B ==C SO 3 NUBMERS ARE EQUAL
        JMP FIND_SND  ;
        
   
    ABC_EQUAL:
        MOV AH, 09H
        LEA DX, EQUAL  ; PRINT MESSAGE THAT 3 NUMBERS ARE EQUAL
        INT 21H
        JMP EXIT
        
    FIND_SND:
        MOV BL, B                
        CMP BL, FST             ; IF(B<=FST)
        JLE CHK_FSTE_C          ; TRUE? THEN JUMP TO CHECK (C>FST)?
            MOV BL, FST         ; SND = FST
            MOV SND, BL         ; FST = B
            MOV BL, B
            MOV FST, BL
              
                 
    CHK_FSTE_C:
        MOV BL, C
        CMP BL, FST            ; IF(C<=FST)
        JLE DOUBLE_CHK         ; TRUE THEN JUMP TO CHECK (A<FST AND A>SND) THEN SND = A
            MOV BL, FST        ; SND = FST
            MOV SND, BL        ; FST = C
            MOV BL, B
            MOV FST, BL
            
    DOUBLE_CHK:
        MOV BL, A
        CMP BL, FST
        JGE CHK_SND_B          ; IF(A<FST AND A>SND) THEN SND = A
            MOV BL, A
            CMP BL, SND
            JLE CHK_SND_B
                MOV BL, A
                MOV SND, BL
              
    CHK_SND_B:
        MOV BL, B
        CMP BL, FST
        JGE CHK_SND_C          ; IF(B<FST AND B>SND) THEN SND = B
            MOV BL, B
            CMP BL, SND
            JLE CHK_SND_C
                MOV BL, B
                MOV SND, BL
    
    CHK_SND_C:                  
        MOV BL, C
        CMP BL, FST
        JGE OUTPUT             ; IF(C<FST AND C>SND) THEN SND = C
            MOV BL, C
            CMP BL, SND
            JLE OUTPUT
                MOV BL, C
                MOV SND, BL
                    
    ; OUTPUT SHOW    
    OUTPUT:
       MOV AH, 02H
       MOV DL, SND
       INT 21H
       JMP EXIT
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
ENDP MAIN
END MAIN       
RET