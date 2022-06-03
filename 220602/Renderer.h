#pragma once
#pragma once

#include <Windows.h>
#include "Text.h"

class Renderer
{
public:
	Renderer() = delete;
	~Renderer() = delete;
	Renderer(const Renderer&) = delete;
	Renderer& operator=(const Renderer&) = delete;

	bool Init(void)
	{
		s_consoleHandle = GetStdHandle(STD_OUTPUT_HANDLE);
		if (INVALID_HANDLE_VALUE == s_consoleHandle)
		{
			return false;
		}

		for (int32 i = 0; i < 2; i++)
		{
			s_screens[i] = CreateConsoleScreenBuffer(GENERIC_READ | GENERIC_WRITE, 0, NULL, CONSOLE_TEXTMODE_BUFFER, NULL);
		}

		return true;
	}

	void Cleanup(void)
	{
		CloseHandle(s_consoleHandle);
		CloseHandle(s_screens[0]);
		CloseHandle(s_screens[1]);
	}

	static void clear(HANDLE consoleHandle)
	{
		CONSOLE_SCREEN_BUFFER_INFO csbi;
		GetConsoleScreenBufferInfo(consoleHandle, &csbi);

		SMALL_RECT scrollRect;
		scrollRect.Left = 0;
		scrollRect.Top = 0;
		scrollRect.Right = csbi.dwSize.X;
		scrollRect.Bottom = csbi.dwSize.Y;

		COORD scrollTarget;
		scrollTarget.X = 0;
		scrollTarget.Y = (SHORT)(0 - csbi.dwSize.Y);

		CHAR_INFO fill;
		fill.Char.UnicodeChar = TEXT(' ');
		fill.Attributes = csbi.wAttributes;

		ScrollConsoleScreenBuffer(consoleHandle, &scrollRect, NULL, scrollTarget, &fill);

		csbi.dwCursorPosition.X = 0;
		csbi.dwCursorPosition.Y = 0;
		SetConsoleCursorPosition(consoleHandle, csbi.dwCursorPosition);
	}

	void Flip(void)
	{
		SetConsoleActiveScreenBuffer(s_screens[s_backIndex]);

		s_backIndex = !s_backIndex;

		clear(s_screens[s_backIndex]);
	}

	void DrawText(const Text* text, int32 numberOfChar, int32 x, int32 y)
	{
		HANDLE backBuffer = s_screens[s_backIndex];

		// 2. 커서 위치를 옮겨준다.
		COORD pos = { x, y };
		SetConsoleCursorPosition(backBuffer, pos);

		// 3. 백 버퍼에 텍스트를 출력한다.
		for (int32 i = 0; i < numberOfChar; ++i)
		{
			SetConsoleTextAttribute(backBuffer, text);
			WriteConsole(backBuffer, &text[i].Char, 1, NULL, NULL);
		}
		SetConsoleTextAttribute(backBuffer, TEXT_COLOR_WHITE);
	}

private:
	HANDLE s_consoleHandle;
	HANDLE s_screens[2];
	int32 s_backIndex;
};