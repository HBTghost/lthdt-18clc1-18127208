#include "Student.h"

#define FILE_OUT_NAME "out.XML"

int main(int argc, char const* argv[])
{
	std::ofstream fileout;
	fileout.open(FILE_OUT_NAME);
	Student a, b;
	std::cout << "Enter Student A:\n";
	a.input();
	std::cout << "Enter Student B:\n";
	b.input();
	if (a.hasGreaterMark(b))
		fileout << a;
	else
		fileout << b;

	fileout.close();
	return 0;
}