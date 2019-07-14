#include "DocGiaThuong.h"

DocGiaThuong::DocGiaThuong() : DocGia()  {
	borrowBooks = 0;
}
DocGiaThuong::DocGiaThuong(const DocGia& reader) : DocGia(reader) {
	borrowBooks = 0;
}
DocGiaThuong::DocGiaThuong(unsigned books) : DocGia() {
	this->borrowBooks = books;
}
DocGiaThuong::DocGiaThuong(const DocGia& reader, unsigned books) : DocGia(reader) {
	this->borrowBooks = books;
}
DocGiaThuong::DocGiaThuong(const DocGiaThuong& basicReader) : DocGia(basicReader)  {
	this->borrowBooks = basicReader.borrowBooks;
}

bool DocGiaThuong::input() {
	DocGia::input();
	std::cout << "The number of borrowed books: ";
	std::cin >> borrowBooks;
	return true;
}
void DocGiaThuong::display() {
	DocGia::display();
	std::cout << "\nThe number of borrowed books: " << borrowBooks;
}
unsigned long DocGiaThuong::getMonthPrice() {
	return borrowBooks * priceBorrowedOne;
}
