ORG 100H
.DATA ; Data segment starts

E DW 2H

.CODE ; CODE SEGMENT HERE
MAIN PROC ; INITIALIZE DATA SEGEMENT 
    MOV AX, @DATA
    MOV DS, AX 
    
    MOV BX, 5H 
    SUB BX, E
    ADD BX, 10H
    
    MOV AX, BX  
    XOR BX, BX
    
    MAIN ENDP; END PROCEDURE
END MAIN
ret



                       