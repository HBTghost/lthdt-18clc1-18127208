#pragma once
#include <iostream>
#include <string>
#include <fstream>

class Student
{
public:
	Student();
	~Student();

	void input();

	bool isLNameGreater(Student& st);

	friend std::ofstream& operator<<(std::ofstream& out, Student& st);
	friend std::ifstream& operator>>(std::ifstream& in, Student& st);

private:
	std::string id, FName, LName, address, DoB;
	float mark;
};

void swap(Student& a, Student& b);
void sortLNameAsc(Student* arr, int n);