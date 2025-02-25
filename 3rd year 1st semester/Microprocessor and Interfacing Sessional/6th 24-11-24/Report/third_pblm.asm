ORG 100H
.DATA
    ARRAY DB 2, 6, 1, 9, 4        
    LENGTH DW 5                  
    MSG_PROMPT DB "The sorted list is: $"

.CODE
MAIN PROC
    MOV AX, @DATA                
    MOV DS, AX

    LEA DX, MSG_PROMPT
    MOV AH, 09H
    INT 21H

    XOR SI, SI                   

OUTER_LOOP:
    CMP SI, LENGTH               
    JGE END_SORT                 
    
    MOV DI, SI                   
    INC DI                       
INNER_LOOP:
    CMP DI, LENGTH               
    JGE NEXT_OUTER               

    MOV AL, ARRAY[SI]            
    MOV BL, ARRAY[DI]            
    CMP AL, BL                   
    JLE NO_SWAP                  

    XCHG AL, BL                
    MOV ARRAY[SI], AL          
    MOV ARRAY[DI], BL          
    
NO_SWAP:
    INC DI                     
    JMP INNER_LOOP             

NEXT_OUTER:
    INC SI                     
    JMP OUTER_LOOP             
END_SORT:
    MOV CX, LENGTH               
    MOV SI, OFFSET ARRAY
    
PRINT_LOOP:
    MOV DL, [SI]                 
    ADD DL, '0'                  
    MOV AH, 02H                  
    INT 21H    
    MOV DL, ' '                  
    MOV AH, 02H
    INT 21H
    INC SI                       
    LOOP PRINT_LOOP              
    MOV AH, 4CH
    INT 21H

MAIN ENDP
END MAIN
