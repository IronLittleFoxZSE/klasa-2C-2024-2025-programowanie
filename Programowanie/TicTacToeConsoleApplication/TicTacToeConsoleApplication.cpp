#include <iostream>

/*
DRY - don't repeat yourself - nie powtarzaj się
KISS - Keept it simple, stupid - trzymaj prostotę głupcze
YAGNI - you aren't gonna need it - nie potrzebujesz tego
SOLID
	S - single responsibility - pojedyńcza odpowiedzialność
	O - open-close  -   otwarty-zamknięty, otwarty na rozszeżenia a zamknięty na modyfikacje
*/

void drawRow(char board[], int row, int rowCount, int fieldCount)
{
	for (int field = 0; field < fieldCount; field++)
	{
		std::cout << " " << board[rowCount * row + field] << " ";
		if (field < fieldCount - 1)
			std::cout << "|";
	}
	std::cout << "\n";
}

void drawHorizontalFrame(char board[], int fieldCount)
{
	for (int field = 0; field < fieldCount; field++)
	{
		std::cout << "---";
		if (field < fieldCount - 1)
			std::cout << "+";
	}
	std::cout << "\n";
}

void drawBoard(char board[], int rowCount, int colCount)
{
	system("cls");
	for (int row = 0; row < rowCount; row++)
	{
		drawRow(board, row, rowCount, colCount);
		if (row < rowCount - 1)
			drawHorizontalFrame(board, colCount);
	}
}

void clearBoard(char board[], int rowCount, int colCount)
{
	for (int i = 0; i < rowCount * colCount; i++)
	{
		board[i] = ' ';
	}
}

int getFieldNumberOnBoard(char playerSign)
{
	int fieldNumber;
	std::cout << "Gracz " << playerSign << " wykonuje ruch.\n";
	std::cout << "Podaj numer pola:\n";
	std::cin >> fieldNumber;
	return fieldNumber;
}

bool isDraw(char board[], int rowCount, int colCount)
{
	for (int i = 0; i < rowCount * colCount; i++)
	{
		if (board[i] == ' ')
			return false;
	}

	return true;
}

bool isWinInRow(char board[], int rowCount, int colCount, char playerSign, int rowToCheck)
{
	for (int fieldNumber = 0; fieldNumber < colCount; fieldNumber++)
	{
		if (board[rowCount * rowToCheck + fieldNumber] != playerSign)
		{
			return false;
		}
	}

	return true;
}

bool isWinInRows(char board[], int rowCount, int colCount, char playerSign)
{
	for (int rowNumber = 0; rowNumber < rowCount; rowNumber++)
	{
		if (isWinInRow(board, rowCount, colCount, playerSign, rowNumber))
			return true;
	}
	return false;
}

bool isWinInCol(char board[], int rowCount, int colCount, char playerSign, int colToCheck)
{
	for (int fieldNumber = 0; fieldNumber < rowCount; fieldNumber++)
	{
		if (board[colCount * fieldNumber + colToCheck] != playerSign)
		{
			return false;
		}
	}

	return true;
}

bool isWinInCols(char board[], int rowCount, int colCount, char playerSign)
{
	for (int colNumber = 0; colNumber < colCount; colNumber++)
	{
		if (isWinInCol(board, rowCount, colCount, playerSign, colNumber))
			return true;
	}
	return false;
}

bool isWinInLeftDiagonal(char board[], int rowCount, int colCount, char playerSign)
{
	for (int fieldNumber = 0; fieldNumber < rowCount; fieldNumber++)
	{
		if (board[rowCount * fieldNumber + fieldNumber] != playerSign)
		{
			return false;
		}
	}

	return true;
}

bool isWinInRightDiagonal(char board[], int rowCount, int colCount, char playerSign)
{
	for (int fieldNumber = 0; fieldNumber < rowCount; fieldNumber++)
	{
		if (board[rowCount * fieldNumber + rowCount - fieldNumber - 1] != playerSign)
		{
			return false;
		}
	}

	return true;
}

bool isWinInDiagonals(char board[], int rowCount, int colCount, char playerSign)
{
	if (isWinInLeftDiagonal(board, rowCount, colCount, playerSign))
		return true;

	if (isWinInRightDiagonal(board, rowCount, colCount, playerSign))
		return true;

	return false;
}

bool isWin(char board[], int rowCount, int colCount, char playerSign)
{
	if (isWinInRows(board, rowCount, colCount, playerSign))
		return true;

	if (isWinInCols(board, rowCount, colCount, playerSign))
		return true;

	if (isWinInDiagonals(board, rowCount, colCount, playerSign))
		return true;

	return false;
}

bool isNotCorrectMove(char board[], int rowCount, int colCount, int fieldNumber)
{
	return fieldNumber < 0
		|| fieldNumber >= rowCount * colCount
		|| board[fieldNumber] != ' ';
}

int main()
{
	//inicjacja początku gry
	const int ROW_COUNT = 3;
	const int COL_COUNT = 3;
	char board[ROW_COUNT * COL_COUNT];

	const int PLAYERS_COUNT = 2;
	char playersSymbol[PLAYERS_COUNT] = { 'X', 'O' };
	int currentPlayer = 1;
	//playersSymbol[0] = 'X';
	//playersSymbol[1] = 'O';

	int fieldNumber;

	clearBoard(board, ROW_COUNT, COL_COUNT);
	while (true)
	{
		drawBoard(board, ROW_COUNT, COL_COUNT);

		fieldNumber = getFieldNumberOnBoard(playersSymbol[currentPlayer]);

		if (isNotCorrectMove(board, ROW_COUNT, COL_COUNT, fieldNumber))
			continue;

		board[fieldNumber] = playersSymbol[currentPlayer];

		if (isWin(board, ROW_COUNT, COL_COUNT, playersSymbol[currentPlayer]))
		{
			drawBoard(board, ROW_COUNT, COL_COUNT);
			std::cout << "Wygrana!!\n Wygrał " << playersSymbol[currentPlayer] << "\n";
			break;
		}

		if (isDraw(board, ROW_COUNT, COL_COUNT))
		{
			drawBoard(board, ROW_COUNT, COL_COUNT);
			std::cout << "Remis\n";
			break;
		}

		//zmienia gracza na następnego
		currentPlayer = (PLAYERS_COUNT + currentPlayer + 1) % PLAYERS_COUNT;
		//jesli chemy iść w drógą stronę 3-2-1-0-3-2...
		//currentPlayer = (PLAYERS_COUNT + currentPlayer - 1) % PLAYERS_COUNT;

	}

}