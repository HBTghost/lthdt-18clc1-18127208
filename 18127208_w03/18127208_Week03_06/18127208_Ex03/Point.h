#pragma once
#include <iostream>
#include <fstream>
#include "math.h"

class Point
{
public:
	Point();
	Point(int x, int y);
	Point(Point& p);
	~Point();

	void input();
	void input(int x, int y);

	int getX();
	int getY();

	float to(Point& p);

	Point& operator=(const Point& p);
	friend std::ifstream& operator>>(std::ifstream& in, Point& p);
	friend std::ostream& operator<<(std::ostream& out, Point& p);

private:
	int x, y;
};
