#pragma once
#include "Point.h"

class PointArr
{
public:
	PointArr();
	PointArr(std::string fileName);
	PointArr(const PointArr& pArr);
	~PointArr();

	Point& MaxDistanceToP(Point& p);

private:
	int quantity;
	Point* arr;
};
