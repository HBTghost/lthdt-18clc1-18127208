#pragma once
#include "Student.h"

class StudentArr
{
public:
	StudentArr();
	StudentArr(std::string fileName);
	StudentArr(const StudentArr& pArr);
	~StudentArr();

	void sortLNameAsc();

	friend std::ofstream& operator<<(std::ofstream& out, StudentArr& sArr);

private:
	int quantity;
	Student* arr;
};

