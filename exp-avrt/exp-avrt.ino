#include <avrt.h>

namespace av = avrt;

av::Serial0<> serial;
RegisterISR_Serial0(serial)

void Test_Serial_ReceiveData()
{
	serial.Println("Test of RecvData");
	for (;;) {
		if (serial.HasRecvData()) {
			serial.Print("Received: ");
			while (serial.HasRecvData()) {
				serial.SendData(serial.RecvData());
			}
		}
	}
}

void setup()
{
	serial.Open(av::Serial::BaudRate57600, av::Serial::CharSize8, av::Serial::ParityNone, av::Serial::StopBit1);
	Test_Serial_ReceiveData();
}

void loop()
{
}
