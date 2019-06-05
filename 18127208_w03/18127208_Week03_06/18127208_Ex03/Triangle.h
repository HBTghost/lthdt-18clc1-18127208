#pragma once

#include "Point.h"

class Triangle
{
public:
	Triangle();
	Triangle(Point a, Point b, Point c);
	Triangle(const Triangle& tri);
	~Triangle();

	Point getA();
	Point getB();
	Point getC();
	float getEdgeA();
	float getEdgeB();
	float getEdgeC();

	bool isValid();

	char getIndexType();
	std::string getType();
	float getPerimeter();
	float getArea();

	friend std::ofstream& operator<<(std::ofstream& out, Triangle& t);
	friend std::ifstream& operator>>(std::ifstream& in, Triangle& t);

private:
	Point a, b, c;
};

std::string getTypeByIndex(char index);
