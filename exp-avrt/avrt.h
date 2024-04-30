//------------------------------------------------------------------------------
// avrt.h
// AVR Template Class
//------------------------------------------------------------------------------
#ifndef AVRT_H
#define AVRT_H

namespace avrt {

constexpr uint8_t Input			= 0;
constexpr uint8_t Output		= 1;
constexpr uint8_t InputPullup	= 2;

class Port {
public:
	template<
		uint8_t d0	= Input,	// D0: PD0(RXD/PCINT16)
		uint8_t d1	= Input,	// D1: PD1(TXD/PCINT17)
		uint8_t d2	= Input,	// D2: PD2(INT0/PCINT18)
		uint8_t d3	= Input,	// D3: PD3(INT1/OC2B/PCINT19)
		uint8_t d4	= Input,	// D4: PD4(XCK/T0/PCINT20)
		uint8_t d5	= Input,	// D5: PD5(T1/OC0B/PCINT21)
		uint8_t d6	= Input,	// D6: PD6(AIN0/OC0A/PCINT22)
		uint8_t d7	= Input,	// D7: PD7(AIN1/PCINT23)
		uint8_t d8	= Input,	// D8: PB0(ICP1/CLKO/PCINT0)
		uint8_t d9	= Input,	// D9: PB1(OC1A/PCINT1)
		uint8_t d10	= Input,	// D10: PB2(SS/OC1B/PCINT2)
		uint8_t d11	= Input,	// D11: PB3(MOSI/OC2A/PCINT3)
		uint8_t d12	= Input,	// D12: PB4(MISO/PCINT4)
		uint8_t d13	= Input,	// D13: PB5(SCK/PCINT5)
		uint8_t d14	= Input,	// D14: PC0(ADC0/PCINT8)
		uint8_t d15	= Input,	// D15: PC1(ADC1/PCINT9)
		uint8_t d16	= Input,	// D16: PC2(ADC2/PCINT10)
		uint8_t d17	= Input,	// D17: PC3(ADC3/PCINT11)
		uint8_t d18	= Input,	// D18: PC4(ADC4/SDA/PCINT12)
		uint8_t d19	= Input,	// D19: PC5(ADC5/SCL/PCINT13)
		uint8_t d20	= Input		// D20: PC6(RESET/PCINT14)
	> static void Init() {
		DDRD = ((d0 & 1) << 0) | ((d1 & 1) << 1) | ((d2 & 1) << 2) | ((d3 & 1) << 3) |
			((d4 & 1) << 4) | ((d5 & 1) << 5) | ((d6 & 1) << 6) | ((d7 & 1) << 7);
		DDRB = ((d8 & 1) << 0) | ((d9 & 1) << 1) | ((d10 & 1) << 2) | ((d11 & 1) << 3) |
			((d12 & 1) << 4) | ((d13 & 1) << 5);
		DDRC = ((d14 & 1) << 0) | ((d15 & 1) << 1) | ((d16 & 1) << 2) | ((d17 & 1) << 3) |
			((d18 & 1) << 4) | ((d19 & 1) << 5) | ((d20 & 1) << 6);
		PORTD = ((d0 >> 1) << 0) | ((d1 >> 1) << 1) | ((d2 >> 1) << 2) | ((d3 >> 1) << 3) |
			((d4 >> 1) << 4) | ((d5 >> 1) << 5) | ((d6 >> 1) << 6) | ((d7 >> 1) << 7);
		PORTB = ((d8 >> 1) << 0) | ((d9 >> 1) << 1) | ((d10 >> 1) << 2) | ((d11 >> 1) << 3) |
			((d12 >> 1) << 4) | ((d13 >> 1) << 5);
		PORTC = ((d14 >> 1) << 0) | ((d15 >> 1) << 1) | ((d16 >> 1) << 2) | ((d17 >> 1) << 3) |
			((d18 >> 1) << 4) | ((d19 >> 1) << 5) | ((d20 >> 1) << 6);
	}
	template<int pin, bool out> static void Output() {
		if constexpr (pin == 0)         { if constexpr (out) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); }
		} else if constexpr (pin == 1)  { if constexpr (out) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); }
		} else if constexpr (pin == 2)  { if constexpr (out) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); }
		} else if constexpr (pin == 3)  { if constexpr (out) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); }
		} else if constexpr (pin == 4)  { if constexpr (out) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); }
		} else if constexpr (pin == 5)  { if constexpr (out) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); }
		} else if constexpr (pin == 6)  { if constexpr (out) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); }
		} else if constexpr (pin == 7)  { if constexpr (out) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); }
		} else if constexpr (pin == 8)  { if constexpr (out) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); }
		} else if constexpr (pin == 9)  { if constexpr (out) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); }
		} else if constexpr (pin == 10) { if constexpr (out) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); }
		} else if constexpr (pin == 11) { if constexpr (out) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); }
		} else if constexpr (pin == 12) { if constexpr (out) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); }
		} else if constexpr (pin == 13) { if constexpr (out) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); }
		} else if constexpr (pin == 14) { if constexpr (out) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); }
		} else if constexpr (pin == 15) { if constexpr (out) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); }
		} else if constexpr (pin == 16) { if constexpr (out) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); }
		} else if constexpr (pin == 17) { if constexpr (out) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); }
		} else if constexpr (pin == 18) { if constexpr (out) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); }
		} else if constexpr (pin == 19) { if constexpr (out) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); }
		} else if constexpr (pin == 20) { if constexpr (out) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); }
		}
	}
	template<int pin> static void Output(bool out) {
		if constexpr (pin == 0) { if (out) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); }
		} else if (pin == 1)    { if (out) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); }
		} else if (pin == 2)    { if (out) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); }
		} else if (pin == 3)    { if (out) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); }
		} else if (pin == 4)    { if (out) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); }
		} else if (pin == 5)    { if (out) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); }
		} else if (pin == 6)    { if (out) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); }
		} else if (pin == 7)    { if (out) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); }
		} else if (pin == 8)    { if (out) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); }
		} else if (pin == 9)    { if (out) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); }
		} else if (pin == 10)   { if (out) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); }
		} else if (pin == 11)   { if (out) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); }
		} else if (pin == 12)   { if (out) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); }
		} else if (pin == 13)   { if (out) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); }
		} else if (pin == 14)   { if (out) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); }
		} else if (pin == 15)   { if (out) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); }
		} else if (pin == 16)   { if (out) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); }
		} else if (pin == 17)   { if (out) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); }
		} else if (pin == 18)   { if (out) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); }
		} else if (pin == 19)   { if (out) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); }
		} else if (pin == 20)   { if (out) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); }
		}
	}
	template<int pin> static uint8_t Input() {
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
		return 0;
	}
};

class ADConv {
public:
	template <
		uint8_t dataREFS	= 0b00,		// REFS: Reference Selction Bits
		uint8_t dataADLAR	= 0b0,		// ADLAR: ADC Left Adjust Result
		uint8_t dataMUX		= 0b0000,	// MUX: Analog Channel Selection Bits
		uint8_t dataADEN	= 0b0,		// ADEN: ADC Enable
		uint8_t dataADSC	= 0b0,		// ADSC: ADC Start Conversion
		uint8_t dataADATE	= 0b0,		// ADATE: ADC Auto Trigger Enable
		uint8_t dataADIF	= 0b0,		// ADIF: ADC Interrupt Flag
		uint8_t dataADIE	= 0b0,		// ADIE: ADC Interrupt Enable
		uint8_t dataADPS	= 0b000,	// ADPS: ADC Prescaler Select Bits
		uint8_t dataACME	= 0b0,		// ACME: Analog Comparator Multiplexer Enable
		uint8_t dataADTS	= 0b000		// ADTS: ADC Auto Trigger Source
	> static void Init() {
		ADMUX = (dataREFS << REFS0) | (dataADLAR << ADLAR) | (dataMUX << MUX0);
		ADCSRA = (dataADEN << ADEN) | (dataADSC << ADSC) | (dataADATE << ADATE) |
			(dataADIF << ADIF) | (dataADIE << ADIE) | (dataADPS << ADPS0);
		ADCSRB = (dataACME << ACME) | (dataADTS << ADTS0);
	}
	template<uint8_t dataMUX> static void Start() {
		ADMUX = ADMUX & (~0b1111 << MUX0) | (dataMUX << MUX0);
		ADCSRA |= (0b1 << ADSC);	// ADC Start Conversion = 1
	}
	static void Wait() {
		while (ADCSRA & (0b1 << ADSC)) ;
	}
	static uint16_t GetValue() { return ADC; }
	template<uint8_t dataMUX> static uint16_t Read() {
		Start<dataMUX>;
		Wait();
		return GetValue();
	}
};

};

#endif
