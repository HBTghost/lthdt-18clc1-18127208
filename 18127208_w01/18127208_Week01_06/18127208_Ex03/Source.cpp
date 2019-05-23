#include "Point.h"

int main(int argc, char const* argv[])
{
	Point a, b;
	std::cout << "Enter A:\n";
	a.input();
	std::cout << "\nEnter B:\n";
	b.input();
	std::cout << "\nDistances: AB = " << a.to(b) << "\n";

	return 0;
}