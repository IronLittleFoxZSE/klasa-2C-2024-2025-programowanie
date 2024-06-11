#include <iostream>
#include <windows.h>
#include <conio.h>


struct point
{
	unsigned short x;
	unsigned short y;
};

void setCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setCursor(point& p)
{
	/*COORD c;
	c.X = p.x;
	c.Y = p.y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);*/

	setCursor(p.x, p.y);
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

int main()
{
	showConsoleCursor(false);

	std::cout << "Naciœnij enter aby wystartowaæ stoper\n";

	while (_getch() != '\r') {}

	//inicjowanie pierwszego stopera
	time_t startTime = time(NULL);
	time_t stopTime;
	time_t middleTime;

	//inicjowanie drugiego stopera
	unsigned int counter = 0;
	while (true)
	{
		//pierwszy stoper
		middleTime = time(NULL);
		setCursor(10, 9);
		std::cout << middleTime - startTime << "\n";

		//drugi stoper
		unsigned int second = counter % 60;
		unsigned int minutes = (counter / 60) % 60;
		unsigned int hour = counter / 60 / 60;

		setCursor(10, 10);
		std::cout << hour << ":";
		if (minutes < 10)
			std::cout << "0";
		std::cout << minutes << ":";
		if (second < 10)
			std::cout << "0";
		std::cout << second;
		
		counter++;
		
		//dla pierwszego stopera mo¿emy zmniejszyæ wartoœæ
		Sleep(1000);

		//koniec pomiaru czasu
		if (_kbhit() && _getch() == '\r')
		{
			stopTime = time(NULL);
			break;
		}
	}

	time_t diffTime = stopTime - startTime;
	setCursor(50, 20);
	std::cout << "Ostateczny czas: " << diffTime << "\n";
}
