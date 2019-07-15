#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

class NhanVien
{
public:
	explicit NhanVien();
	explicit NhanVien(std::string id, std::string fName);
	explicit NhanVien(std::string id, std::string fName, std::string birth);
	explicit NhanVien(std::string id, std::string fName, std::string birth, std::string address);
	explicit NhanVien(const NhanVien& nv);
	virtual ~NhanVien() = default;

	virtual bool input();
	virtual void display();
	virtual uint32_t getSalary() = 0;
	bool isMatchByID(std::string id);
	bool isMatchByName(std::string name);
	bool isMatchByMoB(uint16_t month);
	bool hasSalaryGreaterThan(NhanVien* nv);
	bool hasSalarySmallerThan(uint32_t arg);
	uint16_t getMonthOfBirth();

private:
	std::string id{""};
	std::string fName{""};
	std::string birth{"01/01/1900"};
	std::string address{""};
};

