#pragma once
#include <wchar.h>
#define TextCopyWithWhite(dest, src) TextCopy(dest, src, TEXT_COLOR_WHITE)

#define FOREGROUND_BLUE      0x0001 // text color contains blue.
#define FOREGROUND_GREEN     0x0002 // text color contains green.
#define FOREGROUND_RED       0x0004 // text color contains red.
#define FOREGROUND_INTENSITY 0x0008 // text color is intensified.
#define BACKGROUND_BLUE      0x0010 // background color contains blue.
#define BACKGROUND_GREEN     0x0020 // background color contains green.
#define BACKGROUND_RED       0x0040 // background color contains red.
#define BACKGROUND_INTENSITY 0x0080 // background color is intensified.

typedef unsigned short WORD;
typedef char CHAR;
typedef wchar_t WCHAR;
typedef __int32 int32;
typedef struct _CHAR_INFO {
	union {
		WCHAR UnicodeChar;
		CHAR   AsciiChar;
	} Char;
	WORD Attributes;
} CHAR_INFO, * PCHAR_INFO;

class Text
{
	enum TextColor
	{
		TEXT_COLOR_BLACK,
		TEXT_COLOR_BLUE = FOREGROUND_BLUE,
		TEXT_COLOR_RED = FOREGROUND_RED,
		TEXT_COLOR_GREEN = FOREGROUND_GREEN,
		TEXT_COLOR_CYAN = TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
		TEXT_COLOR_MAGENTA = TEXT_COLOR_RED | TEXT_COLOR_BLUE,
		TEXT_COLOR_YELLOW = TEXT_COLOR_RED | TEXT_COLOR_GREEN,
		TEXT_COLOR_WHITE = TEXT_COLOR_RED | TEXT_COLOR_BLUE | TEXT_COLOR_GREEN,
		TEXT_COLOR_STRONG = FOREGROUND_INTENSITY
	};

	enum BackgroundColor
	{
		BACK_COLOR_BLACK,
		BACK_COLOR_BLUE = BACKGROUND_BLUE,
		BACK_COLOR_RED = BACKGROUND_RED,
		BACK_COLOR_GREEN = BACKGROUND_GREEN,
		BACK_COLOR_CYAN = BACK_COLOR_BLUE | BACK_COLOR_GREEN,
		BACK_COLOR_MAGENTA = BACK_COLOR_RED | BACK_COLOR_BLUE,
		BACK_COLOR_YELLOW = BACK_COLOR_RED | BACK_COLOR_GREEN,
		BACK_COLOR_WHITE = BACK_COLOR_RED | BACK_COLOR_BLUE | BACK_COLOR_GREEN,
		BACK_COLOR_STRONG = BACKGROUND_INTENSITY
	};

public:
	~Text() = delete;
	Text& operator=(const Text&) = delete;

	Text(const WCHAR* str, WORD attribute)
		: info{}
	{
		while (*str)
		{
			this->info.Char.UnicodeChar = *str;
			this->info.Attributes = attribute;

			(this->info);
			++str;
		}

		this->info.Char.UnicodeChar = L'\0';
		this->info.Attributes = 0;
	}

	Text(const Text&)
	{

	}

	int32 Length();

private:
	CHAR_INFO info = { 0 };
};