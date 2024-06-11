#include <iostream>
#include <windows.h>
#include <conio.h>

struct coordinate
{
	unsigned int x, y;
};

void setCursor(int x, int y)
{
	COORD c;
	c.X = x;
	c.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), c);
}

void setCursor(coordinate& p)
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
	//SendMessage(::GetConsoleWindow(), WM_SYSKEYDOWN, VK_RETURN, 0x20000000);

	const unsigned int VERTICES_COUNT = 2;
	coordinate rectangleVertices[VERTICES_COUNT];

	coordinate currentCoordinate;
	currentCoordinate.x = 0;
	currentCoordinate.y = 0;
	setCursor(currentCoordinate);

	showConsoleCursor(false);

	bool wasEnterPrevPress = false;

	for (int i = 0; i < VERTICES_COUNT; i++)
	{
		char currentChar = 0;
		do
		{
			setCursor(currentCoordinate);
			std::cout << "X";
			setCursor(currentCoordinate);

			currentChar = _getch();

			if (currentChar != 13
				&& !wasEnterPrevPress)
			{
				setCursor(currentCoordinate);
				std::cout << ' ';
				
			}
			wasEnterPrevPress = false;
			if (currentChar == 13)
				wasEnterPrevPress = true;

			switch (currentChar)
			{
			case 'w':
				currentCoordinate.y--;
				break;
			case 's':
				currentCoordinate.y++;
				break;
			case 'a':
				currentCoordinate.x--;
				break;
			case 'd':
				currentCoordinate.x++;
				break;
			case 13:
				rectangleVertices[i].x = currentCoordinate.x;
				rectangleVertices[i].y = currentCoordinate.y;
			}
			
		} while (currentChar != 13);
	}

	if (rectangleVertices[0].x > rectangleVertices[1].x
		&& rectangleVertices[0].y > rectangleVertices[1].y)
	{
		coordinate tmp = rectangleVertices[0];
		rectangleVertices[0] = rectangleVertices[1];
		rectangleVertices[1] = tmp;
	}
	if (rectangleVertices[0].x < rectangleVertices[1].x
		&& rectangleVertices[0].y > rectangleVertices[1].y)
	{
		coordinate tmp = rectangleVertices[0];
		rectangleVertices[0] = rectangleVertices[1];
		rectangleVertices[1] = tmp;
	}

	if (rectangleVertices[0].x > rectangleVertices[1].x
		&& rectangleVertices[0].y < rectangleVertices[1].y)
	{
		coordinate first;
		first.x = rectangleVertices[1].x;
		first.y = rectangleVertices[0].y;
		coordinate second;
		second.x = rectangleVertices[0].x;
		second.y = rectangleVertices[1].y;
		rectangleVertices[0] = first;
		rectangleVertices[1] = second;
	}

	setCursor(rectangleVertices[0]);
	for (int i = rectangleVertices[0].x; i <= rectangleVertices[1].x; i++)
		std::cout << "#";

	for (int row = rectangleVertices[0].y + 1; row < rectangleVertices[1].y; row++)
	{
		setCursor(rectangleVertices[0].x, row);
		std::cout << "#";

		setCursor(rectangleVertices[1].x, row);
		std::cout << "#";
	}

	setCursor(rectangleVertices[0].x, rectangleVertices[1].y);
	for (int i = rectangleVertices[0].x; i <= rectangleVertices[1].x; i++)
		std::cout << "#";

	_getch();
}
