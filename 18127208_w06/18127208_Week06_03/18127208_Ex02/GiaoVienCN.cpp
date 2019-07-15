#include "GiaoVienCN.h"

bool GiaoVienCN::input() {
	GiaoVien::input();
	return true;
}
void GiaoVienCN::display() {
	GiaoVien::display();
}
uint64_t GiaoVienCN::getSalary() {
	return GiaoVien::getSalary() + allowance;
}
