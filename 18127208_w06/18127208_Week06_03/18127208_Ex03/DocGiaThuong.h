#pragma once
#include "DocGia.h"
#include "Counter.h"

class DocGiaThuong : public DocGia, private Counter<DocGiaThuong>
{
public:
	template<typename... Args>
	DocGiaThuong(uint16_t books = 0, Args... args) : borrowBooks{books}, DocGia(std::forward<Args>(args)...) {} // 8 overload
	~DocGiaThuong() = default;

	bool input() override;
	void display() override;
	uint32_t getMonthFee() override;
	using Counter<DocGiaThuong>::GetCount;

private:
	uint16_t borrowBooks;
	const uint16_t priceBorrowedOne = 5000;
};

