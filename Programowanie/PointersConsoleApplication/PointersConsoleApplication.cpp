// PointersConsoleApplication.cpp 

#include <iostream>

void task1()
{
    int firstNumber = 48;
    int secondNumber = 697;
    int tab[2] = { 15, 87 };

    std::cout << "Wartość pierwszej zmiennej " << firstNumber << "\n";
    std::cout << "Adres pierwszej zmiennej " << &firstNumber << "\n";
    std::cout << "Wartość drugiej zmiennej " << secondNumber << "\n";
    std::cout << "Adres drugiej zmiennej " << &secondNumber << "\n";
    *(&secondNumber) = 741;
    std::cout << "Wartość drugiej zmiennej " << secondNumber << "\n";

    std::cout << "Zawartość zerowej komórki " << tab[0] << "\n";
    std::cout << "Zawartość pierwszej komórki " << tab[1] << "\n";
    std::cout << "Adres zerowej komórki " << &tab[0] << "\n";
    std::cout << "Adres pierwszej komórki " << &tab[1] << "\n";
    std::cout << "Adres tablicy " << tab << "\n";
    std::cout << "Zawartość zerowej komórki " << *(tab + 0)<< "\n";
    std::cout << "Zawartość pierwszej komórki " << *(tab + 1) << "\n";
}

void task2()
{
    int firstNumber = 48;
    int secondNumber = 697;

    int *ptr = &firstNumber;

    std::cout << "Adres pierwszej zmiennej \t" << &firstNumber << "\n";
    std::cout << "Adres zmiennej \t\t\t" << ptr << "\n";
    std::cout << "Zawartość pierszej zmiennej \t" << firstNumber << "\n";
    std::cout << "Zawartość pierszej zmiennej \t" << *ptr << "\n";

    ptr = &secondNumber;
    std::cout << "Zawartość drugiej zmiennej \t" << *ptr << "\n";


}


int main()
{
    setlocale(LC_CTYPE, "polish");
    task2();
}