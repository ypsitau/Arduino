#include <avrt.h>

namespace av = avrt;

av::Port<av::D3> portD3;
av::Port<av::D5> portD5;
av::Port<av::D6> portD6;
av::Port<av::D9> portD9;
av::Port<av::D10> portD10;
av::Port<av::D11> portD11;
av::Port<av::A0> portA0;

av::ADConv<> adConv;

AVRT_IMPLEMENT_Serial0(serial)

void setup()
{
	serial.Open(serial.BaudRate57600, serial.CharSize8, serial.StopBit1, serial.ParityNone);
	adConv.InitAs8bit();
	portD3.SetMode<av::Out>();
	portD5.SetMode<av::Out>();
	portD6.SetMode<av::Out>();
	portD9.SetMode<av::Out>();
	portD10.SetMode<av::Out>();
	portD11.SetMode<av::Out>();
	portA0.SetMode<av::In>();
	portD3.EnablePWM();
	portD5.EnablePWM();
	portD6.EnablePWM();
	portD9.EnablePWM();
	portD10.EnablePWM();
	portD11.EnablePWM();
	serial.Println("OutputPWM");
}

uint8_t valuePrev = 0;

void loop()
{
	uint8_t value = portA0.InputAnalog_8bit();
	if (valuePrev != value) {
		serial.Printf("Duty: %3d/255\n", value);
		valuePrev = value;
	}
	portD3.OutputFinePWM(value);
	portD5.OutputFinePWM(value);
	portD6.OutputFinePWM(value);
	portD9.OutputFinePWM(value);
	portD10.OutputFinePWM(value);
	portD11.OutputFinePWM(value);
}
