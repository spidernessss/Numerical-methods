section .data
     const1 dq 2.00
     const3 dq 3.00
         
section .text

global function_1
global function_2
global function_3
function_1:
    ; 2 ^ x + 1
    PUSH ebp
    MOV ebp, esp
    SUB esp, 8   ; Allocate 8 bytes for temporary storage on the stack

    FINIT        ; Initialize the FPU

    ; Calculate 2^x

    ;GET THE INTEGER PART
    FLD qword [ebp + 8]      ; Load x onto the FPU stack
    FRNDINT                  ; Get the integer part of x in st1 
    FLD1                     ; and one in st0
    FSCALE                   ; ST(0) = ST(0) * 2ST(1) 

    ;GET THE FRACTIONAL PART
    FLD qword[ebp + 8]
    FLD st0                  ; Duplicate x
    FRNDINT                  ; Integer part in st0
    FSUBP st1, st0           ; ST(1) = ST(1) - ST(0) and pop integer part
    F2XM1                    ; ST(0) = 2^ST(0) - 1
    FLD1
    FADDP                    ; get 2^x fractional 

    ;COMBINE
    FMULP                    ;ST(1) = ST(0) * ST(1) add pop st0
    FLD1
    FADDP                    ;ST(1) = ST(0) + ST(1) and pop 1

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
    FLD1
    FLD qword[ebp + 8]
    FSUBP
    FLD qword[const3]
    FDIVP
    LEAVE 
    RET


