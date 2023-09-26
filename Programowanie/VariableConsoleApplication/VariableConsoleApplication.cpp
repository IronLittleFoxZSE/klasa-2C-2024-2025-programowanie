#include <iostream>

int main() 
{
    //Napisz program który wczyta liczbę od użytkownika i ją wyświetli na konsoli
    
    int numberFromUser;
    std::cout << "Podaj liczbe\n";
    std::cin >> numberFromUser;

    std::cout << "Podales " << numberFromUser << "\n";
}

/*
Algotytm - skończony zbiór instrukcji, 
który rozwiązuje zadany problem.
Określa też kolejność wynonywanych instrukcji.
Zapis algorytmu:
* rysunki 
* opis słowny
* w punktach
* schemat blokowy
* kod źródłowy danego języka programowania
* pseudokod

Zmienna - pewien obszar w pamięci operacyjnej, w której można
w danej chwili przechować tylko jedną daną.

Instrukcja daklaracji zmiennej:
typ_zmiennej nazwa_zmiennej;

Typ zmiennej - wielkość obszaru pamięci, interpretacja ciągu bitów

int - 4 bajtowa liczba całkowita ze znakiem <-2 147 483 648, 2 147 483 647>
short - 2 bajtowa liczba całkowita ze znakiem <-32 768, 32 767>
long - to samo co int
long long - 8 bajtowa liczba ze znakiem <-9 223 372 036 854 775 808, 9 223 372 036 854 775 807>

unsigned - zmienna bez znaku <0, 2*max + 1>

float - 4 bajtowa liczba rzeczywista, dokładność 6-7 cyfr po przecinku
double - 8 bajtowa liczba rzeczywista, dokładność 15-16 cyfr po przecinku
long double - 12 bajtowa liczba rzeczywista, dokładność 19-20 cyfr po przecinku

Nazwa zmiennej - nazwa obszaru w pamięci, identyfikator
Warunki niezbędne:
* dozwolone znaki:
    - alfabet angielski aA-zZ
    - cyfry arabskie 0-9
    - podkreślenie (podłoga) _
* pierwszym znakiem nie może być cyfra
* unikalny w swoim zakresie widoczności
* nie może to być słowo kluczowe (zarezerwowane) danego języka

Warunki programistów:
* nazwa zmiennej powinna oddawać charakter przechowywanych danych
* jeśli wiele słów to w miejscu spacji podkreślenie lub zaczynając od drugiego
  słowa piszemy je z dużej litery
* piszemy po angielsku
*/