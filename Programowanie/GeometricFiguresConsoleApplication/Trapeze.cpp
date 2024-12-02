#include "Trapeze.h"

Trapeze::Trapeze(double a, double b, double c, double d, double h, std::string n = "Trapez") :Quadrangle(a, b, c, d, h, n)
{

}
/*
void Trapeze::ShowInformation()
{
	Quadrangle::ShowInformation();
	std::cout << "Pole = " << GetArea() << "\n";
}
*/
double Trapeze::GetArea()
{
	return (sideB + sideD) * height / 2;
}