#include "Point.h"

Point::Point() {
	this->x = this->y = 0;
}
Point::Point(int x, int y) {
	input(x, y);
}
Point::Point(Point& p) {
	input(p.x, p.y);
}
Point::~Point() {}

void Point::input() {
	std::cout << "x: ";
	std::cin >> this->x;
	std::cout << "y: ";
	std::cin >> this->y;
}
void Point::input(int x, int y) {
	this->x = x;
	this->y = y;
}

int Point::getX() {
	return this->x;
}
int Point::getY() {
	return this->y;
}

float Point::to(Point& p) {
	float temp = pow(getX() - p.getX(), 2) + pow(getY() - p.getY(), 2);
	return sqrt(temp);
}

Point& Point::operator=(const Point& p) {
	this->x = p.x;
	this->y = p.y;
	return *this;
}
std::ifstream& operator>>(std::ifstream& in, Point& p) {
	int x, y;
	in >> x;
	in >> y;
	p.input(x, y);
	return in;
}
std::ostream& operator<<(std::ostream& out, Point& p) {
	out << p.getX() << " " << p.getY();
	return out;
}
