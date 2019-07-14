#pragma once
#include "NhanVien.h"

class NhanVienSanXuat : public NhanVien
{
public:
	NhanVienSanXuat();
	NhanVienSanXuat(const NhanVien& nv);
	NhanVienSanXuat(unsigned produces);
	NhanVienSanXuat(const NhanVien& nv, unsigned produces);
	NhanVienSanXuat(const NhanVienSanXuat& nvss);
	~NhanVienSanXuat() = default;

	bool input();
	void display();
	unsigned long getSalary();

private:
	unsigned produces;
	const int coefficient = 20000;
};

