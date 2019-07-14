#pragma once
#include "DocGia.h"

class DocGiaThuong : public DocGia
{
public:
	DocGiaThuong();
	DocGiaThuong(const DocGia& reader);
	DocGiaThuong(unsigned books);
	DocGiaThuong(const DocGia& reader, unsigned books);
	DocGiaThuong(const DocGiaThuong& basicReader);
	~DocGiaThuong() = default;

	bool input();
	void display();
	unsigned long getMonthPrice();

private:
	unsigned borrowBooks;
	const unsigned priceBorrowedOne = 5000;
};

