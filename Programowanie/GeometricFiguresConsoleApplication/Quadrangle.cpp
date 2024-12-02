#include "Quadrangle.h"

Quadrangle::Quadrangle(double a, double b, double c, double d, double h, std::string n)
{
	sideA = a;
	sideB = b;
	sideC = c;
	sideD = d;
	height = h;
	name = n;
}

void Quadrangle::ShowInformation()
{
	std::cout << "Informacja o obiekcie  o nazwie: " << name << "\n";
	std::cout << "Bok a = " << sideA << "\n";
	std::cout << "Bok b = " << sideB << "\n";
	std::cout << "Bok c = " << sideC << "\n";
	std::cout << "Bok d = " << sideD << "\n";
	std::cout << "Obwód = " << GetPerimeter() << "\n";
	std::cout << "Pole = " << GetArea() << "\n";

}

double Quadrangle::GetPerimeter()
{
	return sideA + sideB + sideC + sideD;
}

double Quadrangle::GetArea()
{
	return -1;
}