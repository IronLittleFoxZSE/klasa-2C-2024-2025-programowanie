#include <iostream>

/*
Operatory warunkowe:
> - większe
< - mniejsze
>= - większe bądź równe
<= - mniejsze bądź równe
== - równe
!= - różne
*/

//Napisz program, który wyświetli informacje czy liczba jest dodatnia czy nie.
void task1()
{
	int number;
	std::cout << "Podaj liczbe:\n";
	std::cin >> number;

	if (number > 0)
		std::cout << "Liczba jest dodatnia\n";

	if (number < 0)
		std::cout << "Liczba jest ujemna";

	if (number == 0)
		std::cout << "Liczba jest równa zero";

	std::cout << "Kolejna instrukcja\n";
}

//Napisz program, który wyświetli informacje czy liczba jest parzysta czy nieparzysta.
void task2()
{
	int number;
	std::cout << "Podaj liczbe:\n";
	std::cin >> number;

	int rest = number % 2;

	if (rest == 0)
		std::cout << "Liczba jest parzysta\n";

	if (rest != 0) // rest == 1
		std::cout << "Liczba jest nieparzysta\n";
}

int main()
{
	task2();
}
