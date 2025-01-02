#pragma once
#include "Quadrangle.h"

class Parallelogram :public Quadrangle  //równoleg³obok
{
private:

protected:

public:
	Parallelogram(double a, double b, double h, std::string n = "równoleg³obok") : Quadrangle(a, b, a, b, h, n)
	{

	}

	/*
	void ShowInformation()
	{
		Quadrangle::ShowInformation();
		std::cout << "Pole = " << GetArea() << "\n";
	}
	*/

	double GetArea()
	{
		return height * sideB;
	}
};

