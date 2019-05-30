#pragma once

#include <iostream>
#include <fstream>

class Fraction
{
public:
	Fraction();
	~Fraction();

	void input();
	bool input(int nu, int de);

	void reduce();

	int getNu();
	int getDe();
	float getVal();

	Fraction& operator+(Fraction& fr);

	friend bool operator>(Fraction& a, Fraction& b);
	friend bool operator<(Fraction& a, Fraction& b);
	friend std::ifstream& operator>>(std::ifstream& in, Fraction& fr);

private:
	int nu, de;
};

void swap(Fraction& a, Fraction& b);
