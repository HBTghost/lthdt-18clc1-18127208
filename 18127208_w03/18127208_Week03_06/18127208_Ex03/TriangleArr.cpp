#include "TriangleArr.h"

TriangleArr::TriangleArr() {
	this->quantity = 0;
	this->arr = nullptr;
}
TriangleArr::TriangleArr(std::string fileName) : TriangleArr() {
	std::ifstream filein;
	filein.open(fileName);
	if (filein.is_open()) {
		filein >> this->quantity;
		this->arr = new Triangle[this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			filein >> this->arr[i];
		}
		filein.close();
	}	
}
TriangleArr::TriangleArr(const TriangleArr& tArr) {
	this->quantity = tArr.quantity;
	if (tArr.arr != nullptr) {
		this->arr = new Triangle [this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			this->arr[i] = tArr.arr[i];
		}
	}
}
TriangleArr::~TriangleArr() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

int TriangleArr::getQuantity() {
	return this->quantity;
}
int TriangleArr::getTheNumberOfValids() {
	int valids = 0;
	for (unsigned i = 0; i < this->quantity; ++i) {
		if (this->arr[i].isValid())
			++valids;
	}
	return valids;
}	

void TriangleArr::deleteInvalids() {
	Triangle* newArr = new Triangle[getTheNumberOfValids()];
	for (unsigned i = 0, j = 0; i < this->quantity; ++i) {
		if (this->arr[i].isValid()) {
			newArr[j++] = arr[i];
		}
	}
	delete[] this->arr;
	this->arr = newArr;
	this->quantity = getTheNumberOfValids();
}

void TriangleArr::showTypes() {
	int type[6] = {0};
	for (unsigned i = 0; i < this->quantity; ++i) {
		type[this->arr[i].getIndexType()]++;
	}
	for (unsigned i = 0; i < 6; ++i) {
		std::cout << getTypeByIndex(i) << " triangle: " << type[i] << "\n";
	}
}
