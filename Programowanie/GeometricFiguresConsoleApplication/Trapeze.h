#pragma once
#include <iostream>
#include "Quadrangle.h"

class Trapeze : public Quadrangle
{
private:


protected:

public:
	Trapeze(double a, double b, double c, double d, double h, std::string n = "Trapez");
	
	void ShowInformation();
	double GetArea();

};

