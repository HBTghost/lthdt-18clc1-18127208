#include "GiaoVienCN.h"

GiaoVienCN::GiaoVienCN() : GiaoVien() {}
GiaoVienCN::GiaoVienCN(std::string id, std::string fName, unsigned basicSalary) : GiaoVien(id, fName, basicSalary) {}
GiaoVienCN::GiaoVienCN(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient) : GiaoVien(id, fName, basicSalary, coefficient) {}
GiaoVienCN::GiaoVienCN(const GiaoVien& gv) : GiaoVien(gv) {}
GiaoVienCN::GiaoVienCN(const GiaoVienCN& gvcn) : GiaoVien(gvcn) {}

bool GiaoVienCN::input() {
	GiaoVien::input();
	return true;
}
void GiaoVienCN::display() {
	GiaoVien::display();
}
unsigned long GiaoVienCN::getSalary() {
	return GiaoVien::getSalary() + allowance;
}
