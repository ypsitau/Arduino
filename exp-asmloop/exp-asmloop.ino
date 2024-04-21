void setup()
{
	pinMode(2, OUTPUT);
	noInterrupts();
	const uint8_t maskPin2 = 1 << 2;
	uint8_t dataHi = PORTD | maskPin2;
	uint8_t dataLo = PORTD & ~maskPin2;
	__asm__ volatile(
    "loop:"						"\n"
	"	out %[portd],%[dataHi]"	"\n" // 1
	"	out %[portd],%[dataLo]"	"\n" // 1
	"	rjmp loop"				"\n" // 2
	:
	:	[portd] "I" (_SFR_IO_ADDR(PORTD)),
		[dataHi] "r" (dataHi),
		[dataLo] "r" (dataLo)
	);
}

void loop()
{
}
