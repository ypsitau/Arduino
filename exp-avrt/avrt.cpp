#include "avrt.h"

namespace avrt {

//------------------------------------------------------------------------------
// Serial
//------------------------------------------------------------------------------
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

//------------------------------------------------------------------------------
// Serial0
//------------------------------------------------------------------------------
void Serial0::Open(int baudRate)
{
}

void Serial0::Close()
{
}

void Serial0::Put(uint8_t data)
{
}

void Serial0::Write(const char* buff, int len)
{
}


};
