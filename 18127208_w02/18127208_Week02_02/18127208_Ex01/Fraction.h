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
	friend std::ostream& operator<<(std::ostream& out, Fraction& fr);
	friend std::ifstream& operator>>(std::ifstream& in, Fraction& fr);

private:
	int nu, de;
};

float sum(Fraction* arr, int n) {
	float sum = 0.0;
	for (unsigned i = 0; i < n; ++i) {
		sum += arr[i].getVal();
	}
	return sum;
}

Fraction max(Fraction* arr, int n) {
	Fraction max = arr[0];
	for (int i = 1; i < n; ++i) {
		if (max < arr[i]) {
			max = arr[i];
		}
	}
	return max;
}

Fraction min(Fraction* arr, int n);
void swap(Fraction& a, Fraction& b);
void ascSort(Fraction* arr, int n);