#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

class DocGia
{
public:
	explicit DocGia();
	explicit DocGia(std::string id, std::string fName);
	explicit DocGia(std::string id, std::string fName, std::string expDate);
	explicit DocGia(std::string id, std::string fName, std::string expDate, std::string gender);
	explicit DocGia(const DocGia& reader);
	virtual ~DocGia() = default;

	virtual bool input();
	virtual void display();
	virtual uint32_t getMonthFee() = 0;
	bool haveFeeGreaterThan(DocGia* dg);
	bool haveFeeGreaterThan(uint32_t fee);
	bool isMatchByID(std::string id);
	bool isMatchByName(std::string name);
	bool isMatchByYear(uint16_t year);
	uint16_t getExpYear();


private:
	std::string id{""};
	std::string fName{""};
	std::string expDate{"01/01/1990"};
	std::string gender{""};
};

