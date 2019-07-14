#pragma once
#include "NhanVien.h"
#include "Counter.h"

class NhanVienSanXuat : public NhanVien, private Counter<NhanVienSanXuat>
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
	using Counter<NhanVienSanXuat>::GetCount;

private:
	unsigned produces;
	const unsigned coefficient = 20000;
};

