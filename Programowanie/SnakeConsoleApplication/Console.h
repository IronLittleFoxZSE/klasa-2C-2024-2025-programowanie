#pragma once

struct point
{
	unsigned short x;
	unsigned short y;
};

void setCursor(int x, int y);
void setCursor(point& p);
void showConsoleCursor(bool showFlag);
void getConsolResolution(int& consoleWidth, int& consoleHeight);


