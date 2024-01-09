#include <iostream>

/*
* Napisz program, który będzie prosił o hasło. Nie przepuści dalej dopóki nie zostanie ono podane prawidłowo.
* Napisz program, który pobiera od użytkownika ciąg znaków i wyświetla liczbę samogłosek i spółgłosek w tym ciągu.
* Poproś użytkownika o wprowadzenie liczby całkowitej w systemie dziesiętnym. Następnie skonwertuj tę liczbę na system dwójkowy (binarny) i wyświetl wynik.
* 
* Program sprawdzający czy podane dwa słowa są anagramami (czyli takimi, które zawierają te same litery, ale w innym układzie, np. "klasa" i "salka")
* Program wyciągający informacje z numeru PESEL
* Program implementujący algorytm szyfrowania Cezara (proste szyfrowanie, w którym każdy znak w tekście jest zastępowany innym znakiem, przesuniętym o stałą liczbę pozycji w alfabecie).

* Program który na wejściu przyjmie równanie a na wyjściu da równanie w odwrotnej notacji polskiej ONP. Np. na wejściu 2+3*4 na wyjścu da 234*+
* Program, który na wejściu przyjmie rówanie w ONP a na wyjściu wyświetli wynik rówania.
* 
*/

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

//Program sprawdzający czy podany ciąg znaków jest palindromem (czyli takim, który czytany od tyłu jest taki sam, jak czytany od przodu, np. "kajak")
void task6()
{
    std::string textFromUser;
    std::cout << "Podaj tekst\n";
    std::cin >> textFromUser;

    //wersja 1
    std::string reverseText = "";
    for (int i = textFromUser.length() - 1; i >= 0; i--)
    {
        reverseText = reverseText + textFromUser[i];
    }

    /*for (int i = 0; i < textFromUser.length(); i++)
    {
        reverseText = textFromUser[i] + reverseText;
    }*/
    
    if (textFromUser == reverseText)
        std::cout << "Ten tekst jest palindromem\n";
    else
        std::cout << "Ten tekst nie jest palindromem\n";

    //wersja 2
    bool isPalindrome = true;

    for (int signFromBegining = 0, signFormEnd = textFromUser.length() - 1; signFromBegining < signFormEnd ; signFromBegining++, signFormEnd--)
    {
        if (textFromUser[signFromBegining] != textFromUser[signFormEnd])
        {
            isPalindrome = false;
            break;
        }
    }

    if (isPalindrome /*== true*/)
        std::cout << "Ten tekst jest palindromem\n";
    else
        std::cout << "Ten tekst nie jest palindromem\n";
}

//Algorytm szyfrowania AtBash Cipher - algorytm szyfrujący, w którym każda litera jest zamieniana na literę z przeciwnej strony alfabetu (np. A na Z, B na Y itd.)
void task7()
{
    std::string textFromUser;
    std::cout << "Podaj tekst\n";
    std::cin >> textFromUser;

    for (int i = 0; i < textFromUser.length(); i++)
    {
        if (textFromUser[i] >= 'a' && textFromUser[i] <= 'z')
            textFromUser[i] = 'z' - (textFromUser[i] - 'a');

        if (textFromUser[i] >= 'A' && textFromUser[i] <= 'Z')
            textFromUser[i] = 'Z' - (textFromUser[i] - 'A');

        if (textFromUser[i] >= '0' && textFromUser[i] <= '9')
            textFromUser[i] = '9' - (textFromUser[i] - '0');
    }

    std::cout << "Zaszyfrowany tekst: " << textFromUser << "\n";

    for (int i = 0; i < textFromUser.length(); i++)
    {
        if (textFromUser[i] >= 'a' && textFromUser[i] <= 'z')
            textFromUser[i] = 'a' + ('z' - textFromUser[i]);

        if (textFromUser[i] >= 'A' && textFromUser[i] <= 'Z')
            textFromUser[i] = 'A' + ('Z' - textFromUser[i]);

        if (textFromUser[i] >= '0' && textFromUser[i] <= '9')
            textFromUser[i] = '0' + ('9' - textFromUser[i]);
    }

    std::cout << "Rozszyfrowany tekst: " << textFromUser << "\n";

}

int main()
{
    setlocale(LC_CTYPE, "polish");
    task7();
}

/*
Typy znakowe:
* char - 1 bajt całkowitoliczbowa ze znakiem <-128; 127>

*/
