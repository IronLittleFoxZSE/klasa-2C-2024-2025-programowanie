#include <iostream>

/*
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
Na podstawie tych danych oblicz wskaźnik BMI (Body Mass Index) i wyświetl odpowiedni komunikat informujący o stanie zdrowia.
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
	int firstNumber,secondNumber;
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

int main()
{
	task4();
}
