#include <iostream>
#include <windows.h>
#include <conio.h>

enum keyCode
{
	UP,
	DOWN = 5,
	LEFT,
	RIGHT,
	ESC
};

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

keyCode codeChar(char charToCode)
{
	if (charToCode == 'w')
		return keyCode::UP;
	if (charToCode == 's')
		return keyCode::DOWN;
	if (charToCode == 'a')
		return keyCode::LEFT;
	if (charToCode == 'd')
		return keyCode::RIGHT;
	if (charToCode == 27)
		return keyCode::ESC;
}

keyCode getKeyCode(keyCode prevKeyCode)
{
	char currentChar = 0;
	keyCode currentKeyCode = prevKeyCode;
	if (_kbhit())
		currentChar = _getch();

	if (currentChar == 'w'
		  || currentChar == 's'
		  || currentChar == 'a'
		  || currentChar == 'd'
		  || currentChar == 27)
		currentKeyCode = codeChar(currentChar);

	return currentKeyCode;
}

int main()
{
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

    unsigned short x = 0;
	unsigned short y = 0;
	keyCode currentKeyCode = keyCode::RIGHT;
	int consoleHeight, consoleWidth;

	getConsolResolution(consoleWidth, consoleHeight);

	showConsoleCursor(false);
	system("cls");

	setCursor(1, 1);
	std::cout << "M";

	while (true)
	{
		setCursor(x, y);
		std::cout << "X";

		currentKeyCode = getKeyCode(currentKeyCode);

		Sleep(300);

		setCursor(x, y);
		std::cout << " ";

		switch (currentKeyCode)
		{
		case keyCode::UP:
			if (y > 0)
				y--;
			else
				y = consoleHeight;
			break;
		case keyCode::DOWN:
			if (y < consoleHeight)
				y++;
			else
				y = 0;
			break;
		case keyCode::LEFT:
			if (x > 0)
				x--;
			else
				x = consoleWidth;
			break;
		case keyCode::RIGHT:
			if (x < consoleWidth)
				x++;
			else
				x = 0;
			break;
		default:
			break;
		}

		if (currentKeyCode == keyCode::ESC)
			break;
	}


	//setCursor(5, 7);
	//std::cout << "Hello World!\n";
	//setCursor(4, 6);
	//int x;
	//std::cin >> x;
}
