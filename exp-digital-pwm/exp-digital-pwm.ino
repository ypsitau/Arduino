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

uint8_t valuePrev = 0;

AVRT_IMPLEMENT_Serial0(serial)

const char* ClockSelToString_OC0_OC1(uint8_t clockSel)
{
	return
		(clockSel == 0)? "No Clock" :
		(clockSel == 1)? "clk/1" :
		(clockSel == 2)? "clk/8" :
		(clockSel == 3)? "clk/64" :
		(clockSel == 4)? "clk/256" :
		(clockSel == 5)? "clk/1024" :
		(clockSel == 6)? "External Falling Edge" :
		(clockSel == 7)? "External Rising Edge" : "";
}

const char* ClockSelToString_OC2(uint8_t clockSel)
{
	return
		(clockSel == 0)? "No Clock" :
		(clockSel == 1)? "clk/1" :
		(clockSel == 2)? "clk/8" :
		(clockSel == 3)? "clk/32" :
		(clockSel == 4)? "clk/64" :
		(clockSel == 5)? "clk/128" :
		(clockSel == 6)? "clk/256" :
		(clockSel == 7)? "clk/1024" : "";
}

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
	serial.Printf("D5, D6  .. OC0:%s\n", ClockSelToString_OC0_OC1((TCCR0B >> CS00) & 0b111));
	serial.Printf("D9, D10 .. OC1:%s\n", ClockSelToString_OC0_OC1((TCCR1B >> CS10) & 0b111));
	serial.Printf("D3, D11 .. OC2:%s\n", ClockSelToString_OC2((TCCR2B >> CS20) & 0b111));
}

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
