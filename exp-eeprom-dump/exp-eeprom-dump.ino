#include <avrt.h>
#include <EEPROM.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0_NoRecv(serial)

void setup()
{
	serial.Open(serial.Speed::Bps57600);
	uint16_t addrEnd = EEPROM.length();
	int col = 0;
	for (uint16_t addr = 0x0000; addr < addrEnd; addr++) {
		uint8_t data = EEPROM.read(addr);
		if (col == 0) {
			serial.Printf(F("%04X "), addr);
		} else {
			serial.Print(" ");
		}
		serial.Printf(F("%02X"), data);
		col++;
		if (col == 32) {
			serial.Println();
			col = 0;
		}
	}
	if (col > 0) serial.Println();
}

void loop()
{
}
