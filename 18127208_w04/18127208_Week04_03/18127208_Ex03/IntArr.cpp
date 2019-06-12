#include "IntArr.h"


IntArr::IntArr() {
	this->quantity = 0;
	this->arr = nullptr;
}
IntArr::IntArr(int quantity) : IntArr() {
	if (quantity <= 0) {
		return;
	}
	this->quantity = quantity;
	this->arr = new int [quantity];
}
IntArr::IntArr(int arr[], int quantity) : IntArr() {
	if (quantity <= 0) {
		return;
	}
	this->quantity = quantity;
	this->arr = new int [quantity];
	for (unsigned i = 0; i < quantity; ++i) {
		this->arr[i] = arr[i];
	}
}
IntArr::IntArr(const IntArr& iArr) : IntArr() {
	this->quantity = iArr.quantity;
	if (this->quantity == 0 || iArr.arr == nullptr) {
		return;
	}
	this->arr = new int [this->quantity];
	for (unsigned i = 0; i < this->quantity; ++i) {
		this->arr[i] = iArr.arr[i];
	}
}
IntArr::~IntArr() {
	if (this->arr != nullptr) {
		delete this->arr;
		this->arr = nullptr;
	}
}

IntArr& IntArr::operator=(const IntArr& iArr) {
	if (iArr.arr == this->arr) {
		return *this;
	}
	if (iArr.arr != nullptr) {
		this->quantity = iArr.quantity;
		this->arr = new int [this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			this->arr[i] = iArr.arr[i];
		}
	}
}
IntArr::operator int() {
	return this->quantity;
}
int& IntArr::operator[](int index) {
	if (this->quantity < index) {
		std::cout << "Array index out of bound, exiting!";
		exit(0);
	}
	return this->arr[index];
}

std::istream& operator>>(std::istream& in, IntArr& iArr) {
	in >> iArr.quantity;
	if (iArr.quantity == 0) {
		iArr.arr = nullptr;
	}
	for (unsigned i = 0; i < iArr.quantity; ++i) {
		in >> iArr.arr[i];
	}
	return in;
}
std::ostream& operator<<(std::ostream& out, IntArr iArr) {
	out << iArr.quantity;
	for (unsigned i = 0; i < iArr.quantity; ++i) {
		out << "\n" << iArr.arr[i];
	}
	return out;
}

