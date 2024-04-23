void setup()
{
	Serial.begin(57600);
	pinMode(A0, INPUT);
}

void loop()
{
	uint16_t value = 0;
	do {
		// value = analogRead(A0);
		ADMUX = (1 << 6)	// REFS = 1: AVcc with external capacitor at AREF pin
			| (0 << 5)		// ADLAR = 0: The result is right adjusted
			| (0 << 0);		// MUX = 0 .. choose A0
		//_SFR_BYTE(ADCSRA) |= _BV(ADSC);
		ADCSRA |= (1 << 6);	// ADSC = 1: ADC Start Conversion
		while (bit_is_set(ADCSRA, 1 << 6)) ;
		value = ADC;
	} while (0);
	Serial.println(value);
}
