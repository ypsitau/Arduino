#include <avrt.h>

namespace av = avrt;

volatile uint8_t data8 = 0;
volatile uint16_t data16 = 0;
volatile av::Logic logic = av::Low;

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
	av::InitPort<>();
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
	av::InitPort<
		av::OutHigh,	// D0: PD0(RXD/PCINT16)
		av::OutHigh,	// D1: PD1(TXD/PCINT17)
		av::OutHigh,	// D2: PD2(INT0/PCINT18)
		av::OutHigh,	// D3: PD3(INT1/OC2B/PCINT19)
		av::OutHigh,	// D4: PD4(XCK/T0/PCINT20)
		av::OutHigh,	// D5: PD5(T1/OC0B/PCINT21)
		av::OutHigh,	// D6: PD6(AIN0/OC0A/PCINT22)
		av::OutHigh,	// D7: PD7(AIN1/PCINT23)
		av::OutHigh,	// D8: PB0(ICP1/CLKO/PCINT0)
		av::OutHigh,	// D9: PB1(OC1A/PCINT1)
		av::OutHigh,	// D10: PB2(SS/OC1B/PCINT2)
		av::OutHigh,	// D11: PB3(MOSI/OC2A/PCINT3)
		av::OutHigh,	// D12: PB4(MISO/PCINT4)
		av::OutHigh,	// D13: PB5(SCK/PCINT5)
		av::OutHigh,	// D14: PC0(ADC0/PCINT8)
		av::OutHigh,	// D15: PC1(ADC1/PCINT9)
		av::OutHigh,	// D16: PC2(ADC2/PCINT10)
		av::OutHigh,	// D17: PC3(ADC3/PCINT11)
		av::OutHigh,	// D18: PC4(ADC4/SDA/PCINT12)
		av::OutHigh,	// D19: PC5(ADC5/SCL/PCINT13)
		av::OutHigh		// D20: PC6(RESET/PCINT14)
	>();
}

void CompileTest_InitADC()
{
	av::InitADC<>();
	av::InitADC<
		0b0,	// ADATE: ADC Auto Trigger Enable = false .. Single conversion triggered by ADSC
		0b000,	// ADTS: ADC Auto Trigger Source = Free Running mode
		0b0,	// ADIE: ADC Interrupt Enable = false
		0b01,	// REFS: Reference Selction Bits = AVcc with external capacitor at AREF pin 
		0b111,	// ADPS: ADC Prescaler Select Bits = 1/128
		0b0,	// ADLAR: ADC Left Adjust Result = false
		0b0000,	// MUX: Analog Channel Selection Bits = ADC0
		0b0,	// ADSC: ADC Start Conversion = false
		0b1,	// ADIF: ADC Interrupt Flag .. clear by setting one
		0b1		// ADEN: ADC Enable = true
	>();
}

void CompileTest_InitAnalogComparator()
{
	av::InitAnalogComparator();
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
	portD0.OutputDigital(logic);
	portD1.OutputDigital(logic);
	portD2.OutputDigital(logic);
	portD3.OutputDigital(logic);
	portD4.OutputDigital(logic);
	portD5.OutputDigital(logic);
	portD6.OutputDigital(logic);
	portD7.OutputDigital(logic);
	portD8.OutputDigital(logic);
	portD9.OutputDigital(logic);
	portD10.OutputDigital(logic);
	portD11.OutputDigital(logic);
	portD12.OutputDigital(logic);
	portD13.OutputDigital(logic);
	portD14.OutputDigital(logic);
	portD15.OutputDigital(logic);
	portD16.OutputDigital(logic);
	portD17.OutputDigital(logic);
	portD18.OutputDigital(logic);
	portD19.OutputDigital(logic);
	portD20.OutputDigital(logic);
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
	av::Port<av::D0>().OutputDigital(logic);
	av::Port<av::D1>().OutputDigital(logic);
	av::Port<av::D2>().OutputDigital(logic);
	av::Port<av::D3>().OutputDigital(logic);
	av::Port<av::D4>().OutputDigital(logic);
	av::Port<av::D5>().OutputDigital(logic);
	av::Port<av::D6>().OutputDigital(logic);
	av::Port<av::D7>().OutputDigital(logic);
	av::Port<av::D8>().OutputDigital(logic);
	av::Port<av::D9>().OutputDigital(logic);
	av::Port<av::D10>().OutputDigital(logic);
	av::Port<av::D11>().OutputDigital(logic);
	av::Port<av::D12>().OutputDigital(logic);
	av::Port<av::D13>().OutputDigital(logic);
	av::Port<av::D14>().OutputDigital(logic);
	av::Port<av::D15>().OutputDigital(logic);
	av::Port<av::D16>().OutputDigital(logic);
	av::Port<av::D17>().OutputDigital(logic);
	av::Port<av::D18>().OutputDigital(logic);
	av::Port<av::D19>().OutputDigital(logic);
	av::Port<av::D20>().OutputDigital(logic);
}

void CompileTest_Port_InputDigital()
{
	logic = portD0.InputDigital();
	logic = portD1.InputDigital();
	logic = portD2.InputDigital();
	logic = portD3.InputDigital();
	logic = portD4.InputDigital();
	logic = portD5.InputDigital();
	logic = portD6.InputDigital();
	logic = portD7.InputDigital();
	logic = portD8.InputDigital();
	logic = portD9.InputDigital();
	logic = portD10.InputDigital();
	logic = portD11.InputDigital();
	logic = portD12.InputDigital();
	logic = portD13.InputDigital();
	logic = portD14.InputDigital();
	logic = portD15.InputDigital();
	logic = portD16.InputDigital();
	logic = portD17.InputDigital();
	logic = portD18.InputDigital();
	logic = portD19.InputDigital();
	logic = portD20.InputDigital();
	logic = av::Port<av::D0>().InputDigital();
	logic = av::Port<av::D1>().InputDigital();
	logic = av::Port<av::D2>().InputDigital();
	logic = av::Port<av::D3>().InputDigital();
	logic = av::Port<av::D4>().InputDigital();
	logic = av::Port<av::D5>().InputDigital();
	logic = av::Port<av::D6>().InputDigital();
	logic = av::Port<av::D7>().InputDigital();
	logic = av::Port<av::D8>().InputDigital();
	logic = av::Port<av::D9>().InputDigital();
	logic = av::Port<av::D10>().InputDigital();
	logic = av::Port<av::D11>().InputDigital();
	logic = av::Port<av::D12>().InputDigital();
	logic = av::Port<av::D13>().InputDigital();
	logic = av::Port<av::D14>().InputDigital();
	logic = av::Port<av::D15>().InputDigital();
	logic = av::Port<av::D16>().InputDigital();
	logic = av::Port<av::D17>().InputDigital();
	logic = av::Port<av::D18>().InputDigital();
	logic = av::Port<av::D19>().InputDigital();
	logic = av::Port<av::D20>().InputDigital();
}

void CompileTest_Port_ProbeDigital()
{
	data8 = portD0.ProbeDigital();
	data8 = portD1.ProbeDigital();
	data8 = portD2.ProbeDigital();
	data8 = portD3.ProbeDigital();
	data8 = portD4.ProbeDigital();
	data8 = portD5.ProbeDigital();
	data8 = portD6.ProbeDigital();
	data8 = portD7.ProbeDigital();
	data8 = portD8.ProbeDigital();
	data8 = portD9.ProbeDigital();
	data8 = portD10.ProbeDigital();
	data8 = portD11.ProbeDigital();
	data8 = portD12.ProbeDigital();
	data8 = portD13.ProbeDigital();
	data8 = portD14.ProbeDigital();
	data8 = portD15.ProbeDigital();
	data8 = portD16.ProbeDigital();
	data8 = portD17.ProbeDigital();
	data8 = portD18.ProbeDigital();
	data8 = portD19.ProbeDigital();
	data8 = portD20.ProbeDigital();
	data8 = av::Port<av::D0>().ProbeDigital();
	data8 = av::Port<av::D1>().ProbeDigital();
	data8 = av::Port<av::D2>().ProbeDigital();
	data8 = av::Port<av::D3>().ProbeDigital();
	data8 = av::Port<av::D4>().ProbeDigital();
	data8 = av::Port<av::D5>().ProbeDigital();
	data8 = av::Port<av::D6>().ProbeDigital();
	data8 = av::Port<av::D7>().ProbeDigital();
	data8 = av::Port<av::D8>().ProbeDigital();
	data8 = av::Port<av::D9>().ProbeDigital();
	data8 = av::Port<av::D10>().ProbeDigital();
	data8 = av::Port<av::D11>().ProbeDigital();
	data8 = av::Port<av::D12>().ProbeDigital();
	data8 = av::Port<av::D13>().ProbeDigital();
	data8 = av::Port<av::D14>().ProbeDigital();
	data8 = av::Port<av::D15>().ProbeDigital();
	data8 = av::Port<av::D16>().ProbeDigital();
	data8 = av::Port<av::D17>().ProbeDigital();
	data8 = av::Port<av::D18>().ProbeDigital();
	data8 = av::Port<av::D19>().ProbeDigital();
	data8 = av::Port<av::D20>().ProbeDigital();
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
	portD0.OutputPWM(data8);
	portD1.OutputPWM(data8);
	portD2.OutputPWM(data8);
	portD3.OutputPWM(data8);
	portD4.OutputPWM(data8);
	portD5.OutputPWM(data8);
	portD6.OutputPWM(data8);
	portD7.OutputPWM(data8);
	portD8.OutputPWM(data8);
	portD9.OutputPWM(data8);
	portD10.OutputPWM(data8);
	portD11.OutputPWM(data8);
	portD12.OutputPWM(data8);
	portD13.OutputPWM(data8);
	portD14.OutputPWM(data8);
	portD15.OutputPWM(data8);
	portD16.OutputPWM(data8);
	portD17.OutputPWM(data8);
	portD18.OutputPWM(data8);
	portD19.OutputPWM(data8);
	portD20.OutputPWM(data8);
	av::Port<av::D0>().OutputPWM(data8);
	av::Port<av::D1>().OutputPWM(data8);
	av::Port<av::D2>().OutputPWM(data8);
	av::Port<av::D3>().OutputPWM(data8);
	av::Port<av::D4>().OutputPWM(data8);
	av::Port<av::D5>().OutputPWM(data8);
	av::Port<av::D6>().OutputPWM(data8);
	av::Port<av::D7>().OutputPWM(data8);
	av::Port<av::D8>().OutputPWM(data8);
	av::Port<av::D9>().OutputPWM(data8);
	av::Port<av::D10>().OutputPWM(data8);
	av::Port<av::D11>().OutputPWM(data8);
	av::Port<av::D12>().OutputPWM(data8);
	av::Port<av::D13>().OutputPWM(data8);
	av::Port<av::D14>().OutputPWM(data8);
	av::Port<av::D15>().OutputPWM(data8);
	av::Port<av::D16>().OutputPWM(data8);
	av::Port<av::D17>().OutputPWM(data8);
	av::Port<av::D18>().OutputPWM(data8);
	av::Port<av::D19>().OutputPWM(data8);
	av::Port<av::D20>().OutputPWM(data8);
}

void CompileTest_Port_OutputFinePWM()
{
	portD0.OutputFinePWM(data8);
	portD1.OutputFinePWM(data8);
	portD2.OutputFinePWM(data8);
	portD3.OutputFinePWM(data8);
	portD4.OutputFinePWM(data8);
	portD5.OutputFinePWM(data8);
	portD6.OutputFinePWM(data8);
	portD7.OutputFinePWM(data8);
	portD8.OutputFinePWM(data8);
	portD9.OutputFinePWM(data8);
	portD10.OutputFinePWM(data8);
	portD11.OutputFinePWM(data8);
	portD12.OutputFinePWM(data8);
	portD13.OutputFinePWM(data8);
	portD14.OutputFinePWM(data8);
	portD15.OutputFinePWM(data8);
	portD16.OutputFinePWM(data8);
	portD17.OutputFinePWM(data8);
	portD18.OutputFinePWM(data8);
	portD19.OutputFinePWM(data8);
	portD20.OutputFinePWM(data8);
	av::Port<av::D0>().OutputFinePWM(data8);
	av::Port<av::D1>().OutputFinePWM(data8);
	av::Port<av::D2>().OutputFinePWM(data8);
	av::Port<av::D3>().OutputFinePWM(data8);
	av::Port<av::D4>().OutputFinePWM(data8);
	av::Port<av::D5>().OutputFinePWM(data8);
	av::Port<av::D6>().OutputFinePWM(data8);
	av::Port<av::D7>().OutputFinePWM(data8);
	av::Port<av::D8>().OutputFinePWM(data8);
	av::Port<av::D9>().OutputFinePWM(data8);
	av::Port<av::D10>().OutputFinePWM(data8);
	av::Port<av::D11>().OutputFinePWM(data8);
	av::Port<av::D12>().OutputFinePWM(data8);
	av::Port<av::D13>().OutputFinePWM(data8);
	av::Port<av::D14>().OutputFinePWM(data8);
	av::Port<av::D15>().OutputFinePWM(data8);
	av::Port<av::D16>().OutputFinePWM(data8);
	av::Port<av::D17>().OutputFinePWM(data8);
	av::Port<av::D18>().OutputFinePWM(data8);
	av::Port<av::D19>().OutputFinePWM(data8);
	av::Port<av::D20>().OutputFinePWM(data8);
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
	data16 = portA0.InputAnalog();
	data16 = portA1.InputAnalog();
	data16 = portA2.InputAnalog();
	data16 = portA3.InputAnalog();
	data16 = portA4.InputAnalog();
	data16 = portA5.InputAnalog();
	data16 = portA6.InputAnalog();
	data16 = av::Port<av::A0>().InputAnalog();
	data16 = av::Port<av::A1>().InputAnalog();
	data16 = av::Port<av::A2>().InputAnalog();
	data16 = av::Port<av::A3>().InputAnalog();
	data16 = av::Port<av::A4>().InputAnalog();
	data16 = av::Port<av::A5>().InputAnalog();
	data16 = av::Port<av::A6>().InputAnalog();
}

void setup()
{
	CompileTest_InitPort();
	CompileTest_InitADC();
	CompileTest_InitAnalogComparator();
	CompileTest_Port_SetMode();
	CompileTest_Port_OutputDigital();
	CompileTest_Port_InputDigital();
	CompileTest_Port_ProbeDigital();
	CompileTest_Port_EnablePWM();
	CompileTest_Port_DisablePWM();
	CompileTest_Port_OutputPWM();
	CompileTest_Port_OutputFinePWM();
	CompileTest_Port_StartADC();
	CompileTest_Port_WaitADC();
	CompileTest_Port_InputAnalog();
}

void loop()
{
}
