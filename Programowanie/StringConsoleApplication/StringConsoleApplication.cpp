// StringConsoleApplication.cpp 

#include <iostream>

int main()
{
    setlocale(LC_CTYPE, "polish");

    std::string text;

    text = "Hello";
    std::cout << "Nasz tekst na pocz�tku: " << text << "\n";
    std::cout << "D�ugo�� �a�cucha to: " << text.length() << "\n";
    std::cout << "Czy zmienna jest pusta: " << text.empty() << "\n";
    text.append(", World!");
    //text = text + ", World!";
    //text +=", World!";
    std::cout << "Nasz tekst na: " << text << "\n";


}
