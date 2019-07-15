#include "TruongHoc.h"

TruongHoc::~TruongHoc() {
	for (GiaoVien* x : pGV) {
		delete x;
	}
}
bool TruongHoc::isValid() {
	return !pGV.empty();
}

bool TruongHoc::input() {
	int type;
	do {
		std::cout << "Chon loai giao vien (1. Giao vien bo mon, 2. Giao vien Chu nhiem, 0. Exit): ";
		std::cin >> type;
		std::cin.ignore();
		GiaoVien* gv{nullptr};
		if (type == 1) {
			gv = new GiaoVien;
		}
		else if (type == 2) {
			gv = new GiaoVienCN;
		}
		if (gv) {
			gv->input();
			pGV.emplace_back(gv);
		}
	} while (type != 0);
	return true;
}
void TruongHoc::display() {
	for (GiaoVien* x : pGV) {
		x->display();
	}
}
uint64_t TruongHoc::getSumSalaries() {
	uint64_t res{0};
	for (GiaoVien* x : pGV) {
		res += x->getSalary();
	}
	return res;
}
GiaoVien* TruongHoc::getGVbyMaxSalary() {
	GiaoVien* xMax = pGV[0];
	for (GiaoVien* x : pGV) {
		if (x->haveSalaryGreaterThan(xMax)) {
			xMax = x;
		}
	}
	return xMax;
}
uint16_t TruongHoc::getGVsQuantity() {
	return pGV.size() - getGVCNsQuantity();
}
uint16_t TruongHoc::getGVCNsQuantity() {
	return GiaoVienCN::GetCount();
}
uint32_t TruongHoc::getAvgSalary() {
	return getSumSalaries() / pGV.size();
}
void TruongHoc::displayGVsHaveSalaryAbove(uint32_t arg) {
	for (GiaoVien* x : pGV) {
		if (x->haveSalaryGreaterThan(arg)) {
			x->display();
		}
	}
}
GiaoVien* TruongHoc::getGVbyID() {
	std::string id;
	std::cout << "Enter ID: ";
	getline(std::cin, id);
	for (GiaoVien* x : pGV) {
		if (x->isMatchByID(id))
			return x;
	}
	return nullptr;
}
GiaoVien* TruongHoc::getGVbyName() {
	std::string name;
	std::cout << "Enter name: ";
	getline(std::cin, name);
	for (GiaoVien* x : pGV) {
		if (x->isMatchByName(name))
			return x;
	}
	return nullptr;
}
uint16_t TruongHoc::getGVsQuantityAbsentAbove(uint16_t absents) {
	uint16_t sum = 0;
	for (GiaoVien* x : pGV) {
		if (x->absentAbove(absents)) {
			++sum;
		}
	}
	return sum;
}
