#pragma once
#include "NhanVien.h"
#include "Counter.h"

class NhanVienSanXuat : public NhanVien, private Counter<NhanVienSanXuat>
{
public:
	template<typename... Args>
	NhanVienSanXuat(uint16_t produces = 0, Args... args)
		: produces{produces}, NhanVien(std::forward<Args>(args)...) {}
	~NhanVienSanXuat() = default;

	bool input() override;
	void display() override;
	uint32_t getSalary() override;
	using Counter<NhanVienSanXuat>::GetCount;

private:
	uint16_t produces;
	const uint16_t coefficient = 20000;
};

