// 12.4 Interrupt Vector in ATMega328 and ATMega328P
ISR(INT0_vect) {}			// External Interrupt Request 0: PD2
ISR(INT1_vect) {}			// External Interrupt Request 1: PD3
ISR(PCINT0_vect) {}			// Pin Change Interrupt 0: PB0..PB7
ISR(PCINT1_vect) {}			// Pin Change Interrupt 1: PC0..PC6
ISR(PCINT2_vect) {}			// Pin Change Interrupt 2: PD0..PD7
ISR(WDT_vect) {}			// Watchdog Time-out Interrupt
ISR(TIMER2_COMPA_vect) {}	// Timer/Counter2 Compare Match A
ISR(TIMER2_COMPB_vect) {}	// Timer/Counter2 Compare Match B
ISR(TIMER2_OVF_vect) {}		// Timer/Counter2 Overflow
ISR(TIMER1_CAPT_vect) {}	// Timer/Counter1 Capture Event
ISR(TIMER1_COMPA_vect) {}	// Timer/Counter1 Compare Match A
ISR(TIMER1_COMPB_vect) {}	// Timer/Counter1 Compare Match B
ISR(TIMER1_OVF_vect) {}		// Timer/Counter1 Overflow
ISR(TIMER0_COMPA_vect) {}	// Timer/Counter0 Compare Match A
ISR(TIMER0_COMPB_vect) {}	// Timer/Counter0 Compare Match B
//ISR(TIMER0_OVF_vect) {}	// Timer/Counter0 Overflow .. defined in wiring.c
ISR(SPI_STC_vect) {}		// SPI Serial Transfer Complete
ISR(USART_RX_vect) {}		// USART Rx Complete .. defined in HardwareSerial0.cpp
ISR(USART_UDRE_vect) {}		// USART Data Register Empty .. defined in HardwareSerial0.cpp
ISR(USART_TX_vect) {}		// UAART Tx Complete
ISR(ADC_vect) {}			// ADC Conversion Complete
ISR(EE_READY_vect) {}		// EEPROM Ready
ISR(ANALOG_COMP_vect) {}	// Analog Comparator
ISR(TWI_vect) {}			// 2-wire Serial Interface
ISR(SPM_READY_vect) {}		// Store Program Memory Ready

void setup()
{
}

void loop()
{
}
