void PrintPIN(uint8_t dataPIN, uint8_t dataDDR)
{
	for (uint8_t mask = 0x80; mask != 0; mask >>= 1) {
		Serial.print((dataPIN & mask)? ((dataDDR & mask)? 'O' : 'I') : '-');
	}
}

void setup()
{
	Serial.begin(57600);
	PORTD =
		(0 << PD7) |	// D7      PCINT23
		(0 << PD6) |	// D6      PCINT22 OC0A
		(0 << PD5) |	// D5      PCINT21 OC0B
		(0 << PD4) |	// D4      PCINT20
		(0 << PD3) |	// D3      PCINT19 OC2B
		(0 << PD2) |	// D2      PCINT18
		(0 << PD1) |	// D1 (TX) PCINT17
		(0 << PD0);		// D0 (RX) PCINT16
	PORTB =
		(0 << PB7) |	// (XTAL2) PCINT7
		(0 << PB6) |	// (XTAL1) PCINT6
		(0 << PB5) |	// D13     PCINT5
		(0 << PB4) |	// D12     PCINT4
		(0 << PB3) |	// D11     PCINT3  OC2A
		(0 << PB2) |	// D10     PCINT2  OC1B
		(0 << PB1) |	// D9      PCINT1  OC1A
		(0 << PB0);		// D8      PCINT0
	PORTC =
		(0 << PC6) |	// D20 A6  PCINT14
		(0 << PC5) |	// D19 A5  PCINT13
		(0 << PC4) |	// D18 A4  PCINT12
		(0 << PC3) |	// D17 A3  PCINT11
		(0 << PC2) |	// D16 A2  PCINT10
		(0 << PC1) |	// D15 A1  PCINT9
		(0 << PC0);		// D14 A0  PCINT8
	DDRD =
		(1 << DDD7) |	// D7
		(1 << DDD6) |	// D6
		(1 << DDD5) |	// D5
		(1 << DDD4) |	// D4
		(1 << DDD3) |	// D3
		(1 << DDD2) |	// D2
		(0 << DDD1) |	// D1 (TX)
		(0 << DDD0);	// D0 (RX)
	DDRB =
		(0 << DDB7) |	// (XTAL2)
		(0 << DDB6) |	// (XTAL1)
		(0 << DDB5) |	// D13 
		(0 << DDB4) |	// D12
		(0 << DDB3) |	// D11
		(1 << DDB2) |	// D10
		(1 << DDB1) |	// D9
		(1 << DDB0);	// D8
	DDRC =
		(0 << DDC6) |	// D20 A6
		(0 << DDC5) |	// D19 A5
		(0 << DDC4) |	// D18 A4
		(0 << DDC3) |	// D17 A3
		(0 << DDC2) |	// D16 A2
		(0 << DDC1) |	// D15 A1
		(0 << DDC0);	// D14 A0
	for (uint8_t pin = 2; pin <= 10; pin++) {
		digitalWrite(pin, HIGH);
		char buff[8];
		sprintf(buff, "Pin#%-2d", pin);
		Serial.print(buff);
		Serial.print(" PIND:");
		PrintPIN(PIND & 0xfc, DDRD);
		Serial.print(" PINB:");
		PrintPIN(PINB, DDRB);
		Serial.print(" PINC:");
		PrintPIN(PINC, DDRC);
		Serial.println();
		digitalWrite(pin, LOW);
	}
	Serial.println("--------");
	DDRD =
		(0 << DDD7) |	// D7
		(0 << DDD6) |	// D6*
		(0 << DDD5) |	// D5*
		(0 << DDD4) |	// D4
		(0 << DDD3) |	// D3*
		(0 << DDD2) |	// D2
		(0 << DDD1) |	// D1 (TX)
		(0 << DDD0);	// D0 (RX)
	DDRB =
		(0 << DDB7) |	// (XTAL2)
		(0 << DDB6) |	// (XTAL1)
		(1 << DDB5) |	// D13
		(1 << DDB4) |	// D12
		(1 << DDB3) |	// D11*
		(0 << DDB2) |	// D10*
		(0 << DDB1) |	// D9*
		(0 << DDB0);	// D8
	DDRC =
		(0 << DDC6) |	// D20 A6
		(1 << DDC5) |	// D19 A5
		(1 << DDC4) |	// D18 A4
		(1 << DDC3) |	// D17 A3
		(1 << DDC2) |	// D16 A2
		(1 << DDC1) |	// D15 A1
		(1 << DDC0);	// D14 A0
	for (uint8_t pin = 11; pin <= 19; pin++) {
		digitalWrite(pin, HIGH);
		char buff[8];
		sprintf(buff, "Pin#%-2d", pin);
		Serial.print(buff);
		Serial.print(" PIND:");
		PrintPIN(PIND & 0xfc, DDRD);
		Serial.print(" PINB:");
		PrintPIN(PINB, DDRB);
		Serial.print(" PINC:");
		PrintPIN(PINC, DDRC);
		Serial.println();
		digitalWrite(pin, LOW);
	}
}

void loop()
{
}
