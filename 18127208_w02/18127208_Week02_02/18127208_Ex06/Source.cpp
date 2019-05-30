#include "Student.h"

#define FILE_IN_NAME "in.txt"
#define FILE_OUT_NAME "out.XML"

int main(int argc, char const* argv[])
{
	std::ifstream filein;
	filein.open(FILE_IN_NAME);
	if (filein.is_open()) {
		int n;
		filein >> n;
		Student* arr = new Student[n];
		for (unsigned i = 0; i < n; ++i) {
			filein >> arr[i];
		}
		sortLNameAsc(arr, n);
		std::ofstream fileout;
		fileout.open(FILE_OUT_NAME);
		fileout << n << "\n";
		for (unsigned i = 0; i < n; ++i) {
			fileout << arr[i];
			if (i < n - 1) {
				fileout << "\n";
			}
		}
		filein.close();
	}

	return 0;
}