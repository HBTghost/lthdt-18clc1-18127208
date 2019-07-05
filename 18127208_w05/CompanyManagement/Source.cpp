#include "NhanVienSanXuat.h"
#include "NhanVienCongNhat.h"

int main(int argc, char const *argv[])
{
	int kind;
	std::cout << "1. Nhan vien san xuat.\n";
	std::cout << "2. Nhan vien cong nhat.\n";
	std::cout << "Chon loai nhan vien: ";
	std::cin >> kind;
	std::cin.ignore();
	if (kind == 1) {
		NhanVienSanXuat nvss;
		nvss.input();
		nvss.display();
	}
	else {
		NhanVienCongNhat nvcn;
		nvcn.input();
		nvcn.display();
	}
	return 0;
}