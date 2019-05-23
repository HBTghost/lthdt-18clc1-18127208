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

private:
	int x, y;
};

