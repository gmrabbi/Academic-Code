ORG 100H

.DATA 
NEWLINE DB 0AH, 0DH, "$" 
RESULT DB 0              
SIGN DB -1               
N DB ?                   
CUNT DB 1                

.CODE
MAIN PROC 
    MOV AX, @DATA
    MOV DS, AX

    MOV AH, 01H          
    INT 21H
    SUB AL, 48           
    MOV N, AL            

    MOV AH, 09H
    LEA DX, NEWLINE     
    INT 21H 

    XOR CX, CX           
    MOV CL, N            

CALCULATION:
    MOV BL, CUNT         
    INC CUNT             

    MOV AL, SIGN         
    IMUL BL              
    
    ADD RESULT, AL       
 
    NEG SIGN             

    LOOP CALCULATION     
           
    MOV AH, 4CH          
    INT 21H

    ENDP MAIN
END MAIN
