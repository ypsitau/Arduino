const uint8_t pinLED = 2;

void setup()
{
	do {
		// pinMode(pinLED, OUTPUT);
		uint8_t bit = digitalPinToBitMask(pinLED);
		uint8_t port = digitalPinToPort(pinLED);
		volatile uint8_t* reg = portModeRegister(port);
		volatile uint8_t* out = portOutputRegister(port);
		uint8_t oldSREG = SREG;
		cli();
		*reg |= bit;
		SREG = oldSREG;
	} while (0);
}

void loop()
{
	do {
		// digitalWrite(pinLED, HIGH);
		uint8_t timer = digitalPinToTimer(pinLED);
		uint8_t bit = digitalPinToBitMask(pinLED);
		uint8_t port = digitalPinToPort(pinLED);
		volatile uint8_t* out = portOutputRegister(port);
		uint8_t oldSREG = SREG;
		cli();
		*out |= bit;
		SREG = oldSREG;
	} while (0);
	do {
		// delay(300);
		unsigned long ms = 300;
		uint32_t start = micros();
		while (ms > 0) {
			yield();
			while (ms > 0 && (micros() - start) >= 1000) {
				ms--;
				start += 1000;
			}
		}
	} while (0);
	do {
		// digitalWrite(pinLED, LOW);
		uint8_t timer = digitalPinToTimer(pinLED);
		uint8_t bit = digitalPinToBitMask(pinLED);
		uint8_t port = digitalPinToPort(pinLED);
		volatile uint8_t* out = portOutputRegister(port);
		uint8_t oldSREG = SREG;
		cli();
		*out &= ~bit;
		SREG = oldSREG;
	} while (0);
	do {
		// delay(300);
		unsigned long ms = 300;
		uint32_t start = micros();
		while (ms > 0) {
			yield();
			while (ms > 0 && (micros() - start) >= 1000) {
				ms--;
				start += 1000;
			}
		}
	} while (0);
}
