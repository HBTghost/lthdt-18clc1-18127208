#pragma once
#include "Fraction.h"

class FractionArr
{
public:
	FractionArr();
	~FractionArr();

	float getSum();

	void ascSort();
	void input(std::string fileName);
	void display();

private:
	Fraction* arr;
	int quantity;
};

