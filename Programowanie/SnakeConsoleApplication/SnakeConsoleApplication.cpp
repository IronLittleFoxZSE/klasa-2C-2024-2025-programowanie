#include <iostream>
#include <windows.h>
#include <conio.h> 
#include "Console.h"


enum keyCode
{
	UP,
	DOWN,
	LEFT,
	RIGHT,
	ESC
};

enum itemType
{
	COLLECT,
	OBSTACLE
};



struct boardCoordinates
{
	point leftTop, rightBottom;
};

struct itemOnBoard
{
	point coordinates;
	char symbol;
	itemType type;
};



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

void setRandomCoordinate(point& p, boardCoordinates& board)
{
	p.x = rand() % (board.rightBottom.x - board.leftTop.x - 1) + board.leftTop.x + 1;
	p.y = rand() % (board.rightBottom.y - board.leftTop.y - 1) + board.leftTop.y + 1;
}

void fillItemsNoBoard(itemOnBoard itemsOnBoard[], unsigned int count, boardCoordinates& board)
{
	srand(time(NULL));
	for (int i = 0; i < count; i++)
	{
		setRandomCoordinate(itemsOnBoard[i].coordinates, board);
		itemsOnBoard[i].symbol = '*';
		itemsOnBoard[i].type = itemType::COLLECT;
	}
}

void printCharacter(point& p, char sign)
{
	setCursor(p);
	std::cout << sign;
}

void printItemsOnBoard(itemOnBoard itemsOnBoard[], unsigned int count)
{
	for (int i = 0; i < count; i++)
	{
		printCharacter(itemsOnBoard[i].coordinates, itemsOnBoard[i].symbol);
	}
}

int getHitItemOnBoard(point coordinate, itemOnBoard itemsOnBoard[], unsigned int count)
{
	for (int i = 0; i < count; i++)
	{
		if (itemsOnBoard[i].coordinates.x == coordinate.x
			&& itemsOnBoard[i].coordinates.y == coordinate.y)
			return i;
	}
	return -1;
}

void changeCoordinate(point& coordinate, keyCode currentKeyCode, boardCoordinates& board)
{
	switch (currentKeyCode)
	{
	case keyCode::UP:
		if (coordinate.y - 1 != board.leftTop.y)
			coordinate.y--;
		else
			coordinate.y = board.rightBottom.y - 1;
		break;
	case keyCode::DOWN:
		if (coordinate.y + 1 != board.rightBottom.y)
			coordinate.y++;
		else
			coordinate.y = board.leftTop.y + 1;
		break;
	case keyCode::LEFT:
		if (coordinate.x - 1 != board.leftTop.x)
			coordinate.x--;
		else
			coordinate.x = board.rightBottom.x - 1;
		break;
	case keyCode::RIGHT:
		if (coordinate.x +1 != board.rightBottom.x)
			coordinate.x++;
		else
			coordinate.x = board.leftTop.x + 1;
		break;
	default:
		break;
	}
}

void printBoard(boardCoordinates& board)
{
	/*
	########################
	#					   #
	#					   #
	#					   #
	#					   #
	########################
	*/

	setCursor(board.leftTop);
	for (int i = board.leftTop.x; i <= board.rightBottom.x; i++)
		std::cout << "#";

	for (int row = board.leftTop.y + 1; row < board.rightBottom.y; row++)
	{
		setCursor(board.leftTop.x, row);
		std::cout << "#";

		setCursor(board.rightBottom.x, row);
		std::cout << "#";
	}

	setCursor(board.leftTop.x, board.rightBottom.y);
	for (int i = board.leftTop.x; i <= board.rightBottom.x; i++)
		std::cout << "#";
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
	unsigned int currentSnakeLength = 1;
	//coordinate.x = 0;
	//coordinate.y = 0;

	keyCode currentKeyCode = keyCode::RIGHT;
	int consoleHeight, consoleWidth;

	//const unsigned int ELEMENT_TO_COLLECT_COUNT = 200;
	//point itemsToCollect[ELEMENT_TO_COLLECT_COUNT];
	const unsigned int MAX_ELEMENT_ON_BOARD = 200;
	itemOnBoard itemsOnBoard[MAX_ELEMENT_ON_BOARD];

	boardCoordinates board;

	unsigned int currentTimeSleep = 50;
	const unsigned int TIME_SLEEP_STEP = 10;
	const unsigned int MIN_TIME_SLEEP = 10;

	getConsolResolution(consoleWidth, consoleHeight);
	board.leftTop.x = 10;
	board.leftTop.y = 2;
	board.rightBottom.x = consoleWidth - 30;
	board.rightBottom.y = consoleHeight - 10;

	showConsoleCursor(false);
	system("cls");

	printBoard(board);

	fillItemsNoBoard(itemsOnBoard, MAX_ELEMENT_ON_BOARD, board);
	printItemsOnBoard(itemsOnBoard, MAX_ELEMENT_ON_BOARD);

	setRandomCoordinate(snakeCoordinates[snakeHead], board);
	printCharacter(snakeCoordinates[snakeHead], 'X');

	while (true)
	{
		int hit;
		if ((hit = getHitItemOnBoard(snakeCoordinates[snakeHead], itemsOnBoard, MAX_ELEMENT_ON_BOARD)) >= 0)
		{
			setRandomCoordinate(itemsOnBoard[hit].coordinates, board);

			printCharacter(itemsOnBoard[hit].coordinates, itemsOnBoard[hit].symbol);
		}

		if (hit != -1
			&& currentTimeSleep >= TIME_SLEEP_STEP
			&& currentTimeSleep - TIME_SLEEP_STEP >= MIN_TIME_SLEEP)
			currentTimeSleep -= TIME_SLEEP_STEP;

		Sleep(currentTimeSleep);

		point tmpHead = snakeCoordinates[snakeHead];
		snakeHead = (snakeHead + 1) % SNAKE_MAX_LENGTH;
		snakeCoordinates[snakeHead] = tmpHead;

		currentKeyCode = getKeyCode(currentKeyCode);

		changeCoordinate(snakeCoordinates[snakeHead], currentKeyCode, board);

		printCharacter(snakeCoordinates[snakeHead], 'X');

		if (hit == -1 || currentSnakeLength == SNAKE_MAX_LENGTH - 1)
		{
			printCharacter(snakeCoordinates[snakeTail], ' ');
			snakeTail = (snakeTail + 1) % SNAKE_MAX_LENGTH;
		}
		else
			currentSnakeLength++;

		if (currentKeyCode == keyCode::ESC)
			break;
	}

	//setCursor(5, 7);
	//std::cout << "Hello World!\n";
	//setCursor(4, 6);
	//int x;
	//std::cin >> x;
}