#include "Fraction.h"

#include <fstream>

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		Fraction a, b;
		filein >> a;
		filein >> b;
		char res = (a > b ? '>' : (a < b ? '<' : '='));
		std::cout << a << res << b << std::endl;
		filein.close();
	}

	return 0;
}