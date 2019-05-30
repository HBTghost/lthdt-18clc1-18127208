#include "Fraction.h"

Fraction::Fraction() {
	this->nu = 0;
	this->de = 1;
}
Fraction::~Fraction() {}

void Fraction::input() {
	std::cout << "Numerator: ";
	std::cin >> this->nu;
	std::cout << "Demominator: ";
	std::cin >> this->de;
}
bool Fraction::input(int nu, int de) {
	if (!de) {
		return false;
	}
	this->nu = nu;
	this->de = de;
	return true;
}

void Fraction::reduce() {
	for (int i = this->de * this->nu; i > 1; i--) {
		if ((this->de % i == 0) && (this->nu % i == 0)) {
			this->de /= i;
			this->nu /= i;
		}
	}
}

int Fraction::getNu() {
	return this->nu;
}
int Fraction::getDe() {
	return this->de;
}
float Fraction::getVal() {
	return (this->nu * 1.0) / this->de;
}

Fraction& Fraction::operator+(Fraction& fr) {
	Fraction temp;
	int nu = this->nu * fr.getDe() + this->de * fr.getNu();
	int de = this->de * fr.getDe();
	temp.input(nu, de);
	return temp;
}

bool operator>(Fraction& a, Fraction& b) {
	return (a.getVal()) > (b.getVal());
}
bool operator<(Fraction & a, Fraction & b) {
	return (a.getVal()) < (b.getVal());
}
std::ostream & operator<<(std::ostream& out, Fraction& fr) {
	fr.reduce();
	out << fr.nu << "/" << fr.de;
	return out;
}
std::ifstream& operator>>(std::ifstream& in, Fraction& fr) {
	int nu, de;
	in >> nu;
	in >> de;
	fr.input(nu, de);
	return in;
}

float sum(Fraction* arr, int n) {
	float sum = 0.0;
	for (unsigned i = 0; i < n; ++i) {
		sum += arr[i].getVal();
	}
	return sum;
}

void swap(Fraction& a, Fraction& b) {
	Fraction c;
	c = a;
	a = b;
	b = c;
}
void ascSort(Fraction* arr, int n) {
	for (unsigned i = 0; i < n - 1; ++i) {
		for (unsigned j = i + 1; j < n; ++j) {
			if (arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
	}
}