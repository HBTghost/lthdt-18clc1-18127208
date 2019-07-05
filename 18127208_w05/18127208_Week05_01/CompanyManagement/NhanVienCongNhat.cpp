#include "NhanVienCongNhat.h"

NhanVienCongNhat::NhanVienCongNhat() : NhanVien() {
	days = 0;
}
NhanVienCongNhat::NhanVienCongNhat(const NhanVien& nv) : NhanVien() {
	days = 0;
}
NhanVienCongNhat::NhanVienCongNhat(unsigned days) : NhanVien() {
	this->days = days;
}
NhanVienCongNhat::NhanVienCongNhat(const NhanVien& nv, unsigned days) : NhanVien(nv) {
	this->days = days;
}
NhanVienCongNhat::NhanVienCongNhat(const NhanVienCongNhat& nvcn) : NhanVien(nvcn) {
	this->days = nvcn.days;
}

bool NhanVienCongNhat::input() {
	NhanVien::input();
	std::cout << "\nThe number of days: ";
	std::cin >> days;
	return true;
}
void NhanVienCongNhat::display() {
	NhanVien::display();
	std::cout << "The number of days: " << days;
	std::cout << "\nSalary: " << getSalary() << " vnd";
}
unsigned long NhanVienCongNhat::getSalary() {
	return days*coefficient;
}