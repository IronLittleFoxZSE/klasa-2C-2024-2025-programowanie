#include <iostream>

//Napisz program, kt�ry obliczy odleg�o�� punktu 2D
//od �rodka uk�adu wsp�rz�dnych.
void task1()
{
	double x, y;
	std::cout << "Podaj x\n";
	std::cin >> x;

	std::cout << "Podaj y\n";
	std::cin >> y;

	double distance = sqrt(x * x + y * y);

	std::cout << "Odleg�o�� to " << distance << "\n";
}