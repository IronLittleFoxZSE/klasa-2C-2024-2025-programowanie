#include <iostream>

//Napisz program który pobierze znak od użytkownika i wyświeli go.
void task1()
{
    char characterFromUser;
    std::cout << "Podaj znak\n";
    std::cin >> characterFromUser;

    std::cout << "Podałeś znak:" << characterFromUser << "\n";
}

//Napisz program, który wczyta znak z klawiatury 
//i sprawdzi czy jest to mała litera alfabetu.
void task2()
{
    unsigned char characterFromUser;
    std::cout << "Podaj znak\n";
    std::cin >> characterFromUser;

    //if (characterFromUser >= 97 && characterFromUser <= 122)
    if (characterFromUser >= 'a' && characterFromUser <= 'z')
        std::cout << "Jest to mała litera alfabetu\n";
    else
        std::cout << "Nie jest to mała litera alfabetu\n";


    /*char x = 'a';
    std::cout << x;
    x = 'g' + 1;
    std::cout << x;
    x = 100;
    std::cout << x;*/

}

int main()
{
    setlocale(LC_CTYPE, "polish");
    task2();
}

/*
Typy znakowe:
* char - 1 bajt całkowitoliczbowa ze znakiem <-128; 127>

*/
