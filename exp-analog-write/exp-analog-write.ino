void setup()
{
	Serial.begin(57600);
	pinMode(3, OUTPUT);
	pinMode(5, OUTPUT);
	pinMode(6, OUTPUT);
	pinMode(9, OUTPUT);
	pinMode(10, OUTPUT);
	pinMode(11, OUTPUT);
}

void loop()
{
	const int pin = 11;
	uint8_t value = map(analogRead(A0), 0, 1023, 0, 255);
	Serial.println(value);
	if (pin == 3) { // analogWrite(3, value);
		// PD3 is controlled by OC2B
		TCCR2A |= 1 << COM2B1;
		OCR2B = value;
	} else if (pin == 5) { // analogWrite(5, value);
		// PD5 is controlled by OC0B
		TCCR0A |= 1 << COM0B1;
		OCR0B = value;
	} else if (pin == 6) { // analogWrite(6, value);
		// PD6 is controlled by OC0A
		TCCR0A |= 1 << COM0A1;
		OCR0A = value;
	} else if (pin == 9) { // analogWrite(9, value);
		// PB1 is controlled by OC1A
		TCCR1A |= 1 << COM1A1;
		OCR1A = value;
	} else if (pin == 10) { // analogWrite(10, value);
		// PB2 is controlled by OC1B
		TCCR1A |= 1 << COM1B1;
		OCR1B = value;
	} else if (pin == 11) { // analogWrite(11, value);
		// PB3 is controlled by OC2A
		TCCR2A |= 1 << COM2A1;
		OCR2A = value;
	}
}
