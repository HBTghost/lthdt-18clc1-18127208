#pragma once
#include <iostream>
#include <string>

class DocGia
{
public:
	DocGia();
	DocGia(std::string id, std::string fName);
	DocGia(std::string id, std::string fName, std::string expDate);
	DocGia(std::string id, std::string fName, std::string expDate, std::string gender);
	DocGia(const DocGia& reader);
	~DocGia() = default;

	bool input();
	void display();
	virtual unsigned long getMonthPrice() = 0;

private:
	std::string id;
	std::string fName;
	std::string expDate;
	std::string gender;
};

