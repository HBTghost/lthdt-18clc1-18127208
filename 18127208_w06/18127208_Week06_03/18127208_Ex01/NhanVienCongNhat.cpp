#include "NhanVienCongNhat.h"

bool NhanVienCongNhat::input() {
	NhanVien::input();
	std::cout << "The number of days: ";
	std::cin >> days;
	return true;
}
void NhanVienCongNhat::display() {
	NhanVien::display();
	std::cout << "\nThe number of days: " << days;
}
uint32_t NhanVienCongNhat::getSalary() {
	return days * coefficient;
}