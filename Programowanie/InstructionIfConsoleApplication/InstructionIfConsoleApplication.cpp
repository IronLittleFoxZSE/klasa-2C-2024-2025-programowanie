#include <iostream>
//#include <cmath>
//#include <math.h>

/*
DRY - don't repeat yourself - nie powtarzaj się
 
Operatory warunkowe:
> - większe
< - mniejsze
>= - większe bądź równe
<= - mniejsze bądź równe
== - równe
!= - różne

Operatory logiczne:
&& - AND
|| - OR
! - NOT
								  ALBO
 a	b	a && b	a || b	!a		a XOR b
 F	F	  F		   F	T			F
 F	T	  F		   T	T			T
 T	F	  F		   T	F			T
 T	T	  T		   T	F			F

 F - false
 T - true

*/
/*
*. Napisz program, który poprosi użytkownika o podanie dwóch liczb całkowitych i sprawdzi, czy są one równe. Wyświetl odpowiedni komunikat.
*. Napisz program, który poprosi użytkownika o podanie wieku i sprawdzi, czy osoba jest pełnoletnia. Wyświetl odpowiedni komunikat.
*. Napisz program, który poprosi użytkownika o podanie liczby całkowitej i obliczy jej wartość bezwzględną. Wyświetl wynik.
*. Napisz program, który poprosi użytkownika o podanie liczby od 1 do 7 i wyświetli odpowiadający mu dzień tygodnia.
*. Napisz program, który poprosi użytkownika o podanie dwóch liczb całkowitych i wyświetli większą z nich.
*. Napisz program, który poprosi użytkownika o podanie roku i sprawdzi, czy jest to rok przestępny. Wyświetl odpowiedni komunikat.
*. Napisz program, który poprosi użytkownika o podanie liczby całkowitej i sprawdzi, czy jest ona podzielna zarówno przez 3, jak i przez 5. Wyświetl odpowiedni komunikat.

*. Napisz program, który poprosi użytkownika o podanie masy ciała (w kilogramach) i wzrostu (w metrach).
Na  podstawie tych danych oblicz wskaźnik BMI (Body Mass Index) i wyświetl odpowiedni komunikat informujący o stanie zdrowia.
poniżej 16 - wygłodzenie
16 - 16.99 - wychudzenie
17 - 18.49 - niedowagę
18.5 - 24.99 - wagę prawidłową
25.0 - 29.9 - nadwagę
30.0 - 34.99 - I stopień otyłości
35.0 - 39.99 - II stopień otyłości
powyżej 40.0 - otyłość skrajną

Wzór:

BMI = masa/wysokość^2

*. Napisz program, który poprosi użytkownika o podanie długości trzech odcinków i sprawdzi, czy można zbudować z nich trójkąt. Wyświetl odpowiedni komunikat.
*. Napisz program, który poprosi użytkownika o podanie liczby dodatniej i obliczy jej pierwiastek kwadratowy, jeśli jest to możliwe. Wyświetl wynik lub odpowiedni komunikat, jeśli liczba jest ujemna.
*. Program sprawdzający czy podana data jest poprawna (np. sprawdzając, czy dzień jest z zakresu od 1 do 31, miesiąc od 1 do 12 itd.)
*.

*/

//Napisz program, który wyświetli informacje czy liczba jest dodatnia czy nie.
void task1()
{
	int number;
	std::cout << "Podaj liczbe:\n";
	std::cin >> number;

	if (number > 0)
		std::cout << "Liczba jest dodatnia\n";

	if (number < 0);
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

	if (rest == 0)
		std::cout << "Liczba jest parzysta\n";
	else
		std::cout << "Liczba jest nieparzysta\n";
}

//Napisz program, który wyświetli informacje czy liczba jest z zakresu <1 ; 10).
void task3()
{
	int number;
	std::cout << "Podaj liczbe:\n";
	std::cin >> number;

	//wersja 1
	if (number >= 1) //number > 0
	{
		if (number < 10) // number <= 9
			std::cout << "Liczba jest w przedziale\n";
		else
			std::cout << "Liczba z poza zakresu\n";
	}
	else
		std::cout << "Liczba z poza zakresu\n";

	//wersja 2
	if (number >= 1) //number > 0
		if (number < 10) // number <= 9
			std::cout << "Liczba jest w przedziale\n";
		else
			std::cout << "Liczba z poza zakresu\n";
	else
		std::cout << "Liczba z poza zakresu\n";

	//wersja 3
	if (number >= 1 && number < 10)
		std::cout << "Liczba jest w przedziale\n";
	else
		std::cout << "Liczba z poza zakresu\n";

	//wersja 4
	if (number < 1 || number >= 10)
		std::cout << "Liczba z poza zakresu\n";
	else
		std::cout << "Liczba jest w przedziale\n";

	//wersja 5
	if (!(number >= 1 && number < 10))
		std::cout << "Liczba z poza zakresu\n";
	else
		std::cout << "Liczba jest w przedziale\n";
}

//Napisz program, który wykona dzielenie dwóch liczb
void task4()
{
	int firstNumber, secondNumber;
	std::cout << "Podaj liczbe:\n";
	std::cin >> firstNumber;
	std::cout << "Podaj liczbe:\n";
	std::cin >> secondNumber;

	if (secondNumber != 0)
	{
		int quoitent = firstNumber / secondNumber;
		std::cout << "wynik dzielenia " << quoitent << "\n";
	}
	else
		std::cout << "Dzzielenie przez zero!!!\n";
}

//Program sprawdzający czy podana data jest poprawna (np. sprawdzając, czy dzień jest z zakresu od 1 do 31, miesiąc od 1 do 12 itd.)
void task5()
{
	int day, month, year;
	std::cout << "Podaj dzień\n";
	std::cin >> day;
	std::cout << "Podaj miesiąc\n";
	std::cin >> month;
	std::cout << "Podaj rok\n";
	std::cin >> year;

	if (day >= 1 && day <= 31
		&& month >= 1 && month <= 12
		&& year != 0

		&& ((month == 4 || month == 6 || month == 9 || month == 11) && day != 31)

		&& month == 2 && (day <= 28
			|| day == 29 && (year % 4 == 0 && year % 100 != 0 || year % 400 == 0))
		)
	{
		std::cout << "Data " << day << "." << month << "." << year << " jest poprawna\n";
	}
	else
	{
		std::cout << "Data nie jest poprawna";
	}
}

//Napisz program, który poprosi użytkownika o podanie liczby od 1 do 7 i wyświetli odpowiadający mu dzień tygodnia.
void task6()
{
	int dayOfWeek;
	std::cout << "Podaj numer dnia tygodnia\n";
	std::cin >> dayOfWeek;

	if (dayOfWeek == 1)
		std::cout << "Podniedziałek\n";
	else if (dayOfWeek == 2)
		std::cout << "Wtorek\n";
	else if (dayOfWeek == 3)
		std::cout << "Środa\n";
	else if (dayOfWeek == 4)
		std::cout << "Czwartek\n";
	else if (dayOfWeek == 5)
		std::cout << "Piątek\n";
	else if (dayOfWeek == 6)
		std::cout << "Sobota\n";
	else if (dayOfWeek == 7 || dayOfWeek == 0)
		std::cout << "Niedziela\n";
	else
		std::cout << "Dzień niepoprawny\n";

	switch (dayOfWeek)
	{
	case 1:
		std::cout << "Podniedziałek\n";
		break;
	case 2:
		std::cout << "Wtorek\n";
		break;
	case 3:
		std::cout << "Środa\n";
		break;
	case 4:
		std::cout << "Czwartek\n";
		break;
	case 5:
		std::cout << "Piątek\n";
		break;
	case 6:
		std::cout << "Sobota\n";
		break;
	case 0:
	case 7:
		std::cout << "Niedziela\n";
		break;
	default:
		std::cout << "Dzień niepoprawny\n";
	}
}

//Napisz program, który ma pobrać od użytkownika liczbę dodatnią. 
//Zabezpiecz program przed pobieraniem liczb ujemnych.
void task7()
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

int main()
{
	task7();

	//float number = 9;
	//double root = pow(number, 19) + sqrt(number) + 8;

}
