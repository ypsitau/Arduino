void setup()
{
	Serial.begin(57600);
	//pinMode(A0, INPUT);   // set pin to input mode
	//digitalWrite(A0, HIGH); // enable internal pull-up resistor
	pinMode(A0, INPUT);
	//pinMode(A0, INPUT_PULLUP);
}

void loop()
{
	float voltage = analogRead(A0) * (5.0 / 1023.0);
	Serial.println(voltage);
}
