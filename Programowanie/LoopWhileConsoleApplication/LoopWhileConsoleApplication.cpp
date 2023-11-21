#include <iostream>

//Napisz program, który policzy sumę cyfr podanej przez użytkownika liczby.
void task1()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	int sum = 0;
	int rest;

	/*
	if (number != 0)
	{
		rest = number % 10;
		sum = sum + rest;
		number = number / 10;
		if (number != 0)
		{
			rest = number % 10;
			sum = sum + rest;
			number = number / 10;
			if (number != 0)
			{
				rest = number % 10;
				sum = sum + rest;
				number = number / 10;
				//if (number != 0) ...
			}
		}
	}
	*/

	while (number != 0)
	{
		rest = number % 10;
		sum = sum + rest;
		number = number / 10;
	}

	std::cout << "Suma " << sum << "\n";
	//4125
}

//Napisz program, który policzy NWD dwóch liczb.
void task2()
{
	int firstNumber, secondNumber;
	std::cout << "Podaj pierwszą liczbę\n";
	std::cin >> firstNumber;
	std::cout << "Podaj drugą liczbę\n";
	std::cin >> secondNumber;

	int nwd;

	if (firstNumber < secondNumber)
		nwd = firstNumber;
	else
		nwd = secondNumber;

	nwd = (firstNumber < secondNumber) ? firstNumber : secondNumber;

	/*
	if (secondNumber % nwd != 0
		|| firstNumber % nwd != 0)
	{
		nwd--;
		if (secondNumber % nwd != 0
			|| firstNumber % nwd != 0)
		{
			nwd--;
			if (secondNumber % nwd != 0
				|| firstNumber % nwd != 0)
			{
				nwd--;
				//if...
			}
		}
	}
	*/

	while (secondNumber % nwd != 0
		|| firstNumber % nwd != 0)
	{
		--nwd;
	}

	std::cout << "NWD = " << nwd << "\n";
}

int main()
{
	task2();
}
