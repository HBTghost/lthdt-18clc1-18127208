#include "FractionArr.h"

FractionArr::FractionArr() {
	this->arr = nullptr;
	this->quantity = 0;
}
FractionArr::FractionArr(std::string fileName) {
	std::ifstream filein;
	filein.open(fileName);
	if (filein.is_open()) {
		filein >> this->quantity;
		this->arr = new Fraction [quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			filein >> this->arr[i];
		}
		filein.close();
	}
}
FractionArr::FractionArr(const FractionArr& frArr) {
	this->arr = new Fraction [frArr.quantity];
	this->quantity = frArr.quantity;
	for (unsigned i = 0; i < frArr.quantity; ++i) {
		this->arr[i] = frArr.arr[i];
	}
}
FractionArr::~FractionArr() {
	if (this->arr != nullptr)
		delete[] this->arr;
}

float FractionArr::getSum() {
	float sum = 0.0;
	for (unsigned i = 0; i < this->quantity; ++i) {
		sum += this->arr[i].getVal();
	}
	return sum;
}

void FractionArr::ascSort() {
	for (unsigned i = 0; i < this->quantity - 1; ++i) {
		for (unsigned j = i + 1; j < this->quantity; ++j) {
			if (this->arr[i] > this->arr[j])
				swap(this->arr[i], this->arr[j]);
		}
	}
}

void FractionArr::input(std::string fileName) {
	std::ifstream filein;
	filein.open(fileName);
	if (filein.is_open()) {
		filein >> this->quantity;
		this->arr = new Fraction [quantity];
		for (unsigned i = 0; i < this->quantity; ++i) {
			filein >> this->arr[i];
		}
		filein.close();
	}
}

void FractionArr::display() {
	std::cout << "Sum of them: " << getSum();
	std::cout << "\nMax: " << this->arr[this->quantity-1];
	std::cout << "\nMin: " << this->arr[0];
	std::cout << "\nSort Ascending order:";
	for (unsigned i = 0; i < this->quantity; ++i) {
		std::cout << "\n" << this->arr[i];
	}
}
