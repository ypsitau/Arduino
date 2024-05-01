#include "avrt.h"

namespace at = avrt;

volatile uint8_t data;
volatile bool flag = true;

constexpr at::Port<at::D0> portD0;
constexpr at::Port<at::D1> portD1;
constexpr at::Port<at::D2> portD2;
constexpr at::Port<at::D3> portD3;
constexpr at::Port<at::D4> portD4;
constexpr at::Port<at::D5> portD5;
constexpr at::Port<at::D6> portD6;
constexpr at::Port<at::D7> portD7;
constexpr at::Port<at::D8> portD8;
constexpr at::Port<at::D9> portD9;
constexpr at::Port<at::D10> portD10;
constexpr at::Port<at::D11> portD11;
constexpr at::Port<at::D12> portD12;
constexpr at::Port<at::D13> portD13;
constexpr at::Port<at::D14> portD14;
constexpr at::Port<at::D15> portD15;
constexpr at::Port<at::D16> portD16;
constexpr at::Port<at::D17> portD17;
constexpr at::Port<at::D18> portD18;
constexpr at::Port<at::D19> portD19;
constexpr at::Port<at::D20> portD20;

constexpr at::Port<at::A0> portA0;
constexpr at::Port<at::A1> portA1;
constexpr at::Port<at::A2> portA2;
constexpr at::Port<at::A3> portA3;
constexpr at::Port<at::A4> portA4;
constexpr at::Port<at::A5> portA5;
constexpr at::Port<at::A6> portA6;

void CompileTest_InitPort()
{
	at::InitPort<
		at::In,			// D0: PD0(RXD/PCINT16)
		at::In,			// D1: PD1(TXD/PCINT17)
		at::In,			// D2: PD2(INT0/PCINT18)
		at::In,			// D3: PD3(INT1/OC2B/PCINT19)
		at::In,			// D4: PD4(XCK/T0/PCINT20)
		at::In,			// D5: PD5(T1/OC0B/PCINT21)
		at::In,			// D6: PD6(AIN0/OC0A/PCINT22)
		at::In,			// D7: PD7(AIN1/PCINT23)
		at::In,			// D8: PB0(ICP1/CLKO/PCINT0)
		at::In,			// D9: PB1(OC1A/PCINT1)
		at::In,			// D10: PB2(SS/OC1B/PCINT2)
		at::In,			// D11: PB3(MOSI/OC2A/PCINT3)
		at::In,			// D12: PB4(MISO/PCINT4)
		at::In,			// D13: PB5(SCK/PCINT5)
		at::In,			// D14: PC0(ADC0/PCINT8)
		at::In,			// D15: PC1(ADC1/PCINT9)
		at::In,			// D16: PC2(ADC2/PCINT10)
		at::In,			// D17: PC3(ADC3/PCINT11)
		at::In,			// D18: PC4(ADC4/SDA/PCINT12)
		at::In,			// D19: PC5(ADC5/SCL/PCINT13)
		at::In			// D20: PC6(RESET/PCINT14)
	>();
	at::InitPort<
		at::Out,		// D0: PD0(RXD/PCINT16)
		at::Out,		// D1: PD1(TXD/PCINT17)
		at::Out,		// D2: PD2(INT0/PCINT18)
		at::Out,		// D3: PD3(INT1/OC2B/PCINT19)
		at::Out,		// D4: PD4(XCK/T0/PCINT20)
		at::Out,		// D5: PD5(T1/OC0B/PCINT21)
		at::Out,		// D6: PD6(AIN0/OC0A/PCINT22)
		at::Out,		// D7: PD7(AIN1/PCINT23)
		at::Out,		// D8: PB0(ICP1/CLKO/PCINT0)
		at::Out,		// D9: PB1(OC1A/PCINT1)
		at::Out,		// D10: PB2(SS/OC1B/PCINT2)
		at::Out,		// D11: PB3(MOSI/OC2A/PCINT3)
		at::Out,		// D12: PB4(MISO/PCINT4)
		at::Out,		// D13: PB5(SCK/PCINT5)
		at::Out,		// D14: PC0(ADC0/PCINT8)
		at::Out,		// D15: PC1(ADC1/PCINT9)
		at::Out,		// D16: PC2(ADC2/PCINT10)
		at::Out,		// D17: PC3(ADC3/PCINT11)
		at::Out,		// D18: PC4(ADC4/SDA/PCINT12)
		at::Out,		// D19: PC5(ADC5/SCL/PCINT13)
		at::Out			// D20: PC6(RESET/PCINT14)
	>();
	at::InitPort<
		at::InPullup,	// D0: PD0(RXD/PCINT16)
		at::InPullup,	// D1: PD1(TXD/PCINT17)
		at::InPullup,	// D2: PD2(INT0/PCINT18)
		at::InPullup,	// D3: PD3(INT1/OC2B/PCINT19)
		at::InPullup,	// D4: PD4(XCK/T0/PCINT20)
		at::InPullup,	// D5: PD5(T1/OC0B/PCINT21)
		at::InPullup,	// D6: PD6(AIN0/OC0A/PCINT22)
		at::InPullup,	// D7: PD7(AIN1/PCINT23)
		at::InPullup,	// D8: PB0(ICP1/CLKO/PCINT0)
		at::InPullup,	// D9: PB1(OC1A/PCINT1)
		at::InPullup,	// D10: PB2(SS/OC1B/PCINT2)
		at::InPullup,	// D11: PB3(MOSI/OC2A/PCINT3)
		at::InPullup,	// D12: PB4(MISO/PCINT4)
		at::InPullup,	// D13: PB5(SCK/PCINT5)
		at::InPullup,	// D14: PC0(ADC0/PCINT8)
		at::InPullup,	// D15: PC1(ADC1/PCINT9)
		at::InPullup,	// D16: PC2(ADC2/PCINT10)
		at::InPullup,	// D17: PC3(ADC3/PCINT11)
		at::InPullup,	// D18: PC4(ADC4/SDA/PCINT12)
		at::InPullup,	// D19: PC5(ADC5/SCL/PCINT13)
		at::InPullup	// D20: PC6(RESET/PCINT14)
	>();
}

void CompileTest_Port_SetMode()
{
	portD0.SetMode<at::In>();
	portD1.SetMode<at::In>();
	portD2.SetMode<at::In>();
	portD3.SetMode<at::In>();
	portD4.SetMode<at::In>();
	portD5.SetMode<at::In>();
	portD6.SetMode<at::In>();
	portD7.SetMode<at::In>();
	portD8.SetMode<at::In>();
	portD9.SetMode<at::In>();
	portD10.SetMode<at::In>();
	portD11.SetMode<at::In>();
	portD12.SetMode<at::In>();
	portD13.SetMode<at::In>();
	portD14.SetMode<at::In>();
	portD15.SetMode<at::In>();
	portD16.SetMode<at::In>();
	portD17.SetMode<at::In>();
	portD18.SetMode<at::In>();
	portD19.SetMode<at::In>();
	portD20.SetMode<at::In>();
	portD0.SetMode<at::Out>();
	portD1.SetMode<at::Out>();
	portD2.SetMode<at::Out>();
	portD3.SetMode<at::Out>();
	portD4.SetMode<at::Out>();
	portD5.SetMode<at::Out>();
	portD6.SetMode<at::Out>();
	portD7.SetMode<at::Out>();
	portD8.SetMode<at::Out>();
	portD9.SetMode<at::Out>();
	portD10.SetMode<at::Out>();
	portD11.SetMode<at::Out>();
	portD12.SetMode<at::Out>();
	portD13.SetMode<at::Out>();
	portD14.SetMode<at::Out>();
	portD15.SetMode<at::Out>();
	portD16.SetMode<at::Out>();
	portD17.SetMode<at::Out>();
	portD18.SetMode<at::Out>();
	portD19.SetMode<at::Out>();
	portD20.SetMode<at::Out>();
	portD0.SetMode<at::InPullup>();
	portD1.SetMode<at::InPullup>();
	portD2.SetMode<at::InPullup>();
	portD3.SetMode<at::InPullup>();
	portD4.SetMode<at::InPullup>();
	portD5.SetMode<at::InPullup>();
	portD6.SetMode<at::InPullup>();
	portD7.SetMode<at::InPullup>();
	portD8.SetMode<at::InPullup>();
	portD9.SetMode<at::InPullup>();
	portD10.SetMode<at::InPullup>();
	portD11.SetMode<at::InPullup>();
	portD12.SetMode<at::InPullup>();
	portD13.SetMode<at::InPullup>();
	portD14.SetMode<at::InPullup>();
	portD15.SetMode<at::InPullup>();
	portD16.SetMode<at::InPullup>();
	portD17.SetMode<at::InPullup>();
	portD18.SetMode<at::InPullup>();
	portD19.SetMode<at::InPullup>();
	portD20.SetMode<at::InPullup>();
	at::Port<at::D0>().SetMode<at::In>();
	at::Port<at::D1>().SetMode<at::In>();
	at::Port<at::D2>().SetMode<at::In>();
	at::Port<at::D3>().SetMode<at::In>();
	at::Port<at::D4>().SetMode<at::In>();
	at::Port<at::D5>().SetMode<at::In>();
	at::Port<at::D6>().SetMode<at::In>();
	at::Port<at::D7>().SetMode<at::In>();
	at::Port<at::D8>().SetMode<at::In>();
	at::Port<at::D9>().SetMode<at::In>();
	at::Port<at::D10>().SetMode<at::In>();
	at::Port<at::D11>().SetMode<at::In>();
	at::Port<at::D12>().SetMode<at::In>();
	at::Port<at::D13>().SetMode<at::In>();
	at::Port<at::D14>().SetMode<at::In>();
	at::Port<at::D15>().SetMode<at::In>();
	at::Port<at::D16>().SetMode<at::In>();
	at::Port<at::D17>().SetMode<at::In>();
	at::Port<at::D18>().SetMode<at::In>();
	at::Port<at::D19>().SetMode<at::In>();
	at::Port<at::D20>().SetMode<at::In>();
	at::Port<at::D0>().SetMode<at::Out>();
	at::Port<at::D1>().SetMode<at::Out>();
	at::Port<at::D2>().SetMode<at::Out>();
	at::Port<at::D3>().SetMode<at::Out>();
	at::Port<at::D4>().SetMode<at::Out>();
	at::Port<at::D5>().SetMode<at::Out>();
	at::Port<at::D6>().SetMode<at::Out>();
	at::Port<at::D7>().SetMode<at::Out>();
	at::Port<at::D8>().SetMode<at::Out>();
	at::Port<at::D9>().SetMode<at::Out>();
	at::Port<at::D10>().SetMode<at::Out>();
	at::Port<at::D11>().SetMode<at::Out>();
	at::Port<at::D12>().SetMode<at::Out>();
	at::Port<at::D13>().SetMode<at::Out>();
	at::Port<at::D14>().SetMode<at::Out>();
	at::Port<at::D15>().SetMode<at::Out>();
	at::Port<at::D16>().SetMode<at::Out>();
	at::Port<at::D17>().SetMode<at::Out>();
	at::Port<at::D18>().SetMode<at::Out>();
	at::Port<at::D19>().SetMode<at::Out>();
	at::Port<at::D20>().SetMode<at::Out>();
	at::Port<at::D0>().SetMode<at::InPullup>();
	at::Port<at::D1>().SetMode<at::InPullup>();
	at::Port<at::D2>().SetMode<at::InPullup>();
	at::Port<at::D3>().SetMode<at::InPullup>();
	at::Port<at::D4>().SetMode<at::InPullup>();
	at::Port<at::D5>().SetMode<at::InPullup>();
	at::Port<at::D6>().SetMode<at::InPullup>();
	at::Port<at::D7>().SetMode<at::InPullup>();
	at::Port<at::D8>().SetMode<at::InPullup>();
	at::Port<at::D9>().SetMode<at::InPullup>();
	at::Port<at::D10>().SetMode<at::InPullup>();
	at::Port<at::D11>().SetMode<at::InPullup>();
	at::Port<at::D12>().SetMode<at::InPullup>();
	at::Port<at::D13>().SetMode<at::InPullup>();
	at::Port<at::D14>().SetMode<at::InPullup>();
	at::Port<at::D15>().SetMode<at::InPullup>();
	at::Port<at::D16>().SetMode<at::InPullup>();
	at::Port<at::D17>().SetMode<at::InPullup>();
	at::Port<at::D18>().SetMode<at::InPullup>();
	at::Port<at::D19>().SetMode<at::InPullup>();
	at::Port<at::D20>().SetMode<at::InPullup>();
}

void CompileTest_Port_Output()
{
	portD0.Output<false>();
	portD1.Output<false>();
	portD2.Output<false>();
	portD3.Output<false>();
	portD4.Output<false>();
	portD5.Output<false>();
	portD6.Output<false>();
	portD7.Output<false>();
	portD8.Output<false>();
	portD9.Output<false>();
	portD10.Output<false>();
	portD11.Output<false>();
	portD12.Output<false>();
	portD13.Output<false>();
	portD14.Output<false>();
	portD15.Output<false>();
	portD16.Output<false>();
	portD17.Output<false>();
	portD18.Output<false>();
	portD19.Output<false>();
	portD20.Output<false>();
	portD0.Output<true>();
	portD1.Output<true>();
	portD2.Output<true>();
	portD3.Output<true>();
	portD4.Output<true>();
	portD5.Output<true>();
	portD6.Output<true>();
	portD7.Output<true>();
	portD8.Output<true>();
	portD9.Output<true>();
	portD10.Output<true>();
	portD11.Output<true>();
	portD12.Output<true>();
	portD13.Output<true>();
	portD14.Output<true>();
	portD15.Output<true>();
	portD16.Output<true>();
	portD17.Output<true>();
	portD18.Output<true>();
	portD19.Output<true>();
	portD20.Output<true>();
	portD0.Output(flag);
	portD1.Output(flag);
	portD2.Output(flag);
	portD3.Output(flag);
	portD4.Output(flag);
	portD5.Output(flag);
	portD6.Output(flag);
	portD7.Output(flag);
	portD8.Output(flag);
	portD9.Output(flag);
	portD10.Output(flag);
	portD11.Output(flag);
	portD12.Output(flag);
	portD13.Output(flag);
	portD14.Output(flag);
	portD15.Output(flag);
	portD16.Output(flag);
	portD17.Output(flag);
	portD18.Output(flag);
	portD19.Output(flag);
	portD20.Output(flag);
	at::Port<at::D0>().Output<false>();
	at::Port<at::D1>().Output<false>();
	at::Port<at::D2>().Output<false>();
	at::Port<at::D3>().Output<false>();
	at::Port<at::D4>().Output<false>();
	at::Port<at::D5>().Output<false>();
	at::Port<at::D6>().Output<false>();
	at::Port<at::D7>().Output<false>();
	at::Port<at::D8>().Output<false>();
	at::Port<at::D9>().Output<false>();
	at::Port<at::D10>().Output<false>();
	at::Port<at::D11>().Output<false>();
	at::Port<at::D12>().Output<false>();
	at::Port<at::D13>().Output<false>();
	at::Port<at::D14>().Output<false>();
	at::Port<at::D15>().Output<false>();
	at::Port<at::D16>().Output<false>();
	at::Port<at::D17>().Output<false>();
	at::Port<at::D18>().Output<false>();
	at::Port<at::D19>().Output<false>();
	at::Port<at::D20>().Output<false>();
	at::Port<at::D0>().Output<true>();
	at::Port<at::D1>().Output<true>();
	at::Port<at::D2>().Output<true>();
	at::Port<at::D3>().Output<true>();
	at::Port<at::D4>().Output<true>();
	at::Port<at::D5>().Output<true>();
	at::Port<at::D6>().Output<true>();
	at::Port<at::D7>().Output<true>();
	at::Port<at::D8>().Output<true>();
	at::Port<at::D9>().Output<true>();
	at::Port<at::D10>().Output<true>();
	at::Port<at::D11>().Output<true>();
	at::Port<at::D12>().Output<true>();
	at::Port<at::D13>().Output<true>();
	at::Port<at::D14>().Output<true>();
	at::Port<at::D15>().Output<true>();
	at::Port<at::D16>().Output<true>();
	at::Port<at::D17>().Output<true>();
	at::Port<at::D18>().Output<true>();
	at::Port<at::D19>().Output<true>();
	at::Port<at::D20>().Output<true>();
	at::Port<at::D0>().Output(flag);
	at::Port<at::D1>().Output(flag);
	at::Port<at::D2>().Output(flag);
	at::Port<at::D3>().Output(flag);
	at::Port<at::D4>().Output(flag);
	at::Port<at::D5>().Output(flag);
	at::Port<at::D6>().Output(flag);
	at::Port<at::D7>().Output(flag);
	at::Port<at::D8>().Output(flag);
	at::Port<at::D9>().Output(flag);
	at::Port<at::D10>().Output(flag);
	at::Port<at::D11>().Output(flag);
	at::Port<at::D12>().Output(flag);
	at::Port<at::D13>().Output(flag);
	at::Port<at::D14>().Output(flag);
	at::Port<at::D15>().Output(flag);
	at::Port<at::D16>().Output(flag);
	at::Port<at::D17>().Output(flag);
	at::Port<at::D18>().Output(flag);
	at::Port<at::D19>().Output(flag);
	at::Port<at::D20>().Output(flag);
}

void CompileTest_Port_Input()
{
	data = portD0.Input();
	data = portD1.Input();
	data = portD2.Input();
	data = portD3.Input();
	data = portD4.Input();
	data = portD5.Input();
	data = portD6.Input();
	data = portD7.Input();
	data = portD8.Input();
	data = portD9.Input();
	data = portD10.Input();
	data = portD11.Input();
	data = portD12.Input();
	data = portD13.Input();
	data = portD14.Input();
	data = portD15.Input();
	data = portD16.Input();
	data = portD17.Input();
	data = portD18.Input();
	data = portD19.Input();
	data = portD20.Input();
	data = at::Port<at::D0>().Input();
	data = at::Port<at::D1>().Input();
	data = at::Port<at::D2>().Input();
	data = at::Port<at::D3>().Input();
	data = at::Port<at::D4>().Input();
	data = at::Port<at::D5>().Input();
	data = at::Port<at::D6>().Input();
	data = at::Port<at::D7>().Input();
	data = at::Port<at::D8>().Input();
	data = at::Port<at::D9>().Input();
	data = at::Port<at::D10>().Input();
	data = at::Port<at::D11>().Input();
	data = at::Port<at::D12>().Input();
	data = at::Port<at::D13>().Input();
	data = at::Port<at::D14>().Input();
	data = at::Port<at::D15>().Input();
	data = at::Port<at::D16>().Input();
	data = at::Port<at::D17>().Input();
	data = at::Port<at::D18>().Input();
	data = at::Port<at::D19>().Input();
	data = at::Port<at::D20>().Input();
}

void CompileTest_Port_EnablePWM()
{
	portD0.EnablePWM();
	portD1.EnablePWM();
	portD2.EnablePWM();
	portD3.EnablePWM();
	portD4.EnablePWM();
	portD5.EnablePWM();
	portD6.EnablePWM();
	portD7.EnablePWM();
	portD8.EnablePWM();
	portD9.EnablePWM();
	portD10.EnablePWM();
	portD11.EnablePWM();
	portD12.EnablePWM();
	portD13.EnablePWM();
	portD14.EnablePWM();
	portD15.EnablePWM();
	portD16.EnablePWM();
	portD17.EnablePWM();
	portD18.EnablePWM();
	portD19.EnablePWM();
	portD20.EnablePWM();
	at::Port<at::D0>().EnablePWM();
	at::Port<at::D1>().EnablePWM();
	at::Port<at::D2>().EnablePWM();
	at::Port<at::D3>().EnablePWM();
	at::Port<at::D4>().EnablePWM();
	at::Port<at::D5>().EnablePWM();
	at::Port<at::D6>().EnablePWM();
	at::Port<at::D7>().EnablePWM();
	at::Port<at::D8>().EnablePWM();
	at::Port<at::D9>().EnablePWM();
	at::Port<at::D10>().EnablePWM();
	at::Port<at::D11>().EnablePWM();
	at::Port<at::D12>().EnablePWM();
	at::Port<at::D13>().EnablePWM();
	at::Port<at::D14>().EnablePWM();
	at::Port<at::D15>().EnablePWM();
	at::Port<at::D16>().EnablePWM();
	at::Port<at::D17>().EnablePWM();
	at::Port<at::D18>().EnablePWM();
	at::Port<at::D19>().EnablePWM();
	at::Port<at::D20>().EnablePWM();
}

void CompileTest_Port_DisablePWM()
{
	portD0.DisablePWM();
	portD1.DisablePWM();
	portD2.DisablePWM();
	portD3.DisablePWM();
	portD4.DisablePWM();
	portD5.DisablePWM();
	portD6.DisablePWM();
	portD7.DisablePWM();
	portD8.DisablePWM();
	portD9.DisablePWM();
	portD10.DisablePWM();
	portD11.DisablePWM();
	portD12.DisablePWM();
	portD13.DisablePWM();
	portD14.DisablePWM();
	portD15.DisablePWM();
	portD16.DisablePWM();
	portD17.DisablePWM();
	portD18.DisablePWM();
	portD19.DisablePWM();
	portD20.DisablePWM();
	at::Port<at::D0>().DisablePWM();
	at::Port<at::D1>().DisablePWM();
	at::Port<at::D2>().DisablePWM();
	at::Port<at::D3>().DisablePWM();
	at::Port<at::D4>().DisablePWM();
	at::Port<at::D5>().DisablePWM();
	at::Port<at::D6>().DisablePWM();
	at::Port<at::D7>().DisablePWM();
	at::Port<at::D8>().DisablePWM();
	at::Port<at::D9>().DisablePWM();
	at::Port<at::D10>().DisablePWM();
	at::Port<at::D11>().DisablePWM();
	at::Port<at::D12>().DisablePWM();
	at::Port<at::D13>().DisablePWM();
	at::Port<at::D14>().DisablePWM();
	at::Port<at::D15>().DisablePWM();
	at::Port<at::D16>().DisablePWM();
	at::Port<at::D17>().DisablePWM();
	at::Port<at::D18>().DisablePWM();
	at::Port<at::D19>().DisablePWM();
	at::Port<at::D20>().DisablePWM();
}

void CompileTest_Port_OutputPWM()
{
	portD0.OutputPWM(128);
	portD1.OutputPWM(128);
	portD2.OutputPWM(128);
	portD3.OutputPWM(128);
	portD4.OutputPWM(128);
	portD5.OutputPWM(128);
	portD6.OutputPWM(128);
	portD7.OutputPWM(128);
	portD8.OutputPWM(128);
	portD9.OutputPWM(128);
	portD10.OutputPWM(128);
	portD11.OutputPWM(128);
	portD12.OutputPWM(128);
	portD13.OutputPWM(128);
	portD14.OutputPWM(128);
	portD15.OutputPWM(128);
	portD16.OutputPWM(128);
	portD17.OutputPWM(128);
	portD18.OutputPWM(128);
	portD19.OutputPWM(128);
	portD20.OutputPWM(128);
	at::Port<at::D0>().OutputPWM(128);
	at::Port<at::D1>().OutputPWM(128);
	at::Port<at::D2>().OutputPWM(128);
	at::Port<at::D3>().OutputPWM(128);
	at::Port<at::D4>().OutputPWM(128);
	at::Port<at::D5>().OutputPWM(128);
	at::Port<at::D6>().OutputPWM(128);
	at::Port<at::D7>().OutputPWM(128);
	at::Port<at::D8>().OutputPWM(128);
	at::Port<at::D9>().OutputPWM(128);
	at::Port<at::D10>().OutputPWM(128);
	at::Port<at::D11>().OutputPWM(128);
	at::Port<at::D12>().OutputPWM(128);
	at::Port<at::D13>().OutputPWM(128);
	at::Port<at::D14>().OutputPWM(128);
	at::Port<at::D15>().OutputPWM(128);
	at::Port<at::D16>().OutputPWM(128);
	at::Port<at::D17>().OutputPWM(128);
	at::Port<at::D18>().OutputPWM(128);
	at::Port<at::D19>().OutputPWM(128);
	at::Port<at::D20>().OutputPWM(128);
}

void CompileTest_InitADConv()
{
	at::InitADConv<
		0b00,	// REFS: Reference Selction Bits
		0b0,	// ADLAR: ADC Left Adjust Result
		0b0000,	// MUX: Analog Channel Selection Bits
		0b0,	// ADEN: ADC Enable
		0b0,	// ADSC: ADC Start Conversion
		0b0,	// ADATE: ADC Auto Trigger Enable
		0b0,	// ADIF: ADC Interrupt Flag
		0b0,	// ADIE: ADC Interrupt Enable
		0b000,	// ADPS: ADC Prescaler Select Bits
		0b0,	// ACME: Analog Comparator Multiplexer Enable
		0b000	// ADTS: ADC Auto Trigger Source
	>();
}

void CompileTest_ADConv_Start()
{
	at::ADConv<at::A0>().Start();
	at::ADConv<at::A1>().Start();
	at::ADConv<at::A2>().Start();
	at::ADConv<at::A3>().Start();
	at::ADConv<at::A4>().Start();
	at::ADConv<at::A5>().Start();
	at::ADConv<at::A6>().Start();
}

void CompileTest_ADConv_Wait()
{
	at::ADConv<at::A0>().Wait();
	at::ADConv<at::A1>().Wait();
	at::ADConv<at::A2>().Wait();
	at::ADConv<at::A3>().Wait();
	at::ADConv<at::A4>().Wait();
	at::ADConv<at::A5>().Wait();
	at::ADConv<at::A6>().Wait();
}

void CompileTest_ADConv_Read()
{
	data = at::ADConv<at::A0>().Read();
	data = at::ADConv<at::A1>().Read();
	data = at::ADConv<at::A2>().Read();
	data = at::ADConv<at::A3>().Read();
	data = at::ADConv<at::A4>().Read();
	data = at::ADConv<at::A5>().Read();
	data = at::ADConv<at::A6>().Read();
}

void setup()
{
	CompileTest_InitPort();
	CompileTest_Port_SetMode();
	CompileTest_Port_Output();
	CompileTest_Port_Input();
	CompileTest_Port_EnablePWM();
	CompileTest_Port_DisablePWM();
	CompileTest_Port_OutputPWM();
	CompileTest_InitADConv();
	CompileTest_ADConv_Start();
	CompileTest_ADConv_Wait();
	CompileTest_ADConv_Read();
}

void loop()
{
}
