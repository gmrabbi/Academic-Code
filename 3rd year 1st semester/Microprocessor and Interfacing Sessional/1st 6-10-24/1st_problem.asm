ORG 100H
.DATA ; Data segment starts

A DW 9
B DW 4 
C DW 5


.CODE ; CODE SEGMENT HERE
MAIN PROC ; INITIALIZE DATA SEGEMENT 
    MOV AX, @DATA
    MOV DS, AX 
    
     
    XOR DX, DX
    MOV DX, A
    ADD DX, B 
    ADD DX, C
    
    MAIN ENDP; END PROCEDURE
END MAIN
ret



                       