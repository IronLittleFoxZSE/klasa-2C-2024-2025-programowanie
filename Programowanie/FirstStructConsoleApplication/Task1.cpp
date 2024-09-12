#include <iostream>

//Napisz program, który obliczy odleg³oœæ punktu 2D
//od œrodka uk³adu wspó³rzêdnych.
void task1()
{
	double x, y;
	std::cout << "Podaj x\n";
	std::cin >> x;

	std::cout << "Podaj y\n";
	std::cin >> y;

	double distance = sqrt(x * x + y * y);

	std::cout << "Odleg³oœæ to " << distance << "\n";
}