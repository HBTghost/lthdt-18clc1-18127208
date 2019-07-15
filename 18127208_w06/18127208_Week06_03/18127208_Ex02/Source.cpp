#include "TruongHoc.h"

int main(int argc, char const *argv[])
{
	TruongHoc school;

	std::cout << "Input:\n";
	school.input();
	if (school.isValid()) {
		std::cout << "\nDisplay:";
		school.display();

		std::cout << "\n\nTong tien luong cua tat ca giao vien: " << school.getSumSalaries();

		std::cout << "\n\nGiao vien co luong cao nhat:\n";
		school.getGVbyMaxSalary()->display();

		std::cout << "\n\nSo luong giao vien: " << school.getGVsQuantity();

		std::cout << "\n\nSo luong giao vien chu nhiem: " << school.getGVCNsQuantity();

		std::cout << "\n\nLuong trung binh trong truong: " << school.getAvgSalary();

		std::cout << "\n\nLiet ke cac giao vien co luong cao hon 10.000.000:\n";
		school.displayGVsHaveSalaryAbove(10000000);

		std::cout << "\n\nNhap vao ma, tim giao vien tuong ung:\n";
		GiaoVien* gv;
		if ((gv = school.getGVbyID()) != nullptr) {
			gv->display();
		}

		std::cout << "\n\nNhap vao ten, tim giao vien tuong ung:\n";
		if ((gv = school.getGVbyName()) != nullptr) {
			gv->display();
		}

		std::cout << "\n\nSo luong giao vien sinh nghi qua 4 ngay trong thang: ";
		std::cout << school.getGVsQuantityAbsentAbove(4) << "\n";
	}
	
	return 0;
}