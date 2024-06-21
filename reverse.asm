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
	LDR R0, =
	LDR R2, =DST
BACK
	LDR R1, [R0],#-4
	STR R1, [R2],#4
	SUB R3,#1
	CMP R3,#0
	BNE BACK
STOP B STOP 
N EQU 10
SRC DCD 0x12,0x13,0x14,0x15,0x16,0x17,0x18,0x19,0x20,0x21
	AREA MYDATA, DATA, READWRITE
DST DCD 0,0,0,0,0,0,0,0,0,0
	END
	