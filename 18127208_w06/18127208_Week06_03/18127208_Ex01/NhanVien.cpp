#include "NhanVien.h"

NhanVien::NhanVien() {}
NhanVien::NhanVien(std::string id, std::string fName)
	: id{id}, fName{fName} {}
NhanVien::NhanVien(std::string id, std::string fName, std::string birth)
	: id{id}, fName{fName}, birth{birth} {}
NhanVien::NhanVien(std::string id, std::string fName, std::string birth, std::string address)
	: id{id}, fName{fName}, birth{birth}, address{address} {}
NhanVien::NhanVien(const NhanVien& nv) {
	*this = nv;
}

bool NhanVien::isMatchByID(std::string id) {
	return this->id == id;
}
bool NhanVien::isMatchByName(std::string name) {
	return fName == name;
}
bool NhanVien::isMatchByMoB(uint16_t month) {
	return month == getMonthOfBirth();
}
bool NhanVien::hasSalaryGreaterThan(NhanVien* nv) {
	return getSalary() > nv->getSalary();
}
bool NhanVien::hasSalarySmallerThan(uint32_t arg) {
	return getSalary() < arg;
}
uint16_t NhanVien::getMonthOfBirth() {
	return std::stoi(birth.substr(3, 2));
}

bool NhanVien::input() {
	std::cout << "\nID: ";
	getline(std::cin, id);
	std::cout << "Full name: ";
	getline(std::cin, fName);
	std::cout << "Day of birth (dd/mm/yyyy): ";
	getline(std::cin, birth);
	std::cout << "Address: ";
	getline(std::cin, address);
	return true;
}
void NhanVien::display() {
	std::cout << "\nID: " << id;
	std::cout << "\nFull name: " << fName;
	std::cout << "\nDay of birth: " << birth;
	std::cout << "\nAddress: " << address;
}
