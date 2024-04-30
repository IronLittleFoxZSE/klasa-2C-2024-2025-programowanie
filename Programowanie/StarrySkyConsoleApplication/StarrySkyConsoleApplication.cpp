#include <iostream>
#include <windows.h>
#include <conio.h>

void setCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

void getConsolResolution(int& consoleWidth, int& consoleHeight)
{
	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(GetStdHandle(STD_OUTPUT_HANDLE), &csbi);

	consoleWidth = csbi.srWindow.Right - csbi.srWindow.Left;
	consoleHeight = csbi.srWindow.Bottom - csbi.srWindow.Top;
}

void showStarrySky()
{
	const unsigned int NUMBER_OF_STARS = 50;
	int coordinatesX[NUMBER_OF_STARS];
	int coordinatesY[NUMBER_OF_STARS];

	int consoleWidth, consoleHeight;

	showConsoleCursor(false);
	system("cls");
	getConsolResolution(consoleWidth, consoleHeight);
	srand(time(NULL));
	for (int i = 0; i < NUMBER_OF_STARS; i++)
	{
		coordinatesX[i] = rand() % consoleWidth;
		coordinatesY[i] = rand() % consoleHeight;
	}

	while (true)
	{
		for (int i = 0; i < NUMBER_OF_STARS; i++)
		{
			bool showNewStar = rand() % 2;

			if (showNewStar)
			{
				setCursor(coordinatesX[i], coordinatesY[i]);
				std::cout << " ";
				coordinatesX[i] = rand() % consoleWidth;
				coordinatesY[i] = rand() % consoleHeight;
				setCursor(coordinatesX[i], coordinatesY[i]);
				std::cout << "*";
			}
			Sleep(100);
		}
	}
}

int main()
{
	showStarrySky();
}
