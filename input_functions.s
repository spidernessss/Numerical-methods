extern pow
section .data
     const1 dd 2
     const3 dd 4
     
section .text

global function_1
global function_2
global function_3

function_1:
    ; 2 ^ x + 1
    PUSH ebp
    MOV ebp, esp
    SUB esp, 8  
    FINIT
    FLD qword[ebp + 8]
    FSTP dword[esp + 4]
    MOV edx, dword[const1]
    MOV dword[esp], edx
    CALL pow
    ADD esp, 8 
    LEAVE
    RET   
function_2:
   ; x^5
   ; making 5 muls in order not to do pow
    PUSH ebp
    MOV ebp, esp
    SUB esp, 8  
    FINIT
    FLD qword[ebp + 8] ;pushing x to the stack
    FLD qword[ebp + 8] ; again to make multiplication
    FLD qword[ebp + 8] ; again
    FLD qword[ebp + 8] ; again
    FLD qword[ebp + 8] ; again
    FMULP 
    FMULP
    FMULP
    FMULP  ; result in st0
    ADD esp, 8 
    LEAVE
    RET  
function_3:
    ; (1 - x) / 3
    PUSH ebp
    MOV ebp, esp
    SUB esp, 8  ; in order to make an aligned stack frame
    FINIT
    FLDZ
    FLD qword[ebp + 8]
    FSUBP
    FLD dword[const3]
    FDIVP
    ADD esp, 8
    LEAVE 
    RET