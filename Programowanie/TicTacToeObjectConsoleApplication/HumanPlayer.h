#pragma once
#include <iostream>
#include "Player.h"

class HumanPlayer : public Player
{
private:


public:
	HumanPlayer(char s) : Player(s)
	{

	}

	int getFieldNumber() override
	{
		int fieldNumber;
		std::cout << "Gracz " << symbol << " wykonuje ruch.\n";
		std::cout << "Podaj numer pola:\n";
		std::cin >> fieldNumber;
		return fieldNumber;
	}


};

