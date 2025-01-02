#pragma once
#include <iostream>
#include "Quadrangle.h"

class Rectangle: public Quadrangle
{
private:
	
protected:
	

public:
	
	Rectangle(double a, double b, std::string n = "Prostok¹t");

	//void ShowInformation();
	double GetArea();
};

/*
	Rectangle()
	{
		sideA = 5;
		sideB = 8;
	}
	*/

