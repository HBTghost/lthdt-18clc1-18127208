#pragma once
#include "Triangle.h"

class TriangleArr
{
public:
	TriangleArr();
	TriangleArr(std::string fileName);
	TriangleArr(const TriangleArr& tArr);
	~TriangleArr();

	int getQuantity();
	int getTheNumberOfValids();
	void deleteInvalids();
	void showTypes();

private:
	int quantity;
	Triangle* arr;
};

