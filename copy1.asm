	AREA RESET, DATA, READONLY
	EXPORT __Vectors
__Vectors 
	DCD 0x10001000 ; stack pointer value when stack is empty
	DCD Reset_Handler ; reset vector 
	ALIGN
	AREA mycode, CODE, READONLY
	ENTRY
	EXPORT Reset_Handler
Reset_Handler
	MOV R3,#N
	LDR R0, =SRC+4*(N-1)
	LDR R2, =SRC+4*(N-1+Shifts)
BACK
	LDR R1, [R0],#-4
	STR R1, [R2],#-4
	SUB R3,#1
	CMP R3,#0
	BNE BACK
STOP B STOP 
N EQU 5
Shifts EQU 2
	AREA MYDATA, DATA, READWRITE
SRC DCD 0,0,0,0,0,0,0,0,0,0
END
	