#include "Rectangle.h"

Rectangle::Rectangle(double a, double b, std::string n):Quadrangle(a, b, a, b, a, n)
{
}

void Rectangle::ShowInformation()
{
	Quadrangle::ShowInformation();
	std::cout << "Pole = " << GetArea() << "\n";
}


double Rectangle::GetArea()
{
	return sideA * sideB;
}