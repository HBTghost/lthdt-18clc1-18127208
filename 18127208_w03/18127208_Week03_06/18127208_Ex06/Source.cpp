#include "StudentArr.h"

#define FILE_IN_NAME "in.txt"
#define FILE_OUT_NAME "out.XML"

int main(int argc, char const* argv[])
{
	StudentArr sArr(std::string(FILE_IN_NAME));
	sArr.sortLNameAsc();
	std::ofstream fileout;
	fileout.open(FILE_OUT_NAME);
	fileout << sArr;
	fileout.close();

	return 0;
}