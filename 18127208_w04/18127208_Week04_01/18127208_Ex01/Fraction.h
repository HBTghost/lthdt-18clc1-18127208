#pragma once

#include <iostream>
#include <fstream>

class Fraction
{
public:
	Fraction();
	Fraction(int nu, int de);
	Fraction(const Fraction& fr);
	~Fraction();

	operator float();

	void input();
	bool input(int nu, int de);

	void reduce();

	int getNu();
	int getDe();
	float getVal();

	Fraction& operator=(const Fraction& fr);	

	Fraction& operator++();
	Fraction operator++(int);
	Fraction& operator--();
	Fraction operator--(int);

	Fraction& operator+=(const Fraction& fr);
	Fraction& operator-=(const Fraction& fr);
	Fraction& operator*=(const Fraction& fr);
	Fraction& operator/=(const Fraction& fr);

	friend Fraction operator+(Fraction a, Fraction b);
	friend Fraction operator-(Fraction a, Fraction b);
	friend Fraction operator*(Fraction a, Fraction b);
	friend Fraction operator/(Fraction a, Fraction b);

	friend Fraction operator+(Fraction fr, int num);
	friend Fraction operator-(Fraction fr, int num);
	friend Fraction operator+(int num, Fraction& fr);
	friend Fraction operator*(int num, Fraction& fr);

	friend bool operator==(Fraction& a, Fraction& b);
	friend bool operator!=(Fraction& a, Fraction& b);
	friend bool operator>(Fraction& a, Fraction& b);
	friend bool operator>=(Fraction& a, Fraction& b);
	friend bool operator<(Fraction& a, Fraction& b);
	friend bool operator<=(Fraction& a, Fraction& b);

	friend std::ifstream& operator>>(std::ifstream& in, Fraction& fr);
	friend std::ostream& operator<<(std::ostream& out, Fraction fr);

private:
	int nu, de;
};

void swap(Fraction& a, Fraction& b);
