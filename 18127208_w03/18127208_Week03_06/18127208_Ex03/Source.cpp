#include "TriangleArr.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	TriangleArr tArr(std::string(FILE_IN_NAME));
	std::cout << "The number of triangles were removed: ";
	std::cout << tArr.getQuantity() - tArr.getTheNumberOfValids() << "\n";
	tArr.deleteInvalids();
	tArr.showTypes();

	return 0;
}