#include "NhanVienSanXuat.h"

bool NhanVienSanXuat::input() {
	NhanVien::input();
	std::cout << "The number of produces: ";
	std::cin >> produces;
	return true;
}
void NhanVienSanXuat::display() {
	NhanVien::display();
	std::cout << "\nThe number of produces: " << produces;
}
uint32_t NhanVienSanXuat::getSalary() {
	return produces * coefficient;
}
