// GeometricFiguresConsoleApplication.cpp
#include <iostream>
#include "Rectangle.h"
#include "Square.h"

//Napisz klasy kt�re opisz� figury geometryczne: 
// trapez, romb, r�wnoleg�obok, prostok�t i kwadrat.
// Zdefiniuj podstawowe metody.

int main()
{
    Rectangle rec(6, 4);
    rec.ShowInformation();

    Square sq(5, "Ala");
    sq.ShowInformation();
}
