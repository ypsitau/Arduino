#include <avrt.h>
#include "Wire.h"

AVRT_IMPLEMENT_Serial0(serial)

void receiveEvent()
{
	serial.Printf(F("receiveEvent\n"));
	serial.Printf(F("%02x\n"), Wire.read());
	serial.Printf(F("%02x\n"), Wire.read());
	//Serial.print("onReceive: 0x");
	//Serial.println(Wire.read(), 16);
	//Serial.println(Wire.read(), 16);
}

void requestEvent()
{
	serial.Printf(F("requestEvent\n"));
	//Serial.print("onRequest: 0x");
	//Serial.println(Wire.read(), 16);
	//Wire.write("hello "); // respond with message of 6 bytes
}

void setup()
{
	serial.Open(serial.Speed::Bps57600);
	serial.Printf(F("I2C test\n"));
	//twi_init();
	//twi_setAddress(0x08);
	Wire.begin(0x08); // join i2c bus with address #8
	Wire.onReceive(receiveEvent); // register event
	Wire.onRequest(requestEvent); // register event
}

void loop()
{
}
