#include "Rectangle.h"

Rectangle::Rectangle(double a, double b, std::string n)
{
	sideA = a;
	sideB = b;
	name = n;
}

void Rectangle::ShowInformation()
{
	std::cout << "Informacja o obiekcie  o nazwie: " << name << "\n";
	std::cout << "Bok a = " << sideA << "\n";
	std::cout << "Bok b = " << sideB << "\n";
	std::cout << "Pole = " << GetArea() << "\n";
	std::cout << "Obwód = " << GetPerimeter() << "\n";

}
double Rectangle::GetPerimeter()
{
	return 2 * sideA + 2 * sideB;
}
double Rectangle::GetArea()
{
	return sideA * sideB;
}