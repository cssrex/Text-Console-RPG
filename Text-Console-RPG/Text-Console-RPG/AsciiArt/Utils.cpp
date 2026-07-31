#include "Utils.h"
#include <vector>
#include <Windows.h>

void Utils::HideCursor(bool flag)
{
	CONSOLE_CURSOR_INFO CursorInfo;

	CursorInfo.dwSize = 1;
	CursorInfo.bVisible = flag;

	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &CursorInfo);
}

void Utils::MoveCursorTo(const short x, const short y)
{
	const COORD pos = { x, y };
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), pos);
}

void Utils::SetColor(int color)
{
	SetConsoleTextAttribute(GetStdHandle(STD_OUTPUT_HANDLE), color);
}
