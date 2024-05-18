#include <avrt.h>
#include <util/twi.h>

#define AVRT_IMPLEMENT_TwoWire(variableName) \
avrt::TwoWire<> variableName; \
ISR(TWI_vect) { \
	variableName.HandleISR_TWI(); \
}

namespace avrt {

//------------------------------------------------------------------------------
// TwoWire
//------------------------------------------------------------------------------
template<
	uint8_t dataTWGCE = 0b0						// TWGCE: TWI General Call Recognition Enable Bit
> class TwoWire {
public:
	void Open(uint8_t address = 0x00, uint32_t freq = 100000) {
		uint8_t dataTWA = address;				// TWA: TWI (Slave) Address Register
		uint8_t dataTWBR = static_cast<uint8_t>(((F_CPU / freq) - 16) / 2);
												// TWBR: TWI Bit Rate Register
		constexpr uint8_t dataTWINT = 0b1;		// TWINT: TWI Interrupt Flag = set one to clear
		constexpr uint8_t dataTWEA = 0b1;		// TWEA: TWI Enable Acknowledge Bit = true .. connect to the bus
		constexpr uint8_t dataTWIE = 0b1;		// TWIE: TWI Interrupt Enable = true
		constexpr uint8_t dataTWEN = 0b1;		// TWEN: TWI Enable Bit = true
		constexpr uint8_t dataTWPS = 0b00;		// TWPS: TWI Prescaler Bits = Div1
		constexpr uint8_t dataTWSTA = 0b0;		// TWSTA: TWI START Condition Bit
		constexpr uint8_t dataTWSTO = 0b0;		// TWSTO: TWI STOP Condition Bit
		constexpr uint8_t dataTWAM = 0b0000000;	// TWAM: TWI Address Mask
		TWBR = dataTWBR << TWBR0;
		TWCR = (dataTWINT << TWINT) | (dataTWEA << TWEA) | (dataTWSTA < TWSTA) | (dataTWSTO << TWSTO) |
			(dataTWEN << TWEN) | (dataTWIE << TWIE);
		TWSR = (dataTWPS << TWPS0);
		TWDR = 0x00;
		TWAR = (dataTWA << TWA0) | (dataTWGCE << TWGCE);
		TWAMR = dataTWAM << TWAM0;
	}
	void Close() {
		TWCR &= ~(0b1 << TWEA);					// TWEA: TWI Enable Acknowledge Bit = false .. disconnect from the bus
	}
	void HandleISR_TWI() {
		switch (TW_STATUS) {
		case TW_START:					// 0x08: start condition transmitted
			break;
		case TW_REP_START:				// 0x10: repeated start condition transmitted
			break;
		// Master Transmitter
		case TW_MT_SLA_ACK:				// 0x18: SLA+W transmitted, ACK received
			break;
		case TW_MT_SLA_NACK:			// 0x20: SLA+W transmitted, NACK received
			break;
		case TW_MT_DATA_ACK:			// 0x28: data transmitted, ACK received
			break;
		case TW_MT_DATA_NACK:			// 0x30: data transmitted, NACK received
			break;
		//case TW_MT_ARB_LOST:			// 0x38: arbitration lost in SLA+W or data
		//	break;
		// Master Receiver
		case TW_MR_ARB_LOST:			// 0x38: arbitration lost in SLA+R or NACK
			break;
		case TW_MR_SLA_ACK:				// 0x40: SLA+R transmitted, ACK received
			break;
		case TW_MR_SLA_NACK:			// 0x48: SLA+R transmitted, NACK received
			break;
		case TW_MR_DATA_ACK:			// 0x50: data received, ACK returned
			break;
		case TW_MR_DATA_NACK:			// 0x58: data received, NACK returned
			break;
		// Slave Transmitter
		case TW_ST_SLA_ACK:				// 0xA8: SLA+R received, ACK returned
			break;
		case TW_ST_ARB_LOST_SLA_ACK:	// 0xB0: arbitration lost in SLA+RW, SLA+R received, ACK returned
			break;
		case TW_ST_DATA_ACK:			// 0xB8:data transmitted, ACK received
			break;
		case TW_ST_DATA_NACK:			// 0xC0: data transmitted, NACK received
			break;
		case TW_ST_LAST_DATA:			// 0xC8: last data byte transmitted, ACK received
			break;
		// Slave Receiver
		case TW_SR_SLA_ACK:				// 0x60: SLA+W received, ACK returned
			break;
		case TW_SR_ARB_LOST_SLA_ACK:	// 0x68: arbitration lost in SLA+RW, SLA+W received, ACK returned
			break;
		case TW_SR_GCALL_ACK:			// 0x70: general call received, ACK returned
			break;
		case TW_SR_ARB_LOST_GCALL_ACK:	// 0x78: arbitration lost in SLA+RW, general call received, ACK returned
			break;
		case TW_SR_DATA_ACK:			// 0x80: data received, ACK returned
			break;
		case TW_SR_DATA_NACK:			// 0x88:data received, NACK returned
			break;
		case TW_SR_GCALL_DATA_ACK:		// 0x90: general call data received, ACK returned
			break;
		case TW_SR_GCALL_DATA_NACK:		// 0x98: general call data received, NACK returned
			break;
		case TW_SR_STOP:				// 0xA0: stop or repeated start condition received while selected
			break;
		// Misc
		case TW_NO_INFO:				// 0xF8: no state information available
			break;
		case TW_BUS_ERROR:				// 0x00: illegal start or stop condition
			break;
		default:
			break;
		}
	}
};

}
