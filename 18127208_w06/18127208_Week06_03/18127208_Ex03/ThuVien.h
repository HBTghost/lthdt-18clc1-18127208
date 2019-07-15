#pragma once
#include <vector>
#include "DocGia.h"
#include "DocGiaThuong.h"
#include "DocGiaVip.h"

class ThuVien
{
public:
	ThuVien() = default;
	~ThuVien();
	bool isValid();

	bool input();
	void display();
	uint64_t getSumFee();
	DocGia* getDGbyMaxFee();
	uint16_t getDGTsQuantity();
	uint16_t getDGVsQuantity();
	uint32_t getAvgFee();
	void displayDGsHaveFeeAbove(uint32_t fee);
	DocGia* getDGbyID();
	DocGia* getDGbyName();
	uint16_t getDGsHaveExpDateIn(uint16_t year);

private:
	std::vector <DocGia*> pDG;
};

