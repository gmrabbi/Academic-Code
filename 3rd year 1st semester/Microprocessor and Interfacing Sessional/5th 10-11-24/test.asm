ORG 100H

.DATA
N DW ? 

.CODE

MAIN PROC
    
    MOV AX, @DATA
    MOV DS, AX  
    
     
    MOV AX, 10
    MOV N, AX
    SHL N, 2 

    ADD N, AX
     
    
    EXIT:
        MOV AH, 4CH
        INT 21H
        
ENDP MAIN
END MAIN