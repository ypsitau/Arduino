#include "avrt.h"

#define ENABLE_L_FLAG

namespace avrt {

//------------------------------------------------------------------------------
// FormatterFlags
//------------------------------------------------------------------------------
void FormatterFlags::Initialize()
{
	upperCaseFlag = false;
	leftAlignFlag = false;
	sharpFlag = false;
	fieldMinWidth = 0;
	precision = Prec::Default;
	plusMode = PlusMode::None;
	charPadding = ' ';
}

const char* FormatterFlags::FormatNumber_e(float num, char* buff, size_t size) const
{
#if 1
	char fmt[32];
	ToString(fmt, upperCaseFlag? 'E' : 'e');
	::snprintf(buff, size, fmt, num);
#endif
	return buff;
}

const char* FormatterFlags::FormatNumber_f(float num, char* buff, size_t size) const
{
#if 1
	char fmt[32];
	ToString(fmt, 'f');
	::snprintf(buff, size, fmt, num);
#endif
	return buff;
}

const char* FormatterFlags::FormatNumber_g(float num, char* buff, size_t size) const
{
#if 1
	char fmt[32];
	ToString(fmt, upperCaseFlag? 'G' : 'g');
	::snprintf(buff, size, fmt, num);
#endif
	return buff;
}

void FormatterFlags::ToString(char* fmt, char qualifier) const
{
	char* p = fmt;
	*p++ = '%';
	if (leftAlignFlag) *p++ += '-';
	if (sharpFlag) *p++ += '#';
	if (charPadding == '0') *p++ += '0';
	if (plusMode == PlusMode::Space) {
		*p++ += ' ';
	} else if (plusMode == PlusMode::Plus) {
		*p++ += '+';
	}
	if (fieldMinWidth > 0) {
		::itoa(fieldMinWidth, p, 10);
		for ( ; *p; p++) ;
	}
	if (precision == Prec::Null) {
		*p++ = '.';
	} else if (precision >= 0) {
		*p++ = '.';
		::itoa(precision, p, 10);
		for ( ; *p; p++) ;
	}
	*p++ += qualifier;
	*p = '\0';
}

//------------------------------------------------------------------------------
// Serial
//------------------------------------------------------------------------------
void Serial::Write(const uint8_t* buff, int len)
{
	for ( ; len > 0; buff++, len--) PutData(*buff);
}

void Serial::Print(const char* str)
{
	for (const char* p = str; *p; p++) PutChar(*p);
}

void Serial::Print(const __FlashStringHelper* str)
{
	const char* p = reinterpret_cast<const char*>(str);
	for ( ; ; p++) {
		char ch = pgm_read_byte(p);
		if (!ch) break;
		PutChar(ch);
	}
}

void Serial::Println(const char* str)
{
	Print(str);
	PutChar('\n');
}

void Serial::Println(const __FlashStringHelper* str)
{
	Print(str);
	PutChar('\n');
}

bool Serial::Printf(const char* format, ...)
{
	va_list ap;
	va_start(ap, format);
	bool rtn = PrintfV(format, ap);
	va_end(ap);
	return rtn;
}

bool Serial::Printf(const __FlashStringHelper* format, ...)
{
	va_list ap;
	va_start(ap, format);
	bool rtn = PrintfV(format, ap);
	va_end(ap);
	return rtn;
}

bool Serial::PrintfV(const char* format, va_list ap)
{
	StringPtr_SRAM format_(format);
	return PrintfV(format_, ap);
}

bool Serial::PrintfV(const __FlashStringHelper* format, va_list ap)
{
	StringPtr_Flash format_(format);
	return PrintfV(format_, ap);
}

bool Serial::PrintfV(StringPtr& format, va_list ap)
{
	enum class Stat {
		Start, NoFormat, FlagsPre, Flags,
		FlagsAfterWhite,
#if defined(ENABLE_L_FLAG)
		FlagsAfterL,
#endif
		PrecisionPre, Precision, Padding,
	};
	char buff[40];
	bool eatNextFlag;
	FormatterFlags formatterFlags;
	Stat stat = Stat::Start;
	char ch = format.Next();
	for (;;) {
		eatNextFlag = true;
		if (ch == '\0') break;
		switch (stat) {
		case Stat::Start: {
			if (ch == '%') {
				stat = Stat::FlagsPre;
			} else {
				PutChar(ch);
			}
			break;
		}
		case Stat::NoFormat: {
			PutChar(ch);
			break;
		}
		case Stat::FlagsPre: {
			if (ch == '%') {
				PutChar(ch);
				stat = Stat::Start;
			} else {
				formatterFlags.Initialize();
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
		case Stat::Flags: {
			if (ch == '#') {
				formatterFlags.sharpFlag = true;
			} else if (ch == '0') {
				if (!formatterFlags.leftAlignFlag) {
					formatterFlags.charPadding = '0';
				}
			} else if (ch == '-') {
				formatterFlags.leftAlignFlag = true;
				formatterFlags.charPadding = ' ';
			} else if (ch == ' ') {
				if (formatterFlags.plusMode == FormatterFlags::PlusMode::None) {
					formatterFlags.plusMode = FormatterFlags::PlusMode::Space;
				}
				stat = Stat::FlagsAfterWhite;
			} else if (ch == '+') {
				formatterFlags.plusMode = FormatterFlags::PlusMode::Plus;
			} else if (ch == '*') {
				formatterFlags.fieldMinWidth = va_arg(ap, int);
				if (formatterFlags.fieldMinWidth < 0) {
					formatterFlags.leftAlignFlag = true;
					formatterFlags.fieldMinWidth = -formatterFlags.fieldMinWidth;
				}
			} else if ('0' < ch && ch <= '9') {
				eatNextFlag = false;
				stat = Stat::Padding;
			} else if (ch == '.') {
				stat = Stat::PrecisionPre;
			} else if (ch == 'l') {
#if defined(ENABLE_L_FLAG)
				stat = Stat::FlagsAfterL;
#else
				static const char msg[] PROGMEM = "[l flag is not enabled]";
				Print(reinterpret_cast<const __FlashStringHelper*>(msg));
				stat = Stat::NoFormat;
#endif
			} else if (ch == 'd' || ch == 'i') {
				int num = va_arg(ap, int);
				const char* p = formatterFlags.FormatNumber_d<int, unsigned int>(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'u') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_u(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'b') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_b(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'o') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_o(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'x' || ch == 'X') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.upperCaseFlag = (ch == 'X');
				const char* p = formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'p') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				Print("0x");
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'e' || ch == 'E') {
				float num = va_arg(ap, float);
				formatterFlags.upperCaseFlag = (ch == 'E');
				const char* p = formatterFlags.FormatNumber_e(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'f' || ch == 'F') {
				float num = va_arg(ap, float);
				const char* p = formatterFlags.FormatNumber_f(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'g' || ch == 'G') {
				float num = va_arg(ap, float);
				formatterFlags.upperCaseFlag = (ch == 'G');
				const char* p = formatterFlags.FormatNumber_g(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 's') {
				const char* str = va_arg(ap, const char*);
				PutAlignedString(formatterFlags, str);
				stat = Stat::Start;
			} else if (ch == 'c') {
				char ch = va_arg(ap, char);
				PutChar(ch);
				stat = Stat::Start;
			} else {
				return false;
			}
			break;
		}
		case Stat::FlagsAfterWhite: {
			if (ch == ' ') {
				return false;
			} else {
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
#if defined(ENABLE_L_FLAG)
		case Stat::FlagsAfterL: {
			if (ch == 'd' || ch == 'i') {
				int32_t num = va_arg(ap, int32_t);
				const char* p = formatterFlags.FormatNumber_d<int32_t, uint32_t>(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'u') {
				uint32_t num = va_arg(ap, uint32_t);
				const char* p = formatterFlags.FormatNumber_u(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'b') {
				uint32_t num = va_arg(ap, uint32_t);
				const char* p = formatterFlags.FormatNumber_b(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'o') {
				uint32_t num = va_arg(ap, uint32_t);
				const char* p = formatterFlags.FormatNumber_o(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else if (ch == 'x' || ch == 'X') {
				uint32_t num = va_arg(ap, uint32_t);
				formatterFlags.upperCaseFlag = (ch == 'X');
				const char* p = formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				PutAlignedString(formatterFlags, p);
				stat = Stat::Start;
			} else {
				return false;
			}
			break;
		}
#endif
		case Stat::Padding: {
			if ('0' <= ch && ch <= '9') {
				formatterFlags.fieldMinWidth = formatterFlags.fieldMinWidth * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
		case Stat::PrecisionPre: {
			if (ch == '*') {
				formatterFlags.precision = va_arg(ap, int);
				if (formatterFlags.precision < 0) formatterFlags.precision = FormatterFlags::Prec::Default;
				stat = Stat::Flags;
			} else if ('0' <= ch && ch <= '9') {
				formatterFlags.precision = 0;
				eatNextFlag = false;
				stat = Stat::Precision;
			} else {
				formatterFlags.precision = FormatterFlags::Prec::Null;
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
		case Stat::Precision: {
			if ('0' <= ch && ch <= '9') {
				formatterFlags.precision = formatterFlags.precision * 10 + (ch - '0');
			} else {
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
		default:
			break;
		}
		if (eatNextFlag) {
			ch = format.Next();
		}
	}
	return true;
}

void Serial::PutAlignedString(const FormatterFlags& formatterFlags, const char* str, int cntMax)
{
	int cnt = 0;
	for (const char* p = str; *p; p++, cnt++) ;
	if (cntMax >= 0 && cnt > cntMax) cnt = cntMax;
	int cntPadding = formatterFlags.fieldMinWidth - cnt;
	const char* p = str;
	if (formatterFlags.leftAlignFlag) {
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
		while (cntPadding-- > 0) PutChar(formatterFlags.charPadding);
	} else {
		while (cntPadding-- > 0) PutChar(formatterFlags.charPadding);
		for ( ; cnt > 0; p++, cnt--) PutChar(*p);
	}
}

uint16_t Serial::LookupUBRR(BaudRate baudRate, bool doubleSpeedFlag)
{
	// 20.20 Examples of Baud Rate Setting
	// System Clock = 16.0000MHz
	if (doubleSpeedFlag) {
		return
			(baudRate == BaudRate2400)? 832 : (baudRate == BaudRate4800)? 416 :
			(baudRate == BaudRate9600)? 207 : (baudRate == BaudRate14400)? 138 :
			(baudRate == BaudRate19200)? 103 : (baudRate == BaudRate28800)? 68 :
			(baudRate == BaudRate38400)? 51 : (baudRate == BaudRate57600)? 34 :
			(baudRate == BaudRate76800)? 25 : (baudRate == BaudRate115200)? 16 :
			(baudRate == BaudRate230400)? 8 : (baudRate == BaudRate250000)? 7 :
			(baudRate == BaudRate500000)? 3 : (baudRate == BaudRate1000000)? 1 : 207;
	} else {
		return
			(baudRate == BaudRate2400)? 416 : (baudRate == BaudRate4800)? 207 :
			(baudRate == BaudRate9600)? 103 : (baudRate == BaudRate14400)? 68 :
			(baudRate == BaudRate19200)? 51 : (baudRate == BaudRate28800)? 34 :
			(baudRate == BaudRate38400)? 25 : (baudRate == BaudRate57600)? 16 :
			(baudRate == BaudRate76800)? 12 : (baudRate == BaudRate115200)? 8 :
			(baudRate == BaudRate230400)? 3 : (baudRate == BaudRate250000)? 3 :
			(baudRate == BaudRate500000)? 1 : (baudRate == BaudRate1000000)? 0 : 103;
	}
}

//------------------------------------------------------------------------------
// Serial0
//------------------------------------------------------------------------------
void Serial0::Open(BaudRate baudRate, uint8_t charSize, uint8_t stopBit, uint8_t parity)
{
	constexpr bool doubleSpeedFlag = false;
	constexpr uint8_t dataU2X = doubleSpeedFlag? 0b1 : 0b0;
	uint8_t dataUCSZ = charSize;
	uint8_t dataUSBS = stopBit;
	uint8_t dataUPM = parity;
	uint16_t dataUBRR = LookupUBRR(baudRate, doubleSpeedFlag);
	UCSR0A =
		(0b1 << TXC0) |					// TXCn: USART Transmit Complete .. set one to clear
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

void Serial0::PutData(uint8_t data)
{
	UDR0 = data;
	while (!(UCSR0A & (0b1 << TXC0))) ;
	UCSR0A |= (0b1 << TXC0);	// set one to clear TXCn
}

uint8_t Serial0::GetData()
{
	return UDR0;
}

};
