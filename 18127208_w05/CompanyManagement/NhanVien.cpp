#include "NhanVien.h"

NhanVien::NhanVien() {
	id = "";
	fName = "";
	birth = "";
	address = "";
}
NhanVien::NhanVien(std::string id, std::string fName) {
	this->id = id;
	this->fName = fName;
	birth = "";
	address = "";
}
NhanVien::NhanVien(std::string id, std::string fName, std::string birth) {
	this->id = id;
	this->fName = fName;
	this->birth = birth;
	address = "";
}
NhanVien::NhanVien(std::string id, std::string fName, std::string birth, std::string address) {
	this->id = id;
	this->fName = fName;
	this->birth = birth;
	this->address = address;
}
NhanVien::NhanVien(const NhanVien& nv) {
	this->id = nv.id;
	this->fName = nv.fName;
	this->birth = nv.birth;
	this->address = nv.address;
}

bool NhanVien::input() {
	std::cout << "\nID: ";
	getline(std::cin, id);
	std::cout << "Full name: ";
	getline(std::cin, fName);
	std::cout << "Day of birth: ";
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
