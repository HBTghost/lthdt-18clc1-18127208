#pragma once
#include <vector>
#include "GiaoVien.h"
#include "GiaoVienCN.h"

class TruongHoc
{
public:
	TruongHoc() = default;
	~TruongHoc();
	bool isValid();

	bool input();
	void display();
	uint64_t getSumSalaries();
	GiaoVien* getGVbyMaxSalary();
	uint16_t getGVsQuantity();
	uint16_t getGVCNsQuantity();
	uint32_t getAvgSalary();
	void displayGVsHaveSalaryAbove(uint32_t arg);
	GiaoVien* getGVbyID();
	GiaoVien* getGVbyName();
	uint16_t getGVsQuantityAbsentAbove(uint16_t);

private:
	std::vector <GiaoVien*> pGV;
};

