#include "ThuVien.h"

ThuVien::~ThuVien() {
	for (auto x : pDG) {
		delete x;
	}
}
bool ThuVien::isValid() {
	return !pDG.empty();
}

bool ThuVien::input() {
	int type;
	do {
		std::cout << "Chon loai doc gia (1. Doc gia Thuong, 2. Doc gia Vip, 0. Exit): ";
		std::cin >> type;
		std::cin.ignore();
		DocGia* DG{nullptr};
		if (type == 1) {
			DG = new DocGiaThuong;
		}
		else if (type == 2) {
			DG = new DocGiaVip;
		}
		if (DG) {
			DG->input();
			pDG.emplace_back(DG);
		}
	} while (type != 0);
	return true;
}
void ThuVien::display() {
	for (auto x : pDG) {
		x->display();
	}
}
uint64_t ThuVien::getSumFee() {
	uint64_t res{0};
	for (auto x : pDG) {
		res += x->getMonthFee();
	}
	return res;
}
DocGia* ThuVien::getDGbyMaxFee() {
	DocGia* xMax = pDG[0];
	for (auto x : pDG) {
		if (x->haveFeeGreaterThan(xMax)) {
			xMax = x;
		}
	}
	return xMax;
}
uint16_t ThuVien::getDGTsQuantity() {
	return DocGiaThuong::GetCount();
}
uint16_t ThuVien::getDGVsQuantity() {
	return DocGiaVip::GetCount();
}
uint32_t ThuVien::getAvgFee() {
	return getSumFee() / pDG.size();
}
void ThuVien::displayDGsHaveFeeAbove(uint32_t fee) {
	for (auto x : pDG) {
		if (x->haveFeeGreaterThan(fee)) {
			x->display();
		}
	}
}
DocGia* ThuVien::getDGbyID() {
	std::string id;
	std::cout << "Enter ID: ";
	getline(std::cin, id);
	for (auto x : pDG) {
		if (x->isMatchByID(id))
			return x;
	}
	return nullptr;
}
DocGia* ThuVien::getDGbyName() {
	std::string name;
	std::cout << "Enter name: ";
	getline(std::cin, name);
	for (auto x : pDG) {
		if (x->isMatchByName(name))
			return x;
	}
	return nullptr;
}
uint16_t ThuVien::getDGsHaveExpDateIn(uint16_t year) {
	uint16_t res = 0;
	for (auto x : pDG) {
		if (x->isMatchByYear(year)) {
			++res;
		}
	}
	return res;
}
