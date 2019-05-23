#include "Triangle.h"

Triangle::Triangle() {}
Triangle::~Triangle() {}

Point Triangle::getA() {
	return this->a;
}
Point Triangle::getB() {
	return this->b;
}
Point Triangle::getC() {
	return this->c;
}
float Triangle::getEdgeA() {
	return this->b.to(this->c);
}
float Triangle::getEdgeB() {
	return this->a.to(this->c);
}
float Triangle::getEdgeC() {
	return this->a.to(this->b);
}

bool Triangle::isValid() {
	float A = getEdgeA();
	float B = getEdgeB();
	float C = getEdgeC();
	if ((A + B <= C) || (B + C <= A) || (C + A <= B))
		return false;
	else
		return true;
}

std::string Triangle::getType() {
	float A = getEdgeA();
	float B = getEdgeB();
	float C = getEdgeC();
	bool equi = (A == B && B == C);
	bool isos = ((A == B && A != C) || (A == C && A != B) || (B == C && B != A));
	bool right = ((A * A + B * B == C * C) || (B * B + C * C == A * A) || (C * C + A * A == B * B));

	if (equi) {
		return "Equilateral triangle";
	}
	else if (isos) {
		return "Isoscles triangle";
	}
	else if (right) {
		return "Right triangle";
	}
	else if (isos && right) {
		return "Isoscles right triangle";
	}
	else
		return "Regular triangle";
}
float Triangle::getPerimeter() {
	return getEdgeA() + getEdgeB() + getEdgeC();
}
float Triangle::getArea() {
	float p = getPerimeter() / 2;
	float a = getEdgeA();
	float b = getEdgeB();
	float c = getEdgeC();
	return sqrt(p * (p - a) * (p - b) * (p - c));
}

std::ofstream & operator<<(std::ofstream & out, Triangle & t) {
	if (t.isValid()) {
		out << "3 vertices of triangle: " << t.getEdgeA() << " | " << t.getEdgeB() << " | " << t.getEdgeC();
		out << "\nType of triangle: " << t.getType();
		out << "\nPerimeter: " << t.getPerimeter();
		out << "\nArea: " << t.getArea();
	}
	else
		out << "We can't build a triangle from them!";
	return out;
}
std::ifstream& operator>>(std::ifstream & in, Triangle & t) {
	in >> t.a;
	in >> t.b;
	in >> t.c;
	return in;
}
