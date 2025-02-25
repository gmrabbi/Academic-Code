ORG 100H
.DATA              
arr DW 10 DUP(0)   
n DW 0             
result DW 0        

MSG_INPUT DB 'Enter n (2~9): $'
MSG_RESULT DB 13, 10, 'Result: $'

.CODE              
MOV AX, @DATA      
MOV DS, AX

; Input n
LEA DX, MSG_INPUT  
MOV AH, 9          
INT 21h

MOV AH, 1          
INT 21h
SUB AL, '0'        
XOR AH, AH
MOV n, AX          

MOV CX, n          
MOV BX, 0          
MOV AX, 1          

INIT_ARRAY:
MOV arr[BX], AX    
INC BX             
INC AX             
LOOP INIT_ARRAY    

MOV CX, n          
MOV BX, 0          
MOV result, 0      

SUM_SQUARES:  
XOR AX, AX
MOV AX, arr[BX]    
AND AX, 0FH
MOV DX, AX  
IMUL DX     

ADD result, AX     
INC BX             
LOOP SUM_SQUARES   

LEA DX, MSG_RESULT 
MOV AH, 9
INT 21h

MOV AX, result     

MOV AH, 4Ch        
INT 21h

END MAIN
