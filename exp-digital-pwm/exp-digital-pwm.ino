#include <avrt.h>

namespace av = avrt;

av::Port<av::D3> portD3;
av::Port<av::D5> portD5;
av::Port<av::D6> portD6;
av::Port<av::D9> portD9;
av::Port<av::D10> portD10;
av::Port<av::D11> portD11;

AVRT_IMPLEMENT_Serial0(serial)

void setup()
{
	serial.Open(serial.BaudRate57600, serial.CharSize8, serial.StopBit1, serial.ParityNone);
	portD3.SetMode<av::Out>();
	portD5.SetMode<av::Out>();
	portD6.SetMode<av::Out>();
	portD9.SetMode<av::Out>();
	portD10.SetMode<av::Out>();
	portD11.SetMode<av::Out>();
	portD3.OutputPWM(128);
	portD5.OutputPWM(128);
	portD6.OutputPWM(128);
	portD9.OutputPWM(128);
	portD10.OutputPWM(128);
	portD11.OutputPWM(128);
	serial.Println("OutputPWM");
}

void loop()
{
}
