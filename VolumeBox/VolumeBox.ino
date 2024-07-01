#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0(serial)
AVRT_IMPLEMENT_ADConv(adConv)

av::Timer0 timer0;
av::Timer1 timer1;

av::Port<av::A0> portA0;
av::Port<av::A1> portA1;
av::Port<av::A2> portA2;
av::Port<av::A3> portA3;

av::Port<av::D5, av::Out> portD5;
av::Port<av::D6, av::Out> portD6;
av::Port<av::D9, av::Out> portD9;
av::Port<av::D10, av::Out> portD10;

void setup()
{
	av::Ports::Init();
	serial.Open(serial.Speed::Bps57600);
	adConv.Init();
	timer0.Start(timer0.Clock::Div64, timer0.Waveform::PhaseCorrectPWM_UptoFF);
	timer1.Start(timer1.Clock::Div64, timer1.Waveform::PhaseCorrectPWM_Upto00FF);
	portD5.PWMEnable();
	portD6.PWMEnable();
	portD9.PWMEnable();
	portD10.PWMEnable();
}

void loop()
{
	uint8_t value0 = portA0.AnalogInput8bit();
	uint8_t value1 = portA1.AnalogInput8bit();
	uint8_t value2 = portA2.AnalogInput8bit();
	uint8_t value3 = portA3.AnalogInput8bit();
	serial.Printf("Result:%3d %3d %3d %3d\n", value0, value1, value2, value3);
	portD5.PWMOutput(value0);
	portD6.PWMOutput(value1);
	portD9.PWMOutput(value2);
	portD10.PWMOutput(value3);
}
