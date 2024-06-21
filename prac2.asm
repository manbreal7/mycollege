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
	LDR R0, =N
	LDR R1, [R0]
	LDR R2, =DST
	STR R1, [R2]
STOP B STOP 
N DCD 0xFFFFFFFF
	AREA MYDATA, DATA, READWRITE
DST DCD 0
	END
	