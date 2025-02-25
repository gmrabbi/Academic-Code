ORG 100H

.DATA
INPUT_MSG DB "We aRE DUET STuDeNTs$"
FST DB " "
SND DB " "

.CODE
MAIN PROC
    MOV AX, @DATA
    MOV DS, AX
    
    MOV SI, 0
    MOV CX, 20
    CAL: 
        CMP INPUT_MSG[SI], " "
        JE  BACK
        CMP INPUT_MSG[SI], "a"
        JGE CHKz
        JMP BACK
        
   CHKz:
        CMP INPUT_MSG[SI], "z"
        JLE CHK_FST 
        JMP BACK
  CHK_FST:
        CMP FST, " "
        JE SET_FST
        MOV BL, INPUT_MSG[SI]
        MOV SND, BL
        JMP BACK
  SET_FST: 
        MOV BL, INPUT_MSG[SI]
        MOV FST, BL
        
  BACK:  
    INC SI
    LOOP CAL
        
        
   
    
    
    
    MOV AH, 4CH
    INT 21H
    MAIN ENDP
END MAIN
RET