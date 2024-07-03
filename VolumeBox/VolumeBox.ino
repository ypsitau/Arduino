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

uint8_t AdjustValue(uint8_t valueRaw)
{
	const uint8_t valueMin = 70, valueMax = 230;
	return static_cast<uint8_t>(static_cast<uint16_t>(valueRaw) * (valueMax - valueMin) / 255 + valueMin);
}

void loop()
{
	uint8_t valueOrange = AdjustValue(portA0.AnalogInput8bit());
	uint8_t valueYellow = AdjustValue(portA1.AnalogInput8bit());
	uint8_t valueGreen = AdjustValue(portA2.AnalogInput8bit());
	uint8_t valueBlue = AdjustValue(255 - portA3.AnalogInput8bit());
	serial.Printf("Result:%3d %3d %3d %3d\n", valueOrange, valueYellow, valueGreen, valueBlue);
	portD5.PWMOutput(valueOrange);
	portD6.PWMOutput(valueYellow);
	portD9.PWMOutput(valueGreen);
	portD10.PWMOutput(valueBlue);
}
