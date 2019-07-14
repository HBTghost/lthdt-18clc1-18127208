#include "NhanVienSanXuat.h"

NhanVienSanXuat::NhanVienSanXuat() : NhanVien() {
	produces = 0;
}
NhanVienSanXuat::NhanVienSanXuat(const NhanVien& nv) : NhanVien() {
	produces = 0;
}
NhanVienSanXuat::NhanVienSanXuat(unsigned produces) : NhanVien() {
	this->produces = produces;
}
NhanVienSanXuat::NhanVienSanXuat(const NhanVien& nv, unsigned produces) : NhanVien(nv) {
	this->produces = produces;
}
NhanVienSanXuat::NhanVienSanXuat(const NhanVienSanXuat& nvss) : NhanVien(nvss) {
	this->produces = nvss.produces;
}

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
unsigned long NhanVienSanXuat::getSalary() {
	return produces * coefficient;
}
