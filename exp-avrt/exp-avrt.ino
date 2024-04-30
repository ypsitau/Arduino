#include "avrt.h"

volatile uint8_t data;
volatile bool flag = true;

class A {
public:
	char buff[32];
};

A a;
constexpr avrt::Port<0> portHoge0;
constexpr avrt::Port<1> portHoge1;
constexpr avrt::Port<2> portHoge2;
constexpr avrt::Port<3> portHoge3;
constexpr avrt::Port<4> portHoge4;
constexpr avrt::Port<5> portHoge5;
constexpr avrt::Port<6> portHoge6;

void setup()
{
	avrt::InitPort<
		avrt::In,	// D0: PD0(RXD/PCINT16)
		avrt::In,	// D1: PD1(TXD/PCINT17)
		avrt::In,	// D2: PD2(INT0/PCINT18)
		avrt::In,	// D3: PD3(INT1/OC2B/PCINT19)
		avrt::In,	// D4: PD4(XCK/T0/PCINT20)
		avrt::In,	// D5: PD5(T1/OC0B/PCINT21)
		avrt::In,	// D6: PD6(AIN0/OC0A/PCINT22)
		avrt::In,	// D7: PD7(AIN1/PCINT23)
		avrt::In,	// D8: PB0(ICP1/CLKO/PCINT0)
		avrt::In,	// D9: PB1(OC1A/PCINT1)
		avrt::In,	// D10: PB2(SS/OC1B/PCINT2)
		avrt::In,	// D11: PB3(MOSI/OC2A/PCINT3)
		avrt::In,	// D12: PB4(MISO/PCINT4)
		avrt::In,	// D13: PB5(SCK/PCINT5)
		avrt::In,	// D14: PC0(ADC0/PCINT8)
		avrt::In,	// D15: PC1(ADC1/PCINT9)
		avrt::In,	// D16: PC2(ADC2/PCINT10)
		avrt::In,	// D17: PC3(ADC3/PCINT11)
		avrt::In,	// D18: PC4(ADC4/SDA/PCINT12)
		avrt::In,	// D19: PC5(ADC5/SCL/PCINT13)
		avrt::In	// D20: PC6(RESET/PCINT14)
	>();
	avrt::Port<0>().Output(a.buff[0]);
	portHoge0.SetMode<avrt::Out>();
	portHoge1.SetMode<avrt::Out>();
	portHoge2.SetMode<avrt::Out>();
	portHoge3.SetMode<avrt::Out>();
	portHoge4.SetMode<avrt::Out>();
	portHoge5.SetMode<avrt::Out>();
	avrt::Port<0>().SetMode<avrt::Out>();
	avrt::Port<1>().SetMode<avrt::Out>();
	avrt::Port<2>().SetMode<avrt::Out>();
	avrt::Port<3>().SetMode<avrt::Out>();
	avrt::Port<4>().SetMode<avrt::Out>();
	avrt::Port<5>().SetMode<avrt::Out>();
	avrt::Port<6>().SetMode<avrt::Out>();
	avrt::Port<7>().SetMode<avrt::Out>();
	avrt::Port<8>().SetMode<avrt::Out>();
	avrt::Port<9>().SetMode<avrt::Out>();
	avrt::Port<10>().SetMode<avrt::Out>();
	avrt::Port<11>().SetMode<avrt::Out>();
	avrt::Port<12>().SetMode<avrt::Out>();
	avrt::Port<13>().SetMode<avrt::Out>();
	avrt::Port<14>().SetMode<avrt::Out>();
	avrt::Port<15>().SetMode<avrt::Out>();
	avrt::Port<16>().SetMode<avrt::Out>();
	avrt::Port<17>().SetMode<avrt::Out>();
	avrt::Port<18>().SetMode<avrt::Out>();
	avrt::Port<19>().SetMode<avrt::Out>();
	avrt::Port<20>().SetMode<avrt::Out>();
	avrt::Port<0>().SetMode<avrt::In>();
	avrt::Port<1>().SetMode<avrt::In>();
	avrt::Port<2>().SetMode<avrt::In>();
	avrt::Port<3>().SetMode<avrt::In>();
	avrt::Port<4>().SetMode<avrt::In>();
	avrt::Port<5>().SetMode<avrt::In>();
	avrt::Port<6>().SetMode<avrt::In>();
	avrt::Port<7>().SetMode<avrt::In>();
	avrt::Port<8>().SetMode<avrt::In>();
	avrt::Port<9>().SetMode<avrt::In>();
	avrt::Port<10>().SetMode<avrt::In>();
	avrt::Port<11>().SetMode<avrt::In>();
	avrt::Port<12>().SetMode<avrt::In>();
	avrt::Port<13>().SetMode<avrt::In>();
	avrt::Port<14>().SetMode<avrt::In>();
	avrt::Port<15>().SetMode<avrt::In>();
	avrt::Port<16>().SetMode<avrt::In>();
	avrt::Port<17>().SetMode<avrt::In>();
	avrt::Port<18>().SetMode<avrt::In>();
	avrt::Port<19>().SetMode<avrt::In>();
	avrt::Port<20>().SetMode<avrt::In>();
	avrt::Port<0>().SetMode<avrt::InPullup>();
	avrt::Port<1>().SetMode<avrt::InPullup>();
	avrt::Port<2>().SetMode<avrt::InPullup>();
	avrt::Port<3>().SetMode<avrt::InPullup>();
	avrt::Port<4>().SetMode<avrt::InPullup>();
	avrt::Port<5>().SetMode<avrt::InPullup>();
	avrt::Port<6>().SetMode<avrt::InPullup>();
	avrt::Port<7>().SetMode<avrt::InPullup>();
	avrt::Port<8>().SetMode<avrt::InPullup>();
	avrt::Port<9>().SetMode<avrt::InPullup>();
	avrt::Port<10>().SetMode<avrt::InPullup>();
	avrt::Port<11>().SetMode<avrt::InPullup>();
	avrt::Port<12>().SetMode<avrt::InPullup>();
	avrt::Port<13>().SetMode<avrt::InPullup>();
	avrt::Port<14>().SetMode<avrt::InPullup>();
	avrt::Port<15>().SetMode<avrt::InPullup>();
	avrt::Port<16>().SetMode<avrt::InPullup>();
	avrt::Port<17>().SetMode<avrt::InPullup>();
	avrt::Port<18>().SetMode<avrt::InPullup>();
	avrt::Port<19>().SetMode<avrt::InPullup>();
	avrt::Port<20>().SetMode<avrt::InPullup>();
	avrt::Port<0>().Output<false>();
	avrt::Port<1>().Output<false>();
	avrt::Port<2>().Output<false>();
	avrt::Port<3>().Output<false>();
	avrt::Port<4>().Output<false>();
	avrt::Port<5>().Output<false>();
	avrt::Port<6>().Output<false>();
	avrt::Port<7>().Output<false>();
	avrt::Port<8>().Output<false>();
	avrt::Port<9>().Output<false>();
	avrt::Port<10>().Output<false>();
	avrt::Port<11>().Output<false>();
	avrt::Port<12>().Output<false>();
	avrt::Port<13>().Output<false>();
	avrt::Port<14>().Output<false>();
	avrt::Port<15>().Output<false>();
	avrt::Port<16>().Output<false>();
	avrt::Port<17>().Output<false>();
	avrt::Port<18>().Output<false>();
	avrt::Port<19>().Output<false>();
	avrt::Port<20>().Output<false>();
	avrt::Port<0>().Output<true>();
	avrt::Port<1>().Output<true>();
	avrt::Port<2>().Output<true>();
	avrt::Port<3>().Output<true>();
	avrt::Port<4>().Output<true>();
	avrt::Port<5>().Output<true>();
	avrt::Port<6>().Output<true>();
	avrt::Port<7>().Output<true>();
	avrt::Port<8>().Output<true>();
	avrt::Port<9>().Output<true>();
	avrt::Port<10>().Output<true>();
	avrt::Port<11>().Output<true>();
	avrt::Port<12>().Output<true>();
	avrt::Port<13>().Output<true>();
	avrt::Port<14>().Output<true>();
	avrt::Port<15>().Output<true>();
	avrt::Port<16>().Output<true>();
	avrt::Port<17>().Output<true>();
	avrt::Port<18>().Output<true>();
	avrt::Port<19>().Output<true>();
	avrt::Port<20>().Output<true>();
	avrt::Port<0>().Output(flag);
	avrt::Port<1>().Output(flag);
	avrt::Port<2>().Output(flag);
	avrt::Port<3>().Output(flag);
	avrt::Port<4>().Output(flag);
	avrt::Port<5>().Output(flag);
	avrt::Port<6>().Output(flag);
	avrt::Port<7>().Output(flag);
	avrt::Port<8>().Output(flag);
	avrt::Port<9>().Output(flag);
	avrt::Port<10>().Output(flag);
	avrt::Port<11>().Output(flag);
	avrt::Port<12>().Output(flag);
	avrt::Port<13>().Output(flag);
	avrt::Port<14>().Output(flag);
	avrt::Port<15>().Output(flag);
	avrt::Port<16>().Output(flag);
	avrt::Port<17>().Output(flag);
	avrt::Port<18>().Output(flag);
	avrt::Port<19>().Output(flag);
	avrt::Port<20>().Output(flag);
	data = avrt::Port<0>().Input();
	data = avrt::Port<1>().Input();
	data = avrt::Port<2>().Input();
	data = avrt::Port<3>().Input();
	data = avrt::Port<4>().Input();
	data = avrt::Port<5>().Input();
	data = avrt::Port<6>().Input();
	data = avrt::Port<7>().Input();
	data = avrt::Port<8>().Input();
	data = avrt::Port<9>().Input();
	data = avrt::Port<10>().Input();
	data = avrt::Port<11>().Input();
	data = avrt::Port<12>().Input();
	data = avrt::Port<13>().Input();
	data = avrt::Port<14>().Input();
	data = avrt::Port<15>().Input();
	data = avrt::Port<16>().Input();
	data = avrt::Port<17>().Input();
	data = avrt::Port<18>().Input();
	data = avrt::Port<19>().Input();
	data = avrt::Port<20>().Input();
	avrt::Port<0>().EnablePWM();
	avrt::Port<1>().EnablePWM();
	avrt::Port<2>().EnablePWM();
	avrt::Port<3>().EnablePWM();
	avrt::Port<4>().EnablePWM();
	avrt::Port<5>().EnablePWM();
	avrt::Port<6>().EnablePWM();
	avrt::Port<7>().EnablePWM();
	avrt::Port<8>().EnablePWM();
	avrt::Port<9>().EnablePWM();
	avrt::Port<10>().EnablePWM();
	avrt::Port<11>().EnablePWM();
	avrt::Port<12>().EnablePWM();
	avrt::Port<13>().EnablePWM();
	avrt::Port<14>().EnablePWM();
	avrt::Port<15>().EnablePWM();
	avrt::Port<16>().EnablePWM();
	avrt::Port<17>().EnablePWM();
	avrt::Port<18>().EnablePWM();
	avrt::Port<19>().EnablePWM();
	avrt::Port<20>().EnablePWM();
	avrt::Port<0>().DisablePWM();
	avrt::Port<1>().DisablePWM();
	avrt::Port<2>().DisablePWM();
	avrt::Port<3>().DisablePWM();
	avrt::Port<4>().DisablePWM();
	avrt::Port<5>().DisablePWM();
	avrt::Port<6>().DisablePWM();
	avrt::Port<7>().DisablePWM();
	avrt::Port<8>().DisablePWM();
	avrt::Port<9>().DisablePWM();
	avrt::Port<10>().DisablePWM();
	avrt::Port<11>().DisablePWM();
	avrt::Port<12>().DisablePWM();
	avrt::Port<13>().DisablePWM();
	avrt::Port<14>().DisablePWM();
	avrt::Port<15>().DisablePWM();
	avrt::Port<16>().DisablePWM();
	avrt::Port<17>().DisablePWM();
	avrt::Port<18>().DisablePWM();
	avrt::Port<19>().DisablePWM();
	avrt::Port<20>().DisablePWM();
}

void loop()
{
}
