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
	MOV R3,#10
	LDR R0, =SRC
	LDR R2, =DST
BACK
	LDR R1, [R0],#4
	STR R1, [R2],#4
	SUB R3,#1
	CMP R3,#0
	BNE BACK
STOP B STOP 
SRC DCD 0x12,0xF1,0x3C,0x24,0x4D,0x6A,0x9A,0x8B,0x55,0x43
	AREA MYDATA, DATA, READWRITE
DST DCD 0,0,0,0,0,0,0,0,0,0
	END
	