#include <iostream>

//Napisz program, który wczyta np. 5 liczb 
//a następnie wyświetli je w odwrotnej kolejności.
void task1()
{
	const unsigned short ARRAY_SIZE = 5;
	//std::cin >> ARRAY_SIZE; // jest błąd!!!!!
	int numbers[ARRAY_SIZE];
	//numbers[2] = 70;

	/*
	std::cout << "Podaj daną\n";
	std::cin >> numbers[0];
	std::cout << "Podaj daną\n";
	std::cin >> numbers[1];
	std::cout << "Podaj daną\n";
	std::cin >> numbers[2];
	std::cout << "Podaj daną\n";
	std::cin >> numbers[3];
	std::cout << "Podaj daną\n";
	std::cin >> numbers[4];
	*/

	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		std::cout << "Podaj daną\n";
		std::cin >> numbers[i];
	}

	std::cout << "Podane dane w odwrotnej kolejności:\n";
	for (int i = ARRAY_SIZE - 1; i >= 0; i--)
	{
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n";
}

//Napisz program obliczający średnią arytmetyczną elementów w tablicy liczb całkowitych.
void task2()
{
	// <LOWER_RANGE; UPPER_RANGE> przy założeniu, że LOWER_RANGE <= UPPER_RANGE
	const unsigned short LOWER_RANGE = 5;
	const unsigned short UPPER_RANGE = 7;

	const unsigned short ARRAY_SIZE = 3;
	int numbers[ARRAY_SIZE];

	srand(time(0));

	std::cout << "wylosowane liczby:\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n";
	//----------------------------------------------------------------------------

	int sum = 0;
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		sum = sum + numbers[i];
	}

	double avg = sum * 1.0 / ARRAY_SIZE;
	std::cout << "Średnia wynosi: " << avg << "\n";
}

//Napisz program, który uzupełni tablicę liczbami losowymi a następnie znajdzie minimum oraz maksimum.
void task3()
{
	const short LOWER_RANGE = 0;
	const short UPPER_RANGE = 70;

	const unsigned short ARRAY_SIZE = 100;
	int numbers[ARRAY_SIZE];

	srand(time(0));

	std::cout << "wylosowane liczby:\n";
	for (int i = 0; i < ARRAY_SIZE; i++)
	{
		numbers[i] = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n";
	//----------------------------------------------------------------------------

	int max = numbers[0];
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (numbers[i] > max)
			max = numbers[i];
	}

	std::cout << "Max to: " << max << "\n";

	int min = numbers[0];
	for (int i = 1; i < ARRAY_SIZE; i++)
	{
		if (numbers[i] < min)
			min = numbers[i];
	}

	std::cout << "Min to: " << min << "\n";
}

//Napisz program, który wyznaczy wszystkie liczby pierwsze od 2 do zadeklarowanego zakresu. Metoda sito Eratostenesa.
void task4()
{
	const long long UPPER_RANGE = 70;

	//wersja 1

	for (long long numberToCheck = 2; numberToCheck <= UPPER_RANGE; numberToCheck++)
	{
		bool isPrime = true;
		for (long long i = 2; i <= numberToCheck / 2; i++)
		{
			if (numberToCheck % i == 0)
			{
				isPrime = false;
				break;
			}
		}

		if (isPrime /*== true*/)
			std::cout << numberToCheck << ", ";
	}
	std::cout << "Gotowe\n";

}

int main()
{
	setlocale(LC_CTYPE, "polish");
	task4();
}