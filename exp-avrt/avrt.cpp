#include "avrt.h"

namespace avrt {

//------------------------------------------------------------------------------
// Serial
//------------------------------------------------------------------------------
void Serial::Write(const uint8_t* buff, int len)
{
	for ( ; len > 0; buff++, len--) Put(*buff);
}

uint16_t Serial::LookupUBRR(int baudRate, bool doubleSpeedFlag)
{
	// 20.20 Examples of Baud Rate Setting
	// System Clock = 16.0000MHz
	if (doubleSpeedFlag) {
		return
			(baudRate == 2400)? 832 : (baudRate == 4800)? 416 : (baudRate == 9600)? 207 : (baudRate == 14400)? 138 :
			(baudRate == 19200)? 103 : (baudRate == 28800)? 68 : (baudRate == 38400)? 51 : (baudRate == 57600)? 34 :
			(baudRate == 76800)? 25 : (baudRate == 115200)? 16 : (baudRate == 230400)? 8 : (baudRate == 250000)? 7 :
			(baudRate == 500000)? 3 : (baudRate == 1000000)? 1 : 207;
	} else {
		return
			(baudRate == 2400)? 416 : (baudRate == 4800)? 207 : (baudRate == 9600)? 103 : (baudRate == 14400)? 68 :
			(baudRate == 19200)? 51 : (baudRate == 28800)? 34 : (baudRate == 38400)? 25 : (baudRate == 57600)? 16 :
			(baudRate == 76800)? 12 : (baudRate == 115200)? 8 : (baudRate == 230400)? 3 : (baudRate == 250000)? 3 :
			(baudRate == 500000)? 1 : (baudRate == 1000000)? 0 : 103;
	}
}

void Serial::Printf(const char* format, ...)
{
}

//------------------------------------------------------------------------------
// Serial0
//------------------------------------------------------------------------------
void Serial0::Open(int baudRate, uint8_t charSize, uint8_t parity, uint8_t stopBit)
{
	constexpr bool doubleSpeedFlag = false;
	constexpr uint8_t dataU2X = doubleSpeedFlag? 0b1 : 0b0;
	uint8_t dataUCSZ = charSize;
	uint8_t dataUPM = parity;
	uint8_t dataUSBS = stopBit;
	uint16_t dataUBRR = LookupUBRR(baudRate, doubleSpeedFlag);
	UCSR0A =
		(0b1 << TXC0) |					// TXCn: USART Transmit Complete .. clear by setting one
		(dataU2X << U2X0) |				// U2Xn: Double the USART Transmission Speed
		(0b0 << MPCM0);					// MPCMn: Multi-processor Communication Mode
	UCSR0B =
		(0b0 << RXCIE0) |				// RXCIEn: RX Complete Interrupt Enable n = false
		(0b0 << TXCIE0) |				// TXCIEn: TX Complete Interrupt Enable n = false
		(0b0 << UDRIE0) |				// UDRIEn: USART Data Register Empty Interrupt Enable n = false
		(0b1 << RXEN0) |				// RXENn: Receiver Enable n = true
		(0b1 << TXEN0) |				// TXENn: Transmitter Enable n = true
		((dataUCSZ >> 2) << UCSZ02) |	// UCSZn: Character Size
		(0b0 << TXB80);					// TXB8n: Transmit Data Bit 8 n
	UCSR0C =
		(0b00 << UMSEL00) |				// UMSELn: USART Mode Select = Asynchronous USART
		(dataUPM << UPM00) |			// UPMn: Parity Mode
		(dataUSBS << USBS0) |			// USBSn: Stop Bit Select
		((dataUCSZ & 0b11) << UCSZ00) |	// UCSZn: Character Size
		(0b0 << UCPOL0);				// UCPOLn: Clock Polarity = Tx on Rising XCKn & Rx on Falling XCKn
	UBRR0H = static_cast<uint8_t>((dataUBRR >> 8) & 0xff); // this must be written first
	UBRR0L = static_cast<uint8_t>(dataUBRR & 0xff);
}

void Serial0::Close()
{
}

void Serial0::Put(uint8_t data)
{
	UDR0 = data;
}

uint8_t Serial0::Get()
{
	return UDR0;
}

};
