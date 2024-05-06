//------------------------------------------------------------------------------
// avrt.h
// AVR Template Class
//------------------------------------------------------------------------------
#ifndef AVRT_H
#define AVRT_H
#include <stdarg.h>
#include <stdlib.h>
#include <stdio.h>
#include <avr/pgmspace.h>
#include <avr/io.h>
#include <avr/interrupt.h>

class __FlashStringHelper;

namespace avrt {

template<typename T> T ChooseMin(T a, T b) { return (a < b)? a : b; }

using Logic = uint8_t;

constexpr uint8_t Low		= 0;
constexpr uint8_t High		= 1;

constexpr uint8_t In		= 0;
constexpr uint8_t Out		= 1;
constexpr uint8_t InPullup	= 2;
constexpr uint8_t OutHigh	= 3;

constexpr int D0 = 0;
constexpr int D1 = 1;
constexpr int D2 = 2;
constexpr int D3 = 3;
constexpr int D4 = 4;
constexpr int D5 = 5;
constexpr int D6 = 6;
constexpr int D7 = 7;
constexpr int D8 = 8;
constexpr int D9 = 9;
constexpr int D10 = 10;
constexpr int D11 = 11;
constexpr int D12 = 12;
constexpr int D13 = 13;
constexpr int D14 = 14;
constexpr int D15 = 15;
constexpr int D16 = 16;
constexpr int D17 = 17;
constexpr int D18 = 18;
constexpr int D19 = 19;
constexpr int D20 = 20;

constexpr int A0 = 14;
constexpr int A1 = 15;
constexpr int A2 = 16;
constexpr int A3 = 17;
constexpr int A4 = 18;
constexpr int A5 = 19;
constexpr int A6 = 20;

//------------------------------------------------------------------------------
// InitPort
//------------------------------------------------------------------------------
template<
	uint8_t mode0	= In,	// D0: PD0(RXD/PCINT16)
	uint8_t mode1	= In,	// D1: PD1(TXD/PCINT17)
	uint8_t mode2	= In,	// D2: PD2(INT0/PCINT18)
	uint8_t mode3	= In,	// D3: PD3(INT1/OC2B/PCINT19)
	uint8_t mode4	= In,	// D4: PD4(XCK/T0/PCINT20)
	uint8_t mode5	= In,	// D5: PD5(T1/OC0B/PCINT21)
	uint8_t mode6	= In,	// D6: PD6(AIN0/OC0A/PCINT22)
	uint8_t mode7	= In,	// D7: PD7(AIN1/PCINT23)
	uint8_t mode8	= In,	// D8: PB0(ICP1/CLKO/PCINT0)
	uint8_t mode9	= In,	// D9: PB1(OC1A/PCINT1)
	uint8_t mode10	= In,	// D10: PB2(SS/OC1B/PCINT2)
	uint8_t mode11	= In,	// D11: PB3(MOSI/OC2A/PCINT3)
	uint8_t mode12	= In,	// D12: PB4(MISO/PCINT4)
	uint8_t mode13	= In,	// D13: PB5(SCK/PCINT5)
	uint8_t mode14	= In,	// D14: PC0(ADC0/PCINT8)
	uint8_t mode15	= In,	// D15: PC1(ADC1/PCINT9)
	uint8_t mode16	= In,	// D16: PC2(ADC2/PCINT10)
	uint8_t mode17	= In,	// D17: PC3(ADC3/PCINT11)
	uint8_t mode18	= In,	// D18: PC4(ADC4/SDA/PCINT12)
	uint8_t mode19	= In,	// D19: PC5(ADC5/SCL/PCINT13)
	uint8_t mode20	= In	// D20: PC6(RESET/PCINT14)
> void InitPort() {
	DDRD = ((mode0 & 1) << 0) | ((mode1 & 1) << 1) | ((mode2 & 1) << 2) | ((mode3 & 1) << 3) |
		((mode4 & 1) << 4) | ((mode5 & 1) << 5) | ((mode6 & 1) << 6) | ((mode7 & 1) << 7);
	DDRB = ((mode8 & 1) << 0) | ((mode9 & 1) << 1) | ((mode10 & 1) << 2) | ((mode11 & 1) << 3) |
		((mode12 & 1) << 4) | ((mode13 & 1) << 5);
	DDRC = ((mode14 & 1) << 0) | ((mode15 & 1) << 1) | ((mode16 & 1) << 2) | ((mode17 & 1) << 3) |
		((mode18 & 1) << 4) | ((mode19 & 1) << 5) | ((mode20 & 1) << 6);
	PORTD = ((mode0 >> 1) << 0) | ((mode1 >> 1) << 1) | ((mode2 >> 1) << 2) | ((mode3 >> 1) << 3) |
		((mode4 >> 1) << 4) | ((mode5 >> 1) << 5) | ((mode6 >> 1) << 6) | ((mode7 >> 1) << 7);
	PORTB = ((mode8 >> 1) << 0) | ((mode9 >> 1) << 1) | ((mode10 >> 1) << 2) | ((mode11 >> 1) << 3) |
		((mode12 >> 1) << 4) | ((mode13 >> 1) << 5);
	PORTC = ((mode14 >> 1) << 0) | ((mode15 >> 1) << 1) | ((mode16 >> 1) << 2) | ((mode17 >> 1) << 3) |
		((mode18 >> 1) << 4) | ((mode19 >> 1) << 5) | ((mode20 >> 1) << 6);
}

//------------------------------------------------------------------------------
// InitADC
//------------------------------------------------------------------------------
template <
	uint8_t dataADATE	= 0b0,		// ADATE: ADC Auto Trigger Enable = false .. Single conversion triggered by ADSC
	uint8_t dataADTS	= 0b000,	// ADTS: ADC Auto Trigger Source = Free Running mode
	uint8_t dataADIE	= 0b0,		// ADIE: ADC Interrupt Enable = false
	uint8_t dataREFS	= 0b01,		// REFS: Reference Selction Bits = AVcc with external capacitor at AREF pin 
	uint8_t dataADPS	= 0b111,	// ADPS: ADC Prescaler Select Bits = 1/128
	uint8_t dataADLAR	= 0b0,		// ADLAR: ADC Left Adjust Result = false
	uint8_t dataMUX		= 0b0000,	// MUX: Analog Channel Selection Bits = ADC0
	uint8_t dataADSC	= 0b0,		// ADSC: ADC Start Conversion = false
	uint8_t dataADIF	= 0b1,		// ADIF: ADC Interrupt Flag .. set one to clear
	uint8_t dataADEN	= 0b1		// ADEN: ADC Enable = true
> static void InitADC() {
	ADMUX = (dataREFS << REFS0) | (dataADLAR << ADLAR) | (dataMUX << MUX0);
	ADCSRA = (dataADEN << ADEN) | (dataADSC << ADSC) | (dataADATE << ADATE) |
		(dataADIF << ADIF) | (dataADIE << ADIE) | (dataADPS << ADPS0);
	ADCSRB = ADCSRB & ~(0b111 << ADTS0) | (dataADTS << ADTS0);
}

//------------------------------------------------------------------------------
// InitADC_8bit
//------------------------------------------------------------------------------
template <
	uint8_t dataADATE	= 0b0,		// ADATE: ADC Auto Trigger Enable = false .. Single conversion triggered by ADSC
	uint8_t dataADTS	= 0b000,	// ADTS: ADC Auto Trigger Source = Free Running mode
	uint8_t dataADIE	= 0b0,		// ADIE: ADC Interrupt Enable = false
	uint8_t dataREFS	= 0b01,		// REFS: Reference Selction Bits = AVcc with external capacitor at AREF pin 
	uint8_t dataADPS	= 0b111,	// ADPS: ADC Prescaler Select Bits = 1/128
	uint8_t dataADLAR	= 0b1,		// ADLAR: ADC Left Adjust Result = true
	uint8_t dataMUX		= 0b0000,	// MUX: Analog Channel Selection Bits = ADC0
	uint8_t dataADSC	= 0b0,		// ADSC: ADC Start Conversion = false
	uint8_t dataADIF	= 0b1,		// ADIF: ADC Interrupt Flag .. set one to clear
	uint8_t dataADEN	= 0b1		// ADEN: ADC Enable = true
> static void InitADC_8bit() {
	ADMUX = (dataREFS << REFS0) | (dataADLAR << ADLAR) | (dataMUX << MUX0);
	ADCSRA = (dataADEN << ADEN) | (dataADSC << ADSC) | (dataADATE << ADATE) |
		(dataADIF << ADIF) | (dataADIE << ADIE) | (dataADPS << ADPS0);
	ADCSRB = ADCSRB & ~(0b111 << ADTS0) | (dataADTS << ADTS0);
}

//------------------------------------------------------------------------------
// InitAnalogComparator
//------------------------------------------------------------------------------
template <
	uint8_t dataACME	= 0b0,		// ACME: Analog Comparator Multiplexer Enable = false
	uint8_t dataACD		= 0b0,		// ACD: Analog Comparator Disable = false
	uint8_t dataACBG	= 0b0,		// ACBG: Analog Comparator Bandgap Select = AIN0 is applied to the positive input
	uint8_t dataACO		= 0b0,		// ACO: Analog Comparator Output (Read only)
	uint8_t dataACI		= 0b0,		// ACI: Analog Comparator Interrupt Flag = false
	uint8_t dataACIE	= 0b0,		// ACIE: Analog Comparator Interrupt Enable = false
	uint8_t dataACIC	= 0b0,		// ACIC: Analog Comparator Input Capture Enable = false
	uint8_t dataACIS	= 0b00,		// ACIS: Analog Comparator Interrupt Mode Select = Comparator Interrupt on Output Toggle
	uint8_t dataAIN0D	= 0b0,		// AIN0 Digital Input Disable
	uint8_t dataAIN1D	= 0b0		// AIN1 Digital Input Disable
> static void InitAnalogComparator() {
	ADCSRB = ADCSRB & ~(0b1 << ACME) | (dataACME << ACME);
	ACSR = (dataACD << ACD) | (dataACBG << ACBG) | (dataACO << ACO) | (dataACI << ACI) |
		(dataACIE << ACIE) | (dataACIC << ACIC) | (dataACIS << ACIS0);
	DIDR1 = (dataAIN1D << AIN1D) | (dataAIN0D << AIN0D);
}

//------------------------------------------------------------------------------
// Port
//------------------------------------------------------------------------------
template<int pin_> class Port {
public:
	constexpr static int pin = pin_;
	template<int mode> void SetMode() const {
		if constexpr (pin == 0)         {
			if constexpr (mode & 1) { DDRD |= (1 << 0); } else { DDRD &= ~(1 << 0); if constexpr (mode >> 1) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); } }
		} else if constexpr (pin == 1)  {
			if constexpr (mode & 1) { DDRD |= (1 << 1); } else { DDRD &= ~(1 << 1); if constexpr (mode >> 1) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); } }
		} else if constexpr (pin == 2)  {
			if constexpr (mode & 1) { DDRD |= (1 << 2); } else { DDRD &= ~(1 << 2); if constexpr (mode >> 1) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); } }
		} else if constexpr (pin == 3)  {
			if constexpr (mode & 1) { DDRD |= (1 << 3); } else { DDRD &= ~(1 << 3); if constexpr (mode >> 1) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); } }
		} else if constexpr (pin == 4)  {
			if constexpr (mode & 1) { DDRD |= (1 << 4); } else { DDRD &= ~(1 << 4); if constexpr (mode >> 1) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); } }
		} else if constexpr (pin == 5)  {
			if constexpr (mode & 1) { DDRD |= (1 << 5); } else { DDRD &= ~(1 << 5); if constexpr (mode >> 1) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); } }
		} else if constexpr (pin == 6)  {
			if constexpr (mode & 1) { DDRD |= (1 << 6); } else { DDRD &= ~(1 << 6); if constexpr (mode >> 1) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); } }
		} else if constexpr (pin == 7)  {
			if constexpr (mode & 1) { DDRD |= (1 << 7); } else { DDRD &= ~(1 << 7); if constexpr (mode >> 1) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); } }
		} else if constexpr (pin == 8)  {
			if constexpr (mode & 1) { DDRB |= (1 << 0); } else { DDRB &= ~(1 << 0); if constexpr (mode >> 1) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); } }
		} else if constexpr (pin == 9)  {
			if constexpr (mode & 1) { DDRB |= (1 << 1); } else { DDRB &= ~(1 << 1); if constexpr (mode >> 1) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); } }
		} else if constexpr (pin == 10) {
			if constexpr (mode & 1) { DDRB |= (1 << 2); } else { DDRB &= ~(1 << 2); if constexpr (mode >> 1) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); } }
		} else if constexpr (pin == 11) {
			if constexpr (mode & 1) { DDRB |= (1 << 3); } else { DDRB &= ~(1 << 3); if constexpr (mode >> 1) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); } }
		} else if constexpr (pin == 12) {
			if constexpr (mode & 1) { DDRB |= (1 << 4); } else { DDRB &= ~(1 << 4); if constexpr (mode >> 1) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); } }
		} else if constexpr (pin == 13) {
			if constexpr (mode & 1) { DDRB |= (1 << 5); } else { DDRB &= ~(1 << 5); if constexpr (mode >> 1) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); } }
		} else if constexpr (pin == 14) {
			if constexpr (mode & 1) { DDRC |= (1 << 0); } else { DDRC &= ~(1 << 0); if constexpr (mode >> 1) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); } }
		} else if constexpr (pin == 15) {
			if constexpr (mode & 1) { DDRC |= (1 << 1); } else { DDRC &= ~(1 << 1); if constexpr (mode >> 1) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); } }
		} else if constexpr (pin == 16) {
			if constexpr (mode & 1) { DDRC |= (1 << 2); } else { DDRC &= ~(1 << 2); if constexpr (mode >> 1) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); } }
		} else if constexpr (pin == 17) {
			if constexpr (mode & 1) { DDRC |= (1 << 3); } else { DDRC &= ~(1 << 3); if constexpr (mode >> 1) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); } }
		} else if constexpr (pin == 18) {
			if constexpr (mode & 1) { DDRC |= (1 << 4); } else { DDRC &= ~(1 << 4); if constexpr (mode >> 1) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); } }
		} else if constexpr (pin == 19) {
			if constexpr (mode & 1) { DDRC |= (1 << 5); } else { DDRC &= ~(1 << 5); if constexpr (mode >> 1) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); } }
		} else if constexpr (pin == 20) {
			if constexpr (mode & 1) { DDRC |= (1 << 6); } else { DDRC &= ~(1 << 6); if constexpr (mode >> 1) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); } }
		}
	}
	template<Logic logic> void OutputDigital() const {
		if constexpr (pin == 0)         { if constexpr (logic) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); }
		} else if constexpr (pin == 1)  { if constexpr (logic) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); }
		} else if constexpr (pin == 2)  { if constexpr (logic) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); }
		} else if constexpr (pin == 3)  { if constexpr (logic) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); }
		} else if constexpr (pin == 4)  { if constexpr (logic) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); }
		} else if constexpr (pin == 5)  { if constexpr (logic) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); }
		} else if constexpr (pin == 6)  { if constexpr (logic) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); }
		} else if constexpr (pin == 7)  { if constexpr (logic) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); }
		} else if constexpr (pin == 8)  { if constexpr (logic) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); }
		} else if constexpr (pin == 9)  { if constexpr (logic) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); }
		} else if constexpr (pin == 10) { if constexpr (logic) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); }
		} else if constexpr (pin == 11) { if constexpr (logic) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); }
		} else if constexpr (pin == 12) { if constexpr (logic) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); }
		} else if constexpr (pin == 13) { if constexpr (logic) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); }
		} else if constexpr (pin == 14) { if constexpr (logic) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); }
		} else if constexpr (pin == 15) { if constexpr (logic) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); }
		} else if constexpr (pin == 16) { if constexpr (logic) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); }
		} else if constexpr (pin == 17) { if constexpr (logic) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); }
		} else if constexpr (pin == 18) { if constexpr (logic) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); }
		} else if constexpr (pin == 19) { if constexpr (logic) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); }
		} else if constexpr (pin == 20) { if constexpr (logic) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); }
		}
	}
	void OutputDigital(Logic logic) const {
		if constexpr (pin == 0) { if (logic) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); }
		} else if (pin == 1)    { if (logic) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); }
		} else if (pin == 2)    { if (logic) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); }
		} else if (pin == 3)    { if (logic) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); }
		} else if (pin == 4)    { if (logic) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); }
		} else if (pin == 5)    { if (logic) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); }
		} else if (pin == 6)    { if (logic) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); }
		} else if (pin == 7)    { if (logic) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); }
		} else if (pin == 8)    { if (logic) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); }
		} else if (pin == 9)    { if (logic) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); }
		} else if (pin == 10)   { if (logic) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); }
		} else if (pin == 11)   { if (logic) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); }
		} else if (pin == 12)   { if (logic) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); }
		} else if (pin == 13)   { if (logic) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); }
		} else if (pin == 14)   { if (logic) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); }
		} else if (pin == 15)   { if (logic) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); }
		} else if (pin == 16)   { if (logic) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); }
		} else if (pin == 17)   { if (logic) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); }
		} else if (pin == 18)   { if (logic) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); }
		} else if (pin == 19)   { if (logic) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); }
		} else if (pin == 20)   { if (logic) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); }
		}
	}
	Logic InputDigital() const {
		if constexpr (pin == 0) return (PIND >> 0) & 1;
		else if (pin == 1)      return (PIND >> 1) & 1;
		else if (pin == 2)      return (PIND >> 2) & 1;
		else if (pin == 3)      return (PIND >> 3) & 1;
		else if (pin == 4)      return (PIND >> 4) & 1;
		else if (pin == 5)      return (PIND >> 5) & 1;
		else if (pin == 6)      return (PIND >> 6) & 1;
		else if (pin == 7)      return (PIND >> 7) & 1;
		else if (pin == 8)      return (PINB >> 0) & 1;
		else if (pin == 9)      return (PINB >> 1) & 1;
		else if (pin == 10)     return (PINB >> 2) & 1;
		else if (pin == 11)     return (PINB >> 3) & 1;
		else if (pin == 12)     return (PINB >> 4) & 1;
		else if (pin == 13)     return (PINB >> 5) & 1;
		else if (pin == 14)     return (PINC >> 0) & 1;
		else if (pin == 15)     return (PINC >> 1) & 1;
		else if (pin == 16)     return (PINC >> 2) & 1;
		else if (pin == 17)     return (PINC >> 3) & 1;
		else if (pin == 18)     return (PINC >> 4) & 1;
		else if (pin == 19)     return (PINC >> 5) & 1;
		else if (pin == 20)     return (PINC >> 6) & 1;
		return Low;
	}
	uint8_t ProbeDigital() const {
		if constexpr (pin == 0) return PIND & (1 << 0);
		else if (pin == 1)      return PIND & (1 << 1);
		else if (pin == 2)      return PIND & (1 << 2);
		else if (pin == 3)      return PIND & (1 << 3);
		else if (pin == 4)      return PIND & (1 << 4);
		else if (pin == 5)      return PIND & (1 << 5);
		else if (pin == 6)      return PIND & (1 << 6);
		else if (pin == 7)      return PIND & (1 << 7);
		else if (pin == 8)      return PINB & (1 << 0);
		else if (pin == 9)      return PINB & (1 << 1);
		else if (pin == 10)     return PINB & (1 << 2);
		else if (pin == 11)     return PINB & (1 << 3);
		else if (pin == 12)     return PINB & (1 << 4);
		else if (pin == 13)     return PINB & (1 << 5);
		else if (pin == 14)     return PINC & (1 << 0);
		else if (pin == 15)     return PINC & (1 << 1);
		else if (pin == 16)     return PINC & (1 << 2);
		else if (pin == 17)     return PINC & (1 << 3);
		else if (pin == 18)     return PINC & (1 << 4);
		else if (pin == 19)     return PINC & (1 << 5);
		else if (pin == 20)     return PINC & (1 << 6);
		return 0x00;
	}
	void EnablePWM() const {
		if constexpr (pin == 3) { // PD3 is controlled by OC2B
			TCCR2A |= (1 << COM2B1);
		} else if (pin == 5) { // PD5 is controlled by OC0B
			TCCR0A |= (1 << COM0B1);
		} else if (pin == 6) { // PD6 is controlled by OC0A
			TCCR0A |= (1 << COM0A1);
		} else if (pin == 9) { // PB1 is controlled by OC1A
			TCCR1A |= (1 << COM1A1);
		} else if (pin == 10) { // PB2 is controlled by OC1B
			TCCR1A |= (1 << COM1B1);
		} else if (pin == 11) { // PB3 is controlled by OC2A
			TCCR2A |= (1 << COM2A1);
		}
	}
	void DisablePWM() const {
		if constexpr (pin == 3) { // PD3 is controlled by OC2B
			TCCR2A &= ~(1 << COM2B1);
		} else if (pin == 5) { // PD5 is controlled by OC0B
			TCCR0A &= ~(1 << COM0B1);
		} else if (pin == 6) { // PD6 is controlled by OC0A
			TCCR0A &= ~(1 << COM0A1);
		} else if (pin == 9) { // PB1 is controlled by OC1A
			TCCR1A &= ~(1 << COM1A1);
		} else if (pin == 10) { // PB2 is controlled by OC1B
			TCCR1A &= ~(1 << COM1B1);
		} else if (pin == 11) { // PB3 is controlled by OC2A
			TCCR2A &= ~(1 << COM2A1);
		}
	}
	void OutputPWM(uint8_t value) const {
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
	void OutputFinePWM(uint8_t value) const {
		if (value == 0) {
			DisablePWM();
			OutputDigital<Low>();
		} else if (value == 255) {
			DisablePWM();
			OutputDigital<High>();
		} else {
			EnablePWM();
			OutputPWM(value);
		}
	}
	static uint8_t PinToADCChannel(int pin) { return static_cast<uint8_t>(pin - A0); }
	void StartADC() const {
		ADMUX = ADMUX & (~0b1111 << MUX0) | (PinToADCChannel(pin) << MUX0);
		ADCSRA |= (0b1 << ADSC);	// ADSC: ADC Start Conversion = 1
	}
	void WaitADC() const {
		while (ADCSRA & (0b1 << ADSC)) ;
	}
	static uint16_t GetADC() { return ADC; }
	static uint8_t GetADC_8bit() { return ADCH; }
	uint16_t InputAnalog() const {
		ADMUX = ADMUX & (~0b1111 << MUX0) | (PinToADCChannel(pin) << MUX0);
		ADCSRA |= (0b1 << ADSC);	// ADSC: ADC Start Conversion = 1
		while (ADCSRA & (0b1 << ADSC)) ;
		return ADC;
	}
	uint8_t InputAnalog_8bit() const {
		ADMUX = ADMUX & (~0b1111 << MUX0) | (PinToADCChannel(pin) << MUX0);
		ADCSRA |= (0b1 << ADSC);	// ADSC: ADC Start Conversion = 1
		while (ADCSRA & (0b1 << ADSC)) ;
		return ADCH;
	}
};

//------------------------------------------------------------------------------
// FormatterFlags
//------------------------------------------------------------------------------
class FormatterFlags {
public:
	enum class PlusMode { None, Space, Plus };
	struct Prec {
		static const int Default	= -1;
		static const int Null		= -2;
	};
public:
	bool upperCaseFlag;
	bool leftAlignFlag;
	bool sharpFlag;
	int fieldMinWidth;
	int precision;
	PlusMode plusMode;
	char charPadding;
public:
	void Initialize();
	template<typename T, typename T_Unsigned> const char* FormatNumber_d(T num, char* buff, size_t size) const;
	template<typename T> const char* FormatNumber_u(T num, char* buff, size_t size) const;
	template<typename T> const char* FormatNumber_b(T num, char* buff, size_t size) const;
	template<typename T> const char* FormatNumber_o(T num, char* buff, size_t size) const;
	template<typename T> const char* FormatNumber_x(T num, char* buff, size_t size) const;
	const char* FormatNumber_e(float num, char* buff, size_t size) const;
	const char* FormatNumber_f(float num, char* buff, size_t size) const;
	const char* FormatNumber_g(float num, char* buff, size_t size) const;
private:
	void ToString(char* fmt, char qualifier) const;
};

template<typename T, typename T_Unsigned>
const char* FormatterFlags::FormatNumber_d(T num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else if (num > 0) {
		int nCols = 0;
		for ( ; num != 0; num /= 10, nCols++) {
			p--;
			*p = (num % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 2) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (plusMode == PlusMode::Space) {
			p--;
			*p = ' ';
		} else if (plusMode == PlusMode::Plus) {
			p--;
			*p = '+';
		}
	} else {
		int nCols = 0;
		T_Unsigned numNeg = -num;
		for ( ; numNeg != 0; numNeg /= 10, nCols++) {
			p--;
			*p = (numNeg % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 2) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		p--;
		*p = '-';
	}
	return p;
}

template<typename T>
const char* FormatterFlags::FormatNumber_u(T num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num /= 10, nCols++) {
			p--;
			*p = (num % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
	}
	return p;
}

template<typename T>
const char* FormatterFlags::FormatNumber_b(T num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 1, nCols++) {
			p--;
			*p = '0' + (num & 0x1);
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (sharpFlag) {
			p--;
			*p = 'b';
			p--;
			*p = '0';
		}
	}
	return p;
}

template<typename T>
const char* FormatterFlags::FormatNumber_o(T num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 3, nCols++) {
			p--;
			*p = '0' + (num & 0x7);
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (sharpFlag) {
			p--;
			*p = '0';
		}
	}
	return p;
}

template<typename T>
const char* FormatterFlags::FormatNumber_x(T num, char* buff, size_t size) const
{
	const static char convUpperTbl[] PROGMEM = "0123456789ABCDEF";
	const static char convLowerTbl[] PROGMEM = "0123456789abcdef";
	char* p = buff + size - 1;
	*p = '\0';
	const char* convTbl = upperCaseFlag? convUpperTbl : convLowerTbl;
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 4, nCols++) {
			p--;
			*p = pgm_read_byte(&convTbl[num & 0xf]);
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 3) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (sharpFlag) {
			p--;
			*p = upperCaseFlag? 'X' : 'x';
			p--;
			*p = '0';
		}
	}
	return p;
}

//------------------------------------------------------------------------------
// StringPtr
//------------------------------------------------------------------------------
class StringPtr {
public:
	virtual char Next() = 0;
};

class StringPtr_SRAM : public StringPtr {
private:
	const char* p_;
public:
	StringPtr_SRAM(const char* p) : p_(p) {}
	virtual char Next() override { return *p_++; }
};

class StringPtr_Flash : public StringPtr {
private:
	const char* p_;
public:
	StringPtr_Flash(const __FlashStringHelper* p) : p_(reinterpret_cast<const char*>(p)) {}
	virtual char Next() override { char ch = pgm_read_byte(p_); p_++; return ch; }
};

//------------------------------------------------------------------------------
// FIFOBuff
//------------------------------------------------------------------------------
template<int size = 32> class FIFOBuff {
public:
	static constexpr uint8_t sizeMinusOne = static_cast<uint8_t>(size - 1);
private:
	volatile uint8_t posRead_;
	volatile uint8_t posWrite_;
	volatile uint8_t buff_[size];
public:
	FIFOBuff() : posRead_(0), posWrite_(0) {}
	void WriteByte(uint8_t data) {
		uint8_t posWriteNext = (posWrite_ == sizeMinusOne)? 0 : posWrite_ + 1;
		if (posWriteNext == posRead_) return;
		buff_[posWrite_] = data;
		posWrite_ = posWriteNext;
	}
	uint8_t ReadByte() {
		if (IsEmpty()) return 0x00;
		uint8_t data = buff_[posRead_];
		posRead_ = (posRead_ == sizeMinusOne)? 0 : posRead_ + 1;
		return data;
	}
	bool IsEmpty() { return posRead_ == posWrite_; }
	bool HasRoom() {
		uint8_t posWriteNext = (posWrite_ == sizeMinusOne)? 0 : posWrite_ + 1;
		return posWriteNext != posRead_;
	}
};

//------------------------------------------------------------------------------
// Stream
//------------------------------------------------------------------------------
class Stream {
public:
	Stream() {}
	void Write(const uint8_t* buff, int len);
	void PutChar(char ch) { SendData(static_cast<uint8_t>(ch)); }
	char GetChar() { return static_cast<char>(RecvData()); }
	void Print(const char* str);
	void Print(const __FlashStringHelper* str);
	void Println() { PutChar('\n'); }
	void Println(const char* str);
	void Println(const __FlashStringHelper* str);
	bool Printf(const char* format, ...);
	bool Printf(const __FlashStringHelper* format, ...);
	bool PrintfV(const char* format, va_list ap);
	bool PrintfV(const __FlashStringHelper* format, va_list ap);
	bool PrintfV(StringPtr& format, va_list ap);
	void PutAlignedString(const FormatterFlags& formatterFlags, const char* str, int cntMax = -1);
public:
	virtual void SendData(uint8_t) = 0;
	virtual uint8_t RecvData() = 0;
};

//------------------------------------------------------------------------------
// Serial
//------------------------------------------------------------------------------
class Serial : public Stream {
public:
	enum BaudRate {
		BaudRate2400,
		BaudRate4800,
		BaudRate9600,
		BaudRate14400,
		BaudRate19200,
		BaudRate28800,
		BaudRate38400,
		BaudRate57600,
		BaudRate76800,
		BaudRate115200,
		BaudRate230400,
		BaudRate250000,
		BaudRate500000,
		BaudRate1000000,
	};	
	constexpr static uint8_t CharSize5	= 0b000;
	constexpr static uint8_t CharSize6	= 0b001;
	constexpr static uint8_t CharSize7	= 0b010;
	constexpr static uint8_t CharSize8	= 0b011;
	constexpr static uint8_t CharSize9	= 0b111;
	constexpr static uint8_t ParityNone	= 0b00;
	constexpr static uint8_t ParityEven	= 0b10;
	constexpr static uint8_t ParityOdd	= 0b11;
	constexpr static uint8_t StopBit1	= 0b0;
	constexpr static uint8_t StopBit2	= 0b1;
public:
	static uint16_t LookupUBRR(BaudRate baudRate, bool doubleSpeedFlag);
};

//------------------------------------------------------------------------------
// Serial0
//------------------------------------------------------------------------------
template<
	bool enableReceive		= true,
	uint8_t dataTXCIE0		= 0b0,			// TXCIEn: TX Complete Interrupt Enable n = false
	uint8_t dataUDRIE0		= 0b0,			// UDRIEn: USART Data Register Empty Interrupt Enable n = false
	uint8_t dataUMSEL00		= 0b00,			// UMSELn: USART Mode Select = Asynchronous USART
	uint8_t dataUCPOL0		= 0b0,			// UCPOLn: Clock Polarity = Tx on Rising XCKn & Rx on Falling XCKn
	uint8_t dataMPCM0		= 0b0,			// MPCMn: Multi-processor Communication Mode = false
	uint8_t dataU2X			= 0b0,			// U2Xn: Double the USART Transmission Speed = false
	uint8_t dataTXB80		= 0b0,			// TXB8n: Transmit Data Bit 8 n = false
	uint8_t dataRXEN0		= 0b1,			// RXENn: Receiver Enable n = true
	uint8_t dataTXEN0		= 0b1			// TXENn: Transmitter Enable n = true
> class Serial0 : public Serial {
private:
	FIFOBuff<> buffs_[enableReceive? 1 : 0];
public:
	Serial0() {}
	FIFOBuff<>& GetBuffForRead() { return buffs_[0]; }
	void Open(BaudRate baudRate, uint8_t charSize = CharSize8, uint8_t stopBit = StopBit1, uint8_t parity = ParityNone) {
		constexpr uint8_t dataRXCIE0 = enableReceive? 0b1 : 0b0; // RXCIEn: RX Complete Interrupt Enable n
		uint8_t dataUCSZ = charSize;
		uint8_t dataUSBS = stopBit;
		uint8_t dataUPM = parity;
		UCSR0A =
			(0b1 << TXC0) |					// TXCn: USART Transmit Complete .. set one to clear
			(dataU2X << U2X0) |				// U2Xn: Double the USART Transmission Speed
			(dataMPCM0 << MPCM0);			// MPCMn: Multi-processor Communication Mode
		UCSR0B =
			(dataRXCIE0 << RXCIE0) |		// RXCIEn: RX Complete Interrupt Enable n
			(dataTXCIE0 << TXCIE0) |		// TXCIEn: TX Complete Interrupt Enable n
			(dataUDRIE0 << UDRIE0) |		// UDRIEn: USART Data Register Empty Interrupt Enable n
			(dataRXEN0 << RXEN0) |			// RXENn: Receiver Enable n
			(dataTXEN0 << TXEN0) |			// TXENn: Transmitter Enable n
			((dataUCSZ >> 2) << UCSZ02) |	// UCSZn: Character Size
			(dataTXB80 << TXB80);			// TXB8n: Transmit Data Bit 8 n
		UCSR0C =
			(dataUMSEL00 << UMSEL00) |		// UMSELn: USART Mode Select
			(dataUPM << UPM00) |			// UPMn: Parity Mode
			(dataUSBS << USBS0) |			// USBSn: Stop Bit Select
			((dataUCSZ & 0b11) << UCSZ00) |	// UCSZn: Character Size
			(dataUCPOL0 << UCPOL0);			// UCPOLn: Clock Polarity = Tx on Rising XCKn & Rx on Falling XCKn
		uint16_t dataUBRR = LookupUBRR(baudRate, dataU2X);
		UBRR0H = static_cast<uint8_t>((dataUBRR >> 8) & 0xff); // this must be written first
		UBRR0L = static_cast<uint8_t>(dataUBRR & 0xff);
	}
	void Close() {}
	virtual void SendData(uint8_t data) override {
		while (!(UCSR0A & (0b1 << UDRE0))) ;
		UDR0 = data;
	}
	virtual uint8_t RecvData() override {
		if constexpr (enableReceive) {
			return GetBuffForRead().ReadByte();
		} else {
			return 0x00;
		}
	}
	bool HasRecvData() {
		if constexpr (enableReceive) {
			return !GetBuffForRead().IsEmpty();
		} else {
			return false;
		}
	}
	void HandleIRQ_USART_RX() {
		while (UCSR0A & (0b1 << RXC0)) GetBuffForRead().WriteByte(UDR0);
	}
};

}

#define RegisterISR_Serial0(serial) ISR(USART_RX_vect) { serial.HandleIRQ_USART_RX(); }

#endif
