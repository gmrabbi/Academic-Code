ORG 100H

.DATA
EQUAL DB "All are equal$" 
NEWLINE DB 0AH, 0DH, "$"
A DB ?
B DB ?
C DB ?   
FST DB 0
SND DB 0

.CODE

MAIN PROC
    MOV AX, @DATA
    MOV DS, AX  
    
    MOV AH, 01H
    INT 21H 
    MOV A, AL
    
    INT 21H 
    MOV B, AL
    
    INT 21H 
    MOV C, AL
    
    MOV AH, 09H
    LEA DX, NEWLINE
    INT 21H 
    
    MOV FST, A      ; FST = A
    
    MOV BL, B   
    CMP BL, A         ; A == B ?
    JE A_B_EQUAL      
    JMP FIND_SND      
    
    A_B_EQUAL:
        MOV BL, B
        CMP BL, C
        JE ABC_EQUAL  ; A == B && B ==C ;EQUAL
        JMP FIND_SND  
        
   
    ABC_EQUAL:
        MOV AH, 09H
        LEA DX, EQUAL  
        INT 21H
        JMP EXIT
        
    FIND_SND:
        MOV BL, B                
        CMP BL, FST             ; (B<=FST)?
        JLE CHK_FSTE_C          
            MOV BL, FST         
            MOV SND, BL         
            MOV BL, B
            MOV FST, BL
              
                 
    CHK_FSTE_C:
        MOV BL, C
        CMP BL, FST            ; (C<=FST)?
        JLE DOUBLE_CHK         
            MOV BL, FST        
            MOV SND, BL        
            MOV BL, B
            MOV FST, BL
            
    DOUBLE_CHK:
        MOV BL, A
        CMP BL, FST
        JGE CHK_SND_B          ; (A<FST AND A>SND) ?
            MOV BL, A
            CMP BL, SND
            JLE CHK_SND_B
                MOV BL, A
                MOV SND, BL
              
    CHK_SND_B:
        MOV BL, B
        CMP BL, FST
        JGE CHK_SND_C          ; (B<FST AND B>SND) ?
            MOV BL, B
            CMP BL, SND
            JLE CHK_SND_C
                MOV BL, B
                MOV SND, BL
    
    CHK_SND_C:                  
        MOV BL, C
        CMP BL, FST
        JGE OUTPUT             ; (C<FST AND C>SND) ?
            MOV BL, C
            CMP BL, SND
            JLE OUTPUT
                MOV BL, C
                MOV SND, BL
                        
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