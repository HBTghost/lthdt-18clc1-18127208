#include "DocGia.h"

DocGia::DocGia() {}
DocGia::DocGia(std::string id, std::string fName)
	: id{id}, fName{fName} {}
DocGia::DocGia(std::string id, std::string fName, std::string expDate)
	: id{id}, fName{fName}, expDate{expDate} {}
DocGia::DocGia(std::string id, std::string fName, std::string expDate, std::string gender)
	: id{id}, fName{fName}, expDate{expDate}, gender{gender} {}
DocGia::DocGia(const DocGia& reader) {
	*this = reader;
}

bool DocGia::haveFeeGreaterThan(DocGia* dg) {
	return getMonthFee() > dg->getMonthFee();
}
bool DocGia::haveFeeGreaterThan(uint32_t fee) {
	return getMonthFee() > fee;
}
bool DocGia::isMatchByID(std::string id) {
	return this->id.compare(id) == 0;
}
bool DocGia::isMatchByName(std::string name) {
	return fName.compare(name) == 0;
}
bool DocGia::isMatchByYear(uint16_t year) {
	return year == getExpYear();
}
uint16_t DocGia::getExpYear() {
	return std::stoi(expDate.substr(6, 4));
}

bool DocGia::input() {
	std::cout << "\nID: ";
	getline(std::cin, id);
	std::cout << "Full name: ";
	getline(std::cin, fName);
	std::cout << "Expirition date (dd/mm/yyyy): ";
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
