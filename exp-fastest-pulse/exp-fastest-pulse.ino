// Generates a pulse of 4MHz (16MHz / 4clk)
void setup()
{
	pinMode(2, OUTPUT);
	noInterrupts();
	uint8_t dataHi = PORTD | (1 << PD2);
	uint8_t dataLo = PORTD & ~(1 << PD2);
	__asm__ volatile(
    "loop:"						"\n"
	"	out %[portD],%[dataHi]"	"\n" // 1clk
	"	out %[portD],%[dataLo]"	"\n" // 1clk
	"	rjmp loop"				"\n" // 2clk
	:
	:	[portD] "I" (_SFR_IO_ADDR(PORTD)),
		[dataHi] "r" (dataHi),
		[dataLo] "r" (dataLo)
	);
}

void loop()
{
}
