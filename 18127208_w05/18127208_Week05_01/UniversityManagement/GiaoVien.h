#pragma once
#include <iostream>
#include <string>

class GiaoVien
{
public:
	GiaoVien();
	GiaoVien(std::string id, std::string fName, unsigned basicSalary);
	GiaoVien(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient);
	GiaoVien(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient, unsigned absentDays);
	GiaoVien(const GiaoVien& gv);
	~GiaoVien() = default;

	bool input();
	void display();
	virtual unsigned long getSalary();

private:
	std::string id;
	std::string fName;
	unsigned basicSalary;
	unsigned coefficient;
	unsigned absentDays;
};

