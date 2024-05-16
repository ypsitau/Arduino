#include <avrt.h>
#include <avr/boot.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0_NoRecv(serial)

void setup()
{
	uint8_t data;
	serial.Open(serial.Speed::Bps57600);
	data = boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS);
	serial.Printf(F("Low Fuse:      0x%02X (0b%08b)\n"), data, data);
	data = boot_lock_fuse_bits_get(GET_HIGH_FUSE_BITS);
	serial.Printf(F("High Fuse:     0x%02X (0b%08b)\n"), data, data);
	data = boot_lock_fuse_bits_get(GET_EXTENDED_FUSE_BITS);
	serial.Printf(F("Extended Fuse: 0x%02X (0b%08b)\n"), data, data);
	data = boot_lock_fuse_bits_get(GET_LOCK_BITS);
	serial.Printf(F("Lock:          0x%02X (0b%08b)\n"), data, data);
}

void loop()
{
}
