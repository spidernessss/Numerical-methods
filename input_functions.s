section .data
     const1 dq 2
     const3 dq 3
         
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
    F2XM1
    FLD qword[const1]
    FADDP
    LEAVE
    RET   
function_2:
   ; x^5
   ; making fast multiplication
    PUSH ebp
    MOV ebp, esp
    SUB esp, 8  
    FINIT
    FLD qword[ebp + 8] ;pushing x to the stack
    FLD qword[ebp + 8] ; again to make multiplication
    FMUL ; result in st0
    FMUL st0, st0  ; st0 * st0
    FLD qword[ebp + 8]
    FMULP ; in st0
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
    FLD qword[const3]
    FDIVP
    LEAVE 
    RET
