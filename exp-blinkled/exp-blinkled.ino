const uint8_t pinLED = 2;

void setup()
{
	pinMode(pinLED, OUTPUT);
}

void loop()
{
	digitalWrite(pinLED, HIGH);
	delay(100);
	digitalWrite(pinLED, LOW);
	delay(100);
}
