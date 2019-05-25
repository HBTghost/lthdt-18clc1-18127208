#include "Point.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		int n;
		filein >> n;
		Point* arr = new Point[n];
		for (unsigned i = 0; i < n; ++i) {
			filein >> arr[i];
		}
		std::cout << "Input P: ";
		Point p;
		p.input();
		std::cout << "Output: " << MaxDistanceToP(arr, n, p);
		filein.close();
	}

	return 0;
}