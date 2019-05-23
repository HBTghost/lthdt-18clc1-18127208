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

	char getGPA();
	std::string getClass();

	bool hasGreaterMark(Student& st);

	friend std::ofstream& operator<<(std::ofstream& out, Student& st);

private:
	std::string id, name, gender, address;
	float mark;
};
