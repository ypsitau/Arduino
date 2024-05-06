#include <avrt.h>

namespace av = avrt;

AVRT_IMPLEMENT_Serial0_NoRecv(serial)

void setup()
{
	serial.Open(av::Serial::BaudRate57600);
	uint16_t addrEnd = 0x8000;
	int col = 0;
	for (uint16_t addr = 0x0000; addr < addrEnd; addr++) {
		uint8_t data = pgm_read_byte(addr);
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
