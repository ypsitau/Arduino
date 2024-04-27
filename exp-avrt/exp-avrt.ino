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
	if (pin == 0)         { if (out) { PORTD |= (1 << 0); } else { PORTD &= ~(1 << 0); }
	} else if (pin == 1)  { if (out) { PORTD |= (1 << 1); } else { PORTD &= ~(1 << 1); }
	} else if (pin == 2)  { if (out) { PORTD |= (1 << 2); } else { PORTD &= ~(1 << 2); }
	} else if (pin == 3)  { if (out) { PORTD |= (1 << 3); } else { PORTD &= ~(1 << 3); }
	} else if (pin == 4)  { if (out) { PORTD |= (1 << 4); } else { PORTD &= ~(1 << 4); }
	} else if (pin == 5)  { if (out) { PORTD |= (1 << 5); } else { PORTD &= ~(1 << 5); }
	} else if (pin == 6)  { if (out) { PORTD |= (1 << 6); } else { PORTD &= ~(1 << 6); }
	} else if (pin == 7)  { if (out) { PORTD |= (1 << 7); } else { PORTD &= ~(1 << 7); }
	} else if (pin == 8)  { if (out) { PORTB |= (1 << 0); } else { PORTB &= ~(1 << 0); }
	} else if (pin == 9)  { if (out) { PORTB |= (1 << 1); } else { PORTB &= ~(1 << 1); }
	} else if (pin == 10) { if (out) { PORTB |= (1 << 2); } else { PORTB &= ~(1 << 2); }
	} else if (pin == 11) { if (out) { PORTB |= (1 << 3); } else { PORTB &= ~(1 << 3); }
	} else if (pin == 12) { if (out) { PORTB |= (1 << 4); } else { PORTB &= ~(1 << 4); }
	} else if (pin == 13) { if (out) { PORTB |= (1 << 5); } else { PORTB &= ~(1 << 5); }
	} else if (pin == 14) { if (out) { PORTC |= (1 << 0); } else { PORTC &= ~(1 << 0); }
	} else if (pin == 15) { if (out) { PORTC |= (1 << 1); } else { PORTC &= ~(1 << 1); }
	} else if (pin == 16) { if (out) { PORTC |= (1 << 2); } else { PORTC &= ~(1 << 2); }
	} else if (pin == 17) { if (out) { PORTC |= (1 << 3); } else { PORTC &= ~(1 << 3); }
	} else if (pin == 18) { if (out) { PORTC |= (1 << 4); } else { PORTC &= ~(1 << 4); }
	} else if (pin == 19) { if (out) { PORTC |= (1 << 5); } else { PORTC &= ~(1 << 5); }
	} else if (pin == 20) { if (out) { PORTC |= (1 << 6); } else { PORTC &= ~(1 << 6); }
	}
}

template<int pin> uint8_t InputPin()
{
	if (pin == 0)       return PIND & (1 << 0);
	else if (pin == 1)  return PIND & (1 << 1);
	else if (pin == 2)  return PIND & (1 << 2);
	else if (pin == 3)  return PIND & (1 << 3);
	else if (pin == 4)  return PIND & (1 << 4);
	else if (pin == 5)  return PIND & (1 << 5);
	else if (pin == 6)  return PIND & (1 << 6);
	else if (pin == 7)  return PIND & (1 << 7);
	else if (pin == 8)  return PINB & (1 << 0);
	else if (pin == 9)  return PINB & (1 << 1);
	else if (pin == 10) return PINB & (1 << 2);
	else if (pin == 11) return PINB & (1 << 3);
	else if (pin == 12) return PINB & (1 << 4);
	else if (pin == 13) return PINB & (1 << 5);
	else if (pin == 14) return PINC & (1 << 0);
	else if (pin == 15) return PINC & (1 << 1);
	else if (pin == 16) return PINC & (1 << 2);
	else if (pin == 17) return PINC & (1 << 3);
	else if (pin == 18) return PINC & (1 << 4);
	else if (pin == 19) return PINC & (1 << 5);
	else if (pin == 20) return PINC & (1 << 6);
	return 0;
}

};

volatile uint8_t data;

void setup()
{
	avrt::OutputPin<0, false>();
	avrt::OutputPin<0, true>();
	avrt::OutputPin<1, false>();
	avrt::OutputPin<1, true>();
	avrt::OutputPin<2, false>();
	avrt::OutputPin<2, true>();
	avrt::OutputPin<3, false>();
	avrt::OutputPin<3, true>();
	avrt::OutputPin<4, false>();
	avrt::OutputPin<4, true>();
	avrt::OutputPin<0>(false);
	data = avrt::InputPin<0>();
	data = avrt::InputPin<1>();
	data = avrt::InputPin<2>();
	data = avrt::InputPin<3>();
	data = avrt::InputPin<4>();
	data = avrt::InputPin<5>();
	data = avrt::InputPin<6>();
	data = avrt::InputPin<7>();
	data = avrt::InputPin<8>();
	data = avrt::InputPin<9>();
	//avrt::OutputPin(0, HIGH);
	//Serial.print(avrt::InputPin<0>());
}

void loop()
{
}
