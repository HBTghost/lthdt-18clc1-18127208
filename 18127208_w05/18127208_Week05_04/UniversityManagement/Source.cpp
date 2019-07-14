#include "GiaoVienCN.h"

int main(int argc, char const *argv[])
{
	int kind;
	std::cout << "1. Giao vien bo mon.\n";
	std::cout << "2. Giao vien chu nhiem.\n";
	std::cout << "Chon loai giao vien: ";
	std::cin >> kind;
	std::cin.ignore();
	if (kind == 1) {
		GiaoVien gv;
		gv.input();
		gv.display();
		gv.getSalary();
	}
	else {
		GiaoVienCN gvcn;
		gvcn.input();
		gvcn.display();
		gvcn.getSalary();
	}
	return 0;
}