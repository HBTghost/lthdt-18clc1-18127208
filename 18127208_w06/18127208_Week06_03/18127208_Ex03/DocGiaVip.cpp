#include "DocGiaVip.h"

bool DocGiaVip::input() {
	DocGia::input();
	return true;
}
void DocGiaVip::display() {
	DocGia::display();
}
uint32_t DocGiaVip::getMonthFee() {
	return feePerMonth;
}
