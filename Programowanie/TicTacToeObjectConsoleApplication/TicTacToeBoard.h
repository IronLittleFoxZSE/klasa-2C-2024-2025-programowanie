#pragma once
#include <iostream>

class TicTacToeBoard
{
private:
	int rowCount;
	int colCount;
	char* board;

	void drawRow(int row)
	{
		for (int field = 0; field < colCount; field++)
		{
			std::cout << " " << board[rowCount * row + field] << " ";
			if (field < colCount - 1)
				std::cout << "|";
		}
		std::cout << "\n";
	}

	void drawHorizontalFrame()
	{
		for (int field = 0; field < colCount; field++)
		{
			std::cout << "---";
			if (field < colCount - 1)
				std::cout << "+";
		}
		std::cout << "\n";
	}

	bool isWinInRows(char playerSign)
	{
		for (int rowNumber = 0; rowNumber < rowCount; rowNumber++)
		{
			if (isWinInRow(playerSign, rowNumber))
				return true;
		}
		return false;
	}

	bool isWinInRow(char playerSign, int rowToCheck)
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

	bool isWinInCols(char playerSign)
	{
		for (int colNumber = 0; colNumber < colCount; colNumber++)
		{
			if (isWinInCol(playerSign, colNumber))
				return true;
		}
		return false;
	}

	bool isWinInCol(char playerSign, int colToCheck)
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

	bool isWinInDiagonals(char playerSign)
	{
		if (isWinInLeftDiagonal(playerSign))
			return true;

		if (isWinInRightDiagonal(playerSign))
			return true;

		return false;
	}

	bool isWinInLeftDiagonal(char playerSign)
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

	bool isWinInRightDiagonal(char playerSign)
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
protected:

public:
	TicTacToeBoard(int size)
	{
		colCount = size;
		rowCount = size;
		board = new char[rowCount * colCount];
	}

	void clearBoard()
	{
		for (int i = 0; i < rowCount * colCount; i++)
		{
			board[i] = ' ';
		}
	}

	void drawBoard()
	{
		system("cls");
		for (int row = 0; row < rowCount; row++)
		{
			drawRow(row);
			if (row < rowCount - 1)
				drawHorizontalFrame();
		}
	}

	bool isNotCorrectMove(int fieldNumber)
	{
		return fieldNumber < 0
			|| fieldNumber >= rowCount * colCount
			|| board[fieldNumber] != ' ';
	}

	void SetBoardField(int fieldNumber, char symbol)
	{
		board[fieldNumber] = symbol;
	}

	bool isWin(char playerSign)
	{
		if (isWinInRows(playerSign))
			return true;

		if (isWinInCols(playerSign))
			return true;

		if (isWinInDiagonals(playerSign))
			return true;

		return false;
	}

	bool isDraw()
	{
		for (int i = 0; i < rowCount * colCount; i++)
		{
			if (board[i] == ' ')
				return false;
		}

		return true;
	}
};



