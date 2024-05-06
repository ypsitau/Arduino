#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0(serial)

av::Port<av::A0> portA0;
av::Port<av::A1> portA1;
av::Port<av::A2> portA2;
av::Port<av::A3> portA3;
av::Port<av::A4> portA4;
av::Port<av::A5> portA5;
av::Port<av::A5> portA6;

void setup()
{
	serial.Open(av::Serial::BaudRate57600);
	av::InitPort<>();
	av::InitADC<>();
	serial.Println(F("Analog Print"));
}

void loop()
{
	serial.Printf(F("A0:%-4d A1:%-4d A2:%-4d A3:%-4d A4:%-4d A5:%-4d A6:%-4d\n"),
		portA0.InputAnalog(), portA1.InputAnalog(), portA2.InputAnalog(),
		portA3.InputAnalog(), portA4.InputAnalog(), portA5.InputAnalog(), portA6.InputAnalog());
}
