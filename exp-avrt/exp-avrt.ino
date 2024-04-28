namespace avrt {

template<int pin, bool out> void OutputPin()
{
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

template<int pin> void OutputPin(bool out)
{
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

template<int pin> uint8_t InputPin()
{
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

volatile uint8_t data;
volatile bool flag = true;

void setup()
{
	avrt::OutputPin<0, false>();
	avrt::OutputPin<1, false>();
	avrt::OutputPin<2, false>();
	avrt::OutputPin<3, false>();
	avrt::OutputPin<4, false>();
	avrt::OutputPin<5, false>();
	avrt::OutputPin<6, false>();
	avrt::OutputPin<7, false>();
	avrt::OutputPin<8, false>();
	avrt::OutputPin<9, false>();
	avrt::OutputPin<10, false>();
	avrt::OutputPin<11, false>();
	avrt::OutputPin<12, false>();
	avrt::OutputPin<13, false>();
	avrt::OutputPin<14, false>();
	avrt::OutputPin<15, false>();
	avrt::OutputPin<16, false>();
	avrt::OutputPin<17, false>();
	avrt::OutputPin<18, false>();
	avrt::OutputPin<19, false>();
	avrt::OutputPin<20, false>();
	avrt::OutputPin<0, true>();
	avrt::OutputPin<1, true>();
	avrt::OutputPin<2, true>();
	avrt::OutputPin<3, true>();
	avrt::OutputPin<4, true>();
	avrt::OutputPin<5, true>();
	avrt::OutputPin<6, true>();
	avrt::OutputPin<7, true>();
	avrt::OutputPin<8, true>();
	avrt::OutputPin<9, true>();
	avrt::OutputPin<10, true>();
	avrt::OutputPin<11, true>();
	avrt::OutputPin<12, true>();
	avrt::OutputPin<13, true>();
	avrt::OutputPin<14, true>();
	avrt::OutputPin<15, true>();
	avrt::OutputPin<16, true>();
	avrt::OutputPin<17, true>();
	avrt::OutputPin<18, true>();
	avrt::OutputPin<19, true>();
	avrt::OutputPin<20, true>();
	avrt::OutputPin<0>(flag);
	avrt::OutputPin<1>(flag);
	avrt::OutputPin<2>(flag);
	avrt::OutputPin<3>(flag);
	avrt::OutputPin<4>(flag);
	avrt::OutputPin<5>(flag);
	avrt::OutputPin<6>(flag);
	avrt::OutputPin<7>(flag);
	avrt::OutputPin<8>(flag);
	avrt::OutputPin<9>(flag);
	avrt::OutputPin<10>(flag);
	avrt::OutputPin<11>(flag);
	avrt::OutputPin<12>(flag);
	avrt::OutputPin<13>(flag);
	avrt::OutputPin<14>(flag);
	avrt::OutputPin<15>(flag);
	avrt::OutputPin<16>(flag);
	avrt::OutputPin<17>(flag);
	avrt::OutputPin<18>(flag);
	avrt::OutputPin<19>(flag);
	avrt::OutputPin<20>(flag);
	avrt::InputPin<0>();
	avrt::InputPin<1>();
	avrt::InputPin<2>();
	avrt::InputPin<3>();
	avrt::InputPin<4>();
	avrt::InputPin<5>();
	avrt::InputPin<6>();
	avrt::InputPin<7>();
	avrt::InputPin<8>();
	avrt::InputPin<9>();
	avrt::InputPin<10>();
	avrt::InputPin<11>();
	avrt::InputPin<12>();
	avrt::InputPin<13>();
	avrt::InputPin<14>();
	avrt::InputPin<15>();
	avrt::InputPin<16>();
	avrt::InputPin<17>();
	avrt::InputPin<18>();
	avrt::InputPin<19>();
	avrt::InputPin<20>();
}

void loop()
{
}
