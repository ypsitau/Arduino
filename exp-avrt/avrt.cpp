#include <stdarg.h>
#include "avrt.h"

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

const char* FormatterFlags::FormatNumber_d(int num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else if (num > 0) {
		int nCols = 0;
		for ( ; num != 0; num /= 10, nCols++) {
			p--;
			*p = (num % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 2) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (plusMode == PlusMode::Space) {
			p--;
			*p = ' ';
		} else if (plusMode == PlusMode::Plus) {
			p--;
			*p = '+';
		}
	} else {
		int nCols = 0;
		unsigned int numNeg = -num;
		for ( ; numNeg != 0; numNeg /= 10, nCols++) {
			p--;
			*p = (numNeg % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 2) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		p--;
		*p = '-';
	}
	return p;
}

const char* FormatterFlags::FormatNumber_u(unsigned int num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num /= 10, nCols++) {
			p--;
			*p = (num % 10) + '0';
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
	}
	return p;
}

const char* FormatterFlags::FormatNumber_b(unsigned int num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 1, nCols++) {
			p--;
			*p = '0' + (num & 0x1);
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (sharpFlag) {
			p--;
			*p = 'b';
			p--;
			*p = '0';
		}
	}
	return p;
}

const char* FormatterFlags::FormatNumber_o(unsigned int num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 3, nCols++) {
			p--;
			*p = '0' + (num & 0x7);
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 1) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		} else if (sharpFlag) {
			p--;
			*p = '0';
		}
	}
	return p;
}

const char* FormatterFlags::FormatNumber_x(unsigned int num, char* buff, size_t size) const
{
	char* p = buff + size - 1;
	*p = '\0';
	const char* convTbl = upperCaseFlag? "0123456789ABCDEF" : "0123456789abcdef";
	if (num == 0) {
		if (precision == 0) {
			// empty string
		} else {
			p--;
			*p = '0';
		}
	} else {
		int nCols = 0;
		for ( ; num != 0; num >>= 4, nCols++) {
			p--;
			*p = convTbl[num & 0xf];
		}
		if (nCols < precision) {
			int cnt = ChooseMin(precision, static_cast<int>(size) - 3) - nCols;
			while (cnt-- > 0) {
				p--;
				*p = '0';
			}
		}
		if (sharpFlag) {
			p--;
			*p = upperCaseFlag? 'X' : 'x';
			p--;
			*p = '0';
		}
	}
	return p;
}

const char* FormatterFlags::FormatNumber_e(double num, char* buff, size_t size) const
{
	//::snprintf(buff, size, ToString(upperCaseFlag? "E" : "e").c_str(), num);
	return buff;
}

const char* FormatterFlags::FormatNumber_f(double num, char* buff, size_t size) const
{
	//::snprintf(buff, size, ToString("f").c_str(), num);
	return buff;
}

const char* FormatterFlags::FormatNumber_g(double num, char* buff, size_t size) const
{
	//::snprintf(buff, size, ToString(upperCaseFlag? "G" : "g").c_str(), num);
	return buff;
}

//------------------------------------------------------------------------------
// Serial
//------------------------------------------------------------------------------
void Serial::Write(const uint8_t* buff, int len)
{
	for ( ; len > 0; buff++, len--) PutData(*buff);
}

void Serial::PutString(char* str)
{
	for ( ; *str; str++) PutChar(*str);
}

bool Serial::Printf(const char* format, ...)
{
	enum class Stat {
		Start, FlagsPre, Flags,
		FlagsAfterWhite,
		//FlagsAfterL, FlagsAfterLL, FlagsAfterZ,
		PrecisionPre, Precision, Padding,
	};
	char buff[32];
	bool eatNextFlag;
	FormatterFlags formatterFlags;
	Stat stat = Stat::Start;
	va_list ap;
	va_start(ap, format);
	for (const char* formatp = format; ; ) {
		char ch = *formatp;
		eatNextFlag = true;
		if (ch == '\0') break;
		switch (stat) {
		case Stat::Start: {
			if (ch == '%') {
				stat = Stat::FlagsPre;
			//} else if (ch == '\n') {
			//	PutString(lineSep);
			} else {
				PutChar(ch);
			}
			break;
		}
		case Stat::FlagsPre: {
			if (ch == '%') {
				PutChar(ch);
				stat = Stat::Start;
			} else {
				//if (source.IsEnd()) {
				//	IssueError_NotEnoughArguments();
				//	return false;
				//}
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
				formatterFlags.fieldMinWidth = va_arg(ap, int32_t);
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
				stat = Stat::Flags;
			//} else if (ch == 'z') {
			//	stat = Stat::FlagsAfterZ;
			} else if (ch == 'd' || ch == 'i') {
				int num = va_arg(ap, int);
				const char* p = formatterFlags.FormatNumber_d(num, buff, sizeof(buff));
				PutString(p);
				stat = Stat::Start;
			} else if (ch == 'u') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_u(num, buff, sizeof(buff));
				PutString(p);
				stat = Stat::Start;
			} else if (ch == 'b') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_b(num, buff, sizeof(buff));
				PutString(p);
				stat = Stat::Start;
			} else if (ch == 'o') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_o(num, buff, sizeof(buff));
				PutString(p);
				stat = Stat::Start;
			} else if (ch == 'x' || ch == 'X') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.upperCaseFlag = (ch == 'X');
				const char* p = formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				PutString(p);
				stat = Stat::Start;
			} else if (ch == 'p') {
				unsigned int num = va_arg(ap, unsigned int);
				const char* p = formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				PutString("0x");
				PutString(p);
				stat = Stat::Start;
#if 0
			} else if (ch == 'e' || ch == 'E') {
				RefPtr<Value> pValue(source.FetchDouble());
				if (!pValue) return false;
				formatterFlags.upperCaseFlag = (ch == 'E');
				if (!pValue->Format_e(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'f' || ch == 'F') {
				RefPtr<Value> pValue(source.FetchDouble());
				if (!pValue) return false;
				if (!pValue->Format_f(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'g' || ch == 'G') {
				RefPtr<Value> pValue(source.FetchDouble());
				if (!pValue) return false;
				formatterFlags.upperCaseFlag = (ch == 'G');
				if (!pValue->Format_g(*this, formatterFlags)) return false;
				stat = Stat::Start;
#endif
			} else if (ch == 's') {
				const char* str = va_arg(ap, const char*);
				PutString(str);
				stat = Stat::Start;
			} else if (ch == 'c') {
				char ch = va_arg(ap, char);
				PutChar(ch);
				stat = Stat::Start;
			} else {
				va_end(ap);
				return false;
			}
			break;
		}
		case Stat::FlagsAfterWhite: {
			if (ch == ' ') {
				va_end(ap);
				return false;
			} else {
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
#if 0
		case Stat::FlagsAfterL: {
			if (ch == 'l') {
				stat = Stat::FlagsAfterLL;
			} else {
				eatNextFlag = false;
				stat = Stat::Flags;
			}
			break;
		}
#endif
#if 0
		case Stat::FlagsAfterLL: {
			if (ch == 'd' || ch == 'i') {
				int32_t num = va_arg(ap, int32_t);
				formatterFlags.FormatNumber_d(num, buff, sizeof(buff));
				PutString(buff);
				stat = Stat::Start;
			} else if (ch == 'u') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.FormatNumber_u(num, buff, sizeof(buff));
				PutString(buff);
				stat = Stat::Start;
			} else if (ch == 'b') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.FormatNumber_b(num, buff, sizeof(buff));
				PutString(buff);
				stat = Stat::Start;
			} else if (ch == 'o') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.FormatNumber_o(num, buff, sizeof(buff));
				PutString(buff);
				stat = Stat::Start;
			} else if (ch == 'x' || ch == 'X') {
				unsigned int num = va_arg(ap, unsigned int);
				formatterFlags.upperCaseFlag = (ch == 'X');
				formatterFlags.FormatNumber_x(num, buff, sizeof(buff));
				PutString(buff);
				stat = Stat::Start;
			} else {
				va_end(ap);
				return false;
			}
			break;
		}
#endif
#if 0
		case Stat::FlagsAfterZ: {
			if (ch == 'd' || ch == 'i') {
				RefPtr<Value> pValue(source.FetchSizeT());
				if (!pValue) return false;
				if (!pValue->Format_d(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'u') {
				RefPtr<Value> pValue(source.FetchSizeT());
				if (!pValue) return false;
				if (!pValue->Format_u(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'b') {
				RefPtr<Value> pValue(source.FetchSizeT());
				if (!pValue) return false;
				if (!pValue->Format_b(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'o') {
				RefPtr<Value> pValue(source.FetchSizeT());
				if (!pValue) return false;
				if (!pValue->Format_o(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else if (ch == 'x' || ch == 'X') {
				RefPtr<Value> pValue(source.FetchSizeT());
				if (!pValue) return false;
				formatterFlags.upperCaseFlag = (ch == 'X');
				if (!pValue->Format_x(*this, formatterFlags)) return false;
				stat = Stat::Start;
			} else {
				IssueError_WrongFormat();
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
		if (eatNextFlag) formatp++;
	}
	va_end(ap);
	return true;
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
