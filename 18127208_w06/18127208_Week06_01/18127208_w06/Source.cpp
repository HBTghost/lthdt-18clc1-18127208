#include "CongTy.h"

int main(int argc, char const *argv[])
{
	CongTy company;

	std::cout << "Input:\n";
	company.input();
	std::cout << "\nDisplay:";
	company.display();

	std::cout << "\n\nTong tien luong cua tat ca nhan vien: " << company.getSumSalaries();

	std::cout << "\n\nNhan vien co luong cao nhat:\n";
	company.getNVbyMaxSalary()->display();

	std::cout << "\n\nSo luong nhan vien San Xuat: " << company.getNVSXsQuantity();

	std::cout << "\n\nSo luong nhan vien Cong Nhat: " << company.getNVCNsQuantity();

	std::cout << "\n\nLuong trung binh trong cong ty: " << company.getAvgSalary();

	std::cout << "\n\nLiet ke cac nhan vien co luong thap hon 3.000.000:\n";
	company.displayNVsHaveSalaryUnder3M();

	std::cout << "\n\nNhap vao ma, tim nhan vien tuong ung:\n";
	NhanVien* nv;
	if ((nv = company.getNVbyID()) != nullptr) {
		nv->display();
	}

	std::cout << "\n\nNhap vao ten, tim nhan vien tuong ung:\n";
	if ((nv = company.getNVbyName()) != nullptr) {
		nv->display();
	}

	std::cout << "\n\nSo luong nhan vien sinh trong thang 5: ";
	std::cout << company.getTheNumberOfNVsByMoB(5) << "\n";
	
	return 0;
}