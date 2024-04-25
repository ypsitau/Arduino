void EnablePWM(int pin)
{
	if (pin == 3) { // PD3 is controlled by OC2B
		TCCR2A |= 1 << COM2B1;
	} else if (pin == 5) { // PD5 is controlled by OC0B
		TCCR0A |= 1 << COM0B1;
	} else if (pin == 6) { // PD6 is controlled by OC0A
		TCCR0A |= 1 << COM0A1;
	} else if (pin == 9) { // PB1 is controlled by OC1A
		TCCR1A |= 1 << COM1A1;
	} else if (pin == 10) { // PB2 is controlled by OC1B
		TCCR1A |= 1 << COM1B1;
	} else if (pin == 11) { // PB3 is controlled by OC2A
		TCCR2A |= 1 << COM2A1;
	}
}

void OutputPWM(int pin, uint8_t value)
{
	if (pin == 3) { // PD3 is controlled by OC2B
		OCR2B = value;
	} else if (pin == 5) { // PD5 is controlled by OC0B
		OCR0B = value;
	} else if (pin == 6) { // PD6 is controlled by OC0A
		OCR0A = value;
	} else if (pin == 9) { // PB1 is controlled by OC1A
		OCR1A = value;
	} else if (pin == 10) { // PB2 is controlled by OC1B
		OCR1B = value;
	} else if (pin == 11) { // PB3 is controlled by OC2A
		OCR2A = value;
	}
}

int pin = 11;

void setup()
{

	Serial.begin(57600);
	pinMode(pin, OUTPUT);
	EnablePWM(pin);
}

void loop()
{
	uint8_t value = map(analogRead(A0), 0, 1023, 0, 255);
	Serial.println(value);
	OutputPWM(pin, value);
}
