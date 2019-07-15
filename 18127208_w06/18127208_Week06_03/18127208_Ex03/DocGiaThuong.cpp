#include "DocGiaThuong.h"

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
uint32_t DocGiaThuong::getMonthFee() {
	return borrowBooks * priceBorrowedOne;
}
