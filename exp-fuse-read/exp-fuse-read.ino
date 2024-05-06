#include <avr/boot.h>
#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0(serial)

void setup()
{
	serial.Open(av::Serial::BaudRate57600);
	serial.Printf("Low Fuse: %02x", boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS));
#if 0
	Serial.println();
	Serial.print("High Fuse: ");
	PrintHex(boot_lock_fuse_bits_get(GET_HIGH_FUSE_BITS));
	Serial.println();
	Serial.print("Extended Fuse: ");
	PrintHex(boot_lock_fuse_bits_get(GET_EXTENDED_FUSE_BITS));
	Serial.println();
	Serial.print("Lock: ");
	PrintHex(boot_lock_fuse_bits_get(GET_LOCK_BITS));
	Serial.println();
#endif
}

void loop()
{
}
