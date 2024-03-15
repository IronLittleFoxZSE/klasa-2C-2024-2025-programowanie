// TasksConsoleApplication.cpp

#include <iostream>
#include <string>

/*
Zadanie: Tworzenie prostego kalkulatora

Napisz program, który będzie działał jako prosty kalkulator
i będzie umożliwiał użytkownikowi wykonywanie
podstawowych operacji arytmetycznych na dwóch liczbach.

Instrukcje:

Poproś użytkownika o podanie dwóch liczb oraz wybór operacji (dodawanie, odejmowanie, mnożenie lub dzielenie).
W zależności od wyboru użytkownika, wykonaj odpowiednią operację arytmetyczną.
Wyświetl wynik operacji.
Przykładowe działanie programu:

Prosty Kalkulator
-----------------
1. Dodawanie
2. Odejmowanie
3. Mnożenie
4. Dzielenie
0. Koniec programu

Wybierz operację: 3
Podaj pierwszą liczbę: 5
Podaj drugą liczbę: 3

Wynik mnożenia: 15
*/

/*
ZADANIE
Konwersja temperatury

Napisz program, który będzie konwertować temperaturę pomiędzy skalami: Celsiusza, Fahrenheita i Kelvina.

Instrukcje:

Poproś użytkownika o wybór jednostki, z której chce dokonać konwersji (C - Celsiusz, F - Fahrenheit, K - Kelvin).
Poproś użytkownika o podanie temperatury w wybranej jednostce.
Przelicz temperaturę na pozostałe jednostki (z wykorzystaniem odpowiednich wzorów konwersji).
Wyświetl przeliczone temperatury.
Przykładowe działanie programu:

Konwerter Temperatur
---------------------
Wybierz jednostkę temperatury:
1. Celsiusz (C)
2. Fahrenheit (F)
3. Kelvin (K)
Wybór: C

Podaj temperaturę w stopniach Celsiusza: 25

Przeliczona temperatura:
Fahrenheit: 77.0 °F
Kelvin: 298.15 K
*/

/*
ZADANIE
Symulator rzutu kostką

Napisz program, który będzie symulował rzut kostką. Program powinien umożliwiać użytkownikowi wybór rodzaju kostki (np. 6-ścienna, 10-ścienna, 20-ścienna) oraz ilość rzutów. Po wykonaniu rzutów, program powinien wyświetlić wyniki oraz sumę otrzymanych wartości.

Instrukcje:

Poproś użytkownika o wybór rodzaju kostki (np. 6-ścienna, 10-ścienna, 20-ścienna).
Poproś użytkownika o podanie ilości rzutów.
Wykonaj podaną liczbę rzutów wybranej kostką, zapisując wyniki.
Wyświetl otrzymane wyniki oraz sumę otrzymanych wartości.
Przykładowe działanie programu:

Symulator rzutu kostką
-----------------------

Wybierz rodzaj kostki (6/10/20): 10
Ile rzutów chcesz wykonać?: 5

Wyniki rzutów kostką 10-ścienną:
1. Rzut 1: 7
2. Rzut 2: 3
3. Rzut 3: 10
4. Rzut 4: 5
5. Rzut 5: 8

Suma wyników: 33

*/

/*
ZADANIE
Konwerter jednostek

Napisz program konwertujący jednostki miar. Program powinien umożliwiać konwersję między różnymi jednostkami (np. metry na centymetry, kilogramy na funty) oraz obsługiwać różne typy jednostek.

Instrukcje:

Zdefiniuj zestaw jednostek, które chcesz obsługiwać (np. długość: metry, centymetry, cale; masa: kilogramy, funty).
Poproś użytkownika o wybór jednostki wejściowej i jednostki wyjściowej oraz podanie wartości do konwersji.
Przekonwertuj wartość z jednostki wejściowej na jednostkę wyjściową na podstawie ustalonego współczynnika konwersji.
Wyświetl wynik konwersji.
Przykładowe działanie programu:

Konwerter jednostek
-------------------

Wybierz jednostkę wejściową:
1. Metry
2. Centymetry
3. Cale
Wybór: 1

Wybierz jednostkę wyjściową:
1. Metry
2. Centymetry
3. Cale
Wybór: 2

Podaj wartość do konwersji: 5

Wynik konwersji: 500 centymetrów

*/

void showMenu()
{
	system("cls");
	std::cout << "Prosty Kalkulator\n";
	std::cout << "-----------------\n";
	std::cout << "1. Dodawanie\n";
	std::cout << "2. Odejmowanie\n";
	std::cout << "3. Mnożenie\n";
	std::cout << "4. Dzielenie\n";
	std::cout << "0. Koniec programu\n";
}

int convertStringToInt(std::string value)
{
	int result = 0;

	for (int i = 0; i < value.length(); i++)
	{
		if (value[i] >= '0' && value[i] <= '9')
			result = result * 10 + (value[i] - '0');
		else
			return -1;
	}

	return result;
}

int getNumber(std::string message)
{
	std::string strChoise;

	std::cout << message;

	std::getline(std::cin, strChoise);

	return convertStringToInt(strChoise);
}

void calculate(int choice, int firstNumber, int secondNumber)
{
	switch (choice)
	{
	case 1:
		std::cout << "Wynik operacji: " << firstNumber + secondNumber << "\n";
		break;
	case 2:
		std::cout << "Wynik operacji: " << firstNumber - secondNumber << "\n";
		break;
	case 3:
		std::cout << "Wynik operacji: " << firstNumber * secondNumber << "\n";
		break;
	case 4:
		if (secondNumber != 0)
			std::cout << "Wynik operacji: " << firstNumber / secondNumber << "\n";
		else
			std::cout << "Nie można dzielić przez zero\n";
		break;
	default:
		break;
	}
}

void task1()
{
	while (true)
	{
		showMenu();

		int choice = getNumber("Wybierz operację:\n");

		if (choice == 0)
			break;

		int firstNumber = getNumber("Podaj pierwszą liczbę:\n");
		int secondNumber = getNumber("Podaj drugą liczbę:\n");

		calculate(choice, firstNumber, secondNumber);
		system("pause");
	}
}

int main()
{
	task1();
}
