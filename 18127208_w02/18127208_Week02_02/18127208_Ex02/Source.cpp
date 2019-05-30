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
		Point p, res;
		std::cout << "Input P:\n";
		p.input();
		res = MaxDistanceToP(arr, n, p);
		std::cout << "Output: " << res;
		filein.close();
	}

	return 0;
}