#include "Fraction.h"

int main(int argc, char const *argv[])
{
	Fraction f1, f2;					// 0/1
	Fraction f3(1,-7);				// -1/7
	Fraction f4(f3);				// Copy constructor
	Fraction f5 = f2;					// Copy constructor
	Fraction f6, f7, f8;					// Default constructor
	f6=f3;							// Operator =

	f7 = f1 + f5;
	f8 = f2 - f4;
	f3 = f1 * f7;
	try {
		f5 = f6 / f2;	
	}
	catch (const std::invalid_argument& err) {
		std::cerr << err.what();
	}

	if (f2 == f3)
		std::cout << "\nf2==f3";
	if (f3 != f1)
		std::cout << "\nf3!=f1";
	if (f2 >= f5)
		std::cout << "\nf2>=f5";
	if (f2 > f5)
		std::cout << "\nf2>f5";
	if (f5 <= f3)
		std::cout << "\nf5<=f3";
	if (f5 < f3)
		std::cout << "\nf5<f3";

	f1 = f2 + 3;
	f3 = -7 + f1;
	f5 = 7 * f3;
	f6 = f4 - 6;
	
	std::cout << "\n" << f3;
	std::cout << "\n" << f6;

	f1 += f5;
	f6 -= f7;
	f8 *= f1;
	try {
		f8 /= f2;
	}
	catch (const std::invalid_argument& err) {
		std::cerr << err.what();
	}

	std::cout << "\n" << f8++;
	std::cout << "\n" << ++f7;
	
	std::cout << "\n" << f8--;
	std::cout << "\n" << --f7;
	
	float f = (float)f3;				// 3/2 => 1.5
	return 0;
}