#include <iostream>
#include "Player.h"
#include "TicTacToeBoard.h"
#include "EasyBoot.h"
#include "HumanPlayer.h"

int main()
{
	int currentPlayer = 0;
	int playersCount = 2;
	Player** players = new Player * [playersCount];
	players[0] = new HumanPlayer('X');
	players[1] = new EasyBoot('0');

	TicTacToeBoard board(3);
	
	int fieldNumber;

	board.clearBoard();

	while (true)
	{
		board.drawBoard();

		fieldNumber = players[currentPlayer]->getFieldNumber();

		if (board.isNotCorrectMove(fieldNumber))
			continue;

		board.SetBoardField(fieldNumber, players[currentPlayer]->GetSymbol());
		
		if (board.isWin(players[currentPlayer]->GetSymbol()))
		{
			board.drawBoard();
			std::cout << "Wygrana!!\n Wygra³ " << players[currentPlayer]->GetSymbol() << "\n";
			break;
		}

		if (board.isDraw())
		{
			board.drawBoard();
			std::cout << "Remis\n";
			break;
		}

		currentPlayer = (playersCount + currentPlayer + 1) % playersCount;
	}

	//sam koniec
	//delete[] board;

	for (int i = 0; i < playersCount; i++)
		delete players[i];
	delete[] players;
}