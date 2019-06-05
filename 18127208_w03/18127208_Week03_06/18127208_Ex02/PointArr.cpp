#include "PointArr.h"

PointArr::PointArr() {
	this->quantity = 0;
	this->arr = nullptr;
}
PointArr::PointArr(std::string fileName) : PointArr() {
	std::ifstream filein;
	filein.open(fileName);
	if (filein.is_open()) {
		filein >> this->quantity;
		this->arr = new Point[this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			filein >> this->arr[i];
		}
		filein.close();
	}	
}
PointArr::PointArr(const PointArr& pArr) {
	this->quantity = pArr.quantity;
	if (pArr.arr != nullptr) {
		this->arr = new Point [this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			this->arr[i] = pArr.arr[i];
		}
	}
}
PointArr::~PointArr() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

Point& PointArr::MaxDistanceToP(Point& p) {
	int iMax = 0;
	for (unsigned i = 0; i < this->quantity; ++i) {
		if (this->arr[iMax].to(p) < this->arr[i].to(p)) {
			iMax = i;
		}
	}
	return this->arr[iMax];
}