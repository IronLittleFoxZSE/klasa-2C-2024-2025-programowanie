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

int main()
{
    setlocale(LC_CTYPE, "polish");

    task1();
    task1();

    task2("Witaj świecie!!");
    task2("Ala ma kota");
    std::string text = "Uczyć się programowania!!!";
    task2(text);

    task3("Jan", 35);
    task3("Ala", 17);
}
