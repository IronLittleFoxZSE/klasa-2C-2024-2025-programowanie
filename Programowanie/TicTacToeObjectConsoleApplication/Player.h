#pragma once
#include <iostream>

class Player
{
private:

protected:
	char symbol;
public:
	Player(char s)
	{
		symbol = s;
	}

	virtual int getFieldNumber()
	{
		int fieldNumber = 0;
	
		return fieldNumber;
	}

	char GetSymbol()
	{
		return symbol;
	}
};

