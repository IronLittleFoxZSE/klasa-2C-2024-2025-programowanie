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

//Napisz program, który poprosi cie o twoje imię i cię przywita.
void task3()
{
    std::string userName;
    std::cout << "Podaj swoje imie\n";
    std::cin >> userName;

    std::cout << "Witaj " << userName << " tutaj.\n";
}

//Program sprawdzający czy podane hasło jest poprawne 
//(np. jeśli hasło jest "abc123", program powinien wyświetlić "hasło poprawne", 
//jeśli jest inne, powinien wyświetlić "hasło niepoprawne").
void task4()
{
    std::string password;
    std::cout << "Podaj hasło\n";
    std::cin >> password;

    if (password == "abc123")
        std::cout << "Hasło poprawne\n";
    else
        std::cout << "Hasło niepoprawne\n";
}

//Napisz program, który wczyta łańcuch znaków i policzy ile jest małych liter 'a'.
void task5()
{
    std::string textFromUser;
    std::cout << "Podaj łańcuch znaków\n";
    std::cin >> textFromUser;

    int numberOfCharacters = 0;

    //std::cout << "Pierwszy znak to " << textFromUser[0] << "\n";
    //textFromUser[1] = 'x';
    //std::cout << "Ilość znaków " << textFromUser.length()  << "\n";
    
    for (int i = 0; i < textFromUser.length(); i++)
    {
        if (textFromUser[i] == 'a')
            numberOfCharacters++;
    }

    std::cout << "Małych liter 'a' jest " << numberOfCharacters << "\n";
}

int main()
{
    setlocale(LC_CTYPE, "polish");
    task5();
}

/*
Typy znakowe:
* char - 1 bajt całkowitoliczbowa ze znakiem <-128; 127>

*/
