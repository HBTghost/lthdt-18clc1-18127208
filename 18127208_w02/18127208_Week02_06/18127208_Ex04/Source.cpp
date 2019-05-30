#include "Date.h"

int main(int argc, char const* argv[])
{
	Date input;
	input.input();
	std::cout << "Input: " << input << "\n";
	--input;
	std::cout << "The day before: " << input << "\n";
	++++input;
	std::cout << "The day after: " << input << "\n";
	return 0;
}