#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0(serial)

void setup()
{
	serial.Open(av::Serial::BaudRate57600, av::Serial::CharSize8, av::Serial::ParityNone, av::Serial::StopBit1);
	serial.Println("Test of RecvData");
}


void loop()
{
	if (serial.HasRecvData()) {
		serial.Print("Received: ");
		while (serial.HasRecvData()) {
			serial.SendData(serial.RecvData());
		}
	}
}
