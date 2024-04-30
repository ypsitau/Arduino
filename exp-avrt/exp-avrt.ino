namespace avrt {

constexpr uint8_t Input = 0;
constexpr uint8_t Output = 1;
constexpr uint8_t InputPullup = 2;

class Port {
public:
	template<
		uint8_t pin0	= Input,
		uint8_t pin1	= Input,
		uint8_t pin2	= Input,
		uint8_t pin3	= Input,
		uint8_t pin4	= Input,
		uint8_t pin5	= Input,
		uint8_t pin6	= Input,
		uint8_t pin7	= Input,
		uint8_t pin8	= Input,
		uint8_t pin9	= Input,
		uint8_t pin10	= Input,
		uint8_t pin11	= Input,
		uint8_t pin12	= Input,
		uint8_t pin13	= Input,
		uint8_t pin14	= Input,
		uint8_t pin15	= Input,
		uint8_t pin16	= Input,
		uint8_t pin17	= Input,
		uint8_t pin18	= Input,
		uint8_t pin19	= Input,
		uint8_t pin20	= Input
	> static void Init() {
		DDRD = ((pin0 & 1) << 0) | ((pin1 & 1) << 1) | ((pin2 & 1) << 2) | ((pin3 & 1) << 3) |
			((pin4 & 1) << 4) | ((pin5 & 1) << 5) | ((pin6 & 1) << 6) | ((pin7 & 1) << 7);
		DDRB = ((pin8 & 1) << 0) | ((pin9 & 1) << 1) | ((pin10 & 1) << 2) | ((pin11 & 1) << 3) |
			((pin12 & 1) << 4) | ((pin13 & 1) << 5);
		DDRC = ((pin14 & 1) << 0) | ((pin15 & 1) << 1) | ((pin16 & 1) << 2) | ((pin17 & 1) << 3) |
			((pin18 & 1) << 4) | ((pin19 & 1) << 5) | ((pin20 & 1) << 6);
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


};

volatile uint8_t data;
volatile bool flag = true;

void setup()
{
	avrt::Port::Init<>();
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
