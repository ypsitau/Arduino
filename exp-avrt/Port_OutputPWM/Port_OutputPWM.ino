#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0(serial)

av::Port<av::A0> portA0;
av::Port<av::D3> portPWM;

void setup()
{
	serial.Open(av::Serial::BaudRate57600);
	av::InitPort<>();
	av::InitADC_8bit<>();
	portPWM.SetMode<av::Out>();
	portPWM.EnablePWM();
}

void loop()
{
	uint8_t value = portA0.InputAnalog_8bit();
	serial.Printf(F("Duty: %3d/255\n"), value);
	portPWM.OutputPWM(value);
}

#if 0
#define cbi(sfr, bit) (_SFR_BYTE(sfr) &= ~_BV(bit))
#define sbi(sfr, bit) (_SFR_BYTE(sfr) |= _BV(bit))

template<int pin> void EnablePWM()
{
	if constexpr (pin == 3) { // PD3 is controlled by OC2B
		sbi(TCCR2A, COM2B1);
		//TCCR2A = (TCCR2A & ~(0b11 << COM2B0)) | (0b10 << COM2B0);
	} else if (pin == 5) { // PD5 is controlled by OC0B
		sbi(TCCR0A, COM0B1);
		//TCCR0A = (TCCR0A & ~(0b11 << COM0B0)) | (0b10 << COM0B0);
	} else if (pin == 6) { // PD6 is controlled by OC0A
		sbi(TCCR0A, COM0A1);
		//TCCR0A = (TCCR0A & ~(0b11 << COM0A0)) | (0b10 << COM0A0);
	} else if (pin == 9) { // PB1 is controlled by OC1A
		sbi(TCCR1A, COM1A1);
		//TCCR1A = (TCCR1A & ~(0b11 << COM1A0)) | (0b10 << COM1A0);
	} else if (pin == 10) { // PB2 is controlled by OC1B
		sbi(TCCR1A, COM1B1);
		//TCCR1A = (TCCR1A & ~(0b11 << COM1B0)) | (0b10 << COM1B0);
	} else if (pin == 11) { // PB3 is controlled by OC2A
		sbi(TCCR2A, COM2A1);
		//TCCR2A = (TCCR2A & ~(0b11 << COM2A0)) | (0b10 << COM2A0);
	}
}

template<int pin> void DisablePWM()
{
	if constexpr (pin == 3) { // PD3 is controlled by OC2B
		clr(TCCR2A, COM2B1);
		//TCCR2A &= ~(0b11 << COM2B0);
	} else if (pin == 5) { // PD5 is controlled by OC0B
		clr(TCCR0A, COM0B1);
		//TCCR0A &= ~(0b11 << COM0B0);
	} else if (pin == 6) { // PD6 is controlled by OC0A
		clr(TCCR0A, COM0A1);
		//TCCR0A &= ~(0b11 << COM0A0);
	} else if (pin == 9) { // PB1 is controlled by OC1A
		clr(TCCR1A, COM1A1);
		//TCCR1A &= ~(0b11 << COM1A0);
	} else if (pin == 10) { // PB2 is controlled by OC1B
		clr(TCCR1A, COM1B1);
		//TCCR1A &= ~(0b11 << COM1B0);
	} else if (pin == 11) { // PB3 is controlled by OC2A
		clr(TCCR2A, COM2A1);
		//TCCR2A &= ~(0b11 << COM2A0);
	}
}

template<int pin> void OutputPWM(uint8_t value)
{
	if constexpr (pin == 3) { // PD3 is controlled by OC2B
		OCR2B = value;
	} else if (pin == 5) { // PD5 is controlled by OC0B
		OCR0B = value;
	} else if (pin == 6) { // PD6 is controlled by OC0A
		OCR0A = value;
	} else if (pin == 9) { // PB1 is controlled by OC1A
		OCR1A = value;
	} else if (pin == 10) { // PB2 is controlled by OC1B
		OCR1B = value;
	} else if (pin == 11) { // PB3 is controlled by OC2A
		OCR2A = value;
	}
}

constexpr int pin = 11;

void setup()
{
	Serial.begin(57600);
	//pinMode(pin, OUTPUT);
	//EnablePWM<pin>();
	avrt::Port::SetMode<pin, avrt::Out>();
	avrt::Port::EnablePWM<pin>();
}

void loop()
{
	uint8_t value = map(analogRead(A0), 0, 1023, 0, 255);
	Serial.println(value);
	//OutputPWM<pin>(value);
	avrt::Port::OutputPWM<pin>(value);
}
#endif
