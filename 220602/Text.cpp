#include "Text.h"

int32 Text::Length()
{
	int32 result = 0;
	while (this->info.Char.UnicodeChar)
	{
		++result;
		++this->info;
	}

	return result;
}