#include <iostream>
#include <windows.h>
#include <conio.h>

enum keyCode
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESC
};

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

void setCursor(point &p)
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

keyCode codeChar(unsigned char charToCode)
{
	if (charToCode == 'w' || charToCode == 72)
		return keyCode::UP;
	if (charToCode == 's' || charToCode == 80)
		return keyCode::DOWN;
	if (charToCode == 'a' || charToCode == 75)
		return keyCode::LEFT;
	if (charToCode == 'd' || charToCode == 77)
		return keyCode::RIGHT;
	if (charToCode == 27)
		return keyCode::ESC;
}

keyCode getKeyCode(keyCode prevKeyCode)
{
	unsigned char currentChar = 0;
	keyCode currentKeyCode = prevKeyCode;
	if (_kbhit())
	{
		currentChar = _getch();
		if (currentChar == 224 || currentChar == 0)
		{
			currentChar = _getch();
			if (currentChar == 72
				|| currentChar == 80
				|| currentChar == 75
				|| currentChar == 77
				|| currentChar == 27)
				currentKeyCode = codeChar(currentChar);
		}
		else if (currentChar == 'w'
			|| currentChar == 's'
			|| currentChar == 'a'
			|| currentChar == 'd'
			|| currentChar == 27)
			currentKeyCode = codeChar(currentChar);
	}
	return currentKeyCode;
}

void setRandomCoordinate(point &p ,int maxX, int maxY)
{
	p.x = rand() % maxX;
	p.y = rand() % maxY;
}

void fillItemsToCollect(point itemsToCollect[], unsigned int count, int maxX, int maxY)
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		setRandomCoordinate(itemsToCollect[i], maxX, maxY);
	}
}

void printCharacter(point &p, char sign)
{
	setCursor(p);
	std::cout << sign;
}

void printItemsToCollect(point itemsToCollect[], unsigned int count)
{
	for (int i = 0; i < count; i++)
	{
		printCharacter(itemsToCollect[i], '*');
	}
}

int getHitItemCollect(point coordinate, point itemsToCollect[], unsigned int count)
{
	for (int i = 0; i < count; i++)
	{
		if (itemsToCollect[i].x == coordinate.x
			&& itemsToCollect[i].y == coordinate.y)
			return i;
	}
	return -1;
}

void changeCoordinate(point& coordinate, keyCode currentKeyCode, int consoleWidth, int consoleHeight)
{
	switch (currentKeyCode)
	{
	case keyCode::UP:
		if (coordinate.y > 0)
			coordinate.y--;
		else
			coordinate.y = consoleHeight;
		break;
	case keyCode::DOWN:
		if (coordinate.y < consoleHeight)
			coordinate.y++;
		else
			coordinate.y = 0;
		break;
	case keyCode::LEFT:
		if (coordinate.x > 0)
			coordinate.x--;
		else
			coordinate.x = consoleWidth;
		break;
	case keyCode::RIGHT:
		if (coordinate.x < consoleWidth)
			coordinate.x++;
		else
			coordinate.x = 0;
		break;
	default:
		break;
	}
}

int main()
{
	/*unsigned char sign;

	while (true)
	{
		sign = _getch();
		std::cout << (int)sign << "\n";
	}

	return 0;*/

	/*std::string password = "";
	char characterFromUser;

	do
	{
		characterFromUser = _getch();
		std::cout << "*";
		if (characterFromUser != 13)
			password += characterFromUser;
	} while (characterFromUser != 13);

	std::cout << "\n" << password;

	return 0;*/


	//typ nazwa;
	//point coordinate;
	const unsigned int SNAKE_MAX_LENGTH = 10;
	point snakeCoordinates[SNAKE_MAX_LENGTH];
	unsigned int snakeHead = 0;
	unsigned int snakeTail = 0;
	//coordinate.x = 0;
	//coordinate.y = 0;

	keyCode currentKeyCode = keyCode::RIGHT;
	int consoleHeight, consoleWidth;

	const unsigned int ELEMENT_TO_COLLECT_COUNT = 20;
	point itemsToCollect[ELEMENT_TO_COLLECT_COUNT];

	getConsolResolution(consoleWidth, consoleHeight);

	showConsoleCursor(false);
	system("cls");

	fillItemsToCollect(itemsToCollect, ELEMENT_TO_COLLECT_COUNT, consoleWidth, consoleHeight);
	printItemsToCollect(itemsToCollect, ELEMENT_TO_COLLECT_COUNT);

	setRandomCoordinate(snakeCoordinates[snakeHead], consoleWidth, consoleHeight);
	while (true)
	{
		printCharacter(snakeCoordinates[snakeHead], 'X');

		int hit;
		if ((hit = getHitItemCollect(snakeCoordinates[snakeHead], itemsToCollect, ELEMENT_TO_COLLECT_COUNT)) >= 0)
		{
			setRandomCoordinate(itemsToCollect[hit], consoleWidth, consoleHeight);

			printCharacter(itemsToCollect[hit], '*');
		}

		currentKeyCode = getKeyCode(currentKeyCode);	

		if (hit == -1 && snakeTail != snakeHead)
		{
			printCharacter(snakeCoordinates[snakeTail], ' ');
			snakeTail = (snakeTail + 1) % SNAKE_MAX_LENGTH;
		}

		Sleep(300);

		point tmpHead = snakeCoordinates[snakeHead];
		snakeHead = (snakeHead + 1) % SNAKE_MAX_LENGTH;
		snakeCoordinates[snakeHead] = tmpHead;

		changeCoordinate(snakeCoordinates[snakeHead], currentKeyCode, consoleWidth, consoleHeight);

		if (currentKeyCode == keyCode::ESC)
			break;
	}

	//setCursor(5, 7);
	//std::cout << "Hello World!\n";
	//setCursor(4, 6);
	//int x;
	//std::cin >> x;
}