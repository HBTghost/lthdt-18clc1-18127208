#include "ThuVien.h"

int main(int argc, char const *argv[])
{
	ThuVien lib;

	std::cout << "Input:\n";
	lib.input();
	if (lib.isValid()) {
		std::cout << "\nDisplay:";
		lib.display();

		std::cout << "\n\nTong doc phi cua tat ca doc gia: " << lib.getSumFee();

		std::cout << "\n\nDoc gia co phi cao nhat:\n";
		lib.getDGbyMaxFee()->display();

		std::cout << "\n\nSo doc gia thuong: " << lib.getDGTsQuantity();

		std::cout << "\n\nSo doc gia Vip: " << lib.getDGVsQuantity();

		std::cout << "\n\nPhi doc gia trung binh trong thu vien: " << lib.getAvgFee();

		std::cout << "\n\nLiet ke cac doc gia co phi doc gia cao hon 30.000:\n";
		lib.displayDGsHaveFeeAbove(30000);

		std::cout << "\n\nNhap vao ma, tim doc gia tuong ung:\n";
		DocGia* DG;
		if ((DG = lib.getDGbyID()) != nullptr) {
			DG->display();
		}

		std::cout << "\n\nNhap vao ten, tim doc gia tuong ung:\n";
		if ((DG = lib.getDGbyName()) != nullptr) {
			DG->display();
		}

		std::cout << "\n\nSo luong doc gia het han trong nam 2017: ";
		std::cout << lib.getDGsHaveExpDateIn(2017) << "\n";
	}
	
	return 0;
}