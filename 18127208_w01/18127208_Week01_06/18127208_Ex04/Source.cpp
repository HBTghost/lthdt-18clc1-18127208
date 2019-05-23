#include "Triangle.h"

#include <fstream>

#define FILE_IN_NAME "in.txt"
#define FILE_OUT_NAME "out.txt"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		Triangle t;
		filein >> t;
		std::ofstream fileout;
		fileout.open(FILE_OUT_NAME);
		fileout << t;
		filein.close();
		fileout.close();
	}

	return 0;
}