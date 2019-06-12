#pragma once
#include <iostream>
#include <ctime>

class Date
{
public:
	Date();
	Date(int year);
	Date(int year, int month);
	Date(int year, int month, int day);
	Date(const Date& date);
	Date(tm date);
	~Date();

	void input();

	Date Tomorrow();
	Date Yesterday();

	Date& operator=(const Date& date);	

	Date& operator+=(int days);
	Date& operator-=(int days);

	Date& operator++();
	Date operator++(int);
	Date& operator--();
	Date operator--(int);

	operator int();
	operator long();

	friend Date operator+(Date date, int days);
	friend Date operator-(Date date, int days);

	friend std::ostream& operator<<(std::ostream& out, Date date);
	friend std::istream& operator>>(std::istream& in, Date& date);

	friend bool operator==(Date& a, Date& b);
	friend bool operator!=(Date& a, Date& b);
	friend bool operator>(Date& a, Date& b);
	friend bool operator>=(Date& a, Date& b);
	friend bool operator<(Date& a, Date& b);
	friend bool operator<=(Date& a, Date& b);

private:
	int year, month, day;

	void input(tm date);
	tm getTM() const;
};
