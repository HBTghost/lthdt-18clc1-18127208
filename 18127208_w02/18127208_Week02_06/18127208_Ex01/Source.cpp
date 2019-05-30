#include "FractionArr.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	FractionArr arr;
	arr.input(std::string(FILE_IN_NAME));
	arr.ascSort();
	arr.display();
	return 0;
}