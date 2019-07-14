#pragma once
#include "NhanVien.h"

class NhanVienCongNhat : public NhanVien
{
public:
	NhanVienCongNhat();
	NhanVienCongNhat(const NhanVien& nv);
	NhanVienCongNhat(unsigned days);
	NhanVienCongNhat(const NhanVien& nv, unsigned days);
	NhanVienCongNhat(const NhanVienCongNhat& nvcn);
	~NhanVienCongNhat() = default;

	bool input();
	void display();
	unsigned long getSalary();
	
private:
	unsigned days;
	const unsigned coefficient = 300000;
};

