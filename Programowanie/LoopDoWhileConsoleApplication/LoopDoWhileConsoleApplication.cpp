#include <iostream>

//Napisz program, który ma pobrać od użytkownika liczbę dodatnią. 
//Zabezpiecz program przed pobieraniem liczb ujemnych.
void task1()
{
	int numberFromUser;

	std::cout << "Podaj liczbę doodatnią:\n";
	std::cin >> numberFromUser;
	if (numberFromUser < 0)
	{
		std::cout << "Podaj liczbę doodatnią:\n";
		std::cin >> numberFromUser;
		if (numberFromUser < 0)
		{
			std::cout << "Podaj liczbę doodatnią:\n";
			std::cin >> numberFromUser;
			if (numberFromUser < 0)
			{
				std::cout << "Podaj liczbę doodatnią:\n";
				std::cin >> numberFromUser;
				if (numberFromUser < 0)
				{
					std::cout << "Podaj liczbę doodatnią:\n";
					std::cin >> numberFromUser;
					//wklejamy całego If'a
				}
			}
		}
	}

	std::cout << "Liczba dodatnia pobrana od uzytkownika " << numberFromUser << "\n";
}

//Napisz program, który ma pobrać od użytkownika liczbę dodatnią. 
//Zabezpiecz program przed pobieraniem liczb ujemnych.
void task2()
{
	int numberFromUser;

	do
	{
		std::cout << "Podaj liczbę dodatnią:\n";
		std::cin >> numberFromUser;
	} while (numberFromUser < 0);

	std::cout << "Liczba dodatnia pobrana od uzytkownika " << numberFromUser << "\n";
}

//Napisz program, który wylosuje liczbę a następnie uzytkownik będzie musiał ją zgadnąć.
void task3()
{
	const int LOWER_RANGE = 1;
	const int UPPER_RANGE = 100;
	srand(time(NULL));
	int randomNumber = rand() % (UPPER_RANGE - LOWER_RANGE + 1) + LOWER_RANGE;
	//std::cout << randomNumber << "\n";

	int numberFromUser;

	/*
	std::cout << "Podaj liczbę:\n";
	std::cin >> numberFromUser;
	if (numberFromUser != randomNumber)
	{
		std::cout << "Podaj liczbę:\n";
		std::cin >> numberFromUser;
		if (numberFromUser != randomNumber)
		{
			std::cout << "Podaj liczbę:\n";
			std::cin >> numberFromUser;
			//...
		}
	}*/

	do
	{
		std::cout << "Podaj liczbę:\n";
		std::cin >> numberFromUser;
		if (numberFromUser > randomNumber)
			std::cout << "Za duża liczba\n";
		if (numberFromUser < randomNumber)
			std::cout << "Za mała liczba\n";
	} while (numberFromUser != randomNumber);

	std::cout << "Gratulacje!!!!\n";

}

//Napisz program wyświetlający liczby całkowite z przedziału <1,x>.
//Gdzie x pdaje użytkownika.
void task4()
{
	//std::cout << "1, 2, 3, 4, 5, 6 \n";
	unsigned long long upperRange;
	std::cout << "Podaj górny zakres większy bądź równy 1\n";
	std::cin >> upperRange;

	/*
	std::cout << "1, ";
	if (upperRange > 1)
	{
		std::cout << "2, ";
		if (upperRange > 2)
		{
			std::cout << "3, ";
			if (upperRange > 3)
			{
				std::cout << "4, ";
				//.....
			}
		}
	}
	*/

	unsigned long long currentNumber = 0;
	do
	{
		//currentNumber = currentNumber + 1;
		//currentNumber += 1;
		//currentNumber++;
		++currentNumber;
		std::cout << currentNumber << ", ";
	} while (upperRange > currentNumber);
}

//Napisz program, który policzy sumę cyfr podanej przez użytkownika liczby.
void task5()
{
	int number;
	std::cout << "Podaj liczbę\n";
	std::cin >> number;

	int sum = 0;
	int rest;

	/*
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

	do
	{
		rest = number % 10;
		sum = sum + rest;
		number = number / 10;
	} while (number != 0);

	std::cout << "Suma " << sum << "\n";
	//4125
}

//* Poproś użytkownika o podawanie liczb, aż wprowadzi zero. 
//Oblicz sumę oraz średnią arytmetyczną wprowadzonych liczb.
void task6()
{
	int number;
	int sum = 0;
	int numberOfNumbers = 0;

	/*
	std::cout << "Podaj liczbę:\n";
	std::cin >> number;
	sum = sum + number;
	numberOfNumbers++;
	if (number != 0)
	{
		std::cout << "Podaj liczbę:\n";
		std::cin >> number;
		sum = sum + number;
		numberOfNumbers++;
		if (number != 0)
		{
			std::cout << "Podaj liczbę:\n";
			std::cin >> number;
			sum = sum + number;
			numberOfNumbers++;
			//if ...
		}
	}
	*/

	do
	{
		std::cout << "Podaj liczbę:\n";
		std::cin >> number;
		sum = sum + number;
		//if (number != 0)
		numberOfNumbers++;
	} while (number != 0);

	//numberOfNumbers--;
	std::cout << "Suma liczb wynosi " << sum << "\n";
	double avg = sum * 1.0 / numberOfNumbers;
	std::cout << "Średnia " << avg << "\n";
}

//Napisz program, który poprosi użytkownika o wprowadzenie dowolnej liczby całkowitej. 
//Następnie program powinien obliczyć i wyświetlić liczbę cyfr.
void task7()
{
	int number;

	std::cout << "Podaj liczbę\n";
	std::cin >> number;


}


int main()
{
	task6();

}
