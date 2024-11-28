#pragma once
#include <iostream>

class Rectangle
{
private:
	
protected:
	double sideA, sideB;

	std::string name;

public:
	
	Rectangle(double a, double b, std::string n = "Prostok¹t");

	void ShowInformation();
	double GetPerimeter();
	double GetArea();
};

/*
	Rectangle()
	{
		sideA = 5;
		sideB = 8;
	}
	*/

