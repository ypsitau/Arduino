#include <avrt.h>
#include "twi.h"

AVRT_IMPLEMENT_Serial0(serial)

void setup()
{
	serial.Open(serial.Speed::Bps57600);
	twi_init();
	serial.Printf(F("I2C test\n"));
}

void loop()
{
}
