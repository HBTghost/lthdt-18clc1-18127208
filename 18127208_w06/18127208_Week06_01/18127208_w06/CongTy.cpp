#include "CongTy.h"

CongTy::~CongTy() {
	for (unsigned i = 0; i < pNV.size(); ++i) {
		delete pNV[i];
	}
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
			pNV.push_back(nv);
		}
	} while (type != 0);
	return true;
}
void CongTy::display() {
	for (unsigned i = 0; i < pNV.size(); ++i) {
		pNV[i]->display();
	}
}
unsigned long long CongTy::getSumSalaries() {
	unsigned long long res{0};
	for (unsigned i = 0; i < pNV.size(); ++i) {
		res += pNV[i]->getSalary();
	}
	return res;
}
NhanVien* CongTy::getNVbyMaxSalary() {
	unsigned iMax = 0;
	for (unsigned i = 1; i < pNV.size(); ++i) {
		if (pNV[i]->getSalary() > pNV[iMax]->getSalary()) {
			iMax = i;
		}
	}
	return pNV[iMax];
}
unsigned CongTy::getNVSXsQuantity() {
	return NhanVienSanXuat::GetCount();
}
unsigned CongTy::getNVCNsQuantity() {
	return NhanVienCongNhat::GetCount();
}
unsigned long CongTy::getAvgSalary() {
	return getSumSalaries() / pNV.size();
}
void CongTy::displayNVsHaveSalaryUnder3M() {
	for (int i = 0; i < pNV.size(); ++i)
	{
		if (pNV[i]->getSalary() < 3000000) {
			pNV[i]->display();
		}
	}
}
NhanVien* CongTy::getNVbyID() {
	std::string id;
	std::cout << "Enter ID: ";
	getline(std::cin, id);
	for (unsigned i = 0; i < pNV.size(); ++i) {
		if (pNV[i]->isMatchByID(id))
			return pNV[i];
	}
	return nullptr;
}
NhanVien* CongTy::getNVbyName() {
	std::string name;
	std::cout << "Enter name: ";
	getline(std::cin, name);
	for (unsigned i = 0; i < pNV.size(); ++i) {
		if (pNV[i]->isMatchByName(name))
			return pNV[i];
	}
	return nullptr;
}
unsigned CongTy::getTheNumberOfNVsByMoB(unsigned MoB) {
	unsigned res = 0;
	for (unsigned i = 0; i < pNV.size(); ++i) {
		if (pNV[i]->isMatchByMoB(MoB)) {
			++res;
		}
	}
	return res;
}
