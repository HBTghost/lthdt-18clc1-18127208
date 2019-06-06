#include "StudentArr.h"

StudentArr::StudentArr() {
	this->quantity = 0;
	this->arr = nullptr;
}
StudentArr::StudentArr(std::string fileName) : StudentArr() {
	std::ifstream filein;
	filein.open(fileName);
	if (filein.is_open()) {
		filein >> this->quantity;
		std::string temp;
		getline(filein, temp);
		this->arr = new Student[this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			filein >> this->arr[i];
		}
		filein.close();
	}	
}
StudentArr::StudentArr(const StudentArr& pArr) {
	this->quantity = pArr.quantity;
	if (pArr.arr != nullptr) {
		this->arr = new Student [this->quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			this->arr[i] = pArr.arr[i];
		}
	}
}
StudentArr::~StudentArr() {
	if (this->arr != nullptr) {
		delete[] this->arr;
		this->arr = nullptr;
	}
}

void StudentArr::sortLNameAsc() {
	for (unsigned i = 0; i < this->quantity - 1; ++i) {
		for (unsigned j = i + 1; j < this->quantity; ++j) {
			if (this->arr[i].isLNameGreater(this->arr[j])) {
				swap(this->arr[i], this->arr[j]);
			}
		}
	}
}

std::ofstream& operator<<(std::ofstream& out, StudentArr& sArr) {
	out << sArr.quantity;
	for (unsigned i = 0; i < sArr.quantity; ++i) {
		out << "\n";
		out << sArr.arr[i];
	}
	return out;
}
