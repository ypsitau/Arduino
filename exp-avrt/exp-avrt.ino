#include "avrt.h"

volatile uint8_t data;
volatile bool flag = true;

void setup()
{
	avrt::Port::Init<
		avrt::Input,	// D0: PD0(RXD/PCINT16)
		avrt::Input,	// D1: PD1(TXD/PCINT17)
		avrt::Input,	// D2: PD2(INT0/PCINT18)
		avrt::Input,	// D3: PD3(INT1/OC2B/PCINT19)
		avrt::Input,	// D4: PD4(XCK/T0/PCINT20)
		avrt::Input,	// D5: PD5(T1/OC0B/PCINT21)
		avrt::Input,	// D6: PD6(AIN0/OC0A/PCINT22)
		avrt::Input,	// D7: PD7(AIN1/PCINT23)
		avrt::Input,	// D8: PB0(ICP1/CLKO/PCINT0)
		avrt::Input,	// D9: PB1(OC1A/PCINT1)
		avrt::Input,	// D10: PB2(SS/OC1B/PCINT2)
		avrt::Input,	// D11: PB3(MOSI/OC2A/PCINT3)
		avrt::Input,	// D12: PB4(MISO/PCINT4)
		avrt::Input,	// D13: PB5(SCK/PCINT5)
		avrt::Input,	// D14: PC0(ADC0/PCINT8)
		avrt::Input,	// D15: PC1(ADC1/PCINT9)
		avrt::Input,	// D16: PC2(ADC2/PCINT10)
		avrt::Input,	// D17: PC3(ADC3/PCINT11)
		avrt::Input,	// D18: PC4(ADC4/SDA/PCINT12)
		avrt::Input,	// D19: PC5(ADC5/SCL/PCINT13)
		avrt::Input		// D20: PC6(RESET/PCINT14)
	>();
	avrt::Port::Output<0, false>();
	avrt::Port::Output<1, false>();
	avrt::Port::Output<2, false>();
	avrt::Port::Output<3, false>();
	avrt::Port::Output<4, false>();
	avrt::Port::Output<5, false>();
	avrt::Port::Output<6, false>();
	avrt::Port::Output<7, false>();
	avrt::Port::Output<8, false>();
	avrt::Port::Output<9, false>();
	avrt::Port::Output<10, false>();
	avrt::Port::Output<11, false>();
	avrt::Port::Output<12, false>();
	avrt::Port::Output<13, false>();
	avrt::Port::Output<14, false>();
	avrt::Port::Output<15, false>();
	avrt::Port::Output<16, false>();
	avrt::Port::Output<17, false>();
	avrt::Port::Output<18, false>();
	avrt::Port::Output<19, false>();
	avrt::Port::Output<20, false>();
	avrt::Port::Output<0, true>();
	avrt::Port::Output<1, true>();
	avrt::Port::Output<2, true>();
	avrt::Port::Output<3, true>();
	avrt::Port::Output<4, true>();
	avrt::Port::Output<5, true>();
	avrt::Port::Output<6, true>();
	avrt::Port::Output<7, true>();
	avrt::Port::Output<8, true>();
	avrt::Port::Output<9, true>();
	avrt::Port::Output<10, true>();
	avrt::Port::Output<11, true>();
	avrt::Port::Output<12, true>();
	avrt::Port::Output<13, true>();
	avrt::Port::Output<14, true>();
	avrt::Port::Output<15, true>();
	avrt::Port::Output<16, true>();
	avrt::Port::Output<17, true>();
	avrt::Port::Output<18, true>();
	avrt::Port::Output<19, true>();
	avrt::Port::Output<20, true>();
	avrt::Port::Output<0>(flag);
	avrt::Port::Output<1>(flag);
	avrt::Port::Output<2>(flag);
	avrt::Port::Output<3>(flag);
	avrt::Port::Output<4>(flag);
	avrt::Port::Output<5>(flag);
	avrt::Port::Output<6>(flag);
	avrt::Port::Output<7>(flag);
	avrt::Port::Output<8>(flag);
	avrt::Port::Output<9>(flag);
	avrt::Port::Output<10>(flag);
	avrt::Port::Output<11>(flag);
	avrt::Port::Output<12>(flag);
	avrt::Port::Output<13>(flag);
	avrt::Port::Output<14>(flag);
	avrt::Port::Output<15>(flag);
	avrt::Port::Output<16>(flag);
	avrt::Port::Output<17>(flag);
	avrt::Port::Output<18>(flag);
	avrt::Port::Output<19>(flag);
	avrt::Port::Output<20>(flag);
	avrt::Port::Input<0>();
	avrt::Port::Input<1>();
	avrt::Port::Input<2>();
	avrt::Port::Input<3>();
	avrt::Port::Input<4>();
	avrt::Port::Input<5>();
	avrt::Port::Input<6>();
	avrt::Port::Input<7>();
	avrt::Port::Input<8>();
	avrt::Port::Input<9>();
	avrt::Port::Input<10>();
	avrt::Port::Input<11>();
	avrt::Port::Input<12>();
	avrt::Port::Input<13>();
	avrt::Port::Input<14>();
	avrt::Port::Input<15>();
	avrt::Port::Input<16>();
	avrt::Port::Input<17>();
	avrt::Port::Input<18>();
	avrt::Port::Input<19>();
	avrt::Port::Input<20>();
}

void loop()
{
}
