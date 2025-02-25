ORG 100H
.DATA ; Data segment starts

A DW 9
B DW 4 
C DW 5
D DW 8


.CODE ; CODE SEGMENT HERE
MAIN PROC ; INITIALIZE DATA SEGEMENT 
    MOV AX, @DATA
    MOV DS, AX 
    
    XOR BX, BX 
    MOV BX, A
    ADD BX, D 
    SUB BX, B
    SUB BX, C
    
    MAIN ENDP; END PROCEDURE
END MAIN
ret



                       