#include <avrt.h>

namespace av = avrt;

av::Port<av::A0> portA0;

AVRT_IMPLEMENT_Serial0(serial)
AVRT_IMPLEMENT_Timer1(timer)
AVRT_IMPLEMENT_ADConv_AutoTrigger(adConv)

void setup()
{
	av::Ports::Init();
	serial.Open(serial.Speed::Bps57600);
	timer.Start();
	adConv.Init();
	//adConv.Init(adConv.Clock::Div128, adConv.VoltRef::AVcc);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::FreeRunning);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_ANALOG_COMP);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_INT0);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_TIMER0_COMPA);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_TIMER0_OVF);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_TIMER1_COMPB);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_TIMER1_OVF);
	//adConv.StartAutoTrigger(av::A0, adConv.Trigger::Int_TIMER1_CAPT>();
	serial.Printf("ADConv Test\n");
}

void loop()
{
	uint8_t value = portA0.AnalogInput8bit();
	//serial.Printf("Result:%d\n", value);
	//if (adConv.IsResultReady()) {
	//	serial.Printf("Result:%d\n", adConv.ReadResult());
	//}
}
