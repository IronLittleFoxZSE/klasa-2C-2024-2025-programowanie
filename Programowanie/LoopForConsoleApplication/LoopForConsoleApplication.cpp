#include <iostream>

/*
*
*
*
*
*
*
* Program wyświetlający na ekranie wszystkie liczby podzielne przez 3 z zakresu od 1 do 100
* Program obliczający sumę kwadratów liczb od 1 do 10
*

* Program, kóry wyświetli poniższe cztery zwory:
	****       54321        121212        122333
	***        65432        212121        223334444
	**         76543        121212        333444455555
	*          87654        212121        444455555666666

* Oblicz sumę szeregu 1/1^2 + 1/2^2 + 1/3^2 + ... +1/n^2. Jeżeli się nie pomylisz, to dla odpowiednio dużej wartości n po przemnożeniu jej przez 6 i spierwiastkowaniu powinieneś otrzymać wartość liczby π (suma szeregu jest równa π2/6). Zwróć uwagę, że pierwsza wartość indeksu to 1, a nie 0. Dokładność obliczeń można sprawdzić porównując z wartością odczytaną z własności Math.PI.

* Rozkład liczby na czynniki pierwsze
*/

//Napisz program, który wyświetli "Hello world" tyle razy ile chce użytkownik
void task1()
{
	int howManyTimes;
	std::cout << "Podaj ile razy wyświetlić\n";
	std::cin >> howManyTimes;

	for (int i = 0; i != howManyTimes; i++)
	{
		std::cout << "Hello world\n";
	}
}

//Napisz program, który wyświetli liczby parzyste do podanej przez użytkownika liczby
void task2()
{
	int upperRange;
	std::cout << "Podaj górną granicę do wyświetlenia\n";
	std::cin >> upperRange;

	for (int i = 0; i <= upperRange; i += 2)
	{
		std::cout << i << "\n";
	}
}

//Program obliczający sumę liczb od 1 do 100
void task3()
{
	int sum = 0;
	for (int i = 1; i <= 100; i++)
	{
		//std::cout << i << "\n";
		sum = sum + i;
	}
	std::cout << "Suma: " << sum << "\n";
}

//Program sprawdzający czy podana liczba jest liczbą doskonałą 
//(czyli taką, której suma dzielników (z wyłączeniem samej siebie) 
//jest równa danej liczbie, np. 6 jest liczbą doskonałą, ponieważ 1 + 2 + 3 = 6).
void task4()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	//wersja 1  złożoność O(number-1)
	int sum = 1;
	for (int i = 2; i < number; i++)
	{
		if (number % i == 0)
		{
			//std::cout << i << "\n";
			sum += i;
		}
	}

	std::cout << "Suma dzielników " << sum << "\n";

	if (number == sum)
		std::cout << "Liczba jest doskonała\n";
	else
		std::cout << "Liczba nie jest doskonała\n";

	//wersja 2 O(number/2)
	sum = 1;
	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			//std::cout << i << "\n";
			sum += i;
		}
	}

	std::cout << "Suma dzielników " << sum << "\n";

	if (number == sum)
		std::cout << "Liczba jest doskonała\n";
	else
		std::cout << "Liczba nie jest doskonała\n";

	//wersja 3 O(number/2)
	sum = 1;
	for (int i = 2; i <= number / 2; i++)
	{
		if (number % i == 0)
		{
			//std::cout << i << "\n";
			sum += i + number / i;
		}
	}

	std::cout << "Suma dzielników " << sum << "\n";

	if (number == sum)
		std::cout << "Liczba jest doskonała\n";
	else
		std::cout << "Liczba nie jest doskonała\n";
}

//Program wyświetlający na ekranie kwadraty liczb od 1 do 10 (np. 1, 4, 9, 16 itd.)
void task5()
{
	for (int i = 1; i < 11; i++)
	{
		std::cout << i << "*" << i << "=" << i * i << "\n";
	}
}

//Program obliczający n!.
void task6()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	long long factorial = 1;
	for (int i = 2; i <= number; i++)
	{
		factorial = factorial * i;
	}

	std::cout << number << "!=" << factorial << "\n";
}

//Program wyświetlający na ekranie silnie z liczb od 1 do 10 (np. 1!, 2!, 3!, 4! itd.)
void task7()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	long long factorial = 1;
	for (int i = 1; i <= number; i++)
	{
		factorial = factorial * i;
		std::cout << i << "!=" << factorial << "\n";
	}
}

//Program wyświetlający na ekranie tabliczkę mnożenia od 1 do 9 (np. 1x1=1, 1x2=2, 1x3=3 itd.).
void task8()
{
	//0x0	0x1		0x2		0x3	
	//1x0	1x1		1x2		1x3	
	//2x0	2x1		2x2		2x3	

	for (int x = 0; x < 10; x++)
	{
		for (int y = 0; y < 10; y++)
		{
			std::cout << x << "x" << y << "=" << x * y << "\t";
		}
		std::cout << "\n";
	}
}

//Program wyświetlający na ekranie ciąg Fibonacciego do 20 elementu (ciąg Fibonacciego to ciąg gdzie każdy element jest sumą dwóch poprzednich, np. 0, 1, 1, 2, 3, 5, 8, 13 itd.)
void task9()
{
	int f2 = 0;
	int f1 = 1;
	std::cout << f2 << ", " << f1 << ", ";
	for (int i = 2; i < 20; i++)
	{
		int f = f1 + f2;
		std::cout << f << ", ";
		f2 = f1;
		f1 = f;
	}
}

//* Program, kóry wyświetli poniższe cztery zwory:
// 
//****		54321        121212        122333
//***		65432        212121        223334444
//**		76543        121212        333444455555
//*			87654        212121        444455555666666
void task10()
{
	const int NUMBER_OF_LINES = 4;

	//wzór 1
	for (int lineNumber = 0; lineNumber < NUMBER_OF_LINES; lineNumber++)
	{
		for (int i = 0; i < NUMBER_OF_LINES - lineNumber; i++)
			std::cout << "*";

		std::cout << "\n";
	}

	//wzór 2
	for (int lineNumber = 0; lineNumber < NUMBER_OF_LINES; lineNumber++)
	{
		for (int i = 5; i > 0; i--)
			std::cout << i + lineNumber;

		std::cout << "\n";
	}
}

int main()
{
	task10();
}