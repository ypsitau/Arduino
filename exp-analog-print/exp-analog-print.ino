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
		ADMUX =
			(1 << REFS0) |		// Reference Selection Bits = AVcc with external capacitor at AREF pin
			(0 << ADLAR) |		// ADC Left Adjust Result = 0
			(0 << MUX0);		// Analog Channel Selection Bits = ADC0
		ADCSRA |= (1 << ADSC);	// ADC Start Conversion = 1
		while (ADCSRA & (1 << ADSC)) ;
		value = ADC;
	} while (0);
	Serial.println(value, 16);
}
