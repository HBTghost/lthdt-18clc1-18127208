#include "GiaoVien.h"

GiaoVien::GiaoVien() {}
GiaoVien::GiaoVien(std::string id, std::string fName)
	: id{id}, fName{fName} {}

GiaoVien::GiaoVien(std::string id, std::string fName, float coefficient, uint32_t basicSalary)
	: id{id}, fName{fName}, coefficient{coefficient}, basicSalary{basicSalary} {}
GiaoVien::GiaoVien(std::string id, std::string fName, float coefficient, uint32_t basicSalary, uint16_t absentDays)
	: GiaoVien(id, fName, coefficient, basicSalary) {
		this->absentDays = absentDays;
}
GiaoVien::GiaoVien(const GiaoVien& gv) {
	*this = gv;
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
uint64_t GiaoVien::getSalary() {
	return coefficient*basicSalary - absentDays*100000;
}
bool GiaoVien::haveSalaryGreaterThan(GiaoVien* gv) {
	return getSalary() > gv->getSalary();
}
bool GiaoVien::haveSalaryGreaterThan(uint64_t salary) {
	return getSalary() > salary;
}
bool GiaoVien::isMatchByID(std::string id) {
	return this->id == id;
}
bool GiaoVien::isMatchByName(std::string name) {
	return fName == name;
}
bool GiaoVien::absentAbove(uint16_t absents) {
	return absentDays > absents;
}
