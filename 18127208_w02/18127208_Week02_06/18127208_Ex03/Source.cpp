#include "Triangle.h"

#define FILE_IN_NAME "in.txt"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		int n;
		filein >> n;
		Triangle* arr = new Triangle[n];
		for (unsigned i = 0; i < n; ++i) {
			filein >> arr[i];
		}
		int valids = 0;
		for (unsigned i = 0; i < n; ++i) {
			if (arr[i].isValid())
				++valids;
		}
		Triangle* newArr = new Triangle[valids];
		for (unsigned i = 0, j = 0; i < n; ++i) {
			if (arr[i].isValid()) {
				newArr[j++] = arr[i];
			}
		}
		delete[] arr;
		std::cout << "The number of triangles were removed: " << n - valids << "\n";
		int type[6] = {0};
		for (unsigned i = 0; i < valids; ++i) {
			type[newArr[i].getIndexType()]++;
		}
		for (unsigned i = 0; i < 6; ++i) {
			std::cout << getTypeByIndex(i) << " triangle: " << type[i] << "\n";
		}
		delete[] newArr;
		filein.close();
	}

	return 0;
}