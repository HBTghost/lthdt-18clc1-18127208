#include "CongTy.h"

CongTy::~CongTy() {
	for (NhanVien* x : pNV) {
		delete x;
	}
}
bool CongTy::isValid() {
	return !pNV.empty();
}

bool CongTy::input() {
	int type;
	do {
		std::cout << "Chon loai nhan vien (1. Nhan Vien San Xuat, 2. Nhan Vien Cong Nhat, 0. Exit): ";
		std::cin >> type;
		std::cin.ignore();
		NhanVien* nv{nullptr};
		if (type == 1) {
			nv = new NhanVienSanXuat;
		}
		else if (type == 2) {
			nv = new NhanVienCongNhat;
		}
		if (nv) {
			nv->input();
			pNV.emplace_back(nv);
		}
	} while (type != 0);
	return true;
}
void CongTy::display() {
	for (NhanVien* x : pNV) {
		x->display();
	}
}
uint64_t CongTy::getSumSalaries() {
	uint64_t res{0};
	for (NhanVien* x : pNV) {
		res += x->getSalary();
	}
	return res;
}
NhanVien* CongTy::getNVbyMaxSalary() {
	NhanVien* xMax = pNV[0];
	for (NhanVien* x : pNV) {
		if (x->hasSalaryGreaterThan(xMax)) {
			xMax = x;
		}
	}
	return xMax;
}
uint16_t CongTy::getNVSXsQuantity() {
	return NhanVienSanXuat::GetCount();
}
uint16_t CongTy::getNVCNsQuantity() {
	return NhanVienCongNhat::GetCount();
}
uint32_t CongTy::getAvgSalary() {
	return getSumSalaries() / pNV.size();
}
void CongTy::displayNVsHaveSalaryUnder(uint32_t arg) {
	for (NhanVien* x : pNV) {
		if (x->hasSalarySmallerThan(arg)) {
			x->display();
		}
	}
}
NhanVien* CongTy::getNVbyID() {
	std::string id;
	std::cout << "Enter ID: ";
	getline(std::cin, id);
	for (NhanVien* x : pNV) {
		if (x->isMatchByID(id))
			return x;
	}
	return nullptr;
}
NhanVien* CongTy::getNVbyName() {
	std::string name;
	std::cout << "Enter name: ";
	getline(std::cin, name);
	for (NhanVien* x : pNV) {
		if (x->isMatchByName(name))
			return x;
	}
	return nullptr;
}
uint16_t CongTy::getTheNumberOfNVsByMoB(uint16_t MoB) {
	uint16_t res = 0;
	for (NhanVien* x : pNV) {
		if (x->isMatchByMoB(MoB)) {
			++res;
		}
	}
	return res;
}
