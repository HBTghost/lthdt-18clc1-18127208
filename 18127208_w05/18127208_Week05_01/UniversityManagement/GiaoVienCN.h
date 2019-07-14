#pragma once
#include "GiaoVien.h"

class GiaoVienCN : public GiaoVien
{
public:
	GiaoVienCN();
	GiaoVienCN(std::string id, std::string fName, unsigned basicSalary);
	GiaoVienCN(std::string id, std::string fName, unsigned basicSalary, unsigned coefficient);
	GiaoVienCN(const GiaoVien& gv);
	GiaoVienCN(const GiaoVienCN& gvcn);
	~GiaoVienCN() = default;

	bool input();
	void display();
	unsigned long getSalary();

private:
	const unsigned allowance = 500000;
};

