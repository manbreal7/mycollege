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
	MOV R3,#5
	MOV R4,#7
	MOV R5,R3
	MOV R3,R4
	MOV R4,R5
	MOV R5,#0
STOP B STOP
	END
	
