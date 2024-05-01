#include "avrt.h"

namespace av = avrt;

volatile uint16_t data = 0;
volatile av::Signal sig = av::Low;

constexpr av::Port<av::D0> portD0;
constexpr av::Port<av::D1> portD1;
constexpr av::Port<av::D2> portD2;
constexpr av::Port<av::D3> portD3;
constexpr av::Port<av::D4> portD4;
constexpr av::Port<av::D5> portD5;
constexpr av::Port<av::D6> portD6;
constexpr av::Port<av::D7> portD7;
constexpr av::Port<av::D8> portD8;
constexpr av::Port<av::D9> portD9;
constexpr av::Port<av::D10> portD10;
constexpr av::Port<av::D11> portD11;
constexpr av::Port<av::D12> portD12;
constexpr av::Port<av::D13> portD13;
constexpr av::Port<av::D14> portD14;
constexpr av::Port<av::D15> portD15;
constexpr av::Port<av::D16> portD16;
constexpr av::Port<av::D17> portD17;
constexpr av::Port<av::D18> portD18;
constexpr av::Port<av::D19> portD19;
constexpr av::Port<av::D20> portD20;

constexpr av::Port<av::A0> portA0;
constexpr av::Port<av::A1> portA1;
constexpr av::Port<av::A2> portA2;
constexpr av::Port<av::A3> portA3;
constexpr av::Port<av::A4> portA4;
constexpr av::Port<av::A5> portA5;
constexpr av::Port<av::A6> portA6;

void CompileTest_InitPort()
{
	av::InitPort<
		av::In,			// D0: PD0(RXD/PCINT16)
		av::In,			// D1: PD1(TXD/PCINT17)
		av::In,			// D2: PD2(INT0/PCINT18)
		av::In,			// D3: PD3(INT1/OC2B/PCINT19)
		av::In,			// D4: PD4(XCK/T0/PCINT20)
		av::In,			// D5: PD5(T1/OC0B/PCINT21)
		av::In,			// D6: PD6(AIN0/OC0A/PCINT22)
		av::In,			// D7: PD7(AIN1/PCINT23)
		av::In,			// D8: PB0(ICP1/CLKO/PCINT0)
		av::In,			// D9: PB1(OC1A/PCINT1)
		av::In,			// D10: PB2(SS/OC1B/PCINT2)
		av::In,			// D11: PB3(MOSI/OC2A/PCINT3)
		av::In,			// D12: PB4(MISO/PCINT4)
		av::In,			// D13: PB5(SCK/PCINT5)
		av::In,			// D14: PC0(ADC0/PCINT8)
		av::In,			// D15: PC1(ADC1/PCINT9)
		av::In,			// D16: PC2(ADC2/PCINT10)
		av::In,			// D17: PC3(ADC3/PCINT11)
		av::In,			// D18: PC4(ADC4/SDA/PCINT12)
		av::In,			// D19: PC5(ADC5/SCL/PCINT13)
		av::In			// D20: PC6(RESET/PCINT14)
	>();
	av::InitPort<
		av::Out,		// D0: PD0(RXD/PCINT16)
		av::Out,		// D1: PD1(TXD/PCINT17)
		av::Out,		// D2: PD2(INT0/PCINT18)
		av::Out,		// D3: PD3(INT1/OC2B/PCINT19)
		av::Out,		// D4: PD4(XCK/T0/PCINT20)
		av::Out,		// D5: PD5(T1/OC0B/PCINT21)
		av::Out,		// D6: PD6(AIN0/OC0A/PCINT22)
		av::Out,		// D7: PD7(AIN1/PCINT23)
		av::Out,		// D8: PB0(ICP1/CLKO/PCINT0)
		av::Out,		// D9: PB1(OC1A/PCINT1)
		av::Out,		// D10: PB2(SS/OC1B/PCINT2)
		av::Out,		// D11: PB3(MOSI/OC2A/PCINT3)
		av::Out,		// D12: PB4(MISO/PCINT4)
		av::Out,		// D13: PB5(SCK/PCINT5)
		av::Out,		// D14: PC0(ADC0/PCINT8)
		av::Out,		// D15: PC1(ADC1/PCINT9)
		av::Out,		// D16: PC2(ADC2/PCINT10)
		av::Out,		// D17: PC3(ADC3/PCINT11)
		av::Out,		// D18: PC4(ADC4/SDA/PCINT12)
		av::Out,		// D19: PC5(ADC5/SCL/PCINT13)
		av::Out			// D20: PC6(RESET/PCINT14)
	>();
	av::InitPort<
		av::InPullup,	// D0: PD0(RXD/PCINT16)
		av::InPullup,	// D1: PD1(TXD/PCINT17)
		av::InPullup,	// D2: PD2(INT0/PCINT18)
		av::InPullup,	// D3: PD3(INT1/OC2B/PCINT19)
		av::InPullup,	// D4: PD4(XCK/T0/PCINT20)
		av::InPullup,	// D5: PD5(T1/OC0B/PCINT21)
		av::InPullup,	// D6: PD6(AIN0/OC0A/PCINT22)
		av::InPullup,	// D7: PD7(AIN1/PCINT23)
		av::InPullup,	// D8: PB0(ICP1/CLKO/PCINT0)
		av::InPullup,	// D9: PB1(OC1A/PCINT1)
		av::InPullup,	// D10: PB2(SS/OC1B/PCINT2)
		av::InPullup,	// D11: PB3(MOSI/OC2A/PCINT3)
		av::InPullup,	// D12: PB4(MISO/PCINT4)
		av::InPullup,	// D13: PB5(SCK/PCINT5)
		av::InPullup,	// D14: PC0(ADC0/PCINT8)
		av::InPullup,	// D15: PC1(ADC1/PCINT9)
		av::InPullup,	// D16: PC2(ADC2/PCINT10)
		av::InPullup,	// D17: PC3(ADC3/PCINT11)
		av::InPullup,	// D18: PC4(ADC4/SDA/PCINT12)
		av::InPullup,	// D19: PC5(ADC5/SCL/PCINT13)
		av::InPullup	// D20: PC6(RESET/PCINT14)
	>();
}

void CompileTest_InitADConv()
{
	av::InitADConv<
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

void CompileTest_Port_SetMode()
{
	portD0.SetMode<av::In>();
	portD1.SetMode<av::In>();
	portD2.SetMode<av::In>();
	portD3.SetMode<av::In>();
	portD4.SetMode<av::In>();
	portD5.SetMode<av::In>();
	portD6.SetMode<av::In>();
	portD7.SetMode<av::In>();
	portD8.SetMode<av::In>();
	portD9.SetMode<av::In>();
	portD10.SetMode<av::In>();
	portD11.SetMode<av::In>();
	portD12.SetMode<av::In>();
	portD13.SetMode<av::In>();
	portD14.SetMode<av::In>();
	portD15.SetMode<av::In>();
	portD16.SetMode<av::In>();
	portD17.SetMode<av::In>();
	portD18.SetMode<av::In>();
	portD19.SetMode<av::In>();
	portD20.SetMode<av::In>();
	portD0.SetMode<av::Out>();
	portD1.SetMode<av::Out>();
	portD2.SetMode<av::Out>();
	portD3.SetMode<av::Out>();
	portD4.SetMode<av::Out>();
	portD5.SetMode<av::Out>();
	portD6.SetMode<av::Out>();
	portD7.SetMode<av::Out>();
	portD8.SetMode<av::Out>();
	portD9.SetMode<av::Out>();
	portD10.SetMode<av::Out>();
	portD11.SetMode<av::Out>();
	portD12.SetMode<av::Out>();
	portD13.SetMode<av::Out>();
	portD14.SetMode<av::Out>();
	portD15.SetMode<av::Out>();
	portD16.SetMode<av::Out>();
	portD17.SetMode<av::Out>();
	portD18.SetMode<av::Out>();
	portD19.SetMode<av::Out>();
	portD20.SetMode<av::Out>();
	portD0.SetMode<av::InPullup>();
	portD1.SetMode<av::InPullup>();
	portD2.SetMode<av::InPullup>();
	portD3.SetMode<av::InPullup>();
	portD4.SetMode<av::InPullup>();
	portD5.SetMode<av::InPullup>();
	portD6.SetMode<av::InPullup>();
	portD7.SetMode<av::InPullup>();
	portD8.SetMode<av::InPullup>();
	portD9.SetMode<av::InPullup>();
	portD10.SetMode<av::InPullup>();
	portD11.SetMode<av::InPullup>();
	portD12.SetMode<av::InPullup>();
	portD13.SetMode<av::InPullup>();
	portD14.SetMode<av::InPullup>();
	portD15.SetMode<av::InPullup>();
	portD16.SetMode<av::InPullup>();
	portD17.SetMode<av::InPullup>();
	portD18.SetMode<av::InPullup>();
	portD19.SetMode<av::InPullup>();
	portD20.SetMode<av::InPullup>();
	av::Port<av::D0>().SetMode<av::In>();
	av::Port<av::D1>().SetMode<av::In>();
	av::Port<av::D2>().SetMode<av::In>();
	av::Port<av::D3>().SetMode<av::In>();
	av::Port<av::D4>().SetMode<av::In>();
	av::Port<av::D5>().SetMode<av::In>();
	av::Port<av::D6>().SetMode<av::In>();
	av::Port<av::D7>().SetMode<av::In>();
	av::Port<av::D8>().SetMode<av::In>();
	av::Port<av::D9>().SetMode<av::In>();
	av::Port<av::D10>().SetMode<av::In>();
	av::Port<av::D11>().SetMode<av::In>();
	av::Port<av::D12>().SetMode<av::In>();
	av::Port<av::D13>().SetMode<av::In>();
	av::Port<av::D14>().SetMode<av::In>();
	av::Port<av::D15>().SetMode<av::In>();
	av::Port<av::D16>().SetMode<av::In>();
	av::Port<av::D17>().SetMode<av::In>();
	av::Port<av::D18>().SetMode<av::In>();
	av::Port<av::D19>().SetMode<av::In>();
	av::Port<av::D20>().SetMode<av::In>();
	av::Port<av::D0>().SetMode<av::Out>();
	av::Port<av::D1>().SetMode<av::Out>();
	av::Port<av::D2>().SetMode<av::Out>();
	av::Port<av::D3>().SetMode<av::Out>();
	av::Port<av::D4>().SetMode<av::Out>();
	av::Port<av::D5>().SetMode<av::Out>();
	av::Port<av::D6>().SetMode<av::Out>();
	av::Port<av::D7>().SetMode<av::Out>();
	av::Port<av::D8>().SetMode<av::Out>();
	av::Port<av::D9>().SetMode<av::Out>();
	av::Port<av::D10>().SetMode<av::Out>();
	av::Port<av::D11>().SetMode<av::Out>();
	av::Port<av::D12>().SetMode<av::Out>();
	av::Port<av::D13>().SetMode<av::Out>();
	av::Port<av::D14>().SetMode<av::Out>();
	av::Port<av::D15>().SetMode<av::Out>();
	av::Port<av::D16>().SetMode<av::Out>();
	av::Port<av::D17>().SetMode<av::Out>();
	av::Port<av::D18>().SetMode<av::Out>();
	av::Port<av::D19>().SetMode<av::Out>();
	av::Port<av::D20>().SetMode<av::Out>();
	av::Port<av::D0>().SetMode<av::InPullup>();
	av::Port<av::D1>().SetMode<av::InPullup>();
	av::Port<av::D2>().SetMode<av::InPullup>();
	av::Port<av::D3>().SetMode<av::InPullup>();
	av::Port<av::D4>().SetMode<av::InPullup>();
	av::Port<av::D5>().SetMode<av::InPullup>();
	av::Port<av::D6>().SetMode<av::InPullup>();
	av::Port<av::D7>().SetMode<av::InPullup>();
	av::Port<av::D8>().SetMode<av::InPullup>();
	av::Port<av::D9>().SetMode<av::InPullup>();
	av::Port<av::D10>().SetMode<av::InPullup>();
	av::Port<av::D11>().SetMode<av::InPullup>();
	av::Port<av::D12>().SetMode<av::InPullup>();
	av::Port<av::D13>().SetMode<av::InPullup>();
	av::Port<av::D14>().SetMode<av::InPullup>();
	av::Port<av::D15>().SetMode<av::InPullup>();
	av::Port<av::D16>().SetMode<av::InPullup>();
	av::Port<av::D17>().SetMode<av::InPullup>();
	av::Port<av::D18>().SetMode<av::InPullup>();
	av::Port<av::D19>().SetMode<av::InPullup>();
	av::Port<av::D20>().SetMode<av::InPullup>();
}

void CompileTest_Port_OutputDigital()
{
	portD0.OutputDigital<av::Low>();
	portD1.OutputDigital<av::Low>();
	portD2.OutputDigital<av::Low>();
	portD3.OutputDigital<av::Low>();
	portD4.OutputDigital<av::Low>();
	portD5.OutputDigital<av::Low>();
	portD6.OutputDigital<av::Low>();
	portD7.OutputDigital<av::Low>();
	portD8.OutputDigital<av::Low>();
	portD9.OutputDigital<av::Low>();
	portD10.OutputDigital<av::Low>();
	portD11.OutputDigital<av::Low>();
	portD12.OutputDigital<av::Low>();
	portD13.OutputDigital<av::Low>();
	portD14.OutputDigital<av::Low>();
	portD15.OutputDigital<av::Low>();
	portD16.OutputDigital<av::Low>();
	portD17.OutputDigital<av::Low>();
	portD18.OutputDigital<av::Low>();
	portD19.OutputDigital<av::Low>();
	portD20.OutputDigital<av::Low>();
	portD0.OutputDigital<av::High>();
	portD1.OutputDigital<av::High>();
	portD2.OutputDigital<av::High>();
	portD3.OutputDigital<av::High>();
	portD4.OutputDigital<av::High>();
	portD5.OutputDigital<av::High>();
	portD6.OutputDigital<av::High>();
	portD7.OutputDigital<av::High>();
	portD8.OutputDigital<av::High>();
	portD9.OutputDigital<av::High>();
	portD10.OutputDigital<av::High>();
	portD11.OutputDigital<av::High>();
	portD12.OutputDigital<av::High>();
	portD13.OutputDigital<av::High>();
	portD14.OutputDigital<av::High>();
	portD15.OutputDigital<av::High>();
	portD16.OutputDigital<av::High>();
	portD17.OutputDigital<av::High>();
	portD18.OutputDigital<av::High>();
	portD19.OutputDigital<av::High>();
	portD20.OutputDigital<av::High>();
	portD0.OutputDigital(sig);
	portD1.OutputDigital(sig);
	portD2.OutputDigital(sig);
	portD3.OutputDigital(sig);
	portD4.OutputDigital(sig);
	portD5.OutputDigital(sig);
	portD6.OutputDigital(sig);
	portD7.OutputDigital(sig);
	portD8.OutputDigital(sig);
	portD9.OutputDigital(sig);
	portD10.OutputDigital(sig);
	portD11.OutputDigital(sig);
	portD12.OutputDigital(sig);
	portD13.OutputDigital(sig);
	portD14.OutputDigital(sig);
	portD15.OutputDigital(sig);
	portD16.OutputDigital(sig);
	portD17.OutputDigital(sig);
	portD18.OutputDigital(sig);
	portD19.OutputDigital(sig);
	portD20.OutputDigital(sig);
	av::Port<av::D0>().OutputDigital<av::Low>();
	av::Port<av::D1>().OutputDigital<av::Low>();
	av::Port<av::D2>().OutputDigital<av::Low>();
	av::Port<av::D3>().OutputDigital<av::Low>();
	av::Port<av::D4>().OutputDigital<av::Low>();
	av::Port<av::D5>().OutputDigital<av::Low>();
	av::Port<av::D6>().OutputDigital<av::Low>();
	av::Port<av::D7>().OutputDigital<av::Low>();
	av::Port<av::D8>().OutputDigital<av::Low>();
	av::Port<av::D9>().OutputDigital<av::Low>();
	av::Port<av::D10>().OutputDigital<av::Low>();
	av::Port<av::D11>().OutputDigital<av::Low>();
	av::Port<av::D12>().OutputDigital<av::Low>();
	av::Port<av::D13>().OutputDigital<av::Low>();
	av::Port<av::D14>().OutputDigital<av::Low>();
	av::Port<av::D15>().OutputDigital<av::Low>();
	av::Port<av::D16>().OutputDigital<av::Low>();
	av::Port<av::D17>().OutputDigital<av::Low>();
	av::Port<av::D18>().OutputDigital<av::Low>();
	av::Port<av::D19>().OutputDigital<av::Low>();
	av::Port<av::D20>().OutputDigital<av::Low>();
	av::Port<av::D0>().OutputDigital<av::High>();
	av::Port<av::D1>().OutputDigital<av::High>();
	av::Port<av::D2>().OutputDigital<av::High>();
	av::Port<av::D3>().OutputDigital<av::High>();
	av::Port<av::D4>().OutputDigital<av::High>();
	av::Port<av::D5>().OutputDigital<av::High>();
	av::Port<av::D6>().OutputDigital<av::High>();
	av::Port<av::D7>().OutputDigital<av::High>();
	av::Port<av::D8>().OutputDigital<av::High>();
	av::Port<av::D9>().OutputDigital<av::High>();
	av::Port<av::D10>().OutputDigital<av::High>();
	av::Port<av::D11>().OutputDigital<av::High>();
	av::Port<av::D12>().OutputDigital<av::High>();
	av::Port<av::D13>().OutputDigital<av::High>();
	av::Port<av::D14>().OutputDigital<av::High>();
	av::Port<av::D15>().OutputDigital<av::High>();
	av::Port<av::D16>().OutputDigital<av::High>();
	av::Port<av::D17>().OutputDigital<av::High>();
	av::Port<av::D18>().OutputDigital<av::High>();
	av::Port<av::D19>().OutputDigital<av::High>();
	av::Port<av::D20>().OutputDigital<av::High>();
	av::Port<av::D0>().OutputDigital(sig);
	av::Port<av::D1>().OutputDigital(sig);
	av::Port<av::D2>().OutputDigital(sig);
	av::Port<av::D3>().OutputDigital(sig);
	av::Port<av::D4>().OutputDigital(sig);
	av::Port<av::D5>().OutputDigital(sig);
	av::Port<av::D6>().OutputDigital(sig);
	av::Port<av::D7>().OutputDigital(sig);
	av::Port<av::D8>().OutputDigital(sig);
	av::Port<av::D9>().OutputDigital(sig);
	av::Port<av::D10>().OutputDigital(sig);
	av::Port<av::D11>().OutputDigital(sig);
	av::Port<av::D12>().OutputDigital(sig);
	av::Port<av::D13>().OutputDigital(sig);
	av::Port<av::D14>().OutputDigital(sig);
	av::Port<av::D15>().OutputDigital(sig);
	av::Port<av::D16>().OutputDigital(sig);
	av::Port<av::D17>().OutputDigital(sig);
	av::Port<av::D18>().OutputDigital(sig);
	av::Port<av::D19>().OutputDigital(sig);
	av::Port<av::D20>().OutputDigital(sig);
}

void CompileTest_Port_InputDigital()
{
	sig = portD0.InputDigital();
	sig = portD1.InputDigital();
	sig = portD2.InputDigital();
	sig = portD3.InputDigital();
	sig = portD4.InputDigital();
	sig = portD5.InputDigital();
	sig = portD6.InputDigital();
	sig = portD7.InputDigital();
	sig = portD8.InputDigital();
	sig = portD9.InputDigital();
	sig = portD10.InputDigital();
	sig = portD11.InputDigital();
	sig = portD12.InputDigital();
	sig = portD13.InputDigital();
	sig = portD14.InputDigital();
	sig = portD15.InputDigital();
	sig = portD16.InputDigital();
	sig = portD17.InputDigital();
	sig = portD18.InputDigital();
	sig = portD19.InputDigital();
	sig = portD20.InputDigital();
	sig = av::Port<av::D0>().InputDigital();
	sig = av::Port<av::D1>().InputDigital();
	sig = av::Port<av::D2>().InputDigital();
	sig = av::Port<av::D3>().InputDigital();
	sig = av::Port<av::D4>().InputDigital();
	sig = av::Port<av::D5>().InputDigital();
	sig = av::Port<av::D6>().InputDigital();
	sig = av::Port<av::D7>().InputDigital();
	sig = av::Port<av::D8>().InputDigital();
	sig = av::Port<av::D9>().InputDigital();
	sig = av::Port<av::D10>().InputDigital();
	sig = av::Port<av::D11>().InputDigital();
	sig = av::Port<av::D12>().InputDigital();
	sig = av::Port<av::D13>().InputDigital();
	sig = av::Port<av::D14>().InputDigital();
	sig = av::Port<av::D15>().InputDigital();
	sig = av::Port<av::D16>().InputDigital();
	sig = av::Port<av::D17>().InputDigital();
	sig = av::Port<av::D18>().InputDigital();
	sig = av::Port<av::D19>().InputDigital();
	sig = av::Port<av::D20>().InputDigital();
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
	av::Port<av::D0>().EnablePWM();
	av::Port<av::D1>().EnablePWM();
	av::Port<av::D2>().EnablePWM();
	av::Port<av::D3>().EnablePWM();
	av::Port<av::D4>().EnablePWM();
	av::Port<av::D5>().EnablePWM();
	av::Port<av::D6>().EnablePWM();
	av::Port<av::D7>().EnablePWM();
	av::Port<av::D8>().EnablePWM();
	av::Port<av::D9>().EnablePWM();
	av::Port<av::D10>().EnablePWM();
	av::Port<av::D11>().EnablePWM();
	av::Port<av::D12>().EnablePWM();
	av::Port<av::D13>().EnablePWM();
	av::Port<av::D14>().EnablePWM();
	av::Port<av::D15>().EnablePWM();
	av::Port<av::D16>().EnablePWM();
	av::Port<av::D17>().EnablePWM();
	av::Port<av::D18>().EnablePWM();
	av::Port<av::D19>().EnablePWM();
	av::Port<av::D20>().EnablePWM();
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
	av::Port<av::D0>().DisablePWM();
	av::Port<av::D1>().DisablePWM();
	av::Port<av::D2>().DisablePWM();
	av::Port<av::D3>().DisablePWM();
	av::Port<av::D4>().DisablePWM();
	av::Port<av::D5>().DisablePWM();
	av::Port<av::D6>().DisablePWM();
	av::Port<av::D7>().DisablePWM();
	av::Port<av::D8>().DisablePWM();
	av::Port<av::D9>().DisablePWM();
	av::Port<av::D10>().DisablePWM();
	av::Port<av::D11>().DisablePWM();
	av::Port<av::D12>().DisablePWM();
	av::Port<av::D13>().DisablePWM();
	av::Port<av::D14>().DisablePWM();
	av::Port<av::D15>().DisablePWM();
	av::Port<av::D16>().DisablePWM();
	av::Port<av::D17>().DisablePWM();
	av::Port<av::D18>().DisablePWM();
	av::Port<av::D19>().DisablePWM();
	av::Port<av::D20>().DisablePWM();
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
	av::Port<av::D0>().OutputPWM(128);
	av::Port<av::D1>().OutputPWM(128);
	av::Port<av::D2>().OutputPWM(128);
	av::Port<av::D3>().OutputPWM(128);
	av::Port<av::D4>().OutputPWM(128);
	av::Port<av::D5>().OutputPWM(128);
	av::Port<av::D6>().OutputPWM(128);
	av::Port<av::D7>().OutputPWM(128);
	av::Port<av::D8>().OutputPWM(128);
	av::Port<av::D9>().OutputPWM(128);
	av::Port<av::D10>().OutputPWM(128);
	av::Port<av::D11>().OutputPWM(128);
	av::Port<av::D12>().OutputPWM(128);
	av::Port<av::D13>().OutputPWM(128);
	av::Port<av::D14>().OutputPWM(128);
	av::Port<av::D15>().OutputPWM(128);
	av::Port<av::D16>().OutputPWM(128);
	av::Port<av::D17>().OutputPWM(128);
	av::Port<av::D18>().OutputPWM(128);
	av::Port<av::D19>().OutputPWM(128);
	av::Port<av::D20>().OutputPWM(128);
}

void CompileTest_Port_StartADC()
{
	av::Port<av::A0>().StartADC();
	av::Port<av::A1>().StartADC();
	av::Port<av::A2>().StartADC();
	av::Port<av::A3>().StartADC();
	av::Port<av::A4>().StartADC();
	av::Port<av::A5>().StartADC();
	av::Port<av::A6>().StartADC();
}

void CompileTest_Port_WaitADC()
{
	av::Port<av::A0>().WaitADC();
	av::Port<av::A1>().WaitADC();
	av::Port<av::A2>().WaitADC();
	av::Port<av::A3>().WaitADC();
	av::Port<av::A4>().WaitADC();
	av::Port<av::A5>().WaitADC();
	av::Port<av::A6>().WaitADC();
}

void CompileTest_Port_InputAnalog()
{
	data = portA0.InputAnalog();
	data = portA1.InputAnalog();
	data = portA2.InputAnalog();
	data = portA3.InputAnalog();
	data = portA4.InputAnalog();
	data = portA5.InputAnalog();
	data = portA6.InputAnalog();
	data = av::Port<av::A0>().InputAnalog();
	data = av::Port<av::A1>().InputAnalog();
	data = av::Port<av::A2>().InputAnalog();
	data = av::Port<av::A3>().InputAnalog();
	data = av::Port<av::A4>().InputAnalog();
	data = av::Port<av::A5>().InputAnalog();
	data = av::Port<av::A6>().InputAnalog();
}

void setup()
{
	CompileTest_InitPort();
	CompileTest_InitADConv();
	CompileTest_Port_SetMode();
	CompileTest_Port_OutputDigital();
	CompileTest_Port_InputDigital();
	CompileTest_Port_EnablePWM();
	CompileTest_Port_DisablePWM();
	CompileTest_Port_OutputPWM();
	CompileTest_Port_StartADC();
	CompileTest_Port_WaitADC();
	CompileTest_Port_InputAnalog();
}

void loop()
{
}
