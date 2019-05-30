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

char Triangle::getIndexType() {
	float A = getEdgeA();
	float B = getEdgeB();
	float C = getEdgeC();
	float cosA = (B*B+C*C-A*A)/(2*B*C);
	float cosB = (A*A+C*C-B*B)/(2*A*C);
	float cosC = (A*A+B*B-C*C)/(2*A*B);
	bool equi = (A == B && B == C);
	bool isos = ((A == B && A != C) || (A == C && A != B) || (B == C && B != A));
	bool right = ((A * A + B * B == C * C) || (B * B + C * C == A * A) || (C * C + A * A == B * B));
	bool acute = (cosA>0 && cosB>0 && cosC>0);

	if (equi) {
		return 0;
	}
	else if (isos) {
		return 1;
	}
	else if (right) {
		return 2;
	}
	else if (isos && right) {
		return 3;
	}
	else if (acute) {
		return 4;
	}
	else
		return 5;
}
std::string Triangle::getType() {
	const char* types[] = {"Equilateral", "Isoscles", "Right", "Isoscles right", "Acute", "Obtuse"};
	return types[getIndexType()];
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

std::ofstream& operator<<(std::ofstream& out, Triangle& t) {
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
std::ifstream& operator>>(std::ifstream& in, Triangle& t) {
	in >> t.a;
	in >> t.b;
	in >> t.c;
	return in;
}
std::string getTypeByIndex(char index) {
	const char* types[] = {"Equilateral", "Isoscles", "Right", "Isoscles right", "Acute", "Obtuse"};
	return types[index];
}
