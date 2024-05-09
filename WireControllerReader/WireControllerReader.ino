// Wire Controller Reader
// by Nicholas Zambetti [http://www.zambetti.com](http://www.zambetti.com)

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI peripheral device
// Refer to the "Wire Peripheral Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void receiveEvent();
void requestEvent();

void setup()
{
	Serial.begin(57600);
	Serial.print("Waiting for data from I2C at 0x08\n");
	Wire.begin(0x08); // join i2c bus with address #8
	Wire.onReceive(receiveEvent); // register event
	Wire.onRequest(requestEvent); // register event
}

void loop()
{
	delay(100);
}

void receiveEvent()
{
	Serial.print("onReceive: 0x");
	Serial.println(Wire.read(), 16);
	Serial.println(Wire.read(), 16);
}

void requestEvent()
{
	Serial.print("onRequest: 0x");
	Serial.println(Wire.read(), 16);
	Wire.write("hello "); // respond with message of 6 bytes
}

