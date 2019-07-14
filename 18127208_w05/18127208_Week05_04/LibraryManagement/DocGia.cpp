#include "DocGia.h"

DocGia::DocGia() {
	id = "";
	fName = "";
	expDate = "01/01/0001";
	gender = "";
}
DocGia::DocGia(std::string id, std::string fName) {
	this->id = id;
	this->fName = fName;
	expDate = "01/01/0001";
	gender = "";
}
DocGia::DocGia(std::string id, std::string fName, std::string expDate) {
	this->id = id;
	this->fName = fName;
	this->expDate = expDate;
	gender = "";
}
DocGia::DocGia(std::string id, std::string fName, std::string expDate, std::string gender) {
	this->id = id;
	this->fName = fName;
	this->expDate = expDate;
	this->gender = gender;
}
DocGia::DocGia(const DocGia& reader) {
	this->id = reader.id;
	this->fName = reader.fName;
	this->expDate = reader.expDate;
	this->gender = reader.gender;
}

bool DocGia::input() {
	std::cout << "\nID: ";
	getline(std::cin, id);
	std::cout << "Full name: ";
	getline(std::cin, fName);
	std::cout << "Expirition date: ";
	getline(std::cin, expDate);
	std::cout << "Gender: ";
	getline(std::cin, gender);
	return true;
}
void DocGia::display() {
	std::cout << "\nID: " << id;
	std::cout << "\nFull name: " << fName;
	std::cout << "\nExpirition date: " << expDate;
	std::cout << "\nGender: " << gender;
}