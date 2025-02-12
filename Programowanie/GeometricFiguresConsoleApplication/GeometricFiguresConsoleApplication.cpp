// GeometricFiguresConsoleApplication.cpp
#include <iostream>
#include "Rectangle.h"
#include "Square.h"
#include "Trapeze.h"

//Napisz klasy które opisz¹ figury geometryczne: 
// trapez, romb, równoleg³obok, prostok¹t i kwadrat.
// Zdefiniuj podstawowe metody.

void WorkOnRectangle(Rectangle& r);
void WorkOnTrapeze(Trapeze& t);
void WorkOn(Quadrangle& q);

int main()
{
    Rectangle rec(6, 4);
    rec.ShowInformation();
    //std::cout << "Pole2 = " << rec.GetArea() << "\n";

    Square sq(5, "Ala");
    sq.ShowInformation();

    Trapeze tr(5, 8, 7, 2, 7);
    tr.ShowInformation();

    Rectangle firstRec(2,8, "Pierwszy prostokat"), secondRec(6, 4, "Drugi prostokat");

    /*
    firstRec.ShowInformation();
    std::cout << "Pole obiektu = " << firstRec.GetArea();
    std::cout << "Obwód naszego obiektu = " << firstRec.GetPerimeter();

    secondRec.ShowInformation();
    std::cout << "Pole obiektu = " << secondRec.GetArea();
    std::cout << "Obwód naszego obiektu = " << secondRec.GetPerimeter();
    */

    //WorkOnRectangle(firstRec);
    //WorkOnRectangle(secondRec);
    WorkOn(firstRec);
    WorkOn(secondRec);

    Trapeze firstTrapeze(5, 8, 7, 2, 7, "Pierwszy trapez"), secondTrapeze(2, 4, 7, 2, 7, "Drugi trapez");

    //WorkOnTrapeze(firstTrapeze);
    //WorkOnTrapeze(secondTrapeze);

    WorkOn(firstTrapeze);
    WorkOn(secondTrapeze);

}

void WorkOnRectangle(Rectangle& r)
{
    r.ShowInformation();
    std::cout << "Pole obiektu = " << r.GetArea() << "\n";
    std::cout << "Obwód naszego obiektu = " << r.GetPerimeter() << "\n";
}

void WorkOnTrapeze(Trapeze& t)
{
    t.ShowInformation();
    std::cout << "Pole obiektu = " << t.GetArea() << "\n";
    std::cout << "Obwód naszego obiektu = " << t.GetPerimeter() << "\n";
}


void WorkOn(Quadrangle& q)
{
    q.ShowInformation();
    std::cout << "Pole obiektu = " << q.GetArea() << "\n";
    std::cout << "Obwód naszego obiektu = " << q.GetPerimeter() << "\n";
}