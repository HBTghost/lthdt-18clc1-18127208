#pragma once
#include <iostream>
#include <string>

class NhanVien
{
public:
	NhanVien();
	NhanVien(std::string id, std::string fName);
	NhanVien(std::string id, std::string fName, std::string birth);
	NhanVien(std::string id, std::string fName, std::string birth, std::string address);
	NhanVien(const NhanVien& nv);
	~NhanVien() = default;

	bool input();
	void display();

private:
	std::string id;
	std::string fName;
	std::string birth;
	std::string address;
};

