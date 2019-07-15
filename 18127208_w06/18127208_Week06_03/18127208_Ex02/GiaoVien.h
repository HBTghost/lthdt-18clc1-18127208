#pragma once
#include <iostream>
#include <string>
#include <stdint.h>

class GiaoVien
{
public:
	explicit GiaoVien();
	explicit GiaoVien(std::string id, std::string fName);
	explicit GiaoVien(std::string id, std::string fName, float coefficient, uint32_t basicSalary);
	explicit GiaoVien(std::string id, std::string fName, float coefficient, uint32_t basicSalary, uint16_t absentDays);
	explicit GiaoVien(const GiaoVien& gv);
	virtual ~GiaoVien() = default;

	virtual bool input();
	virtual void display();
	virtual uint64_t getSalary();
	bool haveSalaryGreaterThan(GiaoVien* gv);
	bool haveSalaryGreaterThan(uint64_t salary);
	bool isMatchByID(std::string id);
	bool isMatchByName(std::string name);
	bool absentAbove(uint16_t absents);

private:
	std::string id{""};
	std::string fName{""};
	float coefficient{1};
	uint32_t basicSalary{0};
	uint16_t absentDays{0};
};

