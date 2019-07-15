#pragma once
#include "GiaoVien.h"
#include "Counter.h"

class GiaoVienCN : public GiaoVien, private Counter<GiaoVienCN>
{
public:
	template<typename... Args>
	GiaoVienCN(Args... args) : GiaoVien(std::forward<Args>(args)...) {} // 6 overload 
	~GiaoVienCN() = default;

	bool input() override;
	void display() override;
	uint64_t getSalary() override;
	using Counter<GiaoVienCN>::GetCount;

private:
	const uint32_t allowance = 500000;
};

