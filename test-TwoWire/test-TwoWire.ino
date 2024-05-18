#include "TwoWire.h"

namespace av = avrt;

AVRT_IMPLEMENT_TwoWire(twi)
AVRT_IMPLEMENT_Serial0_NoRecv(serial)

void setup()
{
	twi.Open();
	serial.Open(serial.Speed::Bps57600);
	serial.Printf("hello\n");
	
}

void loop()
{
}
