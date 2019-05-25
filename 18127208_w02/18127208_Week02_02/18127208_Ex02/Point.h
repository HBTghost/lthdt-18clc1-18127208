#pragma once
#include <iostream>
#include <fstream>
#include "math.h"

class Point
{
public:
	Point();
	~Point();

	void input();
	void input(int x, int y);

	int getX();
	int getY();

	float to(Point& p);

	friend std::ifstream& operator>>(std::ifstream& in, Point& p);
	friend std::ostream& operator<<(std::ostream& out, Point& p);

private:
	int x, y;
};

Point MaxDistanceToP(Point* arr, int n, Point p) {
	float max = arr[0].to(p);
	int iMax = 0;
	for (unsigned i = 0; i < n; ++i) {
		if (max < arr[i].to(p)) {
			iMax = i;
			max = arr[i].to(p);
		}
	}
	return arr[iMax];
}