#pragma once
#include "NhanVien.h"
#include "Counter.h"

class NhanVienCongNhat : public NhanVien, private Counter<NhanVienCongNhat>
{
public:
	template<typename... Args>
	NhanVienCongNhat(uint16_t days = 0, Args... args)
		: days{days}, NhanVien(std::forward<Args>(args)...) {} // 12 overload
	~NhanVienCongNhat() = default;

	bool input() override;
	void display() override;
	uint32_t getSalary() override;
	using Counter<NhanVienCongNhat>::GetCount;

private:
	uint16_t days;
	const uint16_t coefficient = 300000;
};

