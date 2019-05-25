#include "Fraction.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		int n;
		filein >> n;
		Fraction* arr = new Fraction[n];
		for (unsigned i = 0; i < n; ++i) {
			filein >> arr[i];
		}
		std::cout << "\nSum of them: " << sum(arr, n);
		ascSort(arr, n);
		std::cout << "\nMax: " << arr[n-1];
		std::cout << "\nMin: " << arr[0];
		std::cout << "\nSort Ascending order:\n";
		for (unsigned i = 0; i < n; ++i) {
			std::cout << arr[i] << "\n";
		}
		filein.close();
	}

	return 0;
}