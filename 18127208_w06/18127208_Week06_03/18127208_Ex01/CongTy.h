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
	bool isValid();

	bool input();
	void display();
	uint64_t getSumSalaries();
	NhanVien* getNVbyMaxSalary();
	uint16_t getNVSXsQuantity();
	uint16_t getNVCNsQuantity();
	uint32_t getAvgSalary();
	void displayNVsHaveSalaryUnder(uint32_t arg);
	NhanVien* getNVbyID();
	NhanVien* getNVbyName();
	uint16_t getTheNumberOfNVsByMoB(uint16_t MoB);

private:
	std::vector <NhanVien*> pNV;
};

