#pragma once
#include "DocGia.h"

class DocGiaVip : public DocGia
{
public:
	DocGiaVip();
	DocGiaVip(std::string id, std::string fName);
	DocGiaVip(std::string id, std::string fName, std::string expDate);
	DocGiaVip(const DocGia& reader);
	DocGiaVip(const DocGiaVip& vipReader);
	~DocGiaVip() = default;

	bool input();
	void display();
	unsigned long getMonthPrice();

private:
	const unsigned pricePerMonth = 50000;
};

