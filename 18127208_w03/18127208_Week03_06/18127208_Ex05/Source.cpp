#include "Time.h"

int main(int argc, char const *argv[])
{
	Time input;
	input.input();
	Time copy(input);
	std::cout << "Input: " << input << "\n";
	std::cout << "Increase: " << ++input << "\n";
	std::cout << "Descrease: " << --copy << "\n";
	return 0;
}