#include <iostream>

struct point
{
	double x;
	double y;
};

void getPointValue(double &x, double &y)
{
	std::cout << "Podaj x\n";
	std::cin >> x;

	std::cout << "Podaj y\n";
	std::cin >> y;
}

void getPointValue(point &p)
{
	std::cout << "Podaj x\n";
	std::cin >> p.x;

	std::cout << "Podaj y\n";
	std::cin >> p.y;
}

//Napisz program, który obliczy odleg³oœæ punktu 2D
//od innego innego punktu.
void task2()
{
	//double x, y;
	point firstPoint;
	//firstPoint.x = 5.9;

	//getPointValue(firstPoint.x, firstPoint.y);
	getPointValue(firstPoint);

	double distance = sqrt(firstPoint.x * firstPoint.x + firstPoint.y * firstPoint.y);

	std::cout << "Odleg³oœæ to " << distance << "\n";
}