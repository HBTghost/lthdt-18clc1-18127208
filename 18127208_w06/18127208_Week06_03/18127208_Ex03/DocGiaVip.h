#pragma once
#include "DocGia.h"
#include "Counter.h"

class DocGiaVip : public DocGia, private Counter<DocGiaVip>
{
public:
	template<typename... Args>
	DocGiaVip(Args... args) : DocGia(std::forward<Args>(args)...) {} // 6 overload
	~DocGiaVip() = default;

	bool input() override;
	void display() override;
	uint32_t getMonthFee() override;
	using Counter<DocGiaVip>::GetCount;

private:
	const uint16_t feePerMonth = 50000;
};

