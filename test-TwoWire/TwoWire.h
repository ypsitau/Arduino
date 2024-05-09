#include <avrt.h>
#include <util/twi.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0_NoRecv(serial)

namespace avrt {

//------------------------------------------------------------------------------
// InitTwoWIre
//------------------------------------------------------------------------------
void InitTwoWire()
{
}

//------------------------------------------------------------------------------
// TwoWire
//------------------------------------------------------------------------------
template<
	uint8_t dataTWBR = 0x00,		// TWBR: TWI Bit Rate Register
	uint8_t dataTWINT = 0b0,		// TWINT: TWI Interrupt Flag
	uint8_t dataTWEA = 0b0,			// TWEA: TWI Enable Acknowldge Bit
	uint8_t dataTWSTA = 0b0,		// TWSTA: TWI START Condition Bit
	uint8_t dataTWSTO = 0b0,		// TWSTO: TWI STOP Condition Bit
	uint8_t dataTWEN = 0b0,			// TWEN: TWI Enable Bit
	uint8_t dataTWIE = 0b0,			// TWIE: TWI Interrupt Enable
	uint8_t dataTWPS = 0b00,		// TWPS: TWI Prescaler Bits
	uint8_t dataTWA = 0b0000000,	// TWA: TWI (Slave) Address Register
	uint8_t dataTWGCE = 0b0,		// TWGCE: TWI General Call Recognition Enable Bit
	uint8_t dataTWAM = 0b0000000	// TWAM: TWI Address Mask
> class TwoWire {
public:
	void Open() {
		TWBR = dataTWBR << TWBR0;
		TWCR = (dataTWINT << TWINT) | (dataTWEA << TWEA) | (dataTWSTA < TWSTA) | (dataTWSTO << TWSTO) |
			(dataTWEN << TWEN) | (dataTWIE << TWIE);
		TWSR = (dataTWPS << TWPS0);
		TWDR = 0x00;
		TWAR = (dataTWA << TWA0) | (dataTWGCE << TWGCE);
		TWAMR = dataTWAM << TWAM0;
	}
};

#define AVRT_IMPLEMENT_TwoWire(variableName) \
avrt::TwoWire<> variableName; \

}
