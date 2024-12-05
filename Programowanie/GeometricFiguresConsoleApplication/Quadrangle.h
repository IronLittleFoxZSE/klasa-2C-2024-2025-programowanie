#pragma once
#include <iostream>

class Quadrangle
{
private:

protected:
	double sideA, sideB, sideC, sideD;
	double height;
	std::string name;
public:
	Quadrangle(double a, double b, double c, double d, double h, std::string n);

	void ShowInformation();
	double GetPerimeter();
	//double GetArea();
};

