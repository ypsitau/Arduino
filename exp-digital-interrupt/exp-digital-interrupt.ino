const char* volatile msg = nullptr;

ISR(INT0_vect) // External Interrupt Request 0: PD2
{
	msg = "INT0";
}

ISR(INT1_vect) // External Interrupt Request 1: PD3
{
	msg = "INT1";
}

ISR(PCINT0_vect) // Pin Change Interrupt 0: PB0..PB7
{
	msg = "PCINT0";
}

ISR(PCINT1_vect) // Pin Change Interrupt 1: PC0..PC6
{
	msg = "PCINT1";
}

ISR(PCINT2_vect) // Pin Change Interrupt 2: PD0..PD7
{
	msg = "PCINT2";
}

void setup()
{
	Serial.begin(57600);
	PORTD =
		(1 << PD7) |	// D7  PCINT23
		(1 << PD6) |	// D6  PCINT22 OC0A
		(1 << PD5) |	// D5  PCINT21 OC0B
		(1 << PD4) |	// D4  PCINT20
		(1 << PD3) |	// D3  PCINT19 OC2B INT1
		(1 << PD2) |	// D2  PCINT18      INT0
		(0 << PD1) |	// D1  (TX) 
		(0 << PD0);		// D0  (RX) 
	PORTB =
		(0 << PB7) |	// (XTAL2) 
		(0 << PB6) |	// (XTAL1) 
		(1 << PB5) |	// D13 PCINT5
		(1 << PB4) |	// D12 PCINT4
		(1 << PB3) |	// D11 PCINT3  OC2A
		(1 << PB2) |	// D10 PCINT2  OC1B
		(1 << PB1) |	// D9  PCINT1  OC1A
		(1 << PB0);		// D8  PCINT0
	PORTC =
		(1 << PC6) |	// D20 PCINT14 A6
		(1 << PC5) |	// D19 PCINT13 A5
		(1 << PC4) |	// D18 PCINT12 A4
		(1 << PC3) |	// D17 PCINT11 A3
		(1 << PC2) |	// D16 PCINT10 A2
		(1 << PC1) |	// D15 PCINT9  A1
		(1 << PC0);		// D14 PCINT8  A0
	DDRD =
		(0 << DDD7) |	// D7
		(0 << DDD6) |	// D6
		(0 << DDD5) |	// D5
		(0 << DDD4) |	// D4
		(0 << DDD3) |	// D3
		(0 << DDD2) |	// D2
		(0 << DDD1) |	// D1 (TX)
		(0 << DDD0);	// D0 (RX)
	DDRB =
		(0 << DDB7) |	// (XTAL2)
		(0 << DDB6) |	// (XTAL1)
		(0 << DDB5) |	// D13 
		(0 << DDB4) |	// D12
		(0 << DDB3) |	// D11
		(0 << DDB2) |	// D10
		(0 << DDB1) |	// D9
		(0 << DDB0);	// D8
	DDRC =
		(0 << DDC6) |	// D20 A6
		(0 << DDC5) |	// D19 A5
		(0 << DDC4) |	// D18 A4
		(0 << DDC3) |	// D17 A3
		(0 << DDC2) |	// D16 A2
		(0 << DDC1) |	// D15 A1
		(0 << DDC0);	// D14 A0
	EICRA =
		(1 << ISC10) |	// Interrupt Sense Control 1 = Any logical change on INT1 generates an interrupt request
		(1 << ISC00);	// Interrupt Sense Control 0 = Any logical change on INT0 generates an interrupt request
	EIMSK =
		(1 << INT1) |	// Exernal Interrupt Request 1 Enable = 1
		(1 << INT0);	// Exernal Interrupt Request 0 Enable = 1
	PCICR =
		(1 << PCIE2) |	// Pin Change Interrupt Enable 2 = 1
		(1 << PCIE1) |	// Pin Change Interrupt Enable 1 = 1
		(1 << PCIE0);	// Pin Change Interrupt Enable 0 = 1
	PCMSK2 =
		(1 << PCINT20);	// Pin Change Enable Mask 20 (D4) = 1
	PCMSK1 =
		(1 << PCINT8);	// Pin Change Enable Mask 8 (D14) = 1
	PCMSK0 =
		(1 << PCINT0);	// Pin Change Enable Mask 0 (D8) = 1
}

int cnt = 0;
void loop()
{
	//Serial.println(PIND, 16);
	if (msg) {
		Serial.print(cnt);
		Serial.print(" ");
		Serial.println(msg);
		msg = nullptr;
		cnt++;
	}
}
