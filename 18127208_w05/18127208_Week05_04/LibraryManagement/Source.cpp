#include "DocGiaThuong.h"
#include "DocGiaVip.h"

int main(int argc, char const *argv[])
{
	int kind;
	std::cout << "1. Doc gia thuong.\n";
	std::cout << "2. Doc gia vip.\n";
	std::cout << "Chon loai doc gia: ";
	std::cin >> kind;
	std::cin.ignore();
	if (kind == 1) {
		DocGiaThuong basic;
		basic.input();
		basic.display();
		basic.getMonthPrice();
	}
	else {
		DocGiaVip vip;
		vip.input();
		vip.display();
		vip.getMonthPrice();
	}
	return 0;
}