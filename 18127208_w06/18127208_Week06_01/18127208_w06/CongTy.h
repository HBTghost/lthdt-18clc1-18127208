#pragma once
#include <vector>
#include "NhanVien.h"
#include "NhanVienCongNhat.h"
#include "NhanVienSanXuat.h"

class CongTy
{
public:
	CongTy() = default;
	~CongTy();

	bool input();
	void display();
	unsigned long long getSumSalaries();
	NhanVien* getNVbyMaxSalary();
	unsigned getNVSXsQuantity();
	unsigned getNVCNsQuantity();
	unsigned long getAvgSalary();
	void displayNVsHaveSalaryUnder3M();
	NhanVien* getNVbyID();
	NhanVien* getNVbyName();
	unsigned getTheNumberOfNVsByMoB(unsigned MoB);

private:
	std::vector <NhanVien*> pNV;
};

