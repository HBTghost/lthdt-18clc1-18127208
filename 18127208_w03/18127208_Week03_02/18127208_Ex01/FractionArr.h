#pragma once
#include "Fraction.h"

class FractionArr
{
public:
	FractionArr();
	FractionArr(std::string fileName);
	FractionArr(const FractionArr& frArr);
	~FractionArr();

	float getSum();

	void ascSort();
	void input(std::string fileName);
	void display();

private:
	Fraction* arr;
	int quantity;
};

