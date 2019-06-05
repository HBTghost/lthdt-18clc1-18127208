#include "PointArr.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	Point p;
	std::cout << "Enter P:\n";
	p.input();
	PointArr arr(std::string(FILE_IN_NAME));
	std::cout << "Max to P: " << arr.MaxDistanceToP(p);

	return 0;
}