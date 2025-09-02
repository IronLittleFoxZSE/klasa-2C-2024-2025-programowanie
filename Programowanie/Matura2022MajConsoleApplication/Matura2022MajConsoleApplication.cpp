// Matura2022MajConsoleApplication.cpp 

#include <iostream>
#include <fstream>
#include <vector>

int main()
{
	std::ifstream file("przyklad.txt");

	/*
	int numbers[200];

	for (int i = 0; i < 200; i++)
	{
		file >> numbers[i];
	}


	std::cout << "Odczytane liczby:\n";
	for (int i = 0; i < 200; i++)
	{
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n";
	*/

	std::vector<int> numbers;

	int num;
	while (file >> num)
		numbers.push_back(num);

	/*
	for (int i = 0; i < numbers.size(); i++)
	{
		std::cout << numbers[i] << ", ";
	}
	std::cout << "\n";
	*/

	std::cout << "Odczytane liczby:\n";
	for (int num : numbers)
	{
		std::cout << num << ", ";
	}
	std::cout << "\n";

	std::cout << "Zadanie 4.1:\n";

	int count = 0;
	for (int num : numbers)
	{
		int firstDigit;
		int lastDigit = num % 10;

		int tmpNum = num;
		do
		{
			firstDigit = tmpNum % 10;
			tmpNum = tmpNum / 10;
		} while (tmpNum != 0);

		if (firstDigit == lastDigit)
		{
			count++;
		}
	}
	std::cout << count << "\n";
}
