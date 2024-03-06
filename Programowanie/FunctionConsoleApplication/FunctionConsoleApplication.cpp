#include <iostream>

/*
Funkcja 
    - zbiór instrukcji realizujący zadanie
    - podprogram

Budowa funkcji:
    * nagłówek
    * ciało funkcji - instrukcje ograniczone nawiasami klamrowymi

Nagłówek:
    typ_zwracanej_danej nazwa_funkcji(parametry)


*/

//Napisz funcję, która wyświetli na konsoli "Hello World!".
void task1()
{
    std::cout << "Hello World!\n";
}

//Napisz fukcję uniwersalną, która pozwala wyświetlić dowolny tekst
void task2(std::string textParam)
{
    std::cout << textParam <<"\n";
}

//Napisz funcję uniwersalną, która wyświetli imię oraz informację czy ktoś
//jest pełnoletni czy nie.
void task3(std::string name, int age)
{
    if (age >= 18)
        std::cout << name << " jest pełnoletni/pełnoletnia\n";
    else
        std::cout << name << " jest niepełnoletni/niepełnoletnia\n";
}

//Napisz program, który przetestuje zachowanie się przekazywanych danych przez parametr.
void task4(int number)
{
    std::cout << "Zmienna number w funkcji task4: " << number << "\n";
    number--;
    std::cout << "Zmienna number w funkcji task4: " << number << "\n";
}

//Napisz program, który wykorzysta przekazywanie parametru przez referencję
void task5(int &number)
{
    std::cout << "Zmienna number w funkcji task5: " << number << "\n";
    number--;
    std::cout << "Zmienna number w funkcji task5: " << number << "\n";
}

//Napisz funkcję, kóra pobierze od użytkownika liczbę
void task6_GetNumber(int &number)
{
    std::cout << "Podaj liczbe:\n";
    std::cin >> number;
}

int sumOfNumbers(int fn, int sn)
{
    int s;
    s = fn + sn;
    return s;
}

//Napisz funkcję która obliczy wartość silni i ją zwróci.
long long calculateFactorial(long long n)
{
    long long factorial = 1;
    for (int i = 2; i <= n; i++)
    {
        factorial = factorial * i;
    }
    return factorial;
}

long long calculateFactorialV2(long long n)
{
    if (n <= 1)
        return 1;
    else
        return n * calculateFactorialV2(n - 1);
}

void task7()
{
    int number;
    std::cout << "Podaj liczbę:\n";
    std::cin >> number;

    long long factorial = calculateFactorialV2(number);

    std::cout << "Silnia jest równa " << factorial << "\n";
}

int main()
{
    setlocale(LC_CTYPE, "polish");

    //task1();
    //task1();

    //task2("Witaj świecie!!");
    //task2("Ala ma kota");
    //std::string text = "Uczyć się programowania!!!";
    //task2(text);

    //task3("Jan", 35);
    //task3("Ala", 17);

    //int number = 5;
    //std::cout << "Zmienna number w funkcji main: " << number << "\n";
    //task4(number);
    //std::cout << "Zmienna number w funkcji main: " << number << "\n";

    //task4(9);
    //const int NUMBER = 9;
    //task4(NUMBER);

    //std::cout << "Zmienna number w funkcji main: " << number << "\n";
    //task5(number);
    //std::cout << "Zmienna number w funkcji main: " << number << "\n";

    //task5(9);  //BŁAD - przez parametr można przekazać tylko zmienną
    //task5(NUMBER); //BŁAD - przez parametr można przekazać tylko zmienną

    //int numberFromUser = 5;
    //task6_GetNumber(numberFromUser);
    //std::cout << "Uzytkownik podał liczbę " << numberFromUser << "\n";

    /*int numberFromUser = 16;

    double result = sqrt(numberFromUser);

    int firstNumber, secondNumber, sum;
    firstNumber = 9;
    secondNumber = 1;
    sum = sumOfNumbers(firstNumber, secondNumber);
    std::cout << sum << "\n";*/

    task7();
}
