#include "DocGiaVip.h"

DocGiaVip::DocGiaVip() : DocGia() {}
DocGiaVip::DocGiaVip(std::string id, std::string fName) : DocGia(id, fName) {}
DocGiaVip::DocGiaVip(std::string id, std::string fName, std::string expDate) : DocGia(id, fName, expDate) {}
DocGiaVip::DocGiaVip(const DocGia& reader) : DocGia(reader) {}
DocGiaVip::DocGiaVip(const DocGiaVip& vipReader) : DocGia(vipReader) {}

bool DocGiaVip::input() {
	DocGia::input();
	return true;
}
void DocGiaVip::display() {
	DocGia::display();
}
unsigned long DocGiaVip::getMonthPrice() {
	return pricePerMonth;
}
