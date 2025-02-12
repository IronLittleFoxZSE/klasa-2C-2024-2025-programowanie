﻿// PointersConsoleApplication.cpp 

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

    int *ptr;
    ptr = &firstNumber;

    std::cout << "Adres pierwszej zmiennej \t" << &firstNumber << "\n";
    std::cout << "Adres zmiennej \t\t\t" << ptr << "\n";
    std::cout << "Zawartość pierszej zmiennej \t" << firstNumber << "\n";
    std::cout << "Zawartość pierszej zmiennej \t" << *ptr << "\n";

    ptr = &secondNumber;
    std::cout << "Zawartość drugiej zmiennej \t" << *ptr << "\n";

    ptr = new int;

    std::cout << "Adres nowego obszaru \t\t\t" << ptr << "\n";
    *ptr = 5;
    //std::cin >> *ptr;
    std::cout << "Zawartość w nowym obszarze \t" << *ptr << "\n";

    delete ptr;
    ptr = NULL;

    /*
    while (true)
        new long long;
    */

    int count;
    std::cout << "Podaj wielkość tablicy\n";
    std::cin >> count;
    //int tab[count];
    int* tab;
    tab = new int[count];

    *tab = 45;
    tab[0] = 45;
    *(tab + 1) = 78;
    tab[1] = 78;
}


int main()
{
    setlocale(LC_CTYPE, "polish");
    //long long t[10000000];

    task2();
}