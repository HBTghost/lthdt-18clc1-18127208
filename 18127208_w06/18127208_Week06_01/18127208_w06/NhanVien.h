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

	bool isMatchByID(std::string id);
	bool isMatchByName(std::string name);
	bool isMatchByMoB(unsigned month);
	unsigned getMonthOfBirth();

	virtual bool input();
	virtual void display();
	virtual unsigned long getSalary() = 0;

private:
	std::string id;
	std::string fName;
	std::string birth;
	std::string address;
};

