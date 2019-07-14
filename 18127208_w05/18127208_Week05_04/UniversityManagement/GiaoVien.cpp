#include "GiaoVien.h"

GiaoVien::GiaoVien() {
	id = "";
	fName = "";
	basicSalary = 0;
	coefficient = 1;
	absentDays = 0;
}
GiaoVien::GiaoVien(std::string id, std::string fName, unsigned basicSalary) {
	this->id = id;
	this->fName = fName;
	this->basicSalary = basicSalary;
	coefficient = 1;
	absentDays = 0;
}
GiaoVien::GiaoVien(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient) {
	this->id = id;
	this->fName = fName;
	this->basicSalary = basicSalary;
	this->coefficient = coefficient;
	absentDays = 0;
}
GiaoVien::GiaoVien(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient, unsigned absentDays) {
	this->id = id;
	this->fName = fName;
	this->basicSalary = basicSalary;
	this->coefficient = coefficient;
	this->absentDays = absentDays;
}
GiaoVien::GiaoVien(const GiaoVien& gv) {
	this->id = gv.id;
	this->fName = gv.fName;
	this->basicSalary = gv.basicSalary;
	this->coefficient = gv.coefficient;
	this->absentDays = gv.absentDays;
}

bool GiaoVien::input() {
	std::cout << "\nID: ";
	getline(std::cin, id);
	std::cout << "Full name: ";
	getline(std::cin, fName);
	std::cout << "Basic salary: ";
	std::cin >> basicSalary;
	std::cout << "Coefficients salary: ";
	std::cin >> coefficient;
	std::cout << "Absent days: ";
	std::cin >> absentDays;
	return true;
}
void GiaoVien::display() {
	std::cout << "\nID: " << id;
	std::cout << "\nFull name: " << fName;
	std::cout << "\nBasic salary: " << basicSalary;
	std::cout << "\nCoefficients salary: " << coefficient;
	std::cout << "\nAbsent days: " << absentDays;
}
unsigned long GiaoVien::getSalary() {
	return coefficient*basicSalary - absentDays*100000;
}