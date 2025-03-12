#pragma once
#include "Player.h"

class EasyBoot : public Player
{
private:

public:
	EasyBoot(char s) : Player(s)
	{
		srand(time(NULL));
	}

	int getFieldNumber()
	{
		int fieldNumber;
		fieldNumber = rand();
		return fieldNumber;
	}
};

