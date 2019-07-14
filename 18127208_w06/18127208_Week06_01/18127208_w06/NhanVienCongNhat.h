#pragma once
#include "NhanVien.h"
#include "Counter.h"

class NhanVienCongNhat : public NhanVien, private Counter<NhanVienCongNhat>
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
	using Counter<NhanVienCongNhat>::GetCount;

private:
	unsigned days;
	const unsigned coefficient = 300000;
};

