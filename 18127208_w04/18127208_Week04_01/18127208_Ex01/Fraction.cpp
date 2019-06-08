#include "Fraction.h"

Fraction::Fraction() {
	this->nu = 0;
	this->de = 1;
}
Fraction::Fraction(int nu, int de) {
	this->nu = nu;
	this->de = de;
}
Fraction::Fraction(const Fraction& fr) {
	this->nu = fr.nu;
	this->de = fr.de;
}
Fraction::~Fraction() {}

Fraction::operator float() {
	return this->nu * 1.0 / this->de;
}

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

Fraction& Fraction::operator=(const Fraction& fr) {
	this->nu = fr.nu;
	this->de = fr.de;
	return *this;
}

Fraction& Fraction::operator++() {
	*this = *this + 1;
	return *this;
}
Fraction Fraction::operator++(int) {
	Fraction temp(*this);
	++(*this);
	return temp;
}
Fraction& Fraction::operator--() {
	*this = *this - 1;
	return *this;
}
Fraction Fraction::operator--(int) {
	Fraction temp(*this);
	--(*this);
	return temp;
}

Fraction& Fraction::operator+=(const Fraction& fr) {
	this->nu = this->nu*fr.de + fr.nu*this->de;
	this->de = this->de * fr.de;
	return *this;
}
Fraction& Fraction::operator-=(const Fraction& fr) {
	this->nu = this->nu*fr.de - fr.nu*this->de;
	this->de = this->de * fr.de;
	return *this;
}
Fraction& Fraction::operator*=(const Fraction& fr) {
	this->nu = this->nu*fr.nu;
	this->de = this->de * fr.de;
	return *this;
}
Fraction& Fraction::operator/=(const Fraction& fr) {
	if (!fr.nu) {
		throw std::invalid_argument("The second fraction is zero");
	}
	this->nu = this->nu*fr.de;
	this->de = this->de * fr.nu;
	return *this;
}

Fraction operator+(Fraction a, Fraction b) {
	a += b;
	return a;
}
Fraction operator-(Fraction a, Fraction b) {
	a -= b;
	return a;
}
Fraction operator*(Fraction a, Fraction b) {
	a *= b;
	return a;
}
Fraction operator/(Fraction a, Fraction b) {
	a /= b;
	return a;
}

Fraction operator+(Fraction fr, int num) {
	Fraction temp(num, 1);
	return fr + temp;
}
Fraction operator-(Fraction fr, int num) {
	Fraction temp(num, 1);
	return fr - temp;
}
Fraction operator+(int num, Fraction& fr) {
	Fraction temp(num, 1);
	return temp + fr;
}
Fraction operator*(int num, Fraction& fr) {
	Fraction temp(num, 1);
	return temp * fr;
}

bool operator==(Fraction& a, Fraction& b) {
	return (a.getVal()) == (b.getVal());
}
bool operator!=(Fraction& a, Fraction& b) {
	return (a.getVal()) != (b.getVal());
}
bool operator>(Fraction& a, Fraction& b) {
	return (a.getVal()) > (b.getVal());
}
bool operator>=(Fraction& a, Fraction& b) {
	return (a.getVal()) >= (b.getVal());
}
bool operator<(Fraction& a, Fraction& b) {
	return (a.getVal()) < (b.getVal());
}
bool operator<=(Fraction& a, Fraction& b) {
	return (a.getVal()) <= (b.getVal());
}

std::ifstream& operator>>(std::ifstream& in, Fraction& fr) {
	int nu, de;
	in >> nu;
	in >> de;
	fr.input(nu, de);
	return in;
}
std::ostream& operator<<(std::ostream& out, Fraction fr) {
	if (fr.nu == 0) {
		out << 0;
	}
	else if (fr.de == 1)  {
		out << fr.nu;
	}
	else {
		out << fr.nu << "/" << fr.de;
	}
	return out;
}

void swap(Fraction& a, Fraction& b) {
	Fraction c;
	c = a;
	a = b;
	b = c;
}
