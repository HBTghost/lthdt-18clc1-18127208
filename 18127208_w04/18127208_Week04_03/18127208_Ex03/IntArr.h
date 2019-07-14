#pragma once
#include <iostream>

class IntArr
{
public:
	IntArr();
	IntArr(int quantity);
	IntArr(int arr[], int quantity);
	IntArr(const IntArr& iArr);
	~IntArr();

	IntArr& operator=(IntArr iArr);
	operator int();
	int& operator[](int index);

	friend std::istream& operator>>(std::istream& in, IntArr& iArr);
	friend std::ostream& operator<<(std::ostream& out, IntArr iArr);


private:
	int quantity;
	int* arr;
};

