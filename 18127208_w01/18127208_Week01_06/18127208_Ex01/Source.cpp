#include "Fraction.h"

int main(int argc, char const* argv[])
{
	 Fraction a, b, sum;
	 std::cout << "Enter fraction a:\n";
	 a.input();
	 std::cout << "\nEnter fraction b:\n";
	 b.input();
	 sum = a + b;
	 std::cout << "\nSum:\n";
	 std::cout << a << " + " << b << " = " << sum << std::endl;

	return 0;
}