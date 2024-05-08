// Wire Controller Reader
// by Nicholas Zambetti [http://www.zambetti.com](http://www.zambetti.com)

// Demonstrates use of the Wire library
// Reads data from an I2C/TWI peripheral device
// Refer to the "Wire Peripheral Sender" example for use with this

// Created 29 March 2006

// This example code is in the public domain.


#include <Wire.h>

void requestEvent();

void setup()
{
	Wire.begin(8);                // join i2c bus with address #8
	Wire.onRequest(requestEvent); // register event
}

void loop()
{
	delay(100);
}

void requestEvent()
{
	Wire.write("hello "); // respond with message of 6 bytes
}