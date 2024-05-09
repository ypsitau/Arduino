#include "TwoWire.h"

namespace av = avrt;

AVRT_IMPLEMENT_Serial0_NoRecv(serial)

AVRT_IMPLEMENT_TwoWire(twi)

void setup()
{
	serial.Open(av::Serial::BaudRate57600);
	serial.Printf("hello\n");
	
}

void loop()
{
}
