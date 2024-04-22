#include <EEPROM.h>

char HalfToHexChar(uint8_t num)
{
	static const char hexCharTbl[] PROGMEM = "0123456789ABCDEF";
	return pgm_read_byte(&hexCharTbl[num]);
}

void setup()
{
	Serial.begin(57500);
	uint16_t addrEnd = EEPROM.length();
	int col = 0;
	for (uint16_t addr = 0x0000; addr < addrEnd; addr++) {
		uint8_t data = EEPROM.read(addr);
		if (col == 0) {
			Serial.print(HalfToHexChar((addr >> 12) & 0xf));
			Serial.print(HalfToHexChar((addr >> 8) & 0xf));
			Serial.print(HalfToHexChar((addr >> 4) & 0xf));
			Serial.print(HalfToHexChar(addr & 0xf));
			Serial.print("  ");
		} else {
			Serial.print(" ");
		}
		Serial.print(HalfToHexChar((data >> 4) & 0xf));
		Serial.print(HalfToHexChar(data & 0xf));
		col++;
		if (col == 32) {
			Serial.print("\n");
			col = 0;
		}
	}
	if (col > 0) Serial.print("\n");
}

void loop()
{
}
