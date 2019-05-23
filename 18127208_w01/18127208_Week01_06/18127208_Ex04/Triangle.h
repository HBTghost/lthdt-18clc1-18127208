#pragma once

#include "Point.h"

class Triangle
{
public:
	Triangle();
	~Triangle();

	Point getA();
	Point getB();
	Point getC();
	float getEdgeA();
	float getEdgeB();
	float getEdgeC();

	bool isValid();

	std::string getType();
	float getPerimeter();
	float getArea();

	friend std::ofstream& operator<<(std::ofstream& out, Triangle& t);
	friend std::ifstream& operator>>(std::ifstream& in, Triangle& t);

private:
	Point a, b, c;
};
