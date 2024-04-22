#include <avr/boot.h>

char HalfToHexChar(uint8_t num)
{
	static const char hexCharTbl[] PROGMEM = "0123456789ABCDEF";
	return pgm_read_byte(&hexCharTbl[num]);
}

void PrintHex(uint8_t data)
{
	Serial.print(HalfToHexChar((data >> 4) & 0xf));
	Serial.print(HalfToHexChar(data & 0xf));
}

void setup()
{
	Serial.begin(57500);
	Serial.print("Low Fuse: ");
	PrintHex(boot_lock_fuse_bits_get(GET_LOW_FUSE_BITS));
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
}

void loop()
{
}
