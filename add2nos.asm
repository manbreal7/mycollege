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
	LDR R0,= 0XFFFFFFFF
	LDR R1,= 0XAAAAAAAA
	ADDS R0,R1
	ADC R0,R1
	ADC R2,0
	STR R0, =0X00000001
	STR R2, =0X00000005
STOP B STOP 
	AREA MYDATA, DATA, READWRITE
DST DCD 0
	END
	